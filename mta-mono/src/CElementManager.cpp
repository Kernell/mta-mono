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
#include "CElementManager.h"

CElementManager::CElementManager( CResource* pResource )
{
	this->m_pResource = pResource;
}

CElementManager::~CElementManager( void )
{
	this->DeleteAll();

	this->m_pResource = nullptr;
}

void CElementManager::DeleteAll( void )
{
	auto clonedList = this->m_List;

	this->m_List.clear();

	for( const auto iter: clonedList )
	{
		delete iter;
	}
}

CElement* CElementManager::Create( MonoObject* pObject, PVOID pUserdata )
{
	string strTypeName;
	
	if( pObject == nullptr )
	{
		string _tmp;

		if( CLuaFunctionDefinitions::IsElement( this->m_pResource->GetLua(), pUserdata ) )
		{
			strTypeName = CLuaFunctionDefinitions::GetElementType( this->m_pResource->GetLua(), pUserdata );
		}
		else if( CLuaFunctionDefinitions::GetResourceName( this->m_pResource->GetLua(), pUserdata, _tmp ) )
		{
			strTypeName = "resource";
		}

		const char* szClassName = CElement::GetTypeClassName( CElement::GetTypeByName( strTypeName ) );

		CMonoClass* pClass = this->m_pResource->GetDomain()->GetMTALib()->GetClass( szClassName );

		if( pClass )
		{
			pObject = pClass->New();
		}
		else
		{
			this->m_pResource->ErrorPrintf( "[mono] Could not find the 'MultiTheftAuto.%s' class\n", szClassName );
		}
	}

	if( pObject )
	{
		CElement* pElement = new CElement( this, pObject, pUserdata, this->m_pResource );

		pElement->SetTypeName( strTypeName );

		return pElement;
	}

	return nullptr;
}

CElement* CElementManager::FindOrCreate( PVOID pUserdata )
{
	CElement* pElement;

	pElement = this->GetFromList( pUserdata );

	if( !pElement )
	{
		pElement = this->Create( nullptr, pUserdata );
	}

	return pElement;
}

void CElementManager::AddToList( CElement* pElement )
{
	this->m_List.push_back( pElement );
}

void CElementManager::RemoveFromList( CElement* pElement )
{
	this->m_List.remove( pElement );
}

CElement* CElementManager::GetFromList( PVOID pUserdata )
{
	for( const auto& pElement : this->m_List )
	{
		if( pElement->GetLuaUserdata() == pUserdata )
		{
			return pElement;
		}
	}

	return nullptr;
}

CElement* CElementManager::GetFromList( MonoObject* pMonoObject )
{
	for( const auto& pElement : this->m_List )
	{
		if( pElement->GetMonoObject() == pMonoObject )
		{
			return pElement;
		}
	}

	return nullptr;
}
