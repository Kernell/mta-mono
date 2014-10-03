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
		CResource *pResource;

		if( !( pResource = g_pResourceManager->GetFromList( pLuaVM ) ) )
		{
			pResource = g_pResourceManager->Create( pLuaVM );
		}

		if( pResource )
		{
			pResource->Init();

			return 1;
		}
	}

	return 0;
}