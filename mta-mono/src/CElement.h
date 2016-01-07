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

class CElement;

#ifndef __CELEMENT_H
#define __CELEMENT_H

#include "CResource.h"
#include "CElementManager.h"
#include "CMonoFunctions.h"

enum class eElementType
{
    Dummy,
    Player,
    Vehicle,
    Object,
    Marker,
    Blip,
    Pickup,
    RadarArea,
    SpawnpointDeprecated,
    RemoteclientDeprecated,
    Console,
    PathNodeUnused,
    WorldMeshUnused,
    Team,
    Ped,
    ColShape,
    ScriptFile,
    Water,
    Weapon,
    DatabaseConnection,
	Resource,
    Root,
    Unknown,
};

class CElement
{
public:
	static const map<eElementType, pair<string, string>> _eElementType;

	inline static const string GetTypeName( eElementType iType )
	{
		for( const auto& iter : _eElementType )
		{
			if( iter.first == iType )
			{
				return iter.second.first;
			}
		}

		return "unknown";
	}

	inline static const eElementType GetTypeByName( const string& strName )
	{
		for( const auto& iter : _eElementType )
		{
			if( iter.second.first == strName )
			{
				return iter.first;
			}
		}

		return eElementType::Unknown;
	}

	inline static const char* GetTypeClassName( eElementType iType )
	{
		for( const auto& iter : _eElementType )
		{
			if( iter.first == iType )
			{
				return iter.second.second.c_str();
			}
		}

		return nullptr;
	}

	inline static const char* GetTypeClassName( const string& strType )
	{
		for( const auto& iter : _eElementType )
		{
			if( iter.second.first == strType )
			{
				return iter.second.second.c_str();
			}
		}

		return nullptr;
	}

private:
	PVOID                                       m_pLuaUserdata;
	MonoObject*                                 m_pMonoObject;
	const CResource*                            m_pParent;
	CElementManager*						    m_pElementManager;

	eElementType                                m_iType;

	uint32_t                                    m_uiGCHandle;

public:
	                                            CElement                    ( CElementManager* pManager, MonoObject* pObject, PVOID pUserdata, const CResource* pParent = nullptr );
    virtual                                     ~CElement                   ( void );
	inline eElementType                         GetType                     ( void ) const                  { return this->m_iType; }
	inline void                                 SetType                     ( eElementType iType )          { this->m_iType = iType; }
	
	void                                        SetTypeName                 ( const string& strTypeName );
	const string                                GetTypeName                 ( void );

	CElement*                                   GetParent                   ( void ) const;

	inline MonoObject*                          ToMonoObject                ( void ) const                   { return this->m_pMonoObject; }
	inline PVOID                                ToLuaUserData               ( void ) const                   { return this->m_pLuaUserdata; }
};

#endif
