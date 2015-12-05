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

bool CEventManager::Add( string strName, DWORD pUserData, MonoObject* pMonoDelegate, bool bPropagated, string strPriority )
{
	if( !pUserData )
	{
		return false;
	}

	CEvent* pEvent = new CEvent( this, strName, pUserData, pMonoDelegate, bPropagated, strPriority );

	this->m_Events.insert( pair< string, CEvent* >( pEvent->GetName(), pEvent ) );

	return true;
}

bool CEventManager::Delete( string strName, DWORD pUserData, MonoObject* pMonoDelegate )
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

bool CEventManager::Call( string strName, void* pThis, list< CLuaArgument* > Arguments )
{
	CMonoMTALib* pMTALib = this->GetResource()->GetDomain()->GetMTALib();

	MonoObject* pThisObj = pMTALib->RegisterElement( pThis );

	if( !pThisObj )
	{
		return false;
	}

	DWORD pSource = 0;

	auto *iter = *Arguments.begin();

	if( iter->GetType() == LUA_TLIGHTUSERDATA )
	{
		pSource = (DWORD)iter->GetLightUserData();
	}

	void** params = new void*[ Arguments.size() ];

	this->ReadArgumens( Arguments, params );

	for( auto iter : this->m_Events )
	{
		CEvent* pEvent = iter.second;

		DWORD pElement = pEvent->GetElement();

		if( pEvent->GetName() == strName && ( pElement == (DWORD)pThis || ( pEvent->IsPropagated() && pElement == pSource ) ) )
		{
			pEvent->Call( (DWORD)pThis, params );
		}
	}

	delete[] params;

	CMonoClass* pClass = pMTALib->GetClass( "Element" );

	assert( pClass );

	strName[ 0 ] = toupper( strName[ 0 ] );

	CMonoEvent* pEvent = pClass->GetEvent( strName );

	if( pEvent )
	{
		return pEvent->Call( pThisObj, Arguments );
	}

	return true;
}

void CEventManager::ReadArgumens( list< CLuaArgument* > Arguments, void** params )
{
	CMonoDomain* pDomain = this->GetResource()->GetDomain();

	CMonoMTALib* pMTALib = pDomain->GetMTALib();
	CMonoCorlib* pCorlib = pDomain->GetCorlib();

	uint argc = 0;

	for( auto iter : Arguments )
	{
		int iLuaType = iter->GetType();

		switch( iLuaType )
		{
			case LUA_TBOOLEAN:
			{
				bool bValue = iter->GetBoolean();

				params[ argc++ ] = &bValue;

				break;
			}
			case LUA_TNUMBER:
			{
				double value = iter->GetNumber< double >();

				MonoObject* pObj = pCorlib->Class[ "double" ]->Box( &value );

				params[ argc++ ] = pObj;

				break;
			}
			case LUA_TSTRING:
			{
				const char* szValue = iter->GetString();

				MonoString* pString = pDomain->NewString( szValue );

				params[ argc++ ] = pString;

				break;
			}
			case LUA_TLIGHTUSERDATA:
			{
				void* pUserData = iter->GetLightUserData();

				MonoObject* pValue = pMTALib->RegisterElement( pUserData );

				if( pValue )
				{
					params[ argc++ ] = pValue;
				}
				else
				{
					params[ argc++ ] = pUserData;
				}

				break;
			}
			default:
			{
				break;
			}
		}
	}
}
