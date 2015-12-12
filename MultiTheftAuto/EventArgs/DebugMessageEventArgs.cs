using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class DebugMessageEventArgs : ElementEventArgs
	{
		public DebugMessageEventArgs( Element _this, string message, int level, string file, int line )
			: base( _this )
		{
			this.Message	= message;
			this.Level		= level;
			this.File		= file;
			this.Line		= line;
		}

		public string Message;
		public int Level;
		public string File;
		public int Line;
	}
}
