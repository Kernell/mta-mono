using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Water : Element
	{
		internal Water()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Water( Vector3 position1, Vector3 position2, Vector3 position3, Vector3 position4 = null, bool bShallow = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLevelWorld( float level, bool includeWaterFeatures = true, bool includeWaterElements = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetLevel( float level );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ResetLevel();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vector3 GetVertexPosition( int vertex );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetVertexPosition( Vector3 position );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetColor( Color color );
		
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ResetColor();
	}
}
