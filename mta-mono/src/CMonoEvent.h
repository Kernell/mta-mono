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

class CMonoEvent;

#ifndef __CMONOEVENT_H
#define __CMONOEVENT_H

#include "CMonoClass.h"
#include "CMonoMethod.h"

#include "extra/CLuaArgument.h"

class CMonoEvent
{
private:
	CMonoClass*					m_pClass;

	MonoEvent*					m_pEvent;
	MonoMethod*					m_pAddMethod;
	MonoMethod*					m_pRemoveMethod;
	MonoMethod*					m_pRaiseMethod;

	string						m_strName;

public:
								CMonoEvent					( CMonoClass* pClass, MonoEvent* pEvent );
								~CMonoEvent					( void );

	bool						Call						( MonoObject* pThis, list< CLuaArgument* > argv );
	void**						ParseArguments				( list< CLuaArgument* > argv );

	CMonoMethod*				GetAddMethod				( void );
	CMonoMethod*				GetRemoveMethod				( void );
	CMonoMethod*				GetRaiseMethod				( void );

	CMonoClass*					GetClass					( void )	{ return this->m_pClass; }
	MonoEvent*					GetMonoPtr					( void )	{ return this->m_pEvent; }

	string						GetName						( void )	{ return this->m_strName; }
};

#endif