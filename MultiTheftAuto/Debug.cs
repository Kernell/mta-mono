using System;
using System.Runtime.CompilerServices;
using System.Diagnostics;
using System.Reflection;
using System.IO;

namespace MultiTheftAuto
{
    public static class Debug
    {
		private static string assemblyName = Resource.GetCurrent().GetName();

        [MethodImpl( MethodImplOptions.InternalCall )]
		private static extern void Log( string message );

		[MethodImpl( MethodImplOptions.InternalCall )]
		private static extern void Info( string message );

		[MethodImpl( MethodImplOptions.InternalCall )]
		private static extern void Error( string message );

		public static void Log( string message, params object[] args )
		{
			Log( String.Format( message, args ) );
		}

		public static string FormatPath( string path )
		{
			string filepath = "";

			bool start = false;

			foreach( string s in path.Split( '\\' ) )
			{
				if( start )
				{
					if( filepath.Length > 0 )
					{
						filepath += "\\";
					}

					filepath += s;
				}

				if( s == assemblyName )
				{
					start = true;
				}
			}

			return filepath;
		}

		public static void Info( string message, [CallerMemberName] string memberName = "", [CallerFilePath] string filePath = "", [CallerLineNumber] int lineNumber = 0 )
		{
			Info( String.Format( "{0}:{1}: {2}", FormatPath( filePath ), lineNumber, message ) );
		}

		public static void Error( string message, [CallerMemberName] string memberName = "", [CallerFilePath] string filePath = "", [CallerLineNumber] int lineNumber = 0 )
		{
			Error( String.Format( "{0}:{1}: {2}", FormatPath( filePath ), lineNumber, message ) );
		}
    }
}
