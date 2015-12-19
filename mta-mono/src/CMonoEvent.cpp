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
#include "CMonoEvent.h"

CMonoEvent::CMonoEvent( CMonoClass* pClass, MonoEvent* pEvent )
{
	this->m_pClass			= pClass;
	this->m_pEvent			= pEvent;
	this->m_pAddMethod		= nullptr;
	this->m_pRemoveMethod	= nullptr;
	this->m_pRaiseMethod	= nullptr;

	this->m_strName			= mono_event_get_name( pEvent );
}

CMonoEvent::~CMonoEvent( void )
{
	this->m_pClass			= nullptr;
	this->m_pEvent			= nullptr;
	this->m_pAddMethod		= nullptr;
	this->m_pRemoveMethod	= nullptr;
	this->m_pRaiseMethod	= nullptr;
}

bool CMonoEvent::Call( MonoObject* pThis, list< CLuaArgument* > argv )
{
	CMonoMethod* pMethod = this->GetRaiseMethod();

	if( !pMethod )
	{
		return false;
	}

	void** pArguments = this->ParseArguments( argv );

	if( !pArguments )
	{
		this->GetClass()->GetDomain()->GetResource()->ErrorPrintf( "Raise method for event '%s' not found\n", this->GetName().c_str() );

		return false;
	}

	MonoObject* pException	= nullptr;

	pMethod->Invoke( pThis, pArguments, pException );

	if( !pException )
	{
		auto iter = argv.begin();

		if( (*iter)->GetType() == LUA_TLIGHTUSERDATA )
		{
			pMethod->Invoke( pArguments[ 0 ], pArguments, pException );
		}
	}

	delete [] pArguments;
	
	if( pException )
	{
		this->GetClass()->GetDomain()->GetResource()->ErrorPrintf( "%s\n", mono_string_to_utf8( mono_object_to_string( pException, nullptr ) ) );

		return false;
	}

	return false;
}

void** CMonoEvent::ParseArguments( list< CLuaArgument* > argv )
{
	CMonoMTALib* pMTALib = this->GetClass()->GetDomain()->GetMTALib();
	CMonoCorlib* pCorlib = this->GetClass()->GetDomain()->GetCorlib();

	gpointer *pArguments = new gpointer[ argv.size() ];
	
	uint argc = 0;

	auto pMethods = this->m_pClass->GetMethods( "raise_" + this->GetName() );

	for( auto pMethod : pMethods )
	{
		vector< SMonoType > pArgList = pMethod->GetArguments();

		if( pArgList.size() != argv.size() )
		{
			continue;
		}

		auto iter	= argv.begin();
		auto pType	= pArgList.begin();

		for( ; ; iter++ )
		{
			if( iter == argv.end() || pType == pArgList.end() )
			{
				return pArguments;
			}

			int iLuaType = (*iter)->GetType();

			switch( pType->iType )
			{
				case MONO_TYPE_BOOLEAN: // System.Boolean
				{
					if( iLuaType == LUA_TBOOLEAN )
					{
						bool bValue = (*iter)->GetBoolean();

						pArguments[ argc++ ] = &bValue;
					}

					break;
				}
				case MONO_TYPE_CHAR: // System.Char
				{
					if( iLuaType == LUA_TNUMBER )
					{
						wchar_t iValue = (*iter)->GetNumber< wchar_t >();

						MonoObject* pObj = pCorlib->Class[ "char" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_I1: // System.SByte
				{
					if( iLuaType == LUA_TNUMBER )
					{
						int8_t iValue = (*iter)->GetNumber< int8_t >();

						MonoObject* pObj = pCorlib->Class[ "sbyte" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_U1: // System.Byte
				{
					if( iLuaType == LUA_TNUMBER )
					{
						uint8_t iValue = (*iter)->GetNumber< uint8_t >();

						MonoObject* pObj = pCorlib->Class[ "byte" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_I2: // System.Int16
				{
					if( iLuaType == LUA_TNUMBER )
					{
						int16_t iValue = (*iter)->GetNumber< int16_t >();

						MonoObject* pObj = pCorlib->Class[ "int16" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_U2: // System.UInt16
				{
					if( iLuaType == LUA_TNUMBER )
					{
						uint16_t iValue = (*iter)->GetNumber< uint16_t >();

						MonoObject* pObj = pCorlib->Class[ "uint16" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_I4: // System.Int32
				{
					if( iLuaType == LUA_TNUMBER )
					{
						int32_t iValue = (*iter)->GetNumber< int32_t >();

						MonoObject* pObj = pCorlib->Class[ "int32" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_U4: // System.UInt32
				{
					if( iLuaType == LUA_TNUMBER )
					{
						uint32_t iValue = (*iter)->GetNumber< uint32_t >();

						MonoObject* pObj = pCorlib->Class[ "uint32" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_I8: // System.Int64
				{
					if( iLuaType == LUA_TNUMBER )
					{
						int64_t iValue = (*iter)->GetNumber< int64_t >();

						MonoObject* pObj = pCorlib->Class[ "int64" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_U8: // System.UInt64
				{
					if( iLuaType == LUA_TNUMBER )
					{
						uint64_t iValue = (*iter)->GetNumber< uint64_t >();

						MonoObject* pObj = pCorlib->Class[ "uint64" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_R4: // System.Single
				{
					if( iLuaType == LUA_TNUMBER )
					{
						float iValue = (*iter)->GetNumber< float >();

						MonoObject* pObj = pCorlib->Class[ "float" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_R8: // System.Double
				{
					if( iLuaType == LUA_TNUMBER )
					{
						double iValue = (*iter)->GetNumber< double >();

						MonoObject* pObj = pCorlib->Class[ "double" ]->Box( &iValue );

						pArguments[ argc++ ] = pObj;
					}

					break;
				}
				case MONO_TYPE_STRING: // System.String
				{
					if( iLuaType == LUA_TSTRING )
					{
						const char* szValue = (*iter)->GetString();

						MonoString* pString = this->GetClass()->GetDomain()->NewString( szValue );

						pArguments[ argc++ ] = pString;
					}

					break;
				}
				case MONO_TYPE_OBJECT: // System.Object
				case MONO_TYPE_CLASS:
				{
					if( iLuaType == LUA_TLIGHTUSERDATA )
					{
						void* pUserData = (*iter)->GetLightUserData();

						MonoObject* pValue = pMTALib->RegisterElement( pUserData );

						if( pValue )
						{
							pArguments[ argc++ ] = pValue;
						}
						else
						{
							pArguments[ argc++ ] = pUserData;
						}
					}

					break;
				}
				case MONO_TYPE_I:
				case MONO_TYPE_U:
				default:
				{
					this->GetClass()->GetDomain()->GetResource()->ErrorPrintf( "Unsupported type '%s (0x%i)' for '%s'\n", pType->strName.c_str(), pType->iType, this->GetName().c_str() );

					break;
				}
			}
		}
	}

	delete [] pArguments;

	return nullptr;
}

CMonoMethod* CMonoEvent::GetAddMethod( void )
{
	return this->m_pClass->GetMethod( "add_" + this->GetName(), 0 );
}

CMonoMethod* CMonoEvent::GetRemoveMethod( void )
{
	return this->m_pClass->GetMethod( "remove_" + this->GetName(), 0 );
}

CMonoMethod* CMonoEvent::GetRaiseMethod( void )
{
	return this->m_pClass->GetMethod( "raise_" + this->GetName(), 0 );
}
