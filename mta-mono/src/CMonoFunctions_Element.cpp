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

// Element create/destroy

void CMonoFunctions::Element::Ctor( TElement pThis, MonoString* msTypeName, MonoString* msID )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szTypeName = mono_string_to_utf8( msTypeName );
		const char* szID = mono_string_to_utf8( msID );

		PVOID pUserData = CLuaFunctionDefinitions::CreateElement( pResource->GetLua(), szTypeName, szID );

		if( pUserData )
		{
			pResource->GetElementManager()->Create( pThis, pUserData );
		}
	}
}

bool CMonoFunctions::Element::Destroy( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::DestroyElement( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return false;
}

TElement CMonoFunctions::Element::Clone( TElement pThis, MonoObject* vecPosition, bool bCloneElement )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::CloneElement( pResource->GetLua(), pElement->ToLuaUserData(), Vector3( vecPosition ), bCloneElement );

		if( pUserData )
		{
			return pResource->GetElementManager()->Create( nullptr, pUserData )->ToMonoObject();
		}
	}

	return false;
}

// Element get funcs

TElement CMonoFunctions::Element::GetRootElement( void )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		PVOID pUserData = CLuaFunctionDefinitions::GetRootElement( pResource->GetLua() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

MonoArray* CMonoFunctions::Element::GetByType( MonoString* msType, TElement pArgStartElement )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szType = mono_string_to_utf8( msType );

		PVOID pStartElement = nullptr;

		if( pArgStartElement )
		{
			pStartElement = pResource->GetElementManager()->GetFromList( pArgStartElement )->ToLuaUserData();
		}

		CLuaArgumentsVector pLuaArguments = CLuaFunctionDefinitions::GetElementsByType( pResource->GetLua(), szType, pStartElement );

		if( pLuaArguments.size() > 0 )
		{
			CMonoClass* pElementClass = nullptr;

			const char* szTypeName = CElement::GetTypeClassName( szType );

			if( szTypeName )
			{
				pElementClass = pResource->GetDomain()->GetMTALib()->GetClass( szTypeName );
			}

			if( !pElementClass )
			{
				pElementClass = pResource->GetDomain()->GetMTALib()->GetClass( "Element" );
			}

			return pResource->GetDomain()->NewElementArray( pElementClass->GetMonoPtr(), pLuaArguments );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Element::IsElement( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		ASSERT( pElement );

		return CLuaFunctionDefinitions::IsElement( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return false;
}

uint32_t CMonoFunctions::Element::GetUserData( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( pElement )
		{
			return reinterpret_cast< uint32_t >( pElement->ToLuaUserData() );
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Element::GetElementType( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		const string strType = CLuaFunctionDefinitions::GetElementType( pResource->GetLua(), pElement->ToLuaUserData() );

		return pResource->GetDomain()->NewString( strType );
	}

	return nullptr;
}

TElement CMonoFunctions::Element::GetByID( MonoString* msID, unsigned int uiIndex )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szID = mono_string_to_utf8( msID );

		PVOID pUserData = CLuaFunctionDefinitions::GetElementByID( pResource->GetLua(), szID, uiIndex );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Element::GetByIndex( int iIndex )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		PVOID pUserData = CLuaFunctionDefinitions::GetElementByIndex( pResource->GetLua(), iIndex );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Element::GetChild( TElement pThis, int iIndex )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetElementChild( pResource->GetLua(), pElement->ToLuaUserData(), iIndex );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

int CMonoFunctions::Element::GetChildrenCount( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::GetElementChildrenCount( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return 0;
}

MonoString* CMonoFunctions::Element::GetID( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		const string strID = CLuaFunctionDefinitions::GetElementID( pResource->GetLua(), pElement->ToLuaUserData() );

		return mono_string_new( mono_domain_get(), strID.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

TElement CMonoFunctions::Element::GetParent( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetElementParent( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Element::GetPosition( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementPosition( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Element::GetRotation( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementRotation( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Element::GetVelocity( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementVelocity( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

unsigned char CMonoFunctions::Element::GetInterior( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucInterior;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementInterior( pResource->GetLua(), pElement->ToLuaUserData(), ucInterior ) )
		{
			return ucInterior;
		}
	}

	return 0;
}

bool CMonoFunctions::Element::IsWithinColShape( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bWithin;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::IsElementWithinColShape( pResource->GetLua(), pElement->ToLuaUserData(), bWithin ) )
		{
			return bWithin;
		}
	}

	return false;
}

bool CMonoFunctions::Element::IsWithinMarker( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bWithin;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::IsElementWithinMarker( pResource->GetLua(), pElement->ToLuaUserData(), bWithin ) )
		{
			return bWithin;
		}
	}

	return false;
}

unsigned short CMonoFunctions::Element::GetDimension( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned short usDimension;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementDimension( pResource->GetLua(), pElement->ToLuaUserData(), usDimension ) )
		{
			return usDimension;
		}
	}

	return 0;
}

MonoString* CMonoFunctions::Element::GetZoneName( TElement pThis, bool bCitiesOnly )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strOutName;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementZoneName( pResource->GetLua(), pElement->ToLuaUserData(), strOutName, bCitiesOnly ) )
		{
			return pResource->GetDomain()->NewString( strOutName );
		}
	}

	return nullptr;
}

bool CMonoFunctions::Element::IsAttached( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::IsElementAttached( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return false;
}

TElement CMonoFunctions::Element::GetAttachedTo( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetElementAttachedTo( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Element::GetColShape( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetElementColShape( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

unsigned char CMonoFunctions::Element::GetAlpha( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned char ucAlpha;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetElementAlpha( pResource->GetLua(), pElement->ToLuaUserData(), ucAlpha ) )
		{
			return ucAlpha;
		}
	}

	return 0;
}

bool CMonoFunctions::Element::IsDoubleSided( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bDoubleSided;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::IsElementDoubleSided( pResource->GetLua(), pElement->ToLuaUserData(), bDoubleSided ) )
		{
			return bDoubleSided;
		}
	}

	return false;
}

float CMonoFunctions::Element::GetHealth( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		float fHealth;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementHealth( pResource->GetLua(), pElement->ToLuaUserData(), fHealth ) )
		{
			return fHealth;
		}
	}

	return false;
}

unsigned short CMonoFunctions::Element::GetModel( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		unsigned short usModel;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementModel( pResource->GetLua(), pElement->ToLuaUserData(), usModel ) )
		{
			return usModel;
		}
	}

	return false;
}

bool CMonoFunctions::Element::IsInWater( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bInWater;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::IsElementInWater( pResource->GetLua(), pElement->ToLuaUserData(), bInWater ) )
		{
			return bInWater;
		}
	}

	return false;
}

MonoObject* CMonoFunctions::Element::GetAttachedOffsetPosition( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition, vecRotation;
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetElementAttachedOffsets( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition, vecRotation ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecPosition );
		}
	}

	return nullptr;
}

MonoObject* CMonoFunctions::Element::GetAttachedOffsetRotation( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3 vecPosition, vecRotation;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::GetElementAttachedOffsets( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition, vecRotation ) )
		{
			return pResource->GetDomain()->GetMTALib()->Vector3->New( vecRotation );
		}
	}

	return nullptr;
}

TElement CMonoFunctions::Element::GetSyncer( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		PVOID pUserData = CLuaFunctionDefinitions::GetElementSyncer( pResource->GetLua(), pElement->ToLuaUserData() );

		if( pUserData )
		{
			return pResource->GetElementManager()->FindOrCreate( pUserData )->ToMonoObject();
		}
	}

	return nullptr;
}

bool CMonoFunctions::Element::GetCollisionsEnabled( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::GetElementCollisionsEnabled( pResource->GetLua(), pElement->ToLuaUserData() );
	}

	return false;
}

bool CMonoFunctions::Element::IsFrozen( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bFrozen;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsElementFrozen( pResource->GetLua(), pElement->ToLuaUserData(), bFrozen ) )
		{
			return bFrozen;
		}
	}

	return false;
}

TElement CMonoFunctions::Element::GetLowLod( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		PVOID pLODUserData;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		if( CLuaFunctionDefinitions::GetLowLodElement( pResource->GetLua(), pElement->ToLuaUserData(), pLODUserData ) )
		{
			if( pLODUserData )
			{
				return pResource->GetElementManager()->FindOrCreate( pLODUserData )->ToMonoObject();
			}
		}
	}

	return nullptr;
}

bool CMonoFunctions::Element::IsLowLod( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		bool bIsLowLod;

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		
		if( CLuaFunctionDefinitions::IsElementLowLod( pResource->GetLua(), pElement->ToLuaUserData(), bIsLowLod ) )
		{
			return bIsLowLod;
		}
	}

	return false;
}

// Element set funcs

bool CMonoFunctions::Element::ClearVisibleTo( TElement pThis )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::ClearElementVisibleTo( pResource->GetLua(), pElement->ToLuaUserData() );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetID( TElement pThis, MonoString* msID )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementID( pResource->GetLua(), pElement->ToLuaUserData(), mono_string_to_utf8( msID ) );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetData( TElement pThis, MonoString* msKey, CLuaArgument& Variable )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strKey( mono_string_to_utf8( msKey ) );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementData( pResource->GetLua(), pElement->ToLuaUserData(), strKey, Variable );
	}
	
	return false;
}

bool CMonoFunctions::Element::RemoveData( TElement pThis, MonoString* msKey )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		string strKey( mono_string_to_utf8( msKey ) );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::RemoveElementData( pResource->GetLua(), pElement->ToLuaUserData(), strKey );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetParent( TElement pThis, TElement pTarget )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pElementTarget = pResource->GetElementManager()->GetFromList( pTarget );

		return CLuaFunctionDefinitions::SetElementParent( pResource->GetLua(), pElement->ToLuaUserData(), pElementTarget->ToLuaUserData() );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetPosition( TElement pThis, MonoObject* pPosition, bool bWarp )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementPosition( pResource->GetLua(), pElement->ToLuaUserData(), Vector3( pPosition ), bWarp );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetRotation( TElement pThis, MonoObject* pRotation, MonoString* msRotationOrder, bool bNewWay )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		const char* szRotationOrder = mono_string_to_utf8( msRotationOrder );

		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementRotation( pResource->GetLua(), pElement->ToLuaUserData(), Vector3( pRotation ), szRotationOrder, bNewWay );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetVelocity( TElement pThis, MonoObject* pVelocity )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementVelocity( pResource->GetLua(), pElement->ToLuaUserData(), Vector3( pVelocity ) );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetVisibleTo( TElement pThis, TElement pTarget, bool bVisible )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pElementTarget = pResource->GetElementManager()->GetFromList( pTarget );

		return CLuaFunctionDefinitions::SetElementVisibleTo( pResource->GetLua(), pElement->ToLuaUserData(), pElementTarget->ToLuaUserData(), bVisible );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetInterior( TElement pThis, int iInterior )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementInterior( pResource->GetLua(), pElement->ToLuaUserData(), iInterior );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetDimension( TElement pThis, int iDimension )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementDimension( pResource->GetLua(), pElement->ToLuaUserData(), iDimension );
	}
	
	return false;
}

bool CMonoFunctions::Element::Attach( TElement pThis, TElement pTarget, MonoObject* pMonoPosition, MonoObject* pMonoRotation )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3
			vecPosition( pMonoPosition ),
			vecRotation( pMonoRotation );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pElementTarget = pResource->GetElementManager()->GetFromList( pTarget );

		return CLuaFunctionDefinitions::AttachElements( pResource->GetLua(), pElement->ToLuaUserData(), pElementTarget->ToLuaUserData(), vecPosition, vecRotation );
	}
	
	return false;
}

bool CMonoFunctions::Element::Detach( TElement pThis, TElement pTarget )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pElementTarget = pResource->GetElementManager()->GetFromList( pTarget );

		return CLuaFunctionDefinitions::DetachElements( pResource->GetLua(), pElement->ToLuaUserData(), pElementTarget->ToLuaUserData() );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetAlpha( TElement pThis, int iAlpha )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementAlpha( pResource->GetLua(), pElement->ToLuaUserData(), iAlpha );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetDoubleSided( TElement pThis, bool bDoubleSided )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementDoubleSided( pResource->GetLua(), pElement->ToLuaUserData(), bDoubleSided );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetHealth( TElement pThis, float fHealth )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementHealth( pResource->GetLua(), pElement->ToLuaUserData(), fHealth );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetModel( TElement pThis, int iModel )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementModel( pResource->GetLua(), pElement->ToLuaUserData(), iModel );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetAttachedOffsets( TElement pThis, MonoObject* pMonoPosition, MonoObject* pMonoRotation )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		Vector3
			vecPosition( pMonoPosition ),
			vecRotation( pMonoRotation );
		
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementAttachedOffsets( pResource->GetLua(), pElement->ToLuaUserData(), vecPosition, vecRotation );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetSyncer( TElement pThis, TElement pPlayer )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );
		CElement* pElementPlayer = pResource->GetElementManager()->GetFromList( pPlayer );

		return CLuaFunctionDefinitions::SetElementSyncer( pResource->GetLua(), pElement->ToLuaUserData(), pElementPlayer->ToLuaUserData() );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetCollisionsEnabled( TElement pThis, bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementCollisionsEnabled( pResource->GetLua(), pElement->ToLuaUserData(), bEnabled );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetFrozen( TElement pThis, bool bFrozen )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetElementFrozen( pResource->GetLua(), pElement->ToLuaUserData(), bFrozen );
	}
	
	return false;
}

bool CMonoFunctions::Element::SetLowLod( TElement pThis, bool bEnabled )
{
	CResource* pResource = g_pModule->GetResourceManager()->GetFromList( mono_domain_get() );

	if( pResource )
	{
		CElement* pElement = pResource->GetElementManager()->GetFromList( pThis );

		return CLuaFunctionDefinitions::SetLowLodElement( pResource->GetLua(), pElement->ToLuaUserData(), bEnabled );
	}
	
	return false;
}
