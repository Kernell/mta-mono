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

bool CMonoEvent::Call( CElement* pThis, list< CLuaArgument* > argv )
{
	const CMonoMethod* pMethod = this->GetRaiseMethod();

	if( !pMethod )
	{
		return false;
	}

	CMonoArguments pArguments;
	
	if( !this->ParseArguments( pMethod, pArguments, argv ) )
	{
		this->m_pResource->ErrorPrintf( "Raise method for event '%s' not found\n", this->m_strName.c_str() );

		return false;
	}

	pMethod->Invoke( pThis->GetMonoObject(), *pArguments, nullptr );

	const auto& iter = *argv.begin();

	if( iter->GetType() == eLuaType::LightUserdata && iter->GetLightUserData() != pThis->GetLuaUserdata() )
	{
		pMethod->Invoke( pArguments[ 0 ], *pArguments, nullptr );
	}

	return true;
}

bool CMonoEvent::ParseArguments( const CMonoMethod* pMethod, CMonoArguments& pArguments, list< CLuaArgument* > argv )
{
	vector< SMonoType > pArgList = pMethod->GetArguments();

	if( pArgList.size() != argv.size() )
	{
		return false;
	}

	auto iter	= argv.begin();
	auto pType	= pArgList.begin();

	for( ; ; iter++, pType++ )
	{
		if( iter == argv.end() || pType == pArgList.end() )
		{
			return true;
		}

		eLuaType iLuaType = (*iter)->GetType();

		switch( pType->iType )
		{
			case MONO_TYPE_BOOLEAN: // System.Boolean
			{
				bool bValue = false;

				if( iLuaType == eLuaType::Boolean )
				{
					bValue = (*iter)->GetBoolean();
				}
				
				pArguments.Push( bValue );

				break;
			}
			case MONO_TYPE_CHAR: // System.Char
			{
				wchar_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< wchar_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_I1: // System.SByte
			{
				int8_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< int8_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_U1: // System.Byte
			{
				uint8_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< uint8_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_I2: // System.Int16
			{
				int16_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< int16_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_U2: // System.UInt16
			{
				uint16_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< uint16_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_I4: // System.Int32
			{
				int32_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< int32_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_U4: // System.UInt32
			{
				uint32_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< uint32_t >();
				}
					
				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_I8: // System.Int64
			{
				int64_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< int64_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_U8: // System.UInt64
			{
				uint64_t iValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					iValue = (*iter)->GetNumber< uint64_t >();
				}

				pArguments.Push( iValue );

				break;
			}
			case MONO_TYPE_R4: // System.Single
			{
				float fValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					fValue = (*iter)->GetNumber< float >();
				}

				pArguments.Push( fValue );

				break;
			}
			case MONO_TYPE_R8: // System.Double
			{
				double dValue = 0;

				if( iLuaType == eLuaType::Number )
				{
					dValue = (*iter)->GetNumber< double >();
				}

				pArguments.Push( dValue );

				break;
			}
			case MONO_TYPE_STRING: // System.String
			{
				string strValue = "";

				if( iLuaType == eLuaType::String )
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

				if( iLuaType == eLuaType::LightUserdata )
				{
					CElement* pElement = this->m_pResource->GetElementManager()->FindOrCreate( (*iter)->GetLightUserData() );

					ASSERT( pElement );

					auto typeName = pElement->GetTypeName();

					auto className = pElement->GetTypeClassName();

					pValue = pElement->GetMonoObject();
				}

				pArguments.Push( pValue );

				break;
			}
			case MONO_TYPE_I:
			case MONO_TYPE_U:
			default:
			{
				this->m_pResource->ErrorPrintf( "Unsupported type '%s (0x%X)' for '%s'\n", pType->strName.c_str(), pType->iType, this->m_strName.c_str() );

				break;
			}
		}
	}

	return false;
}

CMonoMethod* CMonoEvent::GetAddMethod( void ) const
{
	return this->m_pClass->GetMethod( "add_" + this->m_strName, 0 );
}

CMonoMethod* CMonoEvent::GetRemoveMethod( void ) const
{
	return this->m_pClass->GetMethod( "remove_" + this->m_strName, 0 );
}

CMonoMethod* CMonoEvent::GetRaiseMethod( void ) const
{
	return this->m_pClass->GetMethod( "raise_" + this->m_strName, 0 );
}
