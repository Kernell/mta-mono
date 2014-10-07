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

#include "CLuaFunctionDefinitions.h"

string CLuaFunctionDefinitions::Get( lua_State *pLuaVM, const string &sKey )
{
	CLuaArguments pLuaArguments; 
	
	pLuaArguments.PushString( sKey.c_str() );
	
	if( pLuaArguments.Call( pLuaVM, "get", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char *szString = pLuaArgument.GetString() )
		{
			return string( szString );
		}
	}
	
	return string();
}

bool CLuaFunctionDefinitions::Set( lua_State *pLuaVM, const string &sKey, const string &sValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( sKey.c_str() );
	pLuaArguments.PushString( sValue.c_str() );
	
	if( pLuaArguments.Call( pLuaVM, "set", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		return pLuaArgument.GetBoolean();
	}

	return false;
}

string CLuaFunctionDefinitions::GetGameType( lua_State *pLuaVM )
{
	string sResult = "";

	CLuaArguments pLuaArguments; 

	if( pLuaArguments.Call( pLuaVM, "getGameType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}

	return string();
}

string CLuaFunctionDefinitions::GetMapName( lua_State *pLuaVM )
{
	CLuaArguments pLuaArguments; 

	if( pLuaArguments.Call( pLuaVM, "getMapName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}

	return string();
}

string CLuaFunctionDefinitions::GetRuleValue( lua_State *pLuaVM, const string &sKey )
{
	CLuaArguments pLuaArguments; 
	
	pLuaArguments.PushString( sKey.c_str() );
	
	if( pLuaArguments.Call( pLuaVM, "getRuleValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}
	
	return string();
}

bool CLuaFunctionDefinitions::RemoveRuleValue( lua_State *pLuaVM, const string &sKey )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( sKey.c_str() );

	if( pLuaArguments.Call( pLuaVM, "removeRuleValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetGameType( lua_State *pLuaVM, const string &sType )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( sType.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setGameType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMapName( lua_State *pLuaVM, const string &sName )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( sName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setMapName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetRuleValue( lua_State *pLuaVM, const string &sKey, const string &sValue )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( sKey.c_str() );
	pLuaArguments.PushString( sValue.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setRuleValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

void* CLuaFunctionDefinitions::CreateVehicle( lua_State* pLuaVM, int model, float fX, float fY, float fZ, float fRX, float fRY, float fRZ, string &numberplate, bool direction, int variant1, int variant2 )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( model );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );
	pLuaArguments.PushString( numberplate.c_str() );
	pLuaArguments.PushBoolean( direction );
	pLuaArguments.PushNumber( variant1 );
	pLuaArguments.PushNumber( variant2 );

	if( pLuaArguments.Call( pLuaVM, "createVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}