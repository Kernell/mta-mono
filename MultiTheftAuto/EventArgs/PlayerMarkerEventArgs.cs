using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerMarkerEventArgs : ElementEventArgs
	{
		public PlayerMarkerEventArgs( Element _this, Marker marker, bool matchingDimension )
			: base( _this )
		{
			this.Marker = marker;
			this.MatchingDimension = matchingDimension;
		}

		public Marker Marker;
		public bool MatchingDimension;
	}
}
