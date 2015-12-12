using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ElementModelChangeEventArgs : ElementEventArgs
	{
		public ElementModelChangeEventArgs( Element _this, int oldModel, int newModel )
			: base( _this )
		{
			this.OldModel = oldModel;
			this.NewModel = newModel;
		}

		public int OldModel;
		public int NewModel;
	}
}
