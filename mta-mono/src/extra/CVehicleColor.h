class CVehicleColor;

#ifndef __CVEHICLECOLOR_H
#define __CVEHICLECOLOR_H

#include "SColor.h"

class CVehicleColor
{
public:
	                CVehicleColor               ( void );

	void            SetRGBColors                ( SColor color1, SColor color2, SColor color3, SColor color4 );
	void            SetPaletteColors            ( uchar ucColor1, uchar ucColor2, uchar ucColor3, uchar ucColor4 );

	void            SetRGBColor                 ( uint uiSlot, SColor color );
	void            SetPaletteColor             ( uint uiSlot, uchar ucColor );

	SColor          GetRGBColor                 ( uint uiSlot );
	uchar			GetPaletteColor             ( uint uiSlot );

	int             GetNumColorsUsed            ( void );

	static uchar    GetPaletteIndexFromRGB      ( SColor color );
	static SColor   GetRGBFromPaletteIndex      ( uchar ucColor );

protected:
	void            InvalidatePaletteColors     ( void );
	void            ValidatePaletteColors       ( void );
	void            InvalidateRGBColors         ( void );
	void            ValidateRGBColors           ( void );

	SColor          m_RGBColors[ 4 ];
	uchar		    m_ucPaletteColors[ 4 ];
	bool            m_bPaletteColorsWrong;
	bool            m_bRGBColorsWrong;
};

#endif
