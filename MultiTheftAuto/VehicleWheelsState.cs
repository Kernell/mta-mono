using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class VehicleWheelsState
    {
		public byte FrontLeft;
		public byte RearLeft;
		public byte FrontRight;
		public byte RearRight;

		public VehicleWheelsState( byte frontLeft, byte rearLeft, byte frontRight, byte rearRight )
		{
			this.FrontLeft		= frontLeft;
			this.RearLeft		= rearLeft;
			this.FrontRight		= frontRight;
			this.RearRight		= rearRight;
		}
    }
}
