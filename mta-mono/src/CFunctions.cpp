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