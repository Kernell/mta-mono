using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	static class World
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static byte[] GetTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static int[] GetWeather();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static string GetZoneName( Vector3 position, bool citiesOnly = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetGravity();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetGameSpeed();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetWaveHeight();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static ushort GetFPSLimit();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static ulong GetMinuteDuration();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool IsGarageOpen( byte garageID );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static byte GetTrafficLightState();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool GetTrafficLightsLocked();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetJetpackMaxHeight();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetAircraftMaxVelocity();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool GetInteriorSoundsEnabled();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetRainLevel();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetSunSize();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Color[] GetSunColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Vector3 GetWindVelocity();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetFarClipDistance();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetFogDistance();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static float GetAircraftMaxHeight();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool GetOcclusionsEnabled();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static int GetMoonSize();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Color[] GetSkyGradient();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static HeatHazeSettings GetHeatHaze();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool GetJetpackWeaponEnabled( uint weaponType );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool GetCloudsEnabled();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetTime( byte hour, byte minute );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetWeather( byte weather );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetWeatherBlended( byte weather );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetGravity( float gravity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetGameSpeed( float speed );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetWaveHeight( float height );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetSkyGradient( Color topColor, Color bottomColor );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetSkyGradient();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetHeatHaze( HeatHazeSettings heatHazeSettings );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetHeatHaze();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetFPSLimit( ushort limit, bool save );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetMinuteDuration( ulong duration );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetGarageOpen( byte garageID, bool isOpen );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetGlitchEnabled( string glitchName, bool enabled );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool IsGlitchEnabled( string glitchName );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetJetpackWeaponEnabled( uint weaponType, bool enabled );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetCloudsEnabled( bool enabled );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetTrafficLightState( byte state, bool forced = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetTrafficLightsLocked( bool locked );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetJetpackMaxHeight( float maxHeight );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetInteriorSoundsEnabled( bool enable );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetRainLevel( float rainLevel );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetSunSize( float sunSize );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetSunColor( Color coreColor, Color coronaColor );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetWindVelocity( Vector3 velocity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetFarClipDistance( float farClip );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetFogDistance( float fogDist );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetAircraftMaxHeight( float maxHeight );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetAircraftMaxVelocity( float velocity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetOcclusionsEnabled( bool enabled );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetRainLevel();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetSunSize();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetSunColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetWindVelocity();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetFarClipDistance();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetFogDistance();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool RemoveWorldModel( ushort model, float radius, Vector3 position, byte interior );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool RestoreWorldModel( ushort model, float radius, Vector3 position, byte interior );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool RestoreAllWorldModels();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool SetMoonSize( int iMoonSize );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ResetMoonSize();
	}
}
