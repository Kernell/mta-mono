#include "SharedUtil.MonoObject.h"

#ifndef __SHAREDUTIL_H
#define __SHAREDUTIL_H

template< typename T >
T Min( const T& a, const T& b )
{
    return a < b ? a : b;
}

template< typename T >
T Max( const T& a, const T& b )
{
    return a > b ? a : b;
}

template< typename T >
T Clamp( const T& min, const T& a, const T& max )
{
    return a < min ? min : a > max ? max : a;
}

template< typename T >
T Lerp( const T& from, float fAlpha, const T& to )
{
    return (T)( ( to - from ) * fAlpha + from );
}

inline const float Unlerp( const double dFrom, const double dPos, const double dTo )
{
	if( dFrom == dTo )
	{
		return 1.0f;
	}

    return static_cast< float >( ( dPos - dFrom ) / ( dTo - dFrom ) );
}

inline const float UnlerpClamped( const double dFrom, const double dPos, const double dTo )
{
    return Clamp( 0.0f, Unlerp( dFrom, dPos, dTo ), 1.0f );
}

template < typename T >
int Round( T value )
{
    return static_cast< int >( floor( value + 0.5f ) );
}

template < typename T > T
WrapAround( T fLow, T fValue, T fHigh )
{
    const T fSize = fHigh - fLow;

    return fValue - ( fSize * floor( ( fValue - fLow ) / fSize ) );
}

struct SHeatHazeSettings
{
    SHeatHazeSettings( void ) 
		: ucIntensity( 0 ),
		ucRandomShift( 0 ),
		usSpeedMin( 1 ),
		usSpeedMax( 1 ),
		sScanSizeX( 1 ),
		sScanSizeY( 1 ),
		usRenderSizeX( 1 ),
		usRenderSizeY( 1 ),
		bInsideBuilding( false )
    {
	}

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
