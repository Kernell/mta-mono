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

// Resource funcs
void CMonoFunctions::Resource::Ctor( TElement pThis, MonoString* msResourceName, MonoString* msOrganizationalDir )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szResourceName		= mono_string_to_utf8( msResourceName );
		const char* szOrganizationalDir	= mono_string_to_utf8( msOrganizationalDir );

		PVOID pUserData = CLuaFunctionDefinitions::CreateResource( pResource->GetLua(), szResourceName, szOrganizationalDir );

		ASSERT( pUserData );

		pResource->GetElementManager()->Create( pThis, pUserData );
	}
}

TElement CMonoFunctions::Resource::Copy( TElement pThis, MonoString* msNewResourceName, MonoString* msOrganizationalDir )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szResourceName		= mono_string_to_utf8( msNewResourceName );
		const char* szOrganizationalDir	= mono_string_to_utf8( msOrganizationalDir );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::CopyResource( pResource->GetLua(), pElement->GetLuaUserdata(), szResourceName, szOrganizationalDir );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Resource::GetRootElement( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetResourceRootElement( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Resource::GetMapRootElement( TElement pThis, MonoString* msMap )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szMap = mono_string_to_utf8( msMap );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetResourceMapRootElement( pResource->GetLua(), pElement->GetLuaUserdata(), szMap );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Resource::GetDynamicElementRoot( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetResourceDynamicElementRoot( pResource->GetLua(), pElement->GetLuaUserdata() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Resource::RemoveFile( TElement pThis, MonoString* msFilename )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szFileName = mono_string_to_utf8( msFilename );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::RemoveResourceFile( pResource->GetLua(), pElement->GetLuaUserdata(), szFileName );
	}

	return false;
}

TElement CMonoFunctions::Resource::GetFromName( MonoString* msResourceName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szResourceName = mono_string_to_utf8( msResourceName );
		
		PVOID pUserData = CLuaFunctionDefinitions::GetResourceFromName( pResource->GetLua(), szResourceName );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return false;
}

MonoString* CMonoFunctions::Resource::GetInfo( TElement pThis, MonoString* msAttribute )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szAttribute = mono_string_to_utf8( msAttribute );

		string strOutInfo;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetResourceInfo( pResource->GetLua(), pElement->GetLuaUserdata(), szAttribute, strOutInfo ) )
		{
			return pResource->GetDomain()->NewString( strOutInfo );
		}
	}

	return nullptr;
}

unsigned int CMonoFunctions::Resource::GetLastStartTime( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiTime;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetResourceLastStartTime( pResource->GetLua(), pElement->GetLuaUserdata(), uiTime ) )
		{
			return uiTime;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Resource::GetLoadFailureReason( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutReason;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetResourceLoadFailureReason( pResource->GetLua(), pElement->GetLuaUserdata(), strOutReason ) )
		{
			return pResource->GetDomain()->NewString( strOutReason );
		}
	}

	return nullptr;
}

unsigned int CMonoFunctions::Resource::GetLoadTime( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned int uiTime;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetResourceLoadTime( pResource->GetLua(), pElement->GetLuaUserdata(), uiTime ) )
		{
			return uiTime;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Resource::GetName( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOut;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetResourceName( pResource->GetLua(), pElement->GetLuaUserdata(), strOut ) )
		{
			return pResource->GetDomain()->NewString( strOut );
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Resource::GetResources( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CLuaArgumentsVector pLuaTable = CLuaFunctionDefinitions::GetResources( pResource->GetLua() );

		if( pLuaTable.size() > 0 )
		{
			return pResource->GetDomain()->NewArray( **pResource->GetDomain()->GetMTALib()->GetClass( "Resource" ), pLuaTable );
		}
	}

	return nullptr;
}

MonoString* CMonoFunctions::Resource::GetState( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOut;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetResourceState( pResource->GetLua(), pElement->GetLuaUserdata(), strOut ) )
		{
			return pResource->GetDomain()->NewString( strOut );
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Resource::GetCurrent( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		PVOID pUserData = CLuaFunctionDefinitions::GetThisResource( pResource->GetLua() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->GetMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Resource::Refresh( bool refreshAll )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		return CLuaFunctionDefinitions::RefreshResources( pResource->GetLua(), refreshAll );
	}

	return nullptr;
}

bool CMonoFunctions::Resource::RemoveDefaultSetting( TElement pThis, MonoString* msSettingName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szSettingName = mono_string_to_utf8( msSettingName );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::RemoveResourceDefaultSetting( pResource->GetLua(), pElement->GetLuaUserdata(), szSettingName );
	}

	return false;
}

bool CMonoFunctions::Resource::Start( TElement pThis, bool persistent, bool startIncludedResources, bool loadServerConfigs, bool loadMaps, bool loadServerScripts, bool loadHTML, bool loadClientConfigs, bool loadClientScripts, bool loadFiles )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::StartResource( pResource->GetLua(), pElement->GetLuaUserdata(), persistent, startIncludedResources, loadServerConfigs, loadMaps, loadServerScripts, loadHTML, loadClientConfigs, loadClientScripts, loadFiles );
	}

	return false;
}

bool CMonoFunctions::Resource::Restart( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::RestartResource( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Resource::Stop( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::StopResource( pResource->GetLua(), pElement->GetLuaUserdata() );
	}

	return false;
}

bool CMonoFunctions::Resource::SetDefaultSetting( TElement pThis, MonoString* msSettingName, MonoString* msSettingValue )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szSettingName	= mono_string_to_utf8( msSettingName );
		const char* szSettingValue	= mono_string_to_utf8( msSettingValue );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetResourceDefaultSetting( pResource->GetLua(), pElement->GetLuaUserdata(), szSettingName, szSettingValue );
	}

	return false;
}

bool CMonoFunctions::Resource::SetInfo( TElement pThis, MonoString* msAttribute, MonoString* msValue )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szAttribute	= mono_string_to_utf8( msAttribute );
		const char* szValue		= mono_string_to_utf8( msValue );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetResourceInfo( pResource->GetLua(), pElement->GetLuaUserdata(), szAttribute, szValue );
	}

	return false;
}

bool CMonoFunctions::Resource::Rename( MonoString* msResourceName, MonoString* msNewResourceName, MonoString* msOrganizationalPath )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szResourceName			= mono_string_to_utf8( msResourceName );
		const char* szNewResourceName		= mono_string_to_utf8( msNewResourceName );
		const char* szOrganizationalPath	= mono_string_to_utf8( msOrganizationalPath );

		return CLuaFunctionDefinitions::RenameResource( pResource->GetLua(), szResourceName, szNewResourceName, szOrganizationalPath );
	}

	return false;
}

bool CMonoFunctions::Resource::Delete( MonoString* msResourceName )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szResourceName = mono_string_to_utf8( msResourceName );

		return CLuaFunctionDefinitions::DeleteResource( pResource->GetLua(), szResourceName );
	}

	return false;
}

bool CMonoFunctions::Resource::UpdateACLRequest( TElement pThis, MonoString* msRightName, bool bAccess, MonoString* msByWho )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szRightName = mono_string_to_utf8( msRightName );
		const char* szByWho		= mono_string_to_utf8( msByWho );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::UpdateResourceACLRequest( pResource->GetLua(), pElement->GetLuaUserdata(), szRightName, bAccess, szByWho );
	}

	return false;
}
