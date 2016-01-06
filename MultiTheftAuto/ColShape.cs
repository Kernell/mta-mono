using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class ColShape : Element
	{
		public ColShape()
		{
		}
	}

	public class ColCircle : ColShape
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern ColCircle( Vector2 position, float radius );
	}

	public class ColCuboid : ColShape
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern ColCuboid( Vector3 position, Vector3 size );
	}

	public class ColSphere : ColShape
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern ColSphere( Vector3 position, float fadius );
	}
	
	public class ColRectangle : ColShape
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern ColRectangle( Vector2 position, Vector2 size );
	}
	
	public class ColPolygon : ColShape
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern ColPolygon( Vector2 pos1, Vector2 pos2, Vector2 pos3, Vector2 pos4, params Vector2[] args );
	}

	public class ColTube : ColShape
	{
		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern ColTube( Vector3 position, float radius, float height );
	}
}
