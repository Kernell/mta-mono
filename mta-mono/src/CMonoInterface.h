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

class CMonoInterface;

#ifndef __CMONOINTERFACE_H
#define __CMONOINTERFACE_H

#include "CModule.h"
#include "CMonoGC.h"
#include "CMonoDomain.h"
#include "CResource.h"

#include "extra/CLuaArguments.h"

extern CModule* g_pModule;

class CMonoInterface
{
private:
	CModule*				m_pModule;
	MonoDomain*				m_pMonoDomain;
	CMonoGC*				m_pGC;

	static MonoAssembly*	m_pMTALib;

public:
							CMonoInterface					( CModule* pModule );
							~CMonoInterface					( void );

	CMonoDomain*			CreateAppdomain					( CResource* pResource, const char* szName, char* szConfig );

	void					SetDomain						( MonoDomain* pDomain = nullptr, bool bForce = false );

	inline CMonoGC*			GetGC							( void )	{ return this->m_pGC; }

	inline static string	GetBinariesDirectory			( void )	{ return "mods/deathmatch/resources/[ire]"; }

	static MonoAssembly*	GetMTALib						( void );

	static CLuaArguments	MonoArrayToLuaArguments			( MonoArray* pArray, CResource* pResource );

	static void				MonoPrintCallbackHandler		( const char *string, mono_bool is_stdout );
	static void				MonoPrintErrorCallbackHandler	( const char *string, mono_bool is_stdout );
};

#endif