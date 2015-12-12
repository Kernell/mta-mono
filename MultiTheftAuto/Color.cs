using System;

namespace MultiTheftAuto
{
	public class Color
	{
		public uint R = 255;
		public uint G = 255;
		public uint B = 255;
		public uint A = 255;

		public uint Red
		{
			get
			{
				return this.R;
			}
			set
			{
				this.R = value;
			}
		}

		public uint Green
		{
			get
			{
				return this.G;
			}
			set
			{
				this.G = value;
			}
		}

		public uint Blue
		{
			get
			{
				return this.B;
			}
			set
			{
				this.B = value;
			}
		}

		public uint Alpha
		{
			get
			{
				return this.A;
			}
			set
			{
				this.A = value;
			}
		}

		public Color( uint red, uint green, uint blue, uint alpha )
		{
			this.R = red % 256;
			this.G = green % 256;
			this.B = blue % 256;
			this.A = alpha % 256;
		}

		public Color( uint red, uint green, uint blue )
		{
			this.R = red % 256;
			this.G = green % 256;
			this.B = blue % 256;
		}

		public Color( uint color )
		{
			this.A = color >> 24 & 255;
			this.R = color >> 16 & 255;
			this.G = color >> 8 & 255;
			this.B = color & 255;
		}

		public uint ToARGB()
		{
			return ( this.A << 24 ) | ( this.R << 16 ) | ( this.G << 8 ) | this.B;
		}

		public uint ToRGBA()
		{
			return ( this.R << 24 ) | ( this.G << 16 ) | ( this.B << 8 ) | this.A;
		}
	}
}
