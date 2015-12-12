using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiTheftAuto
{
	public class Team : Element
	{
		#region Construcotrs

		public Team( string name, Color color = null )
			: base( Native.Team.Create( name, color ) )
		{
			
		}

		public Team( UInt32 userdata )
			: base( userdata )
		{

		}

		#endregion

		#region Methods

		public string GetName()
		{
			return Native.Team.GetName( this.userdata );
		}

		public Color GetColor()
		{
			return Native.Team.GetColor( this.userdata );
		}

		public bool GetFriendlyFire()
		{
			return Native.Team.GetFriendlyFire( this.userdata );
		}

		public Player[] GetPlayers()
		{
			UInt32[] userdataArray = Native.Team.GetPlayers( this.userdata );

			Player[] players = new Player[ userdataArray.Length ];

			for( uint i = 0; i < userdataArray.Length; i++ )
			{
				players.SetValue( Element.FindOrCreate( userdataArray[ i ] ) as Player, i );
			}

			return players;
		}

		public int CountPlayers()
		{
			return Native.Team.CountPlayers( this.userdata );
		}

		public bool SetName( string name )
		{
			return Native.Team.SetName( this.userdata, name );
		}

		public bool SetColor( Color color )
		{
			return Native.Team.SetColor( this.userdata, color );
		}

		public bool SetFriendlyFire( bool enabled )
		{
			return Native.Team.SetFriendlyFire( this.userdata, enabled );
		}

		#endregion

		#region Static methods

		public static Team GetFromName( string name )
		{
			return Element.FindOrCreate( Native.Team.GetFromName( name ) ) as Team;
		}

		#endregion
	}
}
