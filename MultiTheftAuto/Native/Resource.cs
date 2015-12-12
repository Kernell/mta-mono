using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public class Resource
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Create( string resourceName, string organizationalDir );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Copy( UInt32 resource, string newResourceName, string organizationalDir );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetRootElement( UInt32 resource = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetMapRootElement( UInt32 resource, string map );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetDynamicElementRoot( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveFile( UInt32 resource, string filename );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetFromName( string resourceName );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetInfo( UInt32 resource, string attribute );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern uint GetLastStartTime( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetLoadFailureReason( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern uint GetLoadTime( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetName( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32[] GetResources();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetState( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetCurrent();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Refresh( bool refreshAll = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveDefaultSetting( UInt32 resource, string settingName );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Start( UInt32 resource, bool persistent = false, bool startIncludedResources = true, bool loadServerConfigs = true, bool loadMaps = true, bool loadServerScripts = true, bool loadHTML = true, bool loadClientConfigs = true, bool loadClientScripts = true, bool loadFiles = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Restart( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Stop( UInt32 resource );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDefaultSetting( UInt32 resource, string settingName, string settingValue );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetInfo( UInt32 resource, string attribute, string value );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Rename( string resourceName, string newResourceName, string organizationalPath );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Delete( string resourceName );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool UpdateACLRequest( UInt32 resource, string rightName, bool bAccess, string byWho );
	}
}
