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

#include "CMonoGC.h"
#include "CMonoDomain.h"
#include "CResource.h"

class CMonoInterface
{
private:
	MonoDomain*			m_pMonoDomain;

	CMonoGC*			m_pGC;

public:
						CMonoInterface		( void );
						~CMonoInterface		( void );

	CMonoDomain*		CreateAppdomain		( CResource* pResource, const char* szName, char* szConfig );

	void				SetDomain			( MonoDomain* pDomain = nullptr, bool bForce = false );

	CMonoGC*			GetGC				( void )	{ return this->m_pGC; }

#pragma region Static methods

	static string	GetBinariesDirectory( void )
	{
		return "mods/deathmatch/resources/[ire]";
	}

#pragma endregion
};

#endif