using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class AccountDataChangeEventArgs : ElementEventArgs
	{
		public AccountDataChangeEventArgs( Element _this, Account account, string key, dynamic value )
			: base( _this )
		{
			this.Account = account;
			this.Key = key;
			this.Value = value;
		}

		public Account Account;
		public string Key;
		public dynamic Value;
	}
}
