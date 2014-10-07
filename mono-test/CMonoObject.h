class CMonoObject;

#ifndef _CMONOOBJECT
#define _CMONOOBJECT

#include "CMonoAssembly.h"
#include "CMonoClass.h"

class CMonoObject
{
private:
	MonoObject* m_pMonoObect;
	CMonoClass* m_pClass;

public:
	CMonoObject( CMonoClass* pClass, MonoObject* pMonoObect );
	~CMonoObject();

	CMonoClass*		GetClass();
	MonoObject*		CallMethod( const char* methodName );
};

#endif