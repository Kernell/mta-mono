using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class MarkerEventArgs : ElementEventArgs
	{
		public MarkerEventArgs( Element _this, Element element, bool matchingDimension )
			: base( _this )
		{
			this.Element = element;
			this.MatchingDimension = matchingDimension;
		}

		public Element Element;
		public bool MatchingDimension;
	}
}
