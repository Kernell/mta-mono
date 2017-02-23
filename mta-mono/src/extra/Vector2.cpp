#include "../StdInc.h"
#include "Vector2.h"

Vector2::Vector2( void )
{
	fX = 0;
	fY = 0;
}

Vector2::Vector2( float _fX, float _fY )
{
	fX = _fX;
	fY = _fY;
}

Vector2::Vector2( MonoObject* pObject )
{
	this->fX = SharedUtil::MonoObject::GetPropertyValue< float >( pObject, "X" );
	this->fY = SharedUtil::MonoObject::GetPropertyValue< float >( pObject, "Y" );
}

float Vector2::DotProduct( Vector2& other ) const
{
	return fX * other.fX + fY * other.fY;
}

float Vector2::Length() const
{
	return sqrt( fX * fX + fY * fY );
}

float Vector2::LengthSquared( void ) const
{
	return ( fX*fX ) + ( fY*fY );
}

void Vector2::Normalize( void )
{
	float fLength = Length();

	if( fLength > 0.0f )
	{
		fX /= fLength;
		fY /= fLength;
	}
}

Vector2 Vector2::operator * ( float fRight ) const
{
	return Vector2( fX * fRight, fY * fRight );
}

Vector2 Vector2::operator / ( float fRight ) const
{
	float fRcpValue = 1 / fRight;

	return Vector2( fX * fRcpValue, fY * fRcpValue );
}

Vector2 Vector2::operator + ( const Vector2& vecRight ) const
{
	return Vector2( fX + vecRight.fX, fY + vecRight.fY );
}

Vector2 Vector2::operator - ( const Vector2& vecRight ) const
{
	return Vector2( fX - vecRight.fX, fY - vecRight.fY );
}

Vector2 Vector2::operator * ( const Vector2& vecRight ) const
{
	return Vector2( fX * vecRight.fX, fY * vecRight.fY );
}

Vector2 Vector2::operator / ( const Vector2& vecRight ) const
{
	return Vector2( fX / vecRight.fX, fY / vecRight.fY );
}

void Vector2::operator += ( float fRight )
{
	fX += fRight;
	fY += fRight;
}

void Vector2::operator += ( const Vector2& vecRight )
{
	fX += vecRight.fX;
	fY += vecRight.fY;
}

void Vector2::operator -= ( float fRight )
{
	fX -= fRight;
	fY -= fRight;
}

void Vector2::operator -= ( const Vector2& vecRight )
{
	fX -= vecRight.fX;
	fY -= vecRight.fY;
}

void Vector2::operator *= ( float fRight )
{
	fX *= fRight;
	fY *= fRight;
}

void Vector2::operator *= ( const Vector2& vecRight )
{
	fX *= vecRight.fX;
	fY *= vecRight.fY;
}

void Vector2::operator /= ( float fRight )
{
	fX /= fRight;
	fY /= fRight;
}

void Vector2::operator /= ( const Vector2& vecRight )
{
	fX /= vecRight.fX;
	fY /= vecRight.fY;
}

bool Vector2::operator == ( const Vector2& param ) const
{
	return ( ( fabs( fX - param.fX ) < FLOAT_EPSILON ) && ( fabs( fY - param.fY ) < FLOAT_EPSILON ) );
}

bool Vector2::operator != ( const Vector2& param ) const
{
	return ( ( fabs( fX - param.fX ) >= FLOAT_EPSILON ) || ( fabs( fY - param.fY ) >= FLOAT_EPSILON ) );
}