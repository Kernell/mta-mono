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

#include "CElement.h"
#include "CResource.h"
#include "CEventManager.h"

class CEvent
{
private:
	string						m_strName;
	CElement*					m_pElement;
	MonoObject*					m_pMonoDelegate;
	bool						m_bPropagated;
	string						m_strPriority;


	CEventManager*				m_pEventManager;

public:
								CEvent					( CEventManager* pEventManager, string strName, CElement* pElement, MonoObject* pMonoDelegate, bool bPropagated, string strPriority );
								~CEvent					( void );

	bool						Call					( CElement* pThis, PVOID* params ) const;
	bool						IsPropagated			( CElement* pSource ) const;

	inline string				GetName					( void ) const		{ return this->m_strName; }
	inline CElement*			GetElement				( void ) const		{ return this->m_pElement; }
	inline MonoObject*			GetDelegate				( void ) const		{ return this->m_pMonoDelegate; }
	inline string				GetPriority				( void ) const		{ return this->m_strPriority; }
};

#endif