using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public class Account : Element
	{
		internal Account()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public Account Add( string name, string password );

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public Account Get( string name, string password );

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public Account[] GetBySerial( string serial );

		[MethodImpl( MethodImplOptions.InternalCall )]
		static extern public Account[] GetAll();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public Player GetPlayer();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool IsGuest();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public object GetData( string key );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public object[] GetAllData();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public string GetSerial();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool Remove();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetPassword( string password );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetData( string key, object argument );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool CopyData( Account fromAccount );
	}
}
