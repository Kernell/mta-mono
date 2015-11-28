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
#define MODULE_VERSION      0.1f

#include "Common.h"

#include "CFunctions.h"

#include "CResource.h"
#include "CResourceManager.h"

ILuaModuleManager10	*g_pModuleManager		= NULL;
CResourceManager	*g_pResourceManager		= NULL;