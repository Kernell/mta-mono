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

#include "mta-mono.h"

MTAEXPORT bool InitModule( ILuaModuleManager10 *pManager, char *szModuleName, char *szAuthor, float *fVersion )
{
    g_pModuleManager	= pManager;
	g_pResourceManager	= new CResourceManager();

    strncpy( szModuleName, MODULE_NAME, MAX_INFO_LENGTH );
    strncpy( szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH );

    (*fVersion) = MODULE_VERSION;

    return true;
}


MTAEXPORT void RegisterFunctions( lua_State *pLuaVM )
{
    if( g_pModuleManager && pLuaVM && g_pResourceManager )
	{
		if( g_pModuleManager->RegisterFunction( pLuaVM, "monoInit", CFunctions::monoInit ) )
		{
			luaL_dostring( pLuaVM, "addEventHandler( 'onResourceStart', resourceRoot, monoInit )" );
		}
	}
}


MTAEXPORT bool DoPulse( void )
{
	if( g_pResourceManager )
	{
		g_pResourceManager->DoPulse();
	}

    return true;
}

MTAEXPORT bool ShutdownModule( void )
{
    if( g_pResourceManager )
	{
		delete g_pResourceManager;
	}

    return true;
}

MTAEXPORT bool ResourceStopping( lua_State* luaVM )
{
	if( CResource *pResource = g_pResourceManager->GetFromList( luaVM ) )
	{
		pResource->OnStopping();
	}

    return true;
}

MTAEXPORT bool ResourceStopped( lua_State* luaVM )
{
	if( CResource *pResource = g_pResourceManager->GetFromList( luaVM ) )
	{
		delete pResource;
	}

    return true;
}