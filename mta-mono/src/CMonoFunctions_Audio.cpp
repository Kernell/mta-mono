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

// Audio funcs
bool CMonoFunctions::Audio::PlayFrontEnd( TElement pThis, unsigned char ucSound )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::PlaySoundFrontEnd( pResource->GetLua(), pElement->GetLuaUserdata(), ucSound );
	}

	return false;
}

bool CMonoFunctions::Audio::PlayMission( TElement pThis, MonoObject* pPosition, unsigned short usSlot )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition( pPosition );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::PlayMissionAudio( pResource->GetLua(), pElement->GetLuaUserdata(), vecPosition, usSlot );
	}

	return false;
}
