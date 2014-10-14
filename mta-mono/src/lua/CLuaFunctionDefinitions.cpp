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

// Element create/destroy

void* CLuaFunctionDefinitions::CreateElement( lua_State* pLuaVM, string sType, string sID )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( sType.c_str() );

	if( !sID.empty() )
	{
		pLuaArguments.PushString( sID.c_str() );
	}

	if( pLuaArguments.Call( pLuaVM, "createElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
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

void* CLuaFunctionDefinitions::CloneElement( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, bool bCloneChildren )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushBoolean( bCloneChildren );

	if( pLuaArguments.Call( pLuaVM, "cloneElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

// Element get funcs

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

		return string( pLuaArgument.GetString() );
	}

	return string();
}

void* CLuaFunctionDefinitions::GetElementByID( lua_State* pLuaVM, string sID )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( sID.c_str() );

	if( pLuaArguments.Call( pLuaVM, "getElementByID", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
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

		return pLuaArgument.GetLightUserData();
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

		return pLuaArgument.GetLightUserData();
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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetElementPosition( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementPosition", 3 ) )
	{
		fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );
		
		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementRotation( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementRotation", 3 ) )
	{
		fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );
		
		return true;
	}


	return false;
}

bool CLuaFunctionDefinitions::GetElementVelocity( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getElementVelocity", 3 ) )
	{
		fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );
		
		return true;
	}


	return false;
}

int CLuaFunctionDefinitions::GetElementInterior( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementInterior", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsElementWithinColShape( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementWithinColShape", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementWithinMarker( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementWithinMarker", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

int CLuaFunctionDefinitions::GetElementDimension( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementDimension", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

string CLuaFunctionDefinitions::GetElementZoneName( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementZoneName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
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

		return pLuaArgument.GetLightUserData();
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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetElementAlpha( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAlpha", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsElementDoubleSided( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementDoubleSided", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

float CLuaFunctionDefinitions::GetElementHealth( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementHealth", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetNumber() );
	}

	return 0.0f;
}

int CLuaFunctionDefinitions::GetElementModel( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementModel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsElementInWater( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementInWater", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetElementAttachedOffsets( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ, float &fRX, float &fRY, float &fRZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getElementAttachedOffsets", 6 ) )
	{
		fX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -6 ) )->GetNumber() );
		fY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -5 ) )->GetNumber() );
		fZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );
		fRX	= static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fRY	= static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fRZ	= static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

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

		return pLuaArgument.GetLightUserData();
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

bool CLuaFunctionDefinitions::IsElementFrozen( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetLowLodElement( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getLowLodElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsElementLowLod( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isElementLowLod", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
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

bool CLuaFunctionDefinitions::SetElementPosition( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );

	if( pLuaArguments.Call( pLuaVM, "setElementPosition", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementRotation( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );

	if( pLuaArguments.Call( pLuaVM, "setElementRotation", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetElementVelocity( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );

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

bool CLuaFunctionDefinitions::AttachElements( lua_State* pLuaVM, void* pUserData, void* pTarget, float fX, float fY, float fZ, float fRX, float fRY, float fRZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

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

bool CLuaFunctionDefinitions::SetElementAttachedOffsets( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRX );
	pLuaArguments.PushNumber( fRY );
	pLuaArguments.PushNumber( fRZ );

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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}