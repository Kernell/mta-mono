/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  External lua add-on module
*
*  Copyright © 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is © 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

#include "../StdInc.h"
#include "CLuaArguments.h"
#include <assert.h>

CLuaArguments::CLuaArguments( const CLuaArguments& Arguments )
{
	for( const auto& iter : Arguments.m_Arguments )
	{
		CLuaArgument* pArgument = new CLuaArgument( *iter );

		this->m_Arguments.push_back( pArgument );
	}
}

const CLuaArguments& CLuaArguments::operator = ( const CLuaArguments& Arguments )
{
	this->DeleteArguments();

	for( const auto& iter : Arguments.m_Arguments )
	{
		CLuaArgument* pArgument = new CLuaArgument( *iter );

		this->m_Arguments.push_back( pArgument );
	}

	return Arguments;
}

void CLuaArguments::ReadArguments( lua_State* luaVM, unsigned int uiIndexBegin )
{
	this->DeleteArguments();

	while( lua_type( luaVM, uiIndexBegin ) != LUA_TNONE )
	{
		CLuaArgument* pArgument = new CLuaArgument( luaVM, uiIndexBegin++ );

		this->m_Arguments.push_back( pArgument );
	}
}

void CLuaArguments::PushArguments( lua_State* luaVM ) const
{
	for( const auto& pArg : this->m_Arguments )
	{
		pArg->Push( luaVM );
	}
}

void CLuaArguments::PushArguments( CLuaArguments& Arguments )
{
	for( const auto& iter : Arguments.m_Arguments )
	{
		CLuaArgument* pArgument = new CLuaArgument( *iter );

		this->m_Arguments.push_back( pArgument );
	}
}

bool CLuaArguments::Call( lua_State* luaVM, const char* szFunction, int iResults, int iErrorFunc ) const
{
	assert( szFunction );
	assert( luaVM );

	lua_pushstring( luaVM, szFunction );
	lua_gettable( luaVM, LUA_GLOBALSINDEX );

	this->PushArguments( luaVM );

	int iret = lua_pcall( luaVM, m_Arguments.size(), iResults, iErrorFunc );

	return iret != LUA_ERRRUN && iret != LUA_ERRMEM;
}

CLuaArgument* CLuaArguments::PushNil( void )
{
	CLuaArgument* pArgument = new CLuaArgument;

	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

CLuaArgument* CLuaArguments::PushBoolean( bool bBool )
{
	CLuaArgument* pArgument = new CLuaArgument( bBool );

	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

CLuaArgument* CLuaArguments::PushNumber( double dNumber )
{
	CLuaArgument* pArgument = new CLuaArgument( dNumber );
	
	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

CLuaArgument* CLuaArguments::PushString( const char* szString )
{
	CLuaArgument* pArgument = new CLuaArgument( szString );
	
	this->m_Arguments.push_back( pArgument );
	
	return pArgument;
}

CLuaArgument* CLuaArguments::PushUserData( void* pUserData )
{
	CLuaArgument* pArgument = new CLuaArgument( pUserData );
	
	this->m_Arguments.push_back( pArgument );
	
	return pArgument;
}

CLuaArgument* CLuaArguments::PushFunction( lua_CFunction iFunction )
{
	CLuaArgument* pArgument = new CLuaArgument( iFunction );

	this->m_Arguments.push_back( pArgument );

	return pArgument;
}

CLuaArgument* CLuaArguments::PushArgument( const CLuaArgument& argument )
{
	CLuaArgument* pArgument = new CLuaArgument( argument ); // create a copy
	
	this->m_Arguments.push_back( pArgument );
	
	return pArgument;
}

void CLuaArguments::DeleteArguments( void )
{
	for( auto pArg : this->m_Arguments )
	{
		delete pArg;
	}

	this->m_Arguments.clear();
}