using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
    public class ServerVersion
    {
		public ulong Number { get; set; }
		public string String { get; set; }
		public string Name { get; set; }
		public string BuildType { get; set; }
		public ulong Netcode { get; set; }
		public string OperatingSystem { get; set; }
		public string BuildTag { get; set; }
		public string Sortable { get; set; }

		public ServerVersion( ulong number, string version, string name, string buildType, ulong netcode, string os, string tag, string sortable )
		{
			this.Number				= number;
			this.String				= version;
			this.Name				= name;
			this.BuildType			= buildType;
			this.Netcode			= netcode;
			this.OperatingSystem	= os;
			this.BuildTag			= tag;
			this.Sortable			= sortable;
		}
    }
}
