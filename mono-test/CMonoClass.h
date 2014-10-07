class CMonoClass;

#ifndef _CMONOCLASS
#define _CMONOCLASS

#include "CMonoAssembly.h"
#include "CMonoObject.h"

class CMonoClass
{
private:
	MonoClass* m_pMonoClass;
	CMonoAssembly* m_pAssembly;

public:
	CMonoClass( CMonoAssembly* pAssembly, MonoClass* pMonoClass );

	~CMonoClass();

	CMonoObject* New();

	const char* GetName();
	const char* GetNameSpace();

	MonoMethod* GetMethod( const char* szMethodName, int iParamCount );
	MonoMethod* GetMethod( const char* szMethodName );

	MonoClass* GetMonoClass()	{ return this->m_pMonoClass; };
};

#endif