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

// General world get funcs
MonoArray* CMonoFunctions::World::GetTime( void )
{
	if( RESOURCE )
	{
		unsigned char ucHour, ucMinute;

		if( CLuaFunctionDefinitions::GetTime( RESOURCE->GetLua(), ucHour, ucMinute ) )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->m_pMonoDomain, mono_get_char_class(), 2 );

			mono_array_set( pArray, unsigned char, 0, ucHour );
			mono_array_set( pArray, unsigned char, 1, ucMinute );

			return pArray;
		}
	}

	return NULL;
}

MonoArray* CMonoFunctions::World::GetWeather( void )
{
	if( RESOURCE )
	{
		unsigned char ucWeather, ucWeatherBlending;

		if( CLuaFunctionDefinitions::GetWeather( RESOURCE->GetLua(), ucWeather, ucWeatherBlending ) )
		{
			MonoArray* pArray = mono_array_new( RESOURCE->m_pMonoDomain, mono_get_char_class(), 2 );

			mono_array_set( pArray, unsigned char, 0, ucWeather );
			mono_array_set( pArray, unsigned char, 1, ucWeatherBlending );

			return pArray;
		}
	}

	return NULL;
}

MonoString* CMonoFunctions::World::GetZoneName( MonoObject* mPosition, bool bCitiesOnly )
{
	if( RESOURCE )
	{
		string strOutName;

		Vector3 vecPosition( mPosition );

		if( CLuaFunctionDefinitions::GetZoneName( RESOURCE->GetLua(), vecPosition, strOutName, bCitiesOnly ) )
		{
			return RESOURCE->NewString( strOutName );
		}
	}

	return NULL;
}

float CMonoFunctions::World::GetGravity( void )
{
	if( RESOURCE )
	{
		float fGravity;

		if( CLuaFunctionDefinitions::GetGravity( RESOURCE->GetLua(), fGravity ) )
		{
			return fGravity;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetGameSpeed( void )
{
	if( RESOURCE )
	{
		float fGameSpeed;

		if( CLuaFunctionDefinitions::GetGameSpeed( RESOURCE->GetLua(), fGameSpeed ) )
		{
			return fGameSpeed;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetWaveHeight( void )
{
	if( RESOURCE )
	{
		float fHeight;

		if( CLuaFunctionDefinitions::GetWaveHeight( RESOURCE->GetLua(), fHeight ) )
		{
			return fHeight;
		}
	}

	return 0.0f;
}

unsigned short CMonoFunctions::World::GetFPSLimit( void )
{
	if( RESOURCE )
	{
		unsigned short usLimit;

		if( CLuaFunctionDefinitions::GetFPSLimit( RESOURCE->GetLua(), usLimit ) )
		{
			return usLimit;
		}
	}

	return 0;
}

unsigned long CMonoFunctions::World::GetMinuteDuration( void )
{
	if( RESOURCE )
	{
		unsigned long usDuration;

		if( CLuaFunctionDefinitions::GetMinuteDuration( RESOURCE->GetLua(), usDuration ) )
		{
			return usDuration;
		}
	}

	return 0;
}

bool CMonoFunctions::World::IsGarageOpen( unsigned char ucGarageID )
{
	if( RESOURCE )
	{
		bool bIsOpen;

		if( CLuaFunctionDefinitions::IsGarageOpen( RESOURCE->GetLua(), ucGarageID, bIsOpen ) )
		{
			return bIsOpen;
		}
	}

	return false;
}

unsigned char CMonoFunctions::World::GetTrafficLightState( void )
{
	if( RESOURCE )
	{
		unsigned char ucState;

		if( CLuaFunctionDefinitions::GetTrafficLightState( RESOURCE->GetLua(), ucState ) )
		{
			return ucState;
		}
	}

	return 0;
}

bool CMonoFunctions::World::GetTrafficLightsLocked( void )
{
	if( RESOURCE )
	{
		bool bIsLocked;

		if( CLuaFunctionDefinitions::GetTrafficLightsLocked( RESOURCE->GetLua(), bIsLocked ) )
		{
			return bIsLocked;
		}
	}

	return false;
}

float CMonoFunctions::World::GetJetpackMaxHeight( void )
{
	if( RESOURCE )
	{
		float fHeight;

		if( CLuaFunctionDefinitions::GetJetpackMaxHeight( RESOURCE->GetLua(), fHeight ) )
		{
			return fHeight;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetAircraftMaxVelocity( void )
{
	if( RESOURCE )
	{
		float fVelocity;

		if( CLuaFunctionDefinitions::GetAircraftMaxVelocity( RESOURCE->GetLua(), fVelocity ) )
		{
			return fVelocity;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::World::GetInteriorSoundsEnabled( void )
{
	if( RESOURCE )
	{
		bool bEnabled;

		if( CLuaFunctionDefinitions::GetInteriorSoundsEnabled( RESOURCE->GetLua(), bEnabled ) )
		{
			return bEnabled;
		}
	}

	return false;
}

float CMonoFunctions::World::GetRainLevel( void )
{
	if( RESOURCE )
	{
		float fRainLevel;

		if( CLuaFunctionDefinitions::GetRainLevel( RESOURCE->GetLua(), fRainLevel ) )
		{
			return fRainLevel;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetSunSize( void )
{
	if( RESOURCE )
	{
		float fSunSize;

		if( CLuaFunctionDefinitions::GetSunSize( RESOURCE->GetLua(), fSunSize ) )
		{
			return fSunSize;
		}
	}

	return 0.0f;
}

MonoArray* CMonoFunctions::World::GetSunColor( void )
{
	if( RESOURCE )
	{
		SColor pCore, pCorona;

		if( CLuaFunctionDefinitions::GetSunColor( RESOURCE->GetLua(), pCore.R, pCore.G, pCore.B, pCorona.R, pCorona.G, pCorona.B ) )
		{
			pCore.A	= pCorona.A = 255;

			MonoObject* pCoreObject		= RESOURCE->NewObject( pCore );
			MonoObject* pCoronaObject	= RESOURCE->NewObject( pCorona );

			if( pCoreObject && pCoronaObject )
			{
				MonoArray* pMonoArray = mono_array_new( RESOURCE->m_pMonoDomain, CMonoObject::GetClass( pCoreObject ), 2 );

				mono_array_set( pMonoArray, MonoObject*, 0, pCoreObject );
				mono_array_set( pMonoArray, MonoObject*, 1, pCoronaObject );

				return pMonoArray;
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::World::GetWindVelocity( void )
{
	if( RESOURCE )
	{
		Vector3 vecVelocity;

		if( CLuaFunctionDefinitions::GetWindVelocity( RESOURCE->GetLua(), vecVelocity.fX, vecVelocity.fY, vecVelocity.fZ ) )
		{
			return RESOURCE->NewObject( vecVelocity );
		}
	}

	return NULL;
}

float CMonoFunctions::World::GetFarClipDistance( void )
{
	if( RESOURCE )
	{
		float fFarClip;

		if( CLuaFunctionDefinitions::GetFarClipDistance( RESOURCE->GetLua(), fFarClip ) )
		{
			return fFarClip;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetFogDistance( void )
{
	if( RESOURCE )
	{
		float fFogDist;

		if( CLuaFunctionDefinitions::GetFogDistance( RESOURCE->GetLua(), fFogDist ) )
		{
			return fFogDist;
		}
	}

	return 0.0f;
}

float CMonoFunctions::World::GetAircraftMaxHeight( void )
{
	if( RESOURCE )
	{
		float fMaxHeight;

		if( CLuaFunctionDefinitions::GetAircraftMaxHeight( RESOURCE->GetLua(), fMaxHeight ) )
		{
			return fMaxHeight;
		}
	}

	return 0.0f;
}

bool CMonoFunctions::World::GetOcclusionsEnabled( void )
{
	if( RESOURCE )
	{
		bool bEnabled;

		if( CLuaFunctionDefinitions::GetOcclusionsEnabled( RESOURCE->GetLua(), bEnabled ) )
		{
			return bEnabled;
		}
	}

	return false;
}

int CMonoFunctions::World::GetMoonSize( void )
{
	if( RESOURCE )
	{
		int iSize;

		if( CLuaFunctionDefinitions::GetMoonSize( RESOURCE->GetLua(), iSize ) )
		{
			return iSize;
		}
	}

	return 0;
}

MonoArray* CMonoFunctions::World::GetSkyGradient( void )
{
	if( RESOURCE )
	{
		SColor pCore, pCorona;

		if( CLuaFunctionDefinitions::GetSkyGradient( RESOURCE->GetLua(), pCore.R, pCore.G, pCore.B, pCorona.R, pCorona.G, pCorona.B ) )
		{
			pCore.A	= pCorona.A = 255;

			MonoObject* pCoreObject		= RESOURCE->NewObject( pCore );
			MonoObject* pCoronaObject	= RESOURCE->NewObject( pCorona );

			if( pCoreObject && pCoronaObject )
			{
				MonoArray* pMonoArray = mono_array_new( RESOURCE->m_pMonoDomain, CMonoObject::GetClass( pCoreObject ), 2 );

				mono_array_set( pMonoArray, MonoObject*, 0, pCoreObject );
				mono_array_set( pMonoArray, MonoObject*, 1, pCoronaObject );

				return pMonoArray;
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::World::GetHeatHaze( void )
{
	if( RESOURCE )
	{
		SHeatHazeSettings heatHazeSettings;

		if( CLuaFunctionDefinitions::GetHeatHaze( RESOURCE->GetLua(), heatHazeSettings ) )
		{
			void* args[] =
			{
				&heatHazeSettings
			};

			return RESOURCE->NewObject( "MultiTheftAuto", "HeatHazeSettings", args, 1 );
		}
	}

	return NULL;
}

bool CMonoFunctions::World::GetJetpackWeaponEnabled( unsigned int uiWeaponType )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetJetpackWeaponEnabled( RESOURCE->GetLua(), (eWeaponType)uiWeaponType );
	}

	return false;
}

bool CMonoFunctions::World::GetCloudsEnabled( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetCloudsEnabled( RESOURCE->GetLua() );
	}

	return false;
}


// General world set funcs
bool CMonoFunctions::World::SetTime( unsigned char ucHour, unsigned char ucMinute )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTime( RESOURCE->GetLua(), ucHour, ucMinute );
	}

	return false;
}

bool CMonoFunctions::World::SetWeather( unsigned char ucWeather )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetWeather( RESOURCE->GetLua(), ucWeather );
	}

	return false;
}

bool CMonoFunctions::World::SetWeatherBlended( unsigned char ucWeather )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetWeatherBlended( RESOURCE->GetLua(), ucWeather );
	}

	return false;
}

bool CMonoFunctions::World::SetGravity( float fGravity )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetGravity( RESOURCE->GetLua(), fGravity );
	}

	return false;
}

bool CMonoFunctions::World::SetGameSpeed( float fSpeed )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetGameSpeed( RESOURCE->GetLua(), fSpeed );
	}

	return false;
}

bool CMonoFunctions::World::SetWaveHeight( float fHeight )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetWaveHeight( RESOURCE->GetLua(), fHeight );
	}

	return false;
}

bool CMonoFunctions::World::SetSkyGradient( MonoObject* pTopColor, MonoObject* pBottomColor )
{
	if( RESOURCE )
	{
		SColor pTop		= CMonoObject::GetColor( pTopColor );
		SColor pBottom	= CMonoObject::GetColor( pBottomColor );

		return CLuaFunctionDefinitions::SetSkyGradient( RESOURCE->GetLua(), pTop.R, pTop.G, pTop.B, pBottom.R, pBottom.G, pBottom.B );
	}

	return false;
}

bool CMonoFunctions::World::ResetSkyGradient( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetSkyGradient( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::SetHeatHaze( MonoObject* heatHazeSettings )
{
	if( RESOURCE )
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

		return CLuaFunctionDefinitions::SetHeatHaze( RESOURCE->GetLua(), pHeatHazeSettings );
	}

	return false;
}

bool CMonoFunctions::World::ResetHeatHaze( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetHeatHaze( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::SetFPSLimit( unsigned short usLimit, bool bSave )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetFPSLimit( RESOURCE->GetLua(), usLimit, bSave );
	}

	return false;
}

bool CMonoFunctions::World::SetMinuteDuration( unsigned long ulDuration )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetMinuteDuration( RESOURCE->GetLua(), ulDuration );
	}

	return false;
}

bool CMonoFunctions::World::SetGarageOpen( unsigned char ucGarageID, bool bIsOpen )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetGarageOpen( RESOURCE->GetLua(), ucGarageID, bIsOpen );
	}

	return false;
}

bool CMonoFunctions::World::SetGlitchEnabled( MonoString* msGlitchName, bool bEnabled )
{
	if( RESOURCE )
	{
		string strGlitchName( mono_string_to_utf8( msGlitchName ) );

		return CLuaFunctionDefinitions::SetGlitchEnabled( RESOURCE->GetLua(), strGlitchName, bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::IsGlitchEnabled( MonoString* msGlitchName )
{
	if( RESOURCE )
	{
		string strGlitchName( mono_string_to_utf8( msGlitchName ) );

		return CLuaFunctionDefinitions::IsGlitchEnabled( RESOURCE->GetLua(), strGlitchName );
	}

	return false;
}

bool CMonoFunctions::World::SetJetpackWeaponEnabled( unsigned int uiWeaponType, bool bEnabled )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetJetpackWeaponEnabled( RESOURCE->GetLua(), (eWeaponType)uiWeaponType, bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::SetCloudsEnabled( bool bEnabled )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetCloudsEnabled( RESOURCE->GetLua(), bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::SetTrafficLightState( unsigned char ucState, bool bForced )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTrafficLightState( RESOURCE->GetLua(), ucState, bForced );
	}

	return false;
}

bool CMonoFunctions::World::SetTrafficLightsLocked( bool bLocked )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetTrafficLightsLocked( RESOURCE->GetLua(), bLocked );
	}

	return false;
}

bool CMonoFunctions::World::SetJetpackMaxHeight( float fMaxHeight )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetJetpackMaxHeight( RESOURCE->GetLua(), fMaxHeight );
	}

	return false;
}

bool CMonoFunctions::World::SetInteriorSoundsEnabled( bool bEnable )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetInteriorSoundsEnabled( RESOURCE->GetLua(), bEnable );
	}

	return false;
}

bool CMonoFunctions::World::SetRainLevel( float fRainLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetRainLevel( RESOURCE->GetLua(), fRainLevel );
	}

	return false;
}

bool CMonoFunctions::World::SetSunSize( float fSunSize )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetSunSize( RESOURCE->GetLua(), fSunSize );
	}

	return false;
}

bool CMonoFunctions::World::SetSunColor( MonoObject* pCoreColor, MonoObject* pCoronaColor )
{
	if( RESOURCE )
	{
		SColor pTop		= CMonoObject::GetColor( pCoreColor );
		SColor pBottom	= CMonoObject::GetColor( pCoronaColor );

		return CLuaFunctionDefinitions::SetSunColor( RESOURCE->GetLua(), pTop.R, pTop.G, pTop.B, pBottom.R, pBottom.G, pBottom.B );
	}

	return false;
}

bool CMonoFunctions::World::SetWindVelocity( MonoObject* pVelocity )
{
	if( RESOURCE )
	{
		Vector3 vecVelocity( pVelocity );

		return CLuaFunctionDefinitions::SetWindVelocity( RESOURCE->GetLua(), vecVelocity.fX, vecVelocity.fY, vecVelocity.fZ );
	}

	return false;
}

bool CMonoFunctions::World::SetFarClipDistance( float fFarClip )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetFarClipDistance( RESOURCE->GetLua(), fFarClip );
	}

	return false;
}

bool CMonoFunctions::World::SetFogDistance( float fFogDist )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetFogDistance( RESOURCE->GetLua(), fFogDist );
	}

	return false;
}

bool CMonoFunctions::World::SetAircraftMaxHeight( float fMaxHeight )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetAircraftMaxHeight( RESOURCE->GetLua(), fMaxHeight );
	}

	return false;
}

bool CMonoFunctions::World::SetAircraftMaxVelocity( float fVelocity )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetAircraftMaxVelocity( RESOURCE->GetLua(), fVelocity );
	}

	return false;
}

bool CMonoFunctions::World::SetOcclusionsEnabled( bool bEnabled )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetOcclusionsEnabled( RESOURCE->GetLua(), bEnabled );
	}

	return false;
}

bool CMonoFunctions::World::ResetRainLevel( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetRainLevel( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetSunSize( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetSunSize( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetSunColor( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetSunColor( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetWindVelocity( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetWindVelocity( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetFarClipDistance( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetFarClipDistance( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::ResetFogDistance( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetFogDistance( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::RemoveWorldModel( unsigned short usModel, float fRadius, MonoObject* pPosition, char cInterior )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		return CLuaFunctionDefinitions::RemoveWorldModel( RESOURCE->GetLua(), usModel, fRadius, vecPosition, cInterior );
	}

	return false;
}

bool CMonoFunctions::World::RestoreWorldModel( unsigned short usModel, float fRadius, MonoObject* pPosition, char cInterior )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		return CLuaFunctionDefinitions::RestoreWorldModel( RESOURCE->GetLua(), usModel, fRadius, vecPosition, cInterior );
	}

	return false;
}

bool CMonoFunctions::World::RestoreAllWorldModels( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RestoreAllWorldModels( RESOURCE->GetLua() );
	}

	return false;
}

bool CMonoFunctions::World::SetMoonSize( int iMoonSize )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetMoonSize( RESOURCE->GetLua(), iMoonSize );
	}

	return false;
}

bool CMonoFunctions::World::ResetMoonSize( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetMoonSize( RESOURCE->GetLua() );
	}

	return false;
}
