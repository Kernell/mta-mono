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

	void			Collect				( int generation = -1 );

	unsigned int	Hold				( MonoObject* obj );
	unsigned int	HoldWithHope		( MonoObject* obj );
	unsigned int	Keep				( MonoObject* obj );
	unsigned int	Pin					( MonoObject* obj );

	int				GetMaxGeneration	( void );
	int64			GetHeapSize			( void );
	void			ReleaseGCHandle		( unsigned int handle );
	MonoObject*		GetGCHandleTarget	( unsigned int handle );
};

#endif