using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
    public class VehicleColor
    {
		private Color[] Colors;

		public VehicleColor( Color color1, Color color2, Color color3, Color color4 )
		{
			this.Colors = new Color[ 4 ];

			this.Colors[ 0 ] = color1;
			this.Colors[ 1 ] = color2;
			this.Colors[ 2 ] = color3;
			this.Colors[ 3 ] = color4;
		}

		public Color this[ int key ]
		{
			get
			{
				return this.Colors[ key ];
			}
			set
			{
				this.Colors[ key ] = value;
			}
		}
    }
}
