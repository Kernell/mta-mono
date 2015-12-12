using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerEventArgs : ElementEventArgs
	{
		public PlayerEventArgs( Element _this, Player player )
			: base( _this )
		{
			this.Player = player;
		}

		public Player Player;
	}
}
