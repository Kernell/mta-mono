using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public delegate void CommandHandler( Player player, string command, string[] args );

	public static class Server
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool OutputChatBox( string text, Element element, Color color, bool colorCoded );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool AddCommandHandler( string name, CommandHandler handler, bool restricted = false, bool caseSensitive = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool ExecuteCommandHandler( string name, Player player, string args );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool RemoveCommandHandler( string name, CommandHandler handler = null );
	}
}
