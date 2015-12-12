using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerVehicleEnterEventArgs : ElementEventArgs
	{
		public PlayerVehicleEnterEventArgs( Element _this, Vehicle vehicle, int seat, Player jacker )
			: base( _this )
		{
			this.Vehicle	= vehicle;
			this.Seat		= seat;
			this.Jacker		= jacker;
		}

		public Vehicle Vehicle;
		public int Seat;
		public Player Jacker;
	}
}
