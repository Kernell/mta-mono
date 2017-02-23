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
#include "CElement.h"

const map< eElementType, pair< string, string > > CElement::_eElementType =
{
	{ eElementType::Dummy,					{ "dummy",			"Element" } },
	{ eElementType::Player,					{ "player",			"Player" } },
	{ eElementType::Vehicle,				{ "vehicle",		"Vehicle" } },
	{ eElementType::Object,					{ "object",			"Object" } },
	{ eElementType::Marker,					{ "marker",			"Marker" } },
	{ eElementType::Blip,					{ "blip",			"Blip" } },
	{ eElementType::Pickup,					{ "pickup",			"Pickup" } },
	{ eElementType::RadarArea,				{ "radararea",		"RadarArea" } },
	{ eElementType::Console,				{ "console",		"Console" } },
	{ eElementType::Team,					{ "team",			"Team" } },
	{ eElementType::Ped,					{ "ped",			"Ped" } },
	{ eElementType::ColShape,				{ "colshape",		"ColShape" } },
	{ eElementType::ScriptFile,				{ "scriptfile",		"ScriptFile" } },
	{ eElementType::Water,					{ "water",			"Water" } },
	{ eElementType::Weapon,					{ "weapon",			"Weapon" } },
	{ eElementType::DatabaseConnection,		{ "db-connection",	"DbConnection" } },
	{ eElementType::Resource,				{ "resource",		"Element" } },
	{ eElementType::Root,					{ "root",			"Element" } },
	{ eElementType::Unknown,				{ "unknown",		"Element" } },
};

CElement::CElement( CElementManager* pManager, MonoObject* pObject, PVOID pLuaUserdata, const CResource* pParent )
{
	this->m_pLuaUserdata    = pLuaUserdata;
	this->m_pElementManager = pManager;
	this->m_pMonoObject     = pObject;
	this->m_pParent         = pParent;

	this->m_iType           = eElementType::Unknown;

	this->m_uiGCHandle		= mono_gchandle_new( pObject, true );

	this->m_pElementManager->AddToList( this );
}

CElement::~CElement( void )
{
	this->m_pElementManager->RemoveFromList( this );

	if( this->m_uiGCHandle )
	{
		mono_gchandle_free( this->m_uiGCHandle );

		this->m_uiGCHandle = 0;
	}

	this->m_pMonoObject     = nullptr;
	this->m_pLuaUserdata    = nullptr;
	this->m_pParent         = nullptr;
	this->m_pElementManager = nullptr;
}

void CElement::SetTypeName( const string& strTypeName )
{
	this->m_iType = CElement::GetTypeByName( strTypeName );
}

const string CElement::GetTypeName( void )
{
	return CElement::GetTypeName( this->m_iType );
}

const char* CElement::GetTypeClassName( void )
{
	return CElement::GetTypeClassName( this->m_iType );
}

CElement* CElement::GetParent( void ) const
{
	MonoObject* pMonoObject = CMonoFunctions::Element::GetParent( this->m_pMonoObject );

	if( pMonoObject )
	{
		return this->m_pElementManager->GetFromList( pMonoObject );
	}

	return nullptr;
}
