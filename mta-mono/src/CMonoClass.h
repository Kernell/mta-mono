class CMonoClass;

#ifndef _C_MONO_CLASS
#define _C_MONO_CLASS

#include "Common.h"
#include "CMonoObject.h"

extern ILuaModuleManager10	*g_pModuleManager; 

class CMonoClass
{
private:
	MonoClass* m_pMonoClass;

public:
	CMonoClass( MonoClass* pMonoClass );
	~CMonoClass();

	CMonoObject* New( MonoDomain* pMonoDomain );
	CMonoObject* New( MonoDomain* pMonoDomain, Vector3& vecVector );
	CMonoObject* New( MonoDomain* pMonoDomain, void** args, int argc );

	const char* GetName();
	const char* GetNameSpace();

	MonoMethod* GetMethod( const char* szMethodName, int iParamCount );
	MonoMethod* GetMethod( const char* szMethodName );

	MonoClass* GetMonoClass()	{ return this->m_pMonoClass; };

	MonoClass* GetClass()
	{
		return this->m_pMonoClass;
	}
};

#endif