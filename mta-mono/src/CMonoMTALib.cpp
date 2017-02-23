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
#include "CMonoMTALib.h"

CMonoMTALib::CMonoMTALib( CMonoDomain* pDomain )
{
	this->m_pImage		= nullptr;
	this->m_pDomain		= pDomain;

	this->m_pImage	= mono_assembly_get_image( CMonoInterface::GetMTALib() );

	if( this->m_pImage )
	{
		this->Color			= this->GetClass( "Color" );
		this->Vector2		= this->GetClass( "Vector2" );
		this->Vector3		= this->GetClass( "Vector3" );
	}
}

CMonoMTALib::~CMonoMTALib( void )
{
	this->Color			= nullptr;
	this->Vector2		= nullptr;
	this->Vector3		= nullptr;

	this->m_pDomain		= nullptr;
	this->m_pImage		= nullptr;
}

CMonoClass* CMonoMTALib::GetClass( const char* szName ) const
{
	return this->GetDomain()->FindOrAdd( mono_class_from_name( this->m_pImage, "MultiTheftAuto", szName ) );
}

CMonoClass* CMonoMTALib::GetClass( const char* szNameSpace, const char* szName ) const
{
	char szBuffer[ 128 ];

	sprintf( szBuffer, "MultiTheftAuto.%s", szNameSpace );

	return this->GetDomain()->FindOrAdd( mono_class_from_name( this->m_pImage, szBuffer, szName ) );
}
