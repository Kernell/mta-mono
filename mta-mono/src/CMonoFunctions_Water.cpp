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

// Water funcs
void CMonoFunctions::Water::Ctor( TElement pThis, MonoObject* pV1, MonoObject* pV2, MonoObject* pV3, MonoObject* pV4, bool bShallow )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vec1( pV1 );
		Vector3 vec2( pV2 );
		Vector3 vec3( pV3 );
		Vector3 vec4 = pV4 ? Vector3( pV4 ) : nullptr;

		PVOID pUserData = CLuaFunctionDefinitions::CreateWater( pResource->GetLua(), &vec1, &vec2, &vec3, &vec4, bShallow );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

bool CMonoFunctions::Water::SetLevel( TElement pThis, float fLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementWaterLevel( pResource->GetLua(), pElement->ToLuaUserData(), fLevel );
	}

	return false;
}

bool CMonoFunctions::Water::SetLevelAll( float fLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetAllElementWaterLevel( pResource->GetLua(), fLevel );
	}

	return false;
}

bool CMonoFunctions::Water::SetLevelWorld( float fLevel, bool bIncludeWorldNonSeaLevel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::SetWorldWaterLevel( pResource->GetLua(), fLevel, bIncludeWorldNonSeaLevel );
	}

	return false;
}

bool CMonoFunctions::Water::ResetLevelWorld( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetWorldWaterLevel( pResource->GetLua() );
	}

	return false;
}

MonoObject* CMonoFunctions::Water::GetVertexPosition( TElement pThis, int iVertexIndex )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetWaterVertexPosition( pResource->GetLua(), pElement->ToLuaUserData(), iVertexIndex, vecPosition ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Water::SetVertexPosition( TElement pThis, int iVertexIndex, MonoObject* mPosition )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( mPosition );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetWaterVertexPosition( pResource->GetLua(), pElement->ToLuaUserData(), iVertexIndex, vecPosition );
	}

	return false;
}

MonoObject* CMonoFunctions::Water::GetColor( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pColor;

		if( CLuaFunctionDefinitions::GetWaterColor( pResource->GetLua(), pColor.R, pColor.G, pColor.B, pColor.A ) )
		{
			return pResource->GetDomain()->GetMTALib()->Color->New( pColor );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Water::SetColor( MonoObject* mColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pColor = CMonoObject::GetColor( mColor );

		return CLuaFunctionDefinitions::SetWaterColor( pResource->GetLua(), pColor.R, pColor.G, pColor.B, pColor.A );
	}

	return false;
}

bool CMonoFunctions::Water::ResetColor( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ResetWaterColor( pResource->GetLua() );
	}

	return false;
}
