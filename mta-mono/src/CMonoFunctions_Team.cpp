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
void CMonoFunctions::Team::Ctor( TElement pThis, MonoString* msTeamName, MonoObject* mColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char*	szTeamName	= mono_string_to_utf8( msTeamName );
		SColor pColor			= CMonoObject::GetColor( mColor );

		PVOID pUserData = CLuaFunctionDefinitions::CreateTeam( pResource->GetLua(), szTeamName, pColor.R, pColor.G, pColor.B );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

TElement CMonoFunctions::Team::GetFromName( MonoString* msTeamName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char*	szTeamName	= mono_string_to_utf8( msTeamName );

		PVOID pUserData = CLuaFunctionDefinitions::GetTeamFromName( pResource->GetLua(), szTeamName );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Team::GetName( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetTeamName( pResource->GetLua(), pElement->ToLuaUserData(), strOutName ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Team::GetColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pColor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetTeamColor( pResource->GetLua(), pElement->ToLuaUserData(), pColor.R, pColor.G, pColor.B ) )
		{
			return pResource->GetDomain()->GetMTALib()->Color->New( pColor );
		}
	}

	return nullptr;
}

unsigned int CMonoFunctions::Team::CountPlayers( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiCount;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::CountPlayersInTeam( pResource->GetLua(), pElement->ToLuaUserData(), uiCount ) )
		{
			return uiCount;
		}
	}

	return 0;
}

bool CMonoFunctions::Team::GetFriendlyFire( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bFriendlyFire;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetTeamFriendlyFire( pResource->GetLua(), pElement->ToLuaUserData(), bFriendlyFire ) )
		{
			return bFriendlyFire;
		}
	}

	return false;
}


// Team set funcs
bool CMonoFunctions::Team::SetName( TElement pThis, MonoString* msTeamName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szTeamName = mono_string_to_utf8( msTeamName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTeamName( pResource->GetLua(), pElement->ToLuaUserData(), szTeamName );
	}

	return false;
}

bool CMonoFunctions::Team::SetColor( TElement pThis, MonoObject* mColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pColor = CMonoObject::GetColor( mColor );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTeamColor( pResource->GetLua(), pElement->ToLuaUserData(), pColor.R, pColor.G, pColor.B );
	}

	return false;
}

bool CMonoFunctions::Team::SetFriendlyFire( TElement pThis, bool bFriendlyFire )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTeamFriendlyFire( pResource->GetLua(), pElement->ToLuaUserData(), bFriendlyFire );
	}

	return false;
}
