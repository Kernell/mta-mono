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

class CResourceManager;

#ifndef __CRESOURCEMANAGER_H
#define __CRESOURCEMANAGER_H

#include "CModule.h"
#include "CResource.h"
#include "CMonoInterface.h"

class CResourceManager
{
private:
	CModule*				m_pModule;
	CMonoInterface*			m_pMono;

	list< CResource* >		m_List;

public:
								CResourceManager	( CModule* pModule, CMonoInterface* pMono );
								~CResourceManager	( void );

	void						ResourceStopping	( lua_State* pLuaVM );
	void						ResourceStopped		( lua_State* pLuaVM );

	CResource*					Create				( lua_State* luaVM, string strName );
	void						AddToList			( CResource* pResource );
	CResource*					GetFromList			( lua_State* pLuaVM );
	CResource*					GetFromList			( MonoDomain* pDomain );
	void						RemoveFromList		( CResource* pResource );
	void						DoPulse				( void );

	inline CModule*				GetModule			( void )				{ return this->m_pModule; }
	inline CMonoInterface*		GetMono				( void )				{ return this->m_pMono; }
};
#endif
