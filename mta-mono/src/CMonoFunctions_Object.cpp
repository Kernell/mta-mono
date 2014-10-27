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

// Object create/destroy functions
DWORD CMonoFunctions::Object::Create( unsigned short usModelID, MonoObject* pPosition, MonoObject* pRotation, bool bIsLowLod )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( pPosition );

		float fX = pPosition.GetPropertyValue< float >( "X" );
		float fY = pPosition.GetPropertyValue< float >( "Y" );
		float fZ = pPosition.GetPropertyValue< float >( "Z" );

		Vector3 vecPosition( fX, fY, fZ );

		CMonoObject pRotation( pRotation );

		float fRX = pRotation.GetPropertyValue< float >( "X" );
		float fRY = pRotation.GetPropertyValue< float >( "Y" );
		float fRZ = pRotation.GetPropertyValue< float >( "Z" );

		Vector3 vecRotation( fRX, fRY, fRZ );

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
			CMonoObject* pObject = RESOURCE->NewObject( vecScale );

			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}


// Object set functions
bool CMonoFunctions::Object::SetScale( DWORD pUserData, MonoObject* pScale )
{
	if( RESOURCE )
	{
		Vector3 vecScale;

		CMonoObject pScale( pScale );

		vecScale.fX = pScale.GetPropertyValue< float >( "X" );
		vecScale.fY = pScale.GetPropertyValue< float >( "Y" );
		vecScale.fZ = pScale.GetPropertyValue< float >( "Z" );
		
		return CLuaFunctionDefinitions::SetObjectScale( RESOURCE->GetLua(), (void*)pUserData, vecScale );
	}

	return false;
}

bool CMonoFunctions::Object::Move( DWORD pUserData, unsigned long ulTime, MonoObject* pPosition, MonoObject* pRotation, MonoString* msEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot )
{
	if( RESOURCE )
	{
		Vector3 vecPosition, vecRotation;

		CMonoObject pPosition( pPosition );

		vecPosition.fX = pPosition.GetPropertyValue< float >( "X" );
		vecPosition.fY = pPosition.GetPropertyValue< float >( "Y" );
		vecPosition.fZ = pPosition.GetPropertyValue< float >( "Z" );

		CMonoObject pRotation( pRotation );

		vecRotation.fX = pRotation.GetPropertyValue< float >( "X" );
		vecRotation.fY = pRotation.GetPropertyValue< float >( "Y" );
		vecRotation.fZ = pRotation.GetPropertyValue< float >( "Z" );

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
