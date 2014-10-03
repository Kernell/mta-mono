/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
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

class CFunctions;

#ifndef __CFUNCTIONS_H
#define __CFUNCTIONS_H

#include "CResource.h"
#include "CResourceManager.h"

extern CResourceManager	*g_pResourceManager;
extern ILuaModuleManager10 *g_pModuleManager;

class CFunctions
{
public:
		static int		monoInit			( lua_State *pLuaVM );

};
#endif
