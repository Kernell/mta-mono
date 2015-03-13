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

#include "CMonoFunctions.h"

// Resource funcs
DWORD CMonoFunctions::Resource::Create( MonoString* msResourceName, MonoString* msOrganizationalDir )
{
	if( RESOURCE )
	{
		const char* szResourceName		= mono_string_to_utf8( msResourceName );
		const char* szOrganizationalDir	= mono_string_to_utf8( msOrganizationalDir );

		return (DWORD)CLuaFunctionDefinitions::CreateResource( RESOURCE->GetLua(), szResourceName, szOrganizationalDir );
	}

	return NULL;
}

DWORD CMonoFunctions::Resource::Copy( DWORD pResource, MonoString* msNewResourceName, MonoString* msOrganizationalDir )
{
	if( RESOURCE )
	{
		const char* szResourceName		= mono_string_to_utf8( msNewResourceName );
		const char* szOrganizationalDir	= mono_string_to_utf8( msOrganizationalDir );

		return (DWORD)CLuaFunctionDefinitions::CopyResource( RESOURCE->GetLua(), (void*)pResource, szResourceName, szOrganizationalDir );
	}

	return NULL;
}

DWORD CMonoFunctions::Resource::GetRootElement( DWORD pResource )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetResourceRootElement( RESOURCE->GetLua(), (void*)pResource );
	}

	return NULL;
}

DWORD CMonoFunctions::Resource::GetMapRootElement( DWORD pResource, MonoString* msMap )
{
	if( RESOURCE )
	{
		const char* szMap = mono_string_to_utf8( msMap );

		return (DWORD)CLuaFunctionDefinitions::GetResourceMapRootElement( RESOURCE->GetLua(), (void*)pResource, szMap );
	}

	return NULL;
}

DWORD CMonoFunctions::Resource::GetDynamicElementRoot( DWORD pResource )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetResourceDynamicElementRoot( RESOURCE->GetLua(), (void*)pResource );
	}

	return NULL;
}

bool CMonoFunctions::Resource::RemoveFile( DWORD pResource, MonoString* msFilename )
{
	if( RESOURCE )
	{
		const char* szFileName = mono_string_to_utf8( msFilename );

		return CLuaFunctionDefinitions::RemoveResourceFile( RESOURCE->GetLua(), (void*)pResource, szFileName );
	}

	return false;
}

DWORD CMonoFunctions::Resource::GetFromName( MonoString* msResourceName )
{
	if( RESOURCE )
	{
		const char* szResourceName = mono_string_to_utf8( msResourceName );

		return (DWORD)CLuaFunctionDefinitions::GetResourceFromName( RESOURCE->GetLua(), szResourceName );
	}

	return false;
}

MonoString* CMonoFunctions::Resource::GetInfo( DWORD pResource, MonoString* msAttribute )
{
	if( RESOURCE )
	{
		const char* szAttribute = mono_string_to_utf8( msAttribute );

		string strOutInfo;

		if( CLuaFunctionDefinitions::GetResourceInfo( RESOURCE->GetLua(), (void*)pResource, szAttribute, strOutInfo ) )
		{
			return RESOURCE->NewString( strOutInfo );
		}
	}

	return NULL;
}

unsigned int CMonoFunctions::Resource::GetLastStartTime( DWORD pResource )
{
	if( RESOURCE )
	{
		unsigned int uiTime;

		if( CLuaFunctionDefinitions::GetResourceLastStartTime( RESOURCE->GetLua(), (void*)pResource, uiTime ) )
		{
			return uiTime;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Resource::GetLoadFailureReason( DWORD pResource )
{
	if( RESOURCE )
	{
		string strOutReason;

		if( CLuaFunctionDefinitions::GetResourceLoadFailureReason( RESOURCE->GetLua(), (void*)pResource, strOutReason ) )
		{
			return RESOURCE->NewString( strOutReason );
		}
	}

	return NULL;
}

unsigned int CMonoFunctions::Resource::GetLoadTime( DWORD pResource )
{
	if( RESOURCE )
	{
		unsigned int uiTime;

		if( CLuaFunctionDefinitions::GetResourceLoadTime( RESOURCE->GetLua(), (void*)pResource, uiTime ) )
		{
			return uiTime;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Resource::GetName( DWORD pResource )
{
	if( RESOURCE )
	{
		string strOut;

		if( CLuaFunctionDefinitions::GetResourceName( RESOURCE->GetLua(), (void*)pResource, strOut ) )
		{
			return RESOURCE->NewString( strOut );
		}
	}

	return NULL;
}

MonoArray* CMonoFunctions::Resource::GetResources( void )
{
	if( RESOURCE )
	{
		CLuaArguments* pLuaTable = CLuaFunctionDefinitions::GetResources( RESOURCE->GetLua() );

		return RESOURCE->NewArray<DWORD, LUA_TLIGHTUSERDATA>( mono_get_uint32_class(), pLuaTable );
	}

	return NULL;
}

MonoString* CMonoFunctions::Resource::GetState( DWORD pResource )
{
	if( RESOURCE )
	{
		string strOut;

		if( CLuaFunctionDefinitions::GetResourceState( RESOURCE->GetLua(), (void*)pResource, strOut ) )
		{
			return RESOURCE->NewString( strOut );
		}
	}

	return NULL;
}

DWORD CMonoFunctions::Resource::GetCurrent( void )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetThisResource( RESOURCE->GetLua() );
	}

	return NULL;
}

bool CMonoFunctions::Resource::Refresh( bool refreshAll )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RefreshResources( RESOURCE->GetLua(), refreshAll );
	}

	return NULL;
}

bool CMonoFunctions::Resource::RemoveDefaultSetting( DWORD pResource, MonoString* msSettingName )
{
	if( RESOURCE )
	{
		const char* szSettingName = mono_string_to_utf8( msSettingName );

		return CLuaFunctionDefinitions::RemoveResourceDefaultSetting( RESOURCE->GetLua(), (void*)pResource, szSettingName );
	}

	return false;
}

bool CMonoFunctions::Resource::Start( DWORD pResource, bool persistent, bool startIncludedResources, bool loadServerConfigs, bool loadMaps, bool loadServerScripts, bool loadHTML, bool loadClientConfigs, bool loadClientScripts, bool loadFiles )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::StartResource( RESOURCE->GetLua(), (void*)pResource, persistent, startIncludedResources, loadServerConfigs, loadMaps, loadServerScripts, loadHTML, loadClientConfigs, loadClientScripts, loadFiles );
	}

	return false;
}

bool CMonoFunctions::Resource::Restart( DWORD pResource )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::RestartResource( RESOURCE->GetLua(), (void*)pResource );
	}

	return false;
}

bool CMonoFunctions::Resource::Stop( DWORD pResource )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::StopResource( RESOURCE->GetLua(), (void*)pResource );
	}

	return false;
}

bool CMonoFunctions::Resource::SetDefaultSetting( DWORD pResource, MonoString* msSettingName, MonoString* msSettingValue )
{
	if( RESOURCE )
	{
		const char* szSettingName	= mono_string_to_utf8( msSettingName );
		const char* szSettingValue	= mono_string_to_utf8( msSettingValue );

		return CLuaFunctionDefinitions::SetResourceDefaultSetting( RESOURCE->GetLua(), (void*)pResource, szSettingName, szSettingValue );
	}

	return false;
}

bool CMonoFunctions::Resource::SetInfo( DWORD pResource, MonoString* msAttribute, MonoString* msValue )
{
	if( RESOURCE )
	{
		const char* szAttribute	= mono_string_to_utf8( msAttribute );
		const char* szValue		= mono_string_to_utf8( msValue );

		return CLuaFunctionDefinitions::SetResourceInfo( RESOURCE->GetLua(), (void*)pResource, szAttribute, szValue );
	}

	return false;
}

bool CMonoFunctions::Resource::Rename( MonoString* msResourceName, MonoString* msNewResourceName, MonoString* msOrganizationalPath )
{
	if( RESOURCE )
	{
		const char* szResourceName			= mono_string_to_utf8( msResourceName );
		const char* szNewResourceName		= mono_string_to_utf8( msNewResourceName );
		const char* szOrganizationalPath	= mono_string_to_utf8( msOrganizationalPath );

		return CLuaFunctionDefinitions::RenameResource( RESOURCE->GetLua(), szResourceName, szNewResourceName, szOrganizationalPath );
	}

	return false;
}

bool CMonoFunctions::Resource::Delete( MonoString* msResourceName )
{
	if( RESOURCE )
	{
		const char* szResourceName = mono_string_to_utf8( msResourceName );

		return CLuaFunctionDefinitions::DeleteResource( RESOURCE->GetLua(), szResourceName );
	}

	return false;
}

bool CMonoFunctions::Resource::UpdateACLRequest( DWORD pResource, MonoString* msRightName, bool bAccess, MonoString* msByWho )
{
	if( RESOURCE )
	{
		const char* szRightName = mono_string_to_utf8( msRightName );
		const char* szByWho		= mono_string_to_utf8( msByWho );

		return CLuaFunctionDefinitions::UpdateResourceACLRequest( RESOURCE->GetLua(), (void*)pResource, szRightName, bAccess, szByWho );
	}

	return false;
}
