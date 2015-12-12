using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto.Utils
{
	/// <summary>
	///     Contains an Identity property.
	/// </summary>
	public interface IIdentifyable
	{
		/// <summary>
		///     Gets the Identity of this instance.
		/// </summary>
		UInt32 userdata
		{
			get;
		}
	}
}
