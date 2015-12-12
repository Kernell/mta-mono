using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ResourceEventArgs : CancelEventArgs
	{
		public ResourceEventArgs( Element _this, Resource resource )
			: base( _this )
		{
			this.Resource = resource;
		}

		public Resource Resource;
	}
}
