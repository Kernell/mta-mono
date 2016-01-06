using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Fire
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Create( Vector3 position, float size = 1.8f );
	}
}
