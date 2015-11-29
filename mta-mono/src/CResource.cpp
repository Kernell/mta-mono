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

#include "StdInc.h"
#include "CResource.h"
#include "CResourceManager.h"
#include "CFunctions.h"
#include "include/ILuaModuleManager.h"
#include "lua/CLuaFunctionDefinitions.h"

extern ILuaModuleManager10	*g_pModuleManager;
extern CResourceManager	*g_pResourceManager;

CResource::CResource( CMonoInterface* pMono, lua_State *pLuaVM, string sName )
{
	this->m_pMono				= pMono;
	this->m_pLuaVM				= pLuaVM;
	this->m_sName				= sName;

	this->m_pMonoAssembly		= nullptr;
	this->m_pMonoGCHandle		= 0;
	this->m_pMonoDomain			= nullptr;
	this->m_pMonoImage			= nullptr;
	this->m_pMonoClass			= nullptr;
}

CResource::~CResource( void )
{
	this->GetMono()->GetGC()->Collect( this->GetMono()->GetGC()->GetMaxGeneration() );

	mono_domain_set( mono_get_root_domain(), false );

	if( this->m_pMonoDomain )
	{
		this->m_pMonoDomain->Unload();
		this->m_pMonoDomain = nullptr;
	}

	g_pResourceManager->RemoveFromList( this );

	this->m_pMonoAssembly		= nullptr;
	this->m_pMonoGCHandle		= 0;
	this->m_pMonoDomain			= nullptr;
	this->m_pMonoImage			= nullptr;
	this->m_pMonoClass			= nullptr;

	this->m_pMono				= nullptr;
	this->m_pLuaVM				= nullptr;
	this->m_sName				= nullptr;
}

bool CResource::CallEvent( string strEventName, void* pThis, void* pSource, void* pClient, void **args )
{
	MonoEvent* pEvent	= nullptr;
	MonoMethod* method	= nullptr;
	MonoClass* klass	= this->GetDomain()->GetMTALib()->GetClass( "Element" )->GetMonoPtr();

	g_pModuleManager->DebugPrintf( this->GetLua(), "CResource::CallEvent::%s", strEventName.substr( 2 ).c_str() );

	gpointer iter;

	while( klass )
	{
		iter = nullptr;

		while( pEvent = mono_class_get_events( klass, &iter ) )
		{
			if( !strcmp( strEventName.substr( 2 ).c_str(), mono_event_get_name( pEvent ) ) )
			{
				method = mono_event_get_raise_method( pEvent );

				break;
			}
		}

		klass = mono_class_get_parent( klass );
	}

	if( method )
	{
		mono_runtime_invoke( method, pThis, args, nullptr );
		
		return true;
	}
	else
	{
		g_pModuleManager->ErrorPrintf( "mono: method not found\n" );
	}

	return false;
}

void CResource::RegisterEvents( void )
{
	if( this->m_pLuaVM )
	{
		if( g_pModuleManager->RegisterFunction( this->m_pLuaVM, "mono_event_handler", CFunctions::monoEventHandler ) )
		{
			luaL_dostring( this->m_pLuaVM, "addEventHandler( 'onElementDestroy', root, \
function( ... ) \
	mono_event_handler( eventName, this, source, client, ... );\
end \
)"
			);
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

		mono_gchandle_new( pMonoObject, false );

		mono_runtime_object_init( pMonoObject );

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
