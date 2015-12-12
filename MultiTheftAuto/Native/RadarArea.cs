using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class RadarArea
	{
		// Radar area create/destroy funcs
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( float leftX, float bottomY, float sizeX, float sizeY, Color color = null, UInt32 visibleTo = 0 );

		// Radar area get funcs
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetSize( UInt32 radarArea );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Color GetColor( UInt32 radarArea );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsFlashing( UInt32 radarArea );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsInside( UInt32 radarArea, float leftX, float bottomY );

		// Radar area set funcs
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetSize( UInt32 radarArea, float sizeX, float sizeY );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetColor( UInt32 radarArea, Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetFlashing( UInt32 radarArea, bool enabled );
	}
}
