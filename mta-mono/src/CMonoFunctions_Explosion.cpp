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
#include "CMonoFunctions.h"

// Explosion funcs
bool CMonoFunctions::Explosion::Create( MonoObject* pPosition, unsigned char ucType, DWORD pCreator )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::CreateExplosion( RESOURCE->GetLua(), Vector3( pPosition ), ucType, (void*)pCreator );
	}

	return NULL;
}