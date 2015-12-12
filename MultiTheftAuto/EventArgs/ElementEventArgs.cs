using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ElementEventArgs : System.EventArgs
	{
		public ElementEventArgs( Element _this )
		{
			this.This = _this;
		}

		public Element This;
	}
}
