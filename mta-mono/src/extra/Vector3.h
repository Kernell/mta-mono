/*****************************************************************************
*
*  PROJECT:     Multi Theft Auto v1.0
*  LICENSE:     See LICENSE in the top level directory
*  FILE:        sdk/CVector.h
*  PURPOSE:     3D vector math implementation
*
*  Multi Theft Auto is available from http://www.multitheftauto.com/
*
*****************************************************************************/

#ifndef __CVector_H
#define __CVector_H

#ifdef WIN32
#include <windows.h>
#endif

#include <math.h>
#include "../CMonoObject.h"

#define FLOAT_EPSILON 0.0001f
#define PI 3.14159265358979323846f
/**
 * CVector Structure used to store a 3D vertex.
 */
class Vector3
{
public:
	float fX, fY, fZ;

				Vector3			( void );
				Vector3			( float fX, float fY, float fZ );
				Vector3			( MonoObject *pObject );

	float		Normalize		( void );
	float		Length			( void ) const;
	float		LengthSquared	( void ) const;
	float		DotProduct		( const Vector3 * param ) const;
	void		CrossProduct	( const Vector3 * param );

	// Convert (direction) to rotation
	Vector3		ToRotation		( void ) const;

	// Return a perpendicular direction
	Vector3		GetOtherAxis	( void ) const;

	Vector3		operator + ( const Vector3& vecRight ) const;
	Vector3		operator - ( const Vector3& vecRight ) const;
	Vector3		operator * ( const Vector3& vecRight ) const;
	Vector3		operator * ( float fRight ) const;
	Vector3		operator / ( const Vector3& vecRight ) const;
	Vector3		operator / ( float fRight ) const;
	Vector3		operator - () const;

	void		operator += ( float fRight );
	void		operator += ( const Vector3& vecRight );

	void		operator -= ( float fRight );
	void		operator -= ( const Vector3& vecRight );

	void		operator *= ( float fRight );
	void		operator *= ( const Vector3& vecRight );

	void		operator /= ( float fRight );
	void		operator /= ( const Vector3& vecRight );

	bool		operator == ( const Vector3& param ) const;
	bool		operator != ( const Vector3& param ) const;
};

#endif
