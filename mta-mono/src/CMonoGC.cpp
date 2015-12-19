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

void CMonoGC::Collect( int generation )
{
	mono_gc_collect( generation );
}

unsigned int CMonoGC::Hold( MonoObject* obj )
{
	if( obj )
	{
		mono_gchandle_new_weakref( reinterpret_cast< MonoObject* >( obj ), false );
	}

	return -1;
}

unsigned int CMonoGC::HoldWithHope( MonoObject* obj )
{
	if( obj )
	{
		return mono_gchandle_new_weakref( reinterpret_cast< MonoObject* >( obj ), true );
	}

	return -1;
}

unsigned int CMonoGC::Keep( MonoObject* obj )
{
	if( obj )
	{
		return mono_gchandle_new( reinterpret_cast< MonoObject* >( obj ), false );
	}

	return -1;
}

unsigned int CMonoGC::Pin( MonoObject* obj )
{
	if( obj )
	{
		return mono_gchandle_new( reinterpret_cast< MonoObject* >( obj ), true );
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

void CMonoGC::ReleaseGCHandle( unsigned int handle )
{
	mono_gchandle_free( handle );
}

MonoObject* CMonoGC::GetGCHandleTarget( unsigned int handle )
{
	return mono_gchandle_get_target( handle );
}