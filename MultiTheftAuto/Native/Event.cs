using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
    internal static class Event
    {
        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Add( string name, bool allowRemoteTrigger );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AddHandler( string eventName, UInt32 attachedTo, Delegate handlerFunction, bool getPropagated = true, string priority = "normal" );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveHandler( string eventName, UInt32 attachedTo, Delegate handlerFunction );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Trigger( string eventName, UInt32 baseElement, params object[] arguments );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool TriggerClient( UInt32 sendTo, string name, UInt32 sourceElement, params object[] arguments );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern bool Cancel( bool cancel = true, string reason = "" );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern string GetCancelReason();

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern bool WasCancelled();

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int TriggerLatentClient( UInt32 sendTo, string name, int bandwidth, bool persist, UInt32 theElement, params object[] arguments );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetLatentHandles( UInt32 player );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetLatentStatus( UInt32 player, int handle );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int CancelLatent( UInt32 player, int handle );
    }
}
