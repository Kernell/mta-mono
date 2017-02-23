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

// Ped get functions
void CMonoFunctions::Ped::Ctor( TElement pThis, int iModelid, MonoObject* pMonoPosition, float fRot, bool bSynced )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pMonoPosition );
		
		PVOID pUserData = CLuaFunctionDefinitions::CreatePed( pResource->GetLua(), iModelid, vecPosition, fRot, bSynced );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

float CMonoFunctions::Ped::GetArmor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fArmor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedArmor( pResource->GetLua(), pElement->GetLuaUserdata(), fArmor ) )
		{
			return fArmor;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::Ped::IsChoking( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bChoking;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedChoking( pResource->GetLua(), pElement->GetLuaUserdata(), bChoking ) )
		{
			return bChoking;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsDead( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDead;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedDead( pResource->GetLua(), pElement->GetLuaUserdata(), bDead ) )
		{
			return bDead;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsDucked( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDucked;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedDucked( pResource->GetLua(), pElement->GetLuaUserdata(), bDucked ) )
		{
			return bDucked;
		}
	}

	return false;
}

float CMonoFunctions::Ped::GetStat( TElement pThis, unsigned short usStat )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fStat;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedStat( pResource->GetLua(), pElement->GetLuaUserdata(), usStat, fStat ) )
		{
			return fStat;
		}
	}

	return 0.0f;
}

TElement CMonoFunctions::Ped::GetTarget( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetPedTarget( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

int CMonoFunctions::Ped::GetWeapon( TElement pThis, int iWeaponSlot )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::GetPedWeapon( pResource->GetLua(), pElement->GetLuaUserdata(), iWeaponSlot );
	}

	return 0;
}

MonoString* CMonoFunctions::Ped::GetClothesTexture( TElement pThis, unsigned char ucType )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutTexture, strOutModel;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedClothes( pResource->GetLua(), pElement->GetLuaUserdata(), ucType, strOutTexture, strOutModel ) )
		{
			return pResource->GetDomain()->NewString( strOutTexture );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ped::GetClothesModel( TElement pThis, unsigned char ucType )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutTexture, strOutModel;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedClothes( pResource->GetLua(), pElement->GetLuaUserdata(), ucType, strOutTexture, strOutModel ) )
		{
			return pResource->GetDomain()->NewString( strOutModel );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Ped::DoesHaveJetPack( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bHasJetPack;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::DoesPedHaveJetPack( pResource->GetLua(), pElement->GetLuaUserdata(), bHasJetPack ) )
		{
			return bHasJetPack;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsOnGround( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bOnGround;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedOnGround( pResource->GetLua(), pElement->GetLuaUserdata(), bOnGround ) )
		{
			return bOnGround;
		}
	}

	return false;
}

unsigned char CMonoFunctions::Ped::GetFightingStyle( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucStyle;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedFightingStyle( pResource->GetLua(), pElement->GetLuaUserdata(), ucStyle ) )
		{
			return ucStyle;
		}
	}

	return 0;
}

unsigned int CMonoFunctions::Ped::GetMoveAnim( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiMoveAnim;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedMoveAnim( pResource->GetLua(), pElement->GetLuaUserdata(), uiMoveAnim ) )
		{
			return uiMoveAnim;
		}
	}

	return 0;
}

float CMonoFunctions::Ped::GetGravity( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fGravity;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedGravity( pResource->GetLua(), pElement->GetLuaUserdata(), fGravity ) )
		{
			return fGravity;
		}
	}

	return 0.0f;
}

TElement CMonoFunctions::Ped::GetContactElement( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetPedContactElement( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

unsigned char CMonoFunctions::Ped::GetWeaponSlot( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucWeaponSlot;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedWeaponSlot( pResource->GetLua(), pElement->GetLuaUserdata(), ucWeaponSlot ) )
		{
			return ucWeaponSlot;
		}
	}

	return 0;
}

bool CMonoFunctions::Ped::IsDoingGangDriveby( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDoingGangDriveby;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedDoingGangDriveby( pResource->GetLua(), pElement->GetLuaUserdata(), bDoingGangDriveby ) )
		{
			return bDoingGangDriveby;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsOnFire( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bOnFire;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedOnFire( pResource->GetLua(), pElement->GetLuaUserdata(), bOnFire ) )
		{
			return bOnFire;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsHeadless( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bHeadless;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedHeadless( pResource->GetLua(), pElement->GetLuaUserdata(), bHeadless ) )
		{
			return bHeadless;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsFrozen( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bFrozen;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedFrozen( pResource->GetLua(), pElement->GetLuaUserdata(), bFrozen ) )
		{
			return bFrozen;
		}
	}

	return false;
}

TElement CMonoFunctions::Ped::GetOccupiedVehicle( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetPedOccupiedVehicle( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

unsigned int CMonoFunctions::Ped::GetOccupiedVehicleSeat( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiSeat;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetPedOccupiedVehicleSeat( pResource->GetLua(), pElement->GetLuaUserdata(), uiSeat ) )
		{
			return uiSeat;
		}
	}

	return 0;
}

bool CMonoFunctions::Ped::IsInVehicle( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bInVehicle;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsPedInVehicle( pResource->GetLua(), pElement->GetLuaUserdata(), bInVehicle ) )
		{
			return bInVehicle;
		}
	}

	return false;
}

short CMonoFunctions::Ped::GetWeaponProperty( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		short uData;

		const char* szWeaponSkill	= mono_string_to_utf8( msWeaponSkill );
		const char* szProperty		= mono_string_to_utf8( msProperty );
		
		if( CLuaFunctionDefinitions::GetWeaponProperty( pResource->GetLua(), ucWeaponID, szWeaponSkill, szProperty, uData ) )
		{
			return uData;
		}
	}

	return 0;
}

short CMonoFunctions::Ped::GetOriginalWeaponProperty( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		short uData;

		const char* szWeaponSkill	= mono_string_to_utf8( msWeaponSkill );
		const char* szProperty		= mono_string_to_utf8( msProperty );
		
		if( CLuaFunctionDefinitions::GetOriginalWeaponProperty( pResource->GetLua(), ucWeaponID, szWeaponSkill, szProperty, uData ) )
		{
			return uData;
		}
	}

	return 0;
}


// Ped set functions
bool CMonoFunctions::Ped::SetArmor( TElement pThis, float fArmor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedArmor( pResource->GetLua(), pElement->GetLuaUserdata(), fArmor );
	}
	
	return false;
}

bool CMonoFunctions::Ped::Kill( TElement pThis, TElement pKiller, unsigned char ucKillerWeapon, unsigned char ucBodyPart, bool bStealth )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pKillerElement = pResource->GetElementManager()->GetFromList( pKiller );
		
		return CLuaFunctionDefinitions::KillPed( pResource->GetLua(), pElement->GetLuaUserdata(), pKillerElement->GetLuaUserdata(), ucKillerWeapon, ucBodyPart, bStealth );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetStat( TElement pThis, unsigned short usStat, float fValue )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedStat( pResource->GetLua(), pElement->GetLuaUserdata(), usStat, fValue );
	}
	
	return false;
}

bool CMonoFunctions::Ped::AddClothes( TElement pThis, MonoString* msTexture, MonoString* msModel, unsigned char ucType )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szTexture	= mono_string_to_utf8( msTexture );
		const char* szModel		= mono_string_to_utf8( msModel );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::AddPedClothes( pResource->GetLua(), pElement->GetLuaUserdata(), szTexture, szModel, ucType );
	}
	
	return false;
}

bool CMonoFunctions::Ped::RemoveClothes( TElement pThis, unsigned char ucType, MonoString* msTexture, MonoString* msModel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szTexture	= mono_string_to_utf8( msTexture );
		const char* szModel		= mono_string_to_utf8( msModel );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RemovePedClothes( pResource->GetLua(), pElement->GetLuaUserdata(), ucType, szTexture, szModel );
	}
	
	return false;
}

bool CMonoFunctions::Ped::GiveJetPack( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::GivePedJetPack( pResource->GetLua(), pElement->GetLuaUserdata() );
	}
	
	return false;
}

bool CMonoFunctions::Ped::RemoveJetPack( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RemovePedJetPack( pResource->GetLua(), pElement->GetLuaUserdata() );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetFightingStyle( TElement pThis, unsigned char ucStyle )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedFightingStyle( pResource->GetLua(), pElement->GetLuaUserdata(), ucStyle );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetMoveAnim( TElement pThis, unsigned int iMoveAnim )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedMoveAnim( pResource->GetLua(), pElement->GetLuaUserdata(), iMoveAnim );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetGravity( TElement pThis, float fGravity )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedGravity( pResource->GetLua(), pElement->GetLuaUserdata(), fGravity );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetChoking( TElement pThis, bool bChoking )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedChoking( pResource->GetLua(), pElement->GetLuaUserdata(), bChoking );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetWeaponSlot( TElement pThis, unsigned char ucWeaponSlot )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedWeaponSlot( pResource->GetLua(), pElement->GetLuaUserdata(), ucWeaponSlot );
	}
	
	return false;
}

bool CMonoFunctions::Ped::WarpIntoVehicle( TElement pThis, TElement pVehicle, unsigned int uiSeat )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pVehicleElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::WarpPedIntoVehicle( pResource->GetLua(), pElement->GetLuaUserdata(), pVehicleElement->GetLuaUserdata(), uiSeat );
	}
	
	return false;
}

bool CMonoFunctions::Ped::RemoveFromVehicle( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RemovePedFromVehicle( pResource->GetLua(), pElement->GetLuaUserdata() );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetDoingGangDriveby( TElement pThis, bool bGangDriveby )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedDoingGangDriveby( pResource->GetLua(), pElement->GetLuaUserdata(), bGangDriveby );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetAnimation( TElement pThis, MonoString* msBlockName, MonoString* msAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szBlockName	= mono_string_to_utf8( msBlockName );
		const char* szAnimName	= mono_string_to_utf8( msAnimName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedAnimation( pResource->GetLua(), pElement->GetLuaUserdata(), szBlockName, szAnimName, iTime, bLoop, bUpdatePosition, bInterruptable, bFreezeLastFrame );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetAnimationProgress( TElement pThis, MonoString* msAnimName, float fProgress )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szAnimName	= mono_string_to_utf8( msAnimName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedAnimationProgress( pResource->GetLua(), pElement->GetLuaUserdata(), szAnimName, fProgress );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetOnFire( TElement pThis, bool bIsOnFire )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedOnFire( pResource->GetLua(), pElement->GetLuaUserdata(), bIsOnFire );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetHeadless( TElement pThis, bool bIsHeadless )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedHeadless( pResource->GetLua(), pElement->GetLuaUserdata(), bIsHeadless );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetFrozen( TElement pThis, bool bIsFrozen )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetPedFrozen( pResource->GetLua(), pElement->GetLuaUserdata(), bIsFrozen );
	}
	
	return false;
}

bool CMonoFunctions::Ped::ReloadWeapon( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ReloadPedWeapon( pResource->GetLua(), pElement->GetLuaUserdata() );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetWeaponProperty( unsigned char ucWeaponID, MonoString* msWeaponSkill, MonoString* msProperty, short uData )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szWeaponSkill	= mono_string_to_utf8( msWeaponSkill );
		const char* szProperty		= mono_string_to_utf8( msProperty );
		
		return CLuaFunctionDefinitions::SetWeaponProperty( pResource->GetLua(), ucWeaponID, szWeaponSkill, szProperty, uData );
	}
	
	return false;
}


// Ped body?
MonoString* CMonoFunctions::Ped::GetBodyPartName( unsigned char ucID )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		char* szName = nullptr;
		
		if( CLuaFunctionDefinitions::GetBodyPartName( pResource->GetLua(), ucID, szName ) )
		{
			return pResource->GetDomain()->NewString( szName );
		}
	}
	
	return nullptr;
}

MonoArray* CMonoFunctions::Ped::GetClothesByTypeIndex( unsigned char ucType, unsigned char ucIndex )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		char* szTexture = nullptr;
		char* szModel = nullptr;
		
		if( CLuaFunctionDefinitions::GetClothesByTypeIndex( pResource->GetLua(), ucType, ucIndex, szTexture, szModel ) )
		{
			MonoArray* pArray = mono_array_new( **pResource->GetDomain(), mono_get_string_class(), 2 );

			if( pArray )
			{
				mono_array_set( pArray, MonoString*, 0, pResource->GetDomain()->NewString( szTexture ) );
				mono_array_set( pArray, MonoString*, 1, pResource->GetDomain()->NewString( szModel ) );

				return pArray;
			}
		}
	}
	
	return nullptr;
}

MonoArray* CMonoFunctions::Ped::GetTypeIndexFromClothes( MonoString* msTexture, MonoString* msModel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szTexture	= mono_string_to_utf8( msTexture );
		const char* szModel		= mono_string_to_utf8( msModel );

		unsigned char ucType, ucIndex;
		
		if( CLuaFunctionDefinitions::GetTypeIndexFromClothes( pResource->GetLua(), szTexture, szModel, ucType, ucIndex ) )
		{
			MonoArray* pArray = mono_array_new( **pResource->GetDomain(), mono_get_char_class(), 2 );

			if( pArray )
			{
				mono_array_set( pArray, unsigned char, 0, ucType );
				mono_array_set( pArray, unsigned char, 1, ucIndex );

				return pArray;
			}
		}
	}
	
	return nullptr;
}

MonoString* CMonoFunctions::Ped::GetClothesTypeName( unsigned char ucType )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		char* szName = nullptr;
		
		if( CLuaFunctionDefinitions::GetClothesTypeName( pResource->GetLua(), ucType, szName ) )
		{
			return pResource->GetDomain()->NewString( szName );
		}
	}
	
	return nullptr;
}


// Weapon give/take functions
bool CMonoFunctions::Ped::GiveWeapon( TElement pThis, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::GiveWeapon( pResource->GetLua(), pElement->GetLuaUserdata(), ucWeaponID, usAmmo, bSetAsCurrent );
	}
	
	return false;
}

bool CMonoFunctions::Ped::TakeWeapon( TElement pThis, unsigned char ucWeaponID, unsigned short usAmmo )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::TakeWeapon( pResource->GetLua(), pElement->GetLuaUserdata(), ucWeaponID, usAmmo );
	}
	
	return false;
}

bool CMonoFunctions::Ped::TakeAllWeapons( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::TakeAllWeapons( pResource->GetLua(), pElement->GetLuaUserdata() );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetWeaponAmmo( TElement pThis, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetWeaponAmmo( pResource->GetLua(), pElement->GetLuaUserdata(), ucWeaponID, usAmmo, usAmmoInClip );
	}
	
	return false;
}
