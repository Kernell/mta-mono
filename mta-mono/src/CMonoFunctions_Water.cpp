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

// Water funcs
DWORD CMonoFunctions::Water::Create( MonoObject* pV1, MonoObject* pV2, MonoObject* pV3, MonoObject* pV4, bool bShallow )
{
	if( RESOURCE )
	{
		Vector3* vec1			= &CMonoObject( pV1 ).GetVector3();
		Vector3* vec2			= &CMonoObject( pV2 ).GetVector3();
		Vector3* vec3			= &CMonoObject( pV3 ).GetVector3();
		Vector3* vec4			= pV4 ? &CMonoObject( pV4 ).GetVector3() : NULL;

		return (DWORD)CLuaFunctionDefinitions::CreateWater( RESOURCE->GetLua(), vec1, vec2, vec3, vec4, bShallow );
	}

	return NULL;
}

bool CMonoFunctions::Water::SetLevel( DWORD pUserData, float fLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementWaterLevel( RESOURCE->GetLua(), (void*)pUserData, fLevel );
	}

	return false;
}

bool CMonoFunctions::Water::SetLevelAll( float fLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetAllElementWaterLevel( RESOURCE->GetLua(), fLevel );
	}

	return false;
}

bool CMonoFunctions::Water::SetLevelWorld( float fLevel, bool bIncludeWorldNonSeaLevel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetWorldWaterLevel( RESOURCE->GetLua(), fLevel, bIncludeWorldNonSeaLevel );
	}

	return false;
}

bool CMonoFunctions::Water::ResetLevelWorld( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetWorldWaterLevel( RESOURCE->GetLua() );
	}

	return false;
}

MonoObject* CMonoFunctions::Water::GetVertexPosition( DWORD pUserData, int iVertexIndex )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;

		if( CLuaFunctionDefinitions::GetWaterVertexPosition( RESOURCE->GetLua(), (void*)pUserData, iVertexIndex, vecPosition ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( vecPosition );

			return pObject ? pObject->GetObject() : NULL;
		}
	}

	return NULL;
}

bool CMonoFunctions::Water::SetVertexPosition( DWORD pUserData, int iVertexIndex, MonoObject* mPosition )
{
	if( RESOURCE )
	{
		Vector3 vecPosition = CMonoObject( mPosition ).GetVector3();

		return CLuaFunctionDefinitions::SetWaterVertexPosition( RESOURCE->GetLua(), (void*)pUserData, iVertexIndex, vecPosition );
	}

	return false;
}

MonoObject* CMonoFunctions::Water::GetColor( void )
{
	if( RESOURCE )
	{
		SColor pColor;

		if( CLuaFunctionDefinitions::GetWaterColor( RESOURCE->GetLua(), pColor.R, pColor.G, pColor.B, pColor.A ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( pColor );

			return pObject ? pObject->GetObject() : NULL;
		}
	}

	return NULL;
}

bool CMonoFunctions::Water::SetColor( MonoObject* mColor )
{
	if( RESOURCE )
	{
		SColor pColor = CMonoObject( mColor ).GetColor();

		return CLuaFunctionDefinitions::SetWaterColor( RESOURCE->GetLua(), pColor.R, pColor.G, pColor.B, pColor.A );
	}

	return false;
}

bool CMonoFunctions::Water::ResetColor( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ResetWaterColor( RESOURCE->GetLua() );
	}

	return false;
}
