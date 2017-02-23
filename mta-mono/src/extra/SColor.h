class SColor;

#ifndef __SCOLOR_H
#define __SCOLOR_H

//
// SColor
//
// Encapsulates the most common usage of 4 byte color storage.
// Casts to and from a DWORD as 0xAARRGGBB
//
class SColor
{
	// No shifting allowed to access the color channel information
	void operator >> ( int ) const;
	void operator << ( int ) const;
	void operator >>= ( int );
	void operator <<= ( int );

public:
	union
	{
		struct
		{
			unsigned char B, G, R, A;
		};

		unsigned long ulARGB;
	};

	SColor( void );

	SColor( unsigned long ulValue );

	operator unsigned long( void ) const;
};


//
// SColorARGB
//
// Make an SColor from A,R,G,B
//
class SColorARGB : public SColor
{
public:
	SColorARGB( unsigned char ucA, unsigned char ucR, unsigned char ucG, unsigned char ucB );

	template< class T, class U, class V, class W >
	SColorARGB( T a, U r, V g, W b )
	{
		this->A = Clamp< unsigned char >( 0, static_cast< unsigned char >( a ), 255 );
		this->R = Clamp< unsigned char >( 0, static_cast< unsigned char >( r ), 255 );
		this->G = Clamp< unsigned char >( 0, static_cast< unsigned char >( g ), 255 );
		this->B = Clamp< unsigned char >( 0, static_cast< unsigned char >( b ), 255 );
	}
};


//
// SColorRGBA
//
// Make an SColor from R,G,B,A
//
class SColorRGBA : public SColor
{
public:
	SColorRGBA( unsigned char ucR, unsigned char ucG, unsigned char ucB, unsigned char ucA );

	template< class T, class U, class V, class W >
	SColorRGBA( T r, U g, V b, W a )
	{
		this->R = Clamp< unsigned char >( 0, static_cast< unsigned char >( r ), 255 );
		this->G = Clamp< unsigned char >( 0, static_cast< unsigned char >( g ), 255 );
		this->B = Clamp< unsigned char >( 0, static_cast< unsigned char >( b ), 255 );
		this->A = Clamp< unsigned char >( 0, static_cast< unsigned char >( a ), 255 );
	}
};

#endif
