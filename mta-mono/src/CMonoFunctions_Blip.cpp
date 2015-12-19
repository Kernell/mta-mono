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

// Blip create/destroy functions
DWORD CMonoFunctions::Blip::Create( MonoObject* pPosition, unsigned char ucIcon, unsigned char ucSize, MonoObject* color, short sOrdering, unsigned short usVisibleDistance, DWORD pVisibleTo )
{
	if( RESOURCE )
	{
		Vector3 vecPosition( pPosition );

		SColor pColor = CMonoObject::GetColor( color );

		return (DWORD)CLuaFunctionDefinitions::CreateBlip( RESOURCE->GetLua(), vecPosition, ucIcon, ucSize, pColor, sOrdering, usVisibleDistance, (void*)pVisibleTo );
	}

	return NULL;
}

DWORD CMonoFunctions::Blip::CreateAttachedTo( DWORD pTarget, unsigned char ucIcon, unsigned char ucSize, MonoObject* color, short sOrdering, unsigned short usVisibleDistance, DWORD pVisibleTo )
{
	if( RESOURCE )
	{
		SColor pColor = CMonoObject::GetColor( color );

		return (DWORD)CLuaFunctionDefinitions::CreateBlipAttachedTo( RESOURCE->GetLua(), (void*)pTarget, ucIcon, ucSize, pColor, sOrdering, usVisibleDistance, (void*)pVisibleTo );
	}

	return NULL;
}


// Blip get functions
unsigned char CMonoFunctions::Blip::GetIcon( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucIcon;
		
		if( CLuaFunctionDefinitions::GetBlipIcon( RESOURCE->GetLua(), (void*)pUserData, ucIcon ) )
		{
			return ucIcon;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Blip::GetSize( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucSize;
		
		if( CLuaFunctionDefinitions::GetBlipSize( RESOURCE->GetLua(), (void*)pUserData, ucSize ) )
		{
			return ucSize;
		}
	}

	return 0;
}

MonoObject* CMonoFunctions::Blip::GetColor( DWORD pUserData )
{
	if( RESOURCE )
	{
		SColor outColor;
		
		if( CLuaFunctionDefinitions::GetBlipColor( RESOURCE->GetLua(), (void*)pUserData, outColor ) )
		{
			return RESOURCE->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return nullptr;
}

short CMonoFunctions::Blip::GetOrdering( DWORD pUserData )
{
	if( RESOURCE )
	{
		short sOrdering;
		
		if( CLuaFunctionDefinitions::GetBlipOrdering( RESOURCE->GetLua(), (void*)pUserData, sOrdering ) )
		{
			return sOrdering;
		}
	}

	return 0;
}

unsigned short CMonoFunctions::Blip::GetVisibleDistance( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned short usVisibleDistance;
		
		if( CLuaFunctionDefinitions::GetBlipVisibleDistance( RESOURCE->GetLua(), (void*)pUserData, usVisibleDistance ) )
		{
			return usVisibleDistance;
		}
	}

	return 0;
}


// Blip set functions
bool CMonoFunctions::Blip::SetIcon( DWORD pUserData, unsigned char ucIcon )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetBlipIcon( RESOURCE->GetLua(), (void*)pUserData, ucIcon );
	}

	return false;
}

bool CMonoFunctions::Blip::SetSize( DWORD pUserData, unsigned char ucSize )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetBlipSize( RESOURCE->GetLua(), (void*)pUserData, ucSize );
	}

	return false;
}

bool CMonoFunctions::Blip::SetColor( DWORD pUserData, MonoObject* color )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetBlipColor( RESOURCE->GetLua(), (void*)pUserData, CMonoObject::GetColor( color ) );
	}

	return false;
}

bool CMonoFunctions::Blip::SetOrdering( DWORD pUserData, short sOrdering )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetBlipOrdering( RESOURCE->GetLua(), (void*)pUserData, sOrdering );
	}

	return false;
}

bool CMonoFunctions::Blip::SetVisibleDistance( DWORD pUserData, unsigned short usVisibleDistance )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetBlipVisibleDistance( RESOURCE->GetLua(), (void*)pUserData, usVisibleDistance );
	}

	return false;
}
