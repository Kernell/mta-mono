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

#ifndef _CMONO_FUNCS_PLAYER
#define _CMONO_FUNCS_PLAYER

#include "CMonoFunctions.h"

// Player get functions
unsigned int CMonoFunctions::Player::GetCount( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetPlayerCount( RESOURCE->GetLua() );
	}

	return 0;
}

DWORD CMonoFunctions::Player::GetFromName( MonoString* msNick )
{
	if( RESOURCE )
	{
		const char* szNick = mono_string_to_utf8( msNick );

		return (DWORD)CLuaFunctionDefinitions::GetPlayerFromName( RESOURCE->GetLua(), szNick );
	}

	return NULL;
}

unsigned int CMonoFunctions::Player::GetPing( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned int uiPing;

		if( CLuaFunctionDefinitions::GetPlayerPing( RESOURCE->GetLua(), (void*)pUserData, uiPing ) )
		{
			return uiPing;
		}
	}

	return 0;
}

long CMonoFunctions::Player::GetMoney( DWORD pUserData )
{
	if( RESOURCE )
	{
		long lMoney;
		
		if( CLuaFunctionDefinitions::GetPlayerMoney( RESOURCE->GetLua(), (void*)pUserData, lMoney ) )
		{
			return lMoney;
		}
	}
	
	return 0;
}

DWORD CMonoFunctions::Player::GetRandom( void )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetRandomPlayer( RESOURCE->GetLua() );
	}
	
	return 0;
}

bool CMonoFunctions::Player::IsMuted( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bMuted;
		
		if( CLuaFunctionDefinitions::IsPlayerMuted( RESOURCE->GetLua(), (void*)pUserData, bMuted ) )
		{
			return bMuted;
		}
	}
	
	return 0;
}

DWORD CMonoFunctions::Player::GetTeam( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetPlayerTeam( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return 0;
}

unsigned int CMonoFunctions::Player::GetWantedLevel( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned int uiWantedLevel;
		
		if( CLuaFunctionDefinitions::GetPlayerWantedLevel( RESOURCE->GetLua(), (void*)pUserData, uiWantedLevel ) )
		{
			return uiWantedLevel;
		}
	}
	
	return 0;
}

MonoArray* CMonoFunctions::Player::GetAlivePlayers( void )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaArguments = CLuaFunctionDefinitions::GetAlivePlayers( RESOURCE->GetLua() );

		if( pLuaArguments )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->GetDomain()->GetMonoPtr(), mono_get_uint32_class(), pLuaArguments->Count() );

			vector< CLuaArgument* >::const_iterator iter = pLuaArguments->IterBegin();

			for( unsigned int i = 0; iter != pLuaArguments->IterEnd(); iter++, i++ )
			{
				mono_array_set( pArray, DWORD, i, (DWORD)( *iter )->GetLightUserData() );
			}

			return pArray;
		}
	}

	return NULL;
}

MonoArray* CMonoFunctions::Player::GetDeadPlayers( void )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaArguments = CLuaFunctionDefinitions::GetDeadPlayers( RESOURCE->GetLua() );

		if( pLuaArguments )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->GetDomain()->GetMonoPtr(), mono_get_uint32_class(), pLuaArguments->Count() );

			vector< CLuaArgument* >::const_iterator iter = pLuaArguments->IterBegin();

			for( unsigned int i = 0; iter != pLuaArguments->IterEnd(); iter++, i++ )
			{
				mono_array_set( pArray, DWORD, i, (DWORD)( *iter )->GetLightUserData() );
			}

			return pArray;
		}
	}

	return NULL;
}

unsigned int CMonoFunctions::Player::GetIdleTime( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned int uiIdleTime;
		
		if( CLuaFunctionDefinitions::GetPlayerIdleTime( RESOURCE->GetLua(), (void*)pUserData, uiIdleTime ) )
		{
			return uiIdleTime;
		}
	}
	
	return 0;
}

bool CMonoFunctions::Player::IsMapForced( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bForced;
		
		if( CLuaFunctionDefinitions::IsPlayerMapForced( RESOURCE->GetLua(), (void*)pUserData, bForced ) )
		{
			return bForced;
		}
	}
	
	return 0;
}

MonoString* CMonoFunctions::Player::GetNametagText( DWORD pUserData )
{
	if( RESOURCE )
	{
		string strOutText;
		
		if( CLuaFunctionDefinitions::GetPlayerNametagText( RESOURCE->GetLua(), (void*)pUserData, strOutText ) )
		{
			return RESOURCE->GetDomain()->NewString( strOutText );
		}
	}
	
	return NULL;
}

MonoObject* CMonoFunctions::Player::GetNametagColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucR, ucG, ucB;
		
		if( CLuaFunctionDefinitions::GetPlayerNametagColor( RESOURCE->GetLua(), (void*)pUserData, ucR, ucG, ucB ) )
		{
			void *args[] =
			{
				&ucR, &ucG, &ucB
			};
			
			return RESOURCE->GetDomain()->GetMTALib()->Color->New( args, 3 );
		}
	}
	
	return NULL;
}

bool CMonoFunctions::Player::IsNametagShowing( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bShowing;
		
		if( CLuaFunctionDefinitions::IsPlayerNametagShowing( RESOURCE->GetLua(), (void*)pUserData, bShowing ) )
		{
			return bShowing;
		}
	}
	
	return false;
}

MonoString* CMonoFunctions::Player::GetSerial( DWORD pUserData )
{
	if( RESOURCE )
	{
		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerSerial( RESOURCE->GetLua(), (void*)pUserData ) );
	}
	
	return NULL;
}

MonoString* CMonoFunctions::Player::GetUserName( DWORD pUserData )
{
	if( RESOURCE )
	{
		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerUserName( RESOURCE->GetLua(), (void*)pUserData ) );
	}
	
	return NULL;
}

unsigned char CMonoFunctions::Player::GetBlurLevel( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucBlurLevel;
		
		if( CLuaFunctionDefinitions::GetPlayerBlurLevel( RESOURCE->GetLua(), (void*)pUserData, ucBlurLevel ) )
		{
			return ucBlurLevel;
		}
	}
	
	return 0;
}

MonoString* CMonoFunctions::Player::GetName( DWORD pUserData )
{
	if( RESOURCE )
	{
		string strOutName;
		
		if( CLuaFunctionDefinitions::GetPlayerName( RESOURCE->GetLua(), (void*)pUserData, strOutName ) )
		{
			return RESOURCE->GetDomain()->NewString( strOutName );
		}
	}
	
	return NULL;
}

MonoString* CMonoFunctions::Player::GetIP( DWORD pUserData )
{
	if( RESOURCE )
	{
		string strIP;
		
		if( CLuaFunctionDefinitions::GetPlayerIP( RESOURCE->GetLua(), (void*)pUserData, strIP ) )
		{
			return RESOURCE->GetDomain()->NewString( strIP );
		}
	}
	
	return NULL;
}

DWORD CMonoFunctions::Player::GetAccount( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetPlayerAccount( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return NULL;
}

MonoString* CMonoFunctions::Player::GetVersion( DWORD pUserData )
{
	if( RESOURCE )
	{
		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerVersion( RESOURCE->GetLua(), (void*)pUserData ) );
	}
	
	return NULL;
}

MonoObject* CMonoFunctions::Player::GetACInfo( DWORD pUserData )
{
	if( RESOURCE )
	{
		LuaTable pLuaTable = CLuaFunctionDefinitions::GetPlayerACInfo( RESOURCE->GetLua(), (void*)pUserData );

		if( !pLuaTable.empty() )
		{
			MonoString* msDetectedAC	= RESOURCE->GetDomain()->NewString( pLuaTable[ "DetectedAC" ]->GetString() );
			MonoString* msD3D9MD5		= RESOURCE->GetDomain()->NewString( pLuaTable[ "d3d9MD5" ]->GetString() );
			MonoString* msD3D9SHA256	= RESOURCE->GetDomain()->NewString( pLuaTable[ "d3d9SHA256" ]->GetString() );

			unsigned int iD3D9Size		= pLuaTable[ "d3d9Size" ]->GetNumber< unsigned int >();

			void *args[] =
			{
				&msDetectedAC,
				&iD3D9Size,
				&msD3D9MD5,
				&msD3D9SHA256
			};

			return RESOURCE->GetDomain()->GetMTALib()->GetClass( "PlayerACInfo" )->New( args, 4 );
		}
	}
	return NULL;
}

MonoString* CMonoFunctions::Player::GetPlayerAnnounceValue( DWORD pElement, MonoString* msKey )
{
	if( RESOURCE )
	{
		const char* szKey = mono_string_to_utf8( msKey );

		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetPlayerAnnounceValue( RESOURCE->GetLua(), (void*)pElement, szKey ) );
	}

	return NULL;
}


// Player set functions
bool CMonoFunctions::Player::SetMoney( DWORD pUserData, int iAmount, bool bInstant )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerMoney( RESOURCE->GetLua(), (void*)pUserData, iAmount, bInstant );
	}
	
	return false;
}

bool CMonoFunctions::Player::GiveMoney( DWORD pUserData, int iAmount )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GivePlayerMoney( RESOURCE->GetLua(), (void*)pUserData, iAmount );
	}
	
	return false;
}

bool CMonoFunctions::Player::TakeMoney( DWORD pUserData, int iAmount )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::TakePlayerMoney( RESOURCE->GetLua(), (void*)pUserData, iAmount );
	}
	
	return false;
}

bool CMonoFunctions::Player::Spawn( DWORD pUserData, MonoObject* pPosition, int iRotation, int iSkinID, int iInterior, int iDimension, DWORD pTeam )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		return CLuaFunctionDefinitions::SpawnPlayer( RESOURCE->GetLua(), (void*)pUserData, vecPosition, iRotation, iSkinID, iInterior, iDimension, (void*)pTeam );
	}
	
	return false;
}

bool CMonoFunctions::Player::ShowHudComponent( DWORD pUserData, MonoString* msComponent, bool bShow )
{
	if( RESOURCE )
	{
		string strComponent( mono_string_to_utf8( msComponent ) );

		return CLuaFunctionDefinitions::ShowPlayerHudComponent( RESOURCE->GetLua(), (void*)pUserData, strComponent, bShow );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetWantedLevel( DWORD pUserData, int iLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerWantedLevel( RESOURCE->GetLua(), (void*)pUserData, iLevel );
	}
	
	return false;
}

bool CMonoFunctions::Player::ForceMap( DWORD pUserData, bool bForceOn )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ForcePlayerMap( RESOURCE->GetLua(), (void*)pUserData, bForceOn );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetNametagText( DWORD pUserData, MonoString* sText )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerNametagText( RESOURCE->GetLua(), (void*)pUserData, string( mono_string_to_utf8( sText ) ) );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetNametagColor( DWORD pUserData, int iRed, int iGreen, int iBlue )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerNametagColor( RESOURCE->GetLua(), (void*)pUserData, iRed, iGreen, iBlue );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetNametagShowing( DWORD pUserData, bool bShowing )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerNametagShowing( RESOURCE->GetLua(), (void*)pUserData, bShowing );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetMuted( DWORD pUserData, bool bMuted )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerMuted( RESOURCE->GetLua(), (void*)pUserData, bMuted );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetBlurLevel( DWORD pUserData, int iLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerBlurLevel( RESOURCE->GetLua(), (void*)pUserData, iLevel );
	}
	
	return false;
}

bool CMonoFunctions::Player::Redirect( DWORD pUserData, MonoString* sServerIP, int iServerPort, MonoString* sServerPassword )
{
	if( RESOURCE )
	{
		const char* szServerIP			= mono_string_to_utf8( sServerIP );
		const char* szServerPassword	= mono_string_to_utf8( sServerPassword );
		
		return CLuaFunctionDefinitions::RedirectPlayer( RESOURCE->GetLua(), (void*)pUserData, szServerIP, iServerPort, szServerPassword );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetName( DWORD pUserData, MonoString* sName )
{
	if( RESOURCE )
	{
		const char* szName			= mono_string_to_utf8( sName );
		
		return CLuaFunctionDefinitions::SetPlayerName( RESOURCE->GetLua(), (void*)pUserData, szName );
	}
	
	return false;
}

bool CMonoFunctions::Player::DetonateSatchels( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::DetonateSatchels( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return false;
}

bool CMonoFunctions::Player::TakeScreenShot( DWORD pUserData, int iWidth, int iHeight, MonoString* sTag, int iQuality, int iMaxBandwith )
{
	if( RESOURCE )
	{
		string strTag( mono_string_to_utf8( sTag ) );

		return CLuaFunctionDefinitions::TakePlayerScreenShot( RESOURCE->GetLua(), (void*)pUserData, iWidth, iHeight, strTag, iQuality, iMaxBandwith );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetTeam( DWORD pUserData, DWORD pTeam )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPlayerTeam( RESOURCE->GetLua(), (void*)pUserData, (void*)pTeam );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetPlayerAnnounceValue( DWORD pElement, MonoString* msKey, MonoString* msValue )
{

	if( RESOURCE )
	{
		const char* szKey	= mono_string_to_utf8( msKey );
		const char* szValue	= mono_string_to_utf8( msValue );

		return CLuaFunctionDefinitions::SetPlayerAnnounceValue( RESOURCE->GetLua(), (void*)pElement, szKey, szValue );
	}

	return NULL;
}

// Input funcs

bool CMonoFunctions::Player::BindKey( DWORD pUserData, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName, MonoString* msArguments )
{
	if( RESOURCE )
	{
		const char* szKey			= mono_string_to_utf8( msKey );
		const char* szHitState		= mono_string_to_utf8( msHitState );
		const char* szCommandName	= mono_string_to_utf8( msCommandName );
		const char* szArguments		= mono_string_to_utf8( msArguments );

		return CLuaFunctionDefinitions::BindKey( RESOURCE->GetLua(), (void*)pUserData, szKey, szHitState, szCommandName, szArguments );
	}
	
	return false;
}

bool CMonoFunctions::Player::UnbindKey( DWORD pUserData, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName )
{
	if( RESOURCE )
	{
		const char* szKey			= mono_string_to_utf8( msKey );
		const char* szHitState		= mono_string_to_utf8( msHitState );
		const char* szCommandName	= mono_string_to_utf8( msCommandName );
		
		return CLuaFunctionDefinitions::UnbindKey( RESOURCE->GetLua(), (void*)pUserData, szKey, szHitState, szCommandName );
	}
	
	return false;
}

bool CMonoFunctions::Player::GetControlState( DWORD pUserData, MonoString* msControl )
{
	if( RESOURCE )
	{
		const char* szControl = mono_string_to_utf8( msControl );
		
		bool bState;

		if( CLuaFunctionDefinitions::GetControlState( RESOURCE->GetLua(), (void*)pUserData, szControl, bState ) )
		{
			return bState;
		}
	}
	
	return false;
}

bool CMonoFunctions::Player::IsControlEnabled( DWORD pUserData, MonoString* msControl )
{
	if( RESOURCE )
	{
		const char* szControl = mono_string_to_utf8( msControl );
		
		bool bEnabled;

		if( CLuaFunctionDefinitions::IsControlEnabled( RESOURCE->GetLua(), (void*)pUserData, szControl, bEnabled ) )
		{
			return bEnabled;
		}
	}
	
	return false;
}

		
bool CMonoFunctions::Player::SetControlState( DWORD pUserData, MonoString* msControl, bool bState )
{
	if( RESOURCE )
	{
		const char* szControl			= mono_string_to_utf8( msControl );
		
		return CLuaFunctionDefinitions::SetControlState( RESOURCE->GetLua(), (void*)pUserData, szControl, bState );
	}
	
	return false;
}

bool CMonoFunctions::Player::ToggleControl( DWORD pUserData, MonoString* msControl, bool bEnabled )
{
	if( RESOURCE )
	{
		const char* szControl			= mono_string_to_utf8( msControl );
		
		return CLuaFunctionDefinitions::ToggleControl( RESOURCE->GetLua(), (void*)pUserData, szControl, bEnabled );
	}
	
	return false;
}

bool CMonoFunctions::Player::ToggleAllControls( DWORD pUserData, bool bGTAControls, bool bMTAControls, bool bEnabled )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ToggleAllControls( RESOURCE->GetLua(), (void*)pUserData, bGTAControls, bMTAControls, bEnabled );
	}
	
	return false;
}


// Log in/out funcs
bool CMonoFunctions::Player::LogIn( DWORD pPlayer, DWORD pAccount, MonoString* msPassword )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::LogIn( RESOURCE->GetLua(), (void*)pPlayer, (void*)pAccount, mono_string_to_utf8( msPassword ) );
	}
	
	return false;
}

bool CMonoFunctions::Player::LogOut( DWORD pPlayer )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::LogOut( RESOURCE->GetLua(), (void*)pPlayer );
	}
	
	return false;
}


// Admin funcs
bool CMonoFunctions::Player::Kick( DWORD pPlayer, MonoString* msResponsible, MonoString* msReason )
{
	if( RESOURCE )
	{
		string
			strResponsible( mono_string_to_utf8( msResponsible ) ),
			strReason( mono_string_to_utf8( msReason ) );
		
		return CLuaFunctionDefinitions::KickPlayer( RESOURCE->GetLua(), (void*)pPlayer, strResponsible, strReason );
	}
	
	return false;
}

DWORD CMonoFunctions::Player::Ban( DWORD pPlayer, bool bIP, bool bUsername, bool bSerial, DWORD pResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban )
{
	if( RESOURCE )
	{
		string
			strResponsible( mono_string_to_utf8( msResponsible ) ),
			strReason( mono_string_to_utf8( msReason ) );
		
		return (DWORD)CLuaFunctionDefinitions::BanPlayer( RESOURCE->GetLua(), (void*)pPlayer, bIP, bUsername, bSerial, (void*)pResponsible, strResponsible, strReason, iUnban );
	}
	
	return false;
}

		
// Cursor get funcs
bool CMonoFunctions::Player::IsCursorShowing( DWORD pPlayer )
{
	if( RESOURCE )
	{
		bool bShowing;
		
		if( CLuaFunctionDefinitions::IsCursorShowing( RESOURCE->GetLua(), (void*)pPlayer, bShowing ) )
		{
			return bShowing;
		}
	}
	
	return false;
}

		
// Cursor set funcs
bool CMonoFunctions::Player::ShowCursor( DWORD pPlayer, bool bShow, bool bToggleControls )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ShowCursor( RESOURCE->GetLua(), (void*)pPlayer, bShow, bToggleControls );
	}
	
	return false;
}

		
// Chat funcs
bool CMonoFunctions::Player::ShowChat( DWORD pPlayer, bool bShow )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ShowChat( RESOURCE->GetLua(), (void*)pPlayer, bShow );
	}
	
	return false;
}


// Camera get functions
MonoObject* CMonoFunctions::Player::GetCameraMatrix( DWORD pPlayer )
{
	if( RESOURCE )
	{
		Vector3 vecPosition, vecLookAt;
		
		float fRoll, fFOV;

		if( CLuaFunctionDefinitions::GetCameraMatrix( RESOURCE->GetLua(), (void*)pPlayer, vecPosition, vecLookAt, fRoll, fFOV ) )
		{
			void *args[] =
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

			return RESOURCE->GetDomain()->GetMTALib()->GetClass( "CameraMatrix" )->New( args, 8 );
		}
	}

	return NULL;
}

DWORD CMonoFunctions::Player::GetCameraTarget( DWORD pPlayer )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetCameraTarget( RESOURCE->GetLua(), (void*)pPlayer );
	}
	
	return false;
}

unsigned char CMonoFunctions::Player::GetCameraInterior( DWORD pPlayer )
{
	if( RESOURCE )
	{
		unsigned char ucInterior;
		
		if( CLuaFunctionDefinitions::GetCameraInterior( RESOURCE->GetLua(), (void*)pPlayer, ucInterior ) )
		{
			return ucInterior;
		}
	}
	
	return 0;
}


// Camera set functions
bool CMonoFunctions::Player::SetCameraMatrix( DWORD pPlayer, MonoObject* pCameraMatrix )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "Y" );
		float fZ = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "Z" );

		Vector3 vecPosition( fX, fY, fZ );
		
		float fLookAtX = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "LookAtX" );
		float fLookAtY = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "LookAtY" );
		float fLookAtZ = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "LookAtZ" );

		Vector3 vecLookAt( fLookAtX, fLookAtY, fLookAtZ );

		float fRoll = CMonoObject::GetPropertyValue< float >( pCameraMatrix, "Roll" );
		float fFOV	= CMonoObject::GetPropertyValue< float >( pCameraMatrix, "FOV" );

		return CLuaFunctionDefinitions::SetCameraMatrix( RESOURCE->GetLua(), (void*)pPlayer, vecPosition, vecLookAt, fRoll, fFOV );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetCameraTarget( DWORD pPlayer, DWORD pTarget )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetCameraTarget( RESOURCE->GetLua(), (void*)pPlayer, (void*)pTarget );
	}
	
	return false;
}

bool CMonoFunctions::Player::SetCameraInterior( DWORD pPlayer, unsigned char ucInterior )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetCameraInterior( RESOURCE->GetLua(), (void*)pPlayer, ucInterior );
	}
	
	return false;
}

bool CMonoFunctions::Player::FadeCamera( DWORD pPlayer, bool bFadeIn, float fFadeTime, MonoObject* pColor )
{
	if( RESOURCE )
	{
		unsigned char ucReed	= CMonoObject::GetPropertyValue< unsigned char >( pColor, "R" );
		unsigned char ucGreen	= CMonoObject::GetPropertyValue< unsigned char >( pColor, "G" );
		unsigned char ucBlue	= CMonoObject::GetPropertyValue< unsigned char >( pColor, "B" );

		return CLuaFunctionDefinitions::FadeCamera( RESOURCE->GetLua(), (void*)pPlayer, bFadeIn, fFadeTime, ucReed, ucGreen, ucBlue );
	}
	
	return false;
}

#endif