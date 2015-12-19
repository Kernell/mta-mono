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

// Radar area create/destroy funcs
DWORD CMonoFunctions::RadarArea::Create( MonoObject* pPosition, MonoObject* pSize, MonoObject* color, DWORD pVisibleTo )
{
	if( RESOURCE )
	{
		Vector2 vecPosition( pPosition );
		Vector2 vecSize( pSize );
		SColor pColor			= CMonoObject::GetColor( color );

		return (DWORD)CLuaFunctionDefinitions::CreateRadarArea( RESOURCE->GetLua(), vecPosition, vecSize, pColor, (void*)pVisibleTo );
	}

	return NULL;
}


// Radar area get funcs
MonoObject* CMonoFunctions::RadarArea::GetSize( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector2 vecSize;
		
		if( CLuaFunctionDefinitions::GetRadarAreaSize( RESOURCE->GetLua(), (void*)pUserData, vecSize ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Vector2->New( vecSize );
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::RadarArea::GetColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		SColor outColor;
		
		if( CLuaFunctionDefinitions::GetRadarAreaColor( RESOURCE->GetLua(), (void*)pUserData, outColor ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return NULL;
}

bool CMonoFunctions::RadarArea::IsFlashing( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::IsRadarAreaFlashing( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::RadarArea::IsInside( DWORD pUserData, MonoObject* pPosition )
{
	if( RESOURCE )
	{
		bool bInside;

		float fX = CMonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pPosition, "Y" );

		Vector2 vecPosition( fX, fY );

		if( CLuaFunctionDefinitions::IsInsideRadarArea( RESOURCE->GetLua(), (void*)pUserData, vecPosition, bInside ) )
		{
			return bInside;
		}
	}

	return false;
}


// Radar area set funcs
bool CMonoFunctions::RadarArea::SetSize( DWORD pUserData, MonoObject* pSize )
{
	if( RESOURCE )
	{
		float fX = CMonoObject::GetPropertyValue< float >( pSize, "X" );
		float fY = CMonoObject::GetPropertyValue< float >( pSize, "Y" );

		Vector2 vecPosition( fX, fY );

		return CLuaFunctionDefinitions::SetRadarAreaSize( RESOURCE->GetLua(), (void*)pUserData, vecPosition );
	}

	return false;
}

bool CMonoFunctions::RadarArea::SetColor( DWORD pUserData, MonoObject* color )
{
	if( RESOURCE )
	{
		SColor pColor = CMonoObject::GetColor( color );

		return CLuaFunctionDefinitions::SetRadarAreaColor( RESOURCE->GetLua(), (void*)pUserData, pColor );
	}

	return false;
}

bool CMonoFunctions::RadarArea::SetFlashing( DWORD pUserData, bool bFlashing )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetRadarAreaFlashing( RESOURCE->GetLua(), (void*)pUserData, bFlashing );
	}

	return false;
}
