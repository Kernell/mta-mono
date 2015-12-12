using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
    public class CameraMatrix
    {
		public Vector3 Position;
		public Vector3 LookAt;
		public float Roll;
		public float FOV;

		public CameraMatrix( Vector3 position )
			: this( position, Vector3.Zero, 0f, 0f )
		{
		}

		public CameraMatrix( Vector3 position, Vector3 lookAt )
			: this( position, lookAt, 0f, 0f )
		{
		}

		public CameraMatrix( Vector3 position, Vector3 lookAt, float roll, float fov )
			: this( position.X, position.Y, position.Z, lookAt.X, lookAt.Y, lookAt.Z, roll, fov )
		{
		}

		public CameraMatrix( float x, float y, float z, float lookAtX, float lookAtY, float lookAtZ, float roll, float fov )
		{
			this.Position.X	= x;
			this.Position.Y	= y;
			this.Position.Z	= z;
			
			this.LookAt.X	= lookAtX;
			this.LookAt.Y	= lookAtY;
			this.LookAt.Z	= lookAtZ;
			
			this.Roll		= roll;
			this.FOV		= fov;
		}
    }
}
