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

CResourceManager::CResourceManager( CMonoInterface* pMono )
{
	this->m_pMono = pMono;
}

CResourceManager::~CResourceManager( void )
{
	for( auto iter : this->m_List )
	{
		delete iter;
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

		CResource *pResource = new CResource( this->m_pMono, luaVM, strName );

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
		if( iter->GetLua() == pLuaVM )
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
		if( iter->GetDomain()->GetMonoPtr() == pDomain )
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