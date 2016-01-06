using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Explosion
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Create( Vector3 position, int theType, Element creator = null );
	}
}
