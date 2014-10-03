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

class CMonoFunctions;

#ifndef __CMONOFUNCTIONS_H
#define __CMONOFUNCTIONS_H

#include "Common.h"
#include "lua/CLuaFunctionDefinitions.h"

class CMonoFunctions
{
public:
	static void				AddInternals( void );

	class Debug
	{
	public:
		static void			Log									( MonoString *string );
		static void			Info								( MonoString *string );
		static void			Error								( MonoString *string );
	};

	class Config
	{
	public:
		static MonoString	*Get								( MonoString *msKey );
		static bool			Set									( MonoString *msKey, MonoString *msValue );
	};
};

#endif