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

void CMonoFunctions::ColCircle::Ctor( TElement pThis, MonoObject* pPosition, float fRadius )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector2 vecPosition( pPosition );

		PVOID pUserData = CLuaFunctionDefinitions::CreateColCircle( pResource->GetLua(), vecPosition, fRadius );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

void CMonoFunctions::ColCuboid::Ctor( TElement pThis, MonoObject* pPosition, MonoObject* pSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );
		Vector3 vecSize( pSize );

		PVOID pUserData = CLuaFunctionDefinitions::CreateColCuboid( pResource->GetLua(), vecPosition, vecSize );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

void CMonoFunctions::ColSphere::Ctor( TElement pThis, MonoObject* pPosition, float fRadius )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );

		PVOID pUserData = CLuaFunctionDefinitions::CreateColSphere( pResource->GetLua(), vecPosition, fRadius );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

void CMonoFunctions::ColRectangle::Ctor( TElement pThis, MonoObject* pPosition, MonoObject* pSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector2 vecPosition( pPosition );
		Vector2 vecSize( pSize );

		PVOID pUserData = CLuaFunctionDefinitions::CreateColRectangle( pResource->GetLua(), vecPosition, vecSize );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

void CMonoFunctions::ColPolygon::Ctor( TElement pThis, MonoObject* vec1, MonoObject* vec2, MonoObject* vec3, MonoObject* vec4, MonoArray* pPointList )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		vector< Vector2 > vecPointList;

		vecPointList.push_back( Vector2( vec1 ) );
		vecPointList.push_back( Vector2( vec2 ) );
		vecPointList.push_back( Vector2( vec3 ) );
		vecPointList.push_back( Vector2( vec4 ) );
		
		for( unsigned int i = 0; i < mono_array_length( pPointList ); i++ )
		{
			MonoObject* pObject = mono_array_get( pPointList, MonoObject*, i );

			if( pObject )
			{
				vecPointList.push_back( Vector2( pObject ) );
			}
		}

		PVOID pUserData = CLuaFunctionDefinitions::CreateColPolygon( pResource->GetLua(), vecPointList );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

void CMonoFunctions::ColTube::Ctor( TElement pThis, MonoObject* pPosition, float fRadius, float fHeight )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );

		PVOID pUserData = CLuaFunctionDefinitions::CreateColTube( pResource->GetLua(), vecPosition, fRadius, fHeight );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}
