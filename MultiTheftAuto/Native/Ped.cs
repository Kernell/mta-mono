using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class Ped
	{
		// Ped get functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( int modelid, Vector3 position, float rot = 0.0f, bool synced = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetArmor( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsChoking( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsDead( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsDucked( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetStat( UInt32 ped, int stat );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetTarget( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetWeapon( UInt32 ped, int slot = 0 );

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static extern string string GetPedClothes( UInt32 ped, int clothesType );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool DoesHaveJetPack( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsOnGround( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetFightingStyle( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetPedMoveAnim( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetGravity( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetContactElement( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetWeaponSlot( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsDoingGangDriveby( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsOnFire( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsHeadless( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetOccupiedVehicle( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetOccupiedVehicleSeat( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsInVehicle( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetWeaponProperty( int weaponID, string weaponSkill, string property );
//		public static extern int GetWeaponProperty( string weaponName, string weaponSkill, string property );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetOriginalWeaponProperty( int weaponID, string weaponSkill, string property );
//		public static extern int GetOriginalWeaponProperty( string weaponName, string weaponSkill, string property );

		// Player set functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetArmor( UInt32 ped, int armor );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Kill( UInt32 ped, UInt32 theKiller = 0, int weapon = 255, int bodyPart = 255, bool stealth = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetStat( UInt32 ped, int stat, float value );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AddClothes( UInt32 ped, string clothesTexture, string clothesModel, int clothesType );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveClothes( UInt32 ped, int clothesType, string clothesTexture, string clothesModel );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool GiveJetPack( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveJetPack( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetFightingStyle( UInt32 ped, int style );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetPedMoveAnim( UInt32 ped, int anim );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetGravity( UInt32 ped, float gravity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetChoking( UInt32 ped, bool choking );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool WarpIntoVehicle( UInt32 ped, UInt32 vehicle, int seat = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveFromVehicle( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDoingGangDriveby( UInt32 ped, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetAnimation( UInt32 ped, string block = null, string anim = null, int time = -1, bool loop = true, bool updatePosition = true, bool interruptable = true, bool freezeLastFrame = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetAnimationProgress( UInt32 ped, string anim, float progress );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetWeaponSlot( UInt32 ped, int weaponSlot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetOnFire( UInt32 ped, bool isOnFire );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetHeadless( UInt32 ped, bool headState );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ReloadWeapon( UInt32 ped );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetWeaponProperty( int weaponID, string weaponSkill, string property, float theValue );
//		public static extern bool SetWeaponProperty( string weaponName, string weaponSkill, string property, float theValue );
	}
}
