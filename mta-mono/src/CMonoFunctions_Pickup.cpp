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

#include "CMonoFunctions.h"

// Pickup create/destroy funcs
DWORD CMonoFunctions::Pickup::Create( MonoObject* pPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval, double dSix )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		return (DWORD)CLuaFunctionDefinitions::CreatePickup( RESOURCE->GetLua(), vecPosition, ucType, dFive, ulRespawnInterval, dSix );
	}

	return NULL;
}


// Pickup get funcs
unsigned char CMonoFunctions::Pickup::GetType( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucType;
		
		if( CLuaFunctionDefinitions::GetPickupType( RESOURCE->GetLua(), (void*)pUserData, ucType ) )
		{
			return ucType;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Pickup::GetWeapon( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucWeapon;
		
		if( CLuaFunctionDefinitions::GetPickupWeapon( RESOURCE->GetLua(), (void*)pUserData, ucWeapon ) )
		{
			return ucWeapon;
		}
	}

	return 0;
}

float CMonoFunctions::Pickup::GetAmount( DWORD pUserData )
{
	if( RESOURCE )
	{
		float fAmount;
		
		if( CLuaFunctionDefinitions::GetPickupAmount( RESOURCE->GetLua(), (void*)pUserData, fAmount ) )
		{
			return fAmount;
		}
	}

	return 0;
}

unsigned short CMonoFunctions::Pickup::GetAmmo( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned short usAmmo;
		
		if( CLuaFunctionDefinitions::GetPickupAmmo( RESOURCE->GetLua(), (void*)pUserData, usAmmo ) )
		{
			return usAmmo;
		}
	}

	return 0;
}

unsigned long CMonoFunctions::Pickup::GetRespawnInterval( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned long ulInterval;
		
		if( CLuaFunctionDefinitions::GetPickupRespawnInterval( RESOURCE->GetLua(), (void*)pUserData, ulInterval ) )
		{
			return ulInterval;
		}
	}

	return 0;
}

bool CMonoFunctions::Pickup::IsSpawned( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bSpawned;
		
		if( CLuaFunctionDefinitions::IsPickupSpawned( RESOURCE->GetLua(), (void*)pUserData, bSpawned ) )
		{
			return bSpawned;
		}
	}

	return false;
}


// Pickup set funcs
bool CMonoFunctions::Pickup::SetType( DWORD pUserData, unsigned char ucType, double dThree, double dFour )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPickupType( RESOURCE->GetLua(), (void*)pUserData, ucType, dThree, dFour );
	}

	return false;
}

bool CMonoFunctions::Pickup::SetRespawnInterval( DWORD pUserData, unsigned long ulInterval )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPickupRespawnInterval( RESOURCE->GetLua(), (void*)pUserData, ulInterval );
	}

	return false;
}

bool CMonoFunctions::Pickup::Use( DWORD pUserData, DWORD pPlayer )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::UsePickup( RESOURCE->GetLua(), (void*)pUserData, (void*)pPlayer );
	}

	return false;
}
