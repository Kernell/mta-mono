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

class CRegisteredCommands;

#ifndef __CREGISTEREDCOMMANDS_H
#define __CREGISTEREDCOMMANDS_H

#include "CElement.h"
#include "CResource.h"

class CRegisteredCommands
{
private:
	struct SCommand
    {
		string			strName;
		MonoObject*		pDelegate;
		bool			bRestricted;
		bool			bCaseSensitive;
    };

	typedef list< SCommand* >::iterator			iterator;
	typedef list< SCommand* >::const_iterator	const_iterator;

	CResource*					m_pResource;

	list< SCommand* >			m_Commands;

public:
								CRegisteredCommands					( CResource* pResource );
								~CRegisteredCommands				( void );

	bool						Add									( string strCommandName, MonoObject* pDelegate, bool bRestricted = false, bool bCaseSensitive = true );
	bool						Execute								( CElement* pPlayer, string strCommandName, list< string > argv );
	bool						Remove								( string strCommandName, MonoObject* pDelegate = nullptr );

	void						ClearCommands						( void );

private:
	void						Invoke								( CElement* pPlayer, MonoObject* pDelegate, const string& strCommandName, list< string > argv );
	SCommand*					GetCommand							( string strName );
};

#endif
