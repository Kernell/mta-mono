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