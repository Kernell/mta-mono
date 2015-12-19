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

extern "C"
{
    #include <lua.h>
    #include <lualib.h>
    #include <lauxlib.h>
}

#ifdef WIN32
    #define MTAEXPORT extern "C" __declspec(dllexport)
#else
    #define MTAEXPORT extern "C"
#endif

#include <list>
#include <vector>
#include <map>
#include <string.h>
#include <sys/stat.h>
#include <assert.h>

#ifdef WIN32
#pragma warning( push )
#pragma warning( disable: 4996 )
#include <glib.h>
#pragma warning( pop )
#else
#include <glib.h>
#endif

#include <mono/jit/jit.h>
#include <mono/metadata/assembly.h>
#include <mono/metadata/mono-debug.h>
#include <mono/metadata/debug-helpers.h>
#include <mono/metadata/environment.h>
#include <mono/metadata/threads.h>
#include <mono/metadata/mono-gc.h>
#include <mono/utils/mono-logger.h>

#include "Common.h"

#ifndef stricmp
#ifdef _MSC_VER
#define stricmp _stricmp
#else
#define stricmp strcasecmp
#endif
#endif

#define SAFE_DELETE(p)	{ if(p) { delete (p); (p)=nullptr; } }
#define SAFE_RELEASE(p)	{ if(p) { (p)->Release(); (p)=nullptr; } }

#include "extra/Vector2.h"
#include "extra/Vector3.h"

#include "include/ILuaModuleManager.h"