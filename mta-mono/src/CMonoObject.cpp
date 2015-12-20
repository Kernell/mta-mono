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
#include "CMonoObject.h"

MonoClass* CMonoObject::GetClass( MonoObject* pObject )
{
	return mono_object_get_class( pObject );
}

MonoObject* CMonoObject::GetPropertyValue( MonoObject* pObject, const char* szPropertyName )
{
	MonoClass* pMonoClass = mono_object_get_class( pObject );
	
	MonoProperty* pMonoProperty = mono_class_get_property_from_name( pMonoClass, szPropertyName );

	if( !pMonoProperty )
	{
		return nullptr;
	}

	return mono_property_get_value( pMonoProperty, pObject, NULL, NULL );
}

bool CMonoObject::SetPropertyValue( MonoObject* pObject, const char* szPropertyName, int iValue )
{
	return CMonoObject::SetPropertyValue( pObject, szPropertyName, (void*)&iValue );
}

bool CMonoObject::SetPropertyValue( MonoObject* pObject, const char* szPropertyName, float fValue )
{
	return CMonoObject::SetPropertyValue( pObject, szPropertyName, (void*)&fValue );
}

bool CMonoObject::SetPropertyValue( MonoObject* pObject, const char* szPropertyName, char* szValue )
{
	return CMonoObject::SetPropertyValue( pObject, szPropertyName, mono_string_new( mono_domain_get(), szValue ) );
}

bool CMonoObject::SetPropertyValue( MonoObject* pObject, const char* szPropertyName, PVOID gValue )
{
	MonoClass* pMonoClass = mono_object_get_class( pObject );
	
	MonoProperty* pMonoProperty = mono_class_get_property_from_name( pMonoClass, szPropertyName );

	if( !pMonoProperty )
	{
		return false;
	}

	PVOID args[ 1 ] = { gValue };

	mono_property_set_value( pMonoProperty, pObject, args, NULL );

	return true;
}