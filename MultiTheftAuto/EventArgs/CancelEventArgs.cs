using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class CancelEventArgs : ElementEventArgs
	{
		public CancelEventArgs( Element _this )
			: base( _this )
		{
		
		}

		public void Cancel( bool cancel = true, string reason = "" )
		{
			Event.Cancel( cancel, reason );
		}
	}
}
