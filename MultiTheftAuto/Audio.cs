using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Audio
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public static bool PlayFrontEnd( Player player, byte sound );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public static bool PlayMission( Player player, Vector3 position, ushort slot );
	}
}
