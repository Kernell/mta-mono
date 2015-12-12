using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
    public static class Config
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string Get( string key );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Set( string key, string value );
    }
}
