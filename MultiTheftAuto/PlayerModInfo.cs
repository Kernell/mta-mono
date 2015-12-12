using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public class PlayerModInfo
	{
		/// <summary>
		/// GTA model or texture id
		/// </summary>
		public int ID;

		/// <summary>
		/// GTA name
		/// </summary>
		public string Name;

		/// <summary>
		/// The modified model size (If the item is a DFF)
		/// </summary>
		public Vector3 Size;

		/// <summary>
		/// The unmodified model size (If the item is a DFF)
		/// </summary>
		public Vector3 OriginalSize;
		
		/// <summary>
		/// Length in bytes of the item
		/// </summary>
		public uint Length;

		/// <summary>
		/// md5 of the item bytes
		/// </summary>
		public string MD5;

		/// <summary>
		/// sha256 of the item bytes
		/// </summary>
		public string SHA256;

		/// <summary>
		/// Length in bytes of the item padded to 2048 byte boundary
		/// </summary>
		public string PaddedLength;

		/// <summary>
		/// md5 of the item bytes padded to 2048 byte boundary
		/// </summary>
		public string PaddedMD5;

		/// <summary>
		/// sha256 of the item bytes padded to 2048 byte boundary
		/// </summary>
		public string PaddedSHA256;

		public PlayerModInfo( int id, string name, Vector3 size, Vector3 originalSize, uint length, string md5, string sha256, string paddedLength, string paddedMd5, string paddedSha256 )
		{
			this.ID = id;
			this.Name = name;
			this.Size = size;
			this.OriginalSize = originalSize;
			this.Length = length;
			this.MD5 = md5;
			this.SHA256 = sha256;
			this.PaddedLength = paddedLength;
			this.PaddedMD5 = paddedMd5;
			this.PaddedSHA256 = paddedSha256;
		}
	}
}
