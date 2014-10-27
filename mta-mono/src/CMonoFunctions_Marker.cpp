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

// Marker create/destroy functions
DWORD CMonoFunctions::Marker::Create( MonoObject* pPosition, MonoString* msType, float fSize, MonoObject* pColor, DWORD pVisibleTo )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( pPosition );

		float fX = pPosition.GetPropertyValue< float >( "X" );
		float fY = pPosition.GetPropertyValue< float >( "Y" );
		float fZ = pPosition.GetPropertyValue< float >( "Z" );

		Vector3 vecPosition( fX, fY, fZ );

		const char* szType = mono_string_to_utf8( msType );

		CMonoObject pMonoColor( pColor );

		SColor pColor;

		pColor.R = pMonoColor.GetPropertyValue< unsigned char >( "R" );
		pColor.G = pMonoColor.GetPropertyValue< unsigned char >( "G" );
		pColor.B = pMonoColor.GetPropertyValue< unsigned char >( "B" );
		pColor.A = pMonoColor.GetPropertyValue< unsigned char >( "A" );

		return (DWORD)CLuaFunctionDefinitions::CreateMarker( RESOURCE->GetLua(), vecPosition, szType, fSize, pColor, (void*)pVisibleTo );
	}

	return NULL;
}


// Marker get functions
unsigned int CMonoFunctions::Marker::GetCount()
{
	if( RESOURCE )
	{
		unsigned int uiCount;
		
		if( CLuaFunctionDefinitions::GetMarkerCount( RESOURCE->GetLua(), uiCount ) )
		{
			return uiCount;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Marker::GetType( DWORD pUserData )
{
	if( RESOURCE )
	{
		char* szType = NULL;
		
		if( CLuaFunctionDefinitions::GetMarkerType( RESOURCE->GetLua(), (void*)pUserData, szType ) )
		{
			return RESOURCE->NewString( szType );
		}
	}

	return NULL;
}

float CMonoFunctions::Marker::GetSize( DWORD pUserData )
{
	if( RESOURCE )
	{
		float fSize;
		
		if( CLuaFunctionDefinitions::GetMarkerSize( RESOURCE->GetLua(), (void*)pUserData, fSize ) )
		{
			return fSize;
		}
	}

	return 0.0f;
}

MonoObject* CMonoFunctions::Marker::GetColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		SColor outColor;
		
		if( CLuaFunctionDefinitions::GetMarkerColor( RESOURCE->GetLua(), (void*)pUserData, outColor ) )
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

MonoObject* CMonoFunctions::Marker::GetTarget( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetMarkerTarget( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( vecPosition );

			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}

MonoString* CMonoFunctions::Marker::GetIcon( DWORD pUserData )
{
	if( RESOURCE )
	{
		char* szIcon = NULL;
		
		if( CLuaFunctionDefinitions::GetMarkerIcon( RESOURCE->GetLua(), (void*)pUserData, szIcon ) )
		{
			return RESOURCE->NewString( szIcon );
		}
	}

	return NULL;
}


// Marker set functions
bool CMonoFunctions::Marker::SetType( DWORD pUserData, MonoString* msType )
{
	if( RESOURCE )
	{
		const char* szType = mono_string_to_utf8( msType );
		
		return CLuaFunctionDefinitions::SetMarkerType( RESOURCE->GetLua(), (void*)pUserData, szType );
	}

	return false;
}

bool CMonoFunctions::Marker::SetSize( DWORD pUserData, float fSize )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetMarkerSize( RESOURCE->GetLua(), (void*)pUserData, fSize );
	}

	return false;
}

bool CMonoFunctions::Marker::SetColor( DWORD pUserData, MonoObject* color )
{
	if( RESOURCE )
	{
		SColor pColor;

		CMonoObject pMonoColor( color );

		pColor.R = pMonoColor.GetPropertyValue< unsigned char >( "R" );
		pColor.G = pMonoColor.GetPropertyValue< unsigned char >( "G" );
		pColor.B = pMonoColor.GetPropertyValue< unsigned char >( "B" );
		pColor.A = pMonoColor.GetPropertyValue< unsigned char >( "A" );
		
		return CLuaFunctionDefinitions::SetMarkerColor( RESOURCE->GetLua(), (void*)pUserData, pColor );
	}

	return false;
}

bool CMonoFunctions::Marker::SetTarget( DWORD pUserData, MonoObject* pTarget )
{
	if( RESOURCE )
	{
		Vector3* vecPosition = new Vector3;

		CMonoObject pTarget( pTarget );

		vecPosition->fX = pTarget.GetPropertyValue< float >( "X" );
		vecPosition->fY = pTarget.GetPropertyValue< float >( "Y" );
		vecPosition->fZ = pTarget.GetPropertyValue< float >( "Z" );
		
		return CLuaFunctionDefinitions::SetMarkerTarget( RESOURCE->GetLua(), (void*)pUserData, vecPosition );
	}

	return false;
}

bool CMonoFunctions::Marker::SetIcon( DWORD pUserData, MonoString* msIcon )
{
	if( RESOURCE )
	{
		const char* szIcon = mono_string_to_utf8( msIcon );
		
		return CLuaFunctionDefinitions::SetMarkerType( RESOURCE->GetLua(), (void*)pUserData, szIcon );
	}

	return false;
}
