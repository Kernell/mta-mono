using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerLogoutEventArgs : ElementEventArgs
	{
		public PlayerLogoutEventArgs( Element _this, Account previousAccount, Account currentAccount )
			: base( _this )
		{
			this.PreviousAccount	= previousAccount;
			this.CurrentAccount		= currentAccount;
		}

		public Account PreviousAccount;
		public Account CurrentAccount;
	}
}
