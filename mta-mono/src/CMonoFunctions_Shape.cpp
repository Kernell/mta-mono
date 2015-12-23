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

// Shape create funcs
DWORD CMonoFunctions::Shape::CreateCircle( MonoObject* pPosition, float fRadius )
{
	if( RESOURCE )
	{
		Vector2 vecPosition( pPosition );

		return (DWORD)CLuaFunctionDefinitions::CreateColCircle( RESOURCE->GetLua(), vecPosition, fRadius );
	}

	return NULL;
}

DWORD CMonoFunctions::Shape::CreateCuboid( MonoObject* pPosition, MonoObject* pSize )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );
		Vector3 vecSize( pSize );

		return (DWORD)CLuaFunctionDefinitions::CreateColCuboid( RESOURCE->GetLua(), vecPosition, vecSize );
	}

	return NULL;
}

DWORD CMonoFunctions::Shape::CreateSphere( MonoObject* pPosition, float fRadius )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		return (DWORD)CLuaFunctionDefinitions::CreateColSphere( RESOURCE->GetLua(), vecPosition, fRadius );
	}

	return NULL;
}

DWORD CMonoFunctions::Shape::CreateRectangle( MonoObject* pPosition, MonoObject* pSize )
{
	if( RESOURCE )
	{
		Vector2 vecPosition( pPosition );
		Vector2 vecSize( pSize );

		return (DWORD)CLuaFunctionDefinitions::CreateColRectangle( RESOURCE->GetLua(), vecPosition, vecSize );
	}

	return NULL;
}

DWORD CMonoFunctions::Shape::CreatePolygon( float fX, float fY, float fX1, float fY1, float fX2, float fY2, float fX3, float fY3, MonoArray* pPointList )
{
	if( RESOURCE )
	{
		vector< Vector2 > vecPointList;

		vecPointList.push_back( Vector2( fX, fY ) );
		vecPointList.push_back( Vector2( fX1, fY1 ) );
		vecPointList.push_back( Vector2( fX2, fY2 ) );
		vecPointList.push_back( Vector2( fX3, fY3 ) );
		
		for( unsigned int i = 0; i < mono_array_length( pPointList ); i++ )
		{
			MonoObject* pObject = mono_array_get( pPointList, MonoObject*, i );

			if( pObject )
			{
				vecPointList.push_back( Vector2( pObject ) );
			}
		}

		return (DWORD)CLuaFunctionDefinitions::CreateColPolygon( RESOURCE->GetLua(), vecPointList );
	}

	return NULL;
}

DWORD CMonoFunctions::Shape::CreateTube( MonoObject* pPosition, float fRadius, float fHeight )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		return (DWORD)CLuaFunctionDefinitions::CreateColTube( RESOURCE->GetLua(), vecPosition, fRadius, fHeight );
	}

	return NULL;
}
