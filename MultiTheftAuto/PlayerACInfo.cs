using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
    public class PlayerACInfo
    {
		public string DetectedAC;
		public string d3d9MD5;
		public string d3d9SHA256;
		public uint d3d9Size;

		public PlayerACInfo( string detectedAC, uint D3D9Size, string D3D9MD5, string D3D9SHA256 )
		{
			this.DetectedAC		= detectedAC;
			this.d3d9MD5		= D3D9MD5;
			this.d3d9SHA256		= D3D9SHA256;
			this.d3d9Size		= D3D9Size;
		}
    }
}
