using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace MultiTheftAuto
{
	public class Team : Element
	{
		#region Construcotrs

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Team( string name, Color color = null );

		private Team()
		{
		}

		#endregion

		#region Methods

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetName();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GetFriendlyFire();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Player[] GetPlayers();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int CountPlayers();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetName( string name );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetColor( Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetFriendlyFire( bool enabled );

		#endregion

		#region Static methods

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Team GetFromName( string name );

		#endregion
	}
}
