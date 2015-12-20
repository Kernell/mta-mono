/*********************************************************
*
*  Copyright © 2013, Innovation Roleplay Engine. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "StdInc.h"
#include "CMonoInterface.h"
#include "CMonoFunctions.h"

MonoAssembly* CMonoInterface::m_pMTALib = nullptr;

CMonoInterface::CMonoInterface( void )
{
	mono_set_dirs( "mods/deathmatch/mono/lib", "mods/deathmatch/mono/etc" );

	mono_set_signal_chaining( false );

	mono_debug_init( MONO_DEBUG_FORMAT_MONO );

#if _DEBUG
	mono_trace_set_level_string( "debug" );
#else
	mono_trace_set_level_string( "critical" );
#endif

	mono_trace_set_print_handler( CMonoInterface::MonoPrintCallbackHandler );
	mono_trace_set_printerr_handler( CMonoInterface::MonoPrintErrorCallbackHandler );

	this->m_pMonoDomain = mono_jit_init_version( "mono_root_domain", "v4.0.30319" );

	CMonoInterface::m_pMTALib	= mono_assembly_open_full( "mods/deathmatch/mono/lib/MultiTheftAuto.dll", nullptr, FALSE );

	CMonoFunctions::AddInternals();

	this->m_pGC	= new CMonoGC;
}

CMonoInterface::~CMonoInterface( void )
{
	mono_jit_cleanup( this->m_pMonoDomain );

	SAFE_DELETE( this->m_pGC );
}

CMonoDomain* CMonoInterface::CreateAppdomain( CResource* pResource, const char* szName, char* szConfig )
{
	MonoDomain* pMonoDomain = mono_domain_create_appdomain( const_cast< char* >( szName ), szConfig );

	if( pMonoDomain )
	{
		return new CMonoDomain( this, pMonoDomain, pResource, szName );
	}

	return nullptr;
}

void CMonoInterface::SetDomain( MonoDomain* pDomain, bool bForce )
{
	mono_domain_set( pDomain != nullptr ? pDomain : this->m_pMonoDomain, bForce );
}

CLuaArguments CMonoInterface::MonoArrayToLuaArguments( MonoArray* pArray )
{
	CLuaArguments pLuaArguments;

	unsigned int uiLength = mono_array_length( pArray );

	for( unsigned int i = 0; i < uiLength; i++ )
	{
		int iType			= 0;

		MonoObject* pObj	= mono_array_get( pArray, MonoObject*, i );
		MonoType* pType		= nullptr;

		if( pObj )
		{
			MonoClass* pClass = mono_object_get_class( pObj );

			if( pClass )
			{
				pType = mono_class_get_type( pClass );

				if( pType )
				{
					iType = mono_type_get_type( pType );
				}
			}
		}

		switch( iType )
		{
			case NULL:
			{
				pLuaArguments.PushNil();

				break;
			}
			case MONO_TYPE_BOOLEAN: // System.Boolean
			{
				bool bValue = *( reinterpret_cast<bool*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushBoolean( bValue );

				break;
			}
			case MONO_TYPE_CHAR: // System.Char
			{
				wchar_t iValue = *( reinterpret_cast<wchar_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_STRING: // System.String
			{
				const char* szValue = mono_string_to_utf8( reinterpret_cast<MonoString*>( pObj ) );

				pLuaArguments.PushString( szValue );

				break;
			}
			case MONO_TYPE_I1: // System.SByte
			{
				int8_t iValue = *( reinterpret_cast<int8_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_U1: // System.Byte
			{
				uint8_t iValue = *( reinterpret_cast<uint8_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_I2: // System.Int16
			{
				int16_t iValue = *( reinterpret_cast<int16_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_U2: // System.UInt16
			{
				uint16_t iValue = *( reinterpret_cast<uint16_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_I4: // System.Int32
			{
				int32_t iValue = *( reinterpret_cast<int32_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_U4: // System.UInt32
			{
				uint32 iValue = *( reinterpret_cast<uint32*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_I8: // System.Int64
			{
				int64_t iValue = *( reinterpret_cast<int64_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_U8: // System.UInt64
			{
				uint64_t iValue = *( reinterpret_cast<uint64_t*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( iValue );

				break;
			}
			case MONO_TYPE_R4: // System.Single
			{
				float fValue = *( reinterpret_cast<float*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( fValue );

				break;
			}
			case MONO_TYPE_R8: // System.Double
			{
				double dValue = *( reinterpret_cast<double*>( mono_object_unbox( pObj ) ) );

				pLuaArguments.PushNumber( dValue );

				break;
			}
			case MONO_TYPE_OBJECT: // System.Object
			case MONO_TYPE_CLASS:
			{
				void* pValue = CMonoObject::GetPropertyValue<void*>( pObj, "userdata" );

				if( pValue )
				{
					pLuaArguments.PushUserData( pValue );

					break;
				}

				// do not break;
			}
			case MONO_TYPE_I:
			case MONO_TYPE_U:
			default:
			{
				g_pModuleManager->ErrorPrintf( "Unsupported type: %s (0x%i)\n", pType ? mono_type_get_name( pType ) : "(unknown type)", iType );

				break;
			}
		}

		iType	= 0;
		pType	= nullptr;
	}

	return pLuaArguments;
}

MonoAssembly* CMonoInterface::GetMTALib( void )
{
	return CMonoInterface::m_pMTALib;
}

void CMonoInterface::MonoPrintCallbackHandler( const char *string, mono_bool is_stdout )
{
	g_pModuleManager->Printf( string );
}

void CMonoInterface::MonoPrintErrorCallbackHandler( const char *string, mono_bool is_stdout )
{
	g_pModuleManager->ErrorPrintf( string );
}
