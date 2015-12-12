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

#define MODULE_NAME         "Mono 4.2.1"
#define MODULE_AUTHOR       "Dmitry Korolev <kernell@mtaroleplay.ru>"
#define MODULE_VERSION      0.23f

#include "CFunctions.h"
#include "CResource.h"
#include "CResourceManager.h"
#include "CMonoInterface.h"

ILuaModuleManager10*	g_pModuleManager		= nullptr;
CResourceManager*		g_pResourceManager		= nullptr;
CMonoInterface*			g_pMonoInterface		= nullptr;

MTAEXPORT bool InitModule( ILuaModuleManager10 *pManager, char *szModuleName, char *szAuthor, float *fVersion )
{
    g_pModuleManager	= pManager;
	g_pMonoInterface	= new CMonoInterface();
	g_pResourceManager	= new CResourceManager( g_pMonoInterface );

    strncpy( szModuleName, MODULE_NAME, MAX_INFO_LENGTH );
    strncpy( szAuthor, MODULE_AUTHOR, MAX_INFO_LENGTH );

    (*fVersion) = MODULE_VERSION;

    return true;
}

MTAEXPORT void RegisterFunctions( lua_State *pLuaVM )
{
    if( g_pModuleManager && pLuaVM && g_pResourceManager )
	{
		if( g_pModuleManager->RegisterFunction( pLuaVM, "mono_init", CFunctions::monoInit ) )
		{
			//luaL_dostring( pLuaVM, "addEventHandler( 'onResourceStart', resourceRoot, monoInit )" );
			luaL_dostring( pLuaVM, "addEventHandler( 'onResourceStart', resourceRoot, function( res ) mono_init( getResourceName( res ) ) end )" );
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

	if( g_pMonoInterface )
	{
		delete g_pMonoInterface;
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