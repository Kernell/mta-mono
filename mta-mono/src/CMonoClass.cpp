#include "CMonoClass.h"

MonoObject* CMonoClass::New( MonoClass* pMonoClass, MonoDomain* pMonoDomain )
{
	MonoObject* pObject = mono_object_new( pMonoDomain, pMonoClass );

	if( !pObject )
	{
		g_pModuleManager->ErrorPrintf( "%s:%d: Failed to create mono object for %s::%s\n",
			CMonoClass::GetNameSpace( pMonoClass ),
			CMonoClass::GetName( pMonoClass ),
			__FILE__,
			__LINE__
			);

		return nullptr;
	}

	mono_runtime_object_init( pObject );

	return pObject;
}

MonoObject* CMonoClass::New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, SColor& pColor )
{
	void *args[] = { &pColor.R, &pColor.G, &pColor.B, &pColor.A };

	return CMonoClass::New( pMonoClass, pMonoDomain, args, 4 );
}


MonoObject* CMonoClass::New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, Vector2& vecVector )
{
	void *args[] = { &vecVector.fX, &vecVector.fY };

	return CMonoClass::New( pMonoClass, pMonoDomain, args, 2 );
}

MonoObject* CMonoClass::New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, Vector3& vecVector )
{
	void *args[] = { &vecVector.fX, &vecVector.fY, &vecVector.fZ };

	return CMonoClass::New( pMonoClass, pMonoDomain, args, 3 );
}

MonoObject* CMonoClass::New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, void** args, int argc )
{
	MonoObject* pObject = mono_object_new( pMonoDomain, pMonoClass );

	if( !pObject )
	{
		g_pModuleManager->ErrorPrintf( "%s:%d: Failed to create mono object for %s::%s\n", GetNameSpace( pMonoClass ), GetName( pMonoClass ), __FILE__, __LINE__ );

		return nullptr;
	}

	MonoMethod* pMonoMethod = CMonoClass::GetMethod( pMonoClass, ".ctor", argc );

	if( !pMonoMethod )
	{
		g_pModuleManager->ErrorPrintf( "%s:%d: Could not lookup constructor for class %s::%s\n", GetNameSpace( pMonoClass ), GetName( pMonoClass ), __FILE__, __LINE__ );

		return nullptr;
	}

	mono_runtime_invoke( pMonoMethod, pObject, args, nullptr );

	return pObject;
}

const char* CMonoClass::GetName( MonoClass* pMonoClass )
{
	return mono_class_get_name( pMonoClass );
}

const char* CMonoClass::GetNameSpace( MonoClass* pMonoClass )
{
	return mono_class_get_namespace( pMonoClass );
}

MonoMethod* CMonoClass::GetMethod( MonoClass* pMonoClass, const char* szMethodName, int iParamCount )
{
	return mono_class_get_method_from_name( pMonoClass, szMethodName, iParamCount );
}

MonoMethod* CMonoClass::GetMethod( MonoClass* pMonoClass, const char* szMethodName )
{
	MonoMethodDesc* pMonoMethodDesc = mono_method_desc_new( szMethodName, false );

	if( pMonoMethodDesc )
	{
		MonoMethod* pMethod = mono_method_desc_search_in_class( pMonoMethodDesc, pMonoClass );

		mono_method_desc_free( pMonoMethodDesc );

		return pMethod;
	}

	return nullptr;
}