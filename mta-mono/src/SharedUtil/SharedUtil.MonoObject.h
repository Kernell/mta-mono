#ifndef __SHAREDUTIL_MONOOBJECT_H
#define __SHAREDUTIL_MONOOBJECT_H

namespace SharedUtil
{
	namespace MonoObject
	{
		_MonoClass* GetClass( _MonoObject* pMonoObject );

		SColor GetColor( _MonoObject* pMonoObject );

		bool SetPropertyValue( _MonoObject* pMonoObject, const char* szPropertyName, int iValue );
		bool SetPropertyValue( _MonoObject* pMonoObject, const char* szPropertyName, float fValue );
		bool SetPropertyValue( _MonoObject* pMonoObject, const char* szPropertyName, char* szValue );
		bool SetPropertyValue( _MonoObject* pMonoObject, const char* szPropertyName, PVOID pValue );
		
		_MonoObject* GetPropertyValue( _MonoObject* pMonoObject, const char* szPropertyName );

		template< typename T >
		static T GetPropertyValue( _MonoObject* pMonoObject, const char* szPropertyName )
		{
			return *( reinterpret_cast< T* >( mono_object_unbox( GetPropertyValue( pMonoObject, szPropertyName ) ) ) );
		}

		template< typename T >
		static T Unbox( _MonoObject* pMonoObject )
		{
			return *( reinterpret_cast< T* >( mono_object_unbox( pMonoObject ) ) );
		}

		PVOID Unbox( _MonoObject* pMonoObject );

		char* ToString( _MonoObject* pMonoObject );
	}
}

#endif
