using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Server
	{
		public static bool OutputChatBox( string text, Element element, Color color, bool colorCoded )
		{
			return Native.Server.OutputChatBox( text, element.userdata, color, colorCoded );
		}
		public static bool OutputConsole( string text, Element element )
		{
			return Native.Server.OutputConsole( text, element.userdata );
		}
	}
}
