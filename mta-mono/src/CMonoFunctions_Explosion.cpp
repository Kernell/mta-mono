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
bool CMonoFunctions::Explosion::Create( MonoObject* pPosition, unsigned char ucType, TElement pArgCreator )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		PVOID pCreator = nullptr;

		if( pArgCreator )
		{
			pCreator = pResource->GetElementManager()->GetFromList( pArgCreator )->GetLuaUserdata();
		}

		return CLuaFunctionDefinitions::CreateExplosion( pResource->GetLua(), Vector3( pPosition ), ucType, pArgCreator );
	}

	return false;
}