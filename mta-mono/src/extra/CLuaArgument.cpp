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
#include "CLuaArgument.h"
#include <assert.h>
#include <cstring>

using namespace std;

CLuaArgument::CLuaArgument( void )
{
	this->m_iType             = eLuaType::Nil;
	this->m_szString          = nullptr;
	this->m_pLightUserData    = nullptr;
	this->m_Function          = nullptr;
	this->m_bBoolean          = false;
	this->m_Number            = 0;
}

CLuaArgument::CLuaArgument( bool bBool ) : CLuaArgument()
{
	this->m_iType = eLuaType::Boolean;
	this->m_bBoolean = bBool;
}

CLuaArgument::CLuaArgument( double dNumber ) : CLuaArgument()
{
	this->m_iType = eLuaType::Number;
	this->m_Number = dNumber;
}

CLuaArgument::CLuaArgument( const char* szString ) : CLuaArgument()
{
	assert( szString );

	this->m_iType = eLuaType::String;
	this->m_szString = new char[ strlen( szString ) + 1 ];

	strcpy( this->m_szString, szString );
}

CLuaArgument::CLuaArgument( void* pUserData ) : CLuaArgument()
{
	this->m_iType = eLuaType::LightUserdata;
	this->m_pLightUserData = pUserData;
}

CLuaArgument::CLuaArgument( lua_CFunction Function ) : CLuaArgument()
{
	this->m_szString = NULL;
	this->m_iType = eLuaType::Function;
	this->m_Function = Function;
}

CLuaArgument::CLuaArgument( const CLuaArgument& Argument ) : CLuaArgument()
{
	operator = ( Argument );
}

CLuaArgument::CLuaArgument( lua_State* luaVM, unsigned int uiArgument ) : CLuaArgument()
{
	this->Read( luaVM, uiArgument );
}

CLuaArgument::~CLuaArgument( void )
{
	if( this->m_szString )
	{
		delete[] this->m_szString;
	}

	this->m_pArray.clear();
	this->m_pTable.clear();
}

const CLuaArgument& CLuaArgument::operator = ( const CLuaArgument& Argument )
{
	if( this->m_szString )
	{
		delete[] this->m_szString;
		this->m_szString = nullptr;
	}

	this->m_pArray.clear();
	this->m_pTable.clear();

	this->m_iType = Argument.m_iType;

	switch( this->m_iType )
	{
		case eLuaType::Boolean:
		{
			this->m_bBoolean = Argument.m_bBoolean;

			break;
		}
		case eLuaType::LightUserdata:
		{
			this->m_pLightUserData = Argument.m_pLightUserData;

			break;
		}
		case eLuaType::Number:
		{
			this->m_Number = Argument.m_Number;

			break;
		}
		case eLuaType::String:
		{
			if( Argument.m_szString )
			{
				this->m_szString = new char[ strlen( Argument.m_szString ) + 1 ];

				strcpy( this->m_szString, Argument.m_szString );
			}

			break;
		}
		case eLuaType::Function:
		{
			this->m_Function = Argument.m_Function;

			break;
		}
		case eLuaType::Table:
		{
			if( Argument.m_pArray.size() > 0 )
			{
				for( const auto& _item : Argument.m_pArray )
				{
					CLuaArgument* item = new CLuaArgument( _item );

					this->m_pArray.push_back( item );
				}
			}

			if( Argument.m_pTable.size() > 0 )
			{
				for( const auto& iter : Argument.m_pTable )
				{
					this->m_pTable[ iter.first ] = iter.second;
				}
			}

			break;
		}

		default: break;
	}

	return Argument;
}

bool CLuaArgument::operator == ( const CLuaArgument& Argument )
{
	if( Argument.m_iType != this->m_iType )
	{
		return false;
	}

	switch( this->m_iType )
	{
		case eLuaType::Boolean:
		{
			return this->m_bBoolean == Argument.m_bBoolean;
		}
		case eLuaType::LightUserdata:
		{
			return this->m_pLightUserData == Argument.m_pLightUserData;
		}
		case eLuaType::Number:
		{
			return this->m_Number == Argument.m_Number;
		}
		case eLuaType::String:
		{
			if( this->m_szString )
			{
				if( Argument.m_szString )
				{
					return strcmp( this->m_szString, Argument.m_szString ) == 0;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return Argument.m_szString == NULL;
			}
		}
		case eLuaType::Function:
		{
			return this->m_Function == Argument.m_Function;
		}
	}

	return true;
}

bool CLuaArgument::operator != ( const CLuaArgument& Argument )
{
	return !( operator == ( Argument ) );
}

void CLuaArgument::Read( lua_State* luaVM, signed int uiArgument )
{
	if( this->m_szString )
	{
		delete [] this->m_szString;
	}

	this->m_szString          = nullptr;
	this->m_pLightUserData    = nullptr;
	this->m_Function          = nullptr;

	this->m_pArray.clear();
	this->m_pTable.clear();

	this->m_iType = static_cast< eLuaType >( lua_type( luaVM, uiArgument ) );

	if( this->m_iType != eLuaType::None )
	{
		switch( this->m_iType )
		{
			case eLuaType::Nil:
			{
				break;
			}
			case eLuaType::Boolean:
			{
				this->m_bBoolean = lua_toboolean( luaVM, uiArgument ) != 0;

				break;
			}
			case eLuaType::LightUserdata:
			{
				this->m_pLightUserData = lua_touserdata( luaVM, uiArgument );

				break;
			}
			case eLuaType::Number:
			{
				this->m_Number = lua_tonumber( luaVM, uiArgument );

				break;
			}
			case eLuaType::String:
			{
				const char* szLuaString = lua_tostring( luaVM, uiArgument );

				this->m_szString = new char[ strlen( szLuaString ) + 1 ];

				strcpy( this->m_szString, szLuaString );

				break;
			}
			case eLuaType::Function:
			{
				this->m_Function = lua_tocfunction( luaVM, uiArgument );

				break;
			}
			case eLuaType::Table:
			{
				lua_pushnil( luaVM );

				uiArgument--;

				while( lua_next( luaVM, uiArgument ) != 0 )
				{
					CLuaArgument pKey( luaVM, -2 );
					CLuaArgument pValue( luaVM, -1 );

					if( pKey.GetType() == eLuaType::String )
					{
						this->m_pTable[ pKey.GetString() ] = pValue;
					}

					this->m_pArray.push_back( pValue );

					lua_pop( luaVM, 1 );
				}

				break;
			}
			default:
			{
				this->m_iType = eLuaType::None;

				break;
			}
		}
	}
}

void CLuaArgument::Push( lua_State* luaVM ) const
{
	if( this->m_iType != eLuaType::None )
	{
		switch( this->m_iType )
		{
			case eLuaType::Nil:
			{
				lua_pushnil( luaVM );

				break;
			}
			case eLuaType::Boolean:
			{
				lua_pushboolean( luaVM, this->m_bBoolean );
				break;
			}
			case eLuaType::LightUserdata:
			{
				lua_pushlightuserdata( luaVM, this->m_pLightUserData );

				break;
			}
			case eLuaType::Number:
			{
				lua_pushnumber( luaVM, this->m_Number );

				break;
			}
			case eLuaType::String:
			{
				lua_pushstring( luaVM, this->m_szString ? this->m_szString : "" );

				break;
			}
			case eLuaType::Function:
			{
				lua_pushcfunction( luaVM, this->m_Function );

				break;
			}
		}
	}
}

CLuaArgumentsVector CLuaArgument::GetArray( void ) const
{
	CLuaArgumentsVector pArray;

	for( const auto& arg : this->m_pArray )
	{
		CLuaArgument pArgument( arg );

		pArray.push_back( pArgument );
	}

	return pArray;
}

CLuaArgumentsMap CLuaArgument::GetTable( void ) const
{
	CLuaArgumentsMap pMap;

	for( const auto& iter : this->m_pTable )
	{
		CLuaArgument pArgument( iter.second );

		pMap[ iter.first.c_str() ] = pArgument;
	}

	return pMap;
}
