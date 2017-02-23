#include "../StdInc.h"
#include "SColor.h"

SColor::SColor( void )
{
}

SColor::SColor( unsigned long ulValue )
{
	this->ulARGB = ulValue;
}

SColor::operator unsigned long( void ) const
{
	return this->ulARGB;
}


SColorARGB::SColorARGB( unsigned char ucA, unsigned char ucR, unsigned char ucG, unsigned char ucB )
{
	this->A = ucA;
	this->R = ucR;
	this->G = ucG;
	this->B = ucB;
}


SColorRGBA::SColorRGBA( unsigned char ucR, unsigned char ucG, unsigned char ucB, unsigned char ucA )
{
	this->R = ucR;
	this->G = ucG;
	this->B = ucB;
	this->A = ucA;
}
