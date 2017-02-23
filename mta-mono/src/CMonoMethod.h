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

class CMonoMethod;

struct SMonoType;

#ifndef __CMONOMETHOD_H
#define __CMONOMETHOD_H

#include "CMonoClass.h"

struct SMonoType
{
	string strName;
	int iType;
};

class CMonoMethod
{
private:
	MonoMethod*						m_pMethod;

	CMonoClass*						m_pClass;

	vector< SMonoType >				m_ArgList;

	string							m_strName;
	string							m_strSignature;
	
private:
	void							ParseSignature			( void );

public:
									CMonoMethod				( CMonoClass* pClass, MonoMethod* pMethod );
									~CMonoMethod			( void );

	MonoObject*						Invoke					( PVOID pObject, PVOID* params, MonoObject** pException ) const;
	
	inline string					GetSignature			( void ) const	{ return this->m_strSignature; }
	inline vector< SMonoType >		GetArguments			( void ) const	{ return this->m_ArgList; }

	inline CMonoClass*				GetMonoClass			( void ) const	{ return this->m_pClass; }

	inline string					GetName					( void ) const	{ return this->m_strName; }

	inline MonoMethod*				operator *				( void ) const	{ return this->m_pMethod; }
};

#endif