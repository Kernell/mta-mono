class CMono;

#ifndef _CMONO
#define _CMONO

#include "CMonoClass.h"
#include "CMonoObject.h"
#include "CMonoAssembly.h"

class CMono
{
private:
	MonoDomain	*m_pMonoDomain;

public:
	CMono();
	~CMono();

	bool Init( const char* szVersion );
	void AddInternals();
	bool Load( const char * szFilePath );

	static void Test( MonoObject* vector );
};

#endif