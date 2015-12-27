using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public enum VehicleModel
	{
		ADMIRAL		= 445,
		ALPHA		= 602,
		AMBULAN		= 416,
		ANDROM		= 592,
		ARTICT1		= 435,
		ARTICT2		= 450,
		ARTICT3		= 591,
		AT400		= 577,
		BAGBOXA		= 606,
		BAGBOXB		= 607,
		BAGGAGE		= 485,
		BANDITO		= 568,
		BANSHEE		= 429,
		BARRACKS	= 433,
		BEAGLE		= 511,
		BENSON		= 499,
		BF400		= 581,
		BFINJECT	= 424,
		BIKE		= 509,
		BLADE		= 536,
		BLISTAC		= 496,
		BLOODRA		= 504,
		BMX			= 481,
		BOBCAT		= 422,
		BOXBURG		= 609,
		BOXVILLE	= 498,
		BRAVURA		= 401,
		BROADWAY	= 575,
		BUCCANEE	= 518,
		BUFFALO		= 402,
		BULLET		= 541,
		BURRITO		= 482,
		BUS			= 431,
		CABBIE		= 438,
		CADDY		= 457,
		CADRONA		= 527,
		CAMPER		= 483,
		CARGOBOB	= 548,
		CEMENT		= 524,
		CHEETAH		= 415,
		CLOVER		= 542,
		CLUB		= 589,
		COACH		= 437,
		COASTG		= 472,
		COMBINE		= 532,
		COMET		= 480,
		COPBIKE		= 523,
		COPCARLA	= 596,
		COPCARRU	= 599,
		COPCARSF	= 597,
		COPCARVG	= 598,
		CROPDUST	= 512,
		DFT30		= 578,
		DINGHY		= 473,
		DODO		= 593,
		DOZER		= 486,
		DUMPER		= 406,
		DUNERIDE	= 573,
		ELEGANT		= 507,
		ELEGY		= 562,
		EMPEROR		= 585,
		ENFORCER	= 427,
		ESPERANT	= 419,
		EUROS		= 587,
		FAGGIO		= 462,
		FARMTR1		= 610,
		FBIRANCH	= 490,
		FBITRUCK	= 528,
		FCR900		= 521,
		FELTZER		= 533,
		FIRELA		= 544,
		FIRETRUK	= 407,
		FLASH		= 565,
		FLATBED		= 455,
		FORKLIFT	= 530,
		FORTUNE		= 526,
		FREEWAY		= 463,
		FREIBOX		= 590,
		FREIFLAT	= 569,
		FREIGHT		= 537,
		GLENDALE	= 466,
		GLENSHIT	= 604,
		GREENWOO	= 492,
		HERMES		= 474,
		HOTDOG		= 588,
		HOTKNIFE	= 434,
		HOTRINA		= 502,
		HOTRINB		= 503,
		HOTRING		= 494,
		HUNTER		= 425,
		HUNTLEY		= 579,
		HUSTLER		= 545,
		HYDRA		= 520,
		INFERNUS	= 411,
		INTRUDER	= 546,
		JESTER		= 559,
		JETMAX		= 493,
		JOURNEY		= 508,
		KART		= 571,
		LANDSTAL	= 400,
		LAUNCH		= 595,
		LEVIATHN	= 417,
		LINERUN		= 403,
		MAJESTIC	= 517,
		MANANA		= 410,
		MARQUIS		= 484,
		MAVERICK	= 487,
		MERIT		= 551,
		MESA		= 500,
		MONSTER		= 444,
		MONSTERA	= 556,
		MONSTERB	= 557,
		MOONBEAM	= 418,
		MOWER		= 572,
		MRWHOOP		= 423,
		MTBIKE		= 510,
		MULE		= 414,
		NEBULA		= 516,
		NEVADA		= 553,
		NEWSVAN		= 582,
		NRG500		= 522,
		OCEANIC		= 467,
		PACKER		= 443,
		PATRIOT		= 470,
		PCJ600		= 461,
		PEREN		= 404,
		PETRO		= 514,
		PETROTR		= 584,
		PHOENIX		= 603,
		PICADOR		= 600,
		PIZZABOY	= 448,
		POLMAV		= 497,
		PONY		= 413,
		PREDATOR	= 430,
		PREMIER		= 426,
		PREVION		= 436,
		PRIMO		= 547,
		QUAD		= 471,
		RAINDANC	= 563,
		RANCHER		= 489,
		RCBANDIT	= 441,
		RCBARON		= 464,
		RCCAM		= 594,
		RCGOBLIN	= 501,
		RCRAIDER	= 465,
		RCTIGER		= 564,
		RDTRAIN		= 515,
		REEFER		= 453,
		REGINA		= 479,
		REMINGTN	= 534,
		RHINO		= 432,
		RNCHLURE	= 505,
		ROMERO		= 442,
		RUMPO		= 440,
		RUSTLER		= 476,
		SABRE		= 475,
		SADLER		= 543,
		SADLSHIT	= 605,
		SANCHEZ		= 468,
		SANDKING	= 495,
		SAVANNA		= 567,
		SEASPAR		= 447,
		SECURICA	= 428,
		SENTINEL	= 405,
		SHAMAL		= 519,
		SKIMMER		= 460,
		SLAMVAN		= 535,
		SOLAIR		= 458,
		SPARROW		= 469,
		SPEEDER		= 452,
		SQUALO		= 446,
		STAFFORD	= 580,
		STALLION	= 439,
		STRATUM		= 561,
		STREAK		= 538,
		STREAKC		= 570,
		STRETCH		= 409,
		STUNT		= 513,
		SULTAN		= 560,
		SUNRISE		= 550,
		SUPERGT		= 506,
		SWATVAN		= 601,
		SWEEPER		= 574,
		TAHOMA		= 566,
		TAMPA		= 549,
		TAXI		= 420,
		TOPFUN		= 459,
		TORNADO		= 576,
		TOWTRUCK	= 525,
		TRACTOR		= 531,
		TRAM		= 449,
		TRASH		= 408,
		TROPIC		= 454,
		TUG			= 583,
		TUGSTAIR	= 608,
		TURISMO		= 451,
		URANUS		= 558,
		UTILITY		= 552,
		UTILTR1		= 611,
		VCNMAV		= 488,
		VINCENT		= 540,
		VIRGO		= 491,
		VOODOO		= 412,
		VORTEX		= 539,
		WALTON		= 478,
		WASHING		= 421,
		WAYFARER	= 586,
		WILLARD		= 529,
		WINDSOR		= 555,
		YANKEE		= 456,
		YOSEMITE	= 554,
		ZR350		= 477
	}

	public class Vehicle : Element
	{
		#region Properties

		public string Type
		{
			get
			{
				return Native.Vehicle.GetType( this.GetUserData() );
			}
		}

		#endregion

		#region Constructors

		public Vehicle( VehicleModel model, Vector3 position, Vector3 rotation, string numberplate = null, bool direction = false, int variant1 = 255, int variant2 = 255 )
			: base( Native.Vehicle.Create( (int)model, position, rotation, numberplate, direction, variant1, variant2 ) )
		{
			
		}

		public Vehicle( UInt32 userdata )
			: base( userdata )
		{

		}

		#endregion

		#region Static Methods

		public static string GetNameFromModel( int modelID )
		{
			return Native.Vehicle.GetNameFromModel( modelID );
		}

		public static string GetUpgradeSlotName( int upgradeOrSlot )
		{
			return Native.Vehicle.GetUpgradeSlotName( upgradeOrSlot );
		}

		public static IEnumerable<Vehicle> GetOfType( VehicleModel model )
		{
			return Native.Vehicle.GetOfType( (int)model ).Select( i => Element.FindOrCreate( i ) as Vehicle );
		}

		#endregion

		#region Methods

		#region Set

		public bool Fix()
		{
			return Native.Vehicle.Fix( this.GetUserData() );
		}

		public bool Blow( bool blow = true )
		{
			return Native.Vehicle.Blow( this.GetUserData(), blow );
		}

		public bool SetTurnVelocity( Vector3 velocity )
		{
			return Native.Vehicle.SetTurnVelocity( this.GetUserData(), velocity );
		}

		public bool SetColor( Color color1, Color color2 = null, Color color3 = null, Color color4 = null )
		{
			return Native.Vehicle.SetColor( this.GetUserData(), color1, color2, color3, color4 );
		}

		public bool SetLandingGearDown( bool state )
		{
			return Native.Vehicle.SetLandingGearDown( this.GetUserData(), state );
		}

		public bool SetLocked( bool locked )
		{
			return Native.Vehicle.SetLocked( this.GetUserData(), locked );
		}

		public bool SetDoorsUndamageable( bool state )
		{
			return Native.Vehicle.SetDoorsUndamageable( this.GetUserData(), state );
		}

		public bool SetSirensOn( bool state )
		{
			return Native.Vehicle.SetSirensOn( this.GetUserData(), state );
		}

		public bool SetTaxiLightOn( bool state )
		{
			return Native.Vehicle.SetTaxiLightOn( this.GetUserData(), state );
		}

		public bool AddUpgrade( int upgrade )
		{
			return Native.Vehicle.AddUpgrade( this.GetUserData(), upgrade );
		}

		public bool RemoveUpgrade( int upgrade )
		{
			return Native.Vehicle.RemoveUpgrade( this.GetUserData(), upgrade );
		}

		public bool SetDoorState( int door, int state )
		{
			return Native.Vehicle.SetDoorState( this.GetUserData(), door, state );
		}

		public bool SetWheelStates( int frontLeft, int rearLeft, int frontRight, int rearRight )
		{
			return Native.Vehicle.SetWheelStates( this.GetUserData(), frontLeft, rearLeft, frontRight, rearRight );
		}

		public bool SetLightState( int light, int state )
		{
			return Native.Vehicle.SetLightState( this.GetUserData(), light, state );
		}

		public bool SetPanelState( int panelID, int state )
		{
			return Native.Vehicle.SetPanelState( this.GetUserData(), panelID, state );
		}

		public bool SetIdleRespawnDelay( int timeDelay )
		{
			return Native.Vehicle.SetIdleRespawnDelay( this.GetUserData(), timeDelay );
		}

		public bool SetRespawnDelay( int timeDelay )
		{
			return Native.Vehicle.SetRespawnDelay( this.GetUserData(), timeDelay );
		}

		public bool SetRespawnPosition( Vector3 position, Vector3 rotation )
		{
			return Native.Vehicle.SetRespawnPosition( this.GetUserData(), position, rotation );
		}

		public bool ToggleRespawn( bool respawn )
		{
			return Native.Vehicle.ToggleRespawn( this.GetUserData(), respawn );
		}

		public bool ResetExplosionTime()
		{
			return Native.Vehicle.ResetExplosionTime( this.GetUserData() );
		}

		public bool ResetIdleTime()
		{
			return Native.Vehicle.ResetIdleTime( this.GetUserData() );
		}

		public bool Spawn( Vector3 position, Vector3 rotation )
		{
			return Native.Vehicle.Spawn( this.GetUserData(), position, rotation );
		}

		public bool Respawn()
		{
			return Native.Vehicle.Respawn( this.GetUserData() );
		}

		public bool SetOverrideLights( int state )
		{
			return Native.Vehicle.SetOverrideLights( this.GetUserData(), state );
		}

		public bool AttachTrailerToVehicle( Element trailer )
		{
			return Native.Vehicle.AttachTrailerToVehicle( this.GetUserData(), trailer.GetUserData() );
		}

		public bool DetachTrailerFromVehicle( Element trailer = null )
		{
			if( trailer == null )
				return Native.Vehicle.DetachTrailerFromVehicle( this.GetUserData() );

			return Native.Vehicle.DetachTrailerFromVehicle( this.GetUserData(), trailer.GetUserData() );
		}

		public bool SetEngineState( bool state )
		{
			return Native.Vehicle.SetEngineState( this.GetUserData(), state );
		}

		public bool SetDamageProof( bool state )
		{
			return Native.Vehicle.SetDamageProof( this.GetUserData(), state );
		}

		public bool SetPaintjob( int value )
		{
			return Native.Vehicle.SetPaintjob( this.GetUserData(), value );
		}

		public bool SetFuelTankExplodable( bool state )
		{
			return Native.Vehicle.SetFuelTankExplodable( this.GetUserData(), state );
		}

		public bool SetTrainDerailed( bool state )
		{
			return Native.Vehicle.SetTrainDerailed( this.GetUserData(), state );
		}

		public bool SetTrainDerailable( bool state )
		{
			return Native.Vehicle.SetTrainDerailable( this.GetUserData(), state );
		}

		public bool SetTrainDirection( bool state )
		{
			return Native.Vehicle.SetTrainDirection( this.GetUserData(), state );
		}

		public bool SetTrainSpeed( float speed )
		{
			return Native.Vehicle.SetTrainSpeed( this.GetUserData(), speed );
		}

		public bool SetHeadLightColor( Color color )
		{
			return Native.Vehicle.SetHeadLightColor( this.GetUserData(), color );
		}

		public bool SetTurretPosition( float x, float y )
		{
			return Native.Vehicle.SetTurretPosition( this.GetUserData(), x, y );
		}

		public bool SetDoorOpenRatio( int door, float ratio, int time = 0 )
		{
			return Native.Vehicle.SetDoorOpenRatio( this.GetUserData(), door, ratio, time );
		}

		public bool SetVariant( int variant1 = 255, int variant2 = 255 )
		{
			return Native.Vehicle.SetVariant( this.GetUserData(), variant1, variant2 );
		}

		public bool AddSirens( int sirenCount, int sirenType, bool flag360 = false, bool checkLos = true, bool useRandomiser = true, bool silent = false )
		{
			return Native.Vehicle.AddSirens( this.GetUserData(), sirenCount, sirenType, flag360, checkLos, useRandomiser, silent );
		}

		public bool RemoveSirens()
		{
			return Native.Vehicle.RemoveSirens( this.GetUserData() );
		}

		public bool SetSirens( int sirenPoint, Vector3 position, Color color = null, float minAlpha = 0.0f )
		{
			if( color == null )
				return Native.Vehicle.SetSirens( this.GetUserData(), sirenPoint, position, color, minAlpha );
			
			return Native.Vehicle.SetSirens( this.GetUserData(), sirenPoint, position, color, minAlpha );
		}

		public bool SetPlateText( string text )
		{
			return Native.Vehicle.SetPlateText( this.GetUserData(), text );
		}

		#endregion

		#region Get

		public Array GetSirens()
		{
			return Native.Vehicle.GetSirens( this.userdata );
		}

		public Object GetSirenParams()
		{
			return Native.Vehicle.GetSirenParams( this.userdata );
		}

		public string GetVehicleType()
		{
			return Native.Vehicle.GetType( this.userdata );
		}
		
		public char[] GetVariant()
		{
			return Native.Vehicle.GetVariant( this.userdata );
		}

		public VehicleColor GetColor()
		{
			return Native.Vehicle.GetColor( this.userdata );
		}

		public static int GetModelFromName( string name )
		{
			return Native.Vehicle.GetModelFromName( name );
		}

		public bool GetLandingGearDown()
		{
			return Native.Vehicle.GetLandingGearDown( this.userdata );
		}

		public int GetMaxPassengers()
		{
			return Native.Vehicle.GetMaxPassengers( this.userdata );
		}

		public string GetName()
		{
			return Native.Vehicle.GetName( this.userdata );
		}

		public Ped GetOccupant( int seat = 0 )
		{
			return Element.FindOrCreate( Native.Vehicle.GetOccupant( this.userdata, seat ) ) as Ped;
		}

		public IEnumerable<Ped> GetOccupants()
		{
			return Native.Vehicle.GetOccupants( this.userdata ).Select( i => Element.FindOrCreate( i ) as Ped );
		}

		public Ped GetController()
		{
			return Element.FindOrCreate( Native.Vehicle.GetController( this.userdata ) ) as Ped;
		}

		public bool GetSirensOn()
		{
			return Native.Vehicle.GetSirensOn( this.userdata );
		}

		public Vector3 GetTurnVelocity()
		{
			return Native.Vehicle.GetTurnVelocity( this.userdata );
		}

		public Vector3 GetTurretPosition()
		{
			return Native.Vehicle.GetTurretPosition( this.userdata );
		}

		public int GetUpgradeOnSlot( int slot )
		{
			return Native.Vehicle.GetUpgradeOnSlot( this.userdata, slot );
		}

		public UInt32[] GetUpgrades()
		{
			return Native.Vehicle.GetUpgrades( this.userdata );
		}

		public UInt32[] GetCompatibleUpgrades( int slot = 0 )
		{
			return Native.Vehicle.GetCompatibleUpgrades( this.userdata, slot );
		}

		public int GetDoorState( int door )
		{
			return Native.Vehicle.GetDoorState( this.userdata, door );
		}

		public VehicleWheelsState GetWheelStates()
		{
			return Native.Vehicle.GetWheelStates( this.userdata );
		}

		public int GetLightState( int light )
		{
			return Native.Vehicle.GetLightState( this.userdata, light );
		}

		public int GetPanelState( int panel )
		{
			return Native.Vehicle.GetPanelState( this.userdata, panel );
		}

		public int GetOverrideLights()
		{
			return Native.Vehicle.GetOverrideLights( this.userdata );
		}

		public Vehicle GetTowedByVehicle()
		{
			return Element.FindOrCreate( Native.Vehicle.GetTowedByVehicle( this.userdata ) ) as Vehicle;
		}

		public Vehicle GetTowingVehicle()
		{
			return Element.FindOrCreate( Native.Vehicle.GetTowingVehicle( this.userdata ) ) as Vehicle;
		}

		public int GetPaintjob()
		{
			return Native.Vehicle.GetPaintjob( this.userdata );
		}

		public string GetPlateText()
		{
			return Native.Vehicle.GetPlateText( this.userdata );
		}

		public bool GetEngineState()
		{
			return Native.Vehicle.GetEngineState( this.userdata );
		}

		public bool GetTrainDirection()
		{
			return Native.Vehicle.GetTrainDirection( this.userdata );
		}

		public float GetTrainSpeed()
		{
			return Native.Vehicle.GetTrainSpeed( this.userdata );
		}

		public Color GetHeadLightColor()
		{
			return Native.Vehicle.GetHeadLightColor( this.userdata );
		}

		public float GetVehicleDoorOpenRatio( int door )
		{
			return Native.Vehicle.GetVehicleDoorOpenRatio( this.userdata, door );
		}

		#endregion

		#region Is

		public bool IsTaxiLightOn()
		{
			return Native.Vehicle.IsTaxiLightOn( this.GetUserData() );
		}

		public bool IsTrainDerailed()
		{
			return Native.Vehicle.IsTrainDerailed( this.userdata );
		}

		public bool IsTrainDerailable()
		{
			return Native.Vehicle.IsTrainDerailable( this.userdata );
		}

		public bool IsDamageProof()
		{
			return Native.Vehicle.IsDamageProof( this.userdata );
		}

		public bool IsFuelTankExplodable()
		{
			return Native.Vehicle.IsFuelTankExplodable( this.userdata );
		}

		public bool IsOnGround()
		{
			return Native.Vehicle.IsOnGround( this.userdata );
		}

		public bool IsBlown()
		{
			return Native.Vehicle.IsBlown( this.userdata );
		}

		public bool IsLocked()
		{
			return Native.Vehicle.IsLocked( this.userdata );
		}

		#endregion

		#endregion
	}
}
