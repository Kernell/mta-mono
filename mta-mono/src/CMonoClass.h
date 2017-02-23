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

	MonoObject*					New								( void ) const;
	MonoObject*					New								( SColor& pColor ) const;
	MonoObject*					New								( Vector2& vecVector ) const;
	MonoObject*					New								( Vector3& vecVector ) const;
	MonoObject*					New								( PVOID* args, int argc ) const;

	MonoObject*					Box								( PVOID value ) const;

	const char*					GetName							( void ) const;
	const char*					GetNameSpace					( void ) const;

	MonoMethod*					GetMethodFromName				( const string& strMethodName, int iParamCount ) const;
	MonoMethod*					GetMethod						( const string& strMethodName ) const;
	CMonoMethod*				GetMethod						( const string& strMethodName, uint uiIndex );
	list< CMonoMethod* >		GetMethods						( const string& strMethodName );

	CMonoEvent*					GetEvent						( const string& strEventName );
	MonoClassField*				GetField						( const string& strFieldName );

	inline MonoEventMap			GetAllEvents					( void ) const	{ return this->m_Events; }
	inline CMonoDomain*			GetDomain						( void ) const	{ return this->m_pDomain; }

	inline MonoClass*			operator *						( void ) const	{ return this->m_pClass; }
};

#endif