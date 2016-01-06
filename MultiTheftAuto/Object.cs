using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Object : Element
	{
		internal Object()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Object( int modelid, Vector3 position, Vector3 rotation, bool isLowLOD = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetScale();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetScale( float scale );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Move( int time, Vector3 target, Vector3 rotation, string easingType, float easingPeriod, float easingAmplitude, float easingOvershoot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Stop();
	}
}
