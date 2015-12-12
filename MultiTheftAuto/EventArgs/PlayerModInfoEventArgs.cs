using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerModInfoEventArgs : ElementEventArgs
	{
		public PlayerModInfoEventArgs( Element _this, string filename, PlayerModInfo [] list )
			: base( _this )
		{
			this.FileName	= filename;
			this.List		= list;
		}

		public PlayerModInfo [] List;

		public string FileName
		{
			private set;
			get;
		}
	}
}
