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

CResource::CResource( CResourceManager* pResourceManager, lua_State* pLuaVM, const string& sName )
{
	this->m_pResourceManager	= pResourceManager;
	this->m_pModule				= pResourceManager->GetModule();
	this->m_pMono				= pResourceManager->GetMono();
	this->m_pLuaVM				= pLuaVM;
	this->m_sName				= sName;

	this->m_pMonoDomain			= nullptr;

	this->m_pElementManager		= new CElementManager( this );
	this->m_pEventManager		= new CEventManager( this );
	this->m_pRegisteredCommands	= new CRegisteredCommands( this );
}

CResource::~CResource( void )
{
	this->RemoveEvents();

	SAFE_DELETE( this->m_pRegisteredCommands );
	SAFE_DELETE( this->m_pEventManager );
	SAFE_DELETE( this->m_pElementManager );

	this->GetMono()->SetDomain( nullptr, true );

	SAFE_DELETE( this->m_pMonoDomain );

	this->m_pMono				= nullptr;
	this->m_pLuaVM				= nullptr;
	this->m_pResourceManager	= nullptr;
	this->m_pModule				= nullptr;
}

bool CResource::CallEvent( const string& strEventName, PVOID pThis, list< CLuaArgument* > argv ) const
{
	if( !pThis )
	{
		return false;
	}

	CElement* pThisElement = this->m_pElementManager->FindOrCreate( pThis );

	bool bResult = this->m_pEventManager->Call( strEventName, pThisElement, argv );

	if( strEventName == "onElementDestroy" )
	{
		CElement* pSource = nullptr;

		const auto& iter = *argv.begin();

		if( iter->GetType() == eLuaType::LightUserdata )
		{
			pSource = this->m_pElementManager->GetFromList( iter->GetLightUserData() );
		}

		if( pSource )
		{
			delete pSource;
		}
	}

	return bResult;
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

bool CResource::ExecuteCommand( PVOID pPlayer, const string& strCommandName, list< string > argv )
{
	if( !pPlayer )
	{
		return false;
	}

	CElement* pPlayerElement = this->m_pElementManager->FindOrCreate( pPlayer );

	return this->m_pRegisteredCommands->Execute( pPlayerElement, strCommandName, argv );
}

void CResource::RegisterEvents( void )
{
	if( this->m_pLuaVM )
	{
		if( this->RegisterFunction( "mono_event_handler", CFunctions::monoEventHandler ) )
		{
			luaL_dostring( this->m_pLuaVM, "function _mono_event_handler( ... ) mono_event_handler( eventName, source, this, client, ... ); end" );

			CMonoClass* pClass = this->GetDomain()->GetMTALib()->GetClass( "Element" );

			if( pClass )
			{
				for( const auto& iter : pClass->GetAllEvents() )
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
			for( const auto& iter : pClass->GetAllEvents() )
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
			this->ErrorPrintf( "%s - failed to create appdomain\n", this->m_sName.c_str() );

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
	if( !this->m_pModule->RegisterFunction( this->m_pLuaVM, szFunctionName, Func ) )
	{
		this->ErrorPrintf( "Failed to register function '%s' for %s", szFunctionName, this->m_sName.c_str() );

		return false;
	}

	return true;
}
