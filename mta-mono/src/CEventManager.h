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

class CEventManager;

#ifndef __CEVENTMANAGER_H
#define __CEVENTMANAGER_H

#include "CResource.h"
#include "CMonoDomain.h"
#include "CEvent.h"

#include "extra/CLuaArgument.h"
#include "extra/CLuaArguments.h"

class CEventManager
{
private:
	CResource*					m_pResource;
    multimap< string, CEvent* >	m_Events;

public:
								CEventManager			( CResource* pResource );
								~CEventManager			( void );

	bool						Add						( string strName, DWORD pUserData, MonoObject* pMonoDelegate, bool bPropagated, string strPriority );
	bool						Delete					( string strName, DWORD pUserData, MonoObject* pMonoDelegate = nullptr );
	void						DeleteAll				( void );

	bool						Call					( string strName, void* pThis, list< CLuaArgument* > Arguments );

	void						ReadArgumens			( list< CLuaArgument* > Arguments, void** params );

	CResource*					GetResource( void )		{ return this->m_pResource; }
};

#endif
