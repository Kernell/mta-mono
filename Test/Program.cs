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
			Element.Root.OnElementDestroy += ( Element sender, ElementEventArgs e ) =>
			{
				Debug.Info( "lambda " + sender.GetType() + " " + e.This.GetType() );
			};

			Vehicle vehicle = new Vehicle( VehicleModel.ADMIRAL, Vector3.Zero, Vector3.Zero );

			vehicle.OnElementDestroy += Root_ElementDestroy;

			Event.Add( "onTest", true );

			Event.AddHandler( "onTest", vehicle, new Action<Element, string, char, bool>( testEvent_OnTrigger ) );

			Event.Trigger( "onTest", vehicle, "test", 'a', true, false, 123, 456.7f, 1337.01d, null, vehicle );

			//vehicle.Destroy();
		}

		static void testEvent_OnTrigger( Element sender, string a, char b, bool c )
		{
			Debug.Info( "testEvent_OnTrigger " + sender.GetType() + " " + a + " " + b + " " + c );
		}

		static void Root_ElementDestroy( Element sender, ElementEventArgs e )
		{
			Debug.Info( "Root_ElementDestroy " + sender.GetType() + " " + e.This.GetType() );
		}
	}
}
