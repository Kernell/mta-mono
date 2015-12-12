using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerQuitEventArgs : ElementEventArgs
	{
		public PlayerQuitEventArgs( Element _this, string type, string reason, Player responsePlayer )
			: base( _this )
		{
			this.Type = type;
			this.Reason = reason;
			this.ResponsePlayer = responsePlayer;
		}

		public string Type
		{
			private set;
			get;
		}

		public string Reason
		{
			private set;
			get;
		}

		public Player ResponsePlayer
		{
			private set;
			get;
		}
	}
}
