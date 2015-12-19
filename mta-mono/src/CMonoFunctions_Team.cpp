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

// Team get funcs
DWORD CMonoFunctions::Team::Create( MonoString* msTeamName, MonoObject* mColor )
{
	if( RESOURCE )
	{
		const char*	szTeamName	= mono_string_to_utf8( msTeamName );
		SColor pColor			= CMonoObject::GetColor( mColor );

		return (DWORD)CLuaFunctionDefinitions::CreateTeam( RESOURCE->GetLua(), szTeamName, pColor.R, pColor.G, pColor.B );
	}

	return NULL;
}

DWORD CMonoFunctions::Team::GetFromName( MonoString* msTeamName )
{
	if( RESOURCE )
	{
		const char*	szTeamName	= mono_string_to_utf8( msTeamName );

		return (DWORD)CLuaFunctionDefinitions::GetTeamFromName( RESOURCE->GetLua(), szTeamName );
	}

	return NULL;
}

MonoString* CMonoFunctions::Team::GetName( DWORD pUserData )
{
	if( RESOURCE )
	{
		string strOutName;

		if( CLuaFunctionDefinitions::GetTeamName( RESOURCE->GetLua(), (void*)pUserData, strOutName ) )
		{
			return RESOURCE->GetDomain()->NewString( strOutName );
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Team::GetColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		SColor pColor;

		if( CLuaFunctionDefinitions::GetTeamColor( RESOURCE->GetLua(), (void*)pUserData, pColor.R, pColor.G, pColor.B ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Color->New( pColor );
		}
	}

	return NULL;
}

unsigned int CMonoFunctions::Team::CountPlayers( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned int uiCount;
		
		if( CLuaFunctionDefinitions::CountPlayersInTeam( RESOURCE->GetLua(), (void*)pUserData, uiCount ) )
		{
			return uiCount;
		}
	}

	return 0;
}

bool CMonoFunctions::Team::GetFriendlyFire( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bFriendlyFire;
		
		if( CLuaFunctionDefinitions::GetTeamFriendlyFire( RESOURCE->GetLua(), (void*)pUserData, bFriendlyFire ) )
		{
			return bFriendlyFire;
		}
	}

	return false;
}


// Team set funcs
bool CMonoFunctions::Team::SetName( DWORD pUserData, MonoString* msTeamName )
{
	if( RESOURCE )
	{
		const char* szTeamName = mono_string_to_utf8( msTeamName );

		return CLuaFunctionDefinitions::SetTeamName( RESOURCE->GetLua(), (void*)pUserData, szTeamName );
	}

	return false;
}

bool CMonoFunctions::Team::SetColor( DWORD pUserData, MonoObject* mColor )
{
	if( RESOURCE )
	{
		SColor pColor = CMonoObject::GetColor( mColor );

		return CLuaFunctionDefinitions::SetTeamColor( RESOURCE->GetLua(), (void*)pUserData, pColor.R, pColor.G, pColor.B );
	}

	return false;
}

bool CMonoFunctions::Team::SetFriendlyFire( DWORD pUserData, bool bFriendlyFire )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTeamFriendlyFire( RESOURCE->GetLua(), (void*)pUserData, bFriendlyFire );
	}

	return false;
}
