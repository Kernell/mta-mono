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
#include "CEventManager.h"

CEventManager::CEventManager( CResource* pResource )
{
	this->m_pResource = pResource;
}

CEventManager::~CEventManager( void )
{
	this->DeleteAll();

	this->m_pResource = nullptr;
}

bool CEventManager::Add( string strName, CElement* pElement, MonoObject* pMonoDelegate, bool bPropagated, string strPriority )
{
	if( !pElement )
	{
		return false;
	}

	CEvent* pEvent = new CEvent( this, strName, pElement, pMonoDelegate, bPropagated, strPriority );

	this->m_Events.insert( pair< string, CEvent* >( pEvent->GetName(), pEvent ) );

	return true;
}

bool CEventManager::Delete( string strName, CElement* pElement, MonoObject* pMonoDelegate )
{
	bool bFind = false;

	for( auto iter = this->m_Events.begin(); iter != this->m_Events.end(); iter++ )
	{
		CEvent* pEvent = iter->second;

		if( pEvent->GetName() == strName && ( pMonoDelegate == nullptr || pEvent->GetDelegate() == pMonoDelegate ) )
		{
			delete pEvent;

			this->m_Events.erase( iter );

			bFind = true;
		}
	}

	return bFind;
}

void CEventManager::DeleteAll( void )
{
	multimap< string, CEvent* >::iterator iter = this->m_Events.begin();

	while( iter != this->m_Events.end() )
	{
		CEvent* pEvent = iter->second;

		delete pEvent;

		this->m_Events.erase( iter++ );
	}
}

bool CEventManager::Call( const string& strName, CElement* pThis, list< CLuaArgument* > Arguments )
{
	CElementManager* pElementManager = this->m_pResource->GetElementManager();

	CMonoMTALib* pMTALib = this->m_pResource->GetDomain()->GetMTALib();

	CElement* pSource = nullptr;

	const auto& iter = *Arguments.begin();

	if( iter->GetType() == eLuaType::LightUserdata )
	{
		pSource = pElementManager->FindOrCreate( iter->GetLightUserData() );
	}

	CMonoArguments pArguments;

	this->ReadArgumens( Arguments, pArguments );

	for( const auto& iter : this->m_Events )
	{
		CEvent* pEvent = iter.second;

		CElement* pElement = pEvent->GetElement();

		if( pEvent->GetName() == strName && ( pElement == pThis || pEvent->IsPropagated( pSource ) ) )
		{
			pEvent->Call( pThis, *pArguments );
		}
	}

	CMonoClass* pClass = pMTALib->GetClass( pThis->GetTypeClassName() );

	ASSERT( pClass );

	if( pClass )
	{
		string strEventName = strName;

		strEventName[ 0 ] = toupper( strEventName[ 0 ] );

		CMonoEvent* pEvent = pClass->GetEvent( strEventName );

		if( pEvent )
		{
			return pEvent->Call( pThis, Arguments );
		}
	}

	return false;
}

void CEventManager::ReadArgumens( list< CLuaArgument* > Arguments, CMonoArguments& pArguments )
{
	CElementManager* pElementManager = this->m_pResource->GetElementManager();

	CMonoDomain* pDomain = this->m_pResource->GetDomain();

	CMonoMTALib* pMTALib = pDomain->GetMTALib();
	CMonoCorlib* pCorlib = pDomain->GetCorlib();

	for( const auto& iter : Arguments )
	{
		eLuaType iLuaType = iter->GetType();

		switch( iLuaType )
		{
			case eLuaType::Boolean:
			{
				bool bValue = iter->GetBoolean();

				pArguments.Push( bValue );

				break;
			}
			case eLuaType::Number:
			{
				double dValue = iter->GetNumber< double >();

				pArguments.Push( dValue );

				break;
			}
			case eLuaType::String:
			{
				const char* szValue = iter->GetString();

				MonoString* pString = pDomain->NewString( szValue );

				pArguments.Push( pString );

				break;
			}
			case eLuaType::LightUserdata:
			{
				CElement* pElement = pElementManager->FindOrCreate( iter->GetLightUserData() );

				ASSERT( pElement );

				pArguments.Push( pElement->GetMonoObject() );

				break;
			}
			default:
			{
				break;
			}
		}
	}
}
