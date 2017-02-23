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
#include "CMonoArguments.h"

CMonoArguments::CMonoArguments( void )
{
	this->m_pTmpArgs	= nullptr;
}

CMonoArguments::~CMonoArguments( void )
{
	this->Clear();
}

void CMonoArguments::Clear( void )
{
	for( auto iter : this->m_pArgs )
	{
		if( iter.second )
		{
			delete iter.first;
		}
	}

	this->m_pArgs.clear();

	if( this->m_pTmpArgs )
	{
		delete [] this->m_pTmpArgs;
	}
}

bool CMonoArguments::Push( MonoString* pString )
{
	this->m_pArgs.push_back( make_pair( pString, false ) );

	return true;
}

bool CMonoArguments::Push( MonoObject* pObject )
{
	this->m_pArgs.push_back( make_pair( pObject, false ) );

	return true;
}

PVOID* CMonoArguments::GetArgs( void )
{
	if( this->m_pTmpArgs )
	{
		delete [] this->m_pTmpArgs;
	}

	this->m_pTmpArgs = new PVOID[ this->Length() ];

	uint i = 0;

	for( const auto& iter : this->m_pArgs )
	{
		this->m_pTmpArgs[ i++ ] = iter.first;
	}

	return this->m_pTmpArgs;
}

const size_t CMonoArguments::Length( void ) const
{
	return this->m_pArgs.size();
}

PVOID CMonoArguments::operator [] ( int index )
{
	ASSERT( index < this->Length() );

	return this->m_pArgs[ index ].first;
}

PVOID* CMonoArguments::operator * ( void )
{
	return this->GetArgs();
}
