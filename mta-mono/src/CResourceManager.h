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

class CResourceManager;

#ifndef __CRESOURCEMANAGER_H
#define __CRESOURCEMANAGER_H

#include "CMonoFunctions.h"

extern ILuaModuleManager10	*g_pModuleManager;

class CResourceManager
{
private:
	std::list< CResource* >       m_List;

	MonoDomain	*m_pMonoDomain;

public:
	CResourceManager( void )
	{
	//	#ifdef _WIN32
		mono_set_dirs( "mods/deathmatch/mono/lib", "mods/deathmatch/mono/etc" );
	//	#endif

	//	mono_config_parse( NULL );

		mono_debug_init( MONO_DEBUG_FORMAT_MONO );

		this->m_pMonoDomain			= mono_jit_init_version( "Mono Root", "v4.0.30319" );

		CMonoFunctions::AddInternals();
	}

	~CResourceManager( void )
	{
		std::list< CResource* >::const_iterator iter = this->m_List.begin();

		for( ; iter != this->m_List.end(); iter++ )
		{
			delete *iter;
		}

		mono_jit_cleanup( this->m_pMonoDomain );
	}

	CResource* Create( lua_State* luaVM )
	{
		if( !this->GetFromList( luaVM ) )
		{
			string sName = "";

			g_pModuleManager->GetResourceName( luaVM, sName );

			string sPath( "mods/deathmatch/resources/[ire]/" + sName + "/" + sName + ".dll" );

			struct stat buf;

			if( stat( sPath.c_str(), &buf ) == -1 )
			{
				return NULL;
			}

			CResource *pResource = new CResource( luaVM, sName );

			this->AddToList( pResource );

			return pResource;
		}

		return NULL;
	}

	void AddToList( CResource* pResource )
	{
		this->m_List.push_back( pResource );
	}

	CResource* GetFromList( lua_State* pLuaVM )
	{
		std::list< CResource* >::const_iterator iter = this->m_List.begin();
		
		for( ; iter != this->m_List.end(); iter++ )
		{
			if( (*iter)->m_pLuaVM == pLuaVM )
			{
				return *iter;
			}
		}

		return NULL;
	}

	CResource* GetFromList( MonoDomain* pDomain )
	{
		std::list< CResource* >::const_iterator iter = this->m_List.begin();
		
		for( ; iter != this->m_List.end(); iter++ )
		{
			if( (*iter)->m_pMonoDomain == pDomain )
			{
				return *iter;
			}
		}

		return NULL;
	}

	void RemoveFromList( CResource* pResource )
	{
		if( !this->m_List.empty() )
		{
			this->m_List.remove( pResource );
		}
	}
	
	void DoPulse( void )
	{
		std::list< CResource* >::const_iterator iter = this->m_List.begin();
		
		for( ; iter != this->m_List.end(); iter++ )
		{
			(*iter)->DoPulse();
		}
	}
};
#endif
