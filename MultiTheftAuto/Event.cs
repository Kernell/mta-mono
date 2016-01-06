using MultiTheftAuto.EventArgs;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Event
	{
		#region Static methods

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Add( string name, bool allowRemoteTrigger );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AddHandler( string eventName, Element attachedTo, Delegate handlerFunction, bool getPropagated = true, string priority = "normal" );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveHandler( string eventName, Element attachedTo, Delegate handlerFunction );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Trigger( string eventName, Element baseElement, params object[] arguments );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool TriggerClient( Element sendTo, string name, Element sourceElement, params object[] arguments );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Cancel( bool cancel = true, string reason = "" );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetCancelReason();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool WasCancelled();

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static extern int TriggerLatentClient( Element sendTo, string name, int bandwidth, bool persist, Element theElement, params object[] arguments );

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static extern int GetLatentHandles( Player player );

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static extern int GetLatentStatus( Player player, int handle );

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static extern int CancelLatent( Player player, int handle );
		
		#endregion
	}
}
