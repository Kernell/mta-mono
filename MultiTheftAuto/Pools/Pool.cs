using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using MultiTheftAuto.Utils;

namespace MultiTheftAuto.Pools
{
	public abstract class Pool<T> : Disposable
	{
		protected static readonly List<object> Instances = new List<object>();
		protected static ReadOnlyCollection<T> ReadOnly = new ReadOnlyCollection<T>( new List<T>() );
		protected static object Lock = new object();

		protected Pool()
		{
			lock( Lock )
			{
				Instances.Add( this );
				ReadOnly = Instances.OfType<T>().ToList().AsReadOnly();
			}
		}

		public static ReadOnlyCollection<T> All
		{
			get
			{
				lock( Lock )
				{
					return ReadOnly;
				}
			}
		}

		protected override void Dispose( bool disposing )
		{
			lock( Lock )
			{
				Instances.Remove( this );
				ReadOnly = Instances.OfType<T>().ToList().AsReadOnly();
			}
		}

		public static bool Contains( T item )
		{
			lock( Lock )
			{
				return Instances.Contains( item );
			}
		}

		public static ReadOnlyCollection<T2> GetAll<T2>()
		{
			lock( Lock )
			{
				return Instances.OfType<T2>().ToList().AsReadOnly();
			}
		}
	}
}
