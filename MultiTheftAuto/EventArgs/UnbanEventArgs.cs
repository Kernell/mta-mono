using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class UnbanEventArgs : CancelEventArgs
	{
		public UnbanEventArgs( Element _this, Ban ban, Player responsibleElement )
			: base( _this )
		{
			this.Ban = ban;
			this.ResponsibleElement = responsibleElement;
		}

		public Ban Ban;
		public Player ResponsibleElement;
	}
}
