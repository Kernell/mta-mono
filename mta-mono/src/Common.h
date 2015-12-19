/*********************************************************
*
*  Multi Theft Auto: San Andreas - Deathmatch
*
*  ml_base, External lua add-on module
*
*  Copyright © 2003-2008 MTA.  All Rights Reserved.
*
*  Grand Theft Auto is © 2002-2003 Rockstar North
*
*  THE FOLLOWING SOURCES ARE PART OF THE MULTI THEFT
*  AUTO SOFTWARE DEVELOPMENT KIT AND ARE RELEASED AS
*  OPEN SOURCE FILES. THESE FILES MAY BE USED AS LONG
*  AS THE DEVELOPER AGREES TO THE LICENSE THAT IS
*  PROVIDED WITH THIS PACKAGE.
*
*********************************************************/

using namespace std;

#ifndef __COMMON_H
#define __COMMON_H

typedef	unsigned long	    ulong;      //  32      32      64
typedef unsigned int	    uint;       //  32
typedef unsigned short	    ushort;     //  16  
typedef unsigned char	    uchar;      //  8

typedef unsigned long long  uint64;     //  64
typedef unsigned int        uint32;     //  32
typedef unsigned short      uint16;     //  16
typedef unsigned char       uint8;      //  8

// signed types
typedef signed long long    int64;      //  64
typedef signed int          int32;      //  32
typedef signed short        int16;      //  16
typedef signed char         int8;       //  8

// Windowsesq types
typedef unsigned char       BYTE;       //  8
typedef unsigned short      WORD;       //  16
typedef unsigned long       DWORD;      //  32      32      64
typedef float               FLOAT;      //  32

#ifndef NUMELMS     // from DShow.h
    #define NUMELMS(aa) (sizeof(aa)/sizeof((aa)[0]))
#endif

// used in the function argument vector
#define MAX_ARGUMENTS 10
struct FunctionArguments
{
    lua_State* luaVM;
    unsigned char nArguments;
    unsigned char Type[10];
    void*   Arguments[10];
};

namespace FunctionArgumentType
{
    enum
    {
        TYPE_NUMBER = 1,
        TYPE_STRING = 2,
        TYPE_LIGHTUSERDATA = 3,
        TYPE_BOOLEAN = 4,
        TYPE_NIL = 5,
        TYPE_TABLE = 6
    };
}

//
// Some templates
//
template < class T >T Min ( const T& a, const T& b )
{
    return a < b ? a : b;
}

template < class T >T Max ( const T& a, const T& b )
{
    return a > b ? a : b;
}

// Clamps a value between two other values ( min < a < max )
template< class T >T Clamp ( const T& min, const T& a, const T& max )
{
    return a < min ? min : a > max ? max : a;
}

// Lerps between two values depending on the weight
template< class T >T Lerp ( const T& from, float fAlpha, const T& to )
{
    return (T)( ( to - from ) * fAlpha + from );
}

// Find the relative position of Pos between From and To
inline const float Unlerp( const double dFrom, const double dPos, const double dTo )
{
    // Avoid dividing by 0 (results in INF values)
    if ( dFrom == dTo ) return 1.0f;

    return static_cast< float >( ( dPos - dFrom ) / ( dTo - dFrom ) );
}

// Unlerp avoiding extrapolation
inline const float UnlerpClamped( const double dFrom, const double dPos, const double dTo )
{
    return Clamp( 0.0f, Unlerp( dFrom, dPos, dTo ), 1.0f );
}

template < class T > int Round ( T value )
{
    return static_cast< int >( floor( value + 0.5f ) );
}

template < class T > T WrapAround ( T fLow, T fValue, T fHigh )
{
    const T fSize = fHigh - fLow;
    return fValue - ( fSize * floor( ( fValue - fLow ) / fSize ) );
}

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

    SColor() {}
    SColor( unsigned long ulValue )
    {
        ulARGB = ulValue;
    }

    operator unsigned long() const
    {
        return ulARGB;
    }
};


//
// SColorARGB
//
// Make an SColor from A,R,G,B
//
class SColorARGB : public SColor
{
public:
    SColorARGB( unsigned char ucA, unsigned char ucR, unsigned char ucG, unsigned char ucB )
    {
        A = ucA;
		R = ucR;
		G = ucG;
		B = ucB;
    }

    template < class T, class U, class V, class W >
    SColorARGB ( T a, U r, V g, W b )
    {
		A = Clamp < unsigned char >( 0, static_cast <unsigned char> ( a ), 255 );
		R = Clamp < unsigned char >( 0, static_cast <unsigned char> ( r ), 255 );
		G = Clamp < unsigned char >( 0, static_cast <unsigned char> ( g ), 255 );
		B = Clamp < unsigned char >( 0, static_cast <unsigned char> ( b ), 255 );
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
    SColorRGBA ( unsigned char ucR, unsigned char ucG, unsigned char ucB, unsigned char ucA )
    {
        A = ucA; R = ucR; G = ucG; B = ucB;
    }

    template < class T, class U, class V, class W >
    SColorRGBA ( T r, U g, V b, W a )
    {
        A = Clamp < unsigned char > ( 0, static_cast < unsigned char > ( a ), 255 );
        R = Clamp < unsigned char > ( 0, static_cast < unsigned char > ( r ), 255 );
        G = Clamp < unsigned char > ( 0, static_cast < unsigned char > ( g ), 255 );
        B = Clamp < unsigned char > ( 0, static_cast < unsigned char > ( b ), 255 );
    }
};


//
// Things to make it simpler to use SColor with the source code as it stands
//
typedef SColor RGBA;

inline unsigned char COLOR_RGBA_R ( SColor color ) { return color.R; }
inline unsigned char COLOR_RGBA_G ( SColor color ) { return color.G; }
inline unsigned char COLOR_RGBA_B ( SColor color ) { return color.B; }
inline unsigned char COLOR_RGBA_A ( SColor color ) { return color.A; }
inline unsigned char COLOR_ARGB_A ( SColor color ) { return color.A; }

inline SColor COLOR_RGBA ( unsigned char R, unsigned char G, unsigned char B, unsigned char A ) { return SColorRGBA ( R, G, B, A ); }
inline SColor COLOR_ARGB ( unsigned char A, unsigned char R, unsigned char G, unsigned char B ) { return SColorRGBA ( R, G, B, A ); }
inline SColor COLOR_ABGR ( unsigned char A, unsigned char B, unsigned char G, unsigned char R ) { return SColorRGBA ( R, G, B, A ); }

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

    SColor          m_RGBColors[4];
    uchar		    m_ucPaletteColors[4];
    bool            m_bPaletteColorsWrong;
    bool            m_bRGBColorsWrong;
};

struct SHeatHazeSettings
{
    SHeatHazeSettings( void )
        : ucIntensity( 0 )
        , ucRandomShift( 0 )
        , usSpeedMin( 1 )
        , usSpeedMax( 1 )
        , sScanSizeX( 1 )
        , sScanSizeY( 1 )
        , usRenderSizeX( 1 )
        , usRenderSizeY( 1 )
        , bInsideBuilding( false )
    {}

    unsigned char		ucIntensity;        //     0 to 255
    unsigned char		ucRandomShift;      //     0 to 255
    unsigned short		usSpeedMin;         //     0 to 1000
    unsigned short		usSpeedMax;         //     0 to 1000
    short				sScanSizeX;         // -1000 to 1000
    short				sScanSizeY;         // -1000 to 1000
    unsigned short		usRenderSizeX;      //     0 to 1000
    unsigned short		usRenderSizeY;      //     0 to 1000
    bool				bInsideBuilding;
};


enum eWeaponType
{
    WEAPONTYPE_UNARMED=0,
    WEAPONTYPE_BRASSKNUCKLE, 
    WEAPONTYPE_GOLFCLUB,
    WEAPONTYPE_NIGHTSTICK,
    WEAPONTYPE_KNIFE,
    WEAPONTYPE_BASEBALLBAT,
    WEAPONTYPE_SHOVEL,
    WEAPONTYPE_POOL_CUE,
    WEAPONTYPE_KATANA,
    WEAPONTYPE_CHAINSAW,
    
    // gifts
    WEAPONTYPE_DILDO1, // 10
    WEAPONTYPE_DILDO2,
    WEAPONTYPE_VIBE1,
    WEAPONTYPE_VIBE2,
    WEAPONTYPE_FLOWERS,
    WEAPONTYPE_CANE,

    WEAPONTYPE_GRENADE,
    WEAPONTYPE_TEARGAS,
    WEAPONTYPE_MOLOTOV,
    WEAPONTYPE_ROCKET,
    WEAPONTYPE_ROCKET_HS, // 20
    WEAPONTYPE_FREEFALL_BOMB,

    // FIRST SKILL WEAPON
    WEAPONTYPE_PISTOL,          // handguns
    WEAPONTYPE_PISTOL_SILENCED,
    WEAPONTYPE_DESERT_EAGLE,
    WEAPONTYPE_SHOTGUN,         // shotguns
    WEAPONTYPE_SAWNOFF_SHOTGUN, // one handed
    WEAPONTYPE_SPAS12_SHOTGUN,
    WEAPONTYPE_MICRO_UZI,       // submachine guns
    WEAPONTYPE_MP5,
    WEAPONTYPE_AK47, // 30      // machine guns 
    WEAPONTYPE_M4,          
    WEAPONTYPE_TEC9,            // this uses stat from the micro_uzi
    // END SKILL WEAPONS
    
    WEAPONTYPE_COUNTRYRIFLE,    // rifles
    WEAPONTYPE_SNIPERRIFLE, 
    WEAPONTYPE_ROCKETLAUNCHER,  // specials
    WEAPONTYPE_ROCKETLAUNCHER_HS,
    WEAPONTYPE_FLAMETHROWER,
    WEAPONTYPE_MINIGUN,
    WEAPONTYPE_REMOTE_SATCHEL_CHARGE,
    WEAPONTYPE_DETONATOR, // 40 // plastic explosive
    WEAPONTYPE_SPRAYCAN,
    WEAPONTYPE_EXTINGUISHER,
    WEAPONTYPE_CAMERA,
    WEAPONTYPE_NIGHTVISION,
    WEAPONTYPE_INFRARED,
    WEAPONTYPE_PARACHUTE,
    WEAPONTYPE_LAST_WEAPONTYPE,

    WEAPONTYPE_ARMOUR,
    // these are possible ways to die
    WEAPONTYPE_RAMMEDBYCAR,
    WEAPONTYPE_RUNOVERBYCAR, // 50
    WEAPONTYPE_EXPLOSION,
    WEAPONTYPE_UZI_DRIVEBY,
    WEAPONTYPE_DROWNING,
    WEAPONTYPE_FALL,
    WEAPONTYPE_UNIDENTIFIED,    // Used for damage being done
    WEAPONTYPE_ANYMELEE,
    WEAPONTYPE_ANYWEAPON,
    WEAPONTYPE_FLARE,

    // Added by us
    WEAPONTYPE_TANK_GRENADE,
};

#endif
