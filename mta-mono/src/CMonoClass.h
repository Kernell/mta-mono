class CMonoClass;

#ifndef _C_MONO_CLASS
#define _C_MONO_CLASS

#include "Common.h"

extern ILuaModuleManager10 *g_pModuleManager;

class CMonoClass
{
public:
	static MonoObject* New( MonoClass* pMonoClass, MonoDomain* pMonoDomain );
	static MonoObject* New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, SColor& pColor );
	static MonoObject* New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, Vector2& vecVector );
	static MonoObject* New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, Vector3& vecVector );
	static MonoObject* New( MonoClass* pMonoClass, MonoDomain* pMonoDomain, void** args, int argc );

	static const char* GetName( MonoClass* pMonoClass );
	static const char* GetNameSpace( MonoClass* pMonoClass );

	static MonoMethod* GetMethod( MonoClass* pMonoClass, const char* szMethodName, int iParamCount );
	static MonoMethod* GetMethod( MonoClass* pMonoClass, const char* szMethodName );

	static MonoClass* GetClass( MonoClass* pMonoClass );
};

#endif