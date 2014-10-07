using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.CompilerServices;
using System.Diagnostics;

namespace MonoTest
{
    public class Resource
    {
		public Resource()
		{
			Vector3 vector = new Vector3( 192f, 168f, 0f );

			Console.WriteLine( vector );

			vector.Test();
		}
    }

	public class Vector3
	{
		public float X
		{
			get;
			set;
		}
		public float Y
		{
			get;
			set;
		}
		public float Z
		{
			get;
			set;
		}
		public string TestProperty
		{
			get;
			set;
		}

		public Vector3( float X, float Y, float Z )
		{
			this.X = X;
			this.Y = Y;
			this.Z = Z;

			this.TestProperty = "Tested!";
		}

		public override string ToString()
		{
			return String.Format( "({0},{1},{2})", this.X, this.Y, this.Z );
		}

		public void Test()
		{
			Vector3.Test( this );
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern void Test( Vector3 vector );
	}
}
