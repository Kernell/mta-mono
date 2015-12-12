using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerClickEventArgs : ElementEventArgs
	{
		public PlayerClickEventArgs( Element _this, string mouseButton, string buttonState, Element clickedElement, float worldX, float worldY, float worldZ, float screenX, float screenY )
			: base( _this )
		{
			this.MouseButton	= mouseButton;
			this.ButtonState	= buttonState;
			this.ClickedElement = clickedElement;
			this.WorldPosition	= new Vector3( worldX, worldY, worldZ );
			this.ScreenPosition = new Vector2( screenX, screenY );
		}

		public string MouseButton;
		public string ButtonState;
		public Element ClickedElement;
		public Vector3 WorldPosition;
		public Vector2 ScreenPosition;
	}
}
