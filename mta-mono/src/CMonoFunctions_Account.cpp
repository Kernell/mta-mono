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
			return pResource->GetElementManager()->Create( nullptr, pUserData )->GetMonoObject();
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
			return pResource->GetDomain()->NewArray( **pResource->GetDomain()->GetMTALib()->GetClass( "Account" ), pLuaTable );
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

		PVOID pUserData = CLuaFunctionDefinitions::GetAccountPlayer( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->GetMonoObject();
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

		if( CLuaFunctionDefinitions::IsGuestAccount( pResource->GetLua(), pElement->GetLuaUserdata(), bIsGuest ) )
		{
			return bIsGuest;
		}
	}

	return false;
}

MonoObject* CMonoFunctions::Account::GetData( TElement pAccount, MonoString* msKey )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szKey = mono_string_to_utf8( msKey );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		CLuaArgument pLuaArgument = CLuaFunctionDefinitions::GetAccountData( pResource->GetLua(), pElement->GetLuaUserdata(), szKey );

		CMonoCorlib* pCorlib = pResource->GetDomain()->GetCorlib();

		eLuaType iLuaType = pLuaArgument.GetType();

		switch( iLuaType )
		{
			case eLuaType::Boolean:
			{
				bool bValue = pLuaArgument.GetBoolean();

				return pCorlib->Class[ "boolean" ]->Box( &bValue );
			}
			case eLuaType::Number:
			{
				double dValue = pLuaArgument.GetNumber();

				return pCorlib->Class[ "double" ]->Box( &dValue );
			}
			case eLuaType::String:
			{
				const char* szString = pLuaArgument.GetString();

				return reinterpret_cast< MonoObject* >( pResource->GetDomain()->NewString( szString ) );
			}
			case eLuaType::Userdata:
			case eLuaType::LightUserdata:
			{
				DWORD pUserData = reinterpret_cast< DWORD >( pLuaArgument.GetLightUserData() );

				return pCorlib->Class[ "uint32" ]->Box( &pUserData );
			}
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Account::GetSerial( TElement pAccount )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strSerial;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		if( CLuaFunctionDefinitions::GetAccountSerial( pResource->GetLua(), pElement->GetLuaUserdata(), strSerial ) )
		{
			return pResource->GetDomain()->NewString( strSerial );
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Account::GetBySerial( MonoString* msSerial )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const string strSerial = mono_string_to_utf8( msSerial );

		CLuaArgumentsVector pLuaTable = CLuaFunctionDefinitions::GetAccountsBySerial( pResource->GetLua(), strSerial );

		if( pLuaTable.size() > 0 )
		{
			return pResource->GetDomain()->NewArray( **pResource->GetDomain()->GetMTALib()->GetClass( "Account" ), pLuaTable );
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
			return pResource->GetElementManager()->Create( nullptr, pUserData )->GetMonoObject();
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

		return CLuaFunctionDefinitions::RemoveAccount( pResource->GetLua(), pElement->GetLuaUserdata() );
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

		return CLuaFunctionDefinitions::SetAccountPassword( pResource->GetLua(), pElement->GetLuaUserdata(), szPassword );
	}

	return false;
}

bool CMonoFunctions::Account::SetData( TElement pAccount, MonoString* msKey, MonoObject* pObject )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pAccount );

		const char* szKey	= mono_string_to_utf8( msKey );

		CLuaArgument pArgument;

		MonoClass* pClass = mono_object_get_class( pObject );

		ASSERT( pClass );

		MonoType* pType = mono_class_get_type( pClass );

		ASSERT( pType );

		int iType = mono_type_get_type( pType );

		//CMonoObject::GetValue( pObject );

		return CLuaFunctionDefinitions::SetAccountData( pResource->GetLua(), pElement->GetLuaUserdata(), szKey, &pArgument );
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

		return CLuaFunctionDefinitions::CopyAccountData( pResource->GetLua(), pElement->GetLuaUserdata(), pFromElement->GetLuaUserdata() );
	}

	return false;
}
