using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.Native
{
	internal class Server
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern uint GetMaxPlayers();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetMaxPlayers( uint maxPlayers );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool OutputChatBox( string text, UInt32 element, Color color, bool colorCoded );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool OutputConsole( string text, UInt32 element );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool OutputServerLog( string text );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetPassword( string password, bool bSave );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern ServerVersion GetVersion();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool AddCommandHandler( string name, Delegate handler, bool restricted = false, bool caseSensitive = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ExecuteCommandHandler( string name, UInt32 player, string args );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveCommandHandler( string name, Delegate handler );
	}
}
