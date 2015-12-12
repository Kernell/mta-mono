using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MultiTheftAuto.Utils;

namespace MultiTheftAuto.Pools
{
	public abstract class IdentifiedPool<T> : Pool<T> where T : class, IIdentifyable
	{
		protected static Type InstanceType;

		public static void Register<T2>() where T2 : T
		{
			InstanceType = typeof( T2 );
		}

		public static T Find( UInt32 userdata )
		{
			return All.FirstOrDefault( i => i.userdata == userdata );
		}

		public static T Create( UInt32 userdata )
		{
			return (T)Activator.CreateInstance( InstanceType, userdata );
		}

		public static T FindOrCreate( UInt32 userdata )
		{
			return Find( userdata ) ?? Create( userdata );
		}
	}
}
