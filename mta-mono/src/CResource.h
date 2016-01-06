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

#include "CModule.h"
#include "CMonoClass.h"
#include "CMonoEvent.h"
#include "CMonoInterface.h"

#include "CResourceManager.h"
#include "CEventManager.h"
#include "CRegisteredCommands.h"
#include "CFunctions.h"

#include "CElement.h"
#include "CElementManager.h"

#include "extra/CLuaArgument.h"
#include "extra/CLuaArguments.h"

#include "lua/CLuaFunctionDefinitions.h"

class CResource
{
private:
	string						m_sName;

	lua_State*					m_pLuaVM;

	CResourceManager*			m_pResourceManager;
	CElementManager*			m_pElementManager;
	CMonoInterface*				m_pMono;
	CMonoDomain*				m_pMonoDomain;
	CModule*					m_pModule;

	CEventManager*				m_pEventManager;
	CRegisteredCommands*		m_pRegisteredCommands;

public:
								CResource					( CResourceManager* pResourceManager, lua_State* pLuaVM, const string& strName );
								~CResource					( void );

	bool						CallEvent					( const string& strEventName, PVOID pThis, list< CLuaArgument* > argv ) const;
	bool						AddEvent					( const char* szName, const char* szHandleElement );
	bool						RemoveEvent					( const char* szName, const char* szHandleElement );

	bool						ExecuteCommand				( PVOID pPlayer, const string& strCommandName, list< string > argv );

	void						RegisterEvents				( void );
	void						RemoveEvents				( void );
	bool						Init						( void );
	void						OnStopping					( void );
	void						DoPulse						( void );
	bool						RegisterFunction			( const char* szFunctionName, lua_CFunction Func );

	template< typename ... Type >
	void						Printf						( const char* szFormat, Type ... args ) const
	{
		this->m_pModule->Printf( szFormat, args ... );
	}

	template< typename ... Type >
	void						DebugPrintf					( const char* szFormat, Type ... args ) const
	{
		this->m_pModule->DebugPrintf( this->m_pLuaVM, szFormat, args ... );
	}

	template< typename ... Type >
	void						ErrorPrintf					( const char* szFormat, Type ... args ) const
	{
		this->m_pModule->ErrorPrintf( szFormat, args ... );
	}

	inline string				GetName						( void ) const		{ return this->m_sName; }
	inline CModule*				GetModule					( void ) const		{ return this->m_pModule; }
	inline lua_State*			GetLua						( void ) const		{ return this->m_pLuaVM; }
	inline CMonoInterface*		GetMono						( void ) const		{ return this->m_pMono; }
	inline CMonoDomain*			GetDomain					( void ) const		{ return this->m_pMonoDomain; }
	inline CEventManager*		GetEventManager				( void ) const		{ return this->m_pEventManager; }
	inline CElementManager*		GetElementManager			( void ) const		{ return this->m_pElementManager; }
	inline CRegisteredCommands*	GetCommandManager			( void ) const		{ return this->m_pRegisteredCommands; }

private:
	
};

#endif