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

class CElementManager;

#ifndef __CELEMENT_MANAGER_H
#define __CELEMENT_MANAGER_H

#include "CElement.h"
#include "CResource.h"

class CElementManager
{
	friend CElement;

private:
	CResource*						m_pResource;
	list< CElement* >				m_List;

public:
									CElementManager		( CResource* pResource );
									~CElementManager	( void );

	void							DeleteAll			( void );

	CElement*                       Create              ( MonoObject* pObject, PVOID pUserdata );
	CElement*                       FindOrCreate        ( PVOID pUserdata );

	CElement*						GetFromList			( PVOID pUserdata );
	CElement*						GetFromList			( MonoObject* pMonoObject );

private:
	void							AddToList			( CElement* pElement );
	void							RemoveFromList		( CElement* pElement );
};

#endif
