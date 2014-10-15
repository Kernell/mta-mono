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
    Vector2 ( void )
    {
        fX = 0;
        fY = 0;
    }

    Vector2 ( float _fX, float _fY )
    {
        fX = _fX;
        fY = _fY;
    }

    float DotProduct ( Vector2& other ) const
    {
        return fX*other.fX + fY*other.fY;
    }

    float Length () const
    {
        return sqrt ( fX * fX + fY * fY );
    }

    float LengthSquared ( void ) const
    {
        return (fX*fX) + (fY*fY);
    }

    void Normalize ( void ) 
    { 
        float fLength = Length ();
        if ( fLength > 0.0f )
        {
            fX /= fLength;
            fY /= fLength;
        }
    }

    Vector2 operator * ( float fRight ) const
    {
        return Vector2 ( fX * fRight, fY * fRight );
    }

    Vector2 operator / ( float fRight ) const
    {
        float fRcpValue = 1 / fRight;
        return Vector2 ( fX * fRcpValue, fY * fRcpValue );
    }

    Vector2 operator + ( const Vector2& vecRight ) const
    {
        return Vector2 ( fX + vecRight.fX, fY + vecRight.fY );
    }

    Vector2 operator - ( const Vector2& vecRight ) const
    {
        return Vector2 ( fX - vecRight.fX, fY - vecRight.fY );
    }

    Vector2 operator * ( const Vector2& vecRight ) const
    {
        return Vector2 ( fX * vecRight.fX, fY * vecRight.fY );
    }

    Vector2 operator / ( const Vector2& vecRight ) const
    {
        return Vector2 ( fX / vecRight.fX, fY / vecRight.fY );
    }

    void operator += ( float fRight )
    {
        fX += fRight;
        fY += fRight;
    }

    void operator += ( const Vector2& vecRight )
    {
        fX += vecRight.fX;
        fY += vecRight.fY;
    }

    void operator -= ( float fRight )
    {
        fX -= fRight;
        fY -= fRight;
    }

    void operator -= ( const Vector2& vecRight )
    {
        fX -= vecRight.fX;
        fY -= vecRight.fY;
    }

    void operator *= ( float fRight )
    {
        fX *= fRight;
        fY *= fRight;
    }

    void operator *= ( const Vector2& vecRight )
    {
        fX *= vecRight.fX;
        fY *= vecRight.fY;
    }

    void operator /= ( float fRight )
    {
        fX /= fRight;
        fY /= fRight;
    }

    void operator /= ( const Vector2& vecRight )
    {
        fX /= vecRight.fX;
        fY /= vecRight.fY;
    }

    bool operator== ( const Vector2& param ) const
    {
        return ( ( fabs ( fX - param.fX ) < FLOAT_EPSILON ) &&
                 ( fabs ( fY - param.fY ) < FLOAT_EPSILON ) );
    }

    bool operator!= ( const Vector2& param ) const
    {
        return ( ( fabs ( fX - param.fX ) >= FLOAT_EPSILON ) ||
                 ( fabs ( fY - param.fY ) >= FLOAT_EPSILON ) );
    }

    float fX;
    float fY;
};


#endif
