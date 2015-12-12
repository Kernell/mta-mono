using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MultiTheftAuto.Pools;
using MultiTheftAuto.Utils;

namespace MultiTheftAuto
{
	public class Resource : IdentifiedPool<Resource>, IIdentifyable
	{
		#region Properties

		public UInt32 userdata
		{
			get;
			private set;
		}

		#endregion

		#region Static properties

		public static Element Root
		{
			get
			{
				return Element.FindOrCreate( Native.Resource.GetRootElement() );
			}
		}

		#endregion

		#region Constuctors

		public Resource( string resourceName, string organizationalDir )
			: this( Native.Resource.Create( resourceName, organizationalDir ) )
		{
		}

		public Resource( UInt32 userdata )
		{
			this.userdata = userdata;
		}

		#endregion

		#region Methods

		public Resource Copy( string newResourceName, string organizationalDir )
		{
			return new Resource( Native.Resource.Copy( this.userdata, newResourceName, organizationalDir ) );
		}

		public Element GetRoot()
		{
			return Element.FindOrCreate( Native.Resource.GetRootElement( this.userdata ) );
		}

		public Element GetMapRootElement( UInt32 resource, string map )
		{
			return Element.FindOrCreate( Native.Resource.GetMapRootElement( this.userdata, map ) );
		}

		public Element GetDynamicElementRoot()
		{
			return Element.FindOrCreate( Native.Resource.GetDynamicElementRoot( this.userdata ) );
		}

		public bool RemoveFile( string filename )
		{
			return Native.Resource.RemoveFile( this.userdata, filename );
		}

		public string GetInfo( string attribute )
		{
			return Native.Resource.GetInfo( this.userdata, attribute );
		}

		public uint GetLastStartTime()
		{
			return Native.Resource.GetLastStartTime( this.userdata );
		}

		public string GetLoadFailureReason()
		{
			return Native.Resource.GetLoadFailureReason( this.userdata );
		}

		public uint GetLoadTime()
		{
			return Native.Resource.GetLoadTime( this.userdata );
		}

		public string GetName()
		{
			return Native.Resource.GetName( this.userdata );
		}

		public string GetState()
		{
			return Native.Resource.GetState( this.userdata );
		}

		public bool SetDefaultSetting( string settingName, string settingValue )
		{
			return Native.Resource.SetDefaultSetting( this.userdata, settingName, settingValue );
		}

		public bool RemoveDefaultSetting( string settingName )
		{
			return Native.Resource.RemoveDefaultSetting( this.userdata, settingName );
		}

		public bool Start( bool persistent = false, bool startIncludedResources = true, bool loadServerConfigs = true, bool loadMaps = true, bool loadServerScripts = true, bool loadHTML = true, bool loadClientConfigs = true, bool loadClientScripts = true, bool loadFiles = true )
		{
			return Native.Resource.Start( this.userdata, persistent, startIncludedResources, loadServerConfigs, loadMaps, loadServerScripts, loadHTML, loadClientConfigs, loadClientScripts, loadFiles );
		}

		public bool Restart()
		{
			return Native.Resource.Restart( this.userdata );
		}

		public bool Stop()
		{
			return Native.Resource.Stop( this.userdata );
		}

		public bool SetInfo( string attribute, string value )
		{
			return Native.Resource.SetInfo( this.userdata, attribute, value );
		}

		public bool Rename( string newResourceName, string organizationalPath )
		{
			return Native.Resource.Rename( this.GetName(), newResourceName, organizationalPath );
		}

		public bool Delete()
		{
			return Native.Resource.Delete( this.GetName() );
		}

		public bool UpdateACLRequest( string rightName, bool bAccess, string byWho )
		{
			return Native.Resource.UpdateACLRequest( this.userdata, rightName, bAccess, byWho );
		}

		#endregion

		#region Static methods

		public static bool Rename( string resourceName, string newResourceName, string organizationalPath )
		{
			return Native.Resource.Rename( resourceName, newResourceName, organizationalPath );
		}

		public static bool Delete( string resourceName )
		{
			return Native.Resource.Delete( resourceName );
		}

		public static bool Refresh( bool refreshAll = false )
		{
			return Native.Resource.Refresh( refreshAll );
		}

		public static Resource GetCurrent()
		{
			return Resource.FindOrCreate( Native.Resource.GetCurrent() );
		}

		public static Resource[] GetAll()
		{
			UInt32[] userdataArray = Native.Resource.GetResources();

			Resource[] resources = new Resource[ userdataArray.Length ];

			for( uint i = 0; i < userdataArray.Length; i++ )
			{
				resources.SetValue( Resource.FindOrCreate( userdataArray[ i ] ), i );
			}

			return resources;
		}

		public static Element GetRootElement( Element resource = null )
		{
			return Element.FindOrCreate( Native.Resource.GetRootElement( resource.userdata ) );
		}

		public static Resource GetFromName( string resourceName )
		{
			UInt32 userdata = Native.Resource.GetFromName( resourceName );

			if( userdata != 0 )
			{
				return Resource.FindOrCreate( userdata );
			}

			return null;
		}

		#endregion
	}
}
