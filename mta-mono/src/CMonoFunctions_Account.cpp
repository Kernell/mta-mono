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
#include "CMonoFunctions.h"

// Account get funcs
DWORD CMonoFunctions::Account::Get( MonoString* msName, MonoString* msPassword )
{
	if( RESOURCE )
	{
		const char* szName		= mono_string_to_utf8( msName );
		const char* szPassword	= mono_string_to_utf8( msPassword );

		return (DWORD)CLuaFunctionDefinitions::GetAccount( RESOURCE->GetLua(), szName, szPassword );
	}

	return NULL;
}

MonoArray* CMonoFunctions::Account::GetAll( void )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaTable = CLuaFunctionDefinitions::GetAccounts( RESOURCE->GetLua() );

		return RESOURCE->GetDomain()->NewArray<DWORD, LUA_TLIGHTUSERDATA>( mono_get_uint32_class(), pLuaTable );
	}

	return nullptr;
}

DWORD CMonoFunctions::Account::GetPlayer( DWORD pAccount )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetAccountPlayer( RESOURCE->GetLua(), (void*)pAccount );
	}

	return NULL;
}

bool CMonoFunctions::Account::IsGuest( DWORD pAccount )
{
	if( RESOURCE )
	{
		bool bIsGuest;

		if( CLuaFunctionDefinitions::IsGuestAccount( RESOURCE->GetLua(), (void*)pAccount, bIsGuest ) )
		{
			return bIsGuest;
		}
	}

	return false;
}

MonoString* CMonoFunctions::Account::GetSerial( DWORD pAccount )
{
	if( RESOURCE )
	{
		string strSerial;

		if( CLuaFunctionDefinitions::GetAccountSerial( RESOURCE->GetLua(), (void*)pAccount, strSerial ) )
		{
			return RESOURCE->GetDomain()->NewString( strSerial );
		}
	}

	return nullptr;
}

// Account set funcs
DWORD CMonoFunctions::Account::Add( MonoString* msName, MonoString* msPassword )
{
	if( RESOURCE )
	{
		const char* szName		= mono_string_to_utf8( msName );
		const char* szPassword	= mono_string_to_utf8( msPassword );

		return (DWORD)CLuaFunctionDefinitions::AddAccount( RESOURCE->GetLua(), szName, szPassword );
	}

	return NULL;
}

bool CMonoFunctions::Account::Remove( DWORD pAccount )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RemoveAccount( RESOURCE->GetLua(), (void*)pAccount );
	}

	return false;
}

bool CMonoFunctions::Account::SetPassword( DWORD pAccount, MonoString* msPassword )
{
	if( RESOURCE )
	{
		const char* szPassword	= mono_string_to_utf8( msPassword );

		return CLuaFunctionDefinitions::SetAccountPassword( RESOURCE->GetLua(), (void*)pAccount, szPassword );
	}

	return false;
}

bool CMonoFunctions::Account::CopyData( DWORD pAccount, DWORD pFromAccount )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::CopyAccountData( RESOURCE->GetLua(), (void*)pAccount, (void*)pFromAccount );
	}

	return false;
}
