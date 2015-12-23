using System;
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

		public Blip( Vector3 position, BlipIcon icon = BlipIcon.None, int size = 2, Color color = null, int ordering = 0, float visibleDistance = 99999.0f, Element visibleTo = null )
			: base( Native.Blip.Create( position, (int)icon, size, color, ordering, visibleDistance, visibleTo != null ? visibleTo.userdata : 0 ) )
		{

		}

		public Blip( Element element, BlipIcon icon = BlipIcon.None, int size = 2, Color color = null, int ordering = 0, float visibleDistance = 99999.0f, Element visibleTo = null )
			: base( Native.Blip.CreateAttachedTo( element.userdata, (int)icon, size, color, ordering, visibleDistance, visibleTo != null ? visibleTo.userdata : 0 ) )
		{

		}

		public Blip( UInt32 userdata )
			: base( userdata )
		{

		}

		#endregion

		#region Get functions

		public int GetIcon()
		{
			return Native.Blip.GetIcon( this.userdata );
		}

		public int GetSize()
		{
			return Native.Blip.GetSize( this.userdata );
		}

		public Color GetColor()
		{
			return Native.Blip.GetColor( this.userdata );
		}

		public int GetOrdering()
		{
			return Native.Blip.GetOrdering( this.userdata );
		}

		public float GetVisibleDistance()
		{
			return Native.Blip.GetVisibleDistance( this.userdata );
		}

		#endregion

		#region Set functions

		public bool SetIcon( int icon )
		{
			return Native.Blip.SetIcon( this.userdata, icon );
		}

		public bool SetSize( int size )
		{
			return Native.Blip.SetSize( this.userdata, size );
		}

		public bool SetColor( Color color )
		{
			return Native.Blip.SetColor( this.userdata, color );
		}

		public bool SetOrdering( int ordering )
		{
			return Native.Blip.SetOrdering( this.userdata, ordering );
		}

		public bool SetVisibleDistance( float distance )
		{
			return Native.Blip.SetVisibleDistance( this.userdata, distance );
		}

		#endregion
	}
}
