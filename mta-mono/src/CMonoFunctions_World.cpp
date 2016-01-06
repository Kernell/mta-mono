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

// General world get funcs
MonoArray* CMonoFunctions::World::GetTime( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucHour, ucMinute;

		if( CLuaFunctionDefinitions::GetTime( pResource->GetLua(), ucHour, ucMinute ) )
		{
			MonoArray* pArray = mono_array_new( pResource->GetDomain()->GetMonoPtr(), mono_get_char_class(), 2 );

			mono_array_set( pArray, unsigned char, 0, ucHour );
			mono_array_set( pArray, unsigned char, 1, ucMinute );

			return pArray;
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::World::GetWeather( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucWeather, ucWeatherBlending;

		if( CLuaFunctionDefinitions::GetWeather( pResource->GetLua(), ucWeather, ucWeatherBlending ) )
		{
			MonoArray* pArray = mono_array_new( pResource->GetDomain()->GetMonoPtr(), mono_get_char_class(), 2 );

			mono_array_set( pArray, unsigned char, 0, ucWeather );
			mono_array_set( pArray, unsigned char, 1, ucWeatherBlending );

			return pArray;
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::World::GetZoneName( MonoObject* mPosition, bool bCitiesOnly )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;

		Vector3 vecPosition( mPosition );

		if( CLuaFunctionDefinitions::GetZoneName( pResource->GetLua(), vecPosition, strOutName, bCitiesOnly ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}

	return nullptr;
}

float CMonoFunctions::World::GetGravity( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fGravity;

		if( CLuaFunctionDefinitions::GetGravity( pResource->GetLua(), fGravity ) )
		{
			return fGravity;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetGameSpeed( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fGameSpeed;

		if( CLuaFunctionDefinitions::GetGameSpeed( pResource->GetLua(), fGameSpeed ) )
		{
			return fGameSpeed;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetWaveHeight( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fHeight;

		if( CLuaFunctionDefinitions::GetWaveHeight( pResource->GetLua(), fHeight ) )
		{
			return fHeight;
		}
	}

	return 0.0f;
}

unsigned short CMonoFunctions::World::GetFPSLimit( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned short usLimit;

		if( CLuaFunctionDefinitions::GetFPSLimit( pResource->GetLua(), usLimit ) )
		{
			return usLimit;
		}
	}

	return 0;
}

unsigned long CMonoFunctions::World::GetMinuteDuration( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned long usDuration;

		if( CLuaFunctionDefinitions::GetMinuteDuration( pResource->GetLua(), usDuration ) )
		{
			return usDuration;
		}
	}

	return 0;
}

bool CMonoFunctions::World::IsGarageOpen( unsigned char ucGarageID )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bIsOpen;

		if( CLuaFunctionDefinitions::IsGarageOpen( pResource->GetLua(), ucGarageID, bIsOpen ) )
		{
			return bIsOpen;
		}
	}

	return false;
}

unsigned char CMonoFunctions::World::GetTrafficLightState( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucState;

		if( CLuaFunctionDefinitions::GetTrafficLightState( pResource->GetLua(), ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

bool CMonoFunctions::World::GetTrafficLightsLocked( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bIsLocked;

		if( CLuaFunctionDefinitions::GetTrafficLightsLocked( pResource->GetLua(), bIsLocked ) )
		{
			return bIsLocked;
		}
	}

	return false;
}

float CMonoFunctions::World::GetJetpackMaxHeight( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fHeight;

		if( CLuaFunctionDefinitions::GetJetpackMaxHeight( pResource->GetLua(), fHeight ) )
		{
			return fHeight;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetAircraftMaxVelocity( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fVelocity;

		if( CLuaFunctionDefinitions::GetAircraftMaxVelocity( pResource->GetLua(), fVelocity ) )
		{
			return fVelocity;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::World::GetInteriorSoundsEnabled( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bEnabled;

		if( CLuaFunctionDefinitions::GetInteriorSoundsEnabled( pResource->GetLua(), bEnabled ) )
		{
			return bEnabled;
		}
	}

	return false;
}

float CMonoFunctions::World::GetRainLevel( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fRainLevel;

		if( CLuaFunctionDefinitions::GetRainLevel( pResource->GetLua(), fRainLevel ) )
		{
			return fRainLevel;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetSunSize( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fSunSize;

		if( CLuaFunctionDefinitions::GetSunSize( pResource->GetLua(), fSunSize ) )
		{
			return fSunSize;
		}
	}

	return 0.0f;
}

MonoArray* CMonoFunctions::World::GetSunColor( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pCore, pCorona;

		if( CLuaFunctionDefinitions::GetSunColor( pResource->GetLua(), pCore.R, pCore.G, pCore.B, pCorona.R, pCorona.G, pCorona.B ) )
		{
			pCore.A	= pCorona.A = 255;

			MonoObject* pCoreObject		= pResource->GetDomain()->GetMTALib()->Color->New( pCore );
			MonoObject* pCoronaObject	= pResource->GetDomain()->GetMTALib()->Color->New( pCorona );

			if( pCoreObject && pCoronaObject )
			{
				MonoArray* pMonoArray = mono_array_new( pResource->GetDomain()->GetMonoPtr(), CMonoObject::GetClass( pCoreObject ), 2 );

				mono_array_set( pMonoArray, MonoObject*, 0, pCoreObject );
				mono_array_set( pMonoArray, MonoObject*, 1, pCoronaObject );

				return pMonoArray;
			}
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::World::GetWindVelocity( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecVelocity;

		if( CLuaFunctionDefinitions::GetWindVelocity( pResource->GetLua(), vecVelocity.fX, vecVelocity.fY, vecVelocity.fZ ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecVelocity );
		}
	}

	return nullptr;
}

float CMonoFunctions::World::GetFarClipDistance( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fFarClip;

		if( CLuaFunctionDefinitions::GetFarClipDistance( pResource->GetLua(), fFarClip ) )
		{
			return fFarClip;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetFogDistance( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fFogDist;

		if( CLuaFunctionDefinitions::GetFogDistance( pResource->GetLua(), fFogDist ) )
		{
			return fFogDist;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetAircraftMaxHeight( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fMaxHeight;

		if( CLuaFunctionDefinitions::GetAircraftMaxHeight( pResource->GetLua(), fMaxHeight ) )
		{
			return fMaxHeight;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::World::GetOcclusionsEnabled( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bEnabled;

		if( CLuaFunctionDefinitions::GetOcclusionsEnabled( pResource->GetLua(), bEnabled ) )
		{
			return bEnabled;
		}
	}

	return false;
}

int CMonoFunctions::World::GetMoonSize( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		int iSize;

		if( CLuaFunctionDefinitions::GetMoonSize( pResource->GetLua(), iSize ) )
		{
			return iSize;
		}
	}

	return 0;
}

MonoArray* CMonoFunctions::World::GetSkyGradient( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pCore, pCorona;

		if( CLuaFunctionDefinitions::GetSkyGradient( pResource->GetLua(), pCore.R, pCore.G, pCore.B, pCorona.R, pCorona.G, pCorona.B ) )
		{
			pCore.A	= pCorona.A = 255;

			MonoObject* pCoreObject		= pResource->GetDomain()->GetMTALib()->Color->New( pCore );
			MonoObject* pCoronaObject	= pResource->GetDomain()->GetMTALib()->Color->New( pCorona );

			if( pCoreObject && pCoronaObject )
			{
				MonoArray* pMonoArray = mono_array_new( pResource->GetDomain()->GetMonoPtr(), CMonoObject::GetClass( pCoreObject ), 2 );

				mono_array_set( pMonoArray, MonoObject*, 0, pCoreObject );
				mono_array_set( pMonoArray, MonoObject*, 1, pCoronaObject );

				return pMonoArray;
			}
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::World::GetHeatHaze( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SHeatHazeSettings heatHazeSettings;

		if( CLuaFunctionDefinitions::GetHeatHaze( pResource->GetLua(), heatHazeSettings ) )
		{
			PVOID args[] =
			{
				&heatHazeSettings
			};

			return pResource->GetDomain()->GetMTALib()->GetClass( "HeatHazeSettings" )->New( args, 1 );
		}
	}

	return nullptr;
}

bool CMonoFunctions::World::GetJetpackWeaponEnabled( unsigned int uiWeaponType )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::GetJetpackWeaponEnabled( pResource->GetLua(), (eWeaponType)uiWeaponType );
	}

	return false;
}

bool CMonoFunctions::World::GetCloudsEnabled( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::GetCloudsEnabled( pResource->GetLua() );
	}

	return false;
}


// General world set funcs
bool CMonoFunctions::World::SetTime( unsigned char ucHour, unsigned char ucMinute )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetTime( pResource->GetLua(), ucHour, ucMinute );
	}

	return false;
}

bool CMonoFunctions::World::SetWeather( unsigned char ucWeather )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetWeather( pResource->GetLua(), ucWeather );
	}

	return false;
}

bool CMonoFunctions::World::SetWeatherBlended( unsigned char ucWeather )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetWeatherBlended( pResource->GetLua(), ucWeather );
	}

	return false;
}

bool CMonoFunctions::World::SetGravity( float fGravity )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetGravity( pResource->GetLua(), fGravity );
	}

	return false;
}

bool CMonoFunctions::World::SetGameSpeed( float fSpeed )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetGameSpeed( pResource->GetLua(), fSpeed );
	}

	return false;
}

bool CMonoFunctions::World::SetWaveHeight( float fHeight )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetWaveHeight( pResource->GetLua(), fHeight );
	}

	return false;
}

bool CMonoFunctions::World::SetSkyGradient( MonoObject* pTopColor, MonoObject* pBottomColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pTop		= CMonoObject::GetColor( pTopColor );
		SColor pBottom	= CMonoObject::GetColor( pBottomColor );

		return CLuaFunctionDefinitions::SetSkyGradient( pResource->GetLua(), pTop.R, pTop.G, pTop.B, pBottom.R, pBottom.G, pBottom.B );
	}

	return false;
}

bool CMonoFunctions::World::ResetSkyGradient( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetSkyGradient( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::SetHeatHaze( MonoObject* heatHazeSettings )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SHeatHazeSettings pHeatHazeSettings;

		pHeatHazeSettings.ucIntensity		= CMonoObject::GetPropertyValue< unsigned char >( heatHazeSettings, "ucIntensity" );
		pHeatHazeSettings.ucRandomShift		= CMonoObject::GetPropertyValue< unsigned char >( heatHazeSettings, "ucRandomShift" );
		pHeatHazeSettings.usSpeedMin		= CMonoObject::GetPropertyValue< unsigned short >( heatHazeSettings, "usSpeedMin" );
		pHeatHazeSettings.usSpeedMax		= CMonoObject::GetPropertyValue< unsigned short >( heatHazeSettings, "usSpeedMax" );
		pHeatHazeSettings.sScanSizeX		= CMonoObject::GetPropertyValue< short >( heatHazeSettings, "sScanSizeX" );
		pHeatHazeSettings.sScanSizeY		= CMonoObject::GetPropertyValue< short >( heatHazeSettings, "sScanSizeY" );
		pHeatHazeSettings.usRenderSizeX		= CMonoObject::GetPropertyValue< unsigned short >( heatHazeSettings, "usRenderSizeX" );
		pHeatHazeSettings.usRenderSizeY		= CMonoObject::GetPropertyValue< unsigned short >( heatHazeSettings, "usRenderSizeY" );
		pHeatHazeSettings.bInsideBuilding	= CMonoObject::GetPropertyValue< bool >( heatHazeSettings, "bInsideBuilding" );

		return CLuaFunctionDefinitions::SetHeatHaze( pResource->GetLua(), pHeatHazeSettings );
	}

	return false;
}

bool CMonoFunctions::World::ResetHeatHaze( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetHeatHaze( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::SetFPSLimit( unsigned short usLimit, bool bSave )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetFPSLimit( pResource->GetLua(), usLimit, bSave );
	}

	return false;
}

bool CMonoFunctions::World::SetMinuteDuration( unsigned long ulDuration )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetMinuteDuration( pResource->GetLua(), ulDuration );
	}

	return false;
}

bool CMonoFunctions::World::SetGarageOpen( unsigned char ucGarageID, bool bIsOpen )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetGarageOpen( pResource->GetLua(), ucGarageID, bIsOpen );
	}

	return false;
}

bool CMonoFunctions::World::SetGlitchEnabled( MonoString* msGlitchName, bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strGlitchName( mono_string_to_utf8( msGlitchName ) );

		return CLuaFunctionDefinitions::SetGlitchEnabled( pResource->GetLua(), strGlitchName, bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::IsGlitchEnabled( MonoString* msGlitchName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strGlitchName( mono_string_to_utf8( msGlitchName ) );

		return CLuaFunctionDefinitions::IsGlitchEnabled( pResource->GetLua(), strGlitchName );
	}

	return false;
}

bool CMonoFunctions::World::SetJetpackWeaponEnabled( unsigned int uiWeaponType, bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetJetpackWeaponEnabled( pResource->GetLua(), (eWeaponType)uiWeaponType, bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::SetCloudsEnabled( bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetCloudsEnabled( pResource->GetLua(), bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::SetTrafficLightState( unsigned char ucState, bool bForced )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetTrafficLightState( pResource->GetLua(), ucState, bForced );
	}

	return false;
}

bool CMonoFunctions::World::SetTrafficLightsLocked( bool bLocked )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetTrafficLightsLocked( pResource->GetLua(), bLocked );
	}

	return false;
}

bool CMonoFunctions::World::SetJetpackMaxHeight( float fMaxHeight )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetJetpackMaxHeight( pResource->GetLua(), fMaxHeight );
	}

	return false;
}

bool CMonoFunctions::World::SetInteriorSoundsEnabled( bool bEnable )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetInteriorSoundsEnabled( pResource->GetLua(), bEnable );
	}

	return false;
}

bool CMonoFunctions::World::SetRainLevel( float fRainLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetRainLevel( pResource->GetLua(), fRainLevel );
	}

	return false;
}

bool CMonoFunctions::World::SetSunSize( float fSunSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetSunSize( pResource->GetLua(), fSunSize );
	}

	return false;
}

bool CMonoFunctions::World::SetSunColor( MonoObject* pCoreColor, MonoObject* pCoronaColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pTop		= CMonoObject::GetColor( pCoreColor );
		SColor pBottom	= CMonoObject::GetColor( pCoronaColor );

		return CLuaFunctionDefinitions::SetSunColor( pResource->GetLua(), pTop.R, pTop.G, pTop.B, pBottom.R, pBottom.G, pBottom.B );
	}

	return false;
}

bool CMonoFunctions::World::SetWindVelocity( MonoObject* pVelocity )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecVelocity( pVelocity );

		return CLuaFunctionDefinitions::SetWindVelocity( pResource->GetLua(), vecVelocity.fX, vecVelocity.fY, vecVelocity.fZ );
	}

	return false;
}

bool CMonoFunctions::World::SetFarClipDistance( float fFarClip )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetFarClipDistance( pResource->GetLua(), fFarClip );
	}

	return false;
}

bool CMonoFunctions::World::SetFogDistance( float fFogDist )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetFogDistance( pResource->GetLua(), fFogDist );
	}

	return false;
}

bool CMonoFunctions::World::SetAircraftMaxHeight( float fMaxHeight )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetAircraftMaxHeight( pResource->GetLua(), fMaxHeight );
	}

	return false;
}

bool CMonoFunctions::World::SetAircraftMaxVelocity( float fVelocity )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetAircraftMaxVelocity( pResource->GetLua(), fVelocity );
	}

	return false;
}

bool CMonoFunctions::World::SetOcclusionsEnabled( bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetOcclusionsEnabled( pResource->GetLua(), bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::ResetRainLevel( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetRainLevel( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetSunSize( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetSunSize( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetSunColor( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetSunColor( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetWindVelocity( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetWindVelocity( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetFarClipDistance( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetFarClipDistance( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetFogDistance( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetFogDistance( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::RemoveWorldModel( unsigned short usModel, float fRadius, MonoObject* pPosition, char cInterior )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );

		return CLuaFunctionDefinitions::RemoveWorldModel( pResource->GetLua(), usModel, fRadius, vecPosition, cInterior );
	}

	return false;
}

bool CMonoFunctions::World::RestoreWorldModel( unsigned short usModel, float fRadius, MonoObject* pPosition, char cInterior )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );

		return CLuaFunctionDefinitions::RestoreWorldModel( pResource->GetLua(), usModel, fRadius, vecPosition, cInterior );
	}

	return false;
}

bool CMonoFunctions::World::RestoreAllWorldModels( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::RestoreAllWorldModels( pResource->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::SetMoonSize( int iMoonSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetMoonSize( pResource->GetLua(), iMoonSize );
	}

	return false;
}

bool CMonoFunctions::World::ResetMoonSize( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetMoonSize( pResource->GetLua() );
	}

	return false;
}
