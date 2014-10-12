class CMonoObject;

#ifndef _C_MONO_OBJECT
#define _C_MONO_OBJECT

#include "Common.h"
#include "CMonoClass.h"

class CMonoObject
{
private:
	MonoObject* m_pMonoObject;

public:
	CMonoObject( MonoObject* pMonoObject );
	~CMonoObject();

	CMonoClass* GetClass();

	bool SetPropertyValue( const char* szPropertyName, int iValue );
	bool SetPropertyValue( const char* szPropertyName, float fValue );
	bool SetPropertyValue( const char* szPropertyName, char* szValue );
	bool SetPropertyValue( const char* szPropertyName, gpointer gValue );

	MonoObject* GetPropertyValue( const char* szPropertyName );
	
	template <class T> T GetPropertyValue( char* szPropertyName )
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( this->GetPropertyValue( szPropertyName ) ) ) );
	}

	void* GetValue()
	{
		return mono_object_unbox( this->m_pMonoObject );
	}

	template <class T> T GetValue()
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( this->m_pMonoObject ) ) );
	}

	MonoObject *GetObject()
	{
		return this->m_pMonoObject;
	}
};

#endif