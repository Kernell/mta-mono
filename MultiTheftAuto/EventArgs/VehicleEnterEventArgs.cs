using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class VehicleEnterEventArgs : ElementEventArgs
	{
		public VehicleEnterEventArgs( Element _this, Player player, int seat, Player jacked )
			: base( _this )
		{
			this.Player = player;
			this.Seat = seat;
			this.Jacked = jacked;
		}

		public Player Player;
		public int Seat;
		public Player Jacked;
	}
}
