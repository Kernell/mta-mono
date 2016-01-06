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
TElement CMonoFunctions::Account::Get( MonoString* msName, MonoString* msPassword )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szName		= mono_string_to_utf8( msName );
		const char* szPassword	= mono_string_to_utf8( msPassword );

		PVOID pUserData = CLuaFunctionDefinitions::GetAccount( pResource->GetLua(), szName, szPassword );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Account::GetAll( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CLuaArgumentsVector pLuaTable = CLuaFunctionDefinitions::GetAccounts( pResource->GetLua() );

		if( pLuaTable.size() > 0 )
		{
			return pResource->GetDomain()->NewElementArray( pResource->GetDomain()->GetMTALib()->GetClass( "Account" )->GetMonoPtr(), pLuaTable );
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Account::GetPlayer( TElement pAccount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		PVOID pUserData = CLuaFunctionDefinitions::GetAccountPlayer( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Account::IsGuest( TElement pAccount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bIsGuest;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		if( CLuaFunctionDefinitions::IsGuestAccount( pResource->GetLua(), pElement->ToLuaUserData(), bIsGuest ) )
		{
			return bIsGuest;
		}
	}

	return false;
}

MonoString* CMonoFunctions::Account::GetSerial( TElement pAccount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strSerial;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		if( CLuaFunctionDefinitions::GetAccountSerial( pResource->GetLua(), pElement->ToLuaUserData(), strSerial ) )
		{
			return pResource->GetDomain()->NewString( strSerial );
		}
	}

	return nullptr;
}

// Account set funcs
TElement CMonoFunctions::Account::Add( MonoString* msName, MonoString* msPassword )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szName		= mono_string_to_utf8( msName );
		const char* szPassword	= mono_string_to_utf8( msPassword );

		PVOID pUserData = CLuaFunctionDefinitions::AddAccount( pResource->GetLua(), szName, szPassword );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Account::Remove( TElement pAccount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		return CLuaFunctionDefinitions::RemoveAccount( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return false;
}

bool CMonoFunctions::Account::SetPassword( TElement pAccount, MonoString* msPassword )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szPassword	= mono_string_to_utf8( msPassword );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		return CLuaFunctionDefinitions::SetAccountPassword( pResource->GetLua(), pElement->ToLuaUserData(), szPassword );
	}

	return false;
}

bool CMonoFunctions::Account::CopyData( TElement pAccount, TElement pFromAccount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );
		CElement* pFromElement = pResource->GetElementManager()->GetFromList( pFromAccount );

		return CLuaFunctionDefinitions::CopyAccountData( pResource->GetLua(), pElement->ToLuaUserData(), pFromElement->ToLuaUserData() );
	}

	return false;
}
