#include "stdafx.h"
#include "CMonoClass.h"

CMonoClass::CMonoClass( CMonoAssembly* pAssembly, MonoClass* pMonoClass )
{
	this->m_pAssembly	= pAssembly;
	this->m_pMonoClass	= pMonoClass;

	this->m_pAssembly->AddToList( this );
}

CMonoClass::~CMonoClass()
{
	this->m_pAssembly->RemoveFromList( this );
}

CMonoObject* CMonoClass::New()
{
	MonoObject* pObject = mono_object_new( this->m_pAssembly->GetMonoDomain(), this->m_pMonoClass );

	if( !pObject )
	{
		printf( "Failed to create mono object for %s::%s\n", this->GetNameSpace(), this->GetName() );

		return NULL;
	}

	mono_runtime_object_init( pObject );

	return new CMonoObject( this, pObject );
}

const char* CMonoClass::GetName()
{
	return mono_class_get_name( this->m_pMonoClass );
}

const char* CMonoClass::GetNameSpace()
{
	return mono_class_get_namespace( this->m_pMonoClass );
}

MonoMethod* CMonoClass::GetMethod( const char* szMethodName, int iParamCount )
{
	return mono_class_get_method_from_name( this->m_pMonoClass, szMethodName, iParamCount );
}

MonoMethod* CMonoClass::GetMethod( const char* szMethodName )
{
	MonoMethodDesc* pMonoMethodDesc = mono_method_desc_new( szMethodName, false );

	if( pMonoMethodDesc )
	{
		MonoMethod* pMethod = mono_method_desc_search_in_class( pMonoMethodDesc, this->m_pMonoClass );

		mono_method_desc_free( pMonoMethodDesc );

		return pMethod;
	}

	return NULL;
}