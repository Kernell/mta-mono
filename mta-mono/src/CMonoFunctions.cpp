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
#include "CMonoObject.h"

#include "CResource.h"
#include "CResourceManager.h"

extern ILuaModuleManager10	*g_pModuleManager;
extern CResourceManager	*g_pResourceManager;

#define RESOURCE g_pResourceManager->GetFromList( mono_domain_get() )

void CMonoFunctions::AddInternals( void )
{
	mono_add_internal_call( "MultiTheftAuto.Debug::Log",						CMonoFunctions::Debug::Log );
	mono_add_internal_call( "MultiTheftAuto.Debug::Info",						CMonoFunctions::Debug::Info );
	mono_add_internal_call( "MultiTheftAuto.Debug::Error",						CMonoFunctions::Debug::Error );

	mono_add_internal_call( "MultiTheftAuto.Native.Config::Get",				CMonoFunctions::Config::Get );
	mono_add_internal_call( "MultiTheftAuto.Native.Config::Set",				CMonoFunctions::Config::Set );

	// Element create/destroy
	mono_add_internal_call( "MultiTheftAuto.Native.Element::Create",			CMonoFunctions::Element::Create );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::Destroy",			CMonoFunctions::Element::Destroy );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::Clone",				CMonoFunctions::Element::Clone );

	// Element get funcs
	mono_add_internal_call( "MultiTheftAuto.Native.Element::IsElement",			CMonoFunctions::Element::IsElement );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetType",			CMonoFunctions::Element::GetType );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetByID",			CMonoFunctions::Element::GetByID );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetByIndex",		CMonoFunctions::Element::GetByIndex );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetChild",			CMonoFunctions::Element::GetChild );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetChildrenCount",	CMonoFunctions::Element::GetChildrenCount );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetID",				CMonoFunctions::Element::GetID );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetParent",			CMonoFunctions::Element::GetParent );
	mono_add_internal_call( "MultiTheftAuto.Native.Element::GetPosition",		CMonoFunctions::Element::GetPosition );

	mono_add_internal_call( "MultiTheftAuto.Native.Vehicle::Create",			CMonoFunctions::Vehicle::Create );
}

void CMonoFunctions::Debug::Log( MonoString *string )
{
	if( RESOURCE )
	{
		g_pModuleManager->Printf( "%s\n", mono_string_to_utf8( string ) );
	}
}

void CMonoFunctions::Debug::Info( MonoString *string )
{
	if( RESOURCE )
	{
		g_pModuleManager->DebugPrintf( RESOURCE->GetLua(), "%s\n", mono_string_to_utf8( string ) );
	}
}

void CMonoFunctions::Debug::Error( MonoString *string )
{
	if( RESOURCE )
	{
		

		g_pModuleManager->ErrorPrintf( "%s\n", mono_string_to_utf8( string ) );
	}
}

MonoString *CMonoFunctions::Config::Get( MonoString *msKey )
{
	if( RESOURCE )
	{
		string sValue = CLuaFunctionDefinitions::Get( RESOURCE->GetLua(), mono_string_to_utf8( msKey ) );

		return mono_string_new( mono_domain_get(), sValue.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

bool CMonoFunctions::Config::Set( MonoString *msKey, MonoString *msValue )
{
	if( RESOURCE )
	{
		const char* szKey	= mono_string_to_utf8( msKey );
		const char* szValue	= mono_string_to_utf8( msValue );

		return CLuaFunctionDefinitions::Set( RESOURCE->GetLua(), szKey, szValue );
	}

	return false;
}

// Element create/destroy

unsigned int CMonoFunctions::Element::Create( MonoString* msTypeName, MonoString* msID )
{
	if( RESOURCE )
	{
		const char* szTypeName	= mono_string_to_utf8( msTypeName );
		const char* szID		= mono_string_to_utf8( msID );

		return (unsigned int)CLuaFunctionDefinitions::CreateElement( RESOURCE->GetLua(), szTypeName, szID );
	}

	return NULL;
}

bool CMonoFunctions::Element::Destroy( unsigned int pElement )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::DestroyElement( RESOURCE->GetLua(), (void*)pElement );
	}

	return false;
}

unsigned int CMonoFunctions::Element::Clone( unsigned int pUserData, MonoObject* vecPosition, bool bCloneElement )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( vecPosition );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );

		return (unsigned int)CLuaFunctionDefinitions::CloneElement( RESOURCE->GetLua(), (void*)pUserData, Vector3( fX, fY, fZ ), bCloneElement );
	}

	return false;
}

// Element get funcs

bool CMonoFunctions::Element::IsElement( unsigned int pUserData )
{
	if( RESOURCE )
	{
		return (unsigned int)CLuaFunctionDefinitions::IsElement( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

MonoString* CMonoFunctions::Element::GetType( unsigned int pUserData )
{
	if( RESOURCE )
	{
		const string strType = CLuaFunctionDefinitions::GetElementType( RESOURCE->GetLua(), (void*)pUserData );

		return mono_string_new( mono_domain_get(), strType.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

unsigned int CMonoFunctions::Element::GetByID( MonoString* msID, unsigned int uiIndex )
{
	if( RESOURCE )
	{
		const char* szID = mono_string_to_utf8( msID );

		return (unsigned int)CLuaFunctionDefinitions::GetElementByID( RESOURCE->GetLua(), szID, uiIndex );
	}

	return NULL;
}

unsigned int CMonoFunctions::Element::GetByIndex( int iIndex )
{
	if( RESOURCE )
	{
		return (unsigned int)CLuaFunctionDefinitions::GetElementByIndex( RESOURCE->GetLua(), iIndex );
	}

	return NULL;
}

unsigned int CMonoFunctions::Element::GetChild( unsigned int pUserData, int iIndex )
{
	if( RESOURCE )
	{
		return (unsigned int)CLuaFunctionDefinitions::GetElementChild( RESOURCE->GetLua(), (void*)pUserData, iIndex );
	}

	return NULL;
}

int CMonoFunctions::Element::GetChildrenCount( unsigned int pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetElementChildrenCount( RESOURCE->GetLua(), (void*)pUserData );
	}

	return 0;
}

MonoString* CMonoFunctions::Element::GetID( unsigned int pUserData )
{
	if( RESOURCE )
	{
		const string strID = CLuaFunctionDefinitions::GetElementID( RESOURCE->GetLua(), (void*)pUserData );

		return mono_string_new( mono_domain_get(), strID.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

unsigned int CMonoFunctions::Element::GetParent( unsigned int pUserData )
{
	if( RESOURCE )
	{
		return (unsigned int)CLuaFunctionDefinitions::GetElementParent( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetPosition( unsigned int pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetElementPosition( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoClass* pClass = RESOURCE->GetClassFromName( "MultiTheftAuto", "Vector3" );
			
			if( pClass )
			{
				CMonoObject* pObject = pClass->New( mono_domain_get(), vecPosition );
				
				if( pObject )
				{
					return pObject->GetObject();
				}
				else
				{
					g_pModuleManager->ErrorPrintf( "%s:%d: failed to create instance of 'MultiTheftAuto::Vector3'\n", __FILE__, __LINE__ );
				}
			}
			else
			{
				g_pModuleManager->ErrorPrintf( "%s:%d: class 'MultiTheftAuto::Vector3' not found\n", __FILE__, __LINE__ );
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetRotation( unsigned int pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetElementRotation( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoClass* pClass = RESOURCE->GetClassFromName( "MultiTheftAuto", "Vector3" );
			
			if( pClass )
			{
				CMonoObject* pObject = pClass->New( mono_domain_get(), vecPosition );
				
				if( pObject )
				{
					return pObject->GetObject();
				}
				else
				{
					g_pModuleManager->ErrorPrintf( "%s:%d: failed to create instance of 'MultiTheftAuto::Vector3'\n", __FILE__, __LINE__ );
				}
			}
			else
			{
				g_pModuleManager->ErrorPrintf( "%s:%d: class 'MultiTheftAuto::Vector3' not found\n", __FILE__, __LINE__ );
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetVelocity( unsigned int pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetElementVelocity( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoClass* pClass = RESOURCE->GetClassFromName( "MultiTheftAuto", "Vector3" );
			
			if( pClass )
			{
				CMonoObject* pObject = pClass->New( mono_domain_get(), vecPosition );
				
				if( pObject )
				{
					return pObject->GetObject();
				}
				else
				{
					g_pModuleManager->ErrorPrintf( "%s:%d: failed to create instance of 'MultiTheftAuto::Vector3'\n", __FILE__, __LINE__ );
				}
			}
			else
			{
				g_pModuleManager->ErrorPrintf( "%s:%d: class 'MultiTheftAuto::Vector3' not found\n", __FILE__, __LINE__ );
			}
		}
	}

	return NULL;
}


unsigned int CMonoFunctions::Vehicle::Create( int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction, int variant1, int variant2 )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( position );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );
		
		CMonoObject pRotation( rotation );

		float fRX = pRotation.GetPropertyValue<float>( "X" );
		float fRY = pRotation.GetPropertyValue<float>( "Y" );
		float fRZ = pRotation.GetPropertyValue<float>( "Z" );

		string sNumberplate = "";

		if( numberplate && mono_string_length( numberplate ) > 0 )
		{
			sNumberplate = mono_string_to_utf8( numberplate );
		}

		void* pVehicle = CLuaFunctionDefinitions::CreateVehicle( RESOURCE->GetLua(), model, fX, fY, fZ, fRX, fRY, fRZ, sNumberplate, direction, variant1, variant2 );

		if( pVehicle )
		{
			return (unsigned int)pVehicle;
			//return 0x1337;
		}
	}
	
	return NULL;
}

