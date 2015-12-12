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

	this->m_pMonoDomain			= nullptr;

	this->m_pEventManager		= new CEventManager( this );
	this->m_pRegisteredCommands	= new CRegisteredCommands( this );
}

CResource::~CResource( void )
{
	this->RemoveEvents();

	this->GetMono()->GetGC()->Collect( this->GetMono()->GetGC()->GetMaxGeneration() );

	g_pResourceManager->RemoveFromList( this );

	SAFE_DELETE( this->m_pRegisteredCommands );
	SAFE_DELETE( this->m_pEventManager );

	this->GetMono()->SetDomain( nullptr, true );

	SAFE_DELETE( this->m_pMonoDomain );

	this->m_pMono				= nullptr;
	this->m_pLuaVM				= nullptr;

}

bool CResource::CallEvent( string strEventName, void* pThis, list< CLuaArgument* > argv )
{
	if( !pThis )
	{
		return false;
	}

	return this->m_pEventManager->Call( strEventName, pThis, argv );
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

bool CResource::ExecuteCommand( void* pPlayer, string strCommandName, list< string > argv )
{
	if( !pPlayer )
	{
		return false;
	}

	return this->m_pRegisteredCommands->Execute( pPlayer, strCommandName, argv );
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
		this->m_pMonoDomain = this->GetMono()->CreateAppdomain( this, this->m_sName.c_str(), nullptr );

		if( !this->m_pMonoDomain )
		{
			g_pModuleManager->ErrorPrintf( "%s - failed to create appdomain\n", this->m_sName.c_str() );

			return false;
		}

		this->m_pMonoDomain->SetConfig( "mods/deathmatch/", "mods/deathmatch/mono/etc/mono/4.5/machine.config" );

		this->m_pMonoDomain->Set( false );

		if( this->m_pMonoDomain->Init() )
		{
			this->RegisterEvents();

			if( this->m_pMonoDomain->Start() )
			{
				return true;
			}
		}

		CLuaArguments pLuaArguments; 
			
		pLuaArguments.Call( this->m_pLuaVM, "cancelEvent" );
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
