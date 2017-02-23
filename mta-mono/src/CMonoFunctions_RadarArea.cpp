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
void CMonoFunctions::RadarArea::Ctor( TElement pThis, MonoObject* pPosition, MonoObject* pSize, MonoObject* color, TElement pVisibleTo )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector2 vecPosition		( pPosition );
		Vector2 vecSize			( pSize );
		SColor pColor			= SharedUtil::MonoObject::GetColor( color );

		PVOID pElementVisibleTo = nullptr;

		if( pVisibleTo )
		{
			pElementVisibleTo = pResource->GetElementManager()->GetFromList( pVisibleTo )->GetLuaUserdata();
		}

		PVOID pUserData = CLuaFunctionDefinitions::CreateRadarArea( pResource->GetLua(), vecPosition, vecSize, pColor, pElementVisibleTo );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}


// Radar area get funcs
MonoObject* CMonoFunctions::RadarArea::GetSize( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector2 vecSize;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetRadarAreaSize( pResource->GetLua(), pElement->GetLuaUserdata(), vecSize ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector2->New( vecSize );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::RadarArea::GetColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor outColor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetRadarAreaColor( pResource->GetLua(), pElement->GetLuaUserdata(), outColor ) )
		{
			return pResource->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return nullptr;
}

bool CMonoFunctions::RadarArea::IsFlashing( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::IsRadarAreaFlashing( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::RadarArea::IsInside( TElement pThis, MonoObject* pPosition )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bInside;

		float fX = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "X" );
		float fY = SharedUtil::MonoObject::GetPropertyValue< float >( pPosition, "Y" );

		Vector2 vecPosition( fX, fY );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsInsideRadarArea( pResource->GetLua(), pElement->GetLuaUserdata(), vecPosition, bInside ) )
		{
			return bInside;
		}
	}

	return false;
}


// Radar area set funcs
bool CMonoFunctions::RadarArea::SetSize( TElement pThis, MonoObject* pSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fX = SharedUtil::MonoObject::GetPropertyValue< float >( pSize, "X" );
		float fY = SharedUtil::MonoObject::GetPropertyValue< float >( pSize, "Y" );

		Vector2 vecPosition( fX, fY );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetRadarAreaSize( pResource->GetLua(), pElement->GetLuaUserdata(), vecPosition );
	}

	return false;
}

bool CMonoFunctions::RadarArea::SetColor( TElement pThis, MonoObject* color )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pColor = SharedUtil::MonoObject::GetColor( color );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetRadarAreaColor( pResource->GetLua(), pElement->GetLuaUserdata(), pColor );
	}

	return false;
}

bool CMonoFunctions::RadarArea::SetFlashing( TElement pThis, bool bFlashing )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetRadarAreaFlashing( pResource->GetLua(), pElement->GetLuaUserdata(), bFlashing );
	}

	return false;
}
