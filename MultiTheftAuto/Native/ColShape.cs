using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
    public class ColShape
    {
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreateCircle( float fX, float fY, float radius );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreateCuboid( float fX, float fY, float fZ, float fWidth, float fDepth, float fHeight );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreateSphere( float fX, float fY, float fZ, float fRadius );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreateRectangle( float fX, float fY, float fWidth, float fHeight );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreatePolygon( float fX, float fY, float fX1, float fY1, float fX2, float fY2, float fX3, float fY3, float[] args );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreateTube( float fX, float fY, float fZ, float fRadius, float fHeight );
    }
}
