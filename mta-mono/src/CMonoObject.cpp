#include "CMonoObject.h"


CMonoObject::CMonoObject( MonoObject* pMonoObject )
{
	this->m_pMonoObject = pMonoObject;
}


CMonoObject::~CMonoObject()
{
}

MonoClass* CMonoObject::GetClass()
{
	return mono_object_get_class( this->m_pMonoObject );
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