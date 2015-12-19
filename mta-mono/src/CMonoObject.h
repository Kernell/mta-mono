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

class CMonoObject;

#ifndef _C_MONO_OBJECT
#define _C_MONO_OBJECT

#include "Common.h"

class CMonoObject
{
public:
	static MonoClass* GetClass( MonoObject* pMonoObject );

	static bool SetPropertyValue( MonoObject* pMonoObject, const char* szPropertyName, int iValue );
	static bool SetPropertyValue( MonoObject* pMonoObject, const char* szPropertyName, float fValue );
	static bool SetPropertyValue( MonoObject* pMonoObject, const char* szPropertyName, char* szValue );
	static bool SetPropertyValue( MonoObject* pMonoObject, const char* szPropertyName, gpointer gValue );

	static MonoObject* GetPropertyValue( MonoObject* pMonoObject, const char* szPropertyName );
	
	static SColor GetColor( MonoObject* pMonoObject )
	{
		SColor pColor;

		pColor.R = GetPropertyValue< unsigned char >( pMonoObject, "R" );
		pColor.G = GetPropertyValue< unsigned char >( pMonoObject, "G" );
		pColor.B = GetPropertyValue< unsigned char >( pMonoObject, "B" );
		pColor.A = GetPropertyValue< unsigned char >( pMonoObject, "A" );

		return pColor;
	}
	
	template <class T> static T GetPropertyValue( MonoObject* pMonoObject, const char* szPropertyName )
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( GetPropertyValue( pMonoObject, szPropertyName ) ) ) );
	}

	static void* GetValue( MonoObject* pMonoObject )
	{
		return mono_object_unbox( pMonoObject );
	}

	template <class T> static T GetValue( MonoObject* pMonoObject )
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( pMonoObject ) ) );
	}
};

#endif