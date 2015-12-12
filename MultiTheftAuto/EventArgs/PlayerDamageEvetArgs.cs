using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PlayerDamageEvetArgs : ElementEventArgs
	{
		public PlayerDamageEvetArgs( Element _this, Player attacker, int attackerweapon, int bodypart, float loss )
			: base( _this )
		{
			this.Attacker		= attacker;
			this.AttackerWeapon = attackerweapon;
			this.Bodypart		= bodypart;
			this.Loss			= loss;
		}

		public Player Attacker;
		public int AttackerWeapon;
		public int Bodypart;
		public float Loss;
	}
}
