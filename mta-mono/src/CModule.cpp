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

#include "StdInc.h"
#include "CModule.h"

CModule::CModule( ILuaModuleManager10* pModule )
{
	this->m_pModuleManager = pModule;

	this->m_pMonoInterface		= new CMonoInterface( this );
	this->m_pResourceManager	= new CResourceManager( this, this->m_pMonoInterface );
}

CModule::~CModule( void )
{
	SAFE_DELETE( this->m_pResourceManager );
	SAFE_DELETE( this->m_pMonoInterface );

	this->m_pModuleManager = nullptr;
}

void CModule::DoPulse( void )
{
	this->m_pResourceManager->DoPulse();
}

void CModule::Shutdown( void )
{
	delete this;
}

void CModule::ResourceStopped( lua_State* pLuaVM )
{
	this->m_pResourceManager->ResourceStopped( pLuaVM );
}

void CModule::ResourceStopping( lua_State* pLuaVM )
{
	this->m_pResourceManager->ResourceStopping( pLuaVM );
}

bool CModule::RegisterFunction( lua_State* luaVM, const char *szFunctionName, lua_CFunction Func )
{
	return this->m_pModuleManager->RegisterFunction( luaVM, szFunctionName, Func );
}

bool CModule::GetResourceName( lua_State* luaVM, string &strName )
{
	return this->m_pModuleManager->GetResourceName( luaVM, strName );
}

CChecksum CModule::GetResourceMetaChecksum( lua_State* luaVM )
{
	return this->m_pModuleManager->GetResourceMetaChecksum( luaVM );
}

CChecksum CModule::GetResourceFileChecksum( lua_State* luaVM, const char* szFile )
{
	return this->m_pModuleManager->GetResourceFileChecksum( luaVM, szFile );
}

unsigned long CModule::GetVersion( void )
{
	return this->m_pModuleManager->GetVersion();
}

const char* CModule::GetVersionString( void )
{
	return this->m_pModuleManager->GetVersionString();
}

const char* CModule::GetVersionName( void )
{
	return this->m_pModuleManager->GetVersionName();
}

unsigned long CModule::GetNetcodeVersion( void )
{
	return this->m_pModuleManager->GetNetcodeVersion();
}

const char* CModule::GetOperatingSystemName( void )
{
	return this->m_pModuleManager->GetOperatingSystemName();
}

lua_State* CModule::GetResourceFromName( const char* szResourceName )
{
	return this->m_pModuleManager->GetResourceFromName( szResourceName );
}
