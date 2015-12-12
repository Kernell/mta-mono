using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	internal class Vehicle
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( int model, Vector3 position, Vector3 rotation, string numberplate = null, bool direction = false, int variant1 = 255, int variant2 = 255 );

		#region Vehicle get functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetType( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetVariant( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Color GetColor( UInt32 vehicle, int colorIndex );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetModelFromName( string name );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool GetLandingGearDown( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetMaxPassengers( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetName( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetNameFromModel( int modelID );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Player GetOccupant( UInt32 vehicle, int seat = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetOccupants( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Player GetController( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool GetSirensOn( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetTurnVelocity( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetTurretPosition( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsLocked( UInt32 vehicle );

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static int GetVehiclesOfType( lua_State* luaVM );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetUpgradeOnSlot( UInt32 vehicle, int slot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetUpgrades( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetUpgradeSlotName( int upgradeOrSlot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetCompatibleUpgrades( UInt32 vehicle, int slot = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetDoorState( UInt32 vehicle, int door );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetWheelStates( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetLightState( UInt32 vehicle, int light );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetPanelState( UInt32 vehicle, int panel );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetOverrideLights( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetTowedByVehicle( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetTowingVehicle( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetPaintjob( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetPlateText( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsDamageProof( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsFuelTankExplodable( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsOnGround( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool GetEngineState( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsTrainDerailed( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsTrainDerailable( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool GetTrainDirection( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetTrainSpeed( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsBlown( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Color GetHeadLightColor( UInt32 vehicle );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetVehicleDoorOpenRatio( UInt32 vehicle, int door );
		#endregion

		#region Vehicle set functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Fix( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Blow( UInt32 userdata, bool explode );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTurnVelocity( UInt32 userdata, Vector3 velocity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetColor( UInt32 userdata, Color color1, Color color2, Color color3, Color color4 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLandingGearDown( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLocked( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetModel( UInt32 userdata, int model );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDoorsUndamageable( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetSirensOn( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTaxiLightOn( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsTaxiLightOn( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AddUpgrade( UInt32 userdata, int upgrade );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveUpgrade( UInt32 userdata, int upgrade );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDoorState( UInt32 userdata, int door, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetWheelStates( UInt32 userdata, int frontLeft, int rearLeft = -1, int frontRight = -1, int rearRight = -1 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLightState( UInt32 userdata, int light, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetPanelState( UInt32 userdata, int panelID, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetIdleRespawnDelay( UInt32 userdata, int timeDelay );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetRespawnDelay( UInt32 userdata, int timeDelay );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetRespawnPosition( UInt32 userdata, Vector3 position, Vector3 rotation );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ToggleRespawn( UInt32 userdata, bool respawn );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ResetExplosionTime( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ResetIdleTime( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Spawn( UInt32 userdata, Vector3 position, Vector3 rotation );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Respawn( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetOverrideLights( UInt32 userdata, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AttachTrailerToVehicle( UInt32 userdata, UInt32 trailer );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool DetachTrailerFromVehicle( UInt32 userdata, UInt32 trailer = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetEngineState( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDamageProof( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetPaintjob( UInt32 userdata, int value );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetFuelTankExplodable( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTrainDerailed( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTrainDerailable( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTrainDirection( UInt32 userdata, bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTrainSpeed( UInt32 userdata, float speed );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetHeadLightColor( UInt32 userdata, Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTurretPosition( UInt32 userdata, float x, float y );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDoorOpenRatio( UInt32 userdata, int door, float ratio, int time = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetVariant( UInt32 userdata, int variant1 = 255, int variant2 = 255 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AddSirens( UInt32 userdata, int sirenCount, int sirenType, bool flag360 = false, bool checkLos = true, bool useRandomiser = true, bool silent = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveSirens( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetSirens( UInt32 userdata, int sirenPoint, Vector3 position, Color color = null, float minAlpha = 0.0f );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetSirens( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Object GetSirenParams( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetPlateText( UInt32 userdata, string numberplate );

		#endregion
	}
}
