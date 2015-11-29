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

class CMonoCorlib;

#ifndef __CMONOCORLIB_H
#define __CMONOCORLIB_H

#include "CMonoDomain.h"
#include "CMonoClass.h"

class CMonoCorlib
{
private:
	MonoAssembly*		m_pAssembly;
	MonoImage*			m_pImage;
	CMonoDomain*		m_pDomain;

protected:
	map< const char*, CMonoClass* >		Class;

public:
						CMonoCorlib						( CMonoDomain* pDomain );
						~CMonoCorlib					( void );

	CMonoClass*			GetClass						( const char *szNameSpace, const char *szClassName );

	CMonoDomain*		GetDomain						( void )	{ return this->m_pDomain; }
};

#endif