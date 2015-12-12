using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerContactEventArgs : ElementEventArgs
	{
		public PlayerContactEventArgs( Element _this, Element previous, Element current )
			: base( _this )
		{
			this.Previous	= previous;
			this.Current	= current;
		}

		public Element Previous;
		public Element Current;
	}
}
