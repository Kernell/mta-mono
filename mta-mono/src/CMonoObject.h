class CMonoObject;

#ifndef _C_MONO_OBJECT
#define _C_MONO_OBJECT

#include "Common.h"

class CMonoObject
{
private:
	MonoObject* m_pMonoObject;

public:
	CMonoObject( MonoObject* pMonoObject );
	~CMonoObject();

	MonoClass* GetClass();

	MonoObject* GetPropertyValue( const char* szPropertyName );

	template <class T> T GetPropertyValue( char* szPropertyName )
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( this->GetPropertyValue( szPropertyName ) ) ) );
	}
};

#endif