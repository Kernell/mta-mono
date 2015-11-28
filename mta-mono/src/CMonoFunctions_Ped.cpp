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

#ifndef _CMONO_FUNCS_PED
#define _CMONO_FUNCS_PED

#include "CMonoFunctions.h"

// Ped get functions
DWORD CMonoFunctions::Ped::Create( int iModelid, MonoObject* pMonoPosition, float fRot, bool bSynced )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pMonoPosition );
		
		return (DWORD)CLuaFunctionDefinitions::CreatePed( RESOURCE->GetLua(), iModelid, vecPosition, fRot, bSynced );
	}

	return NULL;
}

float CMonoFunctions::Ped::GetArmor( DWORD pUserData )
{
	if( RESOURCE )
	{
		float fArmor;

		if( CLuaFunctionDefinitions::GetPedArmor( RESOURCE->GetLua(), (void*)pUserData, fArmor ) )
		{
			return fArmor;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::Ped::IsChoking( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bChoking;

		if( CLuaFunctionDefinitions::IsPedChoking( RESOURCE->GetLua(), (void*)pUserData, bChoking ) )
		{
			return bChoking;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsDead( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDead;

		if( CLuaFunctionDefinitions::IsPedDead( RESOURCE->GetLua(), (void*)pUserData, bDead ) )
		{
			return bDead;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsDucked( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDucked;

		if( CLuaFunctionDefinitions::IsPedDucked( RESOURCE->GetLua(), (void*)pUserData, bDucked ) )
		{
			return bDucked;
		}
	}

	return false;
}

float CMonoFunctions::Ped::GetStat( DWORD pUserData, unsigned short usStat )
{
	if( RESOURCE )
	{
		float fStat;

		if( CLuaFunctionDefinitions::GetPedStat( RESOURCE->GetLua(), (void*)pUserData, usStat, fStat ) )
		{
			return fStat;
		}
	}

	return 0.0f;
}

DWORD CMonoFunctions::Ped::GetTarget( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetPedTarget( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

int CMonoFunctions::Ped::GetWeapon( DWORD pUserData, int iWeaponSlot )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetPedWeapon( RESOURCE->GetLua(), (void*)pUserData, iWeaponSlot );
	}

	return NULL;
}

MonoString* CMonoFunctions::Ped::GetClothesTexture( DWORD pUserData, unsigned char ucType )
{
	if( RESOURCE )
	{
		string strOutTexture, strOutModel;

		if( CLuaFunctionDefinitions::GetPedClothes( RESOURCE->GetLua(), (void*)pUserData, ucType, strOutTexture, strOutModel ) )
		{
			return RESOURCE->NewString( strOutTexture );
		}
	}

	return NULL;
}

MonoString* CMonoFunctions::Ped::GetClothesModel( DWORD pUserData, unsigned char ucType )
{
	if( RESOURCE )
	{
		string strOutTexture, strOutModel;

		if( CLuaFunctionDefinitions::GetPedClothes( RESOURCE->GetLua(), (void*)pUserData, ucType, strOutTexture, strOutModel ) )
		{
			return RESOURCE->NewString( strOutModel );
		}
	}

	return NULL;
}

bool CMonoFunctions::Ped::DoesHaveJetPack( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bHasJetPack;

		if( CLuaFunctionDefinitions::DoesPedHaveJetPack( RESOURCE->GetLua(), (void*)pUserData, bHasJetPack ) )
		{
			return bHasJetPack;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsOnGround( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bOnGround;

		if( CLuaFunctionDefinitions::IsPedOnGround( RESOURCE->GetLua(), (void*)pUserData, bOnGround ) )
		{
			return bOnGround;
		}
	}

	return false;
}

unsigned char CMonoFunctions::Ped::GetFightingStyle( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucStyle;

		if( CLuaFunctionDefinitions::GetPedFightingStyle( RESOURCE->GetLua(), (void*)pUserData, ucStyle ) )
		{
			return ucStyle;
		}
	}

	return 0;
}

unsigned int CMonoFunctions::Ped::GetMoveAnim( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned int uiMoveAnim;

		if( CLuaFunctionDefinitions::GetPedMoveAnim( RESOURCE->GetLua(), (void*)pUserData, uiMoveAnim ) )
		{
			return uiMoveAnim;
		}
	}

	return 0;
}

float CMonoFunctions::Ped::GetGravity( DWORD pUserData )
{
	if( RESOURCE )
	{
		float fGravity;

		if( CLuaFunctionDefinitions::GetPedGravity( RESOURCE->GetLua(), (void*)pUserData, fGravity ) )
		{
			return fGravity;
		}
	}

	return 0.0f;
}

DWORD CMonoFunctions::Ped::GetContactElement( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetPedContactElement( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

unsigned char CMonoFunctions::Ped::GetWeaponSlot( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucWeaponSlot;

		if( CLuaFunctionDefinitions::GetPedWeaponSlot( RESOURCE->GetLua(), (void*)pUserData, ucWeaponSlot ) )
		{
			return ucWeaponSlot;
		}
	}

	return 0;
}

bool CMonoFunctions::Ped::IsDoingGangDriveby( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDoingGangDriveby;

		if( CLuaFunctionDefinitions::IsPedDoingGangDriveby( RESOURCE->GetLua(), (void*)pUserData, bDoingGangDriveby ) )
		{
			return bDoingGangDriveby;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsOnFire( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bOnFire;

		if( CLuaFunctionDefinitions::IsPedOnFire( RESOURCE->GetLua(), (void*)pUserData, bOnFire ) )
		{
			return bOnFire;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsHeadless( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bHeadless;

		if( CLuaFunctionDefinitions::IsPedHeadless( RESOURCE->GetLua(), (void*)pUserData, bHeadless ) )
		{
			return bHeadless;
		}
	}

	return false;
}

bool CMonoFunctions::Ped::IsFrozen( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bFrozen;

		if( CLuaFunctionDefinitions::IsPedFrozen( RESOURCE->GetLua(), (void*)pUserData, bFrozen ) )
		{
			return bFrozen;
		}
	}

	return false;
}

DWORD CMonoFunctions::Ped::GetOccupiedVehicle( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetPedOccupiedVehicle( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

unsigned int CMonoFunctions::Ped::GetOccupiedVehicleSeat( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned int uiSeat;

		if( CLuaFunctionDefinitions::GetPedOccupiedVehicleSeat( RESOURCE->GetLua(), (void*)pUserData, uiSeat ) )
		{
			return uiSeat;
		}
	}

	return 0;
}

bool CMonoFunctions::Ped::IsInVehicle( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bInVehicle;

		if( CLuaFunctionDefinitions::IsPedInVehicle( RESOURCE->GetLua(), (void*)pUserData, bInVehicle ) )
		{
			return bInVehicle;
		}
	}

	return false;
}

short CMonoFunctions::Ped::GetWeaponProperty( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty )
{
	if( RESOURCE )
	{
		short uData;

		const char* szWeaponSkill	= mono_string_to_utf8( msWeaponSkill );
		const char* szProperty		= mono_string_to_utf8( msProperty );

		if( CLuaFunctionDefinitions::GetWeaponProperty( RESOURCE->GetLua(), ucWeaponID, szWeaponSkill, szProperty, uData ) )
		{
			return uData;
		}
	}

	return 0;
}

short CMonoFunctions::Ped::GetOriginalWeaponProperty( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty )
{
	if( RESOURCE )
	{
		short uData;

		const char* szWeaponSkill	= mono_string_to_utf8( msWeaponSkill );
		const char* szProperty		= mono_string_to_utf8( msProperty );

		if( CLuaFunctionDefinitions::GetOriginalWeaponProperty( RESOURCE->GetLua(), ucWeaponID, szWeaponSkill, szProperty, uData ) )
		{
			return uData;
		}
	}

	return 0;
}


// Ped set functions
bool CMonoFunctions::Ped::SetArmor( DWORD pUserData, float fArmor )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedArmor( RESOURCE->GetLua(), (void*)pUserData, fArmor );
	}
	
	return false;
}

bool CMonoFunctions::Ped::Kill( DWORD pUserData, DWORD pKiller, unsigned char ucKillerWeapon, unsigned char ucBodyPart, bool bStealth )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::KillPed( RESOURCE->GetLua(), (void*)pUserData, (void*)pKiller, ucKillerWeapon, ucBodyPart, bStealth );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetStat( DWORD pUserData, unsigned short usStat, float fValue )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedStat( RESOURCE->GetLua(), (void*)pUserData, usStat, fValue );
	}
	
	return false;
}

bool CMonoFunctions::Ped::AddClothes( DWORD pUserData, MonoString* msTexture, MonoString* msModel, unsigned char ucType )
{
	if( RESOURCE )
	{
		const char* szTexture	= mono_string_to_utf8( msTexture );
		const char* szModel		= mono_string_to_utf8( msModel );
		
		return CLuaFunctionDefinitions::AddPedClothes( RESOURCE->GetLua(), (void*)pUserData, szTexture, szModel, ucType );
	}
	
	return false;
}

bool CMonoFunctions::Ped::RemoveClothes( DWORD pUserData, unsigned char ucType, MonoString* msTexture, MonoString* msModel )
{
	if( RESOURCE )
	{
		const char* szTexture	= mono_string_to_utf8( msTexture );
		const char* szModel		= mono_string_to_utf8( msModel );
		
		return CLuaFunctionDefinitions::RemovePedClothes( RESOURCE->GetLua(), (void*)pUserData, ucType, szTexture, szModel );
	}
	
	return false;
}

bool CMonoFunctions::Ped::GiveJetPack( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GivePedJetPack( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return false;
}

bool CMonoFunctions::Ped::RemoveJetPack( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RemovePedJetPack( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetFightingStyle( DWORD pUserData, unsigned char ucStyle )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedFightingStyle( RESOURCE->GetLua(), (void*)pUserData, ucStyle );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetMoveAnim( DWORD pUserData, unsigned int iMoveAnim )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedMoveAnim( RESOURCE->GetLua(), (void*)pUserData, iMoveAnim );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetGravity( DWORD pUserData, float fGravity )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedGravity( RESOURCE->GetLua(), (void*)pUserData, fGravity );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetChoking( DWORD pUserData, bool bChoking )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedChoking( RESOURCE->GetLua(), (void*)pUserData, bChoking );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetWeaponSlot( DWORD pUserData, unsigned char ucWeaponSlot )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedWeaponSlot( RESOURCE->GetLua(), (void*)pUserData, ucWeaponSlot );
	}
	
	return false;
}

bool CMonoFunctions::Ped::WarpIntoVehicle( DWORD pUserData, DWORD pVehicle, unsigned int uiSeat )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::WarpPedIntoVehicle( RESOURCE->GetLua(), (void*)pUserData, (void*)pVehicle, uiSeat );
	}
	
	return false;
}

bool CMonoFunctions::Ped::RemoveFromVehicle( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RemovePedFromVehicle( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetDoingGangDriveby( DWORD pUserData, bool bGangDriveby )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedDoingGangDriveby( RESOURCE->GetLua(), (void*)pUserData, bGangDriveby );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetAnimation( DWORD pUserData, MonoString* msBlockName, MonoString* msAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame )
{
	if( RESOURCE )
	{
		const char* szBlockName	= mono_string_to_utf8( msBlockName );
		const char* szAnimName	= mono_string_to_utf8( msAnimName );

		return CLuaFunctionDefinitions::SetPedAnimation( RESOURCE->GetLua(), (void*)pUserData, szBlockName, szAnimName, iTime, bLoop, bUpdatePosition, bInterruptable, bFreezeLastFrame );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetAnimationProgress( DWORD pUserData, MonoString* msAnimName, float fProgress )
{
	if( RESOURCE )
	{
		const char* szAnimName	= mono_string_to_utf8( msAnimName );
		
		return CLuaFunctionDefinitions::SetPedAnimationProgress( RESOURCE->GetLua(), (void*)pUserData, szAnimName, fProgress );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetOnFire( DWORD pUserData, bool bIsOnFire )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedOnFire( RESOURCE->GetLua(), (void*)pUserData, bIsOnFire );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetHeadless( DWORD pUserData, bool bIsHeadless )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedHeadless( RESOURCE->GetLua(), (void*)pUserData, bIsHeadless );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetFrozen( DWORD pUserData, bool bIsFrozen )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetPedFrozen( RESOURCE->GetLua(), (void*)pUserData, bIsFrozen );
	}
	
	return false;
}

bool CMonoFunctions::Ped::ReloadWeapon( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ReloadPedWeapon( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetWeaponProperty( unsigned char ucWeaponID, MonoString* msWeaponSkill, MonoString* msProperty, short uData )
{
	if( RESOURCE )
	{
		const char* szWeaponSkill	= mono_string_to_utf8( msWeaponSkill );
		const char* szProperty		= mono_string_to_utf8( msProperty );
		
		return CLuaFunctionDefinitions::SetWeaponProperty( RESOURCE->GetLua(), ucWeaponID, szWeaponSkill, szProperty, uData );
	}
	
	return false;
}


// Ped body?
MonoString* CMonoFunctions::Ped::GetBodyPartName( unsigned char ucID )
{
	if( RESOURCE )
	{
		char* szName = NULL;
		
		if( CLuaFunctionDefinitions::GetBodyPartName( RESOURCE->GetLua(), ucID, szName ) )
		{
			return RESOURCE->NewString( szName );
		}
	}
	
	return NULL;
}

MonoArray* CMonoFunctions::Ped::GetClothesByTypeIndex( unsigned char ucType, unsigned char ucIndex )
{
	if( RESOURCE )
	{
		char* szTexture = NULL;
		char* szModel = NULL;
		
		if( CLuaFunctionDefinitions::GetClothesByTypeIndex( RESOURCE->GetLua(), ucType, ucIndex, szTexture, szModel ) )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->m_pMonoDomain, mono_get_string_class(), 2 );

			if( pArray )
			{
				mono_array_set( pArray, MonoString*, 0, RESOURCE->NewString( szTexture ) );
				mono_array_set( pArray, MonoString*, 1, RESOURCE->NewString( szModel ) );

				return pArray;
			}
		}
	}
	
	return NULL;
}

MonoArray* CMonoFunctions::Ped::GetTypeIndexFromClothes( MonoString* msTexture, MonoString* msModel )
{
	if( RESOURCE )
	{
		const char* szTexture	= mono_string_to_utf8( msTexture );
		const char* szModel		= mono_string_to_utf8( msModel );

		unsigned char ucType, ucIndex;
		
		if( CLuaFunctionDefinitions::GetTypeIndexFromClothes( RESOURCE->GetLua(), szTexture, szModel, ucType, ucIndex ) )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->m_pMonoDomain, mono_get_char_class(), 2 );

			if( pArray )
			{
				mono_array_set( pArray, unsigned char, 0, ucType );
				mono_array_set( pArray, unsigned char, 1, ucIndex );

				return pArray;
			}
		}
	}
	
	return NULL;
}

MonoString* CMonoFunctions::Ped::GetClothesTypeName( unsigned char ucType )
{
	if( RESOURCE )
	{
		char* szName = NULL;
		
		if( CLuaFunctionDefinitions::GetClothesTypeName( RESOURCE->GetLua(), ucType, szName ) )
		{
			return RESOURCE->NewString( szName );
		}
	}
	
	return NULL;
}


// Weapon give/take functions
bool CMonoFunctions::Ped::GiveWeapon( DWORD pPed, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GiveWeapon( RESOURCE->GetLua(), (void*)pPed, ucWeaponID, usAmmo, bSetAsCurrent );
	}
	
	return false;
}

bool CMonoFunctions::Ped::TakeWeapon( DWORD pPed, unsigned char ucWeaponID, unsigned short usAmmo )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::TakeWeapon( RESOURCE->GetLua(), (void*)pPed, ucWeaponID, usAmmo );
	}
	
	return false;
}

bool CMonoFunctions::Ped::TakeAllWeapons( DWORD pPed )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::TakeAllWeapons( RESOURCE->GetLua(), (void*)pPed );
	}
	
	return false;
}

bool CMonoFunctions::Ped::SetWeaponAmmo( DWORD pPed, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetWeaponAmmo( RESOURCE->GetLua(), (void*)pPed, ucWeaponID, usAmmo, usAmmoInClip );
	}
	
	return false;
}

#endif