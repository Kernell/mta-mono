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
void CMonoFunctions::Vehicle::Ctor( TElement pThis, int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction, int variant1, int variant2 )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float
			fX = 0.0f,
			fY = 0.0f,
			fZ = 0.0f,
			fRX = 0.0f,
			fRY = 0.0f,
			fRZ = 0.0f;

		if( position )
		{
			fX = SharedUtil::MonoObject::GetPropertyValue< float >( position, "X" );
			fY = SharedUtil::MonoObject::GetPropertyValue< float >( position, "Y" );
			fZ = SharedUtil::MonoObject::GetPropertyValue< float >( position, "Z" );
		}

		if( rotation )
		{
			fRX = SharedUtil::MonoObject::GetPropertyValue< float >( rotation, "X" );
			fRY = SharedUtil::MonoObject::GetPropertyValue< float >( rotation, "Y" );
			fRZ = SharedUtil::MonoObject::GetPropertyValue< float >( rotation, "Z" );
		}

		string sNumberplate = "";

		if( numberplate && mono_string_length( numberplate ) > 0 )
		{
			sNumberplate = mono_string_to_utf8( numberplate );
		}

		PVOID pUserData = CLuaFunctionDefinitions::CreateVehicle( pResource->GetLua(), model, fX, fY, fZ, fRX, fRY, fRZ, sNumberplate, direction, variant1, variant2 );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

// Vehicle get functions
MonoString* CMonoFunctions::Vehicle::GetVehicleType( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strType;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleType( pResource->GetLua(), pElement->GetLuaUserdata(), strType ) )
		{
			return pResource->GetDomain()->NewString( strType );
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Vehicle::GetVariant( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucVariant;
		unsigned char ucVariant2;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleVariant( pResource->GetLua(), pElement->GetLuaUserdata(), ucVariant, ucVariant2 ) )
		{
			MonoArray* pArray = mono_array_new( **pResource->GetDomain(), mono_get_char_class(), 2 );

			if( pArray )
			{
				mono_array_set( pArray, unsigned char, 0, ucVariant );
				mono_array_set( pArray, unsigned char, 1, ucVariant2 );

				return pArray;
			}
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Vehicle::GetColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CVehicleColor pVehicleColor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleColor( pResource->GetLua(), pElement->GetLuaUserdata(), pVehicleColor ) )
		{
			CMonoMTALib* pMTALib = pResource->GetDomain()->GetMTALib();

			PVOID args[ 4 ];

			for( int i = 0; i < 4; i++ )
			{
				MonoObject* pObject = pMTALib->Color->New( pVehicleColor.GetRGBColor( i ) );

				args[ i ] = pObject;
			}

			return pMTALib->GetClass( "VehicleColor" )->New( args, 4 );
		}
	}

	return nullptr;
}

unsigned short CMonoFunctions::Vehicle::GetModelFromName( MonoString* msName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szName = mono_string_to_utf8( msName );

		unsigned short usModel;
		
		if( CLuaFunctionDefinitions::GetVehicleModelFromName( pResource->GetLua(), szName, usModel ) )
		{
			return usModel;
		}
	}

	return 0;
}

bool CMonoFunctions::Vehicle::GetLandingGearDown( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bGearDown;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleLandingGearDown( pResource->GetLua(), pElement->GetLuaUserdata(), bGearDown ) )
		{
			return bGearDown;
		}
	}

	return false;
}

unsigned char CMonoFunctions::Vehicle::GetMaxPassengers( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucPassengers;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleMaxPassengers( pResource->GetLua(), pElement->GetLuaUserdata(), ucPassengers ) )
		{
			return ucPassengers;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Vehicle::GetName( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleName( pResource->GetLua(), pElement->GetLuaUserdata(), strOutName ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Vehicle::GetNameFromModel( unsigned short usModel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;
		
		if( CLuaFunctionDefinitions::GetVehicleNameFromModel( pResource->GetLua(), usModel, strOutName ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Vehicle::GetOccupant( TElement pThis, unsigned int uiSeat )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetVehicleOccupant( pResource->GetLua(), pElement->GetLuaUserdata(), uiSeat );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Vehicle::GetOccupants( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetVehicleOccupants( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pLuaArguments.size() > 0 )
		{
			return pResource->GetDomain()->NewArray( **pResource->GetDomain()->GetMTALib()->GetClass( "Ped" ), pLuaArguments );
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Vehicle::GetController( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetVehicleController( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Vehicle::GetSirensOn( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bSirensOn;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleSirensOn( pResource->GetLua(), pElement->GetLuaUserdata(), bSirensOn ) )
		{
			return bSirensOn;
		}
	}

	return false;
}

MonoObject* CMonoFunctions::Vehicle::GetTurnVelocity( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecVelocity;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleTurnVelocity( pResource->GetLua(), pElement->GetLuaUserdata(), vecVelocity ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecVelocity );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Vehicle::GetTurretPosition( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector2 vecPosition;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleTurretPosition( pResource->GetLua(), pElement->GetLuaUserdata(), vecPosition ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Vehicle::IsLocked( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bLocked;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsVehicleLocked( pResource->GetLua(), pElement->GetLuaUserdata(), bLocked ) )
		{
			return bLocked;
		}
	}

	return false;
}

MonoArray* CMonoFunctions::Vehicle::GetOfType( unsigned int uiModel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetVehiclesOfType( pResource->GetLua(), uiModel );

		if( pLuaArguments.size() > 0 )
		{
			return pResource->GetDomain()->NewArray( **pResource->GetDomain()->GetMTALib()->GetClass( "Vehicle" ), pLuaArguments );
		}
	}

	return nullptr;
}

unsigned short CMonoFunctions::Vehicle::GetUpgradeOnSlot( TElement pThis, unsigned char ucSlot )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned short ucUpgrade;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleUpgradeOnSlot( pResource->GetLua(), pElement->GetLuaUserdata(), ucSlot, ucUpgrade ) )
		{
			return ucUpgrade;
		}
	}

	return 0;
}

MonoArray* CMonoFunctions::Vehicle::GetUpgrades( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetVehicleUpgrades( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pLuaArguments.size() > 0 )
		{
			return pResource->GetDomain()->NewArray<uint32_t, LUA_TNUMBER>( mono_get_uint32_class(), pLuaArguments );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Vehicle::GetUpgradeSlotName( unsigned short usUpgrade )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;
		
		if( CLuaFunctionDefinitions::GetVehicleUpgradeSlotName( pResource->GetLua(), usUpgrade, strOutName ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Vehicle::GetCompatibleUpgrades( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetVehicleCompatibleUpgrades( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pLuaArguments.size() > 0 )
		{
			return pResource->GetDomain()->NewArray<uint32_t, LUA_TNUMBER>( mono_get_uint32_class(), pLuaArguments );
		}
	}

	return nullptr;
}

unsigned char CMonoFunctions::Vehicle::GetDoorState( TElement pThis, unsigned char ucDoor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucState;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleDoorState( pResource->GetLua(), pElement->GetLuaUserdata(), ucDoor, ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

MonoObject* CMonoFunctions::Vehicle::GetWheelStates( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucFrontLeft, ucRearLeft, ucFrontRight, ucRearRight;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleWheelStates( pResource->GetLua(), pElement->GetLuaUserdata(), ucFrontLeft, ucRearLeft, ucFrontRight, ucRearRight ) )
		{
			void *args[] =
			{
				&ucFrontLeft, &ucRearLeft, &ucFrontRight, &ucRearRight
			};

			return pResource->GetDomain()->GetMTALib()->GetClass( "Vehicle", "VehicleWheelsState" )->New( args, 4 );
		}
	}

	return nullptr;
}

unsigned char CMonoFunctions::Vehicle::GetLightState( TElement pThis, unsigned char ucLight )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucState;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleLightState( pResource->GetLua(), pElement->GetLuaUserdata(), ucLight, ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Vehicle::GetPanelState( TElement pThis, unsigned char ucPanel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucState;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehiclePanelState( pResource->GetLua(), pElement->GetLuaUserdata(), ucPanel, ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Vehicle::GetOverrideLights( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucLights;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleOverrideLights( pResource->GetLua(), pElement->GetLuaUserdata(), ucLights ) )
		{
			return ucLights;
		}
	}

	return 0;
}

TElement CMonoFunctions::Vehicle::GetTowedByVehicle( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetVehicleTowedByVehicle( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Vehicle::GetTowingVehicle( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetVehicleTowingVehicle( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

unsigned char CMonoFunctions::Vehicle::GetPaintjob( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucPaintjob;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehiclePaintjob( pResource->GetLua(), pElement->GetLuaUserdata(), ucPaintjob ) )
		{
			return ucPaintjob;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Vehicle::GetPlateText( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		char* szPlateText = nullptr;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehiclePlateText( pResource->GetLua(), pElement->GetLuaUserdata(), szPlateText ) )
		{
			return pResource->GetDomain()->NewString( szPlateText );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Vehicle::IsDamageProof( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDamageProof;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsVehicleDamageProof( pResource->GetLua(), pElement->GetLuaUserdata(), bDamageProof ) )
		{
			return bDamageProof;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsFuelTankExplodable( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bExplodable;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsVehicleFuelTankExplodable( pResource->GetLua(), pElement->GetLuaUserdata(), bExplodable ) )
		{
			return bExplodable;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsFrozen( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bFrozen;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsVehicleFrozen( pResource->GetLua(), pElement->GetLuaUserdata(), bFrozen ) )
		{
			return bFrozen;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsOnGround( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bOnGround;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsVehicleOnGround( pResource->GetLua(), pElement->GetLuaUserdata(), bOnGround ) )
		{
			return bOnGround;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::GetEngineState( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bState;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleEngineState( pResource->GetLua(), pElement->GetLuaUserdata(), bState ) )
		{
			return bState;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsTrainDerailed( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDerailed;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsTrainDerailed( pResource->GetLua(), pElement->GetLuaUserdata(), bDerailed ) )
		{
			return bDerailed;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::IsTrainDerailable( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDerailed;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsTrainDerailable( pResource->GetLua(), pElement->GetLuaUserdata(), bDerailed ) )
		{
			return bDerailed;
		}
	}

	return false;
}

bool CMonoFunctions::Vehicle::GetTrainDirection( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDirection;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetTrainDirection( pResource->GetLua(), pElement->GetLuaUserdata(), bDirection ) )
		{
			return bDirection;
		}
	}

	return false;
}

float CMonoFunctions::Vehicle::GetTrainSpeed( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fSpeed;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetTrainSpeed( pResource->GetLua(), pElement->GetLuaUserdata(), fSpeed ) )
		{
			return fSpeed;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::Vehicle::IsBlown( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::IsVehicleBlown( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

MonoObject* CMonoFunctions::Vehicle::GetHeadLightColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor outColor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleHeadLightColor( pResource->GetLua(), pElement->GetLuaUserdata(), outColor ) )
		{
			return pResource->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return nullptr;
}

float CMonoFunctions::Vehicle::GetDoorOpenRatio( TElement pThis, unsigned char ucDoor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fRatio;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetVehicleDoorOpenRatio( pResource->GetLua(), pElement->GetLuaUserdata(), ucDoor, fRatio ) )
		{
			return fRatio;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::Vehicle::IsTaxiLightOn( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bLightOn;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsVehicleTaxiLightOn( pResource->GetLua(), pElement->GetLuaUserdata(), bLightOn ) )
		{
			return bLightOn;
		}
	}

	return false;
}


// Vehicle set functions
bool CMonoFunctions::Vehicle::Fix( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::FixVehicle( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::Blow( TElement pThis, bool bExplode )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::BlowVehicle( pResource->GetLua(), pElement->GetLuaUserdata(), bExplode );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTurnVelocity( TElement pThis, MonoObject* pVelocity )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fX = SharedUtil::MonoObject::GetPropertyValue< float >( pVelocity, "X" );
		float fY = SharedUtil::MonoObject::GetPropertyValue< float >( pVelocity, "Y" );
		float fZ = SharedUtil::MonoObject::GetPropertyValue< float >( pVelocity, "Z" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleTurnVelocity( pResource->GetLua(), pElement->GetLuaUserdata(), fX, fY, fZ );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetColor( TElement pThis, MonoObject* pColor1, MonoObject* pColor2, MonoObject* pColor3, MonoObject* pColor4 )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucR1 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor1, "R" );
		unsigned char ucG1 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor1, "G" );
		unsigned char ucB1 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor1, "B" );

		unsigned char ucR2 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor2, "R" );
		unsigned char ucG2 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor2, "G" );
		unsigned char ucB2 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor2, "B" );

		unsigned char ucR3 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor3, "R" );
		unsigned char ucG3 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor3, "G" );
		unsigned char ucB3 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor3, "B" );

		unsigned char ucR4 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor4, "R" );
		unsigned char ucG4 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor4, "G" );
		unsigned char ucB4 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor4, "B" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleColor( pResource->GetLua(), pElement->GetLuaUserdata(), ucR1, ucG1, ucB1, ucR2, ucG2, ucB2, ucR3, ucG3, ucB3, ucR4, ucG4, ucB4 );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetLandingGearDown( TElement pThis, bool bLandingGearDown )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleLandingGearDown( pResource->GetLua(), pElement->GetLuaUserdata(), bLandingGearDown );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetLocked( TElement pThis, bool bLocked )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleLocked( pResource->GetLua(), pElement->GetLuaUserdata(), bLocked );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDoorsUndamageable( TElement pThis, bool bDoorsUndamageable )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleDoorsUndamageable( pResource->GetLua(), pElement->GetLuaUserdata(), bDoorsUndamageable );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetSirensOn( TElement pThis, bool bSirensOn )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleSirensOn( pResource->GetLua(), pElement->GetLuaUserdata(), bSirensOn );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTaxiLightOn( TElement pThis, bool bTaxiLightState )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleTaxiLightOn( pResource->GetLua(), pElement->GetLuaUserdata(), bTaxiLightState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::AddUpgrade( TElement pThis, unsigned short usUpgrade )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::AddVehicleUpgrade( pResource->GetLua(), pElement->GetLuaUserdata(), usUpgrade );
	}

	return false;
}

bool CMonoFunctions::Vehicle::RemoveUpgrade( TElement pThis, unsigned short usUpgrade )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RemoveVehicleUpgrade( pResource->GetLua(), pElement->GetLuaUserdata(), usUpgrade );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDoorState( TElement pThis, unsigned char ucDoor, unsigned char ucState )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleDoorState( pResource->GetLua(), pElement->GetLuaUserdata(), ucDoor, ucState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetWheelStates( TElement pThis, int iFrontLeft, int iRearLeft, int iFrontRight, int iRearRight )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleWheelStates( pResource->GetLua(), pElement->GetLuaUserdata(), iFrontLeft, iRearLeft, iFrontRight, iRearRight );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetLightState( TElement pThis, unsigned char ucLight, unsigned char ucState )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleLightState( pResource->GetLua(), pElement->GetLuaUserdata(), ucLight, ucState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetPanelState( TElement pThis, unsigned char ucPanel, unsigned char ucState )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehiclePanelState( pResource->GetLua(), pElement->GetLuaUserdata(), ucPanel, ucState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetIdleRespawnDelay( TElement pThis, unsigned long ulTime )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleIdleRespawnDelay( pResource->GetLua(), pElement->GetLuaUserdata(), ulTime );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetRespawnDelay( TElement pThis, unsigned long ulTime )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleRespawnDelay( pResource->GetLua(), pElement->GetLuaUserdata(), ulTime );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetRespawnPosition( TElement pThis, MonoObject* pPosition, MonoObject* pRotation )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fX = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Y" );
		float fZ = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Z" );

		float fRX = SharedUtil::MonoObject::GetPropertyValue< float >( pRotation, "X" );
		float fRY = SharedUtil::MonoObject::GetPropertyValue< float >( pRotation, "Y" );
		float fRZ = SharedUtil::MonoObject::GetPropertyValue< float >( pRotation, "Z" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleRespawnPosition( pResource->GetLua(), pElement->GetLuaUserdata(), fX, fY, fZ, fRX, fRY, fRZ );
	}

	return false;
}

bool CMonoFunctions::Vehicle::ToggleRespawn( TElement pThis, bool bRespawn )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ToggleVehicleRespawn( pResource->GetLua(), pElement->GetLuaUserdata(), bRespawn );
	}

	return false;
}

bool CMonoFunctions::Vehicle::ResetExplosionTime( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ResetVehicleExplosionTime( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::ResetIdleTime( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::ResetVehicleIdleTime( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::Spawn( TElement pThis, MonoObject* pPosition, MonoObject* pRotation )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fX = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Y" );
		float fZ = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Z" );

		float fRX = SharedUtil::MonoObject::GetPropertyValue< float >( pRotation, "X" );
		float fRY = SharedUtil::MonoObject::GetPropertyValue< float >( pRotation, "Y" );
		float fRZ = SharedUtil::MonoObject::GetPropertyValue< float >( pRotation, "Z" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SpawnVehicle( pResource->GetLua(), pElement->GetLuaUserdata(), fX, fY, fZ, fRX, fRY, fRZ );
	}

	return false;
}

bool CMonoFunctions::Vehicle::Respawn( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RespawnVehicle( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetOverrideLights( TElement pThis, unsigned char ucLights )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleOverrideLights( pResource->GetLua(), pElement->GetLuaUserdata(), ucLights );
	}

	return false;
}

bool CMonoFunctions::Vehicle::AttachTrailer( TElement pThis, TElement pTrailer )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pTrailerElement = pResource->GetElementManager()->GetFromList( pTrailer );
		
		return CLuaFunctionDefinitions::AttachTrailerToVehicle( pResource->GetLua(), pElement->GetLuaUserdata(), pTrailerElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::DetachTrailer( TElement pThis, TElement pTrailer )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pTrailerElement = pResource->GetElementManager()->GetFromList( pTrailer );
		
		return CLuaFunctionDefinitions::DetachTrailerFromVehicle( pResource->GetLua(), pElement->GetLuaUserdata(), pTrailerElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetEngineState( TElement pThis, bool bState )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleEngineState( pResource->GetLua(), pElement->GetLuaUserdata(), bState );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDirtLevel( TElement pThis, float fDirtLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleDirtLevel( pResource->GetLua(), pElement->GetLuaUserdata(), fDirtLevel );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDamageProof( TElement pThis, bool bDamageProof )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleDamageProof( pResource->GetLua(), pElement->GetLuaUserdata(), bDamageProof );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetPaintjob( TElement pThis, unsigned char ucPaintjob )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehiclePaintjob( pResource->GetLua(), pElement->GetLuaUserdata(), ucPaintjob );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetFuelTankExplodable( TElement pThis, bool bExplodable )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleFuelTankExplodable( pResource->GetLua(), pElement->GetLuaUserdata(), bExplodable );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainDerailed( TElement pThis, bool bDerailed )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTrainDerailed( pResource->GetLua(), pElement->GetLuaUserdata(), bDerailed );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainDerailable( TElement pThis, bool bDerailable )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTrainDerailable( pResource->GetLua(), pElement->GetLuaUserdata(), bDerailable );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainDirection( TElement pThis, bool bDireciton )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTrainDirection( pResource->GetLua(), pElement->GetLuaUserdata(), bDireciton );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTrainSpeed( TElement pThis, float fSpeed )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetTrainSpeed( pResource->GetLua(), pElement->GetLuaUserdata(), fSpeed );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetHeadLightColor( TElement pThis, MonoObject* pColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucR1 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor, "R" );
		unsigned char ucG1 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor, "G" );
		unsigned char ucB1 = SharedUtil::MonoObject::GetPropertyValue< unsigned char >( pColor, "B" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleHeadLightColor( pResource->GetLua(), pElement->GetLuaUserdata(), ucR1, ucG1, ucB1 );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetTurretPosition( TElement pThis, MonoObject* pPosition )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fX = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Y" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleTurretPosition( pResource->GetLua(), pElement->GetLuaUserdata(), fX, fY );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetDoorOpenRatio( TElement pThis, unsigned char ucDoor, float fRatio, unsigned long ulTime )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleDoorOpenRatio( pResource->GetLua(), pElement->GetLuaUserdata(), ucDoor, fRatio, ulTime );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetVariant( TElement pThis, unsigned char ucVariant, unsigned char ucVariant2 )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleVariant( pResource->GetLua(), pElement->GetLuaUserdata(), ucVariant, ucVariant2 );
	}

	return false;
}

bool CMonoFunctions::Vehicle::GiveSirens( TElement pThis, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360, bool bCheckLosFlag, bool bUseRandomiserFlag, bool bSilentFlag )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::GiveVehicleSirens( pResource->GetLua(), pElement->GetLuaUserdata(), ucSirenType, ucSirenCount, bFlag360, bCheckLosFlag, bUseRandomiserFlag, bSilentFlag );
	}

	return false;
}

bool CMonoFunctions::Vehicle::RemoveSirens( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::RemoveVehicleSirens( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Vehicle::SetSirens( TElement pThis, unsigned char ucSirenID, MonoObject* pPosition, MonoObject* pColor, float fMinAlpha )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fX		= SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY		= SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Y" );
		float fZ		= SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Z" );

		float fRed		= SharedUtil::MonoObject::GetPropertyValue< float >( pColor, "R" );
		float fGreen	= SharedUtil::MonoObject::GetPropertyValue< float >( pColor, "G" );
		float fBlue		= SharedUtil::MonoObject::GetPropertyValue< float >( pColor, "B" );
		float fAlpha	= SharedUtil::MonoObject::GetPropertyValue< float >( pColor, "A" );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehicleSirens( pResource->GetLua(), pElement->GetLuaUserdata(), ucSirenID, fX, fY, fZ, fRed, fGreen, fBlue, fAlpha, fMinAlpha );
	}

	return false;
}

MonoArray* CMonoFunctions::Vehicle::GetSirens( TElement pThis )
{
	return nullptr;
}

MonoObject* CMonoFunctions::Vehicle::GetSirenParams( TElement pThis )
{
	return nullptr;
}

bool CMonoFunctions::Vehicle::SetPlateText( TElement pThis, MonoString* msName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szText = mono_string_to_utf8( msName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetVehiclePlateText( pResource->GetLua(), pElement->GetLuaUserdata(), szText );
	}

	return false;
}
