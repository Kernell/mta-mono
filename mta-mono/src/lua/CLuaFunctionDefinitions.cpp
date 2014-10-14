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

// Player get functions
int CLuaFunctionDefinitions::GetPlayerCount( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getPlayerCount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

void* CLuaFunctionDefinitions::GetPlayerFromName( lua_State* pLuaVM, string sName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( sName.c_str() );

	if( pLuaArguments.Call( pLuaVM, "getPlayerFromName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetPlayerMoney( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerMoney", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

int CLuaFunctionDefinitions::GetPlayerPing( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerPing", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

void* CLuaFunctionDefinitions::GetRandomPlayer( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getRandomPlayer", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsPlayerMuted( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerMuted", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return 0;
}

void* CLuaFunctionDefinitions::GetPlayerTeam( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerTeam", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetPlayerWantedLevel( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerWantedLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

int CLuaFunctionDefinitions::GetAlivePlayers( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getAlivePlayers", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

int CLuaFunctionDefinitions::GetDeadPlayers( lua_State* pLuaVM )
{
	CLuaArguments pLuaArguments;

	if( pLuaArguments.Call( pLuaVM, "getDeadPlayers", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

int CLuaFunctionDefinitions::GetPlayerIdleTime( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerIdleTime", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsPlayerMapForced( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerMapForced", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

string CLuaFunctionDefinitions::GetPlayerNametagText( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerNametagText", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

bool CLuaFunctionDefinitions::GetPlayerNametagColor( lua_State* pLuaVM, void* pUserData, int &iRed, int &iGreen, int &iBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerNametagColor", 3 ) )
	{
		iRed	= static_cast< int >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		iGreen	= static_cast< int >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		iBlue	= static_cast< int >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPlayerNametagShowing( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPlayerNametagShowing", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
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

int CLuaFunctionDefinitions::GetPlayerBlurLevel( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerBlurLevel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

string CLuaFunctionDefinitions::GetPlayerName( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

string CLuaFunctionDefinitions::GetPlayerIP( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerIP", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

void* CLuaFunctionDefinitions::GetPlayerAccount( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPlayerAccount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
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

int CLuaFunctionDefinitions::GetPlayerACInfo( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;
	
	pLuaArguments.PushUserData( pUserData );
	
	if( pLuaArguments.Call( pLuaVM, "getPlayerACInfo", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );
		
		// TODO
	}
	
	return 0;
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

bool CLuaFunctionDefinitions::SpawnPlayer( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, int iRotation, int iSkinID, int iInterior, int iDimension, void* pTeam )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
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

bool CLuaFunctionDefinitions::RedirectPlayer( lua_State* pLuaVM, void* pUserData, string sServerIP, int iServerPort, string sServerPassword )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushString( sServerIP.c_str() );
	pLuaArguments.PushNumber( iServerPort );
	pLuaArguments.PushString( sServerPassword.c_str() );

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
void* CLuaFunctionDefinitions::CreatePed( lua_State* pLuaVM, int iModelid, float fX, float fY, float fZ, float fRot, bool bSynced )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( iModelid );
	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushNumber( fRot );
	pLuaArguments.PushBoolean( bSynced );

	if( pLuaArguments.Call( pLuaVM, "createPed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

float CLuaFunctionDefinitions::GetPedArmor( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedArmor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetNumber() );
	}

	return 0.0f;
}

bool CLuaFunctionDefinitions::IsPedChoking( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedChoking", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedDead( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDead", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedDucked( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDucked", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

float CLuaFunctionDefinitions::GetPedStat( lua_State* pLuaVM, void* pUserData, int iStat )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( iStat );

	if( pLuaArguments.Call( pLuaVM, "getPedStat", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetNumber() );
	}

	return 0.0f;
}

void* CLuaFunctionDefinitions::GetPedTarget( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedTarget", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
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
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
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

bool CLuaFunctionDefinitions::DoesPedHaveJetPack( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "doesPedHaveJetPack", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedOnGround( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedOnGround", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

int CLuaFunctionDefinitions::GetPedFightingStyle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedFightingStyle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

int CLuaFunctionDefinitions::GetPedMoveAnim( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedMoveAnim", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

float CLuaFunctionDefinitions::GetPedGravity( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedGravity", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetNumber() );
	}

	return 0;
}

void* CLuaFunctionDefinitions::GetPedContactElement( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedContactElement", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetPedWeaponSlot( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedWeaponSlot", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsPedDoingGangDriveby( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedDoingGangDriveby", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedOnFire( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedOnFire", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedHeadless( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedHeadless", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsPedFrozen( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isPedFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

int CLuaFunctionDefinitions::GetPedOccupiedVehicleSeat( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getPedOccupiedVehicleSeat", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::IsPedInVehicle( lua_State* pLuaVM, void* pUserData, void* pPed )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pPed );

	if( pLuaArguments.Call( pLuaVM, "isPedInVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

// Vehicle get functions
string CLuaFunctionDefinitions::GetVehicleType( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
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

bool CLuaFunctionDefinitions::GetVehicleColor( lua_State* pLuaVM, void* pUserData, unsigned char& ucR1, unsigned char& ucG1, unsigned char& ucB1, unsigned char& ucR2, unsigned char& ucG2, unsigned char& ucB2, unsigned char& ucR3, unsigned char& ucG3, unsigned char& ucB3, unsigned char& ucR4, unsigned char& ucG4, unsigned char& ucB4 )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushBoolean( true );

	if( pLuaArguments.Call( pLuaVM, "getVehicleColor", 12 ) )
	{
		ucR1	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -12 ) )->GetNumber() );
		ucG1	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -11 ) )->GetNumber() );
		ucB1	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -10 ) )->GetNumber() );

		ucR2	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -9 ) )->GetNumber() );
		ucG2	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -8 ) )->GetNumber() );
		ucB2	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -7 ) )->GetNumber() );

		ucR3	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -6 ) )->GetNumber() );
		ucG3	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -5 ) )->GetNumber() );
		ucB3	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -4 ) )->GetNumber() );

		ucR4	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucG4	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucB4	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

unsigned short CLuaFunctionDefinitions::GetVehicleModelFromName( lua_State* pLuaVM, const char* szName )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushString( szName );

	if( pLuaArguments.Call( pLuaVM, "getVehicleModelFromName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned short >( pLuaArgument.GetNumber() );
	}

	return 0;
}

bool CLuaFunctionDefinitions::GetVehicleLandingGearDown( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleLandingGearDown", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

int CLuaFunctionDefinitions::GetVehicleMaxPassengers( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleMaxPassengers", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

string CLuaFunctionDefinitions::GetVehicleName( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

string CLuaFunctionDefinitions::GetVehicleNameFromModel( lua_State* pLuaVM, void* pUserData, unsigned short usModel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( usModel );

	if( pLuaArguments.Call( pLuaVM, "getVehicleNameFromModel", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

void* CLuaFunctionDefinitions::GetVehicleOccupant( lua_State* pLuaVM, void* pUserData, unsigned int uiSeat )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( uiSeat );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOccupant", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehicleOccupants( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOccupants", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		//return pLuaArgument.GetLightUserData();
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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::GetVehicleSirensOn( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleSirensOn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleTurnVelocity( lua_State* pLuaVM, void* pUserData, float &fX, float& fY, float& fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTurnVelocity", 3 ) )
	{
		fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fZ = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleTurretPosition( lua_State* pLuaVM, void* pUserData, float &fX, float& fY )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTurretPosition", 2 ) )
	{
		fX = static_cast< float >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fY = static_cast< float >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleLocked( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleLocked", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehiclesOfType( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclesOfType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		//return pLuaArgument.GetBoolean();
	}

	return false;
}

unsigned short CLuaFunctionDefinitions::GetVehicleUpgradeOnSlot( lua_State* pLuaVM, void* pUserData, unsigned char ucSlot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucSlot );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeOnSlot", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned short >( pLuaArgument.GetNumber() );
	}

	return 0;
}

CLuaArguments* CLuaFunctionDefinitions::GetVehicleUpgrades( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgrades", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		//return pLuaArgument.GetNumber();
	}

	return NULL;
}

string CLuaFunctionDefinitions::GetVehicleUpgradeSlotName( lua_State* pLuaVM, unsigned char ucSlot )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( ucSlot );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeSlotName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

string CLuaFunctionDefinitions::GetVehicleUpgradeSlotName( lua_State* pLuaVM, unsigned short usUpgrade )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( usUpgrade );

	if( pLuaArguments.Call( pLuaVM, "getVehicleUpgradeSlotName", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return string( pLuaArgument.GetString() );
	}

	return string();
}

CLuaArguments* CLuaFunctionDefinitions::GetVehicleCompatibleUpgrades( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleCompatibleUpgrades", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		//return pLuaArgument.GetString();
	}

	return NULL;
}

unsigned char CLuaFunctionDefinitions::GetVehicleDoorState( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );

	if( pLuaArguments.Call( pLuaVM, "getVehicleDoorState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned char >( pLuaArgument.GetNumber() );
	}

	return 0;
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

unsigned char CLuaFunctionDefinitions::GetVehicleLightState( lua_State* pLuaVM, void* pUserData, unsigned char ucLight )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucLight );

	if( pLuaArguments.Call( pLuaVM, "getVehicleLightState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned char >( pLuaArgument.GetNumber() );
	}

	return 0;
}

unsigned char CLuaFunctionDefinitions::GetVehiclePanelState( lua_State* pLuaVM, void* pUserData, unsigned char ucPanel )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucPanel );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePanelState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned char >( pLuaArgument.GetNumber() );
	}

	return 0;
}

unsigned char CLuaFunctionDefinitions::GetVehicleOverrideLights( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleOverrideLights", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned char >( pLuaArgument.GetNumber() );
	}

	return 0;
}

void* CLuaFunctionDefinitions::GetVehicleTowedByVehicle( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleTowedByVehicle", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
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

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

unsigned char CLuaFunctionDefinitions::GetVehiclePaintjob( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePaintjob", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned char >( pLuaArgument.GetNumber() );
	}

	return 0;
}

const char* CLuaFunctionDefinitions::GetVehiclePlateText( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehiclePlateText", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetString();
	}

	return NULL;
}

bool CLuaFunctionDefinitions::IsVehicleDamageProof( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleDamageProof", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleFuelTankExplodable( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleFuelTankExplodable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleFrozen( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleFrozen", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsVehicleOnGround( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleOnGround", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetVehicleEngineState( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleEngineState", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsTrainDerailed( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isTrainDerailed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::IsTrainDerailable( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isTrainDerailable", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::GetTrainDirection( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getTrainDirection", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

float CLuaFunctionDefinitions::GetTrainSpeed( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getTrainSpeed", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetNumber() );
	}

	return 0.0f;
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

bool CLuaFunctionDefinitions::GetVehicleHeadLightColor( lua_State* pLuaVM, void* pUserData, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getVehicleHeadLightColor", 1 ) )
	{
		ucRed	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucGreen	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucBlue	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

float CLuaFunctionDefinitions::GetVehicleDoorOpenRatio( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucDoor );

	if( pLuaArguments.Call( pLuaVM, "getVehicleDoorOpenRatio", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetBoolean() );
	}

	return 0.0f;
}

bool CLuaFunctionDefinitions::IsVehicleTaxiLightOn( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "isVehicleTaxiLightOn", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
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

bool CLuaFunctionDefinitions::SetVehicleColor( lua_State* pLuaVM, void* pUserData, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucRed2, unsigned char& ucGreen2, unsigned char& ucBlue2, unsigned char& ucRed3, unsigned char& ucGreen3, unsigned char& ucBlue3, unsigned char& ucRed4, unsigned char& ucGreen4, unsigned char& ucBlue4 )
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
void* CLuaFunctionDefinitions::CreateMarker( lua_State* pLuaVM, float fX, float fY, float fZ, const char* szType, float fSize, unsigned char iRed, unsigned char iGreen, unsigned char iBlue, void* pVisibleTo )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushNumber( fX );
	pLuaArguments.PushNumber( fY );
	pLuaArguments.PushNumber( fZ );
	pLuaArguments.PushString( szType );
	pLuaArguments.PushNumber( fSize );
	pLuaArguments.PushNumber( iRed );
	pLuaArguments.PushNumber( iGreen );
	pLuaArguments.PushNumber( iBlue );
	pLuaArguments.PushUserData( pVisibleTo );

	if( pLuaArguments.Call( pLuaVM, "createMarker", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetLightUserData();
	}

	return NULL;
}

// Marker get functions
unsigned int CLuaFunctionDefinitions::GetMarkerCount( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerCount", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< unsigned int >( pLuaArgument.GetNumber() );
	}

	return 0;
}

const char* CLuaFunctionDefinitions::GetMarkerType( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerType", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetString();
	}

	return NULL;
}

float CLuaFunctionDefinitions::GetMarkerSize( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerSize", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return static_cast< float >( pLuaArgument.GetNumber() );
	}

	return 0.0f;
}

bool CLuaFunctionDefinitions::GetMarkerColor( lua_State* pLuaVM, void* pUserData, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerColor", 1 ) )
	{
		ucRed	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		ucGreen	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		ucBlue	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

int CLuaFunctionDefinitions::GetMarkerTarget( lua_State* pLuaVM, void* pUserData, float& fX, float& fY, float& fZ )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerTarget", 1 ) )
	{
		fX	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -3 ) )->GetNumber() );
		fY	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -2 ) )->GetNumber() );
		fZ	= static_cast< unsigned char >( ( new CLuaArgument( pLuaVM, -1 ) )->GetNumber() );

		return true;
	}

	return false;
}

const char* CLuaFunctionDefinitions::GetMarkerIcon( lua_State* pLuaVM, void* pUserData )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );

	if( pLuaArguments.Call( pLuaVM, "getMarkerIcon", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetString();
	}

	return 0;
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

bool CLuaFunctionDefinitions::SetMarkerColor( lua_State* pLuaVM, void* pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushNumber( ucRed );
	pLuaArguments.PushNumber( ucGreen );
	pLuaArguments.PushNumber( ucBlue );

	if( pLuaArguments.Call( pLuaVM, "setMarkerColor", 1 ) )
	{
		CLuaArgument pLuaArgument( pLuaVM, -1 );

		return pLuaArgument.GetBoolean();
	}

	return false;
}

bool CLuaFunctionDefinitions::SetMarkerTarget( lua_State* pLuaVM, void* pUserData, void* pTarget )
{
	CLuaArguments pLuaArguments;

	pLuaArguments.PushUserData( pUserData );
	pLuaArguments.PushUserData( pTarget );

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
