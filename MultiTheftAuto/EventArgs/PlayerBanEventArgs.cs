using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerBanEventArgs : ElementEventArgs
	{
		public PlayerBanEventArgs( Element _this, Ban banPointer, Player responsibleElement )
			: base( _this )
		{
			this.Ban = banPointer;
			this.Responsible = responsibleElement;
		}

		public Ban Ban;
		public Player Responsible;
	}
}
