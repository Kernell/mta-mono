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
#include "CMonoFunctions.h"

// Player get functions
unsigned int CMonoFunctions::Player::GetCount( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::GetPlayerCount( pResource->GetLua() );
	}

	return 0;
}

TElement CMonoFunctions::Player::GetFromName( MonoString* msNick )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szNick = mono_string_to_utf8( msNick );

		PVOID pUserData = CLuaFunctionDefinitions::GetPlayerFromName( pResource->GetLua(), szNick );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

unsigned int CMonoFunctions::Player::GetPing( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiPing;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerPing( pResource->GetLua(), pElement->ToLuaUserData(), uiPing ) )
		{
			return uiPing;
		}
	}

	return 0;
}

long CMonoFunctions::Player::GetMoney( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		long lMoney;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerMoney( pResource->GetLua(), pElement->ToLuaUserData(), lMoney ) )
		{
			return lMoney;
		}
	}
	
	return 0;
}

TElement CMonoFunctions::Player::GetRandom( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		PVOID pUserData = CLuaFunctionDefinitions::GetRandomPlayer( pResource->GetLua() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}
	
	return nullptr;
}

bool CMonoFunctions::Player::IsMuted( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bMuted;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPlayerMuted( pResource->GetLua(), pElement->ToLuaUserData(), bMuted ) )
		{
			return bMuted;
		}
	}
	
	return false;
}

TElement CMonoFunctions::Player::GetTeam( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetPlayerTeam( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}
	
	return nullptr;
}

unsigned int CMonoFunctions::Player::GetWantedLevel( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiWantedLevel;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerWantedLevel( pResource->GetLua(), pElement->ToLuaUserData(), uiWantedLevel ) )
		{
			return uiWantedLevel;
		}
	}
	
	return 0;
}

MonoArray* CMonoFunctions::Player::GetAlivePlayers( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetAlivePlayers( pResource->GetLua() );

		if( pLuaArguments.size() > 0 )
		{
			return pResource->GetDomain()->NewElementArray( mono_get_uint32_class(), pLuaArguments );
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Player::GetDeadPlayers( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetDeadPlayers( pResource->GetLua() );

		if( pLuaArguments.size() > 0 )
		{
			return pResource->GetDomain()->NewElementArray( pResource->GetDomain()->GetMTALib()->GetClass( "Player" )->GetMonoPtr(), pLuaArguments );
		}
	}

	return nullptr;
}

unsigned int CMonoFunctions::Player::GetIdleTime( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiIdleTime;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerIdleTime( pResource->GetLua(), pElement->ToLuaUserData(), uiIdleTime ) )
		{
			return uiIdleTime;
		}
	}
	
	return 0;
}

bool CMonoFunctions::Player::IsMapForced( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bForced;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPlayerMapForced( pResource->GetLua(), pElement->ToLuaUserData(), bForced ) )
		{
			return bForced;
		}
	}
	
	return 0;
}

MonoString* CMonoFunctions::Player::GetNametagText( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutText;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerNametagText( pResource->GetLua(), pElement->ToLuaUserData(), strOutText ) )
		{
			return pResource->GetDomain()->NewString( strOutText );
		}
	}
	
	return nullptr;
}

MonoObject* CMonoFunctions::Player::GetNametagColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucR, ucG, ucB;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerNametagColor( pResource->GetLua(), pElement->ToLuaUserData(), ucR, ucG, ucB ) )
		{
			PVOID args[] =
			{
				&ucR, &ucG, &ucB
			};
			
			return pResource->GetDomain()->GetMTALib()->Color->New( args, 3 );
		}
	}
	
	return nullptr;
}

bool CMonoFunctions::Player::IsNametagShowing( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bShowing;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPlayerNametagShowing( pResource->GetLua(), pElement->ToLuaUserData(), bShowing ) )
		{
			return bShowing;
		}
	}
	
	return false;
}

MonoString* CMonoFunctions::Player::GetSerial( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return pResource->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerSerial( pResource->GetLua(), pElement->ToLuaUserData() ) );
	}
	
	return nullptr;
}

MonoString* CMonoFunctions::Player::GetUserName( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return pResource->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerUserName( pResource->GetLua(), pElement->ToLuaUserData() ) );
	}
	
	return nullptr;
}

unsigned char CMonoFunctions::Player::GetBlurLevel( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucBlurLevel;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerBlurLevel( pResource->GetLua(), pElement->ToLuaUserData(), ucBlurLevel ) )
		{
			return ucBlurLevel;
		}
	}
	
	return 0;
}

MonoString* CMonoFunctions::Player::GetName( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerName( pResource->GetLua(), pElement->ToLuaUserData(), strOutName ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}
	
	return nullptr;
}

MonoString* CMonoFunctions::Player::GetIP( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strIP;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPlayerIP( pResource->GetLua(), pElement->ToLuaUserData(), strIP ) )
		{
			return pResource->GetDomain()->NewString( strIP );
		}
	}
	
	return nullptr;
}

TElement CMonoFunctions::Player::GetAccount( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetPlayerAccount( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}
	
	return nullptr;
}

MonoString* CMonoFunctions::Player::GetVersion( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return pResource->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerVersion( pResource->GetLua(), pElement->ToLuaUserData() ) );
	}
	
	return nullptr;
}

MonoObject* CMonoFunctions::Player::GetACInfo( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		CLuaArgumentsMap* pLuaTable = CLuaFunctionDefinitions::GetPlayerACInfo( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pLuaTable )
		{
			MonoString* msDetectedAC	= pResource->GetDomain()->NewString( (*pLuaTable)[ "DetectedAC" ].GetString() );
			MonoString* msD3D9MD5		= pResource->GetDomain()->NewString( (*pLuaTable)[ "d3d9MD5" ].GetString() );
			MonoString* msD3D9SHA256	= pResource->GetDomain()->NewString( (*pLuaTable)[ "d3d9SHA256" ].GetString() );

			unsigned int iD3D9Size		= (*pLuaTable)[ "d3d9Size" ].GetNumber< unsigned int >();

			void *args[] =
			{
				&msDetectedAC,
				&iD3D9Size,
				&msD3D9MD5,
				&msD3D9SHA256
			};

			return pResource->GetDomain()->GetMTALib()->GetClass( "PlayerACInfo" )->New( args, 4 );
		}
	}
	return nullptr;
}

MonoString* CMonoFunctions::Player::GetPlayerAnnounceValue( TElement pThis, MonoString* msKey )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szKey = mono_string_to_utf8( msKey );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return pResource->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerAnnounceValue( pResource->GetLua(), (void*)pElement, szKey ) );
	}

	return nullptr;
}


// Player set functions
bool CMonoFunctions::Player::SetMoney( TElement pThis, int iAmount, bool bInstant )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerMoney( pResource->GetLua(), pElement->ToLuaUserData(), iAmount, bInstant );
	}
	
	return false;
}

bool CMonoFunctions::Player::GiveMoney( TElement pThis, int iAmount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::GivePlayerMoney( pResource->GetLua(), pElement->ToLuaUserData(), iAmount );
	}
	
	return false;
}

bool CMonoFunctions::Player::TakeMoney( TElement pThis, int iAmount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::TakePlayerMoney( pResource->GetLua(), pElement->ToLuaUserData(), iAmount );
	}
	
	return false;
}

bool CMonoFunctions::Player::Spawn( TElement pThis, MonoObject* pPosition, int iRotation, int iSkinID, int iInterior, int iDimension, TElement pTeam )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SpawnPlayer( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition, iRotation, iSkinID, iInterior, iDimension, (void*)pTeam );
	}
	
	return false;
}

bool CMonoFunctions::Player::ShowHudComponent( TElement pThis, MonoString* msComponent, bool bShow )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strComponent( mono_string_to_utf8( msComponent ) );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ShowPlayerHudComponent( pResource->GetLua(), pElement->ToLuaUserData(), strComponent, bShow );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetWantedLevel( TElement pThis, int iLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerWantedLevel( pResource->GetLua(), pElement->ToLuaUserData(), iLevel );
	}
	
	return false;
}

bool CMonoFunctions::Player::ForceMap( TElement pThis, bool bForceOn )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ForcePlayerMap( pResource->GetLua(), pElement->ToLuaUserData(), bForceOn );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetNametagText( TElement pThis, MonoString* sText )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerNametagText( pResource->GetLua(), pElement->ToLuaUserData(), mono_string_to_utf8( sText ) );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetNametagColor( TElement pThis, int iRed, int iGreen, int iBlue )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerNametagColor( pResource->GetLua(), pElement->ToLuaUserData(), iRed, iGreen, iBlue );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetNametagShowing( TElement pThis, bool bShowing )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerNametagShowing( pResource->GetLua(), pElement->ToLuaUserData(), bShowing );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetMuted( TElement pThis, bool bMuted )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerMuted( pResource->GetLua(), pElement->ToLuaUserData(), bMuted );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetBlurLevel( TElement pThis, int iLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerBlurLevel( pResource->GetLua(), pElement->ToLuaUserData(), iLevel );
	}
	
	return false;
}

bool CMonoFunctions::Player::Redirect( TElement pThis, MonoString* sServerIP, int iServerPort, MonoString* sServerPassword )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szServerIP			= mono_string_to_utf8( sServerIP );
		const char* szServerPassword	= mono_string_to_utf8( sServerPassword );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RedirectPlayer( pResource->GetLua(), pElement->ToLuaUserData(), szServerIP, iServerPort, szServerPassword );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetName( TElement pThis, MonoString* sName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szName			= mono_string_to_utf8( sName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerName( pResource->GetLua(), pElement->ToLuaUserData(), szName );
	}
	
	return false;
}

bool CMonoFunctions::Player::DetonateSatchels( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::DetonateSatchels( pResource->GetLua(), pElement->ToLuaUserData() );
	}
	
	return false;
}

bool CMonoFunctions::Player::TakeScreenShot( TElement pThis, int iWidth, int iHeight, MonoString* sTag, int iQuality, int iMaxBandwith )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strTag( mono_string_to_utf8( sTag ) );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::TakePlayerScreenShot( pResource->GetLua(), pElement->ToLuaUserData(), iWidth, iHeight, strTag, iQuality, iMaxBandwith );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetTeam( TElement pThis, TElement pTeam )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pTeaElement = pResource->GetElementManager()->GetFromList( pTeam );
		
		return CLuaFunctionDefinitions::SetPlayerTeam( pResource->GetLua(), pElement->ToLuaUserData(), pTeaElement->ToLuaUserData() );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetPlayerAnnounceValue( TElement pThis, MonoString* msKey, MonoString* msValue )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szKey	= mono_string_to_utf8( msKey );
		const char* szValue	= mono_string_to_utf8( msValue );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPlayerAnnounceValue( pResource->GetLua(), (void*)pElement, szKey, szValue );
	}

	return false;
}

// Input funcs

bool CMonoFunctions::Player::BindKey( TElement pThis, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName, MonoString* msArguments )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szKey			= mono_string_to_utf8( msKey );
		const char* szHitState		= mono_string_to_utf8( msHitState );
		const char* szCommandName	= mono_string_to_utf8( msCommandName );
		const char* szArguments		= mono_string_to_utf8( msArguments );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::BindKey( pResource->GetLua(), pElement->ToLuaUserData(), szKey, szHitState, szCommandName, szArguments );
	}
	
	return false;
}

bool CMonoFunctions::Player::UnbindKey( TElement pThis, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szKey			= mono_string_to_utf8( msKey );
		const char* szHitState		= mono_string_to_utf8( msHitState );
		const char* szCommandName	= mono_string_to_utf8( msCommandName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::UnbindKey( pResource->GetLua(), pElement->ToLuaUserData(), szKey, szHitState, szCommandName );
	}
	
	return false;
}

bool CMonoFunctions::Player::GetControlState( TElement pThis, MonoString* msControl )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szControl = mono_string_to_utf8( msControl );
		
		bool bState;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetControlState( pResource->GetLua(), pElement->ToLuaUserData(), szControl, bState ) )
		{
			return bState;
		}
	}
	
	return false;
}

bool CMonoFunctions::Player::IsControlEnabled( TElement pThis, MonoString* msControl )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szControl = mono_string_to_utf8( msControl );
		
		bool bEnabled;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsControlEnabled( pResource->GetLua(), pElement->ToLuaUserData(), szControl, bEnabled ) )
		{
			return bEnabled;
		}
	}
	
	return false;
}

		
bool CMonoFunctions::Player::SetControlState( TElement pThis, MonoString* msControl, bool bState )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szControl = mono_string_to_utf8( msControl );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetControlState( pResource->GetLua(), pElement->ToLuaUserData(), szControl, bState );
	}
	
	return false;
}

bool CMonoFunctions::Player::ToggleControl( TElement pThis, MonoString* msControl, bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szControl			= mono_string_to_utf8( msControl );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ToggleControl( pResource->GetLua(), pElement->ToLuaUserData(), szControl, bEnabled );
	}
	
	return false;
}

bool CMonoFunctions::Player::ToggleAllControls( TElement pThis, bool bGTAControls, bool bMTAControls, bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ToggleAllControls( pResource->GetLua(), pElement->ToLuaUserData(), bGTAControls, bMTAControls, bEnabled );
	}
	
	return false;
}


// Log in/out funcs
bool CMonoFunctions::Player::LogIn( TElement pThis, TElement pAccount, MonoString* msPassword )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pAccountElement = pResource->GetElementManager()->GetFromList( pAccount );
		
		return CLuaFunctionDefinitions::LogIn( pResource->GetLua(), pElement->ToLuaUserData(), pAccountElement->ToLuaUserData(), mono_string_to_utf8( msPassword ) );
	}
	
	return false;
}

bool CMonoFunctions::Player::LogOut( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::LogOut( pResource->GetLua(), pElement->ToLuaUserData() );
	}
	
	return false;
}


// Admin funcs
bool CMonoFunctions::Player::Kick( TElement pThis, MonoString* msResponsible, MonoString* msReason )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string
			strResponsible	( mono_string_to_utf8( msResponsible ) ),
			strReason		( mono_string_to_utf8( msReason ) );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::KickPlayer( pResource->GetLua(), pElement->ToLuaUserData(), strResponsible, strReason );
	}
	
	return false;
}

TElement CMonoFunctions::Player::Ban( TElement pThis, bool bIP, bool bUsername, bool bSerial, TElement pArgResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string
			strResponsible	( mono_string_to_utf8( msResponsible ) ),
			strReason		( mono_string_to_utf8( msReason ) );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pResponsible = nullptr;

		if( pArgResponsible )
		{
			pResponsible = pResource->GetElementManager()->GetFromList( pArgResponsible )->ToLuaUserData();
		}
		
		PVOID pUserData = CLuaFunctionDefinitions::BanPlayer( pResource->GetLua(), pElement->ToLuaUserData(), bIP, bUsername, bSerial, pResponsible, strResponsible, strReason, iUnban );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->ToMonoObject();
		}
	}
	
	return nullptr;
}

		
// Cursor get funcs
bool CMonoFunctions::Player::IsCursorShowing( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bShowing;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsCursorShowing( pResource->GetLua(), pElement->ToLuaUserData(), bShowing ) )
		{
			return bShowing;
		}
	}
	
	return false;
}

		
// Cursor set funcs
bool CMonoFunctions::Player::ShowCursor( TElement pThis, bool bShow, bool bToggleControls )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ShowCursor( pResource->GetLua(), pElement->ToLuaUserData(), bShow, bToggleControls );
	}
	
	return false;
}

		
// Chat funcs
bool CMonoFunctions::Player::ShowChat( TElement pThis, bool bShow )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ShowChat( pResource->GetLua(), pElement->ToLuaUserData(), bShow );
	}
	
	return false;
}


// Camera get functions
MonoObject* CMonoFunctions::Player::GetCameraMatrix( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition, vecLookAt;
		
		float fRoll, fFOV;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetCameraMatrix( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition, vecLookAt, fRoll, fFOV ) )
		{
			PVOID args[] =
			{
				&vecPosition.fX,
				&vecPosition.fY,
				&vecPosition.fZ,
				&vecLookAt.fX,
				&vecLookAt.fY,
				&vecLookAt.fZ,
				&fRoll,
				&fFOV
			};

			return pResource->GetDomain()->GetMTALib()->GetClass( "CameraMatrix" )->New( args, 8 );
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Player::GetCameraTarget( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetCameraTarget( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}
	
	return nullptr;
}

unsigned char CMonoFunctions::Player::GetCameraInterior( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucInterior;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetCameraInterior( pResource->GetLua(), pElement->ToLuaUserData(), ucInterior ) )
		{
			return ucInterior;
		}
	}
	
	return 0;
}


// Camera set functions
bool CMonoFunctions::Player::SetCameraMatrix( TElement pThis, MonoObject* pCameraMatrix )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		MonoObject* msPosition = CMonoObject::GetPropertyValue< MonoObject* >( pCameraMatrix, "Position" );

		Vector3 vecPosition( msPosition );
		
		MonoObject* msLookAt = CMonoObject::GetPropertyValue< MonoObject* >( pCameraMatrix, "LookAt" );

		Vector3 vecLookAt( msLookAt );

		float fRoll = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "Roll" );
		float fFOV	= CMonoObject::GetPropertyValue< float >( pCameraMatrix, "FOV" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetCameraMatrix( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition, vecLookAt, fRoll, fFOV );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetCameraTarget( TElement pThis, TElement pTarget )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetCameraTarget( pResource->GetLua(), pElement->ToLuaUserData(), (void*)pTarget );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetCameraInterior( TElement pThis, unsigned char ucInterior )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetCameraInterior( pResource->GetLua(), pElement->ToLuaUserData(), ucInterior );
	}
	
	return false;
}

bool CMonoFunctions::Player::FadeCamera( TElement pThis, bool bFadeIn, float fFadeTime, MonoObject* pColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucReed	= CMonoObject::GetPropertyValue< unsigned char >( pColor, "R" );
		unsigned char ucGreen	= CMonoObject::GetPropertyValue< unsigned char >( pColor, "G" );
		unsigned char ucBlue	= CMonoObject::GetPropertyValue< unsigned char >( pColor, "B" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::FadeCamera( pResource->GetLua(), pElement->ToLuaUserData(), bFadeIn, fFadeTime, ucReed, ucGreen, ucBlue );
	}
	
	return false;
}
