using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerConnectEventArgs : CancelEventArgs
	{
		public PlayerConnectEventArgs( Element _this, string nick, string ip, string username, string serial, int versionNumber, string versionString )
			: base( _this )
		{
			this.Nick = nick;
			this.IP = ip;
			this.Username = username;
			this.Serial = serial;
			this.VersionNumber = versionNumber;
			this.VersionString = versionString;
		}

		public string Nick;
		public string IP;
		public string Username;
		public string Serial;
		public int VersionNumber;
		public string VersionString;
	}
}
