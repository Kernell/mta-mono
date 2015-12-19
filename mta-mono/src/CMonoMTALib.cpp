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
	this->m_pClass		= nullptr;
	this->m_pObject		= nullptr;

	this->m_pAssembly	= nullptr;
	this->m_pImage		= nullptr;
	this->m_pDomain		= pDomain;

	this->m_pAssembly	= CMonoInterface::GetMTALib();

	if( this->m_pAssembly )
	{
		this->m_pImage	= mono_assembly_get_image( this->m_pAssembly );

		if( this->m_pImage )
		{
			this->Color			= this->GetClass( "Color" );
			this->Vector2		= this->GetClass( "Vector2" );
			this->Vector3		= this->GetClass( "Vector3" );

			this->m_pClass		= this->GetClass( "MultiTheftAuto" );
			
			if( this->m_pClass )
			{
				this->m_pObject = this->m_pClass->New();
			}
		}
	}
}

CMonoMTALib::~CMonoMTALib( void )
{
	this->Color			= nullptr;
	this->Vector2		= nullptr;
	this->Vector3		= nullptr;
	this->m_pClass		= nullptr;

	this->m_pDomain		= nullptr;
	this->m_pAssembly	= nullptr;
	this->m_pImage		= nullptr;
	this->m_pObject		= nullptr;
}

CMonoClass* CMonoMTALib::GetClass( const char* szName )
{
	return this->GetDomain()->FindOrAdd( mono_class_from_name( this->m_pImage, "MultiTheftAuto", szName ) );
}

CMonoClass* CMonoMTALib::GetClass( const char* szNameSpace, const char* szName )
{
	char szBuffer[ 128 ];

	sprintf( szBuffer, "MultiTheftAuto.%s", szNameSpace );

	return this->GetDomain()->FindOrAdd( mono_class_from_name( this->m_pImage, szBuffer, szName ) );
}

string CMonoMTALib::GetElementType( void* pUseData )
{
	CResource* pResource = this->GetDomain()->GetResource();

	assert( pResource );

	string strTypeName;

	if( CLuaFunctionDefinitions::IsElement( pResource->GetLua(), pUseData ) )
	{
		strTypeName = CLuaFunctionDefinitions::GetElementType( pResource->GetLua(), pUseData );

		strTypeName[ 0 ] = toupper( strTypeName[ 0 ] );

		if( strTypeName == "Root" )
		{
			strTypeName = "Element";
		}
	}

	return strTypeName;
}

MonoObject* CMonoMTALib::RegisterElement( void* pUseData )
{
	string strType = this->GetElementType( pUseData );

	if( strType.length() == 0 )
	{
		return nullptr;
	}

	CMonoClass* pClass	= this->GetClass( strType.c_str() );

	if( !pClass )
	{
		this->GetDomain()->GetResource()->ErrorPrintf( "[mono] Could not find the 'MultiTheftAuto.%s' class\n", strType.c_str() );

		return nullptr;
	}

	CMonoMethod* pMethod = pClass->GetMethod( "Find", 0 );

	if( !pMethod )
	{
		return nullptr;
	}

	void *Args[] = { &pUseData };

	MonoObject* pException = nullptr;

	MonoObject* pObject = pMethod->Invoke( nullptr, Args, pException );

	if( pException )
	{
		this->GetDomain()->GetResource()->ErrorPrintf( "%s\n", mono_string_to_utf8( mono_object_to_string( pException, nullptr ) ) );

		return nullptr;
	}

	if( !pObject )
	{
		pObject = pClass->New( Args, 1 );
	}

	return pObject;
}