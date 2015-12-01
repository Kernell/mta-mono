/*********************************************************
*
*  Copyright © 2013, Innovation Roleplay Engine. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "CResource.h"

CResource::CResource( CMonoInterface* pMono, lua_State *pLuaVM, string sName )
{
	this->m_pMono				= pMono;
	this->m_pLuaVM				= pLuaVM;
	this->m_sName				= sName;

	this->m_pMonoAssembly		= nullptr;
	this->m_pMonoDomain			= nullptr;
	this->m_pMonoImage			= nullptr;
	this->m_pMonoClass			= nullptr;

	this->m_uiGCHandle			= 0;
}

CResource::~CResource( void )
{
	this->RemoveEvents();

	if( this->m_uiGCHandle )
	{
		mono_gchandle_free( this->m_uiGCHandle );

		this->m_uiGCHandle = 0;
	}

	this->GetMono()->GetGC()->Collect( this->GetMono()->GetGC()->GetMaxGeneration() );

	mono_domain_set( mono_get_root_domain(), true );

	g_pResourceManager->RemoveFromList( this );

	this->m_pMonoAssembly		= nullptr;
	this->m_pMonoDomain			= nullptr;
	this->m_pMonoImage			= nullptr;
	this->m_pMonoClass			= nullptr;

	this->m_pMono				= nullptr;
	this->m_pLuaVM				= nullptr;
}

bool CResource::CallEvent( string strEventName, void* pThis, list< CLuaArgument* > argv )
{
	if( !pThis )
	{
		return false;
	}

	CMonoMTALib* pMTALib	= this->GetDomain()->GetMTALib();

	CMonoClass* pClass		= pMTALib->GetClass( "Element" );
	CMonoEvent* pEvent		= pClass->GetEvent( strEventName );

	if( !pEvent )
	{
		g_pModuleManager->ErrorPrintf( "[%s] event '%s' is class '%s' not found", this->m_sName.c_str(), strEventName.c_str(), pClass->GetName() );

		return false;
	}

	MonoObject* pThisObj	= pMTALib->RegisterElement( pThis );

	if( !pThisObj )
	{
		return false;
	}

	return pEvent->Call( pThisObj, argv );
}

bool CResource::AddEvent( const char* szName, const char* szHandleElement )
{
	if( this->m_pLuaVM )
	{
		char szBuffer[ 128 ];

		sprintf( szBuffer, "addEventHandler( '%s', %s, _mono_event_handler, true, 'normal' );", szName, szHandleElement );

		luaL_dostring( this->m_pLuaVM, szBuffer );

		return true;
	}

	return false;
}

bool CResource::RemoveEvent( const char* szName, const char* szHandleElement )
{
	if( this->m_pLuaVM )
	{
		char szBuffer[ 128 ];

		sprintf( szBuffer, "removeEventHandler( '%s', %s, _mono_event_handler );", szName, szHandleElement );

		luaL_dostring( this->m_pLuaVM, szBuffer );

		return true;
	}

	return false;
}

void CResource::RegisterEvents( void )
{
	if( this->m_pLuaVM )
	{
		if( g_pModuleManager->RegisterFunction( this->m_pLuaVM, "mono_event_handler", CFunctions::monoEventHandler ) )
		{
			luaL_dostring( this->m_pLuaVM, "function _mono_event_handler( ... ) mono_event_handler( eventName, source, this, client, ... ); end" );

			CMonoClass* pClass = this->GetDomain()->GetMTALib()->GetClass( "Element" );

			if( pClass )
			{
				for( auto iter : pClass->GetAllEvents() )
				{
					string strEventName = iter.second->GetName();

					strEventName[ 0 ] = tolower( strEventName[ 0 ] );

					this->AddEvent( strEventName.c_str(), "root" );
				}
			}
		}
	}
}

void CResource::RemoveEvents( void )
{
	if( this->m_pLuaVM )
	{
		CMonoClass* pClass = this->GetDomain()->GetMTALib()->GetClass( "Element" );

		if( pClass )
		{
			for( auto iter : pClass->GetAllEvents() )
			{
				string strEventName = iter.second->GetName();

				strEventName[ 0 ] = tolower( strEventName[ 0 ] );

				this->RemoveEvent( strEventName.c_str(), "root" );
			}
		}
	}
}

bool CResource::Init( void )
{
	if( this->m_pLuaVM )
	{
		string sDirectory	( CMonoInterface::GetBinariesDirectory() + "/" + this->m_sName + "/" );
		string sPath		( sDirectory + this->m_sName + ".dll" );
		string sNamespace	( this->m_sName );
		string sClass		( "Program" );

		this->m_pMonoDomain = this->GetMono()->CreateAppdomain( this, const_cast< char* >( this->m_sName.c_str() ), nullptr );

		if( !this->m_pMonoDomain )
		{
			g_pModuleManager->ErrorPrintf( "%s - failed to create appdomain\n", this->m_sName.c_str() );

			return false;
		}

		this->m_pMonoDomain->Set( false );

		this->m_pMonoDomain->Init();

		this->m_pMonoAssembly = this->m_pMonoDomain->OpenAssembly( sPath.c_str() );
		
		if( !this->m_pMonoAssembly )
		{
			g_pModuleManager->ErrorPrintf( "failed to open assembly '%s.dll'\n", this->m_sName.c_str() );

			return false;
		}

		this->RegisterEvents();

		this->m_pMonoImage	= mono_assembly_get_image( this->m_pMonoAssembly );
		this->m_pMonoClass	= mono_class_from_name( this->m_pMonoImage, sNamespace.c_str(), sClass.c_str() );

		MonoObject *pMonoObject = this->m_pMonoDomain->CreateObject( this->m_pMonoClass );

		mono_runtime_object_init( pMonoObject );

		this->m_uiGCHandle = mono_gchandle_new( pMonoObject, true );

		return true;
	}

	return false;
}

void CResource::OnStopping( void )
{
	
}

void CResource::DoPulse( void )
{
}

bool CResource::RegisterFunction( const char *szFunctionName, lua_CFunction Func )
{
	if( !g_pModuleManager->RegisterFunction( this->m_pLuaVM, szFunctionName, Func ) )
	{
		g_pModuleManager->ErrorPrintf( "Failed to register function '%s' for %s", szFunctionName, this->m_sName.c_str() );

		return false;
	}

	return true;
}

void CResource::Printf( const char* szFormat, ... )
{
	va_list args;

	va_start( args, szFormat );

	char szBuffer[ 255 ];

	vsprintf( szBuffer, szFormat, args );

	va_end( args ); 

	g_pModuleManager->Printf( szBuffer );
}

void CResource::DebugPrintf( const char* szFormat, ... )
{
	va_list args;

	va_start( args, szFormat );

	char szBuffer[ 255 ];

	vsprintf( szBuffer, szFormat, args );

	va_end( args ); 

	g_pModuleManager->DebugPrintf( this->m_pLuaVM, szBuffer );
}

void CResource::ErrorPrintf( const char* szFormat, ... )
{
	va_list args;

	va_start( args, szFormat );

	char szBuffer[ 255 ];

	vsprintf( szBuffer, szFormat, args );

	va_end( args ); 

	g_pModuleManager->ErrorPrintf( szBuffer );
}
