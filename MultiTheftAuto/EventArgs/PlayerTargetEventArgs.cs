using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerTargetEventArgs : ElementEventArgs
	{
		public PlayerTargetEventArgs( Element _this, Element targettedElement )
			: base( _this )
		{
			this.Target = targettedElement;
		}

		public Element Target;
	}
}
