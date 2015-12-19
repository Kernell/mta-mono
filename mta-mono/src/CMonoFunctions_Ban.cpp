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

DWORD CMonoFunctions::Ban::Add( MonoString* msIP, MonoString* msUsername, MonoString* msSerial, DWORD pResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban )
{
	if( RESOURCE )
	{
		string
			strIP( mono_string_to_utf8( msIP ) ),
			strUsername( mono_string_to_utf8( msUsername ) ),
			strSerial( mono_string_to_utf8( msSerial ) ),
			strResponsible( mono_string_to_utf8( msResponsible ) ),
			strReason( mono_string_to_utf8( msReason ) );

		return (DWORD)CLuaFunctionDefinitions::AddBan( RESOURCE->GetLua(), strIP, strUsername, strSerial, (void*)pResponsible, strResponsible, strReason, iUnban );
	}

	return NULL;
}

bool CMonoFunctions::Ban::Remove( DWORD pBan, DWORD pResponsible )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::RemoveBan( RESOURCE->GetLua(), (void*)pBan, (void*)pResponsible );
	}

	return false;
}


bool CMonoFunctions::Ban::Reload( void )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::ReloadBanList( RESOURCE->GetLua() );
	}

	return false;
}


MonoString* CMonoFunctions::Ban::GetIP( DWORD pBan )
{
	if( RESOURCE )
	{
		string strIP;

		if( CLuaFunctionDefinitions::GetBanIP( RESOURCE->GetLua(), (void*)pBan, strIP ) )
		{
			return RESOURCE->GetDomain()->NewString( strIP );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetSerial( DWORD pBan )
{
	if( RESOURCE )
	{
		string strSerial;

		if( CLuaFunctionDefinitions::GetBanSerial( RESOURCE->GetLua(), (void*)pBan, strSerial ) )
		{
			return RESOURCE->GetDomain()->NewString( strSerial );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetUsername( DWORD pBan )
{
	if( RESOURCE )
	{
		string strUsername;

		if( CLuaFunctionDefinitions::GetBanUsername( RESOURCE->GetLua(), (void*)pBan, strUsername ) )
		{
			return RESOURCE->GetDomain()->NewString( strUsername );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetNick( DWORD pBan )
{
	if( RESOURCE )
	{
		string strNick;

		if( CLuaFunctionDefinitions::GetBanNick( RESOURCE->GetLua(), (void*)pBan, strNick ) )
		{
			return RESOURCE->GetDomain()->NewString( strNick );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetReason( DWORD pBan )
{
	if( RESOURCE )
	{
		string strReason;

		if( CLuaFunctionDefinitions::GetBanReason( RESOURCE->GetLua(), (void*)pBan, strReason ) )
		{
			return RESOURCE->GetDomain()->NewString( strReason );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Ban::GetAdmin( DWORD pBan )
{
	if( RESOURCE )
	{
		string strAdmin;

		if( CLuaFunctionDefinitions::GetBanAdmin( RESOURCE->GetLua(), (void*)pBan, strAdmin ) )
		{
			return RESOURCE->GetDomain()->NewString( strAdmin );
		}
	}

	return nullptr;
}


int CMonoFunctions::Ban::GetBanTime( DWORD pBan )
{
	if( RESOURCE )
	{
		time_t tTime;

		if( CLuaFunctionDefinitions::GetBanTime( RESOURCE->GetLua(), (void*)pBan, tTime ) )
		{
			return (int)tTime;
		}
	}

	return 0;
}

int CMonoFunctions::Ban::GetUnbanTime( DWORD pBan )
{
	if( RESOURCE )
	{
		time_t tTime;

		if( CLuaFunctionDefinitions::GetUnbanTime( RESOURCE->GetLua(), (void*)pBan, tTime ) )
		{
			return (int)tTime;
		}
	}

	return 0;
}


bool CMonoFunctions::Ban::SetUnbanTime( DWORD pBan, int time )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetUnbanTime( RESOURCE->GetLua(), (void*)pBan, time );
	}

	return false;
}

bool CMonoFunctions::Ban::SetReason( DWORD pBan, MonoString* msReason )
{
	if( RESOURCE )
	{
		string strReason( mono_string_to_utf8( msReason ) );

		return CLuaFunctionDefinitions::SetBanReason( RESOURCE->GetLua(), (void*)pBan, strReason );
	}

	return false;
}

bool CMonoFunctions::Ban::SetAdmin( DWORD pBan, MonoString* msAdminName )
{
	if( RESOURCE )
	{
		string strAdmin( mono_string_to_utf8( msAdminName ) );

		return CLuaFunctionDefinitions::SetBanAdmin( RESOURCE->GetLua(), (void*)pBan, strAdmin );
	}

	return false;
}
