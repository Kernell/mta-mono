using System;
using System.Runtime.CompilerServices;
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
				return this.GetVehicleType();
			}
		}

		#endregion

		#region Constructors

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vehicle( VehicleModel model, Vector3 position, Vector3 rotation, string numberplate = null, bool direction = false, int variant1 = 255, int variant2 = 255 );

		internal Vehicle()
		{

		}

		~Vehicle()
		{
			Debug.Info( "~Vehicle() [" + this.GetName() + "]" );
		}

		#endregion

		#region Static Methods

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static string GetNameFromModel( int modelID );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static string GetUpgradeSlotName( int upgradeOrSlot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static Vehicle[] GetOfType( VehicleModel model );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern static int GetModelFromName( string name );

		#endregion

		#region Methods

		#region Set

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Fix();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Blow( bool blow = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTurnVelocity( Vector3 velocity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetColor( Color color1, Color color2 = null, Color color3 = null, Color color4 = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetLandingGearDown( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetLocked( bool locked );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetDoorsUndamageable( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetSirensOn( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTaxiLightOn( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool AddUpgrade( int upgrade );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveUpgrade( int upgrade );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetDoorState( int door, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetWheelStates( int frontLeft, int rearLeft, int frontRight, int rearRight );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetLightState( int light, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetPanelState( int panelID, int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetIdleRespawnDelay( int timeDelay );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetRespawnDelay( int timeDelay );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetRespawnPosition( Vector3 position, Vector3 rotation );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool ToggleRespawn( bool respawn );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool ResetExplosionTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool ResetIdleTime();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Spawn( Vector3 position, Vector3 rotation );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool Respawn();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetOverrideLights( int state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool AttachTrailerToVehicle( Element trailer );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool DetachTrailerFromVehicle( Element trailer = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetEngineState( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetDamageProof( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetPaintjob( int value );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetFuelTankExplodable( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTrainDerailed( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTrainDerailable( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTrainDirection( bool state );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTrainSpeed( float speed );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetHeadLightColor( Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetTurretPosition( float x, float y );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetDoorOpenRatio( int door, float ratio, int time = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetVariant( int variant1 = 255, int variant2 = 255 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool AddSirens( int sirenCount, int sirenType, bool flag360 = false, bool checkLos = true, bool useRandomiser = true, bool silent = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool RemoveSirens();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetSirens( int sirenPoint, Vector3 position, Color color = null, float minAlpha = 0.0f );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetPlateText( string text );

		#endregion

		#region Get

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Array GetSirens();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern object GetSirenParams();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetVehicleType();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern char[] GetVariant();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern VehicleColor GetColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GetLandingGearDown();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetMaxPassengers();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetName();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Ped GetOccupant( int seat = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Ped[] GetOccupants();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Ped GetController();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GetSirensOn();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vector3 GetTurnVelocity();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vector3 GetTurretPosition();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetUpgradeOnSlot( int slot );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern UInt32[] GetUpgrades();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern UInt32[] GetCompatibleUpgrades( int slot = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetDoorState( int door );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern VehicleWheelsState GetWheelStates();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetLightState( int light );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetPanelState( int panel );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetOverrideLights();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vehicle GetTowedByVehicle();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Vehicle GetTowingVehicle();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetPaintjob();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern string GetPlateText();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GetEngineState();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool GetTrainDirection();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetTrainSpeed();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetHeadLightColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetVehicleDoorOpenRatio( int door );

		#endregion

		#region Is

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsTaxiLightOn();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsTrainDerailed();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsTrainDerailable();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsDamageProof();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsFuelTankExplodable();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsOnGround();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsBlown();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool IsLocked();

		#endregion

		#endregion
	}
}
