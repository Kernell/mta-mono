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
#include "CResourceManager.h"

CResourceManager::CResourceManager( CModule* pModule, CMonoInterface* pMono )
{
	this->m_pModule = pModule;
	this->m_pMono = pMono;
}

CResourceManager::~CResourceManager( void )
{
	for( auto iter : this->m_List )
	{
		delete iter;
	}

	this->m_pModule = nullptr;
}

void CResourceManager::ResourceStopping( lua_State* pLuaVM )
{
	CResource* pResource = this->GetFromList( pLuaVM );

	if( pResource )
	{
		pResource->OnStopping();
	}
}

void CResourceManager::ResourceStopped( lua_State* pLuaVM )
{
	CResource* pResource = this->GetFromList( pLuaVM );

	if( pResource )
	{
		this->RemoveFromList( pResource );

		delete pResource;
	}
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

		CResource *pResource = new CResource( this, luaVM, strName );

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
	for( const auto& iter : this->m_List )
	{
		if( iter->GetLua() == pLuaVM )
		{
			return iter;
		}
	}

	return nullptr;
}

CResource* CResourceManager::GetFromList( MonoDomain* pDomain )
{
	for( const auto& iter : this->m_List )
	{
		if( **iter->GetDomain() == pDomain )
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
	for( const auto& iter : this->m_List )
	{
		iter->DoPulse();
	}
}
