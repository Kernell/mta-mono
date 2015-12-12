using System;
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

		public Ped( UInt32 userdata )
			: base( userdata )
		{

		}

		public Ped( int modelid, Vector3 position, float rot = 0.0f, bool synced = true )
			: base( Native.Ped.Create( modelid, position, rot, synced ) )
		{
		
		}
		
		#endregion

		#region Methods

		#region Set

		public bool SetArmor( int armor )
		{
			return Native.Ped.SetArmor( this.GetUserData(), armor );
		}

		public bool Kill( Ped killer = null, int weapon = 255, int bodyPart = 255, bool stealth = false  )
		{
			return Native.Ped.Kill( this.GetUserData(), killer != null ? killer.GetUserData() : 0, weapon, bodyPart, stealth );
		}

		public bool SetStat( int stat, float value )
		{
			return Native.Ped.SetStat( this.GetUserData(), stat, value );
		}

		public bool AddClothes( string clothesTexture, string clothesModel, int clothesType )
		{
			return Native.Ped.AddClothes( this.GetUserData(), clothesTexture, clothesModel, clothesType );
		}

		public bool RemoveClothes( int clothesType, string clothesTexture, string clothesModel )
		{
			return Native.Ped.RemoveClothes( this.GetUserData(), clothesType, clothesTexture, clothesModel );
		}

		public bool GiveJetPack()
		{
			return Native.Ped.GiveJetPack( this.GetUserData() );
		}

		public bool RemoveJetPack()
		{
			return Native.Ped.RemoveJetPack( this.GetUserData() );
		}

		public bool SetFightingStyle( int style )
		{
			return Native.Ped.SetFightingStyle( this.GetUserData(), style );
		}

		public bool SetPedMoveAnim( int style )
		{
			return Native.Ped.SetPedMoveAnim( this.GetUserData(), style );
		}

		public bool SetGravity( float gravity )
		{
			return Native.Ped.SetGravity( this.GetUserData(), gravity );
		}

		public bool SetChoking( bool choking )
		{
			return Native.Ped.SetChoking( this.GetUserData(), choking );
		}

		public bool WarpIntoVehicle( Vehicle vehicle, int seat = 0 )
		{
			return Native.Ped.WarpIntoVehicle( this.GetUserData(), vehicle.GetUserData(), seat );
		}

		public bool RemoveFromVehicle()
		{
			return Native.Ped.RemoveFromVehicle( this.GetUserData() );
		}

		public bool SetDoingGangDriveby( bool state )
		{
			return Native.Ped.SetDoingGangDriveby( this.GetUserData(), state );
		}

		public bool SetAnimation( string block = null, string anim = null, int time = -1, bool loop = true, bool updatePosition = true, bool interruptable = true, bool freezeLastFrame = true )
		{
			return Native.Ped.SetAnimation( this.GetUserData(), block, anim, time, loop, updatePosition, interruptable, freezeLastFrame );
		}

		public bool SetAnimationProgress( string anim, float progress )
		{
			return Native.Ped.SetAnimationProgress( this.GetUserData(), anim, progress );
		}

		public bool SetWeaponSlot( int weaponSlot )
		{
			return Native.Ped.SetWeaponSlot( this.GetUserData(), weaponSlot );
		}

		public bool SetOnFire( bool isOnFire )
		{
			return Native.Ped.SetOnFire( this.GetUserData(), isOnFire );
		}

		public bool SetHeadless( bool headless )
		{
			return Native.Ped.SetHeadless( this.GetUserData(), headless );
		}

		public bool ReloadWeapon()
		{
			return Native.Ped.ReloadWeapon( this.GetUserData() );
		}

		#endregion

		#region Get
		
		public float GetArmor()
		{
			return Native.Ped.GetArmor( this.GetUserData() );
		}

		public float GetStat( int stat )
		{
			return Native.Ped.GetStat( this.GetUserData(), stat );
		}

		public Object GetTarget()
		{
			return Element.FindOrCreate( Native.Ped.GetTarget( this.GetUserData() ) );
		}

		public int GetWeapon( int slot = 0 )
		{
			return Native.Ped.GetWeapon( this.GetUserData(), slot );
		}

		public int GetFightingStyle()
		{
			return Native.Ped.GetFightingStyle( this.GetUserData() );
		}

		public int GetPedMoveAnim()
		{
			return Native.Ped.GetPedMoveAnim( this.GetUserData() );
		}

		public float GetGravity()
		{
			return Native.Ped.GetGravity( this.GetUserData() );
		}

		public Object GetContactElement()
		{
			return Element.FindOrCreate( Native.Ped.GetContactElement( this.GetUserData() ) );
		}

		public int GetWeaponSlot()
		{
			return Native.Ped.GetWeaponSlot( this.GetUserData() );
		}

		public Vehicle GetVehicle()
		{
			return Element.FindOrCreate( Native.Ped.GetOccupiedVehicle( this.GetUserData() ) ) as Vehicle;
		}

		public int GetVehicleSeat()
		{
			return Native.Ped.GetOccupiedVehicleSeat( this.GetUserData() );
		}

		#endregion

		#region Is

		public bool IsChoking()
		{
			return Native.Ped.IsChoking( this.GetUserData() );
		}

		public bool IsDead()
		{
			return Native.Ped.IsDead( this.GetUserData() );
		}

		public bool IsDucked()
		{
			return Native.Ped.IsDucked( this.GetUserData() );
		}

		public bool IsHaveJetPack()
		{
			return Native.Ped.DoesHaveJetPack( this.GetUserData() );
		}

		public bool IsOnGround()
		{
			return Native.Ped.IsOnGround( this.GetUserData() );
		}

		public bool IsDoingGangDriveby()
		{
			return Native.Ped.IsDoingGangDriveby( this.GetUserData() );
		}

		public bool IsOnFire()
		{
			return Native.Ped.IsOnFire( this.GetUserData() );
		}

		public bool IsHeadless()
		{
			return Native.Ped.IsHeadless( this.GetUserData() );
		}

		public bool IsInVehicle()
		{
			return Native.Ped.IsInVehicle( this.GetUserData() );
		}

		#endregion

		#endregion
	}
}
