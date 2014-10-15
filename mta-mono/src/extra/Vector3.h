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

#define FLOAT_EPSILON 0.0001f
#define PI (3.14159265358979323846f)
/**
 * CVector Structure used to store a 3D vertex.
 */
class Vector3
{
public:
    float fX, fY, fZ;
    
    Vector3 ()
    {
        this->fX = 0;
        this->fY = 0;
        this->fZ = 0;
    };
    
    Vector3 ( float fX, float fY, float fZ) 
    { 
        this->fX = fX;
        this->fY = fY;
        this->fZ = fZ;
    }

    float Normalize ( void ) 
    { 
        float t = sqrt(fX*fX + fY*fY + fZ*fZ);
        if ( t > FLOAT_EPSILON )
        {
            float fRcpt = 1 / t;
            fX *= fRcpt;
            fY *= fRcpt;
            fZ *= fRcpt;
        }
        else
            t = 0;
        return t;
    }

    float Length ( void ) const
    {
        return sqrt ( (fX*fX) + (fY*fY) + (fZ*fZ) );
    }

    float LengthSquared ( void ) const
    {
        return (fX*fX) + (fY*fY) + (fZ*fZ);
    }

    float DotProduct ( const Vector3 * param ) const
    {
        return fX*param->fX + fY*param->fY + fZ*param->fZ;
    }

    void CrossProduct ( const Vector3 * param ) 
    { 
        float _fX = fX, _fY = fY, _fZ = fZ;
        fX = _fY * param->fZ - param->fY * _fZ;
        fY = _fZ * param->fX - param->fZ * _fX;
        fZ = _fX * param->fY - param->fX * _fY;
    }

    // Convert (direction) to rotation
    Vector3 ToRotation ( void ) const
    {
        Vector3 vecRotation;
        vecRotation.fZ = atan2 ( fY, fX );
        Vector3 vecTemp ( sqrt ( fX * fX + fY * fY ), fZ, 0 );
        vecTemp.Normalize ();
        vecRotation.fY = atan2 ( vecTemp.fX, vecTemp.fY ) - PI / 2;
        return vecRotation;
    }

    // Return a perpendicular direction
    Vector3 GetOtherAxis ( void ) const
    {
        Vector3 vecResult;
        if ( abs( fX ) > abs( fY ) )
	        vecResult = Vector3( fZ, 0, -fX );
        else
	        vecResult = Vector3( 0, -fZ, fY );
        vecResult.Normalize();
        return vecResult;
    }

    Vector3 operator + ( const Vector3& vecRight ) const
    {
        return Vector3 ( fX + vecRight.fX, fY + vecRight.fY, fZ + vecRight.fZ );
    }

    Vector3 operator - ( const Vector3& vecRight ) const
    {
        return Vector3 ( fX - vecRight.fX, fY - vecRight.fY, fZ - vecRight.fZ );
    }

    Vector3 operator * ( const Vector3& vecRight ) const
    {
        return Vector3 ( fX * vecRight.fX, fY * vecRight.fY, fZ * vecRight.fZ );
    }

    Vector3 operator * ( float fRight ) const
    {
        return Vector3 ( fX * fRight, fY * fRight, fZ * fRight );
    }

    Vector3 operator / ( const Vector3& vecRight ) const
    {
        return Vector3 ( fX / vecRight.fX, fY / vecRight.fY, fZ / vecRight.fZ );
    }

    Vector3 operator / ( float fRight ) const
    {
        float fRcpValue = 1 / fRight;
        return Vector3 ( fX * fRcpValue, fY * fRcpValue, fZ * fRcpValue );
    }

    Vector3 operator - () const
    {
        return Vector3 ( -fX, -fY, -fZ );
    }

    void operator += ( float fRight )
    {
        fX += fRight;
        fY += fRight;
        fZ += fRight;
    }

    void operator += ( const Vector3& vecRight )
    {
        fX += vecRight.fX;
        fY += vecRight.fY;
        fZ += vecRight.fZ;
    }

    void operator -= ( float fRight )
    {
        fX -= fRight;
        fY -= fRight;
        fZ -= fRight;
    }

    void operator -= ( const Vector3& vecRight )
    {
        fX -= vecRight.fX;
        fY -= vecRight.fY;
        fZ -= vecRight.fZ;
    }

    void operator *= ( float fRight )
    {
        fX *= fRight;
        fY *= fRight;
        fZ *= fRight;
    }

    void operator *= ( const Vector3& vecRight )
    {
        fX *= vecRight.fX;
        fY *= vecRight.fY;
        fZ *= vecRight.fZ;
    }

    void operator /= ( float fRight )
    {
        float fRcpValue = 1 / fRight;
        fX *= fRcpValue;
        fY *= fRcpValue;
        fZ *= fRcpValue;
    }

    void operator /= ( const Vector3& vecRight )
    {
        fX /= vecRight.fX;
        fY /= vecRight.fY;
        fZ /= vecRight.fZ;
    }

    bool operator== ( const Vector3& param ) const
    {
        return ( ( fabs ( fX - param.fX ) < FLOAT_EPSILON ) &&
                 ( fabs ( fY - param.fY ) < FLOAT_EPSILON ) &&
                 ( fabs ( fZ - param.fZ ) < FLOAT_EPSILON ) );
    }

    bool operator!= ( const Vector3& param ) const
    {
        return ( ( fabs ( fX - param.fX ) >= FLOAT_EPSILON ) ||
                 ( fabs ( fY - param.fY ) >= FLOAT_EPSILON ) ||
                 ( fabs ( fZ - param.fZ ) >= FLOAT_EPSILON ) );
    }
};

#endif
