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

TElement CMonoFunctions::Ban::Add( MonoString* msIP, MonoString* msUsername, MonoString* msSerial, TElement pResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string
			strIP			( mono_string_to_utf8( msIP ) ),
			strUsername		( mono_string_to_utf8( msUsername ) ),
			strSerial		( mono_string_to_utf8( msSerial ) ),
			strResponsible	( mono_string_to_utf8( msResponsible ) ),
			strReason		( mono_string_to_utf8( msReason ) );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pResponsible );

		PVOID pUserData = CLuaFunctionDefinitions::AddBan( pResource->GetLua(), strIP, strUsername, strSerial, pElement->ToLuaUserData(), strResponsible, strReason, iUnban );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Ban::Remove( TElement pBan, TElement pResponsible )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );
		CElement* pResponsibleElement = pResource->GetElementManager()->GetFromList( pResponsible );

		return CLuaFunctionDefinitions::RemoveBan( pResource->GetLua(), pElement->ToLuaUserData(), pResponsibleElement->ToLuaUserData() );
	}

	return false;
}


bool CMonoFunctions::Ban::Reload( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::ReloadBanList( pResource->GetLua() );
	}

	return false;
}


MonoString* CMonoFunctions::Ban::GetIP( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strIP;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanIP( pResource->GetLua(), pElement->ToLuaUserData(), strIP ) )
		{
			return pResource->GetDomain()->NewString( strIP );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetSerial( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strSerial;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanSerial( pResource->GetLua(), pElement->ToLuaUserData(), strSerial ) )
		{
			return pResource->GetDomain()->NewString( strSerial );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetUsername( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strUsername;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanUsername( pResource->GetLua(), pElement->ToLuaUserData(), strUsername ) )
		{
			return pResource->GetDomain()->NewString( strUsername );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetNick( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strNick;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanNick( pResource->GetLua(), pElement->ToLuaUserData(), strNick ) )
		{
			return pResource->GetDomain()->NewString( strNick );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetReason( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strReason;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanReason( pResource->GetLua(), pElement->ToLuaUserData(), strReason ) )
		{
			return pResource->GetDomain()->NewString( strReason );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetAdmin( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strAdmin;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanAdmin( pResource->GetLua(), pElement->ToLuaUserData(), strAdmin ) )
		{
			return pResource->GetDomain()->NewString( strAdmin );
		}
	}

	return nullptr;
}


int CMonoFunctions::Ban::GetBanTime( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		time_t tTime;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetBanTime( pResource->GetLua(), pElement->ToLuaUserData(), tTime ) )
		{
			return (int)tTime;
		}
	}

	return 0;
}

int CMonoFunctions::Ban::GetUnbanTime( TElement pBan )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		time_t tTime;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		if( CLuaFunctionDefinitions::GetUnbanTime( pResource->GetLua(), pElement->ToLuaUserData(), tTime ) )
		{
			return (int)tTime;
		}
	}

	return 0;
}


bool CMonoFunctions::Ban::SetUnbanTime( TElement pBan, int time )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		return CLuaFunctionDefinitions::SetUnbanTime( pResource->GetLua(), pElement->ToLuaUserData(), time );
	}

	return false;
}

bool CMonoFunctions::Ban::SetReason( TElement pBan, MonoString* msReason )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strReason( mono_string_to_utf8( msReason ) );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		return CLuaFunctionDefinitions::SetBanReason( pResource->GetLua(), pElement->ToLuaUserData(), strReason );
	}

	return false;
}

bool CMonoFunctions::Ban::SetAdmin( TElement pBan, MonoString* msAdminName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strAdmin( mono_string_to_utf8( msAdminName ) );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pBan );

		return CLuaFunctionDefinitions::SetBanAdmin( pResource->GetLua(), pElement->ToLuaUserData(), strAdmin );
	}

	return false;
}
