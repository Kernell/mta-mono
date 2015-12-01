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

class CMonoClass;

#ifndef _C_MONOCLASS_H
#define _C_MONOCLASS_H

#include "CMonoDomain.h"
#include "CMonoEvent.h"
#include "CMonoMethod.h"

typedef map< string, list< CMonoMethod* > >		MonoMethodMap;
typedef map< string, list< MonoProperty* > >	MonoPropertyMap;
typedef map< string, CMonoEvent* >				MonoEventMap;
typedef map< string, MonoClassField* >			MonoClassFieldMap;

class CMonoClass
{
private:
	MonoClass*					m_pClass;

	CMonoDomain*				m_pDomain;

	MonoEventMap				m_Events;
	MonoMethodMap				m_Methods;
	MonoPropertyMap				m_Properties;
	MonoClassFieldMap			m_Fields;

public:
								CMonoClass						( MonoClass* pMonoClass, CMonoDomain* pDomain );
								~CMonoClass						( void );

	MonoObject*					New								( void );
	MonoObject*					New								( SColor& pColor );
	MonoObject*					New								( Vector2& vecVector );
	MonoObject*					New								( Vector3& vecVector );
	MonoObject*					New								( void** args, int argc );

	MonoObject*					Box								( void* value );

	const char*					GetName							( void );
	const char*					GetNameSpace					( void );

	MonoMethod*					GetMethodFromName				( string strMethodName, int iParamCount );
	MonoMethod*					GetMethod						( string strMethodName );
	CMonoMethod*				GetMethod						( string strMethodName, uint uiIndex );
	list< CMonoMethod* >		GetMethods						( string strMethodName );

	CMonoEvent*					GetEvent						( string strEventName );
	MonoClassField*				GetField						( string strFieldName );

	MonoEventMap				GetAllEvents					( void )	{ return this->m_Events; }

	MonoClass*					GetMonoPtr						( void )	{ return this->m_pClass; }
	CMonoDomain*				GetDomain						( void )	{ return this->m_pDomain; }
};

#endif