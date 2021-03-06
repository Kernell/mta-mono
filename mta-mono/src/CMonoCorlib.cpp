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
#include "CMonoCorlib.h"

CMonoCorlib::CMonoCorlib( CMonoDomain* pDomain )
{
	this->m_pDomain		= pDomain;
	this->m_pImage		= mono_get_corlib();
	this->m_pAssembly	= mono_image_get_assembly( this->m_pImage );

	this->Class[ "intptr" ]			= pDomain->FindOrAdd( mono_get_intptr_class() );
	this->Class[ "uintptr" ]		= pDomain->FindOrAdd( mono_get_uintptr_class() );
	this->Class[ "boolean" ]		= pDomain->FindOrAdd( mono_get_boolean_class() );
	this->Class[ "char" ]			= pDomain->FindOrAdd( mono_get_char_class() );
	this->Class[ "sbyte" ]			= pDomain->FindOrAdd( mono_get_sbyte_class() );
	this->Class[ "byte" ]			= pDomain->FindOrAdd( mono_get_byte_class() );
	this->Class[ "int16" ]			= pDomain->FindOrAdd( mono_get_int16_class() );
	this->Class[ "uint16" ]			= pDomain->FindOrAdd( mono_get_uint16_class() );
	this->Class[ "int32" ]			= pDomain->FindOrAdd( mono_get_int32_class() );
	this->Class[ "uint32" ]			= pDomain->FindOrAdd( mono_get_uint32_class() );
	this->Class[ "int64" ]			= pDomain->FindOrAdd( mono_get_int64_class() );
	this->Class[ "uint64" ]			= pDomain->FindOrAdd( mono_get_uint64_class() );
	this->Class[ "float" ]			= pDomain->FindOrAdd( mono_get_single_class() );
	this->Class[ "double" ]			= pDomain->FindOrAdd( mono_get_double_class() );
	this->Class[ "string" ]			= pDomain->FindOrAdd( mono_get_string_class() );
	this->Class[ "array" ]			= pDomain->FindOrAdd( mono_get_array_class() );
	this->Class[ "enum" ]			= pDomain->FindOrAdd( mono_get_enum_class() );
	this->Class[ "exception" ]		= pDomain->FindOrAdd( mono_get_exception_class() );
	this->Class[ "object" ]			= pDomain->FindOrAdd( mono_get_object_class() );
	this->Class[ "thread" ]			= pDomain->FindOrAdd( mono_get_thread_class() );

	this->Class[ "Type" ]			= this->GetClass( "System", "Type" );
	this->Class[ "ValueType" ]		= this->GetClass( "System", "ValueType" );
}

CMonoCorlib::~CMonoCorlib( void )
{
	this->m_pDomain		= nullptr;
	this->m_pAssembly	= nullptr;
	this->m_pImage		= nullptr;

	this->Class.clear();
}

CMonoClass* CMonoCorlib::GetClass( const char *szNameSpace, const char *szClassName )
{
	return this->GetDomain()->FindOrAdd( mono_class_from_name( this->m_pImage, szNameSpace, szClassName ) );
}