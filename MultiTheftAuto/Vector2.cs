using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class Vector2
	{
		public float X;
		public float Y;

		public Vector2()
		{
			this.X = 0;
			this.Y = 0;
		}

		public Vector2( float _fX, float _fY )
		{
			this.X = _fX;
			this.Y = _fY;
		}

		public float DotProduct( Vector2 other )
		{
			return this.X * other.X + this.Y * other.Y;
		}

		public float Length()
		{
			return (float)Math.Sqrt( this.X * this.X + this.Y * this.Y );
		}

		public float LengthSquared()
		{
			return ( this.X * this.X ) + ( this.Y * this.Y );
		}

		public void Normalize()
		{
			float fLength = this.Length();

			if( fLength > 0.0f )
			{
				this.X /= fLength;
				this.Y /= fLength;
			}
		}
	};
}
