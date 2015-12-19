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
DWORD CMonoFunctions::Object::Create( unsigned short usModelID, MonoObject* pPosition, MonoObject* pRotation, bool bIsLowLod )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );
		Vector3 vecRotation( pRotation );

		return (DWORD)CLuaFunctionDefinitions::CreateObject( RESOURCE->GetLua(), usModelID, vecPosition, vecRotation, bIsLowLod );
	}

	return NULL;
}


// Object get functions
MonoObject* CMonoFunctions::Object::GetScale( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecScale;
		
		if( CLuaFunctionDefinitions::GetObjectScale( RESOURCE->GetLua(), (void*)pUserData, vecScale ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Vector3->New( vecScale );
		}
	}

	return NULL;
}


// Object set functions
bool CMonoFunctions::Object::SetScale( DWORD pUserData, MonoObject* pScale )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetObjectScale( RESOURCE->GetLua(), (void*)pUserData, Vector3( pScale ) );
	}

	return false;
}

bool CMonoFunctions::Object::Move( DWORD pUserData, unsigned long ulTime, MonoObject* pPosition, MonoObject* pRotation, MonoString* msEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot )
{
	if( RESOURCE )
	{
		Vector3
			vecPosition( pPosition ),
			vecRotation( pRotation );

		const char* szEasingType = mono_string_to_utf8( msEasingType );
		
		return CLuaFunctionDefinitions::MoveObject( RESOURCE->GetLua(), (void*)pUserData, ulTime, vecPosition, vecRotation, szEasingType, fEasingPeriod, fEasingAmplitude, fEasingOvershoot );
	}

	return false;
}

bool CMonoFunctions::Object::Stop( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::StopObject( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}
