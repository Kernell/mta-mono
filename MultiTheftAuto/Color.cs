using System;

namespace MultiTheftAuto
{
	internal enum KnownColor
	{
		ActiveBorder = 1,
		ActiveCaption = 2,
		ActiveCaptionText = 3,
		AppWorkspace = 4,
		Control = 5,
		ControlDark = 6,
		ControlDarkDark = 7,
		ControlLight = 8,
		ControlLightLight = 9,
		ControlText = 10,
		Desktop = 11,
		GrayText = 12,
		Highlight = 13,
		HighlightText = 14,
		HotTrack = 15,
		InactiveBorder = 16,
		InactiveCaption = 17,
		InactiveCaptionText = 18,
		Info = 19,
		InfoText = 20,
		Menu = 21,
		MenuText = 22,
		ScrollBar = 23,
		Window = 24,
		WindowFrame = 25,
		WindowText = 26,
		Transparent = 27,
		AliceBlue = 28,
		AntiqueWhite = 29,
		Aqua = 30,
		Aquamarine = 31,
		Azure = 32,
		Beige = 33,
		Bisque = 34,
		Black = 35,
		BlanchedAlmond = 36,
		Blue = 37,
		BlueViolet = 38,
		Brown = 39,
		BurlyWood = 40,
		CadetBlue = 41,
		Chartreuse = 42,
		Chocolate = 43,
		Coral = 44,
		CornflowerBlue = 45,
		Cornsilk = 46,
		Crimson = 47,
		Cyan = 48,
		DarkBlue = 49,
		DarkCyan = 50,
		DarkGoldenrod = 51,
		DarkGray = 52,
		DarkGreen = 53,
		DarkKhaki = 54,
		DarkMagenta = 55,
		DarkOliveGreen = 56,
		DarkOrange = 57,
		DarkOrchid = 58,
		DarkRed = 59,
		DarkSalmon = 60,
		DarkSeaGreen = 61,
		DarkSlateBlue = 62,
		DarkSlateGray = 63,
		DarkTurquoise = 64,
		DarkViolet = 65,
		DeepPink = 66,
		DeepSkyBlue = 67,
		DimGray = 68,
		DodgerBlue = 69,
		Firebrick = 70,
		FloralWhite = 71,
		ForestGreen = 72,
		Fuchsia = 73,
		Gainsboro = 74,
		GhostWhite = 75,
		Gold = 76,
		Goldenrod = 77,
		Gray = 78,
		Green = 79,
		GreenYellow = 80,
		Honeydew = 81,
		HotPink = 82,
		IndianRed = 83,
		Indigo = 84,
		Ivory = 85,
		Khaki = 86,
		Lavender = 87,
		LavenderBlush = 88,
		LawnGreen = 89,
		LemonChiffon = 90,
		LightBlue = 91,
		LightCoral = 92,
		LightCyan = 93,
		LightGoldenrodYellow = 94,
		LightGray = 95,
		LightGreen = 96,
		LightPink = 97,
		LightSalmon = 98,
		LightSeaGreen = 99,
		LightSkyBlue = 100,
		LightSlateGray = 101,
		LightSteelBlue = 102,
		LightYellow = 103,
		Lime = 104,
		LimeGreen = 105,
		Linen = 106,
		Magenta = 107,
		Maroon = 108,
		MediumAquamarine = 109,
		MediumBlue = 110,
		MediumOrchid = 111,
		MediumPurple = 112,
		MediumSeaGreen = 113,
		MediumSlateBlue = 114,
		MediumSpringGreen = 115,
		MediumTurquoise = 116,
		MediumVioletRed = 117,
		MidnightBlue = 118,
		MintCream = 119,
		MistyRose = 120,
		Moccasin = 121,
		NavajoWhite = 122,
		Navy = 123,
		OldLace = 124,
		Olive = 125,
		OliveDrab = 126,
		Orange = 127,
		OrangeRed = 128,
		Orchid = 129,
		PaleGoldenrod = 130,
		PaleGreen = 131,
		PaleTurquoise = 132,
		PaleVioletRed = 133,
		PapayaWhip = 134,
		PeachPuff = 135,
		Peru = 136,
		Pink = 137,
		Plum = 138,
		PowderBlue = 139,
		Purple = 140,
		Red = 141,
		RosyBrown = 142,
		RoyalBlue = 143,
		SaddleBrown = 144,
		Salmon = 145,
		SandyBrown = 146,
		SeaGreen = 147,
		SeaShell = 148,
		Sienna = 149,
		Silver = 150,
		SkyBlue = 151,
		SlateBlue = 152,
		SlateGray = 153,
		Snow = 154,
		SpringGreen = 155,
		SteelBlue = 156,
		Tan = 157,
		Teal = 158,
		Thistle = 159,
		Tomato = 160,
		Turquoise = 161,
		Violet = 162,
		Wheat = 163,
		White = 164,
		WhiteSmoke = 165,
		Yellow = 166,
		YellowGreen = 167,
	}

	[Serializable]
	public class Color
	{
		static internal uint[] ArgbValues = new uint[]
		{
			0x00000000,	/* 000 - Empty */
			0xFFD4D0C8,	/* 001 - ActiveBorder */
			0xFF0054E3,	/* 002 - ActiveCaption */
			0xFFFFFFFF,	/* 003 - ActiveCaptionText */
			0xFF808080,	/* 004 - AppWorkspace */
			0xFFECE9D8,	/* 005 - Control */
			0xFFACA899,	/* 006 - ControlDark */
			0xFF716F64,	/* 007 - ControlDarkDark */
			0xFFF1EFE2,	/* 008 - ControlLight */
			0xFFFFFFFF,	/* 009 - ControlLightLight */
			0xFF000000,	/* 010 - ControlText */
			0xFF004E98,	/* 011 - Desktop */
			0xFFACA899,	/* 012 - GrayText */
			0xFF316AC5,	/* 013 - Highlight */
			0xFFFFFFFF,	/* 014 - HighlightText */
			0xFF000080,	/* 015 - HotTrack */
			0xFFD4D0C8,	/* 016 - InactiveBorder */
			0xFF7A96DF,	/* 017 - InactiveCaption */
			0xFFD8E4F8,	/* 018 - InactiveCaptionText */
			0xFFFFFFE1,	/* 019 - Info */
			0xFF000000,	/* 020 - InfoText */
			0xFFFFFFFF,	/* 021 - Menu */
			0xFF000000,	/* 022 - MenuText */
			0xFFD4D0C8,	/* 023 - ScrollBar */
			0xFFFFFFFF,	/* 024 - Window */
			0xFF000000,	/* 025 - WindowFrame */
			0xFF000000,	/* 026 - WindowText */
			0x00FFFFFF,	/* 027 - Transparent */
			0xFFF0F8FF,	/* 028 - AliceBlue */
			0xFFFAEBD7,	/* 029 - AntiqueWhite */
			0xFF00FFFF,	/* 030 - Aqua */
			0xFF7FFFD4,	/* 031 - Aquamarine */
			0xFFF0FFFF,	/* 032 - Azure */
			0xFFF5F5DC,	/* 033 - Beige */
			0xFFFFE4C4,	/* 034 - Bisque */
			0xFF000000,	/* 035 - Black */
			0xFFFFEBCD,	/* 036 - BlanchedAlmond */
			0xFF0000FF,	/* 037 - Blue */
			0xFF8A2BE2,	/* 038 - BlueViolet */
			0xFFA52A2A,	/* 039 - Brown */
			0xFFDEB887,	/* 040 - BurlyWood */
			0xFF5F9EA0,	/* 041 - CadetBlue */
			0xFF7FFF00,	/* 042 - Chartreuse */
			0xFFD2691E,	/* 043 - Chocolate */
			0xFFFF7F50,	/* 044 - Coral */
			0xFF6495ED,	/* 045 - CornflowerBlue */
			0xFFFFF8DC,	/* 046 - Cornsilk */
			0xFFDC143C,	/* 047 - Crimson */
			0xFF00FFFF,	/* 048 - Cyan */
			0xFF00008B,	/* 049 - DarkBlue */
			0xFF008B8B,	/* 050 - DarkCyan */
			0xFFB8860B,	/* 051 - DarkGoldenrod */
			0xFFA9A9A9,	/* 052 - DarkGray */
			0xFF006400,	/* 053 - DarkGreen */
			0xFFBDB76B,	/* 054 - DarkKhaki */
			0xFF8B008B,	/* 055 - DarkMagenta */
			0xFF556B2F,	/* 056 - DarkOliveGreen */
			0xFFFF8C00,	/* 057 - DarkOrange */
			0xFF9932CC,	/* 058 - DarkOrchid */
			0xFF8B0000,	/* 059 - DarkRed */
			0xFFE9967A,	/* 060 - DarkSalmon */
			0xFF8FBC8B,	/* 061 - DarkSeaGreen */
			0xFF483D8B,	/* 062 - DarkSlateBlue */
			0xFF2F4F4F,	/* 063 - DarkSlateGray */
			0xFF00CED1,	/* 064 - DarkTurquoise */
			0xFF9400D3,	/* 065 - DarkViolet */
			0xFFFF1493,	/* 066 - DeepPink */
			0xFF00BFFF,	/* 067 - DeepSkyBlue */
			0xFF696969,	/* 068 - DimGray */
			0xFF1E90FF,	/* 069 - DodgerBlue */
			0xFFB22222,	/* 070 - Firebrick */
			0xFFFFFAF0,	/* 071 - FloralWhite */
			0xFF228B22,	/* 072 - ForestGreen */
			0xFFFF00FF,	/* 073 - Fuchsia */
			0xFFDCDCDC,	/* 074 - Gainsboro */
			0xFFF8F8FF,	/* 075 - GhostWhite */
			0xFFFFD700,	/* 076 - Gold */
			0xFFDAA520,	/* 077 - Goldenrod */
			0xFF808080,	/* 078 - Gray */
			0xFF008000,	/* 079 - Green */
			0xFFADFF2F,	/* 080 - GreenYellow */
			0xFFF0FFF0,	/* 081 - Honeydew */
			0xFFFF69B4,	/* 082 - HotPink */
			0xFFCD5C5C,	/* 083 - IndianRed */
			0xFF4B0082,	/* 084 - Indigo */
			0xFFFFFFF0,	/* 085 - Ivory */
			0xFFF0E68C,	/* 086 - Khaki */
			0xFFE6E6FA,	/* 087 - Lavender */
			0xFFFFF0F5,	/* 088 - LavenderBlush */
			0xFF7CFC00,	/* 089 - LawnGreen */
			0xFFFFFACD,	/* 090 - LemonChiffon */
			0xFFADD8E6,	/* 091 - LightBlue */
			0xFFF08080,	/* 092 - LightCoral */
			0xFFE0FFFF,	/* 093 - LightCyan */
			0xFFFAFAD2,	/* 094 - LightGoldenrodYellow */
			0xFFD3D3D3,	/* 095 - LightGray */
			0xFF90EE90,	/* 096 - LightGreen */
			0xFFFFB6C1,	/* 097 - LightPink */
			0xFFFFA07A,	/* 098 - LightSalmon */
			0xFF20B2AA,	/* 099 - LightSeaGreen */
			0xFF87CEFA,	/* 100 - LightSkyBlue */
			0xFF778899,	/* 101 - LightSlateGray */
			0xFFB0C4DE,	/* 102 - LightSteelBlue */
			0xFFFFFFE0,	/* 103 - LightYellow */
			0xFF00FF00,	/* 104 - Lime */
			0xFF32CD32,	/* 105 - LimeGreen */
			0xFFFAF0E6,	/* 106 - Linen */
			0xFFFF00FF,	/* 107 - Magenta */
			0xFF800000,	/* 108 - Maroon */
			0xFF66CDAA,	/* 109 - MediumAquamarine */
			0xFF0000CD,	/* 110 - MediumBlue */
			0xFFBA55D3,	/* 111 - MediumOrchid */
			0xFF9370DB,	/* 112 - MediumPurple */
			0xFF3CB371,	/* 113 - MediumSeaGreen */
			0xFF7B68EE,	/* 114 - MediumSlateBlue */
			0xFF00FA9A,	/* 115 - MediumSpringGreen */
			0xFF48D1CC,	/* 116 - MediumTurquoise */
			0xFFC71585,	/* 117 - MediumVioletRed */
			0xFF191970,	/* 118 - MidnightBlue */
			0xFFF5FFFA,	/* 119 - MintCream */
			0xFFFFE4E1,	/* 120 - MistyRose */
			0xFFFFE4B5,	/* 121 - Moccasin */
			0xFFFFDEAD,	/* 122 - NavajoWhite */
			0xFF000080,	/* 123 - Navy */
			0xFFFDF5E6,	/* 124 - OldLace */
			0xFF808000,	/* 125 - Olive */
			0xFF6B8E23,	/* 126 - OliveDrab */
			0xFFFFA500,	/* 127 - Orange */
			0xFFFF4500,	/* 128 - OrangeRed */
			0xFFDA70D6,	/* 129 - Orchid */
			0xFFEEE8AA,	/* 130 - PaleGoldenrod */
			0xFF98FB98,	/* 131 - PaleGreen */
			0xFFAFEEEE,	/* 132 - PaleTurquoise */
			0xFFDB7093,	/* 133 - PaleVioletRed */
			0xFFFFEFD5,	/* 134 - PapayaWhip */
			0xFFFFDAB9,	/* 135 - PeachPuff */
			0xFFCD853F,	/* 136 - Peru */
			0xFFFFC0CB,	/* 137 - Pink */
			0xFFDDA0DD,	/* 138 - Plum */
			0xFFB0E0E6,	/* 139 - PowderBlue */
			0xFF800080,	/* 140 - Purple */
			0xFFFF0000,	/* 141 - Red */
			0xFFBC8F8F,	/* 142 - RosyBrown */
			0xFF4169E1,	/* 143 - RoyalBlue */
			0xFF8B4513,	/* 144 - SaddleBrown */
			0xFFFA8072,	/* 145 - Salmon */
			0xFFF4A460,	/* 146 - SandyBrown */
			0xFF2E8B57,	/* 147 - SeaGreen */
			0xFFFFF5EE,	/* 148 - SeaShell */
			0xFFA0522D,	/* 149 - Sienna */
			0xFFC0C0C0,	/* 150 - Silver */
			0xFF87CEEB,	/* 151 - SkyBlue */
			0xFF6A5ACD,	/* 152 - SlateBlue */
			0xFF708090,	/* 153 - SlateGray */
			0xFFFFFAFA,	/* 154 - Snow */
			0xFF00FF7F,	/* 155 - SpringGreen */
			0xFF4682B4,	/* 156 - SteelBlue */
			0xFFD2B48C,	/* 157 - Tan */
			0xFF008080,	/* 158 - Teal */
			0xFFD8BFD8,	/* 159 - Thistle */
			0xFFFF6347,	/* 160 - Tomato */
			0xFF40E0D0,	/* 161 - Turquoise */
			0xFFEE82EE,	/* 162 - Violet */
			0xFFF5DEB3,	/* 163 - Wheat */
			0xFFFFFFFF,	/* 164 - White */
			0xFFF5F5F5,	/* 165 - WhiteSmoke */
			0xFFFFFF00,	/* 166 - Yellow */
			0xFF9ACD32,	/* 167 - YellowGreen */
		};

		internal string name;

		public uint R = 255;
		public uint G = 255;
		public uint B = 255;
		public uint A = 255;

		public uint Alpha
		{
			get
			{
				return this.A;
			}
			set
			{
				this.A = value;
			}
		}

		public string Name
		{
			get
			{
				if( name == null )
				{
					return String.Format( "{0:x}", this.ToARGB() );
				}

				return name;
			}
		}

		public Color( uint red, uint green, uint blue, uint alpha )
		{
			this.R = red % 256;
			this.G = green % 256;
			this.B = blue % 256;
			this.A = alpha % 256;
		}

		public Color( uint red, uint green, uint blue )
		{
			this.R = red % 256;
			this.G = green % 256;
			this.B = blue % 256;
		}

		public Color( long color, string name )
			: this( color )
		{
			this.name = name;
		}

		public Color( long color )
		{
			this.A = (uint)color >> 24 & 255;
			this.R = (uint)color >> 16 & 255;
			this.G = (uint)color >> 8 & 255;
			this.B = (uint)color & 255;
		}

		public uint ToARGB()
		{
			return ( this.A << 24 ) | ( this.R << 16 ) | ( this.G << 8 ) | this.B;
		}

		public uint ToRGBA()
		{
			return ( this.R << 24 ) | ( this.G << 16 ) | ( this.B << 8 ) | this.A;
		}

		public float GetBrightness()
		{
			byte minval = (byte)Math.Min( R, Math.Min( G, B ) );
			byte maxval = (byte)Math.Max( R, Math.Max( G, B ) );

			return (float)( maxval + minval ) / 510;
		}

		public float GetSaturation()
		{
			byte minval = (byte)Math.Min( this.R, Math.Min( this.G, this.B ) );
			byte maxval = (byte)Math.Max( this.R, Math.Max( this.G, this.B ) );

			if( maxval == minval )
			{
				return 0.0f;
			}

			int sum = maxval + minval;

			if( sum > 255 )
			{
				sum = 510 - sum;
			}

			return (float)( maxval - minval ) / sum;
		}

		public float GetHue()
		{
			uint r = this.R;
			uint g = this.G;
			uint b = this.B;
			
			byte minval = (byte)Math.Min( r, Math.Min( g, b ) );
			byte maxval = (byte)Math.Max( r, Math.Max( g, b ) );

			if( maxval == minval )
			{
				return 0.0f;
			}

			float diff = (float)( maxval - minval );

			float rnorm = ( maxval - r ) / diff;
			float gnorm = ( maxval - g ) / diff;
			float bnorm = ( maxval - b ) / diff;

			float hue = 0.0f;

			if( r == maxval )
			{
				hue = 60.0f * ( 6.0f + bnorm - gnorm );
			}

			if( g == maxval )
			{
				hue = 60.0f * ( 2.0f + rnorm - bnorm );
			}

			if( b == maxval )
			{
				hue = 60.0f * ( 4.0f + gnorm - rnorm );
			}

			if( hue > 360.0f )
			{
				hue = hue - 360.0f;
			}

			return hue;
		}

		public override string ToString()
		{
			if( this.name != null )
			{
				return "Color [" + this.name + "]";
			}

			return String.Format( "Color [A={0}, R={1}, G={2}, B={3}]", this.A, this.R, this.G, this.B );
		}

		internal static Color FromKnownColor( KnownColor kc )
		{
			return new Color( Color.ArgbValues[ (short)kc ], kc.ToString() );
		}

		static public Color Transparent
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Transparent );
			}
		}

		static public Color AliceBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.AliceBlue );
			}
		}

		static public Color AntiqueWhite
		{
			get
			{
				return Color.FromKnownColor( KnownColor.AntiqueWhite );
			}
		}

		static public Color Aqua
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Aqua );
			}
		}

		static public Color Aquamarine
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Aquamarine );
			}
		}

		static public Color Azure
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Azure );
			}
		}

		static public Color Beige
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Beige );
			}
		}

		static public Color Bisque
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Bisque );
			}
		}

		static public Color Black
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Black );
			}
		}

		static public Color BlanchedAlmond
		{
			get
			{
				return Color.FromKnownColor( KnownColor.BlanchedAlmond );
			}
		}

		static public Color Blue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Blue );
			}
		}

		static public Color BlueViolet
		{
			get
			{
				return Color.FromKnownColor( KnownColor.BlueViolet );
			}
		}

		static public Color Brown
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Brown );
			}
		}

		static public Color BurlyWood
		{
			get
			{
				return Color.FromKnownColor( KnownColor.BurlyWood );
			}
		}

		static public Color CadetBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.CadetBlue );
			}
		}

		static public Color Chartreuse
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Chartreuse );
			}
		}

		static public Color Chocolate
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Chocolate );
			}
		}

		static public Color Coral
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Coral );
			}
		}

		static public Color CornflowerBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.CornflowerBlue );
			}
		}

		static public Color Cornsilk
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Cornsilk );
			}
		}

		static public Color Crimson
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Crimson );
			}
		}

		static public Color Cyan
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Cyan );
			}
		}

		static public Color DarkBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkBlue );
			}
		}

		static public Color DarkCyan
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkCyan );
			}
		}

		static public Color DarkGoldenrod
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkGoldenrod );
			}
		}

		static public Color DarkGray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkGray );
			}
		}

		static public Color DarkGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkGreen );
			}
		}

		static public Color DarkKhaki
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkKhaki );
			}
		}

		static public Color DarkMagenta
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkMagenta );
			}
		}

		static public Color DarkOliveGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkOliveGreen );
			}
		}

		static public Color DarkOrange
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkOrange );
			}
		}

		static public Color DarkOrchid
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkOrchid );
			}
		}

		static public Color DarkRed
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkRed );
			}
		}

		static public Color DarkSalmon
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkSalmon );
			}
		}

		static public Color DarkSeaGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkSeaGreen );
			}
		}

		static public Color DarkSlateBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkSlateBlue );
			}
		}

		static public Color DarkSlateGray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkSlateGray );
			}
		}

		static public Color DarkTurquoise
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkTurquoise );
			}
		}

		static public Color DarkViolet
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DarkViolet );
			}
		}

		static public Color DeepPink
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DeepPink );
			}
		}

		static public Color DeepSkyBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DeepSkyBlue );
			}
		}

		static public Color DimGray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DimGray );
			}
		}

		static public Color DodgerBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.DodgerBlue );
			}
		}

		static public Color Firebrick
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Firebrick );
			}
		}

		static public Color FloralWhite
		{
			get
			{
				return Color.FromKnownColor( KnownColor.FloralWhite );
			}
		}

		static public Color ForestGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.ForestGreen );
			}
		}

		static public Color Fuchsia
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Fuchsia );
			}
		}

		static public Color Gainsboro
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Gainsboro );
			}
		}

		static public Color GhostWhite
		{
			get
			{
				return Color.FromKnownColor( KnownColor.GhostWhite );
			}
		}

		static public Color Gold
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Gold );
			}
		}

		static public Color Goldenrod
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Goldenrod );
			}
		}

		static public Color Gray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Gray );
			}
		}

		static public Color Green
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Green );
			}
		}

		static public Color GreenYellow
		{
			get
			{
				return Color.FromKnownColor( KnownColor.GreenYellow );
			}
		}

		static public Color Honeydew
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Honeydew );
			}
		}

		static public Color HotPink
		{
			get
			{
				return Color.FromKnownColor( KnownColor.HotPink );
			}
		}

		static public Color IndianRed
		{
			get
			{
				return Color.FromKnownColor( KnownColor.IndianRed );
			}
		}

		static public Color Indigo
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Indigo );
			}
		}

		static public Color Ivory
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Ivory );
			}
		}

		static public Color Khaki
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Khaki );
			}
		}

		static public Color Lavender
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Lavender );
			}
		}

		static public Color LavenderBlush
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LavenderBlush );
			}
		}

		static public Color LawnGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LawnGreen );
			}
		}

		static public Color LemonChiffon
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LemonChiffon );
			}
		}

		static public Color LightBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightBlue );
			}
		}

		static public Color LightCoral
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightCoral );
			}
		}

		static public Color LightCyan
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightCyan );
			}
		}

		static public Color LightGoldenrodYellow
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightGoldenrodYellow );
			}
		}

		static public Color LightGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightGreen );
			}
		}

		static public Color LightGray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightGray );
			}
		}

		static public Color LightPink
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightPink );
			}
		}

		static public Color LightSalmon
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightSalmon );
			}
		}

		static public Color LightSeaGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightSeaGreen );
			}
		}

		static public Color LightSkyBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightSkyBlue );
			}
		}

		static public Color LightSlateGray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightSlateGray );
			}
		}

		static public Color LightSteelBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightSteelBlue );
			}
		}

		static public Color LightYellow
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LightYellow );
			}
		}

		static public Color Lime
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Lime );
			}
		}

		static public Color LimeGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.LimeGreen );
			}
		}

		static public Color Linen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Linen );
			}
		}

		static public Color Magenta
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Magenta );
			}
		}

		static public Color Maroon
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Maroon );
			}
		}

		static public Color MediumAquamarine
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumAquamarine );
			}
		}

		static public Color MediumBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumBlue );
			}
		}

		static public Color MediumOrchid
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumOrchid );
			}
		}

		static public Color MediumPurple
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumPurple );
			}
		}

		static public Color MediumSeaGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumSeaGreen );
			}
		}

		static public Color MediumSlateBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumSlateBlue );
			}
		}

		static public Color MediumSpringGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumSpringGreen );
			}
		}

		static public Color MediumTurquoise
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumTurquoise );
			}
		}

		static public Color MediumVioletRed
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MediumVioletRed );
			}
		}

		static public Color MidnightBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MidnightBlue );
			}
		}

		static public Color MintCream
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MintCream );
			}
		}

		static public Color MistyRose
		{
			get
			{
				return Color.FromKnownColor( KnownColor.MistyRose );
			}
		}

		static public Color Moccasin
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Moccasin );
			}
		}

		static public Color NavajoWhite
		{
			get
			{
				return Color.FromKnownColor( KnownColor.NavajoWhite );
			}
		}

		static public Color Navy
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Navy );
			}
		}

		static public Color OldLace
		{
			get
			{
				return Color.FromKnownColor( KnownColor.OldLace );
			}
		}

		static public Color Olive
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Olive );
			}
		}

		static public Color OliveDrab
		{
			get
			{
				return Color.FromKnownColor( KnownColor.OliveDrab );
			}
		}

		static public Color Orange
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Orange );
			}
		}

		static public Color OrangeRed
		{
			get
			{
				return Color.FromKnownColor( KnownColor.OrangeRed );
			}
		}

		static public Color Orchid
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Orchid );
			}
		}

		static public Color PaleGoldenrod
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PaleGoldenrod );
			}
		}

		static public Color PaleGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PaleGreen );
			}
		}

		static public Color PaleTurquoise
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PaleTurquoise );
			}
		}

		static public Color PaleVioletRed
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PaleVioletRed );
			}
		}

		static public Color PapayaWhip
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PapayaWhip );
			}
		}

		static public Color PeachPuff
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PeachPuff );
			}
		}

		static public Color Peru
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Peru );
			}
		}

		static public Color Pink
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Pink );
			}
		}

		static public Color Plum
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Plum );
			}
		}

		static public Color PowderBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.PowderBlue );
			}
		}

		static public Color Purple
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Purple );
			}
		}

		static public Color Red
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Red );
			}
		}

		static public Color RosyBrown
		{
			get
			{
				return Color.FromKnownColor( KnownColor.RosyBrown );
			}
		}

		static public Color RoyalBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.RoyalBlue );
			}
		}

		static public Color SaddleBrown
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SaddleBrown );
			}
		}

		static public Color Salmon
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Salmon );
			}
		}

		static public Color SandyBrown
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SandyBrown );
			}
		}

		static public Color SeaGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SeaGreen );
			}
		}

		static public Color SeaShell
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SeaShell );
			}
		}

		static public Color Sienna
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Sienna );
			}
		}

		static public Color Silver
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Silver );
			}
		}

		static public Color SkyBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SkyBlue );
			}
		}

		static public Color SlateBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SlateBlue );
			}
		}

		static public Color SlateGray
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SlateGray );
			}
		}

		static public Color Snow
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Snow );
			}
		}

		static public Color SpringGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SpringGreen );
			}
		}

		static public Color SteelBlue
		{
			get
			{
				return Color.FromKnownColor( KnownColor.SteelBlue );
			}
		}

		static public Color Tan
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Tan );
			}
		}

		static public Color Teal
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Teal );
			}
		}

		static public Color Thistle
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Thistle );
			}
		}

		static public Color Tomato
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Tomato );
			}
		}

		static public Color Turquoise
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Turquoise );
			}
		}

		static public Color Violet
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Violet );
			}
		}

		static public Color Wheat
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Wheat );
			}
		}

		static public Color White
		{
			get
			{
				return Color.FromKnownColor( KnownColor.White );
			}
		}

		static public Color WhiteSmoke
		{
			get
			{
				return Color.FromKnownColor( KnownColor.WhiteSmoke );
			}
		}

		static public Color Yellow
		{
			get
			{
				return Color.FromKnownColor( KnownColor.Yellow );
			}
		}

		static public Color YellowGreen
		{
			get
			{
				return Color.FromKnownColor( KnownColor.YellowGreen );
			}
		}
	}
}
