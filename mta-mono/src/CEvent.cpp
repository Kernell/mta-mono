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
#include "CEvent.h"

CEvent::CEvent( CEventManager* pEventManager, string strName, CElement* pElement, MonoObject* pMonoDelegate, bool bPropagated, string strPriority )
{
	this->m_pEventManager	= pEventManager;

	this->m_strName			= strName;
	this->m_pElement		= pElement;
	this->m_pMonoDelegate	= pMonoDelegate;
	this->m_bPropagated		= bPropagated;
	this->m_strPriority		= strPriority;
}

CEvent::~CEvent( void )
{
	this->m_pMonoDelegate	= nullptr;
	this->m_pElement		= nullptr;

	this->m_pEventManager	= nullptr;
}

bool CEvent::IsPropagated( CElement* pSource ) const
{
	if( this->m_bPropagated )
	{
		CElement* pParent = pSource;

		while( pParent != this->m_pElement )
		{
			pParent = pParent->GetParent();

			if( !pParent )
			{
				return false;
			}
		}

		return true;
	}

	return false;
}

bool CEvent::Call( CElement* pThis, PVOID* params ) const
{
	CResource* pResource = this->m_pEventManager->GetResource();

	ASSERT( pResource );

	CMonoMTALib* pMTALib = pResource->GetDomain()->GetMTALib();

	ASSERT( pMTALib );

	pResource->GetDomain()->Set( false );

	MonoObject* pException = nullptr;

	mono_runtime_delegate_invoke( this->m_pMonoDelegate, params, &pException );

	pResource->GetDomain()->HandleException( pException );

	return pException == nullptr;
}
