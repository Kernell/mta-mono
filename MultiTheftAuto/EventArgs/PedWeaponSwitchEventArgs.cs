using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.EventArgs
{
	public class PedWeaponSwitchEventArgs : ElementEventArgs
	{
		public PedWeaponSwitchEventArgs( Element _this, int previousWeaponID, int currentWeaponID )
			: base( _this )
		{
			this.PreviousWeaponID	= previousWeaponID;
			this.CurrentWeaponID	= currentWeaponID;
		}

		public int PreviousWeaponID;
		public int CurrentWeaponID;
	}
}
