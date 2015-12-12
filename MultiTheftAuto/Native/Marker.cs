using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class Marker
	{
		// Marker create/destroy functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( Vector3 position, string type = "checkpoint", float size = 4.0f, Color color = null, UInt32 visibleTo = 0 );

		// Marker get functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetCount();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetType( UInt32 marker );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetSize( UInt32 marker );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Color GetColor( UInt32 marker );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetTarget( UInt32 marker );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetIcon( UInt32 marker );

		// Marker set functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetType( UInt32 marker, string type );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetSize( UInt32 marker, float size );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetColor( UInt32 marker, Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetTarget( UInt32 marker, Vector3 position );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetIcon( UInt32 marker, string icon );
	}
}
