using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class MultiTheftAuto
	{
		#region Constructor

		public MultiTheftAuto()
		{
			Resource.Register<Resource>();
			Element.Register<Element>();
		}

		#endregion
	}
}
