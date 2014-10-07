/*********************************************************
*
*  Copyright � 2013, Innovation Roleplay Engine. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "CMonoFunctions.h"
#include "CMonoObject.h"

#include "CResource.h"
#include "CResourceManager.h"

extern ILuaModuleManager10	*g_pModuleManager;
extern CResourceManager	*g_pResourceManager;

#define RESOURCE g_pResourceManager->GetFromList( mono_domain_get() )

void CMonoFunctions::AddInternals( void )
{
	mono_add_internal_call( "MultiTheftAuto.Debug::Log",				CMonoFunctions::Debug::Log );
	mono_add_internal_call( "MultiTheftAuto.Debug::Info",				CMonoFunctions::Debug::Info );
	mono_add_internal_call( "MultiTheftAuto.Debug::Error",				CMonoFunctions::Debug::Error );
	mono_add_internal_call( "MultiTheftAuto.Native.Config::Get",		CMonoFunctions::Config::Get );
	mono_add_internal_call( "MultiTheftAuto.Native.Config::Set",		CMonoFunctions::Config::Set );
	mono_add_internal_call( "MultiTheftAuto.Native.Vehicle::Create",	CMonoFunctions::Vehicle::Create );
}

void CMonoFunctions::Debug::Log( MonoString *string )
{
	if( RESOURCE )
	{
		g_pModuleManager->Printf( "%s\n", mono_string_to_utf8( string ) );
	}
}

void CMonoFunctions::Debug::Info( MonoString *string )
{
	if( RESOURCE )
	{
		g_pModuleManager->DebugPrintf( RESOURCE->GetLua(), "%s\n", mono_string_to_utf8( string ) );
	}
}

void CMonoFunctions::Debug::Error( MonoString *string )
{
	if( RESOURCE )
	{
		

		g_pModuleManager->ErrorPrintf( "%s\n", mono_string_to_utf8( string ) );
	}
}

MonoString *CMonoFunctions::Config::Get( MonoString *msKey )
{
	if( RESOURCE )
	{
		string sValue = CLuaFunctionDefinitions::Get( RESOURCE->GetLua(), mono_string_to_utf8( msKey ) );

		return mono_string_new( mono_domain_get(), sValue.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

bool CMonoFunctions::Config::Set( MonoString *msKey, MonoString *msValue )
{
	if( RESOURCE )
	{
		string
			sKey	= mono_string_to_utf8( msKey ),
			sValue	= mono_string_to_utf8( msValue );

		return CLuaFunctionDefinitions::Set( RESOURCE->GetLua(), sKey, sValue );
	}

	return false;
}

MonoObject* CMonoFunctions::Vehicle::Create( int model, MonoObject* position, MonoObject* rotation, string &numberplate, bool direction, int variant1, int variant2 )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( position );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );
		
		CMonoObject pRotation( rotation );

		float fRX = pRotation.GetPropertyValue<float>( "X" );
		float fRY = pRotation.GetPropertyValue<float>( "Y" );
		float fRZ = pRotation.GetPropertyValue<float>( "Z" );

		void* pVehicle = CLuaFunctionDefinitions::CreateVehicle( RESOURCE->GetLua(), model, fX, fY, fZ, fRX, fRY, fRZ, numberplate, direction, variant1, variant2 );

		if( pVehicle )
		{

		}
	}
	
	return NULL;
}