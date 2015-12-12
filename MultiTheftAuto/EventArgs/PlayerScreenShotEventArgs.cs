using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerScreenShotEventArgs : ElementEventArgs
	{
		public PlayerScreenShotEventArgs( Element _this, Resource resource, string status, string imageData, int timestamp, string tag )
			: base( _this )
		{
			this.Resource	= resource;
			this.Status		= status;
			this.ImageData	= imageData;
			this.Timestamp	= timestamp;
			this.Tag		= tag;
		}

		public Resource Resource;
		public string Status;
		public string ImageData;
		public int Timestamp;
		public string Tag;
	}
}
