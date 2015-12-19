#include "../StdInc.h"
#include "Vector3.h"

Vector3::Vector3( void )
{
	this->fX = 0;
	this->fY = 0;
	this->fZ = 0;
};

Vector3::Vector3( float fX, float fY, float fZ )
{
	this->fX = fX;
	this->fY = fY;
	this->fZ = fZ;
}

Vector3::Vector3( MonoObject *pObject )
{
	this->fX = CMonoObject::GetPropertyValue< float >( pObject, "X" );
	this->fY = CMonoObject::GetPropertyValue< float >( pObject, "Y" );
	this->fZ = CMonoObject::GetPropertyValue< float >( pObject, "Z" );
}

float Vector3::Normalize( void )
{
	float t = sqrt( this->fX * this->fX + this->fY * this->fY + this->fZ * this->fZ );

	if( t > FLOAT_EPSILON )
	{
		float fRcpt = 1 / t;

		this->fX *= fRcpt;
		this->fY *= fRcpt;
		this->fZ *= fRcpt;
	}
	else
	{
		t = 0;
	}
		
	return t;
}

float Vector3::Length( void ) const
{
	return sqrt( ( fX*fX ) + ( fY*fY ) + ( fZ*fZ ) );
}

float Vector3::LengthSquared( void ) const
{
	return ( fX*fX ) + ( fY*fY ) + ( fZ*fZ );
}

float Vector3::DotProduct( const Vector3 * param ) const
{
	return fX*param->fX + fY*param->fY + fZ*param->fZ;
}

void Vector3::CrossProduct( const Vector3 * param )
{
	float _fX = fX, _fY = fY, _fZ = fZ;

	fX = _fY * param->fZ - param->fY * _fZ;
	fY = _fZ * param->fX - param->fZ * _fX;
	fZ = _fX * param->fY - param->fX * _fY;
}

Vector3 Vector3::ToRotation( void ) const
{
	Vector3 vecRotation;

	vecRotation.fZ = atan2( fY, fX );

	Vector3 vecTemp( sqrt( fX * fX + fY * fY ), fZ, 0 );

	vecTemp.Normalize();

	vecRotation.fY = atan2( vecTemp.fX, vecTemp.fY ) - PI / 2;

	return vecRotation;
}

Vector3 Vector3::GetOtherAxis( void ) const
{
	Vector3 vecResult;

	if( abs( fX ) > abs( fY ) )
	{
		vecResult = Vector3( fZ, 0, -fX );
	}
	else
	{
		vecResult = Vector3( 0, -fZ, fY );
	}

	vecResult.Normalize();

	return vecResult;
}

Vector3 Vector3::operator + ( const Vector3& vecRight ) const
{
	return Vector3( fX + vecRight.fX, fY + vecRight.fY, fZ + vecRight.fZ );
}

Vector3 Vector3::operator - ( const Vector3& vecRight ) const
{
	return Vector3( fX - vecRight.fX, fY - vecRight.fY, fZ - vecRight.fZ );
}

Vector3 Vector3::operator * ( const Vector3& vecRight ) const
{
	return Vector3( fX * vecRight.fX, fY * vecRight.fY, fZ * vecRight.fZ );
}

Vector3 Vector3::operator * ( float fRight ) const
{
	return Vector3( fX * fRight, fY * fRight, fZ * fRight );
}

Vector3 Vector3::operator / ( const Vector3& vecRight ) const
{
	return Vector3( fX / vecRight.fX, fY / vecRight.fY, fZ / vecRight.fZ );
}

Vector3 Vector3::operator / ( float fRight ) const
{
	float fRcpValue = 1 / fRight;

	return Vector3( fX * fRcpValue, fY * fRcpValue, fZ * fRcpValue );
}

Vector3 Vector3::operator - ( ) const
{
	return Vector3( -fX, -fY, -fZ );
}

void Vector3::operator += ( float fRight )
{
	fX += fRight;
	fY += fRight;
	fZ += fRight;
}

void Vector3::operator += ( const Vector3& vecRight )
{
	fX += vecRight.fX;
	fY += vecRight.fY;
	fZ += vecRight.fZ;
}

void Vector3::operator -= ( float fRight )
{
	fX -= fRight;
	fY -= fRight;
	fZ -= fRight;
}

void Vector3::operator -= ( const Vector3& vecRight )
{
	fX -= vecRight.fX;
	fY -= vecRight.fY;
	fZ -= vecRight.fZ;
}

void Vector3::operator *= ( float fRight )
{
	fX *= fRight;
	fY *= fRight;
	fZ *= fRight;
}

void Vector3::operator *= ( const Vector3& vecRight )
{
	fX *= vecRight.fX;
	fY *= vecRight.fY;
	fZ *= vecRight.fZ;
}

void Vector3::operator /= ( float fRight )
{
	float fRcpValue = 1 / fRight;
	fX *= fRcpValue;
	fY *= fRcpValue;
	fZ *= fRcpValue;
}

void Vector3::operator /= ( const Vector3& vecRight )
{
	fX /= vecRight.fX;
	fY /= vecRight.fY;
	fZ /= vecRight.fZ;
}

bool Vector3::operator== ( const Vector3& param ) const
{
	return ( ( fabs( fX - param.fX ) < FLOAT_EPSILON ) && ( fabs( fY - param.fY ) < FLOAT_EPSILON ) && ( fabs( fZ - param.fZ ) < FLOAT_EPSILON ) );
}

bool Vector3::operator!= ( const Vector3& param ) const
{
	return ( ( fabs( fX - param.fX ) >= FLOAT_EPSILON ) || ( fabs( fY - param.fY ) >= FLOAT_EPSILON ) || ( fabs( fZ - param.fZ ) >= FLOAT_EPSILON ) );
}
