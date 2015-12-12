using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public delegate void CommandHandler( Player player, string command, string[] args );

	public static class Server
	{
		public static bool OutputChatBox( string text, Element element, Color color, bool colorCoded )
		{
			return Native.Server.OutputChatBox( text, element.userdata, color, colorCoded );
		}

		public static bool AddCommandHandler( string name, CommandHandler handler, bool restricted = false, bool caseSensitive = true )
		{
			return Native.Server.AddCommandHandler( name, handler, restricted, caseSensitive );
		}

		public static bool ExecuteCommandHandler( string name, Player player, string args )
		{
			return Native.Server.ExecuteCommandHandler( name, player.userdata, args );
		}

		public static bool RemoveCommandHandler( string name, CommandHandler handler )
		{
			return Native.Server.RemoveCommandHandler( name, handler );
		}
	}
}
