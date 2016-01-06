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
void CMonoFunctions::Blip::Ctor( TElement pThis, MonoObject* pTarget, unsigned char ucIcon, unsigned char ucSize, MonoObject* pArgColor, short sOrdering, unsigned short usVisibleDistance, TElement pArgVisibleTo )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor pColor;
		PVOID pVisibleTo = nullptr;

		if( pArgColor )
		{
			pColor = CMonoObject::GetColor( pArgColor );
		}

		if( pArgVisibleTo )
		{
			CElement* pVisibleToElement = pResource->GetElementManager()->GetFromList( pArgVisibleTo );

			if( pVisibleToElement )
			{
				pVisibleTo = pVisibleToElement->ToLuaUserData();
			}
		}

		PVOID pUserData = nullptr;

		string strClassName = mono_class_get_name( mono_object_get_class( pTarget ) );

		if( strClassName == "Vector3" )
		{
			pUserData = CLuaFunctionDefinitions::CreateBlip( pResource->GetLua(), Vector3( pTarget ), ucIcon, ucSize, pColor, sOrdering, usVisibleDistance, pVisibleTo );
		}
		else
		{
			CElement* pTargetElement = pResource->GetElementManager()->GetFromList( pTarget );

			pUserData = CLuaFunctionDefinitions::CreateBlipAttachedTo( pResource->GetLua(), pTargetElement->ToLuaUserData(), ucIcon, ucSize, pColor, sOrdering, usVisibleDistance, pVisibleTo );
		}

		if( pUserData )
		{
			pResource->GetElementManager()->Create( pThis, pUserData );
		}
	}
}

// Blip get functions
unsigned char CMonoFunctions::Blip::GetIcon( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucIcon;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetBlipIcon( pResource->GetLua(), pElement->ToLuaUserData(), ucIcon ) )
		{
			return ucIcon;
		}
	}

	return 0;
}

unsigned char CMonoFunctions::Blip::GetSize( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucSize;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetBlipSize( pResource->GetLua(), pElement->ToLuaUserData(), ucSize ) )
		{
			return ucSize;
		}
	}

	return 0;
}

MonoObject* CMonoFunctions::Blip::GetColor( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		SColor outColor;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetBlipColor( pResource->GetLua(), pElement->ToLuaUserData(), outColor ) )
		{
			return pResource->GetDomain()->GetMTALib()->Color->New( outColor );
		}
	}

	return nullptr;
}

short CMonoFunctions::Blip::GetOrdering( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		short sOrdering;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetBlipOrdering( pResource->GetLua(), pElement->ToLuaUserData(), sOrdering ) )
		{
			return sOrdering;
		}
	}

	return 0;
}

unsigned short CMonoFunctions::Blip::GetVisibleDistance( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned short usVisibleDistance;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetBlipVisibleDistance( pResource->GetLua(), pElement->ToLuaUserData(), usVisibleDistance ) )
		{
			return usVisibleDistance;
		}
	}

	return 0;
}


// Blip set functions
bool CMonoFunctions::Blip::SetIcon( TElement pThis, unsigned char ucIcon )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetBlipIcon( pResource->GetLua(), pElement->ToLuaUserData(), ucIcon );
	}

	return false;
}

bool CMonoFunctions::Blip::SetSize( TElement pThis, unsigned char ucSize )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetBlipSize( pResource->GetLua(), pElement->ToLuaUserData(), ucSize );
	}

	return false;
}

bool CMonoFunctions::Blip::SetColor( TElement pThis, MonoObject* color )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetBlipColor( pResource->GetLua(), pElement->ToLuaUserData(), CMonoObject::GetColor( color ) );
	}

	return false;
}

bool CMonoFunctions::Blip::SetOrdering( TElement pThis, short sOrdering )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetBlipOrdering( pResource->GetLua(), pElement->ToLuaUserData(), sOrdering );
	}

	return false;
}

bool CMonoFunctions::Blip::SetVisibleDistance( TElement pThis, unsigned short usVisibleDistance )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetBlipVisibleDistance( pResource->GetLua(), pElement->ToLuaUserData(), usVisibleDistance );
	}

	return false;
}
