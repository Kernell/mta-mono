using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class Object
	{
		// Object create/destroy functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( int modelid, Vector3 position, Vector3 rotation, bool isLowLOD = false );

		// Object get functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetScale( UInt32 Object );

		// Object set functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetScale( UInt32 Object, float scale );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Move( UInt32 Object, int time, Vector3 target, Vector3 rotation, string easingType, float easingPeriod, float easingAmplitude, float easingOvershoot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Stop( UInt32 Object );
	}
}
