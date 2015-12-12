using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class VehicleEventArgs : ElementEventArgs
	{
		public VehicleEventArgs( Element _this, Vehicle vehicle )
			: base( _this )
		{
			this.Vehicle = vehicle;
		}

		public Vehicle Vehicle;
	}
}
