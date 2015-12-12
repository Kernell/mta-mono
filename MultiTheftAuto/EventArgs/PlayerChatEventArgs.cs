using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerChatEventArgs : ElementEventArgs
	{
		public PlayerChatEventArgs( Element _this, string message, int messageType )
			: base( _this )
		{
			this.Message	= message;
			this.Type		= messageType;
		}

		public string Message;
		public int Type;
	}
}
