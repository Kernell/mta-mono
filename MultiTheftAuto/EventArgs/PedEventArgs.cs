using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PedEventArgs : ElementEventArgs
	{
		public PedEventArgs( Element _this, Ped ped )
			: base( _this )
		{
			this.Ped = ped;
		}

		public Ped Ped;
	}
}
