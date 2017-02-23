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

// Pickup create/destroy funcs
void CMonoFunctions::Pickup::Ctor( TElement pThis, MonoObject* pPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval, double dSix )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );

		PVOID pUserData = CLuaFunctionDefinitions::CreatePickup( pResource->GetLua(), vecPosition, ucType, dFive, ulRespawnInterval, dSix );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}


// Pickup get funcs
unsigned char CMonoFunctions::Pickup::GetPickupType( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucType;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPickupType( pResource->GetLua(), pElement->GetLuaUserdata(), ucType ) )
		{
			return ucType;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Pickup::GetWeapon( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucWeapon;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPickupWeapon( pResource->GetLua(), pElement->GetLuaUserdata(), ucWeapon ) )
		{
			return ucWeapon;
		}
	}

	return 0;
}

float CMonoFunctions::Pickup::GetAmount( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fAmount;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPickupAmount( pResource->GetLua(), pElement->GetLuaUserdata(), fAmount ) )
		{
			return fAmount;
		}
	}

	return 0;
}

unsigned short CMonoFunctions::Pickup::GetAmmo( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned short usAmmo;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPickupAmmo( pResource->GetLua(), pElement->GetLuaUserdata(), usAmmo ) )
		{
			return usAmmo;
		}
	}

	return 0;
}

unsigned long CMonoFunctions::Pickup::GetRespawnInterval( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned long ulInterval;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPickupRespawnInterval( pResource->GetLua(), pElement->GetLuaUserdata(), ulInterval ) )
		{
			return ulInterval;
		}
	}

	return 0;
}

bool CMonoFunctions::Pickup::IsSpawned( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bSpawned;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPickupSpawned( pResource->GetLua(), pElement->GetLuaUserdata(), bSpawned ) )
		{
			return bSpawned;
		}
	}

	return false;
}


// Pickup set funcs
bool CMonoFunctions::Pickup::SetType( TElement pThis, unsigned char ucType, double dThree, double dFour )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPickupType( pResource->GetLua(), pElement->GetLuaUserdata(), ucType, dThree, dFour );
	}

	return false;
}

bool CMonoFunctions::Pickup::SetRespawnInterval( TElement pThis, unsigned long ulInterval )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPickupRespawnInterval( pResource->GetLua(), pElement->GetLuaUserdata(), ulInterval );
	}

	return false;
}

bool CMonoFunctions::Pickup::Use( TElement pThis, TElement pPlayer )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pPlayerElement = pResource->GetElementManager()->GetFromList( pPlayer );
		
		return CLuaFunctionDefinitions::UsePickup( pResource->GetLua(), pElement->GetLuaUserdata(), pPlayerElement->GetLuaUserdata() );
	}

	return false;
}
