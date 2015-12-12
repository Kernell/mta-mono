using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ChatMessageEventArgs : ElementEventArgs
	{
		public ChatMessageEventArgs( Element _this, string message, Resource element )
			: base( _this )
		{
			this.Message = message;
			this.Element = element;
		}

		public ChatMessageEventArgs( Element _this, string message, Element element )
			: base( _this )
		{
			this.Message = message;
			this.Element = element;
		}

		public string Message;
		public object Element;
	}
}
