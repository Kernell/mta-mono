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

#include "CResource.h"
#include "CMonoInterface.h"

extern ILuaModuleManager10	*g_pModuleManager;

class CResourceManager
{
private:
	CMonoInterface*			m_pMono;

	list< CResource* >		m_List;

public:
					CResourceManager	( CMonoInterface* pMono );
					~CResourceManager	( void );

	CResource*		Create				( lua_State* luaVM, string strName );
	void			AddToList			( CResource* pResource );
	CResource*		GetFromList			( lua_State* pLuaVM );
	CResource*		GetFromList			( MonoDomain* pDomain );
	void			RemoveFromList		( CResource* pResource );
	void			DoPulse				( void );
};
#endif
