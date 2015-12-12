using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class VehicleDamageEventArgs : ElementEventArgs
	{
		public VehicleDamageEventArgs( Element _this, float loss )
			: base( _this )
		{
			this.Loss = loss;
		}

		public float Loss;
	}
}
