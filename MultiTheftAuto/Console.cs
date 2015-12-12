using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class Console : Player
	{
		public Console( uint userdata ) :
			base( userdata )
		{
		}

		public static bool Output( string text, Element element = null )
		{
			return Native.Server.OutputConsole( text, element == null ? Element.Root.userdata : element.userdata );
		}

		public static int Read()
		{
			return System.Console.Read();
		}

		public static ConsoleKeyInfo ReadKey()
		{
			return System.Console.ReadKey();
		}

		public static ConsoleKeyInfo ReadKey( bool intercept )
		{
			return System.Console.ReadKey( intercept );
		}

		public static string ReadLine()
		{
			return System.Console.ReadLine();
		}

		public static bool Write( string message, params string[] args )
		{
			return Native.Server.OutputServerLog( string.Format( message, args ) );
		}

		public static bool WriteLine( string message, params string[] args )
		{
			return Native.Server.OutputServerLog( string.Format( message, args ) );
		}
	}
}
