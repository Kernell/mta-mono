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

// Object create/destroy functions
void CMonoFunctions::Object::Ctor( TElement pThis, unsigned short usModelID, MonoObject* pPosition, MonoObject* pRotation, bool bIsLowLod )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );
		Vector3 vecRotation( pRotation );

		PVOID pUserData = CLuaFunctionDefinitions::CreateObject( pResource->GetLua(), usModelID, vecPosition, vecRotation, bIsLowLod );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}


// Object get functions
MonoObject* CMonoFunctions::Object::GetScale( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecScale;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetObjectScale( pResource->GetLua(), pElement->ToLuaUserData(), vecScale ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecScale );
		}
	}

	return nullptr;
}


// Object set functions
bool CMonoFunctions::Object::SetScale( TElement pThis, MonoObject* pScale )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetObjectScale( pResource->GetLua(), pElement->ToLuaUserData(), Vector3( pScale ) );
	}

	return false;
}

bool CMonoFunctions::Object::Move( TElement pThis, unsigned long ulTime, MonoObject* pPosition, MonoObject* pRotation, MonoString* msEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3
			vecPosition( pPosition ),
			vecRotation( pRotation );

		const char* szEasingType = mono_string_to_utf8( msEasingType );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::MoveObject( pResource->GetLua(), pElement->ToLuaUserData(), ulTime, vecPosition, vecRotation, szEasingType, fEasingPeriod, fEasingAmplitude, fEasingOvershoot );
	}

	return false;
}

bool CMonoFunctions::Object::Stop( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::StopObject( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return false;
}
