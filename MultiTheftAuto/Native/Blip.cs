using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	internal class Blip
	{
		// Blip create/destroy functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( Vector3 position, int icon = 0, int size = 2, Color color = null, int ordering = 0, float visibleDistance = 99999.0f, UInt32 visibleTo = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 CreateAttachedTo( UInt32 element, int icon = 0, int size = 2, Color color = null, int ordering = 0, float visibleDistance = 99999.0f, UInt32 visibleTo = 0 );

		// Blip get functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetIcon( UInt32 blip );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetSize( UInt32 blip );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Color GetColor( UInt32 blip );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetOrdering( UInt32 blip );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetVisibleDistance( UInt32 blip );

		// Blip set functions
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetIcon( UInt32 blip, int icon );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetSize( UInt32 blip, int size );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetColor( UInt32 blip, Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetOrdering( UInt32 blip, int ordering );
		
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetVisibleDistance( UInt32 blip, float distance );
	}
}
