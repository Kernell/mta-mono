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

class CMonoObject;

#ifndef _C_MONO_OBJECT
#define _C_MONO_OBJECT

#include "Common.h"
#include "CMonoClass.h"

class CMonoObject
{
private:
	MonoObject* m_pMonoObject;

public:
	CMonoObject( MonoObject* pMonoObject );
	~CMonoObject();

	CMonoClass* GetClass();

	bool SetPropertyValue( const char* szPropertyName, int iValue );
	bool SetPropertyValue( const char* szPropertyName, float fValue );
	bool SetPropertyValue( const char* szPropertyName, char* szValue );
	bool SetPropertyValue( const char* szPropertyName, gpointer gValue );

	MonoObject* GetPropertyValue( const char* szPropertyName );
	
	Vector2 GetVector2()
	{
		float fX = this->GetPropertyValue< float >( "X" );
		float fY = this->GetPropertyValue< float >( "Y" );

		return Vector2( fX, fY );
	}

	Vector3 GetVector3()
	{
		float fX = this->GetPropertyValue< float >( "X" );
		float fY = this->GetPropertyValue< float >( "Y" );
		float fZ = this->GetPropertyValue< float >( "Z" );

		return Vector3( fX, fY, fZ );
	}

	SColor GetColor()
	{
		SColor pColor;

		pColor.R = this->GetPropertyValue< unsigned char >( "R" );
		pColor.G = this->GetPropertyValue< unsigned char >( "G" );
		pColor.B = this->GetPropertyValue< unsigned char >( "B" );
		pColor.A = this->GetPropertyValue< unsigned char >( "A" );

		return pColor;
	}
	
	template <class T> T GetPropertyValue( char* szPropertyName )
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( this->GetPropertyValue( szPropertyName ) ) ) );
	}

	void* GetValue()
	{
		return mono_object_unbox( this->m_pMonoObject );
	}

	template <class T> T GetValue()
	{
		return *( reinterpret_cast<T*>( mono_object_unbox( this->m_pMonoObject ) ) );
	}

	MonoObject *GetObject()
	{
		return this->m_pMonoObject;
	}
};

#endif