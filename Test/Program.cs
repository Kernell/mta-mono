using System;
using System.Linq;
using System.Collections.Generic;
using MultiTheftAuto;
using MultiTheftAuto.EventArgs;

using Console = MultiTheftAuto.Console;

namespace Test
{
	public class Program
	{
		static void Main( string[] args )
		{
			Event.AddHandler( "onElementDestroy", Resource.Root, new Action<Vehicle>( Vehicle_OnElementDestroy ) );

			for( int i = 0; i < 8; i++ )
			{
				Vehicle vehicle = new Vehicle( VehicleModel.SULTAN + i, Vector3.Zero, Vector3.Zero );
			}

			Debug.Info( "------------------------------------" );

			foreach( Vehicle vehicle in Element.GetByType( "vehicle" ) )
			{
				Debug.Info( string.Format( "{0} {1}", vehicle.GetVehicleType(), vehicle.GetName() ) );

				vehicle.Destroy();
			}

			Debug.Info( "------------------------------------" );
		}

		static void Vehicle_OnElementDestroy( Vehicle sender )
		{
			Console.WriteLine( "onElementDestroy: " + sender.GetName() );
		}
	}
}
