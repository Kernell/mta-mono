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

// All-Seeing Eye related Functions

string CLuaFunctionDefinitions::Get( lua_State *pLuaVM, const char* szKey )
{
	CLuaArguments pLuaArguments; 
	
	pLuaArguments.PushString( szKey );
	
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

bool CLuaFunctionDefinitions::Set( lua_State *pLuaVM, const char* szKey, const char* szValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szValue );
	
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

string CLuaFunctionDefinitions::GetRuleValue( lua_State *pLuaVM, const char* szKey )
{
	CLuaArguments pLuaArguments; 
	
	pLuaArguments.PushString( szKey );
	
	if( pLuaArguments.Call( pLuaVM, "getRuleValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}
	
	return string();
}

bool CLuaFunctionDefinitions::RemoveRuleValue( lua_State *pLuaVM, const char* szKey )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( szKey );

	if( pLuaArguments.Call( pLuaVM, "removeRuleValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetGameType( lua_State *pLuaVM, const char* szGameType )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( szGameType );

	if( pLuaArguments.Call( pLuaVM, "setGameType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMapName( lua_State *pLuaVM, const char* szMapName )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( szMapName );

	if( pLuaArguments.Call( pLuaVM, "setMapName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetRuleValue( lua_State *pLuaVM, const char* szKey, const char* szValue )
{
	CLuaArguments pLuaArguments; 

	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szValue );

	if( pLuaArguments.Call( pLuaVM, "setRuleValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

string CLuaFunctionDefinitions::GetPlayerAnnounceValue( lua_State* pLuaVM, void* pElement, const char* szKey )
{
	CLuaArguments pLuaArguments; 
	
	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushString( szKey );
	
	if( pLuaArguments.Call( pLuaVM, "getPlayerAnnounceValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		if( const char *szString = pLuaArgument.GetString() )
			return string( szString );
	}
	
	return string();
}

bool CLuaFunctionDefinitions::SetPlayerAnnounceValue( lua_State* pLuaVM, void* pElement, const char* szKey, const char* szValue )
{
	CLuaArguments pLuaArguments; 
	
	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szValue );
	
	if( pLuaArguments.Call( pLuaVM, "setPlayerAnnounceValue", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		return pLuaArgument.GetBoolean();
	}
	
	return false;
}

bool CLuaFunctionDefinitions::AddCommandHandler( lua_State* pLuaVM, const char* szCommand, lua_CFunction iLuaFunction, bool bRestricted, bool bCaseSensitive )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szCommand );
	pLuaArguments.PushFunction( iLuaFunction );
	pLuaArguments.PushBoolean( bRestricted );
	pLuaArguments.PushBoolean( bCaseSensitive );

	if( pLuaArguments.Call( pLuaVM, "addCommandHandler", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::ExecuteCommandHandler( lua_State* pLuaVM, const char* szCommand, void* pUserData, const char* szArgs )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szCommand );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szArgs );

	if( pLuaArguments.Call( pLuaVM, "executeCommandHandler", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveCommandHandler( lua_State* pLuaVM, const char* szCommand, lua_CFunction iLuaFunction )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szCommand );
	pLuaArguments.PushFunction( iLuaFunction );

	if( pLuaArguments.Call( pLuaVM, "removeCommandHandler", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::AddEvent( lua_State* pLuaVM, const char* szName, bool bAllowRemoteTrigger )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushBoolean( bAllowRemoteTrigger );

	if( pLuaArguments.Call( pLuaVM, "addEvent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::AddEventHandler( lua_State* pLuaVM, const char* szName, void* pUserData, lua_CFunction iLuaFunction, bool bPropagated, const char* szEventPriority )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushFunction( iLuaFunction );
	pLuaArguments.PushBoolean( bPropagated );
	pLuaArguments.PushString( szEventPriority );

	if( pLuaArguments.Call( pLuaVM, "addEventHandler", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveEventHandler( lua_State* pLuaVM, const char* szName, void* pUserData, lua_CFunction iLuaFunction )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushFunction( iLuaFunction );

	if( pLuaArguments.Call( pLuaVM, "removeEventHandler", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::TriggerEvent( lua_State* pLuaVM, const char* szName, void* pUserData, CLuaArguments& Arguments )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushArguments( Arguments );

	if( pLuaArguments.Call( pLuaVM, "triggerEvent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::CancelEvent( lua_State* pLuaVM, bool bCancel, const char* szReason )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bCancel );
	pLuaArguments.PushString( szReason );

	if( pLuaArguments.Call( pLuaVM, "cancelEvent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::WasEventCancelled( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "wasEventCancelled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

string CLuaFunctionDefinitions::GetCancelReason( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getCancelReason", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TSTRING )
		{
			return pLuaArgument.GetString();
		}
	}

	return string();
}

bool CLuaFunctionDefinitions::TriggerClientEvent( lua_State* pLuaVM, void* pSendTo, const char* szName, void* pSource, CLuaArguments& Arguments )
{
	CLuaArguments pLuaArguments;

	if( pSendTo )
	{
		pLuaArguments.PushUserData( pSendTo );
	}

	pLuaArguments.PushString( szName );
	pLuaArguments.PushUserData( pSource );
	pLuaArguments.PushArguments( Arguments );

	if( pLuaArguments.Call( pLuaVM, "triggerClientEvent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TBOOLEAN )
		{
			return pLuaArgument.GetBoolean();
		}
	}

	return false;
}

// Element create/destroy

void* CLuaFunctionDefinitions::CreateElement( lua_State* pLuaVM, const char* szTypeName, const char* szID )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szTypeName );

	if( szID && strlen( szID ) > 0 )
	{
		pLuaArguments.PushString( szID );
	}

	if( pLuaArguments.Call( pLuaVM, "createElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::DestroyElement( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "destroyElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

void* CLuaFunctionDefinitions::CloneElement( lua_State* pLuaVM, void* pUserData, const Vector3& vecPosition, bool bCloneElement )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushBoolean( bCloneElement );

	if( pLuaArguments.Call( pLuaVM, "cloneElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Element get funcs

CLuaArguments* CLuaFunctionDefinitions::GetElementsByType( lua_State* pLuaVM, const char* szTypeName, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szTypeName );

	if( pUserData )
	{
		pLuaArguments.PushUserData( pUserData );
	}

	if( pLuaArguments.Call( pLuaVM, "getElementsByType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetArray();
	}
	
	return NULL;
}

bool CLuaFunctionDefinitions::IsElement( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

string CLuaFunctionDefinitions::GetElementType( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetString() )
		{
			return string( pLuaArgument.GetString() );
		}
	}

	return string();
}

void* CLuaFunctionDefinitions::GetElementByID( lua_State* pLuaVM, const char* szID, unsigned int uiIndex )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szID );

	if( uiIndex )
	{
		pLuaArguments.PushNumber( uiIndex );
	}

	if( pLuaArguments.Call( pLuaVM, "getElementByID", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetElementByIndex( lua_State* pLuaVM, int iIndex )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iIndex );

	if( pLuaArguments.Call( pLuaVM, "getElementByIndex", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetElementChild( lua_State* pLuaVM, void* pUserData, int iIndex )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iIndex );

	if( pLuaArguments.Call( pLuaVM, "getElementChild", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetElementChildrenCount( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementChildrenCount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return NULL;
}

string CLuaFunctionDefinitions::GetElementID( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementID", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

CLuaArgument* CLuaFunctionDefinitions::GetElementData( lua_State* pLuaVM, void* pUserData, string sKey, bool bInherit )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sKey.c_str() );
	pLuaArguments.PushBoolean( bInherit );

	if( pLuaArguments.Call( pLuaVM, "getElementData", 1 ) )
	{
		return new CLuaArgument( pLuaVM, -1 );
	}

	return NULL;
}

CLuaArguments* CLuaFunctionDefinitions::GetAllElementData( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getAllElementData", 1 ) )
	{
		CLuaArguments *pLuaArguments = new CLuaArguments();

		pLuaArguments->ReadArguments( pLuaVM );

		return pLuaArguments;
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetElementParent( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementParent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetElementPosition( lua_State* pLuaVM, void* pUserData, Vector3& vecPosition )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementPosition", 3 ) )
	{
		vecPosition.fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecPosition.fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecPosition.fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementRotation( lua_State* pLuaVM, void* pUserData, Vector3& vecRotation )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementRotation", 3 ) )
	{
		vecRotation.fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecRotation.fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecRotation.fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );
		
		return true;
	}


	return false;
}

bool CLuaFunctionDefinitions::GetElementVelocity( lua_State* pLuaVM, void* pUserData, Vector3& vecVelocity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementVelocity", 3 ) )
	{
		vecVelocity.fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecVelocity.fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecVelocity.fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );
		
		return true;
	}


	return false;
}

bool CLuaFunctionDefinitions::GetElementInterior( lua_State* pLuaVM, void* pUserData, unsigned char& ucInterior )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementInterior", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucInterior = static_cast< unsigned char >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementWithinColShape( lua_State* pLuaVM, void* pUserData, bool& bWithin )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementWithinColShape", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bWithin = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementWithinMarker( lua_State* pLuaVM, void* pUserData, bool& bWithin )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementWithinMarker", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bWithin = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementDimension( lua_State* pLuaVM, void* pUserData, unsigned short& usDimension )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementDimension", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		usDimension = pLuaArgument.GetNumber< unsigned short >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementZoneName( lua_State* pLuaVM, void* pUserData, string& strOutName, bool bCitiesOnly )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bCitiesOnly );

	if( pLuaArguments.Call( pLuaVM, "getElementZoneName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutName = string( pLuaArgument.GetString() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementAttached( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementAttached", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

void* CLuaFunctionDefinitions::GetElementAttachedTo( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAttachedTo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetElementColShape( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementColShape", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetElementAlpha( lua_State* pLuaVM, void* pUserData, unsigned char& ucAlpha )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAlpha", 1 ) )
	{
		ucAlpha = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementDoubleSided( lua_State* pLuaVM, void* pUserData, bool& bDoubleSided )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementDoubleSided", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bDoubleSided = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementHealth( lua_State* pLuaVM, void* pUserData, float& fHealth )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementHealth", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fHealth = pLuaArgument.GetNumber< float >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementModel( lua_State* pLuaVM, void* pUserData, unsigned short& usModel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementModel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		usModel = pLuaArgument.GetNumber< unsigned short >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementInWater( lua_State* pLuaVM, void* pUserData, bool& bInWater )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementInWater", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bInWater = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementAttachedOffsets( lua_State* pLuaVM, void* pUserData, Vector3& vecPosition, Vector3& vecRotation )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAttachedOffsets", 6 ) )
	{
		vecPosition.fX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -6 ) )->GetNumber() );
		vecPosition.fY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -5 ) )->GetNumber() );
		vecPosition.fZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		vecRotation.fX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecRotation.fY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecRotation.fZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetElementSyncer( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementSyncer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetElementCollisionsEnabled( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementCollisionsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementFrozen( lua_State* pLuaVM, void* pUserData, bool& bFrozen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bFrozen = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetLowLodElement( lua_State* pLuaVM, void* pUserData, void*& pOutLowLodElement )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getLowLodElement", 1 ) )
	{
		pOutLowLodElement = CLuaArgument( pLuaVM, -1 ).GetLightUserData();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementLowLod( lua_State* pLuaVM, void* pUserData, bool& bOutLowLod )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementLowLod", 1 ) )
	{
		bOutLowLod = CLuaArgument( pLuaVM, -1 ).GetBoolean();
	
		return true;
	}

	return false;
}

// Element set funcs

bool CLuaFunctionDefinitions::ClearElementVisibleTo( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "clearElementVisibleTo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementID( lua_State* pLuaVM, void* pUserData, string sID )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sID.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setElementID", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementData( lua_State* pLuaVM, void* pUserData, string sKey, const CLuaArgument& Variable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sKey.c_str() );
	pLuaArguments.PushArgument( Variable );

	if( pLuaArguments.Call( pLuaVM, "setElementData", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveElementData( lua_State* pLuaVM, void* pUserData, string sKey )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sKey.c_str() );

	if( pLuaArguments.Call( pLuaVM, "removeElementData", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementParent( lua_State* pLuaVM, void* pUserData, void* pTarget )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTarget );

	if( pLuaArguments.Call( pLuaVM, "setElementParent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementPosition( lua_State* pLuaVM, void* pUserData, const Vector3& vecPosition, bool bWarp )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushBoolean( bWarp );

	if( pLuaArguments.Call( pLuaVM, "setElementPosition", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementRotation( lua_State* pLuaVM, void* pUserData, const Vector3& vecRotation, const char* szRotationOrder, bool bNewWay )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );
	pLuaArguments.PushString( szRotationOrder );
	pLuaArguments.PushBoolean( bNewWay );

	if( pLuaArguments.Call( pLuaVM, "setElementRotation", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementVelocity( lua_State* pLuaVM, void* pUserData, const Vector3& vecVelocity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecVelocity.fX );
	pLuaArguments.PushNumber( vecVelocity.fY );
	pLuaArguments.PushNumber( vecVelocity.fZ );

	if( pLuaArguments.Call( pLuaVM, "setElementVelocity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementVisibleTo( lua_State* pLuaVM, void* pUserData, void* pTarget, bool bVisible )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTarget );
	pLuaArguments.PushBoolean( bVisible );

	if( pLuaArguments.Call( pLuaVM, "setElementVisibleTo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementInterior( lua_State* pLuaVM, void* pUserData, int iInterior )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iInterior );

	if( pLuaArguments.Call( pLuaVM, "setElementInterior", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementDimension( lua_State* pLuaVM, void* pUserData, int iDimension )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iDimension );

	if( pLuaArguments.Call( pLuaVM, "setElementDimension", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::AttachElements( lua_State* pLuaVM, void* pUserData, void* pTarget, Vector3& vecPosition, Vector3& vecRotation )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );

	if( pLuaArguments.Call( pLuaVM, "attachElements", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::DetachElements( lua_State* pLuaVM, void* pUserData, void* pTarget )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pTarget )
	{
		pLuaArguments.PushUserData( pTarget );
	}

	if( pLuaArguments.Call( pLuaVM, "detachElements", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementAlpha( lua_State* pLuaVM, void* pUserData, int iAlpha )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAlpha );

	if( pLuaArguments.Call( pLuaVM, "setElementAlpha", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementDoubleSided( lua_State* pLuaVM, void* pUserData, bool bDoubleSided )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDoubleSided );

	if( pLuaArguments.Call( pLuaVM, "setElementDoubleSided", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementHealth( lua_State* pLuaVM, void* pUserData, float fHealth )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fHealth );

	if( pLuaArguments.Call( pLuaVM, "setElementHealth", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementModel( lua_State* pLuaVM, void* pUserData, int iModel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iModel );

	if( pLuaArguments.Call( pLuaVM, "setElementModel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementAttachedOffsets( lua_State* pLuaVM, void* pUserData, Vector3& vecPosition, Vector3& vecRotation )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );

	if( pLuaArguments.Call( pLuaVM, "setElementAttachedOffsets", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementSyncer( lua_State* pLuaVM, void* pUserData, void* pPlayer )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "setElementSyncer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementCollisionsEnabled( lua_State* pLuaVM, void* pUserData, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setElementCollisionsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementFrozen( lua_State* pLuaVM, void* pUserData, bool bFrozen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bFrozen );

	if( pLuaArguments.Call( pLuaVM, "setElementFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetLowLodElement( lua_State* pLuaVM, void* pUserData, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setLowLodElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Player get functions

unsigned int CLuaFunctionDefinitions::GetPlayerCount( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getPlayerCount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetNumber< unsigned int >();
	}

	return 0;
}

void* CLuaFunctionDefinitions::GetPlayerFromName( lua_State* pLuaVM, const char* szNick )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szNick );

	if( pLuaArguments.Call( pLuaVM, "getPlayerFromName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetPlayerPing( lua_State* pLuaVM, void* pUserData, unsigned int& uiPing )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerPing", 1 ) )
	{
		uiPing = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPlayerMoney( lua_State* pLuaVM, void* pUserData, long& lMoney )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerMoney", 1 ) )
	{
		lMoney = CLuaArgument( pLuaVM, -1 ).GetNumber< long >();

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetRandomPlayer( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRandomPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsPlayerMuted( lua_State* pLuaVM, void* pUserData, bool& bMuted )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerMuted", 1 ) )
	{
		bMuted = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetPlayerTeam( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerTeam", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetPlayerWantedLevel( lua_State* pLuaVM, void* pUserData, unsigned int& uiWantedLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerWantedLevel", 1 ) )
	{
		uiWantedLevel = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetAlivePlayers( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAlivePlayers", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetArray();
	}

	return NULL;
}

CLuaArguments* CLuaFunctionDefinitions::GetDeadPlayers( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getDeadPlayers", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetArray();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetPlayerIdleTime( lua_State* pLuaVM, void* pUserData, unsigned int& uiIdleTime )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerIdleTime", 1 ) )
	{
		uiIdleTime = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPlayerMapForced( lua_State* pLuaVM, void* pUserData, bool& bForced )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerMapForced", 1 ) )
	{
		bForced = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPlayerNametagText( lua_State* pLuaVM, void* pUserData, string& strOutText )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerNametagText", 1 ) )
	{
		strOutText = string( CLuaArgument( pLuaVM, -1 ).GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPlayerNametagColor( lua_State* pLuaVM, void* pUserData, unsigned char& ucR, unsigned char& ucG, unsigned char& ucB )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerNametagColor", 3 ) )
	{
		ucR	= CLuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		ucG	= CLuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		ucB	= CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPlayerNametagShowing( lua_State* pLuaVM, void* pUserData, bool& bShowing )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerNametagShowing", 1 ) )
	{
		bShowing = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

string CLuaFunctionDefinitions::GetPlayerSerial( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerSerial", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

string CLuaFunctionDefinitions::GetPlayerUserName( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerUserName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

bool CLuaFunctionDefinitions::GetPlayerBlurLevel( lua_State* pLuaVM, void* pUserData, unsigned char& ucLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerBlurLevel", 1 ) )
	{
		ucLevel = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPlayerName( lua_State* pLuaVM, void* pUserData, string& strOutName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerName", 1 ) )
	{
		strOutName = string( CLuaArgument( pLuaVM, -1 ).GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPlayerIP( lua_State* pLuaVM, void* pUserData, string& strOutIP )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerIP", 1 ) )
	{
		strOutIP = string( CLuaArgument( pLuaVM, -1 ).GetString() );

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetPlayerAccount( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerAccount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

string CLuaFunctionDefinitions::GetPlayerVersion( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerVersion", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

LuaTable CLuaFunctionDefinitions::GetPlayerACInfo( lua_State* pLuaVM, void* pUserData )
{
	map<string, CLuaArgument*> pLuaTable;

	CLuaArguments pLuaArguments;
	
	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getPlayerACInfo", 1 ) )
	{
		pLuaTable = CLuaArgument( pLuaVM, -1 ).GetTable();
	}
	
	return pLuaTable;
}

// Player set functions

bool CLuaFunctionDefinitions::SetPlayerMoney( lua_State* pLuaVM, void* pUserData, int iAmount, bool bInstant )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAmount );
	pLuaArguments.PushBoolean( bInstant );

	if( pLuaArguments.Call( pLuaVM, "setPlayerMoney", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GivePlayerMoney( lua_State* pLuaVM, void* pUserData, int iAmount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAmount );

	if( pLuaArguments.Call( pLuaVM, "givePlayerMoney", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::TakePlayerMoney( lua_State* pLuaVM, void* pUserData, int iAmount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iAmount );

	if( pLuaArguments.Call( pLuaVM, "takePlayerMoney", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SpawnPlayer( lua_State* pLuaVM, void* pUserData, Vector3& vecPosition, int iRotation, int iSkinID, int iInterior, int iDimension, void* pTeam )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( iRotation );
	pLuaArguments.PushNumber( iSkinID );
	pLuaArguments.PushNumber( iInterior );
	pLuaArguments.PushNumber( iDimension );

	if( pTeam )
	{
		pLuaArguments.PushUserData( pTeam );
	}

	if( pLuaArguments.Call( pLuaVM, "spawnPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ShowPlayerHudComponent( lua_State* pLuaVM, void* pUserData, string sComponent, bool bShow )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sComponent.c_str() );
	pLuaArguments.PushBoolean( bShow );

	if( pLuaArguments.Call( pLuaVM, "showPlayerHudComponent", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerWantedLevel( lua_State* pLuaVM, void* pUserData, int iLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iLevel );

	if( pLuaArguments.Call( pLuaVM, "setPlayerWantedLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ForcePlayerMap( lua_State* pLuaVM, void* pUserData, bool bForceOn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bForceOn );

	if( pLuaArguments.Call( pLuaVM, "forcePlayerMap", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerNametagText( lua_State* pLuaVM, void* pUserData, string sText )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sText.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setPlayerNametagText", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerNametagColor( lua_State* pLuaVM, void* pUserData, int iRed, int iGreen, int iBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iRed );
	pLuaArguments.PushNumber( iGreen );
	pLuaArguments.PushNumber( iBlue );

	if( pLuaArguments.Call( pLuaVM, "setPlayerNametagColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerNametagShowing( lua_State* pLuaVM, void* pUserData, bool bShowing )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bShowing );

	if( pLuaArguments.Call( pLuaVM, "setPlayerNametagShowing", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerMuted( lua_State* pLuaVM, void* pUserData, bool bMuted )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bMuted );

	if( pLuaArguments.Call( pLuaVM, "setPlayerMuted", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerBlurLevel( lua_State* pLuaVM, void* pUserData, int iLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iLevel );

	if( pLuaArguments.Call( pLuaVM, "setPlayerBlurLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RedirectPlayer( lua_State* pLuaVM, void* pUserData, const char* szServerIP, int iServerPort, const char* szServerPassword )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szServerIP );
	pLuaArguments.PushNumber( iServerPort );
	pLuaArguments.PushString( szServerPassword );

	if( pLuaArguments.Call( pLuaVM, "redirectPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerName( lua_State* pLuaVM, void* pUserData, string sName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setPlayerName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::DetonateSatchels( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "detonateSatchels", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::TakePlayerScreenShot( lua_State* pLuaVM, void* pUserData, int iWidth, int iHeight, string sTag, int iQuality, int iMaxBandwith )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iWidth );
	pLuaArguments.PushNumber( iHeight );
	pLuaArguments.PushString( sTag.c_str() );
	pLuaArguments.PushNumber( iQuality );
	pLuaArguments.PushNumber( iMaxBandwith );

	if( pLuaArguments.Call( pLuaVM, "takePlayerScreenShot", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Ped get functions

void* CLuaFunctionDefinitions::CreatePed( lua_State* pLuaVM, int iModelid, const Vector3& vecPosition, float fRot, bool bSynced )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iModelid );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( fRot );
	pLuaArguments.PushBoolean( bSynced );

	if( pLuaArguments.Call( pLuaVM, "createPed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetPedArmor( lua_State* pLuaVM, void* pUserData, float& fArmor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedArmor", 1 ) )
	{
		fArmor = CLuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedChoking( lua_State* pLuaVM, void* pUserData, bool& bIsChoking )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedChoking", 1 ) )
	{
		bIsChoking = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedDead( lua_State* pLuaVM, void* pUserData, bool& bDead )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDead", 1 ) )
	{
		bDead = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedDucked( lua_State* pLuaVM, void* pUserData, bool& bDucked )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDucked", 1 ) )
	{
		bDucked = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPedStat( lua_State* pLuaVM, void* pUserData, unsigned short usStat, float& fValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usStat );

	if( pLuaArguments.Call( pLuaVM, "getPedStat", 1 ) )
	{
		fValue = CLuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetPedTarget( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedTarget", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetPedWeapon( lua_State* pLuaVM, void* pUserData, int iWeaponSlot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iWeaponSlot );

	if( pLuaArguments.Call( pLuaVM, "getPedWeapon", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetNumber< int >();
	}

	return 0;
}

bool CLuaFunctionDefinitions::GetPedClothes( lua_State* pLuaVM, void* pUserData, unsigned char ucType, string& strOutTexture, string& strOutModel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucType );

	if( pLuaArguments.Call( pLuaVM, "getPedClothes", 2 ) )
	{
		strOutTexture	= string( ( new CLuaArgument( pLuaVM, -2 ) )->GetString() );
		strOutModel		= string( ( new CLuaArgument( pLuaVM, -1 ) )->GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::DoesPedHaveJetPack( lua_State* pLuaVM, void* pUserData, bool& bHasJetPack )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "doesPedHaveJetPack", 1 ) )
	{
		bHasJetPack = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedOnGround( lua_State* pLuaVM, void* pUserData, bool& bOnGround )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedOnGround", 1 ) )
	{
		bOnGround = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPedFightingStyle( lua_State* pLuaVM, void* pUserData, unsigned char& ucStyle )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedFightingStyle", 1 ) )
	{
		ucStyle = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPedMoveAnim( lua_State* pLuaVM, void* pUserData, unsigned int& iMoveAnim )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedMoveAnim", 1 ) )
	{
		iMoveAnim = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPedGravity( lua_State* pLuaVM, void* pUserData, float& fGravity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedGravity", 1 ) )
	{
		fGravity = CLuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetPedContactElement( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedContactElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetPedWeaponSlot( lua_State* pLuaVM, void* pUserData, unsigned char& ucWeaponSlot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedWeaponSlot", 1 ) )
	{
		ucWeaponSlot = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedDoingGangDriveby( lua_State* pLuaVM, void* pUserData, bool & bDoingGangDriveby )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDoingGangDriveby", 1 ) )
	{
		bDoingGangDriveby = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedOnFire( lua_State* pLuaVM, void* pUserData, bool & bIsOnFire )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedOnFire", 1 ) )
	{
		bIsOnFire = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedHeadless( lua_State* pLuaVM, void* pUserData, bool & bIsHeadless )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedHeadless", 1 ) )
	{
		bIsHeadless = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedFrozen( lua_State* pLuaVM, void* pUserData, bool & bIsFrozen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedFrozen", 1 ) )
	{
		bIsFrozen = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetPedOccupiedVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedOccupiedVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetPedOccupiedVehicleSeat( lua_State* pLuaVM, void* pUserData, unsigned int& uiSeat )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedOccupiedVehicleSeat", 1 ) )
	{
		uiSeat = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedInVehicle( lua_State* pLuaVM, void* pUserData, bool & bIsInVehicle )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedInVehicle", 1 ) )
	{
		bIsInVehicle = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetWeaponProperty( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short& uData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushString( szWeaponSkill );
	pLuaArguments.PushString( szProperty );

	if( pLuaArguments.Call( pLuaVM, "getWeaponProperty", 1 ) )
	{
		uData = CLuaArgument( pLuaVM, -1 ).GetNumber< short >();

		return true;
	}
	
	return false;
}

bool CLuaFunctionDefinitions::GetOriginalWeaponProperty( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short& uData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushString( szWeaponSkill );
	pLuaArguments.PushString( szProperty );

	if( pLuaArguments.Call( pLuaVM, "getOriginalWeaponProperty", 1 ) )
	{
		uData = CLuaArgument( pLuaVM, -1 ).GetNumber< short >();

		return true;
	}
	
	return false;
}

// Ped set functions

bool CLuaFunctionDefinitions::SetPedArmor( lua_State* pLuaVM, void* pUserData, float fArmor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fArmor );

	if( pLuaArguments.Call( pLuaVM, "setPedArmor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::KillPed( lua_State* pLuaVM, void* pUserData, void* pKiller, unsigned char ucKillerWeapon, unsigned char ucBodyPart, bool bStealth )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pKiller );
	pLuaArguments.PushNumber( ucKillerWeapon );
	pLuaArguments.PushNumber( ucBodyPart );
	pLuaArguments.PushBoolean( bStealth );

	if( pLuaArguments.Call( pLuaVM, "killPed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedStat( lua_State* pLuaVM, void* pUserData, unsigned short usStat, float fValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usStat );
	pLuaArguments.PushNumber( fValue );

	if( pLuaArguments.Call( pLuaVM, "setPedStat", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::AddPedClothes( lua_State* pLuaVM, void* pUserData, const char* szTexture, const char* szModel, unsigned char ucType )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szTexture );
	pLuaArguments.PushString( szModel );
	pLuaArguments.PushNumber( ucType );

	if( pLuaArguments.Call( pLuaVM, "addPedClothes", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemovePedClothes( lua_State* pLuaVM, void* pUserData, unsigned char ucType, const char* szTexture, const char* szModel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushString( szTexture );
	pLuaArguments.PushString( szModel );

	if( pLuaArguments.Call( pLuaVM, "removePedClothes", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GivePedJetPack( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "givePedJetPack", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemovePedJetPack( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "removePedJetPack", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedFightingStyle( lua_State* pLuaVM, void* pUserData, unsigned char ucStyle )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucStyle );

	if( pLuaArguments.Call( pLuaVM, "setPedFightingStyle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedMoveAnim( lua_State* pLuaVM, void* pUserData, unsigned int iMoveAnim )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iMoveAnim );

	if( pLuaArguments.Call( pLuaVM, "setPedMoveAnim", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedGravity( lua_State* pLuaVM, void* pUserData, float fGravity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fGravity );

	if( pLuaArguments.Call( pLuaVM, "setPedGravity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedChoking( lua_State* pLuaVM, void* pUserData, bool bChoking )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bChoking );

	if( pLuaArguments.Call( pLuaVM, "setPedChoking", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedWeaponSlot( lua_State* pLuaVM, void* pUserData, unsigned char ucWeaponSlot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucWeaponSlot );

	if( pLuaArguments.Call( pLuaVM, "setPedWeaponSlot", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::WarpPedIntoVehicle( lua_State* pLuaVM, void* pUserData, void* pVehicle, unsigned int uiSeat )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pVehicle );
	pLuaArguments.PushNumber( uiSeat );

	if( pLuaArguments.Call( pLuaVM, "warpPedIntoVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemovePedFromVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "removePedFromVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedDoingGangDriveby( lua_State* pLuaVM, void* pUserData, bool bGangDriveby )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bGangDriveby );

	if( pLuaArguments.Call( pLuaVM, "setPedDoingGangDriveby", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedAnimation( lua_State* pLuaVM, void* pUserData, const char * szBlockName, const char * szAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szBlockName );
	pLuaArguments.PushString( szAnimName );
	pLuaArguments.PushNumber( iTime );
	pLuaArguments.PushBoolean( bLoop );
	pLuaArguments.PushBoolean( bUpdatePosition );
	pLuaArguments.PushBoolean( bInterruptable );
	pLuaArguments.PushBoolean( bFreezeLastFrame );

	if( pLuaArguments.Call( pLuaVM, "setPedAnimation", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedAnimationProgress( lua_State* pLuaVM, void* pUserData, const char * szAnimName, float fProgress )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szAnimName );
	pLuaArguments.PushNumber( fProgress );

	if( pLuaArguments.Call( pLuaVM, "setPedAnimationProgress", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedOnFire( lua_State* pLuaVM, void* pUserData, bool bIsOnFire )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bIsOnFire );

	if( pLuaArguments.Call( pLuaVM, "setPedOnFire", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedHeadless( lua_State* pLuaVM, void* pUserData, bool bIsHeadless )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bIsHeadless );

	if( pLuaArguments.Call( pLuaVM, "setPedHeadless", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedFrozen( lua_State* pLuaVM, void* pUserData, bool bIsFrozen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bIsFrozen );

	if( pLuaArguments.Call( pLuaVM, "setPedFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ReloadPedWeapon( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "reloadPedWeapon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWeaponProperty( lua_State* pLuaVM, unsigned char ucWeaponID, const char* szWeaponSkill, const char* szProperty, short uData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushString( szWeaponSkill );
	pLuaArguments.PushString( szProperty );
	pLuaArguments.PushNumber( uData );

	if( pLuaArguments.Call( pLuaVM, "setWeaponProperty", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetBoolean();
	}
	
	return false;
}

// Vehicle create/destroy functions

void* CLuaFunctionDefinitions::CreateVehicle( lua_State* pLuaVM, int model, float fX, float fY, float fZ, float fRX, float fRY, float fRZ, string numberplate, bool direction, int variant1, int variant2 )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( model );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

	if( numberplate.length() > 0 )
	{
		pLuaArguments.PushString( numberplate.c_str() );
		pLuaArguments.PushBoolean( direction );
		pLuaArguments.PushNumber( variant1 );
		pLuaArguments.PushNumber( variant2 );
	}

	if( pLuaArguments.Call( pLuaVM, "createVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Vehicle get functions

bool CLuaFunctionDefinitions::GetVehicleType( lua_State* pLuaVM, void* pUserData, string& strType )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleType", 1 ) )
	{
		strType = string( CLuaArgument( pLuaVM, -1 ).GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleVariant( lua_State* pLuaVM, void* pUserData, unsigned char& ucVariant, unsigned char& ucVariant2 )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleVariant", 2 ) )
	{
		ucVariant	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucVariant2	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleColor( lua_State* pLuaVM, void* pUserData, CVehicleColor& color )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( true );

	if( pLuaArguments.Call( pLuaVM, "getVehicleColor", 12 ) )
	{
		SColor
			color1, color2, color3, color4;

		color1.R = CLuaArgument( pLuaVM, -12 ).GetNumber< unsigned char >();
		color1.G = CLuaArgument( pLuaVM, -11 ).GetNumber< unsigned char >();
		color1.B = CLuaArgument( pLuaVM, -10 ).GetNumber< unsigned char >();

		color2.R = CLuaArgument( pLuaVM, -9 ).GetNumber< unsigned char >();
		color2.G = CLuaArgument( pLuaVM, -8 ).GetNumber< unsigned char >();
		color2.B = CLuaArgument( pLuaVM, -7 ).GetNumber< unsigned char >();

		color3.R = CLuaArgument( pLuaVM, -6 ).GetNumber< unsigned char >();
		color3.G = CLuaArgument( pLuaVM, -5 ).GetNumber< unsigned char >();
		color3.B = CLuaArgument( pLuaVM, -4 ).GetNumber< unsigned char >();

		color4.R = CLuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		color4.G = CLuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		color4.B = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		color.SetRGBColors( color1, color2, color3, color4 );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleModelFromName( lua_State* pLuaVM, const char* szName, unsigned short& usID )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );

	if( pLuaArguments.Call( pLuaVM, "getVehicleModelFromName", 1 ) )
	{
		usID = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned short >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleLandingGearDown( lua_State* pLuaVM, void* pUserData, bool& bGearDown )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleLandingGearDown", 1 ) )
	{
		bGearDown = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleMaxPassengers( lua_State* pLuaVM, void* pUserData, unsigned char& ucMaxPassengers )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleMaxPassengers", 1 ) )
	{
		ucMaxPassengers = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleName( lua_State* pLuaVM, void* pUserData, string& strOutName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleName", 1 ) )
	{
		strOutName = string( CLuaArgument( pLuaVM, -1 ).GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleNameFromModel( lua_State* pLuaVM, unsigned short usModel, string& strOutName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usModel );

	if( pLuaArguments.Call( pLuaVM, "getVehicleNameFromModel", 1 ) )
	{
		strOutName = string( CLuaArgument( pLuaVM, -1 ).GetString() );

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetVehicleOccupant( lua_State* pLuaVM, void* pUserData, unsigned int uiSeat )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( uiSeat );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOccupant", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehicleOccupants( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOccupants", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetArray();
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetVehicleController( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleController", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetVehicleSirensOn( lua_State* pLuaVM, void* pUserData, bool& bSirensOn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleSirensOn", 1 ) )
	{
		bSirensOn = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleTurnVelocity( lua_State* pLuaVM, void* pUserData, Vector3& vecTurnVelocity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTurnVelocity", 3 ) )
	{
		vecTurnVelocity.fX = CLuaArgument( pLuaVM, -3 ).GetNumber< float >();
		vecTurnVelocity.fY = CLuaArgument( pLuaVM, -2 ).GetNumber< float >();
		vecTurnVelocity.fZ = CLuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleTurretPosition( lua_State* pLuaVM, void* pUserData, Vector2& vecPosition )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTurretPosition", 2 ) )
	{
		vecPosition.fX = CLuaArgument( pLuaVM, -2 ).GetNumber< float >();
		vecPosition.fY = CLuaArgument( pLuaVM, -1 ).GetNumber< float >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleLocked( lua_State* pLuaVM, void* pUserData, bool& bLocked )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleLocked", 1 ) )
	{
		bLocked = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehiclesOfType( lua_State* pLuaVM, unsigned int uiModel )
{
	CLuaArguments* pLuaArguments = new CLuaArguments();

	pLuaArguments->PushNumber( uiModel );

	if( pLuaArguments->Call( pLuaVM, "getVehiclesOfType", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetArray();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetVehicleUpgradeOnSlot( lua_State* pLuaVM, void* pUserData, unsigned char ucSlot, unsigned short& usUpgrade )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSlot );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeOnSlot", 1 ) )
	{
		usUpgrade = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned short >();

		return true;
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehicleUpgrades( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgrades", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetArray();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetVehicleUpgradeSlotName( lua_State* pLuaVM, unsigned char ucSlot, string& strOutName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucSlot );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeSlotName", 1 ) )
	{
		strOutName = string( CLuaArgument( pLuaVM, -1 ).GetString() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleUpgradeSlotName( lua_State* pLuaVM, unsigned short usUpgrade, string& strOutName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeSlotName", 1 ) )
	{
		strOutName = string( CLuaArgument( pLuaVM, -1 ).GetString() );
		
		return true;
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehicleCompatibleUpgrades( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleCompatibleUpgrades", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetArray();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetVehicleDoorState( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor, unsigned char& ucState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );

	if( pLuaArguments.Call( pLuaVM, "getVehicleDoorState", 1 ) )
	{
		ucState = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleWheelStates( lua_State* pLuaVM, void* pUserData, unsigned char& ucFrontLeft, unsigned char& ucRearLeft, unsigned char& ucFrontRight, unsigned char& ucRearRight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleWheelStates", 4 ) )
	{
		ucFrontLeft		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		ucRearLeft		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucFrontRight	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucRearRight		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleLightState( lua_State* pLuaVM, void* pUserData, unsigned char ucLight, unsigned char& ucState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLight );

	if( pLuaArguments.Call( pLuaVM, "getVehicleLightState", 1 ) )
	{
		ucState = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehiclePanelState( lua_State* pLuaVM, void* pUserData, unsigned char ucPanel, unsigned char& ucState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPanel );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePanelState", 1 ) )
	{
		ucState = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleOverrideLights( lua_State* pLuaVM, void* pUserData, unsigned char& ucLights )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOverrideLights", 1 ) )
	{
		ucLights = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetVehicleTowedByVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTowedByVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetVehicleTowingVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTowingVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetVehiclePaintjob( lua_State* pLuaVM, void* pUserData, unsigned char& ucPaintjob )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePaintjob", 1 ) )
	{
		ucPaintjob = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehiclePlateText( lua_State* pLuaVM, void* pUserData, char* szPlateText )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePlateText", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szPlateText, pLuaArgument.GetString(), 8 );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleDamageProof( lua_State* pLuaVM, void* pUserData, bool& bDamageProof )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleDamageProof", 1 ) )
	{
		bDamageProof = CLuaArgument( pLuaVM, -1 ).GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleFuelTankExplodable( lua_State* pLuaVM, void* pUserData, bool& bExplodable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleFuelTankExplodable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bExplodable = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleFrozen( lua_State* pLuaVM, void* pUserData, bool& bFrozen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bFrozen = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleOnGround( lua_State* pLuaVM, void* pUserData, bool& bOnGround )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleOnGround", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bOnGround = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleEngineState( lua_State* pLuaVM, void* pUserData, bool& bState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleEngineState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bState = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsTrainDerailed( lua_State* pLuaVM, void* pUserData, bool& bDerailed )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isTrainDerailed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bDerailed = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsTrainDerailable( lua_State* pLuaVM, void* pUserData, bool& bDerailable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isTrainDerailable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bDerailable = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTrainDirection( lua_State* pLuaVM, void* pUserData, bool& bDirection )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getTrainDirection", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bDirection = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTrainSpeed( lua_State* pLuaVM, void* pUserData, float& fSpeed )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getTrainSpeed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fSpeed = pLuaArgument.GetNumber< float >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleBlown( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleBlown", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleHeadLightColor( lua_State* pLuaVM, void* pUserData, SColor& outColor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleHeadLightColor", 3 ) )
	{
		outColor.R = CLuaArgument( pLuaVM, -3 ).GetNumber< unsigned char >();
		outColor.G = CLuaArgument( pLuaVM, -2 ).GetNumber< unsigned char >();
		outColor.B = CLuaArgument( pLuaVM, -1 ).GetNumber< unsigned char >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleDoorOpenRatio( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor, float& fRatio )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );

	if( pLuaArguments.Call( pLuaVM, "getVehicleDoorOpenRatio", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fRatio = pLuaArgument.GetNumber< float >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleTaxiLightOn( lua_State* pLuaVM, void* pUserData, bool& bLightOn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleTaxiLightOn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bLightOn = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

// Vehicle set functions

bool CLuaFunctionDefinitions::FixVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "fixVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::BlowVehicle( lua_State* pLuaVM, void* pUserData, bool bExplode )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bExplode );

	if( pLuaArguments.Call( pLuaVM, "blowVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleTurnVelocity( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );

	if( pLuaArguments.Call( pLuaVM, "setVehicleTurnVelocity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleColor( lua_State* pLuaVM, void* pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, unsigned char ucRed2, unsigned char ucGreen2, unsigned char ucBlue2, unsigned char ucRed3, unsigned char ucGreen3, unsigned char ucBlue3, unsigned char ucRed4, unsigned char ucGreen4, unsigned char ucBlue4 )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	pLuaArguments.PushNumber( ucRed2 );
	pLuaArguments.PushNumber( ucGreen2 );
	pLuaArguments.PushNumber( ucBlue2 );

	pLuaArguments.PushNumber( ucRed3 );
	pLuaArguments.PushNumber( ucGreen3 );
	pLuaArguments.PushNumber( ucBlue3 );

	pLuaArguments.PushNumber( ucRed4 );
	pLuaArguments.PushNumber( ucGreen4 );
	pLuaArguments.PushNumber( ucBlue4 );

	if( pLuaArguments.Call( pLuaVM, "setVehicleColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleLandingGearDown( lua_State* pLuaVM, void* pUserData, bool bLandingGearDown )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bLandingGearDown );

	if( pLuaArguments.Call( pLuaVM, "setVehicleLandingGearDown", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleLocked( lua_State* pLuaVM, void* pUserData, bool bLocked )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bLocked );

	if( pLuaArguments.Call( pLuaVM, "setVehicleLocked", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleDoorsUndamageable( lua_State* pLuaVM, void* pUserData, bool bDoorsUndamageable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDoorsUndamageable );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDoorsUndamageable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleSirensOn( lua_State* pLuaVM, void* pUserData, bool bSirensOn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bSirensOn );

	if( pLuaArguments.Call( pLuaVM, "setVehicleSirensOn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleTaxiLightOn( lua_State* pLuaVM, void* pUserData, bool bTaxiLightState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bTaxiLightState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleTaxiLightOn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::AddVehicleUpgrade( lua_State* pLuaVM, void* pUserData, unsigned short usUpgrade )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "addVehicleUpgrade", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveVehicleUpgrade( lua_State* pLuaVM, void* pUserData, unsigned short usUpgrade )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "removeVehicleUpgrade", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleDoorState( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor, unsigned char ucState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );
	pLuaArguments.PushNumber( ucState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDoorState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleWheelStates( lua_State* pLuaVM, void* pUserData, int iFrontLeft, int iRearLeft, int iFrontRight, int iRearRight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iFrontLeft );
	pLuaArguments.PushNumber( iRearLeft );
	pLuaArguments.PushNumber( iFrontRight );
	pLuaArguments.PushNumber( iRearRight );

	if( pLuaArguments.Call( pLuaVM, "setVehicleWheelStates", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleLightState( lua_State* pLuaVM, void* pUserData, unsigned char ucLight, unsigned char ucState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLight );
	pLuaArguments.PushNumber( ucState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleLightState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehiclePanelState( lua_State* pLuaVM, void* pUserData, unsigned char ucPanel, unsigned char ucState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPanel );
	pLuaArguments.PushNumber( ucState );

	if( pLuaArguments.Call( pLuaVM, "setVehiclePanelState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleIdleRespawnDelay( lua_State* pLuaVM, void* pUserData, unsigned long ulTime )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulTime );

	if( pLuaArguments.Call( pLuaVM, "setVehicleIdleRespawnDelay", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleRespawnDelay( lua_State* pLuaVM, void* pUserData, unsigned long ulTime )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulTime );

	if( pLuaArguments.Call( pLuaVM, "setVehicleRespawnDelay", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleRespawnPosition( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

	if( pLuaArguments.Call( pLuaVM, "setVehicleRespawnPosition", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ToggleVehicleRespawn( lua_State* pLuaVM, void* pUserData, bool bRespawn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( bRespawn );

	if( pLuaArguments.Call( pLuaVM, "toggleVehicleRespawn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetVehicleExplosionTime( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "resetVehicleExplosionTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetVehicleIdleTime( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "resetVehicleIdleTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SpawnVehicle( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

	if( pLuaArguments.Call( pLuaVM, "spawnVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RespawnVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "respawnVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleOverrideLights( lua_State* pLuaVM, void* pUserData, unsigned char ucLights )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLights );

	if( pLuaArguments.Call( pLuaVM, "setVehicleOverrideLights", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::AttachTrailerToVehicle( lua_State* pLuaVM, void* pUserData, void* pTrailer )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTrailer );

	if( pLuaArguments.Call( pLuaVM, "attachTrailerToVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::DetachTrailerFromVehicle( lua_State* pLuaVM, void* pUserData, void* pTrailer )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pTrailer )
	{
		pLuaArguments.PushUserData( pTrailer );
	}

	if( pLuaArguments.Call( pLuaVM, "detachTrailerFromVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleEngineState( lua_State* pLuaVM, void* pUserData, bool bState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bState );

	if( pLuaArguments.Call( pLuaVM, "setVehicleEngineState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleDirtLevel( lua_State* pLuaVM, void* pUserData, float fDirtLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fDirtLevel );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDirtLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleDamageProof( lua_State* pLuaVM, void* pUserData, bool bDamageProof )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDamageProof );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDamageProof", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehiclePaintjob( lua_State* pLuaVM, void* pUserData, unsigned char ucPaintjob )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPaintjob );

	if( pLuaArguments.Call( pLuaVM, "setVehiclePaintjob", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleFuelTankExplodable( lua_State* pLuaVM, void* pUserData, bool bExplodable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bExplodable );

	if( pLuaArguments.Call( pLuaVM, "setVehicleFuelTankExplodable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleFrozen( lua_State* pLuaVM, void* pUserData, bool bFrozen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bFrozen );

	if( pLuaArguments.Call( pLuaVM, "setVehicleFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTrainDerailed( lua_State* pLuaVM, void* pUserData, bool bDerailed )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDerailed );

	if( pLuaArguments.Call( pLuaVM, "setTrainDerailed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTrainDerailable( lua_State* pLuaVM, void* pUserData, bool bDerailable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDerailable );

	if( pLuaArguments.Call( pLuaVM, "setTrainDerailable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTrainDirection( lua_State* pLuaVM, void* pUserData, bool bDireciton )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bDireciton );

	if( pLuaArguments.Call( pLuaVM, "setTrainDirection", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTrainSpeed( lua_State* pLuaVM, void* pUserData, float fSpeed )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fSpeed );

	if( pLuaArguments.Call( pLuaVM, "setTrainDirection", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleHeadLightColor( lua_State* pLuaVM, void* pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "setVehicleHeadLightColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleTurretPosition( lua_State* pLuaVM, void* pUserData, float fHorizontal, float fVertical )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fHorizontal );
	pLuaArguments.PushNumber( fVertical );

	if( pLuaArguments.Call( pLuaVM, "setVehicleTurretPosition", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleDoorOpenRatio( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor, float fRatio, unsigned long ulTime )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );
	pLuaArguments.PushNumber( fRatio );
	pLuaArguments.PushNumber( ulTime );

	if( pLuaArguments.Call( pLuaVM, "setVehicleDoorOpenRatio", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleVariant( lua_State* pLuaVM, void* pUserData, unsigned char ucVariant, unsigned char ucVariant2 )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucVariant );
	pLuaArguments.PushNumber( ucVariant2 );

	if( pLuaArguments.Call( pLuaVM, "setVehicleVariant", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GiveVehicleSirens( lua_State* pLuaVM, void* pUserData, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360, bool bCheckLosFlag, bool bUseRandomiserFlag, bool bSilentFlag )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSirenType );
	pLuaArguments.PushNumber( ucSirenCount );
	pLuaArguments.PushBoolean( bFlag360 );
	pLuaArguments.PushBoolean( bCheckLosFlag );
	pLuaArguments.PushBoolean( bUseRandomiserFlag );
	pLuaArguments.PushBoolean( bSilentFlag );

	if( pLuaArguments.Call( pLuaVM, "addVehicleSirens", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveVehicleSirens( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "removeVehicleSirens", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehicleSirens( lua_State* pLuaVM, void* pUserData, unsigned char ucSirenID, float fX, float fY, float fZ, float fRed, float fGreen, float fBlue, float fAlpha, float fMinAlpha )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSirenID );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRed );
	pLuaArguments.PushNumber( fGreen );
	pLuaArguments.PushNumber( fBlue );
	pLuaArguments.PushNumber( fAlpha );
	pLuaArguments.PushNumber( fMinAlpha );

	if( pLuaArguments.Call( pLuaVM, "setVehicleSirens", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetVehiclePlateText( lua_State* pLuaVM, void* pUserData, const char* szName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szName );

	if( pLuaArguments.Call( pLuaVM, "setVehiclePlateText", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Marker create/destroy functions

void* CLuaFunctionDefinitions::CreateMarker( lua_State* pLuaVM, const Vector3& vecPosition, const char* szType, float fSize, const SColor color, void* pVisibleTo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushString( szType );
	pLuaArguments.PushNumber( fSize );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );
	pLuaArguments.PushUserData( pVisibleTo );

	if( pLuaArguments.Call( pLuaVM, "createMarker", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Marker get functions

bool CLuaFunctionDefinitions::GetMarkerCount( lua_State* pLuaVM, unsigned int& uiCount )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMarkerCount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		uiCount = static_cast< unsigned int >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMarkerType( lua_State* pLuaVM, void* pUserData, char* szType )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szType, pLuaArgument.GetString(), strlen( szType ) );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMarkerSize( lua_State* pLuaVM, void* pUserData, float& fSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fSize = static_cast< float >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMarkerColor( lua_State* pLuaVM, void* pUserData, SColor& outColor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerColor", 4 ) )
	{
		outColor.R	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		outColor.G	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		outColor.B	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		outColor.A	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMarkerTarget( lua_State* pLuaVM, void* pUserData, Vector3& vecTarget )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerTarget", 3 ) )
	{
		vecTarget.fX	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecTarget.fY	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecTarget.fZ	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMarkerIcon( lua_State* pLuaVM, void* pUserData, char* szIcon )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerIcon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szIcon, pLuaArgument.GetString(), strlen( szIcon ) );

		return true;
	}

	return false;
}

// Marker set functions

bool CLuaFunctionDefinitions::SetMarkerType( lua_State* pLuaVM, void* pUserData, const char* szType )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szType );

	if( pLuaArguments.Call( pLuaVM, "setMarkerType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMarkerSize( lua_State* pLuaVM, void* pUserData, float fSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fSize );

	if( pLuaArguments.Call( pLuaVM, "setMarkerSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMarkerColor( lua_State* pLuaVM, void* pUserData, const SColor color )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pLuaArguments.Call( pLuaVM, "setMarkerColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMarkerTarget( lua_State* pLuaVM, void* pUserData, const Vector3& pTarget )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( pTarget.fX );
	pLuaArguments.PushNumber( pTarget.fY );
	pLuaArguments.PushNumber( pTarget.fZ );

	if( pLuaArguments.Call( pLuaVM, "setMarkerTarget", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMarkerIcon( lua_State* pLuaVM, void* pUserData, const char* szIcon )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( szIcon );

	if( pLuaArguments.Call( pLuaVM, "setMarkerIcon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Blip create/destroy functions

void* CLuaFunctionDefinitions::CreateBlip( lua_State* pLuaVM, const Vector3& vecPosition, unsigned char ucIcon, unsigned char ucSize, const SColor color, short sOrdering, unsigned short usVisibleDistance, void* pVisibleTo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( ucIcon );
	pLuaArguments.PushNumber( ucSize );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );
	pLuaArguments.PushNumber( sOrdering );
	pLuaArguments.PushNumber( usVisibleDistance );

	if( pVisibleTo )
	{
		pLuaArguments.PushUserData( pVisibleTo );
	}

	if( pLuaArguments.Call( pLuaVM, "createBlip", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CreateBlipAttachedTo( lua_State* pLuaVM, void* pTarget, unsigned char ucIcon, unsigned char ucSize, const SColor color, short sOrdering, unsigned short usVisibleDistance, void* pVisibleTo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTarget );
	pLuaArguments.PushNumber( ucIcon );
	pLuaArguments.PushNumber( ucSize );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );
	pLuaArguments.PushNumber( sOrdering );
	pLuaArguments.PushNumber( usVisibleDistance );

	if( pVisibleTo )
	{
		pLuaArguments.PushUserData( pVisibleTo );
	}

	if( pLuaArguments.Call( pLuaVM, "createBlip", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Blip get functions

bool CLuaFunctionDefinitions::GetBlipIcon( lua_State* pLuaVM, void* pUserData, unsigned char& ucIcon )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipIcon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucIcon = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBlipSize( lua_State* pLuaVM, void* pUserData, unsigned char& ucSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucSize = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBlipColor( lua_State* pLuaVM, void* pUserData, SColor& outColor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipColor", 4 ) )
	{
		outColor.R	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		outColor.G	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		outColor.B	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		outColor.A	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBlipOrdering( lua_State* pLuaVM, void* pUserData, short& sOrdering )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipOrdering", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		sOrdering = static_cast< short >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBlipVisibleDistance( lua_State* pLuaVM, void* pUserData, unsigned short& usVisibleDistance )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getBlipVisibleDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		usVisibleDistance = static_cast< unsigned short >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

// Blip set functions

bool CLuaFunctionDefinitions::SetBlipIcon( lua_State* pLuaVM, void* pUserData, unsigned char ucIcon )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucIcon );

	if( pLuaArguments.Call( pLuaVM, "setBlipIcon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetBlipSize( lua_State* pLuaVM, void* pUserData, unsigned char ucSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSize );

	if( pLuaArguments.Call( pLuaVM, "setBlipSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetBlipColor( lua_State* pLuaVM, void* pUserData, const SColor color )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pLuaArguments.Call( pLuaVM, "setBlipColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetBlipOrdering( lua_State* pLuaVM, void* pUserData, short sOrdering )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( sOrdering );

	if( pLuaArguments.Call( pLuaVM, "setBlipOrdering", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetBlipVisibleDistance( lua_State* pLuaVM, void* pUserData, unsigned short usVisibleDistance )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usVisibleDistance );

	if( pLuaArguments.Call( pLuaVM, "setBlipVisibleDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Object create/destroy functions

void* CLuaFunctionDefinitions::CreateObject( lua_State* pLuaVM, unsigned short usModelID, const Vector3& vecPosition, const Vector3& vecRotation, bool bIsLowLod )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );

	pLuaArguments.PushBoolean( bIsLowLod );

	if( pLuaArguments.Call( pLuaVM, "createObject", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Object get functions

bool CLuaFunctionDefinitions::GetObjectScale( lua_State* pLuaVM, void* pUserData, Vector3& vecScale )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getObjectScale", 3 ) )
	{
		vecScale.fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecScale.fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecScale.fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

// Object set functions

bool CLuaFunctionDefinitions::SetObjectScale( lua_State* pLuaVM, void* pUserData, const Vector3& vecScale )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	pLuaArguments.PushNumber( vecScale.fX );
	pLuaArguments.PushNumber( vecScale.fY );
	pLuaArguments.PushNumber( vecScale.fZ );

	if( pLuaArguments.Call( pLuaVM, "setObjectScale", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::MoveObject( lua_State* pLuaVM, void* pUserData, unsigned long ulTime, const Vector3& vecPosition, const Vector3& vecRotation, const char* szEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulTime );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( vecRotation.fX );
	pLuaArguments.PushNumber( vecRotation.fY );
	pLuaArguments.PushNumber( vecRotation.fZ );
	pLuaArguments.PushString( szEasingType );
	pLuaArguments.PushNumber( fEasingPeriod );
	pLuaArguments.PushNumber( fEasingAmplitude );
	pLuaArguments.PushNumber( fEasingOvershoot );

	if( pLuaArguments.Call( pLuaVM, "moveObject", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::StopObject( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "stopObject", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Radar area create/destroy funcs

void* CLuaFunctionDefinitions::CreateRadarArea( lua_State* pLuaVM, const Vector2& vecPosition, const Vector2& vecSize, const SColor color, void* pVisibleTo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );

	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );

	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pVisibleTo )
	{
		pLuaArguments.PushUserData( pVisibleTo );
	}

	if( pLuaArguments.Call( pLuaVM, "createRadarArea", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Radar area get funcs

bool CLuaFunctionDefinitions::GetRadarAreaSize( lua_State* pLuaVM, void* pUserData, Vector2& vecSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getRadarAreaSize", 2 ) )
	{
		vecSize.fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecSize.fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetRadarAreaColor( lua_State* pLuaVM, void* pUserData, SColor& outColor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getRadarAreaColor", 4 ) )
	{
		outColor.R	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		outColor.G	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		outColor.B	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		outColor.A	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsRadarAreaFlashing( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isRadarAreaFlashing", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsInsideRadarArea( lua_State* pLuaVM, void* pUserData, const Vector2& vecPosition, bool& bInside )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isInsideRadarArea", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Radar area set funcs

bool CLuaFunctionDefinitions::SetRadarAreaSize( lua_State* pLuaVM, void* pUserData, const Vector2& vecSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );

	if( pLuaArguments.Call( pLuaVM, "setRadarAreaSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetRadarAreaColor( lua_State* pLuaVM, void* pUserData, const SColor color )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( color.R );
	pLuaArguments.PushNumber( color.G );
	pLuaArguments.PushNumber( color.B );
	pLuaArguments.PushNumber( color.A );

	if( pLuaArguments.Call( pLuaVM, "setRadarAreaColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetRadarAreaFlashing( lua_State* pLuaVM, void* pUserData, bool bFlashing )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( bFlashing );

	if( pLuaArguments.Call( pLuaVM, "setRadarAreaFlashing", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Pickup create/destroy funcs

void* CLuaFunctionDefinitions::CreatePickup( lua_State* pLuaVM, const Vector3& vecPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval, double dSix )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushNumber( dFive );

	pLuaArguments.PushNumber( ulRespawnInterval );
	pLuaArguments.PushNumber( dSix );

	if( pLuaArguments.Call( pLuaVM, "createPickup", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Pickup get funcs

bool CLuaFunctionDefinitions::GetPickupType( lua_State* pLuaVM, void* pUserData, unsigned char& ucType )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucType = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPickupWeapon( lua_State* pLuaVM, void* pUserData, unsigned char& ucWeapon )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupWeapon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucWeapon = static_cast< unsigned char >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPickupAmount( lua_State* pLuaVM, void* pUserData, float& fAmount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupAmount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fAmount = static_cast< float >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPickupAmmo( lua_State* pLuaVM, void* pUserData, unsigned short& ucAmmo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupAmmo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucAmmo = static_cast< unsigned short >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetPickupRespawnInterval( lua_State* pLuaVM, void* pUserData, unsigned long& ulInterval )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPickupRespawnInterval", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ulInterval = static_cast< unsigned long >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPickupSpawned( lua_State* pLuaVM, void* pUserData, bool& bSpawned )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPickupSpawned", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bSpawned = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

// Pickup set funcs

bool CLuaFunctionDefinitions::SetPickupType( lua_State* pLuaVM, void* pUserData, unsigned char ucType, double dThree, double dFour )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushNumber( dThree );
	pLuaArguments.PushNumber( dFour );

	if( pLuaArguments.Call( pLuaVM, "setPickupType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPickupRespawnInterval( lua_State* pLuaVM, void* pUserData, unsigned long ulInterval )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ulInterval );

	if( pLuaArguments.Call( pLuaVM, "setPickupRespawnInterval", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::UsePickup( lua_State* pLuaVM, void* pUserData, void* pPlayer )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "usePickup", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Shape create funcs

void* CLuaFunctionDefinitions::CreateColCircle( lua_State* pLuaVM, const Vector2& vecPosition, float fRadius )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( fRadius );

	if( pLuaArguments.Call( pLuaVM, "createColCircle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CreateColCuboid( lua_State* pLuaVM, const Vector3& vecPosition, const Vector3& vecSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );
	pLuaArguments.PushNumber( vecSize.fZ );

	if( pLuaArguments.Call( pLuaVM, "createColCuboid", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CreateColSphere( lua_State* pLuaVM, const Vector3& vecPosition, float fRadius )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( fRadius );

	if( pLuaArguments.Call( pLuaVM, "createColSphere", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CreateColRectangle( lua_State* pLuaVM, const Vector2& vecPosition, const Vector2& vecSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );

	pLuaArguments.PushNumber( vecSize.fX );
	pLuaArguments.PushNumber( vecSize.fY );

	if( pLuaArguments.Call( pLuaVM, "createColRectangle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CreateColPolygon( lua_State* pLuaVM, const vector< Vector2 >& vecPointList )
{
	if( vecPointList.size() < 4 )
	{
		return NULL;
	}

	CLuaArguments pLuaArguments;

	for( unsigned int i = 0; i < vecPointList.size(); i++ )
    {
        pLuaArguments.PushNumber( vecPointList[ i ].fX );
        pLuaArguments.PushNumber( vecPointList[ i ].fY );
    }

	if( pLuaArguments.Call( pLuaVM, "createColRectangle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CreateColTube( lua_State* pLuaVM, const Vector3& vecPosition, float fRadius, float fHeight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( fRadius );
	pLuaArguments.PushNumber( fHeight );

	if( pLuaArguments.Call( pLuaVM, "createColTube", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

// Explosion funcs

bool CLuaFunctionDefinitions::CreateExplosion( lua_State* pLuaVM, const Vector3& vecPosition, unsigned char ucType, void* pCreator )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( ucType );

	if( pCreator )
	{
		pLuaArguments.PushUserData( pCreator );
	}

	if( pLuaArguments.Call( pLuaVM, "createExplosion", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Audio funcs

bool CLuaFunctionDefinitions::PlaySoundFrontEnd( lua_State* pLuaVM, void* pElement, unsigned char ucSound )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucSound );

	if( pLuaArguments.Call( pLuaVM, "playSoundFrontEnd", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::PlayMissionAudio( lua_State* pLuaVM, void* pElement, Vector3& vecPosition, unsigned short usSlot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	pLuaArguments.PushNumber( usSlot );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	if( pLuaArguments.Call( pLuaVM, "playMissionAudio", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Ped body?

bool CLuaFunctionDefinitions::GetBodyPartName( lua_State* pLuaVM, unsigned char ucID, char* szName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucID );

	if( pLuaArguments.Call( pLuaVM, "getBodyPartName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szName, pLuaArgument.GetString(), strlen( pLuaArgument.GetString() ) );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetClothesByTypeIndex( lua_State* pLuaVM, unsigned char ucType, unsigned char ucIndex, char* szTextureReturn, char* szModelReturn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucType );
	pLuaArguments.PushNumber( ucIndex );

	if( pLuaArguments.Call( pLuaVM, "getClothesByTypeIndex", 2 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -2 );

		strncpy( szTextureReturn, pLuaArgument.GetString(), strlen( pLuaArgument.GetString() ) );

		CLuaArgument pLuaArgument2( pLuaVM, -1 );

		strncpy( szModelReturn, pLuaArgument2.GetString(), strlen( pLuaArgument2.GetString() ) );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTypeIndexFromClothes( lua_State* pLuaVM, const char* szTexture, const char* szModel, unsigned char& ucTypeReturn, unsigned char& ucIndexReturn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szTexture );
	pLuaArguments.PushString( szModel );

	if( pLuaArguments.Call( pLuaVM, "getTypeIndexFromClothes", 2 ) )
	{
		ucTypeReturn	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucIndexReturn	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetClothesTypeName( lua_State* pLuaVM, unsigned char ucType, char* szNameReturn )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucType );

	if( pLuaArguments.Call( pLuaVM, "getClothesTypeName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strncpy( szNameReturn, pLuaArgument.GetString(), strlen( pLuaArgument.GetString() ) );

		return true;
	}

	return false;
}

// Input funcs

bool CLuaFunctionDefinitions::BindKey( lua_State* pLuaVM, void* pPlayer, const char* szKey, const char* szHitState, const char* szCommandName, const char* szArguments )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szHitState );
	pLuaArguments.PushString( szCommandName );

	if( szArguments )
	{
		pLuaArguments.PushString( szArguments );
	}

	if( pLuaArguments.Call( pLuaVM, "bindKey", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::UnbindKey( lua_State* pLuaVM, void* pPlayer, const char* szKey, const char* szHitState, const char* szCommandName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushString( szHitState );
	pLuaArguments.PushString( szCommandName );

	if( pLuaArguments.Call( pLuaVM, "unbindKey", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetControlState( lua_State* pLuaVM, void* pPlayer, const char* szControl, bool& bState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );

	if( pLuaArguments.Call( pLuaVM, "getControlState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bState = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsControlEnabled( lua_State* pLuaVM, void* pPlayer, const char* szControl, bool& bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );

	if( pLuaArguments.Call( pLuaVM, "isControlEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bEnabled = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::SetControlState( lua_State* pLuaVM, void* pPlayer, const char* szControl, bool bState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );
	pLuaArguments.PushBoolean( bState );

	if( pLuaArguments.Call( pLuaVM, "setControlState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ToggleControl( lua_State* pLuaVM, void* pPlayer, const char* szControl, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( szControl );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "toggleControl", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ToggleAllControls( lua_State* pLuaVM, void* pPlayer, bool bGTAControls, bool bMTAControls, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushBoolean( bGTAControls );
	pLuaArguments.PushBoolean( bMTAControls );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "toggleAllControls", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Team get funcs

void* CLuaFunctionDefinitions::CreateTeam( lua_State* pLuaVM, const char* szTeamName, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szTeamName );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "createTeam", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetTeamFromName( lua_State* pLuaVM, const char* szTeamName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szTeamName );

	if( pLuaArguments.Call( pLuaVM, "getTeamFromName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetTeamName( lua_State* pLuaVM, void* pTeam, string& strOutName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "getTeamName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutName = pLuaArgument.GetString();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTeamColor( lua_State* pLuaVM, void* pTeam, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "getTeamColor", 3 ) )
	{
		ucRed	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucGreen	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucBlue	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::CountPlayersInTeam( lua_State* pLuaVM, void* pTeam, unsigned int& uiCount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "countPlayersInTeam", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		uiCount = static_cast< unsigned int >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTeamFriendlyFire( lua_State* pLuaVM, void* pTeam, bool& bFriendlyFire )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "getTeamFriendlyFire", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bFriendlyFire = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

// Team set funcs

bool CLuaFunctionDefinitions::SetTeamName( lua_State* pLuaVM, void* pTeam, const char* szTeamName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );
	pLuaArguments.PushString( szTeamName );

	if( pLuaArguments.Call( pLuaVM, "setTeamName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTeamColor( lua_State* pLuaVM, void* pTeam, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "setTeamColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPlayerTeam( lua_State* pLuaVM, void* pPlayer, void* pTeam )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushUserData( pTeam );

	if( pLuaArguments.Call( pLuaVM, "setPlayerTeam", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTeamFriendlyFire( lua_State* pLuaVM, void* pTeam, bool bFriendlyFire )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pTeam );
	pLuaArguments.PushBoolean( bFriendlyFire );

	if( pLuaArguments.Call( pLuaVM, "setTeamFriendlyFire", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Water funcs

void* CLuaFunctionDefinitions::CreateWater( lua_State* pLuaVM, Vector3* pV1, Vector3* pV2, Vector3* pV3, Vector3* pV4, bool bShallow )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( pV1->fX );
	pLuaArguments.PushNumber( pV1->fY );
	pLuaArguments.PushNumber( pV1->fZ );

	pLuaArguments.PushNumber( pV2->fX );
	pLuaArguments.PushNumber( pV2->fY );
	pLuaArguments.PushNumber( pV2->fZ );

	pLuaArguments.PushNumber( pV3->fX );
	pLuaArguments.PushNumber( pV3->fY );
	pLuaArguments.PushNumber( pV3->fZ );

	if( pV4 )
	{
		pLuaArguments.PushNumber( pV4->fX );
		pLuaArguments.PushNumber( pV4->fY );
		pLuaArguments.PushNumber( pV4->fZ );
	}

	pLuaArguments.PushBoolean( bShallow );

	if( pLuaArguments.Call( pLuaVM, "createWater", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementWaterLevel( lua_State* pLuaVM, void* pWater, float fLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pWater );
	pLuaArguments.PushNumber( fLevel );

	if( pLuaArguments.Call( pLuaVM, "setElementWaterLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetAllElementWaterLevel( lua_State* pLuaVM, float fLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fLevel );

	if( pLuaArguments.Call( pLuaVM, "setAllElementWaterLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWorldWaterLevel( lua_State* pLuaVM, float fLevel, bool bIncludeWorldNonSeaLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fLevel );
	pLuaArguments.PushBoolean( bIncludeWorldNonSeaLevel );

	if( pLuaArguments.Call( pLuaVM, "setWorldWaterLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetWorldWaterLevel( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetWorldWaterLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetWaterVertexPosition( lua_State* pLuaVM, void* pWater, int iVertexIndex, Vector3& vecPosition )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pWater );
	pLuaArguments.PushNumber( iVertexIndex );

	if( pLuaArguments.Call( pLuaVM, "getWaterVertexPosition", 3 ) )
	{
		vecPosition.fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		vecPosition.fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		vecPosition.fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWaterVertexPosition( lua_State* pLuaVM, void* pWater, int iVertexIndex, Vector3& vecPosition )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pWater );
	pLuaArguments.PushNumber( iVertexIndex );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	if( pLuaArguments.Call( pLuaVM, "setWaterVertexPosition", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetWaterColor( lua_State* pLuaVM, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucAlpha )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWaterColor", 4 ) )
	{
		ucRed	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		ucGreen	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucBlue	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucAlpha	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWaterColor( lua_State* pLuaVM, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, unsigned char ucAlpha )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );
	pLuaArguments.PushNumber( ucAlpha );

	if( pLuaArguments.Call( pLuaVM, "setWaterColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetWaterColor( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetWaterColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Standard server functions
unsigned int CLuaFunctionDefinitions::GetMaxPlayers( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMaxPlayers", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMaxPlayers( lua_State* pLuaVM, unsigned int uiMax )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( uiMax );

	if( pLuaArguments.Call( pLuaVM, "setMaxPlayers", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::OutputChatBox( lua_State* pLuaVM, const char* szText, void* pElement, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue, bool bColorCoded )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szText );

	if( pElement )
		pLuaArguments.PushUserData( pElement );
	else
		pLuaArguments.PushUserData( NULL );
	
	if( ucRed )
	{
		pLuaArguments.PushNumber( ucRed );
		pLuaArguments.PushNumber( ucGreen );
		pLuaArguments.PushNumber( ucBlue );

		pLuaArguments.PushNumber( bColorCoded );
	}

	if( pLuaArguments.Call( pLuaVM, "outputChatBox", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::OutputConsole( lua_State* pLuaVM, const char* szText, void* pElement )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szText );
	pLuaArguments.PushUserData( pElement );

	if( pLuaArguments.Call( pLuaVM, "outputConsole", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetServerPassword( lua_State* pLuaVM, const string& strPassword, bool bSave )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( strPassword.c_str() );
	pLuaArguments.PushBoolean( bSave );

	if( pLuaArguments.Call( pLuaVM, "setServerPassword", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// General world get funcs

bool CLuaFunctionDefinitions::GetTime( lua_State* pLuaVM, unsigned char& ucHour, unsigned char& ucMinute )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getTime", 2 ) )
	{
		ucHour		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucMinute	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetWeather( lua_State* pLuaVM, unsigned char& ucWeather, unsigned char& ucWeatherBlendingTo )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWeather", 2 ) )
	{
		ucWeather			= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucWeatherBlendingTo	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetZoneName( lua_State* pLuaVM, Vector3& vecPosition, string& strOutName, bool bCitiesOnly )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushBoolean( bCitiesOnly );

	if( pLuaArguments.Call( pLuaVM, "getZoneName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutName = pLuaArgument.GetString();
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetGravity( lua_State* pLuaVM, float& fGravity )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getGravity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fGravity = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetGameSpeed( lua_State* pLuaVM, float& fSpeed )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getGameSpeed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fSpeed = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetWaveHeight( lua_State* pLuaVM, float& fHeight )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWaveHeight", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fHeight = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetFPSLimit( lua_State* pLuaVM, unsigned short& usLimit )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getFPSLimit", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		usLimit = static_cast< unsigned short >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMinuteDuration( lua_State* pLuaVM, unsigned long& ulDuration )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMinuteDuration", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ulDuration = static_cast< unsigned long >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsGarageOpen( lua_State* pLuaVM, unsigned char ucGarageID, bool& bIsOpen )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "isGarageOpen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bIsOpen = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTrafficLightState( lua_State* pLuaVM, unsigned char& ucState )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getTrafficLightState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		ucState = static_cast< unsigned char >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTrafficLightsLocked( lua_State* pLuaVM, bool& bLocked )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getTrafficLightsLocked", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bLocked = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetJetpackMaxHeight( lua_State* pLuaVM, float& fMaxHeight )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getJetpackMaxHeight", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fMaxHeight = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetAircraftMaxVelocity( lua_State* pLuaVM, float& fVelocity )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAircraftMaxVelocity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fVelocity = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetInteriorSoundsEnabled( lua_State* pLuaVM, bool& bEnabled )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getInteriorSoundsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bEnabled = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetRainLevel( lua_State* pLuaVM, float& fRainLevel )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRainLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fRainLevel = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetSunSize( lua_State* pLuaVM, float& fSunSize )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getSunSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fSunSize = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetSunColor( lua_State* pLuaVM, unsigned char& ucCoreR, unsigned char& ucCoreG, unsigned char& ucCoreB, unsigned char& ucCoronaR, unsigned char& ucCoronaG, unsigned char& ucCoronaB )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getSunColor", 6 ) )
	{
		ucCoreR		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -6 ) )->GetNumber() );
		ucCoreG		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -5 ) )->GetNumber() );
		ucCoreB		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );

		ucCoronaR	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucCoronaG	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucCoronaB	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetWindVelocity( lua_State* pLuaVM, float& fVelX, float& fVelY, float& fVelZ )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getWindVelocity", 3 ) )
	{
		fVelX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fVelY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fVelZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetFarClipDistance( lua_State* pLuaVM, float& fFarClip )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getFarClipDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fFarClip = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetFogDistance( lua_State* pLuaVM, float& fFogDist )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getFogDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fFogDist = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetAircraftMaxHeight( lua_State* pLuaVM, float& fMaxHeight )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAircraftMaxHeight", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		fMaxHeight = static_cast< float >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetOcclusionsEnabled( lua_State* pLuaVM, bool& bEnabled )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getOcclusionsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bEnabled = pLuaArgument.GetBoolean();
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetMoonSize( lua_State* pLuaVM, int& iSize )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getMoonSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		iSize = static_cast< int >( pLuaArgument.GetNumber() );
		
		return true;
	}

	return false;
}

// General world set funcs

bool CLuaFunctionDefinitions::SetTime( lua_State* pLuaVM, unsigned char ucHour, unsigned char ucMinute )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucHour );
	pLuaArguments.PushNumber( ucMinute );

	if( pLuaArguments.Call( pLuaVM, "setTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWeather( lua_State* pLuaVM, unsigned char ucWeather )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeather );

	if( pLuaArguments.Call( pLuaVM, "setWeather", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWeatherBlended( lua_State* pLuaVM, unsigned char ucWeather )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucWeather );

	if( pLuaArguments.Call( pLuaVM, "setWeatherBlended", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetGravity( lua_State* pLuaVM, float fGravity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fGravity );

	if( pLuaArguments.Call( pLuaVM, "setGravity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetGameSpeed( lua_State* pLuaVM, float fSpeed )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fSpeed );

	if( pLuaArguments.Call( pLuaVM, "setGameSpeed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWaveHeight( lua_State* pLuaVM, float fHeight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fHeight );

	if( pLuaArguments.Call( pLuaVM, "setWaveHeight", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetSkyGradient( lua_State* pLuaVM, unsigned char& ucTopRed, unsigned char& ucTopGreen, unsigned char& ucTopBlue, unsigned char& ucBottomRed, unsigned char& ucBottomGreen, unsigned char& ucBottomBlue )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getSkyGradient", 6 ) )
	{
		ucTopRed		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -6 ) )->GetBoolean() );
		ucTopGreen		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -5 ) )->GetBoolean() );
		ucTopBlue		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetBoolean() );

		ucBottomRed		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetBoolean() );
		ucBottomGreen	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetBoolean() );
		ucBottomBlue	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::SetSkyGradient( lua_State* pLuaVM, unsigned char ucTopRed, unsigned char ucTopGreen, unsigned char ucTopBlue, unsigned char ucBottomRed, unsigned char ucBottomGreen, unsigned char ucBottomBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucTopRed );
	pLuaArguments.PushNumber( ucTopGreen );
	pLuaArguments.PushNumber( ucTopBlue );

	pLuaArguments.PushNumber( ucBottomRed );
	pLuaArguments.PushNumber( ucBottomGreen );
	pLuaArguments.PushNumber( ucBottomBlue );

	if( pLuaArguments.Call( pLuaVM, "setSkyGradient", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetSkyGradient( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetSkyGradient", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetHeatHaze( lua_State* pLuaVM, SHeatHazeSettings& heatHazeSettings )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getHeatHaze", 9 ) )
	{
		heatHazeSettings.ucIntensity		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -9 ) )->GetNumber() );
		heatHazeSettings.ucRandomShift		= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -8 ) )->GetNumber() );
		heatHazeSettings.usSpeedMin			= static_cast< unsigned short >( ( new CLuaArgument( pLuaVM, -7 ) )->GetNumber() );
		heatHazeSettings.usSpeedMax			= static_cast< unsigned short >( ( new CLuaArgument( pLuaVM, -6 ) )->GetNumber() );
		heatHazeSettings.sScanSizeX			= static_cast< short >( ( new CLuaArgument( pLuaVM, -5 ) )->GetNumber() );
		heatHazeSettings.sScanSizeY			= static_cast< short >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		heatHazeSettings.usRenderSizeX		= static_cast< unsigned short >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		heatHazeSettings.usRenderSizeY		= static_cast< unsigned short >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		heatHazeSettings.bInsideBuilding	= ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::SetHeatHaze( lua_State* pLuaVM, const SHeatHazeSettings& heatHazeSettings )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( heatHazeSettings.ucIntensity );
	pLuaArguments.PushNumber( heatHazeSettings.ucRandomShift );
	pLuaArguments.PushNumber( heatHazeSettings.usSpeedMin );
	pLuaArguments.PushNumber( heatHazeSettings.usSpeedMax );
	pLuaArguments.PushNumber( heatHazeSettings.sScanSizeX );
	pLuaArguments.PushNumber( heatHazeSettings.sScanSizeY );
	pLuaArguments.PushNumber( heatHazeSettings.usRenderSizeX );
	pLuaArguments.PushNumber( heatHazeSettings.usRenderSizeY );
	pLuaArguments.PushBoolean( heatHazeSettings.bInsideBuilding );

	if( pLuaArguments.Call( pLuaVM, "setHeatHaze", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetHeatHaze( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetHeatHaze", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetFPSLimit( lua_State* pLuaVM, unsigned short usLimit, bool bSave )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usLimit );
	pLuaArguments.PushBoolean( bSave );

	if( pLuaArguments.Call( pLuaVM, "setFPSLimit", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMinuteDuration( lua_State* pLuaVM, unsigned long ulDuration )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ulDuration );

	if( pLuaArguments.Call( pLuaVM, "setMinuteDuration", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetGarageOpen( lua_State* pLuaVM, unsigned char ucGarageID, bool bIsOpen )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucGarageID );
	pLuaArguments.PushBoolean( bIsOpen );

	if( pLuaArguments.Call( pLuaVM, "setGarageOpen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetGlitchEnabled( lua_State* pLuaVM, const string& strGlitchName, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( strGlitchName.c_str() );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setGlitchEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsGlitchEnabled( lua_State* pLuaVM, const string& strGlitchName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( strGlitchName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "isGlitchEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetJetpackWeaponEnabled( lua_State* pLuaVM, eWeaponType weaponType )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( weaponType );

	if( pLuaArguments.Call( pLuaVM, "getJetpackWeaponEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetJetpackWeaponEnabled( lua_State* pLuaVM, eWeaponType weaponType, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( weaponType );
	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setJetpackWeaponEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetCloudsEnabled( lua_State* pLuaVM, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setCloudsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetCloudsEnabled( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getCloudsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTrafficLightState( lua_State* pLuaVM, unsigned char ucState, bool bForced )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucState );
	pLuaArguments.PushBoolean( bForced );

	if( pLuaArguments.Call( pLuaVM, "setTrafficLightState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetTrafficLightsLocked( lua_State* pLuaVM, bool bLocked )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bLocked );

	if( pLuaArguments.Call( pLuaVM, "setTrafficLightsLocked", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetJetpackMaxHeight( lua_State* pLuaVM, float fMaxHeight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fMaxHeight );

	if( pLuaArguments.Call( pLuaVM, "setJetpackMaxHeight", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetInteriorSoundsEnabled( lua_State* pLuaVM, bool bEnable )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnable );

	if( pLuaArguments.Call( pLuaVM, "setInteriorSoundsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetRainLevel( lua_State* pLuaVM, float fRainLevel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fRainLevel );

	if( pLuaArguments.Call( pLuaVM, "setRainLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetSunSize( lua_State* pLuaVM, float fSunSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fSunSize );

	if( pLuaArguments.Call( pLuaVM, "setSunSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetSunColor( lua_State* pLuaVM, unsigned char ucCoreR, unsigned char ucCoreG, unsigned char ucCoreB, unsigned char ucCoronaR, unsigned char ucCoronaG, unsigned char ucCoronaB )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucCoreR );
	pLuaArguments.PushNumber( ucCoreG );
	pLuaArguments.PushNumber( ucCoreB );

	pLuaArguments.PushNumber( ucCoronaR );
	pLuaArguments.PushNumber( ucCoronaG );
	pLuaArguments.PushNumber( ucCoronaB );

	if( pLuaArguments.Call( pLuaVM, "setSunColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWindVelocity( lua_State* pLuaVM, float fVelX, float fVelY, float fVelZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fVelX );
	pLuaArguments.PushNumber( fVelY );
	pLuaArguments.PushNumber( fVelZ );

	if( pLuaArguments.Call( pLuaVM, "setWindVelocity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetFarClipDistance( lua_State* pLuaVM, float fFarClip )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fFarClip );

	if( pLuaArguments.Call( pLuaVM, "setFarClipDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetFogDistance( lua_State* pLuaVM, float fFogDist )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fFogDist );

	if( pLuaArguments.Call( pLuaVM, "setFogDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetAircraftMaxHeight( lua_State* pLuaVM, float fMaxHeight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fMaxHeight );

	if( pLuaArguments.Call( pLuaVM, "setAircraftMaxHeight", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetAircraftMaxVelocity( lua_State* pLuaVM, float fVelocity )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fVelocity );

	if( pLuaArguments.Call( pLuaVM, "setAircraftMaxVelocity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetOcclusionsEnabled( lua_State* pLuaVM, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setOcclusionsEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetRainLevel( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetRainLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetSunSize( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetSunSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetSunColor( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetSunColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetWindVelocity( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetWindVelocity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetFarClipDistance( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetFarClipDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetFogDistance( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetFogDistance", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveWorldModel( lua_State* pLuaVM, unsigned short usModel, float fRadius, const Vector3& vecPosition, char cInterior )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usModel );
	pLuaArguments.PushNumber( fRadius );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( cInterior );

	if( pLuaArguments.Call( pLuaVM, "removeWorldModel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RestoreWorldModel( lua_State* pLuaVM, unsigned short usModel, float fRadius, const Vector3& vecPosition, char cInterior )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usModel );
	pLuaArguments.PushNumber( fRadius );
	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );
	pLuaArguments.PushNumber( cInterior );

	if( pLuaArguments.Call( pLuaVM, "restoreWorldModel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RestoreAllWorldModels( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "restoreAllWorldModels", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SendSyncIntervals( lua_State* pLuaVM, void* pPlayer )
{
	CLuaArguments pLuaArguments;

	if( pPlayer )
	{
		pLuaArguments.PushUserData( pPlayer );
	}

	if( pLuaArguments.Call( pLuaVM, "sendSyncIntervals", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetPedTargetingMarkerEnabled( lua_State* pLuaVM, bool bEnabled )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( bEnabled );

	if( pLuaArguments.Call( pLuaVM, "setPedTargetingMarkerEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedTargetingMarkerEnabled( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "isPedTargetingMarkerEnabled", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMoonSize( lua_State* pLuaVM, int iMoonSize )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iMoonSize );

	if( pLuaArguments.Call( pLuaVM, "setMoonSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::ResetMoonSize( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "resetMoonSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Loaded Map Functions

void* CLuaFunctionDefinitions::GetRootElement( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRootElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

//void* CLuaFunctionDefinitions::LoadMapData( lua_State* pLuaVM, void* pParent, CXMLNode* pNode )
//void* CLuaFunctionDefinitions::SaveMapData( lua_State* pLuaVM, void* pElement, CXMLNode* pNode, bool bChildren )
	
// Account get funcs

void* CLuaFunctionDefinitions::GetAccount( lua_State* pLuaVM, const char* szName, const char* szPassword )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "getAccount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

CLuaArguments* CLuaFunctionDefinitions::GetAccounts( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAccounts", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetArray();
	}

	return false;
}

void* CLuaFunctionDefinitions::GetAccountPlayer( lua_State* pLuaVM, void* pAccount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "getAccountPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::IsGuestAccount( lua_State* pLuaVM, void* pAccount, bool& bGuest )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "isGuestAccount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		bGuest = pLuaArgument.GetBoolean();

		return true;
	}

	return false;
}

CLuaArgument* CLuaFunctionDefinitions::GetAccountData( lua_State* pLuaVM, void* pAccount, const char* szKey )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szKey );

	if( pLuaArguments.Call( pLuaVM, "getAccountData", 1 ) )
	{
		return new CLuaArgument( pLuaVM, -1 );
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetAllAccountData( lua_State* pLuaVM, void* pAccount )
{
	return false;
}

bool CLuaFunctionDefinitions::GetAccountSerial( lua_State* pLuaVM, void* pAccount, string& strSerial )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "getAccountSerial", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strSerial = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetAccountsBySerial( lua_State* pLuaVM, const string& strSerial, vector<void*>& outAccounts )
{
	return false;
}

// Account set funcs

void* CLuaFunctionDefinitions::AddAccount( lua_State* pLuaVM, const char* szName, const char* szPassword )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "addAccount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::RemoveAccount( lua_State* pLuaVM, void* pAccount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );

	if( pLuaArguments.Call( pLuaVM, "removeAccount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetAccountPassword( lua_State* pLuaVM, void* pAccount, const char* szPassword )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "setAccountPassword", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetAccountData( lua_State* pLuaVM, void* pAccount, const char* szKey, CLuaArgument* pArgument )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szKey );
	pLuaArguments.PushArgument( pArgument );

	if( pLuaArguments.Call( pLuaVM, "setAccountData", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::CopyAccountData( lua_State* pLuaVM, void* pAccount, void* pFromAccount )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushUserData( pFromAccount );

	if( pLuaArguments.Call( pLuaVM, "copyAccountData", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Log in/out funcs

bool CLuaFunctionDefinitions::LogIn( lua_State* pLuaVM, void* pPlayer, void* pAccount, const char* szPassword )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushUserData( pAccount );
	pLuaArguments.PushString( szPassword );

	if( pLuaArguments.Call( pLuaVM, "logIn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::LogOut( lua_State* pLuaVM, void* pPlayer )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "logOut", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Admin funcs

bool CLuaFunctionDefinitions::KickPlayer( lua_State* pLuaVM, void* pPlayer, string strResponsible, string strReason )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushString( strResponsible.c_str() );
	pLuaArguments.PushString( strReason.c_str() );

	if( pLuaArguments.Call( pLuaVM, "kickPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

void* CLuaFunctionDefinitions::BanPlayer( lua_State* pLuaVM, void* pPlayer, bool bIP, bool bUsername, bool bSerial, void* pResponsible, string strResponsible, string strReason, time_t tUnban )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	pLuaArguments.PushBoolean( bIP );
	pLuaArguments.PushBoolean( bUsername );
	pLuaArguments.PushBoolean( bSerial );

	if( pResponsible )
	{
		pLuaArguments.PushUserData( pResponsible );
		pLuaArguments.PushString( strResponsible.c_str() );
		pLuaArguments.PushString( strReason.c_str() );
		pLuaArguments.PushNumber( static_cast< double >( tUnban ) );
	}

	if( pLuaArguments.Call( pLuaVM, "banPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::AddBan( lua_State* pLuaVM, string strIP, string strUsername, string strSerial, void* pResponsible, string strResponsible, string strReason, time_t tUnban )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( strIP.c_str() );
	pLuaArguments.PushString( strUsername.c_str() );
	pLuaArguments.PushString( strSerial.c_str() );

	if( pResponsible )
	{
		pLuaArguments.PushUserData( pResponsible );
		pLuaArguments.PushString( strResponsible.c_str() );
		pLuaArguments.PushString( strReason.c_str() );
		pLuaArguments.PushNumber( static_cast< double >( tUnban ) );
	}

	if( pLuaArguments.Call( pLuaVM, "addBan", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::RemoveBan( lua_State* pLuaVM, void* pBan, void* pResponsible )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pResponsible )
	{
		pLuaArguments.PushUserData( pResponsible );
	}

	if( pLuaArguments.Call( pLuaVM, "removeBan", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBans( lua_State* pLuaVM ) // TODO
{
	return false;
}

bool CLuaFunctionDefinitions::ReloadBanList( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "reloadBanList", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanIP( lua_State* pLuaVM, void* pBan, string& strOutIP )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanIP", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutIP = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanSerial( lua_State* pLuaVM, void* pBan, string& strOutSerial )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanSerial", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutSerial = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanUsername( lua_State* pLuaVM, void* pBan, string& strOutUsername )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanUsername", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutUsername = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanNick( lua_State* pLuaVM, void* pBan, string& strOutNick )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanNick", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutNick = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanReason( lua_State* pLuaVM, void* pBan, string& strOutReason )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanReason", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutReason = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanAdmin( lua_State* pLuaVM, void* pBan, string& strOutAdmin )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanAdmin", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strOutAdmin = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetBanTime( lua_State* pLuaVM, void* pBan, time_t& time )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getBanTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		time = static_cast< time_t >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetUnbanTime( lua_State* pLuaVM, void* pBan, time_t& time )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );

	if( pLuaArguments.Call( pLuaVM, "getUnbanTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		time = static_cast< time_t >( pLuaArgument.GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::SetUnbanTime( lua_State* pLuaVM, void* pBan, time_t time )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );
	pLuaArguments.PushNumber( static_cast< double >( time ) );

	if( pLuaArguments.Call( pLuaVM, "setUnbanTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetBanReason( lua_State* pLuaVM, void* pBan, const string& strReason )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );
	pLuaArguments.PushString( strReason.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setBanReason", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetBanAdmin( lua_State* pLuaVM, void* pBan, const string& strAdminName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pBan );
	pLuaArguments.PushString( strAdminName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "setBanAdmin", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Cursor get funcs

bool CLuaFunctionDefinitions::IsCursorShowing( lua_State* pLuaVM, void* pPlayer, bool& bShowing )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );

	if( pLuaArguments.Call( pLuaVM, "isCursorShowing", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return bShowing = pLuaArgument.GetBoolean();
	}

	return false;
}

// Cursor set funcs

bool CLuaFunctionDefinitions::ShowCursor( lua_State* pLuaVM, void* pElement, bool bShow, bool bToggleControls )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushBoolean( bShow );
	pLuaArguments.PushBoolean( bToggleControls );

	if( pLuaArguments.Call( pLuaVM, "showCursor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Chat funcs

bool CLuaFunctionDefinitions::ShowChat( lua_State* pLuaVM, void* pElement, bool bShow )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushBoolean( bShow );

	if( pLuaArguments.Call( pLuaVM, "showChat", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Misc funcs

bool CLuaFunctionDefinitions::ResetMapInfo( lua_State* pLuaVM, void* pElement )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	if( pLuaArguments.Call( pLuaVM, "resetMapInfo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Resource funcs

void* CLuaFunctionDefinitions::CreateResource( lua_State* pLuaVM, const char* szResourceName, const char* szOrganizationalDir )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );
	pLuaArguments.PushString( szOrganizationalDir );

	if( pLuaArguments.Call( pLuaVM, "createResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::CopyResource( lua_State* pLuaVM, void* pResource, const char* szNewResourceName, const char* szOrganizationalDir )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szNewResourceName );
	pLuaArguments.PushString( szOrganizationalDir );

	if( pLuaArguments.Call( pLuaVM, "copyResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetResourceRootElement( lua_State* pLuaVM, void* pResource )
{
	CLuaArguments pLuaArguments;

	if( pResource )
	{
		pLuaArguments.PushUserData( pResource );
	}

	if( pLuaArguments.Call( pLuaVM, "getResourceRootElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetResourceMapRootElement( lua_State* pLuaVM, void* pResource, const char* szMap )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szMap );

	if( pLuaArguments.Call( pLuaVM, "getResourceMapRootElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return false;
}

void* CLuaFunctionDefinitions::GetResourceDynamicElementRoot( lua_State* pLuaVM, void* pResource )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceDynamicElementRoot", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::RemoveResourceFile( lua_State* pLuaVM, void* pResource, const char* szFilename )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szFilename );

	if( pLuaArguments.Call( pLuaVM, "removeResourceFile", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetResourceExportedFunctions( lua_State* pLuaVM, void* pResource )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceExportedFunctions", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetArray();
	}

	return NULL;
}

void* CLuaFunctionDefinitions::GetResourceFromName( lua_State* pLuaVM, const char* szResourceName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );

	if( pLuaArguments.Call( pLuaVM, "getResourceFromName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetResourceInfo( lua_State* pLuaVM, void* pResource, const char* szAttribute, string& strInfo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szAttribute );

	if( pLuaArguments.Call( pLuaVM, "getResourceInfo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strInfo = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetResourceLastStartTime( lua_State* pLuaVM, void* pResource, unsigned int& uiTime )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceLastStartTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		uiTime = pLuaArgument.GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetResourceLoadFailureReason( lua_State* pLuaVM, void* pResource, string& strReason )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceLoadFailureReason", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strReason = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetResourceLoadTime( lua_State* pLuaVM, void* pResource, unsigned int& uiTime )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceLoadTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		uiTime = pLuaArgument.GetNumber< unsigned int >();

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetResourceName( lua_State* pLuaVM, void* pResource, string& strName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strName = string( pLuaArgument.GetString() );

		return true;
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetResources( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getResources", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetArray();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetResourceState( lua_State* pLuaVM, void* pResource, string& strState )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "getResourceState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		strState = string( pLuaArgument.GetString() );

		return false;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetThisResource( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getThisResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return false;
}

bool CLuaFunctionDefinitions::RefreshResources( lua_State* pLuaVM, bool refreshAll )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushBoolean( refreshAll );

	if( pLuaArguments.Call( pLuaVM, "refreshResources", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RemoveResourceDefaultSetting( lua_State* pLuaVM, void* pResource, const char* szSettingName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );

	if( pLuaArguments.Call( pLuaVM, "removeResourceDefaultSetting", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::StartResource( lua_State* pLuaVM, void* pResource, bool persistent, bool startIncludedResources, bool loadServerConfigs, bool loadMaps, bool loadServerScripts, bool loadHTML, bool loadClientConfigs, bool loadClientScripts, bool loadFiles )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushBoolean( persistent );
	pLuaArguments.PushBoolean( startIncludedResources );
	pLuaArguments.PushBoolean( loadServerConfigs );
	pLuaArguments.PushBoolean( loadMaps );
	pLuaArguments.PushBoolean( loadServerScripts );
	pLuaArguments.PushBoolean( loadHTML );
	pLuaArguments.PushBoolean( loadClientConfigs );
	pLuaArguments.PushBoolean( loadClientScripts );
	pLuaArguments.PushBoolean( loadFiles );

	if( pLuaArguments.Call( pLuaVM, "startResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RestartResource( lua_State* pLuaVM, void* pResource )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "restartResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::StopResource( lua_State* pLuaVM, void* pResource )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );

	if( pLuaArguments.Call( pLuaVM, "stopResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetResourceDefaultSetting( lua_State* pLuaVM, void* pResource, const char* szSettingName, const char* szSettingValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );
	pLuaArguments.PushString( szSettingValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceDefaultSetting", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetResourceDefaultSetting( lua_State* pLuaVM, void* pResource, const char* szSettingName, int iSettingValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );
	pLuaArguments.PushNumber( iSettingValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceDefaultSetting", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetResourceDefaultSetting( lua_State* pLuaVM, void* pResource, const char* szSettingName, float fSettingValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szSettingName );
	pLuaArguments.PushNumber( fSettingValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceDefaultSetting", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetResourceInfo( lua_State* pLuaVM, void* pResource, const char* szAttribute, const char* szValue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szAttribute );
	pLuaArguments.PushString( szValue );

	if( pLuaArguments.Call( pLuaVM, "setResourceInfo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::RenameResource( lua_State* pLuaVM, const char* szResourceName, const char* szNewResourceName, const char* szOrganizationalPath )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );
	pLuaArguments.PushString( szNewResourceName );
	pLuaArguments.PushString( szOrganizationalPath );

	if( pLuaArguments.Call( pLuaVM, "renameResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::DeleteResource( lua_State* pLuaVM, const char* szResourceName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szResourceName );

	if( pLuaArguments.Call( pLuaVM, "deleteResource", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::UpdateResourceACLRequest( lua_State* pLuaVM, void* pResource, const char* szRightName, bool bAccess, const char* szByWho )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pResource );
	pLuaArguments.PushString( szRightName );
	pLuaArguments.PushBoolean( bAccess );
	pLuaArguments.PushString( szByWho );

	if( pLuaArguments.Call( pLuaVM, "updateResourceACLRequest", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

// Version funcs

LuaTable CLuaFunctionDefinitions::GetVersion( lua_State* pLuaVM )
{
	LuaTable pLuaTable;

	if( CLuaArguments().Call( pLuaVM, "getVersion", 1 ) )
	{
		pLuaTable = CLuaArgument( pLuaVM, -1 ).GetTable();
	}

	return pLuaTable;
}

// Camera get functions
bool CLuaFunctionDefinitions::GetCameraMatrix( lua_State* pLuaVM, void* pPlayer, Vector3& vecPosition, Vector3& vecLookAt, float& fRoll, float& fFOV )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	
	int i = 8;

	if( pLuaArguments.Call( pLuaVM, "getCameraMatrix", i ) )
	{
		vecPosition.fX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );
		vecPosition.fY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );
		vecPosition.fZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );

		vecLookAt.fX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );
		vecLookAt.fY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );
		vecLookAt.fZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );

		fRoll			= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );
		fFOV			= static_cast< float >( ( new CLuaArgument( pLuaVM, -( i-- ) ) )->GetNumber() );

		return true;
	}

	return false;
}

void* CLuaFunctionDefinitions::GetCameraTarget( lua_State* pLuaVM, void* pPlayer )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	
	if( pLuaArguments.Call( pLuaVM, "getCameraTarget", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		if( pLuaArgument.GetType() == LUA_TLIGHTUSERDATA )
		{
			return pLuaArgument.GetLightUserData();
		}
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetCameraInterior( lua_State* pLuaVM, void* pPlayer, unsigned char& ucInterior )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pPlayer );
	
	if( pLuaArguments.Call( pLuaVM, "getCameraInterior", 1 ) )
	{
		ucInterior = static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

// Camera set functions

bool CLuaFunctionDefinitions::SetCameraMatrix( lua_State* pLuaVM, void* pElement, const Vector3& vecPosition, Vector3& pvecLookAt, float fRoll, float fFOV )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	pLuaArguments.PushNumber( vecPosition.fX );
	pLuaArguments.PushNumber( vecPosition.fY );
	pLuaArguments.PushNumber( vecPosition.fZ );

	pLuaArguments.PushNumber( pvecLookAt.fX );
	pLuaArguments.PushNumber( pvecLookAt.fY );
	pLuaArguments.PushNumber( pvecLookAt.fZ );

	pLuaArguments.PushNumber( fRoll );
	pLuaArguments.PushNumber( fFOV );
	
	if( pLuaArguments.Call( pLuaVM, "setCameraMatrix", 1 ) )
	{
		return CLuaArgument( pLuaVM, -1 ).GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetCameraTarget( lua_State* pLuaVM, void* pElement, void* pTarget )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushUserData( pTarget );

	if( pLuaArguments.Call( pLuaVM, "setCameraTarget", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetCameraInterior( lua_State* pLuaVM, void* pElement, unsigned char ucInterior )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucInterior );

	if( pLuaArguments.Call( pLuaVM, "setCameraInterior", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::FadeCamera( lua_State* pLuaVM, void* pElement, bool bFadeIn, float fFadeTime, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushBoolean( bFadeIn );
	pLuaArguments.PushNumber( fFadeTime );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "fFadeCamera", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}

// Weapon give/take functions

bool CLuaFunctionDefinitions::GiveWeapon( lua_State* pLuaVM, void* pElement, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushNumber( usAmmo );
	pLuaArguments.PushBoolean( bSetAsCurrent );

	if( pLuaArguments.Call( pLuaVM, "giveWeapon", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::TakeWeapon( lua_State* pLuaVM, void* pElement, unsigned char ucWeaponID, unsigned short usAmmo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushNumber( usAmmo );

	if( pLuaArguments.Call( pLuaVM, "takeWeapon", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::TakeAllWeapons( lua_State* pLuaVM, void* pElement )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );

	if( pLuaArguments.Call( pLuaVM, "takeAllWeapons", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetWeaponAmmo( lua_State* pLuaVM, void* pElement, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pElement );
	pLuaArguments.PushNumber( ucWeaponID );
	pLuaArguments.PushNumber( usAmmo );
	pLuaArguments.PushNumber( usAmmoInClip );

	if( pLuaArguments.Call( pLuaVM, "setWeaponAmmo", 1 ) )
	{
		return ( new CLuaArgument( pLuaVM, -1 ) )->GetBoolean();
	}

	return false;
}
