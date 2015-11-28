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

#include "CMonoFunctions.h"

// Audio funcs
bool CMonoFunctions::Audio::PlayFrontEnd( DWORD pUserData, unsigned char ucSound )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::PlaySoundFrontEnd( RESOURCE->GetLua(), (void*)pUserData, ucSound );
	}

	return false;
}

bool CMonoFunctions::Audio::PlayMission( DWORD pUserData, MonoObject* pPosition, unsigned short usSlot )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::PlayMissionAudio( RESOURCE->GetLua(), (void*)pUserData, Vector3( pPosition ), usSlot );
	}

	return false;
}
