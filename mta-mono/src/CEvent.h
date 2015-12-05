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

class CEvent;

#ifndef __CEVENT_H
#define __CEVENT_H

#include "extra/CLuaArgument.h"
#include "extra/CLuaArguments.h"

#include "CResource.h"
#include "CEventManager.h"

class CEvent
{
private:
	string						m_strName;
	DWORD						m_pElement;
	MonoObject*					m_pMonoDelegate;
	bool						m_bPropagated;
	string						m_strPriority;


	CEventManager*				m_pEventManager;

public:
								CEvent					( CEventManager* pEventManager, string strName, DWORD pElement, MonoObject* pMonoDelegate, bool bPropagated, string strPriority );
								~CEvent					( void );

	bool						Call					( DWORD pThis, void** params );

	string						GetName					( void )		{ return this->m_strName; }
	DWORD						GetElement				( void )		{ return this->m_pElement; }
	MonoObject*					GetDelegate				( void )		{ return this->m_pMonoDelegate; }
	bool						IsPropagated			( void )		{ return this->m_bPropagated; }
	string						GetPriority				( void )		{ return this->m_strPriority; }
};

#endif