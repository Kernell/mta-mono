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

	MonoClass *pMonoBaseClass = pMonoClass;

	while( pMonoBaseClass )
	{
		gpointer iter = nullptr;

		while( MonoMethod* pMonoMethod = mono_class_get_methods( pMonoBaseClass, &iter ) )
		{
			CMonoMethod* pMethod = new CMonoMethod( this, pMonoMethod );

			this->m_Methods[ pMethod->GetName() ].push_back( pMethod );
		}

		iter = nullptr;

		while( MonoProperty* pMonoProperty = mono_class_get_properties( pMonoBaseClass, &iter ) )
		{
			const char* szName = mono_property_get_name( pMonoProperty );

			this->m_Properties[ szName ].push_back( pMonoProperty );
		}
		
		iter = nullptr;

		while( MonoEvent* pMonoEvent = mono_class_get_events( pMonoBaseClass, &iter ) )
		{
			const char* szName = mono_event_get_name( pMonoEvent );

			this->m_Events[ szName ] = new CMonoEvent( this, pMonoEvent );
		}

		iter = nullptr;

		while( MonoClassField* pMonoField = mono_class_get_fields( pMonoBaseClass, &iter ) )
		{
			const char* szName = mono_field_get_name( pMonoField );

			this->m_Fields[ szName ] = pMonoField;
		}

		pMonoBaseClass = mono_class_get_parent( pMonoBaseClass );
	}
}

CMonoClass::~CMonoClass( void )
{
	this->m_pDomain		= nullptr;
	this->m_pClass		= nullptr;

	this->m_Fields.clear();
	
	for( auto iter : this->m_Events )
	{
		delete iter.second;
	}

	this->m_Events.clear();

	for( auto iter : this->m_Properties )
	{
		iter.second.clear();
	}

	this->m_Properties.clear();

	auto iter = this->m_Methods.begin();

	for( ; iter != this->m_Methods.end(); iter++ )
	{
		for( CMonoMethod* method : iter->second )
		{
			delete method;
		}

		iter->second.clear();
	}

	this->m_Methods.clear();
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

	MonoMethod* pMethod = this->GetMethodFromName( ".ctor", argc );

	if( !pMethod )
	{
		return nullptr;
	}

	MonoObject* pException = nullptr;

	mono_runtime_invoke( pMethod, pObject, args, &pException );

	if( pException )
	{
		this->GetDomain()->HandleException( pException );
	}

	return pObject;
}

MonoObject* CMonoClass::Box( void* value )
{
	return mono_value_box( this->m_pDomain->GetMonoPtr(), this->m_pClass, value );
}

const char* CMonoClass::GetName( void )
{
	return mono_class_get_name( this->m_pClass );
}

const char* CMonoClass::GetNameSpace( void )
{
	return mono_class_get_namespace( this->m_pClass );
}

MonoMethod* CMonoClass::GetMethodFromName( string strMethodName, int iParamCount )
{
	return mono_class_get_method_from_name( this->m_pClass, strMethodName.c_str(), iParamCount );
}

MonoMethod* CMonoClass::GetMethod( string strMethodName )
{
	MonoMethodDesc* pMonoMethodDesc = mono_method_desc_new( strMethodName.c_str(), false );

	if( pMonoMethodDesc )
	{
		MonoMethod* pMethod = mono_method_desc_search_in_class( pMonoMethodDesc, this->m_pClass );

		mono_method_desc_free( pMonoMethodDesc );

		return pMethod;
	}

	return nullptr;
}

CMonoMethod* CMonoClass::GetMethod( string strMethodName, uint uiIndex )
{
	if( this->m_Methods[ strMethodName ].size() > 0 )
	{
		uint i = 0;

		for( auto ptr : this->m_Methods[ strMethodName ] )
		{
			if( i++ == uiIndex )
			{
				return ptr;
			}
		}
	}

	return nullptr;
}

list< CMonoMethod* > CMonoClass::GetMethods( string strMethodName )
{
	return this->m_Methods[ strMethodName ];
}

CMonoEvent* CMonoClass::GetEvent( string strEventName )
{
	return this->m_Events[ strEventName ];
}

MonoClassField* CMonoClass::GetField( string strFieldName )
{
	return this->m_Fields[ strFieldName ];
}