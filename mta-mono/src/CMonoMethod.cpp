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

#include "CMonoMethod.h"

CMonoMethod::CMonoMethod( CMonoClass* pClass, MonoMethod* pMethod )
{
	this->m_pClass		= pClass;
	this->m_pMethod		= pMethod;

	this->m_strName		= mono_method_get_name( pMethod );

	this->ParseSignature();
}

CMonoMethod::~CMonoMethod( void )
{
	this->m_pClass		= nullptr;
	this->m_pMethod		= nullptr;
}

void CMonoMethod::ParseSignature( void )
{
	this->m_strSignature = "";

	MonoMethodSignature* pSignature = mono_method_signature( this->m_pMethod );

	if( pSignature )
	{
		gpointer iter = nullptr;

		this->m_strSignature += this->GetName() + "(";

		while( MonoType* pType = mono_signature_get_params( pSignature, &iter ) )
		{
			string strTypeName	= mono_type_get_name( pType );
			int iType			= mono_type_get_type( pType );

			this->m_ArgList.push_back( { strTypeName, iType } );

			if( this->m_ArgList.size() > 0 )
			{
				this->m_strSignature += ", ";
			}

			this->m_strSignature += strTypeName;
		}

		this->m_strSignature += ")";
	}
}

MonoObject* CMonoMethod::Invoke( void* pObject, void** params, MonoObject* pException )
{
	return mono_runtime_invoke( this->m_pMethod, pObject, params, &pException );
}