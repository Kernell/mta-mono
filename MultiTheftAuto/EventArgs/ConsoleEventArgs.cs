using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ConsoleEventArgs : ElementEventArgs
	{
		public ConsoleEventArgs( Element _this, string message )
			: base( _this )
		{
			this.Message = message;
		}

		public string Message;
	}
}
