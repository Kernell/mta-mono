/*********************************************************
*
*  Copyright � 2013, Innovation Roleplay Engine. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "StdInc.h"
#include "CMonoDomain.h"

CMonoDomain::CMonoDomain( CMonoInterface* pMono, MonoDomain* pDomain, CResource* pResource, const char* szName )
{
	this->m_pMono		= pMono;
	this->m_pDomain		= pDomain;
	this->m_pResource	= pResource;
	this->m_pModule		= pResource->GetModule();

	this->m_strName		= szName;

	this->m_pCorlib		= nullptr;
	this->m_pMTALib		= nullptr;

	this->m_pMonoAssembly	= nullptr;
	this->m_pMonoImage		= nullptr;
	this->m_pMonoClass		= nullptr;
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

	if( this->m_pDomain )
	{
		mono_domain_finalize( this->m_pDomain, 2000 );

		MonoObject* pException = nullptr;

		mono_domain_try_unload( this->m_pDomain, &pException );

		this->HandleException( pException );
	}

	this->m_pDomain			= nullptr;

	this->m_pMonoAssembly	= nullptr;
	this->m_pMonoImage		= nullptr;
	this->m_pMonoClass		= nullptr;
	this->m_pModule			= nullptr;
}

void CMonoDomain::HandleException( MonoObject* pException )
{
	if( pException )
	{
		this->m_pResource->ErrorPrintf( "%s\n", mono_string_to_utf8( mono_object_to_string( pException, nullptr ) ) );
	}
}

CMonoClass* CMonoDomain::FindOrAdd( MonoClass* klass )
{
	if( !klass )
	{
		return nullptr;
	}

	if( this->m_pDomain )
	{
		for( const auto& iter : this->m_ClassPool )
		{
			if( **iter == klass )
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

bool CMonoDomain::Init( void )
{
	string sDirectory	( CMonoInterface::GetBinariesDirectory() + "/" + this->m_strName + "/" );
	string sPath		( sDirectory + this->m_strName + ".dll" );
	string sNamespace	( this->m_strName );
	string sClass		( "Program" );

	this->m_pMonoAssembly = this->OpenAssembly( sPath.c_str() );

	if( !this->m_pMonoAssembly )
	{
		this->GetResource()->ErrorPrintf( "failed to open assembly '%s.dll'\n", this->m_strName.c_str() );

		return false;
	}

	this->m_pMonoImage	= mono_assembly_get_image( this->m_pMonoAssembly );

	if( !this->m_pMonoImage )
	{
		this->GetResource()->ErrorPrintf( "failed to get image '%s.dll'\n", this->m_strName.c_str() );

		return false;
	}

	this->m_pMonoClass	= this->FindOrAdd( mono_class_from_name( this->m_pMonoImage, sNamespace.c_str(), sClass.c_str() ) );

	if( !this->m_pMonoClass )
	{
		this->GetResource()->ErrorPrintf( "class '%s' not found in '%s.dll'\n", sClass.c_str(), this->m_strName.c_str() );

		return false;
	}

	this->m_pCorlib = new CMonoCorlib( this );
	this->m_pMTALib = new CMonoMTALib( this );

	return true;
}

bool CMonoDomain::Start( void )
{
	CMonoMethod* pMethod = this->m_pMonoClass->GetMethod( "Main", 0 );

	if( !pMethod )
	{
		this->GetResource()->ErrorPrintf( "Assembly '%s.dll' doesn't have an entry point.\n", this->m_strName.c_str() );

		return false;
	}

	const char* szStrings[] =
	{
		this->m_strName.c_str(),
	};

	MonoArray* pArray = this->NewArray( sizeof( szStrings ) / sizeof( char* ), szStrings );

	PVOID params[] =
	{
		pArray,
	};

	MonoObject* pException = nullptr;

	pMethod->Invoke( nullptr, params, &pException );

	if( pException )
	{
		this->HandleException( pException );
	}

	return true;
}

void CMonoDomain::Unload( void )
{
	mono_domain_unload( this->m_pDomain );
}

bool CMonoDomain::Set( bool bForce )
{
	return mono_domain_set( this->m_pDomain, bForce ? 1 : 0 ) == 1;
}

MonoAssembly* CMonoDomain::OpenAssembly( const char *szName )
{
	return mono_domain_assembly_open( this->m_pDomain, szName );
}

MonoObject* CMonoDomain::CreateObject( MonoClass* klass )
{
	return mono_object_new( this->m_pDomain, klass );
}

void CMonoDomain::SetConfig( const char* szBaseDir, const char* szConfigFileName )
{
	mono_domain_set_config( this->m_pDomain, szBaseDir, szConfigFileName );
}

MonoString* CMonoDomain::NewString( const char* szText ) const
{
	return mono_string_new( this->m_pDomain, szText );
}

MonoString* CMonoDomain::NewString( const string& strText ) const
{
	return mono_string_new( this->m_pDomain, strText.c_str() );
}

MonoArray* CMonoDomain::NewArray( MonoClass* pMonoClass, CLuaArgumentsVector pLuaArguments ) const
{
	MonoArray* pArray = mono_array_new( this->m_pDomain, pMonoClass, pLuaArguments.size() );

	if( pLuaArguments.size() > 0 )
	{
		int i = 0;

		for( const auto& pArgument : pLuaArguments )
		{
			PVOID pUserData = pArgument.GetLightUserData();

			if( pUserData )
			{
				CElement* pElement = this->m_pResource->GetElementManager()->FindOrCreate( pUserData );

				mono_array_set( pArray, MonoObject*, i++, pElement->GetMonoObject() );
			}
		}
	}

	return pArray;
}

MonoArray* CMonoDomain::NewArray( uint uiLength, const char** szStrings ) const
{
	MonoArray* pArray = mono_array_new( this->m_pDomain, mono_get_string_class(), uiLength );

	for( uint i = 0; i < uiLength; i++ )
	{
		const char* szValue = szStrings[ i ];

		mono_array_set( pArray, MonoString*, i, this->NewString( szValue ) );
	}

	return pArray;
}
