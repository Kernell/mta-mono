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

class CModule;

#ifndef __CMODULE_H
#define __CMODULE_H

#include "CResourceManager.h"
#include "CMonoInterface.h"

#include "include/ILuaModuleManager.h"

class CModule
{
private:
	ILuaModuleManager10*					m_pModuleManager;
	CResourceManager*						m_pResourceManager;
	CMonoInterface*							m_pMonoInterface;

public:
											CModule					( ILuaModuleManager10* pModuleManager );
											~CModule				( void );

	void									DoPulse					( void );
	void									Shutdown				( void );

	void									ResourceStopping		( lua_State* pLuaVM );
	void									ResourceStopped			( lua_State* pLuaVM );

	inline CMonoInterface*					GetMono					( void ) const			{ return this->m_pMonoInterface; }
	inline CResourceManager*				GetResourceManager		( void ) const			{ return this->m_pResourceManager; }
	inline ILuaModuleManager10*				GetModuleManager		( void ) const			{ return this->m_pModuleManager; }

	template< typename ... Type >
	void									Printf					( const char* szFormat, Type ... args ) const
	{
		this->m_pModuleManager->Printf( szFormat, args ... );
	}

	template< typename ... Type >
	void									DebugPrintf				( lua_State* luaVM, const char* szFormat, Type ... args ) const
	{
		this->m_pModuleManager->DebugPrintf( luaVM, szFormat, args ... );
	}

	template< typename ... Type >
	void									ErrorPrintf				( const char* szFormat, Type ... args ) const
	{
		this->m_pModuleManager->ErrorPrintf( szFormat, args ... );
	}

	bool									RegisterFunction		( lua_State* luaVM, const char *szFunctionName, lua_CFunction Func );
	bool									GetResourceName			( lua_State* luaVM, string &strName );
	CChecksum								GetResourceMetaChecksum	( lua_State* luaVM );
	CChecksum								GetResourceFileChecksum	( lua_State* luaVM, const char* szFile );

	unsigned long							GetVersion				( void );
	const char*								GetVersionString		( void );
	const char*								GetVersionName			( void );
	unsigned long							GetNetcodeVersion		( void );
	const char*								GetOperatingSystemName	( void );

	lua_State*								GetResourceFromName		( const char* szResourceName );
};

#endif
