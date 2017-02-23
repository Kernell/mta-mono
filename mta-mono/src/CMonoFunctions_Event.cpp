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
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szName = mono_string_to_utf8( msName );

		if( CLuaFunctionDefinitions::AddEvent( pResource->GetLua(), szName, bAllowRemoteTrigger ) )
		{
			return pResource->AddEvent( szName, "root" );
		}
	}

	return false;
}

bool CMonoFunctions::Event::AddHandler( MonoString* msName, TElement pAttachedTo, MonoObject* pDelegate, bool bPropagated, MonoString* msEventPriority )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		if( !pAttachedTo )
		{
			pResource->ErrorPrintf( "Invalid argument #2 in method 'Event::AddHandler'\n" );

			return false;
		}

		if( !pDelegate )
		{
			pResource->ErrorPrintf( "Invalid argument #3 in method 'Event::AddHandler'\n" );

			return false;
		}
		
		string strEventName = mono_string_to_utf8( msName );

		if( strEventName.length() == 0 )
		{
			pResource->ErrorPrintf( "Invalid argument #1 in method 'Event::AddHandler'\n" );

			return false;
		}

		string strEventPriority = mono_string_to_utf8( msEventPriority );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAttachedTo );

		return pResource->GetEventManager()->Add( strEventName, pElement, pDelegate, bPropagated, strEventPriority );
	}

	return false;
}

bool CMonoFunctions::Event::RemoveHandler( MonoString* msName, TElement pAttachedTo, MonoObject* pDelegate )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		if( !pAttachedTo )
		{
			pResource->ErrorPrintf( "Invalid argument #2 in method 'Event::AddHandler'\n" );

			return false;
		}

		if( !pDelegate )
		{
			pResource->ErrorPrintf( "Invalid argument #3 in method 'Event::AddHandler'\n" );

			return false;
		}
		
		string strEventName = mono_string_to_utf8( msName );

		if( strEventName.length() == 0 )
		{
			pResource->ErrorPrintf( "Invalid argument #1 in method 'Event::RemoveEvent'\n" );

			return false;
		}

		CElement* pElement = pResource->GetElementManager()->GetFromList( pAttachedTo );

		return pResource->GetEventManager()->Delete( strEventName, pElement, pDelegate );
	}

	return false;
}

bool CMonoFunctions::Event::Trigger( MonoString* msName, TElement pArgElement, MonoArray* mpArguments )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szEventName = mono_string_to_utf8( msName );

		CLuaArguments Arguments = CMonoInterface::MonoArrayToLuaArguments( mpArguments, pResource );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pArgElement );

		return CLuaFunctionDefinitions::TriggerEvent( pResource->GetLua(), szEventName, pElement->GetLuaUserdata(), Arguments );
	}

	return false;
}

bool CMonoFunctions::Event::Cancel( bool bCancel, MonoString* msReason )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szReason = mono_string_to_utf8( msReason );

		return CLuaFunctionDefinitions::CancelEvent( pResource->GetLua(), bCancel, szReason );
	}

	return false;
}

bool CMonoFunctions::Event::WasCancelled( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::WasEventCancelled( pResource->GetLua() );
	}

	return false;
}

string CMonoFunctions::Event::GetCancelReason( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::GetCancelReason( pResource->GetLua() );
	}

	return string();
}

bool CMonoFunctions::Event::TriggerClient( TElement pSendTo, MonoString* msName, TElement pSource, MonoArray* mpArguments )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szEventName = mono_string_to_utf8( msName );

		CElement* pSendToElement = pResource->GetElementManager()->GetFromList( pSendTo );
		CElement* pSourceElement = pResource->GetElementManager()->GetFromList( pSource );

		CLuaArguments Arguments = CMonoInterface::MonoArrayToLuaArguments( mpArguments, pResource );

		return CLuaFunctionDefinitions::TriggerClientEvent( pResource->GetLua(), pSendToElement->GetLuaUserdata(), szEventName, pSourceElement->GetLuaUserdata(), Arguments );
	}

	return false;
}
