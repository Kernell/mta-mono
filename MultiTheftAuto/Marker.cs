using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Marker : Element
	{
		#region Constructors

		internal Marker()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Marker( Vector3 position, string type = "checkpoint", float size = 4.0f, Color color = null, Element visibleTo = null );

		#endregion

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetCount();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetMarkerType();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetSize();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vector3 GetTarget();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetIcon();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetType( string type );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetSize( float size );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetColor( Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTarget( Vector3 position );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetIcon( string icon );
	}
}
