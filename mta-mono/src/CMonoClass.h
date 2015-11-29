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

class CMonoClass
{
private:
	MonoClass*			m_pClass;

	CMonoDomain*		m_pDomain;

public:
						CMonoClass						( MonoClass* pMonoClass, CMonoDomain* pDomain );
						~CMonoClass						( void );

	MonoObject*			New								( void );
	MonoObject*			New								( SColor& pColor );
	MonoObject*			New								( Vector2& vecVector );
	MonoObject*			New								( Vector3& vecVector );
	MonoObject*			New								( void** args, int argc );

	const char*			GetName							( void );
	const char*			GetNameSpace					( void );

	MonoMethod*			GetMethod						( const char* szMethodName, int iParamCount );
	MonoMethod*			GetMethod						( const char* szMethodName );

	MonoClass*			GetMonoPtr						( void )	{ return this->m_pClass; }
	CMonoDomain*		GetDomain						( void )	{ return this->m_pDomain; }
};

#endif