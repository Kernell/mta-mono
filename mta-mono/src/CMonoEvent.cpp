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
	this->m_pResource		= pClass->GetDomain()->GetResource();
	this->m_pAddMethod		= nullptr;
	this->m_pRemoveMethod	= nullptr;
	this->m_pRaiseMethod	= nullptr;

	this->m_strName			= mono_event_get_name( pEvent );
}

CMonoEvent::~CMonoEvent( void )
{
	this->m_pResource		= nullptr;
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

	CMonoArguments pArguments;
	
	if( !this->ParseArguments( pArguments, argv ) )
	{
		this->m_pResource->ErrorPrintf( "Raise method for event '%s' not found\n", this->GetName().c_str() );

		return false;
	}

	pMethod->Invoke( pThis, *pArguments, nullptr );

	const auto& iter = *argv.begin();

	if( iter->GetType() == LUA_TLIGHTUSERDATA )
	{
		pMethod->Invoke( pArguments[ 0 ], *pArguments, nullptr );
	}

	return true;
}

bool CMonoEvent::ParseArguments( CMonoArguments& pArguments, list< CLuaArgument* > argv )
{
	CMonoMTALib* pMTALib = this->m_pClass->GetDomain()->GetMTALib();
	CMonoCorlib* pCorlib = this->m_pClass->GetDomain()->GetCorlib();

	const auto& pMethods = this->m_pClass->GetMethods( "raise_" + this->GetName() );

	for( const auto& pMethod : pMethods )
	{
		vector< SMonoType > pArgList = pMethod->GetArguments();

		if( pArgList.size() != argv.size() )
		{
			continue;
		}

		auto iter	= argv.begin();
		auto pType	= pArgList.begin();

		for( ; ; iter++, pType++ )
		{
			if( iter == argv.end() || pType == pArgList.end() )
			{
				return true;
			}

			int iLuaType = (*iter)->GetType();

			switch( pType->iType )
			{
				case MONO_TYPE_BOOLEAN: // System.Boolean
				{
					bool bValue = false;

					if( iLuaType == LUA_TBOOLEAN )
					{
						bValue = (*iter)->GetBoolean();
					}
				
					pArguments.Push( bValue );

					break;
				}
				case MONO_TYPE_CHAR: // System.Char
				{
					wchar_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< wchar_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_I1: // System.SByte
				{
					int8_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< int8_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_U1: // System.Byte
				{
					uint8_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< uint8_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_I2: // System.Int16
				{
					int16_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< int16_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_U2: // System.UInt16
				{
					uint16_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< uint16_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_I4: // System.Int32
				{
					int32_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< int32_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_U4: // System.UInt32
				{
					uint32_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< uint32_t >();
					}
					
					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_I8: // System.Int64
				{
					int64_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< int64_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_U8: // System.UInt64
				{
					uint64_t iValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						iValue = (*iter)->GetNumber< uint64_t >();
					}

					pArguments.Push( iValue );

					break;
				}
				case MONO_TYPE_R4: // System.Single
				{
					float fValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						fValue = (*iter)->GetNumber< float >();
					}

					pArguments.Push( fValue );

					break;
				}
				case MONO_TYPE_R8: // System.Double
				{
					double dValue = 0;

					if( iLuaType == LUA_TNUMBER )
					{
						dValue = (*iter)->GetNumber< double >();
					}

					pArguments.Push( dValue );

					break;
				}
				case MONO_TYPE_STRING: // System.String
				{
					string strValue = "";

					if( iLuaType == LUA_TSTRING )
					{
						strValue = (*iter)->GetString();
					}

					MonoString* pString = this->m_pResource->GetDomain()->NewString( strValue );
					
					pArguments.Push( pString );

					break;
				}
				case MONO_TYPE_OBJECT: // System.Object
				case MONO_TYPE_CLASS:
				{
					MonoObject* pValue = nullptr;

					if( iLuaType == LUA_TLIGHTUSERDATA )
					{
						CElement* pElement = this->m_pResource->GetElementManager()->FindOrCreate( (*iter)->GetLightUserData() );

						pValue = pElement->ToMonoObject();
					}

					pArguments.Push( pValue );

					break;
				}
				case MONO_TYPE_I:
				case MONO_TYPE_U:
				default:
				{
					this->m_pResource->ErrorPrintf( "Unsupported type '%s (0x%i)' for '%s'\n", pType->strName.c_str(), pType->iType, this->GetName().c_str() );

					break;
				}
			}
		}
	}

	return false;
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
