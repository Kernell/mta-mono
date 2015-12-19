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

bool CMonoFunctions::Event::Add( MonoString* msName, bool bAllowRemoteTrigger )
{
	if( RESOURCE )
	{
		const char* szName = mono_string_to_utf8( msName );

		if( CLuaFunctionDefinitions::AddEvent( RESOURCE->GetLua(), szName, bAllowRemoteTrigger ) )
		{
			return RESOURCE->AddEvent( szName, "root" );
		}
	}

	return false;
}

bool CMonoFunctions::Event::AddHandler( MonoString* msName, DWORD pUserData, MonoObject* pDelegate, bool bPropagated, MonoString* msEventPriority )
{
	if( RESOURCE )
	{
		if( !pUserData )
		{
			g_pModuleManager->ErrorPrintf( "Invalid argument #2 in method 'Event::AddHandler'\n" );

			return false;
		}

		if( !pDelegate )
		{
			g_pModuleManager->ErrorPrintf( "Invalid argument #3 in method 'Event::AddHandler'\n" );

			return false;
		}
		
		string strEventName = mono_string_to_utf8( msName );

		if( strEventName.length() == 0 )
		{
			g_pModuleManager->ErrorPrintf( "Invalid argument #1 in method 'Event::AddHandler'\n" );

			return false;
		}

		string strEventPriority = mono_string_to_utf8( msEventPriority );

		return RESOURCE->GetEventManager()->Add( strEventName, pUserData, pDelegate, bPropagated, strEventPriority );
	}

	return false;
}

bool CMonoFunctions::Event::RemoveHandler( MonoString* msName, DWORD pUserData, MonoObject* pDelegate )
{
	if( RESOURCE )
	{
		if( !pUserData )
		{
			g_pModuleManager->ErrorPrintf( "Invalid argument #2 in method 'Event::AddHandler'\n" );

			return false;
		}

		if( !pDelegate )
		{
			g_pModuleManager->ErrorPrintf( "Invalid argument #3 in method 'Event::AddHandler'\n" );

			return false;
		}
		
		string strEventName = mono_string_to_utf8( msName );

		if( strEventName.length() == 0 )
		{
			g_pModuleManager->ErrorPrintf( "Invalid argument #1 in method 'Event::RemoveEvent'\n" );

			return false;
		}

		return RESOURCE->GetEventManager()->Delete( strEventName, pUserData, pDelegate );
	}

	return false;
}

bool CMonoFunctions::Event::Trigger( MonoString* msName, DWORD pUserData, MonoArray* mpArguments )
{
	if( RESOURCE )
	{
		const char* szEventName = mono_string_to_utf8( msName );

		CLuaArguments Arguments = CMonoInterface::MonoArrayToLuaArguments( mpArguments );

		return CLuaFunctionDefinitions::TriggerEvent( RESOURCE->GetLua(), szEventName, (void*)pUserData, Arguments );
	}

	return false;
}

bool CMonoFunctions::Event::Cancel( bool bCancel, MonoString* msReason )
{
	if( RESOURCE )
	{
		const char* szReason = mono_string_to_utf8( msReason );

		return CLuaFunctionDefinitions::CancelEvent( RESOURCE->GetLua(), bCancel, szReason );
	}

	return false;
}

bool CMonoFunctions::Event::WasCancelled( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::WasEventCancelled( RESOURCE->GetLua() );
	}

	return false;
}

string CMonoFunctions::Event::GetCancelReason( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetCancelReason( RESOURCE->GetLua() );
	}

	return string();
}

bool CMonoFunctions::Event::TriggerClient( DWORD pSendTo, MonoString* msName, DWORD pSource, MonoArray* mpArguments )
{
	if( RESOURCE )
	{
		const char* szEventName = mono_string_to_utf8( msName );

		CLuaArguments Arguments = CMonoInterface::MonoArrayToLuaArguments( mpArguments );

		return CLuaFunctionDefinitions::TriggerClientEvent(  RESOURCE->GetLua(), (void*)pSendTo, szEventName, (void*)pSource, Arguments );
	}

	return false;
}
