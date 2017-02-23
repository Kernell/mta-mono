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

#define MODULE_NAME         "Mono 4.2.2"
#define MODULE_AUTHOR       "Dmitry Korolev <kernell@mtaroleplay.ru>"
#define MODULE_VERSION      0.27f

#include "CModule.h"
#include "CFunctions.h"

CModule* g_pModule = nullptr;

DLL_EXPORT bool InitModule( ILuaModuleManager10* pManager, char* szModuleName, char* szAuthor, float* fVersion )
{
	new CModule( pManager );

    strncpy( szModuleName, MODULE_NAME, MAX_INFO_LENGTH );
    strncpy( szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH );

    (*fVersion) = MODULE_VERSION;

    return true;
}

DLL_EXPORT void RegisterFunctions( lua_State *pLuaVM )
{
    if( g_pModule && pLuaVM )
	{
		if( g_pModule->RegisterFunction( pLuaVM, "mono_init", CFunctions::monoInit ) )
		{
			luaL_dostring( pLuaVM, "addEventHandler( 'onResourceStart', resourceRoot, function( res ) mono_init( getResourceName( res ) ) end )" );
		}
	}
}

DLL_EXPORT bool DoPulse( void )
{
	if( g_pModule )
	{
		g_pModule->DoPulse();
	}

    return true;
}

DLL_EXPORT bool ShutdownModule( void )
{
    if( g_pModule )
	{
		g_pModule->Shutdown();
	}

    return true;
}

DLL_EXPORT bool ResourceStopping( lua_State* luaVM )
{
	if( g_pModule )
	{
		g_pModule->ResourceStopping( luaVM );
	}

    return true;
}

DLL_EXPORT bool ResourceStopped( lua_State* luaVM )
{
	if( g_pModule )
	{
		g_pModule->ResourceStopped( luaVM );
	}

    return true;
}