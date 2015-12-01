/*********************************************************
*
*  Copyright � 2013, Innovation Roleplay Engine. 
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
#include "CMonoEvent.h"
#include "CMonoInterface.h"

#include "CResourceManager.h"
#include "CFunctions.h"

#include "extra/CLuaArgument.h"
#include "extra/CLuaArguments.h"

#include "include/ILuaModuleManager.h"
#include "lua/CLuaFunctionDefinitions.h"

extern ILuaModuleManager10	*g_pModuleManager;

class CResource
{
private:
	string						m_sName;

	MonoAssembly*				m_pMonoAssembly;
	MonoImage*					m_pMonoImage;
	MonoClass*					m_pMonoClass;

	uint32_t					m_uiGCHandle;

	lua_State*					m_pLuaVM;

	CMonoInterface*				m_pMono;
	CMonoDomain*				m_pMonoDomain;

public:
								CResource					( CMonoInterface* m_pMono, lua_State *pLuaVM, string sName );
								~CResource					( void );

	bool						CallEvent					( string strEventName, void* pThis, list< CLuaArgument* > argv );
	bool						AddEvent					( const char* szName, const char* szHandleElement );
	bool						RemoveEvent					( const char* szName, const char* szHandleElement );

	void						RegisterEvents				( void );
	void						RemoveEvents				( void );
	bool						Init						( void );
	void						OnStopping					( void );
	void						DoPulse						( void );
	bool						RegisterFunction			( const char *szFunctionName, lua_CFunction Func );

	void						Printf						( const char* szFormat, ... );
	void						DebugPrintf					( const char* szFormat, ... );
	void						ErrorPrintf					( const char* szFormat, ... );

	string						GetName						( void )		{ return this->m_sName; }
	lua_State*					GetLua						( void )		{ return this->m_pLuaVM; }
	CMonoInterface*				GetMono						( void )		{ return this->m_pMono; }
	CMonoDomain*				GetDomain					( void )		{ return this->m_pMonoDomain; }

private:
	
};

#endif