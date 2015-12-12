using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
    public class HeatHazeSettings
    {
		private byte ucIntensity;			//     0 to 255
		private byte ucRandomShift;			//     0 to 255
		private ushort usSpeedMin;			//     0 to 1000
		private ushort usSpeedMax;			//     0 to 1000
		private short sScanSizeX;			// -1000 to 1000
		private short sScanSizeY;			// -1000 to 1000
		private ushort usRenderSizeX;		//     0 to 1000
		private ushort usRenderSizeY;		//     0 to 1000
		private bool bInsideBuilding;

		public byte Intensity
		{
			get
			{
				return this.ucIntensity;
			}
			set
			{
				this.ucIntensity = value;
			}
		}

		public byte RandomShift
		{
			get
			{
				return this.ucRandomShift;
			}
			set
			{
				this.ucRandomShift = value;
			}
		}

		public ushort SpeedMin
		{
			get
			{
				return this.usSpeedMin;
			}
			set
			{
				this.usSpeedMin = value;
			}
		}

		public ushort SpeedMax
		{
			get
			{
				return this.usSpeedMax;
			}
			set
			{
				this.usSpeedMax = value;
			}
		}

		public short ScanSizeX
		{
			get
			{
				return this.sScanSizeX;
			}
			set
			{
				this.sScanSizeX = value;
			}
		}

		public short ScanSizeY
		{
			get
			{
				return this.sScanSizeY;
			}
			set
			{
				this.sScanSizeY = value;
			}
		}

		public ushort RenderSizeX
		{
			get
			{
				return this.usRenderSizeX;
			}
			set
			{
				this.usRenderSizeX = value;
			}
		}

		public ushort RenderSizeY
		{
			get
			{
				return this.usRenderSizeY;
			}
			set
			{
				this.usRenderSizeY = value;
			}
		}

		public bool InsideBuilding
		{
			get
			{
				return this.bInsideBuilding;
			}
			set
			{
				this.bInsideBuilding = value;
			}
		}

		public HeatHazeSettings()
		{
			this.ucIntensity		= 0;
			this.ucRandomShift		= 0;
			this.usSpeedMin			= 1;
			this.usSpeedMax			= 1;
			this.sScanSizeX			= 1;
			this.sScanSizeY			= 1;
			this.usRenderSizeX		= 1;
			this.usRenderSizeY		= 1;
			this.bInsideBuilding	= false;
		}

		public HeatHazeSettings( HeatHazeSettings heatHazeSettings )
		{
			this.ucIntensity		= heatHazeSettings.ucIntensity;
			this.ucRandomShift		= heatHazeSettings.ucRandomShift;
			this.usSpeedMin			= heatHazeSettings.usSpeedMin;
			this.usSpeedMax			= heatHazeSettings.usSpeedMax;
			this.sScanSizeX			= heatHazeSettings.sScanSizeX;
			this.sScanSizeY			= heatHazeSettings.sScanSizeY;
			this.usRenderSizeX		= heatHazeSettings.usRenderSizeX;
			this.usRenderSizeY		= heatHazeSettings.usRenderSizeY;
			this.bInsideBuilding	= heatHazeSettings.bInsideBuilding;
		}
    }
}
