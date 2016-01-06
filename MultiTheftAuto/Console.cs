using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class Console : Player
	{
		private Console()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Output( string text, Element element = null );

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

		[MethodImpl( MethodImplOptions.InternalCall )]
		private static extern void Write( string message );

		[MethodImpl( MethodImplOptions.InternalCall )]
		private static extern void WriteLine( string message );

		public static void Write( string message, params object[] args )
		{
			Write( String.Format( message, args ) );
		}

		public static void WriteLine( string message, params object[] args )
		{
			WriteLine( String.Format( message, args ) );
		}
	}
}
