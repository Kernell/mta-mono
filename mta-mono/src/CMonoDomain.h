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

#include "CMonoInterface.h"
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
	CMonoInterface*						m_pMono;
	CModule*							m_pModule;

	MonoAssembly*						m_pMonoAssembly;
	MonoImage*							m_pMonoImage;
	CMonoClass*							m_pMonoClass;

	CMonoCorlib*						m_pCorlib;
	CMonoMTALib*						m_pMTALib;

	vector< CMonoClass* >				m_ClassPool;

	string								m_strName;

public:
					CMonoDomain			( CMonoInterface* pMono, MonoDomain* pDomain, CResource* pResource, const char* szName );
					~CMonoDomain		( void );

	void			HandleException		( MonoObject* pException );

	CMonoClass*		FindOrAdd			( MonoClass* klass );

	bool			Init				( void );
	bool			Start				( void );
	void			Unload				( void );
	bool			Set					( bool bForce );
	MonoAssembly*	OpenAssembly		( const char *szName );
	MonoObject*		CreateObject		( MonoClass* klass );
	void			SetConfig			( const char* szBaseDir, const char* szConfigFileName );

	MonoString*		NewString			( const char* szText ) const;
	MonoString*		NewString			( const string& strText ) const;

	MonoArray*		NewElementArray		( MonoClass* pMonoClass, CLuaArgumentsVector pLuaArguments );

	template< class T, int iLuaType >
	MonoArray*		NewArray			( MonoClass* pMonoClass, CLuaArgumentsVector pLuaArguments )
	{
		MonoArray* pArray = mono_array_new( this->m_pDomain, pMonoClass, pLuaArguments.size() );

		if( pLuaArguments.size() > 0 )
		{
			int i = 0;

			for( const auto& pArgument : pLuaArguments )
			{
				switch( iLuaType )
				{
					case LUA_TBOOLEAN:
					{
						mono_array_set( pArray, T, i++, ( T )pArgument.GetBoolean() );

						break;
					}
					case LUA_TNUMBER:
					{
						mono_array_set( pArray, T, i++, ( T )pArgument.GetNumber() );

						break;
					}
					case LUA_TSTRING:
					{
						MonoString* msValue = this->NewString( pArgument.GetString() );

						mono_array_set( pArray, MonoString*, i++, msValue );

						break;
					}
					case LUA_TLIGHTUSERDATA:
					case LUA_TUSERDATA:
					{
						mono_array_set( pArray, T, i++, ( T )pArgument.GetLightUserData() );

						break;
					}
				}
			}
		}

		return pArray;
	}

	inline MonoDomain*		GetMonoPtr			( void ) const	{ return this->m_pDomain; }

	inline CMonoInterface*	GetMono				( void ) const	{ return this->m_pMono; }
	inline CResource*		GetResource			( void ) const	{ return this->m_pResource; }

	inline CMonoCorlib*		GetCorlib			( void ) const	{ return this->m_pCorlib; }
	inline CMonoMTALib*		GetMTALib			( void ) const	{ return this->m_pMTALib; }

	inline string			GetName				( void ) const	{ return this->m_strName; }
};

#endif