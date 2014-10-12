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

	string		GetName				( void )		{ return this->m_sName; }
	lua_State	*GetLua				( void )		{ return this->m_pLuaVM; }
};

#endif