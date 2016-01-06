using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiTheftAuto
{
	public class Ped : Element
	{
		#region Properties

		public Vehicle Vehicle
		{
			get
			{
				return this.GetVehicle();
			}
			set
			{
				this.WarpIntoVehicle( value, 0 );
			}
		}

		#endregion

		#region Constructors

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Ped( int modelid, Vector3 position, float rot = 0.0f, bool synced = true );

		internal Ped()
		{
		}
		
		#endregion

		#region Methods

		#region Set

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetArmor( int armor );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Kill( Ped killer = null, int weapon = 255, int bodyPart = 255, bool stealth = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetStat( int stat, float value );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool AddClothes( string clothesTexture, string clothesModel, int clothesType );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveClothes( int clothesType, string clothesTexture, string clothesModel );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GiveJetPack();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveJetPack();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetFightingStyle( int style );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetPedMoveAnim( int style );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetGravity( float gravity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetChoking( bool choking );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool WarpIntoVehicle( Vehicle vehicle, int seat = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveFromVehicle();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetDoingGangDriveby( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetAnimation( string block = null, string anim = null, int time = -1, bool loop = true, bool updatePosition = true, bool interruptable = true, bool freezeLastFrame = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetAnimationProgress( string anim, float progress );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetWeaponSlot( int weaponSlot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetOnFire( bool isOnFire );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetHeadless( bool headless );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool ReloadWeapon();

		#endregion

		#region Get

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetArmor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetStat( int stat );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Element GetTarget();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetWeapon( int slot = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetFightingStyle();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetPedMoveAnim();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetGravity();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Element GetContactElement();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetWeaponSlot();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vehicle GetVehicle();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetVehicleSeat();

		#endregion

		#region Is

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsChoking();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsDead();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsDucked();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsHaveJetPack();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsOnGround();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsDoingGangDriveby();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsOnFire();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsHeadless();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsInVehicle();

		#endregion

		#endregion
	}
}
