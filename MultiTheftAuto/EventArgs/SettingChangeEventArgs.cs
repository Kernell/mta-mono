using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class SettingChangeEventArgs : ElementEventArgs
	{
		public SettingChangeEventArgs( Element _this, string setting, string oldValue, string newValue )
			: base( _this )
		{
			this.Setting	= setting;
			this.OldValue	= oldValue;
			this.NewValue	= newValue;
		}

		public string Setting;
		public string OldValue;
		public string NewValue;
	}
}
