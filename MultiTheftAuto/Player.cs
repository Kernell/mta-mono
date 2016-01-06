using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiTheftAuto
{
	public class Player : Ped
	{
		#region Methods

		#region Set

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetMoney( int money );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GiveMoney( int money );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool TakeMoney( int money );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Spawn( Vector3 position, int rotation = 0, int skinID = 0, int interior = 0, int dimension = 0, Team team = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool ShowHudComponent( string component, bool show );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetWantedLevel( int level );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool ForceMap( bool forcedOn );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetNametagText( string text );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetNametagColor( Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetNametagShowing( bool showed );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetMuted( bool muted );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetBlurLevel( int level );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Redirect( string serverIP, int serverPort, string serverPassword = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetName( string name );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool DetonateSatchels();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool TakeScreenShot( int width, int height, string tag = "", int quality = 30, int maxBandwith = 5000 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTeam( Team team );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetCameraMatrix( CameraMatrix pCameraMatrix );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetCameraTarget( Element pTarget );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetCameraInterior( UInt16 ucInterior );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool FadeCamera( bool bFadeIn, float fFadeTime, Color pColor );

		#endregion

		#region Get

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetAmmoInClip( int weaponSlot = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetTotalAmmo( int weaponSlot = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetWeaponAmmo( int weapon, int totalAmmo, int ammoInClip );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Player GetFromName( string name );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetMoney();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetPing();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Player GetRandom();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Team GetTeam();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetWantedLevel();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetIdleTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetNametagText();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetNametagColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetSerial();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetUserName();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetBlurLevel();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetName();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetIP();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Account GetAccount();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetVersion();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern PlayerACInfo GetACInfo();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern CameraMatrix GetCameraMatrix();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Element GetCameraTarget();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern UInt16 GetCameraInterior();

		#endregion

		#region Is

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsMuted();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsMapForced();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsNametagShowing();

		#endregion

		#endregion

		#region Static

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Player[] GetAlivePlayers();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Player[] GetDeadPlayers();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static int GetCount();
		
		#endregion
	}
}
