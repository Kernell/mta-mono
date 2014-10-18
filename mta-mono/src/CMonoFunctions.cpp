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

#define MONO_DECLARE(a,b) mono_add_internal_call("MultiTheftAuto.Native."#a"::"#b,CMonoFunctions::a::b );

void CMonoFunctions::AddInternals( void )
{
	mono_add_internal_call( "MultiTheftAuto.Debug::Log",						CMonoFunctions::Debug::Log );
	mono_add_internal_call( "MultiTheftAuto.Debug::Info",						CMonoFunctions::Debug::Info );
	mono_add_internal_call( "MultiTheftAuto.Debug::Error",						CMonoFunctions::Debug::Error );

	mono_add_internal_call( "MultiTheftAuto.Native.Config::Get",				CMonoFunctions::Config::Get );
	mono_add_internal_call( "MultiTheftAuto.Native.Config::Set",				CMonoFunctions::Config::Set );

	// Element create/destroy
	MONO_DECLARE( Element, Create );
	MONO_DECLARE( Element, Destroy );
	MONO_DECLARE( Element, Clone );

	// Element get funcs
	MONO_DECLARE( Element, IsElement );
	MONO_DECLARE( Element, GetType );
	MONO_DECLARE( Element, GetByID );
	MONO_DECLARE( Element, GetByIndex );
	MONO_DECLARE( Element, GetChild );
	MONO_DECLARE( Element, GetChildrenCount );
	MONO_DECLARE( Element, GetID );
	MONO_DECLARE( Element, GetParent );
	MONO_DECLARE( Element, GetPosition );
	MONO_DECLARE( Element, GetRotation );
	MONO_DECLARE( Element, GetVelocity );
	MONO_DECLARE( Element, GetInterior );
	MONO_DECLARE( Element, IsWithinColShape );
	MONO_DECLARE( Element, IsWithinMarker );
	MONO_DECLARE( Element, GetDimension );
	MONO_DECLARE( Element, GetZoneName );
	MONO_DECLARE( Element, IsAttached );
	MONO_DECLARE( Element, GetAttachedTo );
	MONO_DECLARE( Element, GetColShape );
	MONO_DECLARE( Element, GetAlpha );
	MONO_DECLARE( Element, IsDoubleSided );
	MONO_DECLARE( Element, GetHealth );
	MONO_DECLARE( Element, GetModel );
	MONO_DECLARE( Element, IsInWater );
	MONO_DECLARE( Element, GetAttachedOffsetPosition );
	MONO_DECLARE( Element, GetAttachedOffsetRotation );
	MONO_DECLARE( Element, GetSyncer );
	MONO_DECLARE( Element, GetCollisionsEnabled );
	MONO_DECLARE( Element, IsFrozen );
	MONO_DECLARE( Element, GetLowLod );
	MONO_DECLARE( Element, IsLowLod );

	// Element set funcs
	MONO_DECLARE( Element, ClearVisibleTo );
	MONO_DECLARE( Element, SetID );
	MONO_DECLARE( Element, SetData );
	MONO_DECLARE( Element, RemoveData );
	MONO_DECLARE( Element, SetParent );
	MONO_DECLARE( Element, SetPosition );
	MONO_DECLARE( Element, SetRotation );
	MONO_DECLARE( Element, SetVelocity );
	MONO_DECLARE( Element, SetVisibleTo );
	MONO_DECLARE( Element, SetInterior );
	MONO_DECLARE( Element, SetDimension );
	MONO_DECLARE( Element, Attach );
	MONO_DECLARE( Element, Detach );
	MONO_DECLARE( Element, SetAlpha );
	MONO_DECLARE( Element, SetDoubleSided );
	MONO_DECLARE( Element, SetHealth );
	MONO_DECLARE( Element, SetModel );
	MONO_DECLARE( Element, SetAttachedOffsets );
	MONO_DECLARE( Element, SetSyncer );
	MONO_DECLARE( Element, SetCollisionsEnabled );
	MONO_DECLARE( Element, SetFrozen );
	MONO_DECLARE( Element, SetLowLod );

	// Vehicle create/destroy functions
	MONO_DECLARE( Vehicle, Create );
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

DWORD CMonoFunctions::Element::Create( MonoString* msTypeName, MonoString* msID )
{
	if( RESOURCE )
	{
		const char* szTypeName	= mono_string_to_utf8( msTypeName );
		const char* szID		= mono_string_to_utf8( msID );

		return (DWORD)CLuaFunctionDefinitions::CreateElement( RESOURCE->GetLua(), szTypeName, szID );
	}

	return NULL;
}

bool CMonoFunctions::Element::Destroy( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::DestroyElement( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

DWORD CMonoFunctions::Element::Clone( DWORD pUserData, MonoObject* vecPosition, bool bCloneElement )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( vecPosition );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );

		return (DWORD)CLuaFunctionDefinitions::CloneElement( RESOURCE->GetLua(), (void*)pUserData, Vector3( fX, fY, fZ ), bCloneElement );
	}

	return false;
}

// Element get funcs

bool CMonoFunctions::Element::IsElement( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (unsigned int)CLuaFunctionDefinitions::IsElement( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

MonoString* CMonoFunctions::Element::GetType( DWORD pUserData )
{
	if( RESOURCE )
	{
		const string strType = CLuaFunctionDefinitions::GetElementType( RESOURCE->GetLua(), (void*)pUserData );

		return mono_string_new( mono_domain_get(), strType.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

DWORD CMonoFunctions::Element::GetByID( MonoString* msID, unsigned int uiIndex )
{
	if( RESOURCE )
	{
		const char* szID = mono_string_to_utf8( msID );

		return (DWORD)CLuaFunctionDefinitions::GetElementByID( RESOURCE->GetLua(), szID, uiIndex );
	}

	return NULL;
}

DWORD CMonoFunctions::Element::GetByIndex( int iIndex )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetElementByIndex( RESOURCE->GetLua(), iIndex );
	}

	return NULL;
}

DWORD CMonoFunctions::Element::GetChild( DWORD pUserData, int iIndex )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetElementChild( RESOURCE->GetLua(), (void*)pUserData, iIndex );
	}

	return NULL;
}

int CMonoFunctions::Element::GetChildrenCount( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetElementChildrenCount( RESOURCE->GetLua(), (void*)pUserData );
	}

	return 0;
}

MonoString* CMonoFunctions::Element::GetID( DWORD pUserData )
{
	if( RESOURCE )
	{
		const string strID = CLuaFunctionDefinitions::GetElementID( RESOURCE->GetLua(), (void*)pUserData );

		return mono_string_new( mono_domain_get(), strID.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

unsigned int CMonoFunctions::Element::GetParent( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (unsigned int)CLuaFunctionDefinitions::GetElementParent( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetPosition( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetElementPosition( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( "MultiTheftAuto", "Vector3", vecPosition );
			
			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetRotation( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetElementRotation( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( "MultiTheftAuto", "Vector3", vecPosition );
			
			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetVelocity( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition;
		
		if( CLuaFunctionDefinitions::GetElementVelocity( RESOURCE->GetLua(), (void*)pUserData, vecPosition ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( "MultiTheftAuto", "Vector3", vecPosition );
			
			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}

unsigned char CMonoFunctions::Element::GetInterior( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucInterior;

		if( CLuaFunctionDefinitions::GetElementInterior( RESOURCE->GetLua(), (void*)pUserData, ucInterior ) )
		{
			return ucInterior;
		}
	}

	return 0;
}

bool CMonoFunctions::Element::IsWithinColShape( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bWithin;

		if( CLuaFunctionDefinitions::IsElementWithinColShape( RESOURCE->GetLua(), (void*)pUserData, bWithin ) )
		{
			return bWithin;
		}
	}

	return false;
}

bool CMonoFunctions::Element::IsWithinMarker( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bWithin;

		if( CLuaFunctionDefinitions::IsElementWithinMarker( RESOURCE->GetLua(), (void*)pUserData, bWithin ) )
		{
			return bWithin;
		}
	}

	return false;
}

unsigned short CMonoFunctions::Element::GetDimension( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned short usDimension;

		if( CLuaFunctionDefinitions::GetElementDimension( RESOURCE->GetLua(), (void*)pUserData, usDimension ) )
		{
			return usDimension;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Element::GetZoneName( DWORD pUserData, bool bCitiesOnly )
{
	if( RESOURCE )
	{
		string strOutName;

		if( CLuaFunctionDefinitions::GetElementZoneName( RESOURCE->GetLua(), (void*)pUserData, strOutName, bCitiesOnly ) )
		{
			return RESOURCE->NewString( strOutName );
		}
	}

	return NULL;
}

bool CMonoFunctions::Element::IsAttached( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::IsElementAttached( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

DWORD CMonoFunctions::Element::GetAttachedTo( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetElementAttachedTo( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

DWORD CMonoFunctions::Element::GetColShape( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetElementColShape( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

unsigned char CMonoFunctions::Element::GetAlpha( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned char ucAlpha;
		
		if( CLuaFunctionDefinitions::GetElementAlpha( RESOURCE->GetLua(), (void*)pUserData, ucAlpha ) )
		{
			return ucAlpha;
		}
	}

	return 0;
}

bool CMonoFunctions::Element::IsDoubleSided( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bDoubleSided;
		
		if( CLuaFunctionDefinitions::IsElementDoubleSided( RESOURCE->GetLua(), (void*)pUserData, bDoubleSided ) )
		{
			return bDoubleSided;
		}
	}

	return false;
}

float CMonoFunctions::Element::GetHealth( DWORD pUserData )
{
	if( RESOURCE )
	{
		float fHealth;
		
		if( CLuaFunctionDefinitions::GetElementHealth( RESOURCE->GetLua(), (void*)pUserData, fHealth ) )
		{
			return fHealth;
		}
	}

	return false;
}

unsigned short CMonoFunctions::Element::GetModel( DWORD pUserData )
{
	if( RESOURCE )
	{
		unsigned short usModel;
		
		if( CLuaFunctionDefinitions::GetElementModel( RESOURCE->GetLua(), (void*)pUserData, usModel ) )
		{
			return usModel;
		}
	}

	return false;
}

bool CMonoFunctions::Element::IsInWater( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bInWater;
		
		if( CLuaFunctionDefinitions::IsElementInWater( RESOURCE->GetLua(), (void*)pUserData, bInWater ) )
		{
			return bInWater;
		}
	}

	return false;
}

MonoObject* CMonoFunctions::Element::GetAttachedOffsetPosition( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition, vecRotation;
		
		if( CLuaFunctionDefinitions::GetElementAttachedOffsets( RESOURCE->GetLua(), (void*)pUserData, vecPosition, vecRotation ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( "MultiTheftAuto", "Vector3", vecPosition );
			
			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}

MonoObject* CMonoFunctions::Element::GetAttachedOffsetRotation( DWORD pUserData )
{
	if( RESOURCE )
	{
		Vector3 vecPosition, vecRotation;
		
		if( CLuaFunctionDefinitions::GetElementAttachedOffsets( RESOURCE->GetLua(), (void*)pUserData, vecPosition, vecRotation ) )
		{
			CMonoObject* pObject = RESOURCE->NewObject( "MultiTheftAuto", "Vector3", vecRotation );
			
			if( pObject )
			{
				return pObject->GetObject();
			}
		}
	}

	return NULL;
}

DWORD CMonoFunctions::Element::GetSyncer( DWORD pUserData )
{
	if( RESOURCE )
	{
		return (DWORD)CLuaFunctionDefinitions::GetElementSyncer( RESOURCE->GetLua(), (void*)pUserData );
	}

	return NULL;
}

bool CMonoFunctions::Element::GetCollisionsEnabled( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetElementCollisionsEnabled( RESOURCE->GetLua(), (void*)pUserData );
	}

	return false;
}

bool CMonoFunctions::Element::IsFrozen( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bFrozen;
		
		if( CLuaFunctionDefinitions::IsElementFrozen( RESOURCE->GetLua(), (void*)pUserData, bFrozen ) )
		{
			return bFrozen;
		}
	}

	return false;
}

DWORD CMonoFunctions::Element::GetLowLod( DWORD pUserData )
{
	if( RESOURCE )
	{
		void* pUserData;

		if( CLuaFunctionDefinitions::GetLowLodElement( RESOURCE->GetLua(), (void*)pUserData, pUserData ) )
		{
			return (DWORD)pUserData;
		}
	}

	return NULL;
}

bool CMonoFunctions::Element::IsLowLod( DWORD pUserData )
{
	if( RESOURCE )
	{
		bool bIsLowLod;
		
		if( CLuaFunctionDefinitions::IsElementLowLod( RESOURCE->GetLua(), (void*)pUserData, bIsLowLod ) )
		{
			return bIsLowLod;
		}
	}

	return false;
}

// Element set funcs

bool CMonoFunctions::Element::ClearVisibleTo( DWORD pUserData )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::ClearElementVisibleTo( RESOURCE->GetLua(), (void*)pUserData );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetID( DWORD pUserData, MonoString* msID )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementID( RESOURCE->GetLua(), (void*)pUserData, string( mono_string_to_utf8( msID ) ) );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetData( DWORD pUserData, MonoString* msKey, CLuaArgument& Variable )
{
	if( RESOURCE )
	{
		string strKey( mono_string_to_utf8( msKey ) );

		return CLuaFunctionDefinitions::SetElementData( RESOURCE->GetLua(), (void*)pUserData, strKey, Variable );
	}
	
	return false;
}

bool CMonoFunctions::Element::RemoveData( DWORD pUserData, MonoString* msKey )
{
	if( RESOURCE )
	{
		string strKey( mono_string_to_utf8( msKey ) );

		return CLuaFunctionDefinitions::RemoveElementData( RESOURCE->GetLua(), (void*)pUserData, strKey );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetParent( DWORD pUserData, DWORD pTarget )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementParent( RESOURCE->GetLua(), (void*)pUserData, (void*)pTarget );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetPosition( DWORD pUserData, MonoObject* pPosition, bool bWarp )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( pPosition );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );

		return CLuaFunctionDefinitions::SetElementPosition( RESOURCE->GetLua(), (void*)pUserData, Vector3( fX, fY, fZ ), bWarp );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetRotation( DWORD pUserData, MonoObject* pRotation, MonoString* msRotationOrder, bool bNewWay )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( pRotation );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );

		const char* szRotationOrder = mono_string_to_utf8( msRotationOrder );

		return CLuaFunctionDefinitions::SetElementRotation( RESOURCE->GetLua(), (void*)pUserData, Vector3( fX, fY, fZ ), szRotationOrder, bNewWay );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetVelocity( DWORD pUserData, MonoObject* pVelocity )
{
	if( RESOURCE )
	{
		CMonoObject pPosition( pVelocity );
		
		float fX = pPosition.GetPropertyValue<float>( "X" );
		float fY = pPosition.GetPropertyValue<float>( "Y" );
		float fZ = pPosition.GetPropertyValue<float>( "Z" );
		
		return CLuaFunctionDefinitions::SetElementVelocity( RESOURCE->GetLua(), (void*)pUserData, Vector3( fX, fY, fZ ) );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetVisibleTo( DWORD pUserData, DWORD pTarget, bool bVisible )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementVisibleTo( RESOURCE->GetLua(), (void*)pUserData, (void*)pTarget, bVisible );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetInterior( DWORD pUserData, int iInterior )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementInterior( RESOURCE->GetLua(), (void*)pUserData, iInterior );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetDimension( DWORD pUserData, int iDimension )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementDimension( RESOURCE->GetLua(), (void*)pUserData, iDimension );
	}
	
	return false;
}

bool CMonoFunctions::Element::Attach( DWORD pUserData, DWORD pTarget, MonoObject* pMonoPosition, MonoObject* pMonoRotation )
{
	if( RESOURCE )
	{
		Vector3
			vecPosition, vecRotation;
		
		CMonoObject
			pPosition( pMonoPosition ), pRotation( pMonoRotation );
		
		vecPosition.fX = pPosition.GetPropertyValue<float>( "X" );
		vecPosition.fY = pPosition.GetPropertyValue<float>( "Y" );
		vecPosition.fZ = pPosition.GetPropertyValue<float>( "Z" );
		
		vecRotation.fX = pRotation.GetPropertyValue<float>( "X" );
		vecRotation.fY = pRotation.GetPropertyValue<float>( "Y" );
		vecRotation.fZ = pRotation.GetPropertyValue<float>( "Z" );
		
		return CLuaFunctionDefinitions::AttachElements( RESOURCE->GetLua(), (void*)pUserData, (void*)pTarget, vecPosition, vecRotation );
	}
	
	return false;
}

bool CMonoFunctions::Element::Detach( DWORD pUserData, DWORD pTarget )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::DetachElements( RESOURCE->GetLua(), (void*)pUserData, (void*)pTarget );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetAlpha( DWORD pUserData, int iAlpha )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementAlpha( RESOURCE->GetLua(), (void*)pUserData, iAlpha );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetDoubleSided( DWORD pUserData, bool bDoubleSided )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementDoubleSided( RESOURCE->GetLua(), (void*)pUserData, bDoubleSided );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetHealth( DWORD pUserData, float fHealth )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementHealth( RESOURCE->GetLua(), (void*)pUserData, fHealth );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetModel( DWORD pUserData, int iModel )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementModel( RESOURCE->GetLua(), (void*)pUserData, iModel );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetAttachedOffsets( DWORD pUserData, MonoObject* pMonoPosition, MonoObject* pMonoRotation )
{
	if( RESOURCE )
	{
		Vector3
			vecPosition, vecRotation;

		CMonoObject
			pPosition( pMonoPosition ), pRotation( pMonoRotation );
		
		vecPosition.fX = pPosition.GetPropertyValue<float>( "X" );
		vecPosition.fY = pPosition.GetPropertyValue<float>( "Y" );
		vecPosition.fZ = pPosition.GetPropertyValue<float>( "Z" );
		
		vecRotation.fX = pRotation.GetPropertyValue<float>( "X" );
		vecRotation.fY = pRotation.GetPropertyValue<float>( "Y" );
		vecRotation.fZ = pRotation.GetPropertyValue<float>( "Z" );
		
		return CLuaFunctionDefinitions::SetElementAttachedOffsets( RESOURCE->GetLua(), (void*)pUserData, vecPosition, vecRotation );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetSyncer( DWORD pUserData, DWORD pPlayer )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementSyncer( RESOURCE->GetLua(), (void*)pUserData, (void*)pPlayer );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetCollisionsEnabled( DWORD pUserData, bool bEnabled )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementCollisionsEnabled( RESOURCE->GetLua(), (void*)pUserData, bEnabled );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetFrozen( DWORD pUserData, bool bFrozen )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetElementFrozen( RESOURCE->GetLua(), (void*)pUserData, bFrozen );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetLowLod( DWORD pUserData, bool bEnabled )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetLowLodElement( RESOURCE->GetLua(), (void*)pUserData, bEnabled );
	}
	
	return false;
}


// Vehicle create/destroy functions

DWORD CMonoFunctions::Vehicle::Create( int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction, int variant1, int variant2 )
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

		return (DWORD)CLuaFunctionDefinitions::CreateVehicle( RESOURCE->GetLua(), model, fX, fY, fZ, fRX, fRY, fRZ, sNumberplate, direction, variant1, variant2 );
	}
	
	return NULL;
}

