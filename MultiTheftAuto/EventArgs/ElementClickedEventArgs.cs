using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class ElementClickedEventArgs : ElementEventArgs
	{
		public ElementClickedEventArgs( Element _this, string mouseButton, string buttonState, Player whoClicked, float clickPosX, float clickPosY, float clickPosZ )
			: base( _this )
		{
			this.MouseButton	= mouseButton;
			this.ButtonState	= buttonState;
			this.WhoClicked		= whoClicked;
			this.ClickPosition	= new Vector3( clickPosX, clickPosY, clickPosZ );
		}

		public string MouseButton;
		public string ButtonState;
		public Player WhoClicked;
		public Vector3 ClickPosition;
	}
}
