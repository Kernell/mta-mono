using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerPickupUseEventArgs : CancelEventArgs
	{
		public PlayerPickupUseEventArgs( Element _this, Pickup pickup )
			: base( _this )
		{
			this.Pickup = pickup;
		}

		public Pickup Pickup;
	}
}
