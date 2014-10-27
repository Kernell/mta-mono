#include "CMonoClass.h"

CMonoClass::CMonoClass( MonoClass* pMonoClass )
{
	this->m_pMonoClass	= pMonoClass;
}


CMonoClass::~CMonoClass()
{
}

CMonoObject* CMonoClass::New( MonoDomain* pMonoDomain )
{
	MonoObject* pObject = mono_object_new( pMonoDomain, this->m_pMonoClass );

	if( !pObject )
	{
		g_pModuleManager->ErrorPrintf( "%s:%d: Failed to create mono object for %s::%s\n", this->GetNameSpace(), this->GetName(), __FILE__, __LINE__ );

		return NULL;
	}

	mono_runtime_object_init( pObject );

	return new CMonoObject( pObject );
}

CMonoObject* CMonoClass::New( MonoDomain* pMonoDomain, SColor& pColor )
{
	void *args[] = { &pColor.R, &pColor.G, &pColor.B, &pColor.A };

	return this->New( pMonoDomain, args, 4 );
}


CMonoObject* CMonoClass::New( MonoDomain* pMonoDomain, Vector2& vecVector )
{
	void *args[] = { &vecVector.fX, &vecVector.fY };

	return this->New( pMonoDomain, args, 2 );
}

CMonoObject* CMonoClass::New( MonoDomain* pMonoDomain, Vector3& vecVector )
{
	void *args[] = { &vecVector.fX, &vecVector.fY, &vecVector.fZ };

	return this->New( pMonoDomain, args, 3 );
}

CMonoObject* CMonoClass::New( MonoDomain* pMonoDomain, void** args, int argc )
{
	MonoObject* pObject = mono_object_new( pMonoDomain, this->m_pMonoClass );

	if( !pObject )
	{
		g_pModuleManager->ErrorPrintf( "%s:%d: Failed to create mono object for %s::%s\n", this->GetNameSpace(), this->GetName(), __FILE__, __LINE__ );

		return NULL;
	}

	MonoMethod* pMonoMethod = this->GetMethod( ".ctor", argc );

	if( !pMonoMethod )
	{
		g_pModuleManager->ErrorPrintf( "%s:%d: Could not lookup constructor for class %s::%s\n", this->GetNameSpace(), this->GetName(), __FILE__, __LINE__ );

		return NULL;
	}
	
	mono_runtime_invoke( pMonoMethod, pObject, args, NULL );

	return new CMonoObject( pObject );
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