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

// Radar area create/destroy funcs
DWORD CMonoFunctions::RadarArea::Create( MonoObject* pPosition, MonoObject* pSize, MonoObject* color, DWORD pVisibleTo )
{
	if( RESOURCE )
	{
		Vector2 vecPosition, vecSize;

		CMonoObject pPosition( pPosition );

		vecPosition.fX = pPosition.GetPropertyValue< float >( "X" );
		vecPosition.fY = pPosition.GetPropertyValue< float >( "Y" );

		CMonoObject pSize( pSize );

		vecSize.fX = pSize.GetPropertyValue< float >( "X" );
		vecSize.fY = pSize.GetPropertyValue< float >( "Y" );

		CMonoObject pMonoColor( color );

		SColor pColor;

		pColor.R = pMonoColor.GetPropertyValue< unsigned char >( "R" );
		pColor.G = pMonoColor.GetPropertyValue< unsigned char >( "G" );
		pColor.B = pMonoColor.GetPropertyValue< unsigned char >( "B" );
		pColor.A = pMonoColor.GetPropertyValue< unsigned char >( "A" );

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
			CMonoObject* pObject = RESOURCE->NewObject( vecSize );

			if( pObject )
			{
				return pObject->GetObject();
			}
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
			CMonoObject* pObject = RESOURCE->NewObject( outColor );

			if( pObject )
			{
				return pObject->GetObject();
			}
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

		CMonoObject pPosition( pPosition );

		float fX = pPosition.GetPropertyValue< float >( "X" );
		float fY = pPosition.GetPropertyValue< float >( "Y" );

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
		CMonoObject pSize( pSize );

		float fX = pSize.GetPropertyValue< float >( "X" );
		float fY = pSize.GetPropertyValue< float >( "Y" );

		Vector2 vecPosition( fX, fY );

		return CLuaFunctionDefinitions::SetRadarAreaSize( RESOURCE->GetLua(), (void*)pUserData, vecPosition );
	}

	return false;
}

bool CMonoFunctions::RadarArea::SetColor( DWORD pUserData, MonoObject* color )
{
	if( RESOURCE )
	{
		SColor pColor;

		CMonoObject pObject( color );

		pColor.R = pObject.GetPropertyValue< unsigned char >( "R" );
		pColor.G = pObject.GetPropertyValue< unsigned char >( "G" );
		pColor.B = pObject.GetPropertyValue< unsigned char >( "B" );
		pColor.A = pObject.GetPropertyValue< unsigned char >( "A" );

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
