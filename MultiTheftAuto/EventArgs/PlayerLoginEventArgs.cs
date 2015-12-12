using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerLoginEventArgs : ElementEventArgs
	{
		public PlayerLoginEventArgs( Element _this, Account previousAccount, Account currentAccount, bool autoLogin )
			: base( _this )
		{
			this.PreviousAccount	= previousAccount;
			this.CurrentAccount		= currentAccount;
			this.AutoLogin			= autoLogin;
		}

		public Account PreviousAccount;
		public Account CurrentAccount;
		public bool AutoLogin;
	}
}
