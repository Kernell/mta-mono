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

#include "CMonoDomain.h"

CMonoDomain::CMonoDomain( CMonoInterface* pMono, MonoDomain* pDomain, CResource* pResource )
{
	this->m_pMono		= pMono;
	this->m_pDomain		= pDomain;
	this->m_pResource	= pResource;

	this->m_pCorlib		= nullptr;
	this->m_pMTALib		= nullptr;
}

CMonoDomain::~CMonoDomain( void )
{
	SAFE_DELETE( this->m_pMTALib );
	SAFE_DELETE( this->m_pCorlib );

	for( auto iter : this->m_ClassPool )
	{
		delete iter;
	}

	this->m_ClassPool.clear();

	this->m_pDomain = nullptr;
}

CMonoClass* CMonoDomain::FindOrAdd( MonoClass* klass )
{
	if( !klass )
	{
		return nullptr;
	}

	if( this->m_pDomain )
	{
		for( auto iter : this->m_ClassPool )
		{
			if( iter->GetMonoPtr() == klass )
			{
				return iter;
			}
		}

		CMonoClass* pClass = new CMonoClass( klass, this );

		this->m_ClassPool.push_back( pClass );

		return pClass;
	}

	return nullptr;
}

void CMonoDomain::ReleaseClass( CMonoClass* pClass )
{
	if( !this->m_ClassPool.empty() )
	{
		this->m_ClassPool.remove( pClass );
	}
}

void CMonoDomain::Init( void )
{
	this->m_pCorlib = new CMonoCorlib( this );
	this->m_pMTALib = new CMonoMTALib( this );
}

void CMonoDomain::Unload( void )
{
	mono_domain_unload( this->m_pDomain );
}

bool CMonoDomain::Set( bool bForce )
{
	return mono_domain_set( this->m_pDomain, static_cast<mono_bool>( bForce ) ) == 1;
}

MonoAssembly* CMonoDomain::OpenAssembly( const char *szName )
{
	return mono_domain_assembly_open( this->m_pDomain, szName );
}

MonoObject* CMonoDomain::CreateObject( MonoClass* klass )
{
	return mono_object_new( this->m_pDomain, klass );
}

MonoString* CMonoDomain::NewString( const char* szText )
{
	return mono_string_new( this->m_pDomain, szText );
}

MonoString* CMonoDomain::NewString( string strText )
{
	return mono_string_new( this->m_pDomain, strText.c_str() );
}
