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

#include "CMonoInterface.h"
#include "CMonoFunctions.h"

CMonoInterface::CMonoInterface( void )
{
	mono_set_dirs( "mods/deathmatch/mono/lib", "mods/deathmatch/mono/etc" );

	mono_set_signal_chaining( false );

	mono_debug_init( MONO_DEBUG_FORMAT_MONO );

	this->m_pMonoDomain = mono_jit_init_version( "Mono Root", "v4.0.30319" );

	mono_domain_set_config( this->m_pMonoDomain, "mods/deathmatch/", "mods/deathmatch/mono/etc/mono/4.5/machine.config" );

	CMonoFunctions::AddInternals();

	this->m_pGC	= new CMonoGC;
}

CMonoInterface::~CMonoInterface( void )
{
	mono_jit_cleanup( this->m_pMonoDomain );

	SAFE_DELETE( this->m_pGC );
}

CMonoDomain* CMonoInterface::CreateAppdomain( CResource* pResource, char* szName, char* szConfig )
{
	MonoDomain* pMonoDomain = mono_domain_create_appdomain( szName, szConfig );

	if( pMonoDomain )
	{
		return new CMonoDomain( this, pMonoDomain, pResource );
	}

	return nullptr;
}
