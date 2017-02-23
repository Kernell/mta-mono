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

#include "StdInc.h"
#include "CMonoGC.h"

CMonoGC::CMonoGC( void )
{
}

void CMonoGC::Collect( int iGeneration )
{
	mono_gc_collect( iGeneration );
}

unsigned int CMonoGC::Hold( MonoObject* pObject )
{
	if( pObject )
	{
		return mono_gchandle_new_weakref( pObject, false );
	}

	return -1;
}

unsigned int CMonoGC::HoldWithHope( MonoObject* pObject )
{
	if( pObject )
	{
		return mono_gchandle_new_weakref( pObject, true );
	}

	return -1;
}

unsigned int CMonoGC::Keep( MonoObject* pObject )
{
	if( pObject )
	{
		return mono_gchandle_new( pObject, false );
	}

	return -1;
}

unsigned int CMonoGC::Pin( MonoObject* pObject )
{
	if( pObject )
	{
		return mono_gchandle_new( pObject, true );
	}

	return -1;
}

int CMonoGC::GetMaxGeneration()
{
	return mono_gc_max_generation();
}

int64 CMonoGC::GetHeapSize()
{
	return mono_gc_get_heap_size();
}

void CMonoGC::ReleaseGCHandle( unsigned int uiHandle )
{
	mono_gchandle_free( uiHandle );
}

MonoObject* CMonoGC::GetGCHandleTarget( unsigned int uiHandle )
{
	return mono_gchandle_get_target( uiHandle );
}