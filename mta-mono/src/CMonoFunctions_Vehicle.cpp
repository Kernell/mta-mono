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

// Vehicle create/destroy functions
DWORD CMonoFunctions::Vehicle::Create( int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction, int variant1, int variant2 )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( position, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( position, "Y" );
		float fZ = CMonoObject::GetPropertyValue< float >( position, "Z" );

		float fRX = CMonoObject::GetPropertyValue< float >( rotation, "X" );
		float fRY = CMonoObject::GetPropertyValue< float >( rotation, "Y" );
		float fRZ = CMonoObject::GetPropertyValue< float >( rotation, "Z" );

		string sNumberplate = "";

		if( numberplate && mono_string_length( numberplate ) > 0 )
		{
			sNumberplate = string( mono_string_to_utf8( numberplate ) );
		}

		return (DWORD)CLuaFunctionDefinitions::CreateVehicle( RESOURCE->GetLua(), model, fX, fY, fZ, fRX, fRY, fRZ, sNumberplate, direction, variant1, variant2 );
	}

	return NULL;
}

// Vehicle get functions
MonoString* CMonoFunctions::Vehicle::GetType( DWORD pUserData )
{
	if( RESOURCE )
	{
		string strType;
		
		if( CLuaFunctionDefinitions::GetVehicleType( RESOURCE->GetLua(), (void*)pUserData, strType ) )
		{
			return RESOURCE->GetDomain()->NewString( strType );
		}
	}

	return NULL;
}

MonoArray* CMonoFunctions::Vehicle::GetVariant( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucVariant;
		unsigned char ucVariant2;
		
		if( CLuaFunctionDefinitions::GetVehicleVariant( RESOURCE->GetLua(), (void*)pUserData, ucVariant, ucVariant2 ) )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->GetDomain()->GetMonoPtr(), mono_get_char_class(), 2 );

			if( pArray )
			{
				mono_array_set( pArray, unsigned char, 0, ucVariant );
				mono_array_set( pArray, unsigned char, 1, ucVariant2 );

				return pArray;
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Vehicle::GetColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		CVehicleColor pColor;
		
		if( CLuaFunctionDefinitions::GetVehicleColor( RESOURCE->GetLua(), (void*)pUserData, pColor ) )
		{
			SColor pColor1 = pColor.GetRGBColor( 0 );
			SColor pColor2 = pColor.GetRGBColor( 1 );
			SColor pColor3 = pColor.GetRGBColor( 2 );
			SColor pColor4 = pColor.GetRGBColor( 3 );

			void* args[] =
			{
				&pColor1,
				&pColor2,
				&pColor3,
				&pColor4
			};

			return RESOURCE->GetDomain()->GetMTALib()->GetClass( "VehicleColor" )->New( args, 4 );
		}
	}

	return NULL;
}

unsigned short CMonoFunctions::Vehicle::GetModelFromName( MonoString* msName )
{
	if( RESOURCE )
	{
		const char* szName = mono_string_to_utf8( msName );

		unsigned short usModel;
		
		if( CLuaFunctionDefinitions::GetVehicleModelFromName( RESOURCE->GetLua(), szName, usModel ) )
		{
			return usModel;
		}
	}

	return 0;
}

bool CMonoFunctions::Vehicle::GetLandingGearDown( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bGearDown;
		
		if( CLuaFunctionDefinitions::GetVehicleLandingGearDown( RESOURCE->GetLua(), (void*)pUserData, bGearDown ) )
		{
			return bGearDown;
		}
	}

	return false;
}

unsigned char CMonoFunctions::Vehicle::GetMaxPassengers( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucPassengers;
		
		if( CLuaFunctionDefinitions::GetVehicleMaxPassengers( RESOURCE->GetLua(), (void*)pUserData, ucPassengers ) )
		{
			return ucPassengers;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Vehicle::GetName( DWORD pUserData )
{
	if( RESOURCE )
	{
		string strOutName;
		
		if( CLuaFunctionDefinitions::GetVehicleName( RESOURCE->GetLua(), (void*)pUserData, strOutName ) )
		{
			return RESOURCE->GetDomain()->NewString( strOutName );
		}
	}

	return NULL;
}

MonoString* CMonoFunctions::Vehicle::GetNameFromModel( unsigned short usModel )
{
	if( RESOURCE )
	{
		string strOutName;
		
		if( CLuaFunctionDefinitions::GetVehicleNameFromModel( RESOURCE->GetLua(), usModel, strOutName ) )
		{
			return RESOURCE->GetDomain()->NewString( strOutName );
		}
	}

	return NULL;
}

DWORD CMonoFunctions::Vehicle::GetOccupant( DWORD pUserData, unsigned int uiSeat )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetVehicleOccupant( RESOURCE->GetLua(), (void*)pUserData, uiSeat );
	}

	return NULL;
}

MonoArray* CMonoFunctions::Vehicle::GetOccupants( DWORD pUserData )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaArguments = CLuaFunctionDefinitions::GetVehicleOccupants( RESOURCE->GetLua(), (void*)pUserData );

		return RESOURCE->GetDomain()->NewArray<DWORD, LUA_TLIGHTUSERDATA>( mono_get_uint32_class(), pLuaArguments );
	}

	return NULL;
}

DWORD CMonoFunctions::Vehicle::GetController( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetVehicleController( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

bool CMonoFunctions::Vehicle::GetSirensOn( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bSirensOn;

		if( CLuaFunctionDefinitions::GetVehicleSirensOn( RESOURCE->GetLua(), (void*)pUserData, bSirensOn ) )
		{
			return bSirensOn;
		}
	}

	return false;
}

MonoObject* CMonoFunctions::Vehicle::GetTurnVelocity( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecVelocity;

		if( CLuaFunctionDefinitions::GetVehicleTurnVelocity( RESOURCE->GetLua(), (void*)pUserData, vecVelocity ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Vector3->New( vecVelocity );
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Vehicle::GetTurretPosition( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector2 vecPosition;

		if( CLuaFunctionDefinitions::GetVehicleTurretPosition( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return NULL;
}

bool CMonoFunctions::Vehicle::IsLocked( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bLocked;

		if( CLuaFunctionDefinitions::IsVehicleLocked( RESOURCE->GetLua(), (void*)pUserData, bLocked ) )
		{
			return bLocked;
		}
	}

	return false;
}

MonoArray* CMonoFunctions::Vehicle::GetOfType( unsigned int uiModel )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaArguments = CLuaFunctionDefinitions::GetVehiclesOfType( RESOURCE->GetLua(), uiModel );

		return RESOURCE->GetDomain()->NewArray<DWORD, LUA_TLIGHTUSERDATA>( mono_get_uint32_class(), pLuaArguments );
	}

	return NULL;
}

unsigned short CMonoFunctions::Vehicle::GetUpgradeOnSlot( DWORD pUserData, unsigned char ucSlot )
{
	if( RESOURCE )
	{
		unsigned short ucUpgrade;

		if( CLuaFunctionDefinitions::GetVehicleUpgradeOnSlot( RESOURCE->GetLua(), (void*)pUserData, ucSlot, ucUpgrade ) )
		{
			return ucUpgrade;
		}
	}

	return 0;
}

MonoArray* CMonoFunctions::Vehicle::GetUpgrades( DWORD pUserData )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaArguments = CLuaFunctionDefinitions::GetVehicleUpgrades( RESOURCE->GetLua(), (void*)pUserData );

		return RESOURCE->GetDomain()->NewArray<DWORD, LUA_TNUMBER>( mono_get_uint32_class(), pLuaArguments );
	}

	return NULL;
}

MonoString* CMonoFunctions::Vehicle::GetUpgradeSlotName( unsigned short usUpgrade )
{
	if( RESOURCE )
	{
		string strOutName;
		
		if( CLuaFunctionDefinitions::GetVehicleUpgradeSlotName( RESOURCE->GetLua(), usUpgrade, strOutName ) )
		{
			return RESOURCE->GetDomain()->NewString( strOutName );
		}
	}

	return NULL;
}

MonoArray* CMonoFunctions::Vehicle::GetCompatibleUpgrades( DWORD pUserData )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaArguments = CLuaFunctionDefinitions::GetVehicleCompatibleUpgrades( RESOURCE->GetLua(), (void*)pUserData );

		return RESOURCE->GetDomain()->NewArray<DWORD, LUA_TNUMBER>( mono_get_uint32_class(), pLuaArguments );
	}

	return NULL;
}

unsigned char CMonoFunctions::Vehicle::GetDoorState( DWORD pUserData, unsigned char ucDoor )
{
	if( RESOURCE )
	{
		unsigned char ucState;

		if( CLuaFunctionDefinitions::GetVehicleDoorState( RESOURCE->GetLua(), (void*)pUserData, ucDoor, ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

MonoObject* CMonoFunctions::Vehicle::GetWheelStates( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucFrontLeft, ucRearLeft, ucFrontRight, ucRearRight;

		if( CLuaFunctionDefinitions::GetVehicleWheelStates( RESOURCE->GetLua(), (void*)pUserData, ucFrontLeft, ucRearLeft, ucFrontRight, ucRearRight ) )
		{
			void *args[] =
			{
				&ucFrontLeft, &ucRearLeft, &ucFrontRight, &ucRearRight
			};

			return RESOURCE->GetDomain()->GetMTALib()->GetClass( "Vehicle", "VehicleWheelsState" )->New( args, 4 );
		}
	}

	return NULL;
}

unsigned char CMonoFunctions::Vehicle::GetLightState( DWORD pUserData, unsigned char ucLight )
{
	if( RESOURCE )
	{
		unsigned char ucState;

		if( CLuaFunctionDefinitions::GetVehicleLightState( RESOURCE->GetLua(), (void*)pUserData, ucLight, ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Vehicle::GetPanelState( DWORD pUserData, unsigned char ucPanel )
{
	if( RESOURCE )
	{
		unsigned char ucState;

		if( CLuaFunctionDefinitions::GetVehiclePanelState( RESOURCE->GetLua(), (void*)pUserData, ucPanel, ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Vehicle::GetOverrideLights( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucLights;

		if( CLuaFunctionDefinitions::GetVehicleOverrideLights( RESOURCE->GetLua(), (void*)pUserData, ucLights ) )
		{
			return ucLights;
		}
	}

	return 0;
}

DWORD CMonoFunctions::Vehicle::GetTowedByVehicle( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetVehicleTowedByVehicle( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

DWORD CMonoFunctions::Vehicle::GetTowingVehicle( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetVehicleTowingVehicle( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

unsigned char CMonoFunctions::Vehicle::GetPaintjob( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucPaintjob;

		if( CLuaFunctionDefinitions::GetVehiclePaintjob( RESOURCE->GetLua(), (void*)pUserData, ucPaintjob ) )
		{
			return ucPaintjob;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Vehicle::GetPlateText( DWORD pUserData )
{
	if( RESOURCE )
	{
		char* szPlateText = NULL;
		
		if( CLuaFunctionDefinitions::GetVehiclePlateText( RESOURCE->GetLua(), (void*)pUserData, szPlateText ) )
		{
			return RESOURCE->GetDomain()->NewString( szPlateText );
		}
	}

	return NULL;
}

bool CMonoFunctions::Vehicle::IsDamageProof( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDamageProof;
		
		if( CLuaFunctionDefinitions::IsVehicleDamageProof( RESOURCE->GetLua(), (void*)pUserData, bDamageProof ) )
		{
			return bDamageProof;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsFuelTankExplodable( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bExplodable;
		
		if( CLuaFunctionDefinitions::IsVehicleFuelTankExplodable( RESOURCE->GetLua(), (void*)pUserData, bExplodable ) )
		{
			return bExplodable;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsFrozen( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bFrozen;
		
		if( CLuaFunctionDefinitions::IsVehicleFrozen( RESOURCE->GetLua(), (void*)pUserData, bFrozen ) )
		{
			return bFrozen;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsOnGround( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bOnGround;
		
		if( CLuaFunctionDefinitions::IsVehicleOnGround( RESOURCE->GetLua(), (void*)pUserData, bOnGround ) )
		{
			return bOnGround;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::GetEngineState( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bState;
		
		if( CLuaFunctionDefinitions::GetVehicleEngineState( RESOURCE->GetLua(), (void*)pUserData, bState ) )
		{
			return bState;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsTrainDerailed( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDerailed;
		
		if( CLuaFunctionDefinitions::IsTrainDerailed( RESOURCE->GetLua(), (void*)pUserData, bDerailed ) )
		{
			return bDerailed;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsTrainDerailable( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDerailed;
		
		if( CLuaFunctionDefinitions::IsTrainDerailable( RESOURCE->GetLua(), (void*)pUserData, bDerailed ) )
		{
			return bDerailed;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::GetTrainDirection( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDirection;
		
		if( CLuaFunctionDefinitions::GetTrainDirection( RESOURCE->GetLua(), (void*)pUserData, bDirection ) )
		{
			return bDirection;
		}
	}

	return false;
}

float CMonoFunctions::Vehicle::GetTrainSpeed( DWORD pUserData )
{
	if( RESOURCE )
	{
		float fSpeed;
		
		if( CLuaFunctionDefinitions::GetTrainSpeed( RESOURCE->GetLua(), (void*)pUserData, fSpeed ) )
		{
			return fSpeed;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::Vehicle::IsBlown( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::IsVehicleBlown( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

MonoObject* CMonoFunctions::Vehicle::GetHeadLightColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		SColor outColor;

		if( CLuaFunctionDefinitions::GetVehicleHeadLightColor( RESOURCE->GetLua(), (void*)pUserData, outColor ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return NULL;
}

float CMonoFunctions::Vehicle::GetDoorOpenRatio( DWORD pUserData, unsigned char ucDoor )
{
	if( RESOURCE )
	{
		float fRatio;
		
		if( CLuaFunctionDefinitions::GetVehicleDoorOpenRatio( RESOURCE->GetLua(), (void*)pUserData, ucDoor, fRatio ) )
		{
			return fRatio;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::Vehicle::IsTaxiLightOn( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bLightOn;
		
		if( CLuaFunctionDefinitions::IsVehicleTaxiLightOn( RESOURCE->GetLua(), (void*)pUserData, bLightOn ) )
		{
			return bLightOn;
		}
	}

	return false;
}


// Vehicle set functions
bool CMonoFunctions::Vehicle::Fix( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::FixVehicle( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::Vehicle::Blow( DWORD pUserData, bool bExplode )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::BlowVehicle( RESOURCE->GetLua(), (void*)pUserData, bExplode );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTurnVelocity( DWORD pUserData, MonoObject* pVelocity )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( pVelocity, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pVelocity, "Y" );
		float fZ = CMonoObject::GetPropertyValue< float >( pVelocity, "Z" );

		return CLuaFunctionDefinitions::SetVehicleTurnVelocity( RESOURCE->GetLua(), (void*)pUserData, fX, fY, fZ );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetColor( DWORD pUserData, MonoObject* pColor1, MonoObject* pColor2, MonoObject* pColor3, MonoObject* pColor4 )
{
	if( RESOURCE )
	{
		unsigned char ucR1 = CMonoObject::GetPropertyValue< unsigned char >( pColor1, "R" );
		unsigned char ucG1 = CMonoObject::GetPropertyValue< unsigned char >( pColor1, "G" );
		unsigned char ucB1 = CMonoObject::GetPropertyValue< unsigned char >( pColor1, "B" );

		unsigned char ucR2 = CMonoObject::GetPropertyValue< unsigned char >( pColor2, "R" );
		unsigned char ucG2 = CMonoObject::GetPropertyValue< unsigned char >( pColor2, "G" );
		unsigned char ucB2 = CMonoObject::GetPropertyValue< unsigned char >( pColor2, "B" );

		unsigned char ucR3 = CMonoObject::GetPropertyValue< unsigned char >( pColor3, "R" );
		unsigned char ucG3 = CMonoObject::GetPropertyValue< unsigned char >( pColor3, "G" );
		unsigned char ucB3 = CMonoObject::GetPropertyValue< unsigned char >( pColor3, "B" );

		unsigned char ucR4 = CMonoObject::GetPropertyValue< unsigned char >( pColor4, "R" );
		unsigned char ucG4 = CMonoObject::GetPropertyValue< unsigned char >( pColor4, "G" );
		unsigned char ucB4 = CMonoObject::GetPropertyValue< unsigned char >( pColor4, "B" );

		return CLuaFunctionDefinitions::SetVehicleColor( RESOURCE->GetLua(), (void*)pUserData, ucR1, ucG1, ucB1, ucR2, ucG2, ucB2, ucR3, ucG3, ucB3, ucR4, ucG4, ucB4 );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetLandingGearDown( DWORD pUserData, bool bLandingGearDown )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleLandingGearDown( RESOURCE->GetLua(), (void*)pUserData, bLandingGearDown );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetLocked( DWORD pUserData, bool bLocked )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleLocked( RESOURCE->GetLua(), (void*)pUserData, bLocked );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDoorsUndamageable( DWORD pUserData, bool bDoorsUndamageable )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleDoorsUndamageable( RESOURCE->GetLua(), (void*)pUserData, bDoorsUndamageable );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetSirensOn( DWORD pUserData, bool bSirensOn )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleSirensOn( RESOURCE->GetLua(), (void*)pUserData, bSirensOn );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTaxiLightOn( DWORD pUserData, bool bTaxiLightState )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleTaxiLightOn( RESOURCE->GetLua(), (void*)pUserData, bTaxiLightState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::AddUpgrade( DWORD pUserData, unsigned short usUpgrade )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::AddVehicleUpgrade( RESOURCE->GetLua(), (void*)pUserData, usUpgrade );
	}

	return false;
}

bool CMonoFunctions::Vehicle::RemoveUpgrade( DWORD pUserData, unsigned short usUpgrade )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RemoveVehicleUpgrade( RESOURCE->GetLua(), (void*)pUserData, usUpgrade );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDoorState( DWORD pUserData, unsigned char ucDoor, unsigned char ucState )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleDoorState( RESOURCE->GetLua(), (void*)pUserData, ucDoor, ucState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetWheelStates( DWORD pUserData, int iFrontLeft, int iRearLeft, int iFrontRight, int iRearRight )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleWheelStates( RESOURCE->GetLua(), (void*)pUserData, iFrontLeft, iRearLeft, iFrontRight, iRearRight );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetLightState( DWORD pUserData, unsigned char ucLight, unsigned char ucState )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleLightState( RESOURCE->GetLua(), (void*)pUserData, ucLight, ucState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetPanelState( DWORD pUserData, unsigned char ucPanel, unsigned char ucState )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehiclePanelState( RESOURCE->GetLua(), (void*)pUserData, ucPanel, ucState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetIdleRespawnDelay( DWORD pUserData, unsigned long ulTime )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleIdleRespawnDelay( RESOURCE->GetLua(), (void*)pUserData, ulTime );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetRespawnDelay( DWORD pUserData, unsigned long ulTime )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleRespawnDelay( RESOURCE->GetLua(), (void*)pUserData, ulTime );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetRespawnPosition( DWORD pUserData, MonoObject* pPosition, MonoObject* pRotation )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pPosition, "Y" );
		float fZ = CMonoObject::GetPropertyValue< float >( pPosition, "Z" );

		float fRX = CMonoObject::GetPropertyValue< float >( pRotation, "X" );
		float fRY = CMonoObject::GetPropertyValue< float >( pRotation, "Y" );
		float fRZ = CMonoObject::GetPropertyValue< float >( pRotation, "Z" );

		return CLuaFunctionDefinitions::SetVehicleRespawnPosition( RESOURCE->GetLua(), (void*)pUserData, fX, fY, fZ, fRX, fRY, fRZ );
	}

	return false;
}

bool CMonoFunctions::Vehicle::ToggleRespawn( DWORD pUserData, bool bRespawn )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ToggleVehicleRespawn( RESOURCE->GetLua(), (void*)pUserData, bRespawn );
	}

	return false;
}

bool CMonoFunctions::Vehicle::ResetExplosionTime( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetVehicleExplosionTime( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::Vehicle::ResetIdleTime( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetVehicleIdleTime( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::Vehicle::Spawn( DWORD pUserData, MonoObject* pPosition, MonoObject* pRotation )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pPosition, "Y" );
		float fZ = CMonoObject::GetPropertyValue< float >( pPosition, "Z" );

		float fRX = CMonoObject::GetPropertyValue< float >( pRotation, "X" );
		float fRY = CMonoObject::GetPropertyValue< float >( pRotation, "Y" );
		float fRZ = CMonoObject::GetPropertyValue< float >( pRotation, "Z" );

		return CLuaFunctionDefinitions::SpawnVehicle( RESOURCE->GetLua(), (void*)pUserData, fX, fY, fZ, fRX, fRY, fRZ );
	}

	return false;
}

bool CMonoFunctions::Vehicle::Respawn( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RespawnVehicle( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetOverrideLights( DWORD pUserData, unsigned char ucLights )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleOverrideLights( RESOURCE->GetLua(), (void*)pUserData, ucLights );
	}

	return false;
}

bool CMonoFunctions::Vehicle::AttachTrailer( DWORD pUserData, DWORD pTrailer )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::AttachTrailerToVehicle( RESOURCE->GetLua(), (void*)pUserData, (void*)pTrailer );
	}

	return false;
}

bool CMonoFunctions::Vehicle::DetachTrailer( DWORD pUserData, DWORD pTrailer )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::DetachTrailerFromVehicle( RESOURCE->GetLua(), (void*)pUserData, (void*)pTrailer );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetEngineState( DWORD pUserData, bool bState )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleEngineState( RESOURCE->GetLua(), (void*)pUserData, bState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDirtLevel( DWORD pUserData, float fDirtLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleDirtLevel( RESOURCE->GetLua(), (void*)pUserData, fDirtLevel );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDamageProof( DWORD pUserData, bool bDamageProof )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleDamageProof( RESOURCE->GetLua(), (void*)pUserData, bDamageProof );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetPaintjob( DWORD pUserData, unsigned char ucPaintjob )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehiclePaintjob( RESOURCE->GetLua(), (void*)pUserData, ucPaintjob );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetFuelTankExplodable( DWORD pUserData, bool bExplodable )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleFuelTankExplodable( RESOURCE->GetLua(), (void*)pUserData, bExplodable );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainDerailed( DWORD pUserData, bool bDerailed )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTrainDerailed( RESOURCE->GetLua(), (void*)pUserData, bDerailed );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainDerailable( DWORD pUserData, bool bDerailable )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTrainDerailable( RESOURCE->GetLua(), (void*)pUserData, bDerailable );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainDirection( DWORD pUserData, bool bDireciton )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTrainDirection( RESOURCE->GetLua(), (void*)pUserData, bDireciton );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainSpeed( DWORD pUserData, float fSpeed )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTrainSpeed( RESOURCE->GetLua(), (void*)pUserData, fSpeed );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetHeadLightColor( DWORD pUserData, MonoObject* pColor )
{
	if( RESOURCE )
	{
		unsigned char ucR1 = CMonoObject::GetPropertyValue< unsigned char >( pColor, "R" );
		unsigned char ucG1 = CMonoObject::GetPropertyValue< unsigned char >( pColor, "G" );
		unsigned char ucB1 = CMonoObject::GetPropertyValue< unsigned char >( pColor, "B" );

		return CLuaFunctionDefinitions::SetVehicleHeadLightColor( RESOURCE->GetLua(), (void*)pUserData, ucR1, ucG1, ucB1 );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTurretPosition( DWORD pUserData, MonoObject* pPosition )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pPosition, "Y" );

		return CLuaFunctionDefinitions::SetVehicleTurretPosition( RESOURCE->GetLua(), (void*)pUserData, fX, fY );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDoorOpenRatio( DWORD pUserData, unsigned char ucDoor, float fRatio, unsigned long ulTime )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleDoorOpenRatio( RESOURCE->GetLua(), (void*)pUserData, ucDoor, fRatio, ulTime );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetVariant( DWORD pUserData, unsigned char ucVariant, unsigned char ucVariant2 )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetVehicleVariant( RESOURCE->GetLua(), (void*)pUserData, ucVariant, ucVariant2 );
	}

	return false;
}

bool CMonoFunctions::Vehicle::GiveSirens( DWORD pUserData, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360, bool bCheckLosFlag, bool bUseRandomiserFlag, bool bSilentFlag )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GiveVehicleSirens( RESOURCE->GetLua(), (void*)pUserData, ucSirenType, ucSirenCount, bFlag360, bCheckLosFlag, bUseRandomiserFlag, bSilentFlag );
	}

	return false;
}

bool CMonoFunctions::Vehicle::RemoveSirens( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RemoveVehicleSirens( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetSirens( DWORD pUserData, unsigned char ucSirenID, MonoObject* pPosition, MonoObject* pColor, float fMinAlpha )
{
	if( RESOURCE )
	{
		float fX		= CMonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY		= CMonoObject::GetPropertyValue< float >( pPosition, "Y" );
		float fZ		= CMonoObject::GetPropertyValue< float >( pPosition, "Z" );

		float fRed		= CMonoObject::GetPropertyValue< float >( pColor, "R" );
		float fGreen	= CMonoObject::GetPropertyValue< float >( pColor, "G" );
		float fBlue		= CMonoObject::GetPropertyValue< float >( pColor, "B" );
		float fAlpha	= CMonoObject::GetPropertyValue< float >( pColor, "A" );

		return CLuaFunctionDefinitions::SetVehicleSirens( RESOURCE->GetLua(), (void*)pUserData, ucSirenID, fX, fY, fZ, fRed, fGreen, fBlue, fAlpha, fMinAlpha );
	}

	return false;
}

MonoArray* CMonoFunctions::Vehicle::GetSirens( DWORD pUserData )
{
	return NULL;
}

MonoObject* CMonoFunctions::Vehicle::GetSirenParams( DWORD pUserData )
{
	return NULL;
}

bool CMonoFunctions::Vehicle::SetPlateText( DWORD pUserData, MonoString* msName )
{
	if( RESOURCE )
	{
		const char* szText = mono_string_to_utf8( msName );

		return CLuaFunctionDefinitions::SetVehiclePlateText( RESOURCE->GetLua(), (void*)pUserData, szText );
	}

	return false;
}
