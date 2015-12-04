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

	mono_trace_set_level_string( "error" );

	this->m_pMonoDomain = mono_jit_init_version( "Mono Root", "v4.0.30319" );

	CMonoFunctions::AddInternals();

	this->m_pGC	= new CMonoGC;
}

CMonoInterface::~CMonoInterface( void )
{
	mono_jit_cleanup( this->m_pMonoDomain );

	SAFE_DELETE( this->m_pGC );
}

CMonoDomain* CMonoInterface::CreateAppdomain( CResource* pResource, const char* szName, char* szConfig )
{
	MonoDomain* pMonoDomain = mono_domain_create_appdomain( const_cast< char* >( szName ), szConfig );

	if( pMonoDomain )
	{
		return new CMonoDomain( this, pMonoDomain, pResource, szName );
	}

	return nullptr;
}

void CMonoInterface::SetDomain( MonoDomain* pDomain, bool bForce )
{
	mono_domain_set( pDomain != nullptr ? pDomain : this->m_pMonoDomain, bForce );
}
