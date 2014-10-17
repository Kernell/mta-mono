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
		static MonoString*	Get									( MonoString *msKey );
		static bool			Set									( MonoString *msKey, MonoString *msValue );
	};

	class Element
	{
	public:
		// Element create/destroy
		static unsigned int	Create								( MonoString* msTypeName, MonoString* msID );
		static bool			Destroy								( unsigned int pUserData );
		static unsigned int Clone								( unsigned int pUserData, MonoObject* vecPosition, bool bCloneElement );

		// Element get funcs
		static bool			IsElement							( unsigned int pUserData );
		static MonoString*	GetType								( unsigned int pUserData );
		static unsigned int	GetByID								( MonoString* msID, unsigned int uiIndex );
		static unsigned int	GetByIndex							( int iIndex );
		static unsigned int	GetChild							( unsigned int pUserData, int iIndex );
		static int			GetChildrenCount					( unsigned int pUserData );
		static MonoString*	GetID								( unsigned int pUserData );
//		static MonoObject*	GetData								( unsigned int pUserData, MonoString* sKey, bool bInherit = true );
//		static ?*			GetAllData							( unsigned int pUserData );
		static unsigned int	GetParent							( unsigned int pUserData );
		static MonoObject*	GetPosition							( unsigned int pUserData );
		static MonoObject*	GetRotation							( unsigned int pUserData );
		static MonoObject*	GetVelocity							( unsigned int pUserData );
	};

	class Vehicle
	{
	public:
		static unsigned int	Create	( int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );
	};
};

#endif