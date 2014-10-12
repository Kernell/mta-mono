#include "CMonoObject.h"

CMonoObject::CMonoObject( MonoObject* pMonoObject )
{
	this->m_pMonoObject = pMonoObject;
}


CMonoObject::~CMonoObject()
{
}

CMonoClass* CMonoObject::GetClass()
{
	MonoClass* pMonoClass = mono_object_get_class( this->m_pMonoObject );

	if( pMonoClass )
	{
		return new CMonoClass( pMonoClass );
	}

	return NULL;
}

MonoObject* CMonoObject::GetPropertyValue( const char* szPropertyName )
{
	MonoClass* pMonoClass = mono_object_get_class( this->m_pMonoObject );
	
	MonoProperty* pMonoProperty = mono_class_get_property_from_name( pMonoClass, szPropertyName );

	if( !pMonoProperty )
	{
		return NULL;
	}

	return mono_property_get_value( pMonoProperty, this->m_pMonoObject, NULL, NULL );
}

bool CMonoObject::SetPropertyValue( const char* szPropertyName, int iValue )
{
	return this->SetPropertyValue( szPropertyName, (void*)&iValue );
}

bool CMonoObject::SetPropertyValue( const char* szPropertyName, float fValue )
{
	return this->SetPropertyValue( szPropertyName, (void*)&fValue );
}

bool CMonoObject::SetPropertyValue( const char* szPropertyName, char* szValue )
{
	return this->SetPropertyValue( szPropertyName, mono_string_new( mono_domain_get(), szValue ) );
}

bool CMonoObject::SetPropertyValue( const char* szPropertyName, gpointer gValue )
{
	MonoClass* pMonoClass = mono_object_get_class( this->m_pMonoObject );
	
	MonoProperty* pMonoProperty = mono_class_get_property_from_name( pMonoClass, szPropertyName );

	if( !pMonoProperty )
	{
		return false;
	}

	gpointer args[ 1 ] = { gValue };

	mono_property_set_value( pMonoProperty, this->m_pMonoObject, args, NULL );

	return true;
}