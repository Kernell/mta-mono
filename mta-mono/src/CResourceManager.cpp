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

#include "CResourceManager.h"

CResourceManager::CResourceManager( void )
{
	mono_set_dirs( "mods/deathmatch/mono/lib", "mods/deathmatch/mono/etc" );

	this->m_pMonoDomain = mono_jit_init_version( "Mono Root", "v4.0.30319" );

	CMonoFunctions::AddInternals();
}

CResourceManager::~CResourceManager( void )
{
	for( auto iter : this->m_List )
	{
		delete iter;
	}

	mono_jit_cleanup( this->m_pMonoDomain );
}

CResource* CResourceManager::Create( lua_State* luaVM, string strName )
{
	if( !this->GetFromList( luaVM ) )
	{
		string sPath( "mods/deathmatch/resources/[ire]/" + strName + "/" + strName + ".dll" );

		struct stat buf;

		if( stat( sPath.c_str(), &buf ) == -1 )
		{
			return nullptr;
		}

		CResource *pResource = new CResource( luaVM, strName );

		this->AddToList( pResource );

		return pResource;
	}

	return nullptr;
}

void CResourceManager::AddToList( CResource* pResource )
{
	this->m_List.push_back( pResource );
}

CResource* CResourceManager::GetFromList( lua_State* pLuaVM )
{
	for( auto iter : this->m_List )
	{
		if( iter->m_pLuaVM == pLuaVM )
		{
			return iter;
		}
	}

	return nullptr;
}

CResource* CResourceManager::GetFromList( MonoDomain* pDomain )
{
	for( auto iter : this->m_List )
	{
		if( iter->m_pMonoDomain == pDomain )
		{
			return iter;
		}
	}

	return nullptr;
}

void CResourceManager::RemoveFromList( CResource* pResource )
{
	if( !this->m_List.empty() )
	{
		this->m_List.remove( pResource );
	}
}
	
void CResourceManager::DoPulse( void )
{
	for( auto iter : this->m_List )
	{
		iter->DoPulse();
	}
}