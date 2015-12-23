using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class ColShape : Element
	{
		public ColShape( UInt32 userdata )
			: base( userdata )
		{

		}
	}

	public class ColCircle : ColShape
	{
		public ColCircle( float x, float y, float radius )
			: base( Native.ColShape.CreateCircle( x, y, radius ) )
		{

		}
	}

	public class ColCuboid : ColShape
	{
		public ColCuboid( float x, float y, float z, float width, float depth, float height )
			 : base( Native.ColShape.CreateCuboid( x, y, z, width, depth, height ) )
		{

		}
	}

	public class ColSphere : ColShape
	{
		public ColSphere( float x, float y, float z, float fadius )
			 : base( Native.ColShape.CreateSphere( x, y, z, fadius ) )
		{

		}
	}
	
	public class ColRectangle : ColShape
	{
		public ColRectangle( float x, float y, float width, float height )
			 : base( Native.ColShape.CreateRectangle( x, y, width, height ) )
		{

		}
	}
	
	public class ColPolygon : ColShape
	{
		public ColPolygon( float x, float y, float x1, float y1, float x2, float y2, float x3, float y3, params float[] args )
			 : base( Native.ColShape.CreatePolygon( x, y, x1, y1, x2, y2, x3, y3, args ) )
		{

		}
	}

	public class ColTube : ColShape
	{
		public ColTube( float x, float y, float z, float radius, float height )
			 : base( Native.ColShape.CreateTube( x, y, z, radius, height ) )
		{

		}
	}
}
