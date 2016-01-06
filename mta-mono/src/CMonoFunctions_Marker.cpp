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

// Marker create/destroy functions
void CMonoFunctions::Marker::Ctor( TElement pThis, MonoObject* pPosition, MonoString* msType, float fSize, MonoObject* pColor, TElement pArgVisibleTo )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szType = mono_string_to_utf8( msType );

		PVOID pVisibleTo = nullptr;

		if( pArgVisibleTo )
		{
			pVisibleTo = pResource->GetElementManager()->GetFromList( pArgVisibleTo )->ToLuaUserData();
		}

		PVOID pUserData = CLuaFunctionDefinitions::CreateMarker( pResource->GetLua(), Vector3( pPosition ), szType, fSize, CMonoObject::GetColor( pColor ), pVisibleTo );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}


// Marker get functions
unsigned int CMonoFunctions::Marker::GetCount()
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiCount;
		
		if( CLuaFunctionDefinitions::GetMarkerCount( pResource->GetLua(), uiCount ) )
		{
			return uiCount;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Marker::GetMarkerType( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		char* szType = nullptr;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetMarkerType( pResource->GetLua(), pElement->ToLuaUserData(), szType ) )
		{
			return pResource->GetDomain()->NewString( szType );
		}
	}

	return nullptr;
}

float CMonoFunctions::Marker::GetSize( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fSize;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetMarkerSize( pResource->GetLua(), pElement->ToLuaUserData(), fSize ) )
		{
			return fSize;
		}
	}

	return 0.0f;
}

MonoObject* CMonoFunctions::Marker::GetColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor outColor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetMarkerColor( pResource->GetLua(), pElement->ToLuaUserData(), outColor ) )
		{
			return pResource->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Marker::GetTarget( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetMarkerTarget( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Marker::GetIcon( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		char* szIcon = nullptr;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetMarkerIcon( pResource->GetLua(), pElement->ToLuaUserData(), szIcon ) )
		{
			return pResource->GetDomain()->NewString( szIcon );
		}
	}

	return nullptr;
}


// Marker set functions
bool CMonoFunctions::Marker::SetType( TElement pThis, MonoString* msType )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szType = mono_string_to_utf8( msType );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetMarkerType( pResource->GetLua(), pElement->ToLuaUserData(), szType );
	}

	return false;
}

bool CMonoFunctions::Marker::SetSize( TElement pThis, float fSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetMarkerSize( pResource->GetLua(), pElement->ToLuaUserData(), fSize );
	}

	return false;
}

bool CMonoFunctions::Marker::SetColor( TElement pThis, MonoObject* pColor )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetMarkerColor( pResource->GetLua(), pElement->ToLuaUserData(), CMonoObject::GetColor( pColor ) );
	}

	return false;
}

bool CMonoFunctions::Marker::SetTarget( TElement pThis, MonoObject* pTarget )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetMarkerTarget( pResource->GetLua(), pElement->ToLuaUserData(), Vector3( pTarget ) );
	}

	return false;
}

bool CMonoFunctions::Marker::SetIcon( TElement pThis, MonoString* msIcon )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szIcon = mono_string_to_utf8( msIcon );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		return CLuaFunctionDefinitions::SetMarkerType( pResource->GetLua(), pElement->ToLuaUserData(), szIcon );
	}

	return false;
}
