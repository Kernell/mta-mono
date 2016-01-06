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

const map<eElementType, pair<string, string>> CElement::_eElementType =
{
	{ eElementType::Dummy,					{ "dummy",			"Element" } },
	{ eElementType::Player,					{ "player",			"Player" } },
	{ eElementType::Vehicle,				{ "vehicle",		"Vehile" } },
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
	{ eElementType::Resource,				{ "resource",		"Resource" } },
	{ eElementType::Root,					{ "root",			"Element" } },
	{ eElementType::Unknown,				{ "unknown",		"Element" } },
};

CElement::CElement( CElementManager* pManager, MonoObject* pObject, PVOID pUserdata, const CResource* pParent )
{
	this->m_pElementManager = pManager;
	this->m_pMonoObject     = pObject;
	this->m_pLuaUserdata    = pUserdata;
	this->m_pParent         = pParent;

	this->m_iType           = eElementType::Unknown;

	this->m_pElementManager->AddToList( this );
}

CElement::~CElement( void )
{
	this->m_pElementManager->RemoveFromList( this );

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
