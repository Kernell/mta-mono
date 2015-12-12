using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
    public class Vector3
    {
        public static double FLOAT_EPSILON = 0.0001;

        public float X { get; set; }
        public float Y { get; set; }
        public float Z { get; set; }

        public static Vector3 Back
        {
            get
            {
                return new Vector3( 0.0f, -1.0f, 0.0f );
            }
        }

        public static Vector3 Down
        {
            get
            {
                return new Vector3( 0.0f, 0.0f, -1.0f );
            }
        }

        public static Vector3 Forward
        {
            get
            {
                return new Vector3( 0.0f, 1.0f, 0.0f );
            }
        }

        public static Vector3 Left
        {
            get
            {
                return new Vector3( -1.0f, 0.0f, 0.0f );
            }
        }

        public static Vector3 One
        {
            get
            {
                return new Vector3( 1.0f, 1.0f, 1.0f );
            }
        }

        public static Vector3 Right
        {
            get
            {
                return new Vector3( 1.0f, 0.0f, 0.0f );
            }
        }

        public static Vector3 Up
        {
            get
            {
                return new Vector3( 0.0f, 0.0f, 1.0f );
            }
        }

        public static Vector3 Zero
        {
            get
            {
                return new Vector3( 0.0f, 0.0f, 0.0f );
            }
        }

        public float Magnitude
        {
            get
            {
                return this.LengthSquared();
            }
        }

        public float SqrMagnitude
        {
            get
            {
                return this.Length();
            }
        }

        public float Normalized
        {
            get
            {
                float length = this.Length();
			
			    if( length > Vector3.FLOAT_EPSILON )
                {
				    return length;
                }

                return 0.0f;
            }
        }

        public Vector3( float fX, float fY, float fZ )
        {
            this.Set( fX, fY, fZ );
        }

        public void Set( float fX, float fY, float fZ )
        {
		    this.X 	= fX;
		    this.Y 	= fY;
		    this.Z 	= fZ;
        }

        public float Normalize()
        {
		    float fLength = this.Length();
		
		    if( fLength > Vector3.FLOAT_EPSILON )
            {
			    this.X = this.X / fLength;
			    this.Y = this.Y / fLength;
			    this.Z = this.Z / fLength;
			
			    return fLength;
            }
		
		    return 0.0f;
	    }

		public Vector3 GetNormalized()
		{
			if( this.Magnitude == 0.0f )
			{
				throw new DivideByZeroException();
			}
			else
			{
				float inverse = 1.0f / this.Magnitude;
				
				return new Vector3( this.X * inverse, this.Y * inverse, this.Z * inverse );
			}
		}

        public float Length()
        {
		    return (float)Math.Sqrt( (float)this.LengthSquared() );
	    }

        public float LengthSquared()
        {
            return this.X * this.X + this.Y * this.Y + this.Z * this.Z;
        }

        public float DotProduct( Vector3 vector )
        {
            return this.X * vector.X + this.Y * vector.Y + this.Z * vector.Z;
        }

        public Vector3 Cross( Vector3 vector )
        {
            return new Vector3( this.Y * vector.Z - this.Z * vector.Y, this.Z * vector.X - this.X * vector.Z, this.X * vector.Y - this.Y * vector.X );
        }

        public void CrossProduct( Vector3 vector )
        {
            float
                fX = this.X,
                fY = this.Y,
                fZ = this.Z;

            this.X = fY * vector.Z - vector.Y * fZ;
            this.Y = fZ * vector.X - vector.Z * fX;
            this.Z = fX * vector.Y - vector.X * fY;
        }

        public Vector3 GetTriangleNormal( Vector3 vector1, Vector3 vector2 )
        {
            return ( vector1 - this ).Cross( vector2 - this );
        }

        public Vector3 GetRotation( Vector3 vector )
        {
		    float fX	= 0.0f;
		    float fY	= 0.0f;
            float fZ    = ( 360.0f - ( (float)Math.Atan2( vector.X - this.X, vector.Y - this.Y ) * 180.0f / (float)Math.PI ) ) % 360.0f;
		
		    return new Vector3( fX, fY, fZ );
        }

        public Vector3 Rotate( float angle )
        {
            angle = (float)Math.PI * angle / 180.0f;

		    return new Vector3(
                this.X * (float)Math.Cos( angle ) - this.Y * (float)Math.Sin( angle ),
                this.X * (float)Math.Sin( angle ) + this.Y * (float)Math.Cos( angle ), 
			    this.Z
		    );
	    }

        public float Distance( Vector3 vector )
        {
            return ( vector - this ).Length();
	    }

        public float Dot( Vector3 vector )
        {
            return this.X * vector.X + this.Y * vector.Y + this.Z * vector.Z;
        }

        public Vector3 Offset( float distance, float angle )
        {
            angle = (float)Math.PI * angle / 180.0f;

            return new Vector3(
                this.X + ( ( (float)Math.Cos( angle ) ) * distance ),
                this.Y + ( ( (float)Math.Sin( angle ) ) * distance ), 
			    this.Z
		    );
        }

        /// <summary>
        /// Returns the angle in degrees between from and to.
        /// </summary>
        /// <param name="from"></param>
        /// <param name="to"></param>
        /// <returns></returns>

        public float Angle( Vector3 to )
        {
            return ( 360.0f - ( (float)Math.Atan2( to.X - this.X, to.Y - this.Y ) * 180.0f / (float)Math.PI ) ) % 360.0f;
        }

		public static float Angle( Vector3 vector1, Vector3 vector2 )
		{
			return (float)Math.Acos( vector1.GetNormalized().DotProduct( vector2.GetNormalized() ) );
		}

		public Vector3 Pitch( float degree )
		{
			float x = this.X;
			float y = ( this.Y * (float)Math.Cos( degree ) ) - ( this.Z * (float)Math.Sin( degree ) );
			float z = ( this.Y * (float)Math.Sin( degree ) ) + ( this.Z * (float)Math.Cos( degree ) );
			
			return new Vector3( x, y, z );
		}

		public Vector3 Yaw( float degree )
		{
			float x = ( this.Z * (float)Math.Sin( degree ) ) + ( this.X * (float)Math.Cos( degree ) );
			float y = this.Y;
			float z = ( this.Z * (float)Math.Cos( degree ) ) - ( this.X * (float)Math.Sin( degree ) );
			
			return new Vector3( x, y, z );
		}

		public Vector3 Roll( float degree )
		{
			float x = ( this.X * (float)Math.Cos( degree ) ) - ( this.Y * (float)Math.Sin( degree ) );
			float y = ( this.X * (float)Math.Sin( degree ) ) + ( this.Y * (float)Math.Cos( degree ) );
			float z = this.Z;

			return new Vector3( x, y, z );
		}

		public bool IsBackFace( Vector3 lineOfSight )
		{
			return this.DotProduct( lineOfSight ) < 0.0f;
		}
		public bool IsPerpendicular( Vector3 vector )
		{
			return this.DotProduct( vector ) == 0.0f;
		}

		public float MixedProduct( Vector3 v2, Vector3 v3 )
		{
			this.CrossProduct( v2 );

			return this.DotProduct( v3 );
		}

        public override string ToString()
        {
            return String.Format( "({0},{1},{2})", this.X, this.Y, this.Z );
        }

        public bool Equals( Vector3 vector )
        {
            return this.X == vector.X && this.Y == vector.Y && this.Z == vector.Z;
        }

        public override bool Equals( object o )
        {
            return true;
        }

        public override int GetHashCode()
        {
            return 0;
        }

		#region Operators

		public static Vector3 operator +( Vector3 vector1, Vector3 vector2 )
        {
            return new Vector3( vector1.X + vector2.X, vector1.Y + vector2.Y, vector1.Z + vector2.Z );
        }

        public static Vector3 operator +( Vector3 vector, float value )
        {
            return new Vector3( vector.X + value, vector.Y + value, vector.Z + value );
        }

        public static Vector3 operator -( Vector3 vector1, Vector3 vector2 )
        {
            return new Vector3( vector1.X - vector2.X, vector1.Y - vector2.Y, vector1.Z - vector2.Z );
        }

        public static Vector3 operator -( Vector3 vector, float value )
        {
            return new Vector3( vector.X - value, vector.Y - value, vector.Z - value );
        }

        public static Vector3 operator *( Vector3 vector1, Vector3 vector2 )
        {
            return new Vector3( vector1.X * vector2.X, vector1.Y * vector2.Y, vector1.Z * vector2.Z );
        }

        public static Vector3 operator *( Vector3 vector, float value )
        {
            return new Vector3( vector.X * value, vector.Y * value, vector.Z * value );
        }

        public static Vector3 operator /( Vector3 vector1, Vector3 vector2 )
        {
            return new Vector3( vector1.X / vector2.X, vector1.Y / vector2.Y, vector1.Z / vector2.Z );
        }

        public static Vector3 operator /( Vector3 vector, float value )
        {
            return new Vector3( vector.X / value, vector.Y / value, vector.Z / value );
        }

        public static Vector3 operator %( Vector3 vector1, Vector3 vector2 )
        {
            return new Vector3( vector1.X % vector2.X, vector1.Y % vector2.Y, vector1.Z % vector2.Z );
        }

        public static Vector3 operator %( Vector3 vector, float value )
        {
            return new Vector3( vector.X % value, vector.Y % value, vector.Z % value );
        }

        public static bool operator ==( Vector3 vector1, Vector3 vector2 )
        {
            return vector1.Equals( vector2 );
        }

        public static bool operator !=( Vector3 vector1, Vector3 vector2 )
        {
            return !vector1.Equals( vector2 );
		}

		#endregion
	}
}
