using System;
using System.Runtime.CompilerServices;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MultiTheftAuto
{
	public enum BlipIcon
	{
		None = 0,
		Border,
		Centre,
		MapHere,
		North,

		AirYard,
		Gun,
		Barbers,
		BigSmoke,
		BoatYard,
		Burgershot,
		Bulldozer,
		CatPink,
		Cesar,
		Chicken,
		CJ,
		Crash1,
		Diner,
		EmmetGun,
		EnemyAttack,
		Fire,
		Girlfriend,
		Hospital,
		Coco,
		Maddog,
		Mafia,
		Mcstrap,
		ModGarage,
		Ogloc,
		Pizza,
		Police,
		PropertyGreen,
		PropertyRed,
		Race,
		Ryder,
		SaveHouse,
		School,
		Mystery,
		Sweet,
		Tattoo,
		Truth,
		Waypoint,
		TorenoRanch,
		Triads,
		TriadsCasino,
		Tshirt,
		Woozie,
		Zero,
		DateDisco,
		DateDrink,
		DateFood,
		Truck,
		Cash,
		Flag,
		Gym,
		Impound,
		RunwayLight,
		Runway,
		GangB,
		GangP,
		GangY,
		GangN,
		GangG,
		Spray
	}

	public class Blip : Element
	{
		#region Constructors

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Blip( Vector3 position, BlipIcon icon = BlipIcon.None, int size = 2, Color color = null, int ordering = 0, float visibleDistance = 99999.0f, Element visibleTo = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Blip( Element element, BlipIcon icon = BlipIcon.None, int size = 2, Color color = null, int ordering = 0, float visibleDistance = 99999.0f, Element visibleTo = null );

		internal Blip()
		{
		}

		#endregion

		#region Get functions

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetIcon();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetSize();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern Color GetColor();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern int GetOrdering();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern float GetVisibleDistance();

		#endregion

		#region Set functions

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetIcon( int icon );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetSize( int size );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetColor( Color color );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetOrdering( int ordering );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public extern bool SetVisibleDistance( float distance );

		#endregion
	}
}
