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

class CMonoGC;

#ifndef __CMONOGC_H
#define __CMONOGC_H

class CMonoGC
{
public:
					CMonoGC				( void );

	void			Collect				( int iGeneration = -1 );

	unsigned int	Hold				( MonoObject* pObject );
	unsigned int	HoldWithHope		( MonoObject* pObject );
	unsigned int	Keep				( MonoObject* pObject );
	unsigned int	Pin					( MonoObject* pObject );

	int				GetMaxGeneration	( void );
	int64			GetHeapSize			( void );
	void			ReleaseGCHandle		( unsigned int uiHandle );
	MonoObject*		GetGCHandleTarget	( unsigned int uiHandle );
};

#endif