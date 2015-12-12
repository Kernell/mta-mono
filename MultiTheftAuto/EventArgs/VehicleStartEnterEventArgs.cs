using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class VehicleStartEnterEventArgs : ElementEventArgs
	{
		public VehicleStartEnterEventArgs( Element _this, Player player, int seat, Player jacked, int door )
			: base( _this )
		{
			this.Player = player;
			this.Seat	= seat;
			this.Jacked = jacked;
			this.Door	= door;
		}

		public Player Player;
		public int Seat;
		public Player Jacked;
		public int Door;
	}
}
