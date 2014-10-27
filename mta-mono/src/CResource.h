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

class CResource;

#ifndef __CRESOURCE_H
#define __CRESOURCE_H

#include "Common.h"
#include "CMonoClass.h"
#include "extra/CLuaArguments.h"

class CResource
{
private:
	string				m_sName;

	MonoAssembly		*m_pMonoAssembly;
	MonoAssembly		*m_pMonoAssemblyLib;
	MonoImage			*m_pMonoImage;
	MonoImage			*m_pMonoImageLib;
	MonoClass			*m_pMonoClass;
	uint32_t			m_pMonoGCHandle;

public:
	lua_State			*m_pLuaVM;
	MonoDomain			*m_pMonoDomain;

	CResource	( lua_State *pLuaVM, string sName );
	~CResource	( void );

	bool	Init				( void );
	void	OnStopping			( void );
	void	DoPulse				( void );
	bool	RegisterFunction	( const char *szFunctionName, lua_CFunction Func );

	CMonoClass* GetClassFromName( const char* szNamespace, const char* szName );

	CMonoObject* NewObject( const char* szNamespace, const char* szName );
	CMonoObject* NewObject( SColor& pColor );
	CMonoObject* NewObject( Vector2& vecVector );
	CMonoObject* NewObject( Vector3& vecVector );
	CMonoObject* NewObject( const char* szNamespace, const char* szName, void** args, int argc );
	
	MonoString*	NewString( const char* szText )
	{
		return mono_string_new( this->m_pMonoDomain, szText );
	}

	MonoString*	NewString( string strText )
	{
		return mono_string_new( this->m_pMonoDomain, strText.c_str() );
	}

	template <class T, int LuaType> MonoArray* NewArray( MonoClass* pMonoClass, CLuaArguments* pLuaArguments = NULL )
	{
		MonoArray* pArray = mono_array_new( this->m_pMonoDomain, pMonoClass, pLuaArguments ? pLuaArguments->Count() : 0 );

		if( pLuaArguments )
		{
			vector< CLuaArgument* >::const_iterator iter = pLuaArguments->IterBegin();

			for( unsigned int i = 0; iter != pLuaArguments->IterEnd(); iter++, i++ )
			{
				if( LuaType == LUA_TBOOLEAN )
				{
					mono_array_set( pArray, T, i, (T)( ( *iter )->GetBoolean() ) );
				}
				else if( LuaType == LUA_TLIGHTUSERDATA )
				{
					mono_array_set( pArray, T, i, (T)( ( *iter )->GetLightUserData() ) );
				}
				else if( LuaType == LUA_TNUMBER )
				{
					mono_array_set( pArray, T, i, ( *iter )->GetNumber< T >() );
				}
				else if( LuaType == LUA_TSTRING )
				{
					mono_array_set( pArray, T, i, (T)( ( *iter )->GetString() ) );
				}
				else if( LuaType == LUA_TUSERDATA )
				{
					mono_array_set( pArray, T, i, (T)( ( *iter )->GetLightUserData() ) );
				}
			}
		}

		return pArray;
	}

	string		GetName				( void )		{ return this->m_sName; }
	lua_State	*GetLua				( void )		{ return this->m_pLuaVM; }
};

#endif