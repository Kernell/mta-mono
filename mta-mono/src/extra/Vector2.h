/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        sdk/CVector2D.h
*  PURPOSE:     2D vector class
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CVector2D_H
#define __CVector2D_H

#include <cmath>
#include "Vector3.h"

/**
 * CVector2D Structure used to store a 2D vertex.
 */
class Vector2
{
public:
	float fX;
	float fY;

	Vector2( void );
	Vector2( float _fX, float _fY );
	Vector2( MonoObject* pObject );

	float		DotProduct		( Vector2& other ) const;
	float		Length			( void ) const;
	float		LengthSquared	( void ) const;
	void		Normalize		( void );

	Vector2 operator * ( float fRight ) const;
	Vector2 operator / ( float fRight ) const;
	Vector2 operator + ( const Vector2& vecRight ) const;
	Vector2 operator - ( const Vector2& vecRight ) const;
	Vector2 operator * ( const Vector2& vecRight ) const;
	Vector2 operator / ( const Vector2& vecRight ) const;

	void operator += ( float fRight );
	void operator += ( const Vector2& vecRight );
	void operator -= ( float fRight );
	void operator -= ( const Vector2& vecRight );
	void operator *= ( float fRight );
	void operator *= ( const Vector2& vecRight );
	void operator /= ( float fRight );
	void operator /= ( const Vector2& vecRight );
	bool operator == ( const Vector2& param ) const;
	bool operator != ( const Vector2& param ) const;
};


#endif
