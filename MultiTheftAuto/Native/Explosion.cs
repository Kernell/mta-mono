using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class Explosion
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Create( Vector3 position, int theType, UInt32 creator = 0 );
	}
}
