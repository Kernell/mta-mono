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
#include "CFunctions.h"
#include "extra/CLuaArguments.h"

int CFunctions::monoInit( lua_State *pLuaVM )
{
	if( pLuaVM )
	{
		CResource *pResource = g_pResourceManager->GetFromList( pLuaVM );

		if( pResource == nullptr )
		{
			//if( g_pModuleManager->GetResourceName( luaVM, strName ) )

			CLuaArgument pLuaArgument( pLuaVM, -1 );

			string strName = pLuaArgument.GetString();

			if( !strName.empty() )
			{
				pResource = g_pResourceManager->Create( pLuaVM, strName );
			}
		}

		if( pResource != nullptr )
		{
			pResource->Init();

			return 1;
		}
	}

	return 0;
}

int CFunctions::monoEventHandler( lua_State *pLuaVM )
{
	if( pLuaVM )
	{
		CResource *pResource = g_pResourceManager->GetFromList( pLuaVM );

		if( pResource )
		{
			// eventName, this, source, client, ...

			string	strEventName		= CLuaArgument( pLuaVM, -4 ).GetString();
			void*	pThis				= CLuaArgument( pLuaVM, -3 ).GetLightUserData();
			void*	pSource				= CLuaArgument( pLuaVM, -2 ).GetLightUserData();
			void*	pClient				= CLuaArgument( pLuaVM, -1 ).GetLightUserData();

			//void *args[] = { &vecVector.fX, &vecVector.fY };

			g_pModuleManager->DebugPrintf( pLuaVM, "event: %s", strEventName.c_str() );

			pResource->CallEvent( strEventName, pThis, pSource, pClient, nullptr );

			return 1;
		}
	}

	return 0;
}
