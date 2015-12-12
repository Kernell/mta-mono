using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerPickupHitEventArgs : CancelEventArgs
	{
		public PlayerPickupHitEventArgs( Element _this, Pickup pickup, bool matchingDimension )
			: base( _this )
		{
			this.Pickup = pickup;
			this.MatchingDimension = matchingDimension;
		}

		public Pickup Pickup;
		public bool MatchingDimension;
	}
}
