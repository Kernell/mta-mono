using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.Utils
{
	/// <summary>
	///     Defines methods to release allocated resources and to check whether this resource has been disposed.
	/// </summary>
	public abstract class Disposable : IDisposable
	{
		/// <summary>
		///     Gets whether this resource has been disposed.
		/// </summary>
		public bool Disposed
		{
			get;
			private set;
		}

		/// <summary>
		///     Performs tasks associated with freeing, releasing, or resetting unmanaged resources.
		/// </summary>
		public void Dispose()
		{
			if( Disposed )
			{
				//We've been desposed already. Abort further disposure.
				return;
			}
			//Dispose all native and managed resources.
			Dispose( true );

			//Remember we've been disposed.
			Disposed = true;

			//Suppress finalisation; We already disposed our  resources.
			GC.SuppressFinalize( this );
		}

		~Disposable()
		{
			if( Disposed )
			{
				//We've been desposed already. Abort further disposure.
				return;
			}

			Dispose( false );

			//We don't care to set Disposed value; Resource is being collected by GC anyways.
		}

		protected void CheckDisposure()
		{
			if( Disposed )
			{
				throw new ObjectDisposedException( "Cannot access disposed resource." );
			}
		}

		/// <summary>
		///     Performs tasks associated with freeing, releasing, or resetting unmanaged resources.
		/// </summary>
		/// <param name="disposing">Whether managed resources should be disposed.</param>
		protected abstract void Dispose( bool disposing );
	}
}
