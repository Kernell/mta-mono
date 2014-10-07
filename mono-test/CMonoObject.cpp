#include "stdafx.h"
#include "CMonoObject.h"

CMonoObject::CMonoObject( CMonoClass* pClass, MonoObject* pMonoObect )
{
	this->m_pClass		= pClass;
	this->m_pMonoObect	= pMonoObect;
}

CMonoObject::~CMonoObject()
{
}

CMonoClass* CMonoObject::GetClass()
{
	return this->m_pClass;
	//return this->m_pAssembly->GetClass( mono_object_get_class( this->m_pMonoObect ) );
}

MonoObject* CMonoObject::CallMethod( const char* szMethodName )
{
	CMonoClass* pClass = this->GetClass();

	if( pClass )
	{
		MonoMethod* pMonoMethod = pClass->GetMethod( szMethodName );

		if( pMonoMethod )
		{
			return mono_runtime_invoke( pMonoMethod, this->m_pMonoObect, NULL, NULL );
		}
	}

	return NULL;
}