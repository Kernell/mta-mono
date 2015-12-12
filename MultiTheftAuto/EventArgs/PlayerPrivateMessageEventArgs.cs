using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerPrivateMessageEventArgs : PlayerCancelEventArgs
	{
		public PlayerPrivateMessageEventArgs( Element _this, string message, Player recipient )
			: base( _this, recipient )
		{
			this.Message = message;
		}

		public string Message;
	}
}
