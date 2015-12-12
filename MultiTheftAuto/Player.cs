using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiTheftAuto
{
	public class Player : Ped
	{
		#region Constructors
		
		public Player( UInt32 userdata )
			: base( userdata )
		{

		}
		
		#endregion

		#region Methods

		#region Set

		public bool SetMoney( int money )
		{
			return Native.Player.SetMoney( this.GetUserData(), money );
		}

		public bool GiveMoney( int money )
		{
			return Native.Player.GiveMoney( this.GetUserData(), money );
		}

		public bool TakeMoney( int money )
		{
			return Native.Player.TakeMoney( this.GetUserData(), money );
		}

		public bool Spawn( Vector3 position, int rotation = 0, int skinID = 0, int interior = 0, int dimension = 0, Team team = null )
		{
			return Native.Player.Spawn( this.GetUserData(), position, rotation, skinID, interior, dimension, team != null ? team.GetUserData() : 0 );
		}

		public bool ShowHudComponent( string component, bool show )
		{
			return Native.Player.ShowHudComponent( this.GetUserData(), component, show );
		}

		public bool SetWantedLevel( int level )
		{
			return Native.Player.SetWantedLevel( this.GetUserData(), level );
		}

		public bool ForceMap( bool forcedOn )
		{
			return Native.Player.ForceMap( this.GetUserData(), forcedOn );
		}

		public bool SetNametagText( string text )
		{
			return Native.Player.SetNametagText( this.GetUserData(), text );
		}

		public bool SetNametagColor( Color color )
		{
			return Native.Player.SetNametagColor( this.GetUserData(), color );
		}

		public bool SetNametagShowing( bool showed )
		{
			return Native.Player.SetNametagShowing( this.GetUserData(), showed );
		}

		public bool SetMuted( bool muted )
		{
			return Native.Player.SetMuted( this.GetUserData(), muted );
		}

		public bool SetBlurLevel( int level )
		{
			return Native.Player.SetBlurLevel( this.GetUserData(), level );
		}

		public bool Redirect( string serverIP, int serverPort, string serverPassword = null )
		{
			return Native.Player.Redirect( this.GetUserData(), serverIP, serverPort, serverPassword );
		}

		public bool SetName( string name )
		{
			return Native.Player.SetName( this.GetUserData(), name );
		}

		public bool DetonateSatchels()
		{
			return Native.Player.DetonateSatchels( this.GetUserData() );
		}

		public bool TakeScreenShot( int width, int height, string tag = "", int quality = 30, int maxBandwith = 5000 )
		{
			return Native.Player.TakeScreenShot( this.GetUserData(), width, height, tag, quality, maxBandwith );
		}

		public bool SetTeam( Team team )
		{
			return Native.Player.SetTeam( this.GetUserData(), team.GetUserData() );
		}

		public bool SetCameraMatrix( CameraMatrix pCameraMatrix )
		{
			return Native.Player.SetCameraMatrix( this.userdata, pCameraMatrix );
		}

		public bool SetCameraTarget( Element pTarget )
		{
			return Native.Player.SetCameraTarget( this.userdata, pTarget.userdata );
		}

		public bool SetCameraInterior( UInt16 ucInterior )
		{
			return Native.Player.SetCameraInterior( this.userdata, ucInterior );
		}

		public bool FadeCamera( bool bFadeIn, float fFadeTime, Color pColor )
		{
			return Native.Player.FadeCamera( this.userdata, bFadeIn, fFadeTime, pColor );
		}

		#endregion

		#region Get

		public int GetAmmoInClip( int weaponSlot = 0 )
		{
			return Native.Player.GetAmmoInClip( this.GetUserData(), weaponSlot );
		}

		public int GetTotalAmmo( int weaponSlot = 0 )
		{
			return Native.Player.GetTotalAmmo( this.GetUserData(), weaponSlot );
		}

		public bool SetWeaponAmmo( int weapon, int totalAmmo, int ammoInClip )
		{
			return Native.Player.SetWeaponAmmo( this.GetUserData(), weapon, totalAmmo, ammoInClip );
		}

		public Player GetFromName( string name )
		{
			return Element.FindOrCreate( Native.Player.GetFromName( name ) ) as Player;
		}

		public int GetMoney()
		{
			return Native.Player.GetMoney( this.GetUserData() );
		}

		public int GetPing()
		{
			return Native.Player.GetPing( this.GetUserData() );
		}

		public Player GetRandom()
		{
			return Element.FindOrCreate( Native.Player.GetRandom() ) as Player;
		}

		public Team GetTeam()
		{
			return Element.FindOrCreate( Native.Player.GetTeam( this.GetUserData() ) ) as Team;
		}

		public int GetWantedLevel()
		{
			return Native.Player.GetWantedLevel( this.GetUserData() );
		}

		public int GetIdleTime()
		{
			return Native.Player.GetIdleTime( this.GetUserData() );
		}

		public string GetNametagText()
		{
			return Native.Player.GetNametagText( this.GetUserData() );
		}

		public Color GetNametagColor()
		{
			return Native.Player.GetNametagColor( this.GetUserData() );
		}

		public string GetSerial()
		{
			return Native.Player.GetSerial( this.GetUserData() );
		}

		public string GetUserName()
		{
			return Native.Player.GetUserName( this.GetUserData() );
		}

		public int GetBlurLevel()
		{
			return Native.Player.GetBlurLevel( this.GetUserData() );
		}

		public string GetName()
		{
			return Native.Player.GetName( this.GetUserData() );
		}

		public string GetIP()
		{
			return Native.Player.GetIP( this.GetUserData() );
		}

		public Account GetAccount()
		{
			return Element.FindOrCreate( Native.Player.GetAccount( this.GetUserData() ) ) as Account;
		}

		public string GetVersion()
		{
			return Native.Player.GetVersion( this.GetUserData() );
		}

		public Object GetACInfo()
		{
			return Native.Player.GetACInfo( this.GetUserData() );
		}

		public CameraMatrix GetCameraMatrix()
		{
			return Native.Player.GetCameraMatrix( this.userdata );
		}

		public UInt32 GetCameraTarget()
		{
			return Native.Player.GetCameraTarget( this.userdata );
		}

		public UInt16 GetCameraInterior()
		{
			return Native.Player.GetCameraInterior( this.userdata );
		}

		#endregion

		#region Is

		public bool IsMuted()
		{
			return Native.Player.IsMuted( this.GetUserData() );
		}

		public bool IsMapForced()
		{
			return Native.Player.IsMapForced( this.GetUserData() );
		}

		public bool IsNametagShowing()
		{
			return Native.Player.IsNametagShowing( this.GetUserData() );
		}

		#endregion

		#endregion

		#region Static
		
		public static Array GetAlivePlayers()
		{
			return Native.Player.GetAlivePlayers();
		}

		public static Array GetDeadPlayers()
		{
			return Native.Player.GetDeadPlayers();
		}

		public static int GetCount()
		{
			return Native.Player.GetCount();
		}
		
		#endregion
	}
}
