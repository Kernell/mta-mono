using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class Resource
	{
		#region Static properties

		public static Element Root
		{
			get
			{
				return Resource.GetCurrent().GetRoot();
			}
		}

		#endregion

		#region Constuctors

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Resource( string resourceName, string organizationalDir );

		private Resource()
		{
		}

		#endregion

		#region Methods

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Resource Copy( string newResourceName, string organizationalDir );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Element GetRoot();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Element GetMapRootElement( UInt32 resource, string map );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Element GetDynamicElementRoot();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveFile( string filename );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetInfo( string attribute );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern uint GetLastStartTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetLoadFailureReason();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern uint GetLoadTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetName();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetState();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetDefaultSetting( string settingName, string settingValue );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveDefaultSetting( string settingName );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Start( bool persistent = false, bool startIncludedResources = true, bool loadServerConfigs = true, bool loadMaps = true, bool loadServerScripts = true, bool loadHTML = true, bool loadClientConfigs = true, bool loadClientScripts = true, bool loadFiles = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Restart();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Stop();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetInfo( string attribute, string value );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Rename( string newResourceName, string organizationalPath );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Delete();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool UpdateACLRequest( string rightName, bool bAccess, string byWho );

		#endregion

		#region Static methods

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool Rename( string resourceName, string newResourceName, string organizationalPath );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool Delete( string resourceName );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static bool Refresh( bool refreshAll = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Resource GetCurrent();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Resource[] GetAll();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Resource GetFromName( string resourceName );

		#endregion
	}
}
