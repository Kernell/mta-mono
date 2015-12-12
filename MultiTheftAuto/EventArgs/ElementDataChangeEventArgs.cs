using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ElementDataChangeEventArgs : ElementEventArgs
	{
		public ElementDataChangeEventArgs( Element _this, Player client, string name, dynamic oldValue )
			: base( _this )
		{
			this.Client		= client;
			this.Name		= name;
			this.OldValue	= oldValue;
		}

		public Player Client;
		public string Name;
		public dynamic OldValue;
	}
}
