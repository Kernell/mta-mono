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

#include "CMonoClass.h"

CMonoClass::CMonoClass( MonoClass* pMonoClass, CMonoDomain* pDomain )
{
	this->m_pClass		= pMonoClass;
	this->m_pDomain		= pDomain;
}

CMonoClass::~CMonoClass( void )
{
	this->m_pDomain		= nullptr;
	this->m_pClass		= nullptr;
}

MonoObject* CMonoClass::New( void )
{
	MonoObject* pObject = this->m_pDomain->CreateObject( this->m_pClass );

	if( !pObject )
	{
		return nullptr;
	}

	mono_runtime_object_init( pObject );

	return pObject;
}

MonoObject* CMonoClass::New( SColor& pColor )
{
	void *args[] = { &pColor.R, &pColor.G, &pColor.B, &pColor.A };

	return this->New( args, 4 );
}

MonoObject* CMonoClass::New( Vector2& vecVector )
{
	void *args[] = { &vecVector.fX, &vecVector.fY };

	return this->New( args, 2 );
}

MonoObject* CMonoClass::New( Vector3& vecVector )
{
	void *args[] = { &vecVector.fX, &vecVector.fY, &vecVector.fZ };

	return this->New( args, 3 );
}

MonoObject* CMonoClass::New( void** args, int argc )
{
	MonoObject* pObject = this->m_pDomain->CreateObject( this->m_pClass );

	if( !pObject )
	{
		return nullptr;
	}

	MonoMethod* pMonoMethod = this->GetMethod( ".ctor", argc );

	if( !pMonoMethod )
	{
		return nullptr;
	}

	mono_runtime_invoke( pMonoMethod, pObject, args, nullptr );

	return pObject;
}


const char* CMonoClass::GetName( void )
{
	return mono_class_get_name( this->m_pClass );
}

const char* CMonoClass::GetNameSpace( void )
{
	return mono_class_get_namespace( this->m_pClass );
}

MonoMethod* CMonoClass::GetMethod( const char* szMethodName, int iParamCount )
{
	return mono_class_get_method_from_name( this->m_pClass, szMethodName, iParamCount );
}

MonoMethod* CMonoClass::GetMethod( const char* szMethodName )
{
	MonoMethodDesc* pMonoMethodDesc = mono_method_desc_new( szMethodName, false );

	if( pMonoMethodDesc )
	{
		MonoMethod* pMethod = mono_method_desc_search_in_class( pMonoMethodDesc, this->m_pClass );

		mono_method_desc_free( pMonoMethodDesc );

		return pMethod;
	}

	return nullptr;
}