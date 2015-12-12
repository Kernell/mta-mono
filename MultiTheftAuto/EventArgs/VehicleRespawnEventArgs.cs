using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class VehicleRespawnEventArgs : ElementEventArgs
	{
		public VehicleRespawnEventArgs( Element _this, bool exploded )
			: base( _this )
		{
			this.Exploded = exploded;
		}

		public bool Exploded;
	}
}
