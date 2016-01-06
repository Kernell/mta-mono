using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Ban : Element
	{
		internal Ban()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public Ban Add( string ip, string username, string serial, Element responsible, string responsibleName, string reason, int unban );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool Remove( Ban ban, Element responsible );

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public Ban[] GetAll();

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public bool Reload();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetIP();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetSerial();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetUsername();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetNick();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetReason();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetAdmin();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public int GetBanTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public int GetUnbanTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetUnbanTime( int time );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetReason( string msReason );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetAdmin( string msAdminName );
	}
}
