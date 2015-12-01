using System;
using System.Collections.Generic;
using MultiTheftAuto;
using MultiTheftAuto.EventArgs;

namespace Test
{
	public class Program
	{
		static void Main( string[] args )
		{
			Element.Root.OnElementDestroy += Root_ElementDestroy;

			Vehicle vehicle = new Vehicle( VehicleModel.ADMIRAL, Vector3.Zero, Vector3.Zero );

			vehicle.OnElementDestroy += Root_ElementDestroy;

			vehicle.Destroy();
		}

		public static void Root_ElementDestroy( Element sender, ElementEventArgs e )
		{
			Debug.Info( "Root_ElementDestroy {0} {1}", sender.GetType(), e.This.GetType() );
		}
	}
}
