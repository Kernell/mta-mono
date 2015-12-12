using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ElementColShapeEventArgs : ElementEventArgs
	{
		public ElementColShapeEventArgs( Element _this, ColShape colShape, bool matchingDimension )
			: base( _this )
		{
			this.ColShape			= colShape;
			this.MatchingDimension	= matchingDimension;
		}

		public ColShape ColShape;
		public bool MatchingDimension;
	}
}
