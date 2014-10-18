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
		static DWORD			Create								( MonoString* msTypeName, MonoString* msID );
		static bool				Destroy								( DWORD pUserData );
		static DWORD			Clone								( DWORD pUserData, MonoObject* vecPosition, bool bCloneElement );

		// Element get funcs
		static bool				IsElement							( DWORD pUserData );
		static MonoString*		GetType								( DWORD pUserData );
		static DWORD			GetByID								( MonoString* msID, unsigned int uiIndex );
		static DWORD			GetByIndex							( int iIndex );
		static DWORD			GetChild							( DWORD pUserData, int iIndex );
		static int				GetChildrenCount					( DWORD pUserData );
		static MonoString*		GetID								( DWORD pUserData );
//		static MonoObject*		GetData								( DWORD pUserData, MonoString* sKey, bool bInherit = true );
//		static ?*				GetAllData							( DWORD pUserData );
		static unsigned int		GetParent							( DWORD pUserData );
		static MonoObject*		GetPosition							( DWORD pUserData );
		static MonoObject*		GetRotation							( DWORD pUserData );
		static MonoObject*		GetVelocity							( DWORD pUserData );
		static unsigned char	GetInterior							( DWORD pUserData );
		static bool				IsWithinColShape					( DWORD pUserData );
		static bool				IsWithinMarker						( DWORD pUserData );
		static unsigned short	GetDimension						( DWORD pUserData );
		static MonoString*		GetZoneName							( DWORD pUserData, bool bCitiesOnly = false );
		static bool				IsAttached							( DWORD pUserData );
		static DWORD			GetAttachedTo						( DWORD pUserData );
		static DWORD			GetColShape							( DWORD pUserData );
		static unsigned char	GetAlpha							( DWORD pUserData );
		static bool				IsDoubleSided						( DWORD pUserData );
		static float			GetHealth							( DWORD pUserData );
		static unsigned short	GetModel							( DWORD pUserData );
		static bool				IsInWater							( DWORD pUserData );
		static MonoObject*		GetAttachedOffsetPosition			( DWORD pUserData );
		static MonoObject*		GetAttachedOffsetRotation			( DWORD pUserData );
		static DWORD			GetSyncer							( DWORD pUserData );
		static bool				GetCollisionsEnabled				( DWORD pUserData );
		static bool				IsFrozen							( DWORD pUserData );
		static DWORD			GetLowLod							( DWORD pUserData );
		static bool				IsLowLod							( DWORD pUserData );

		// Element set funcs
		static bool				ClearVisibleTo						( DWORD pUserData );
		static bool				SetID								( DWORD pUserData, MonoString* msID );
		static bool				SetData								( DWORD pUserData, MonoString* msKey, CLuaArgument& Variable );
		static bool				RemoveData							( DWORD pUserData, MonoString* msKey );
		static bool				SetParent							( DWORD pUserData, DWORD pTarget );
		static bool				SetPosition							( DWORD pUserData, MonoObject* pPosition, bool bWarp );
		static bool				SetRotation							( DWORD pUserData, MonoObject* pRotation, MonoString* msRotationOrder, bool bNewWay );
		static bool				SetVelocity							( DWORD pUserData, MonoObject* pVelocity );
		static bool				SetVisibleTo						( DWORD pUserData, DWORD pTarget, bool bVisible );
		static bool				SetInterior							( DWORD pUserData, int iInterior );
		static bool				SetDimension						( DWORD pUserData, int iDimension );
		static bool				Attach								( DWORD pUserData, DWORD pTarget, MonoObject* pPosition, MonoObject* pRotation );
		static bool				Detach								( DWORD pUserData, DWORD pTarget );
		static bool				SetAlpha							( DWORD pUserData, int iAlpha );
		static bool				SetDoubleSided						( DWORD pUserData, bool bDoubleSided );
		static bool				SetHealth							( DWORD pUserData, float fHealth );
		static bool				SetModel							( DWORD pUserData, int iModel );
		static bool				SetAttachedOffsets					( DWORD pUserData, MonoObject* pPosition, MonoObject* pRotation );
		static bool				SetSyncer							( DWORD pUserData, DWORD pPlayer );
		static bool				SetCollisionsEnabled				( DWORD pUserData, bool bEnabled );
		static bool				SetFrozen							( DWORD pUserData, bool bFrozen );
		static bool				SetLowLod							( DWORD pUserData, bool bEnabled );
	};

	class Vehicle
	{
	public:
		static DWORD		Create	( int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );
	};
};

#endif