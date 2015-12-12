using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerSpawnEventArgs : ElementEventArgs
	{
		public PlayerSpawnEventArgs( Element _this, float x, float y, float z, float rotation, Team team, int skin, int interior, int dimension )
			: base( _this )
		{
			this.Position	= new Vector3( x, y, z );
			this.Rotation	= rotation;
			this.Team		= team;
			this.SkinID		= skin;
			this.Interior	= interior;
			this.Dimension	= dimension;
		}

		public Vector3 Position;
		public float Rotation;
		public Team Team;
		public int SkinID;
		public int Interior;
		public int Dimension;
	}
}
