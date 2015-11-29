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

class CMonoDomain;

#ifndef __CMONODOMAIN_H
#define __CMONODOMAIN_H

#include "CMonoCorlib.h"
#include "CMonoMTALib.h"
#include "CMonoClass.h"
#include "CResource.h"

#include "extra/CLuaArguments.h"

class CMonoDomain
{
private:
	MonoDomain*							m_pDomain;
	CResource*							m_pResource;

	CMonoCorlib*						m_pCorlib;
	CMonoMTALib*						m_pMTALib;

	vector< CMonoClass* >				m_ClassPool;

public:
					CMonoDomain			( CResource* pResource, MonoDomain* pDomain );
					~CMonoDomain		( void );

	CMonoClass*		FindOrAdd			( MonoClass* klass );

	void			Init				( void );

	void			Unload				( void );
	bool			Set					( bool bForce );
	MonoAssembly*	OpenAssembly		( const char *szName );
	MonoObject*		CreateObject		( MonoClass* klass );

	MonoString*		NewString			( const char* szText );
	MonoString*		NewString			( string strText );

	template <class T, int LuaType>
	MonoArray*		NewArray			( MonoClass* pMonoClass, CLuaArguments* pLuaArguments = NULL )
	{
		MonoArray* pArray = mono_array_new( this->m_pDomain, pMonoClass, pLuaArguments ? pLuaArguments->Count() : 0 );

		if( pLuaArguments )
		{
			int i = 0;

			for( auto iter : pLuaArguments->GetArguments() )
			{
				if( LuaType == LUA_TBOOLEAN )
				{
					mono_array_set( pArray, T, i++, (T)( iter->GetBoolean() ) );
				}
				else if( LuaType == LUA_TLIGHTUSERDATA )
				{
					mono_array_set( pArray, T, i++, (T)( iter->GetLightUserData() ) );
				}
				else if( LuaType == LUA_TNUMBER )
				{
					mono_array_set( pArray, T, i++, iter->GetNumber< T >() );
				}
				else if( LuaType == LUA_TSTRING )
				{
					mono_array_set( pArray, T, i++, (T)( iter->GetString() ) );
				}
				else if( LuaType == LUA_TUSERDATA )
				{
					mono_array_set( pArray, T, i++, (T)( iter->GetLightUserData() ) );
				}
			}
		}

		return pArray;
	}

	MonoDomain*		GetMonoPtr			( void )	{ return this->m_pDomain; }

	CResource*		GetResource			( void )	{ return this->m_pResource; }

	CMonoCorlib*	GetCorlib			( void )	{ return this->m_pCorlib; }
	CMonoMTALib*	GetMTALib			( void )	{ return this->m_pMTALib; }
};

#endif