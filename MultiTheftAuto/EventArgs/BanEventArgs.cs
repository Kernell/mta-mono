using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class BanEventArgs : ElementEventArgs
	{
		public BanEventArgs( Element _this, Ban ban )
			: base( _this )
		{
			this.Ban = ban;
		}

		public Ban Ban;
	}
}
