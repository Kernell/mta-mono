using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class RadarArea : Element
	{
		internal RadarArea()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern RadarArea( float leftX, float bottomY, float sizeX, float sizeY, Color color = null, Element visibleTo = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vector3 GetSize();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsFlashing();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsInside( float leftX, float bottomY );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetSize( float sizeX, float sizeY );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetColor( Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetFlashing( bool enabled );
	}
}
