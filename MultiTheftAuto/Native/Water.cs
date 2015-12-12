using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class Water
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( Vector3 position1, Vector3 position2, Vector3 position3, Vector3 position4 = null, bool bShallow = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLevel( float level, bool includeWaterFeatures = true, bool includeWaterElements = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLevel( UInt32 water, float level );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ResetLevel();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetVertexPosition( UInt32 water, int vertex );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetVertexPosition( UInt32 water, Vector3 position );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Color GetColor( UInt32 water );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetColor( UInt32 water, Color color );
		
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ResetColor();
	}
}
