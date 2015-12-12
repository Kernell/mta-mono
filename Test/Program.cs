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
			Element.Root.OnPlayerJoin += Root_OnPlayerJoin;

			//Element.Root.OnElementDestroy += ( Element sender, ElementEventArgs e ) =>
			//{
			//	Debug.Info( "lambda " + sender.GetType() + " " + e.This.GetType() );
			//};

			Element vehicle = new Vehicle( VehicleModel.ADMIRAL, Vector3.Zero, Vector3.Zero );

			Debug.Info( vehicle.GetType().ToString() );

			vehicle.OnElementDestroy += Root_ElementDestroy;

			//Event.Add( "onTest", true );

			//Event.AddHandler( "onTest", vehicle, new Action<Element, string, bool, bool>( testEvent_OnTrigger ) );

			//Event.Trigger( "onTest", vehicle, "test", true, false, 123, 456.7f, 1337.01d, null, vehicle );

			vehicle.Destroy();
		}

		static void Root_OnPlayerJoin( Element sender, ElementEventArgs e )
		{
			Player player = sender as Player;

			Debug.Info( "Player '" + player.GetName() + "' joined" );
		}

		static void Root_OnPlayerConnect( Element sender, PlayerConnectEventArgs e )
		{
			//Player player = sender as Player;

			Debug.Info( "Player '" + sender.GetType() + "' connected" );
		}

		static void testEvent_OnTrigger( Element sender, string a, bool b, bool c )
		{
			Debug.Info( "testEvent_OnTrigger " + sender.GetType() + " " + a + " " + b + " " + c );
		}

		static void Root_ElementDestroy( Element sender, ElementEventArgs e )
		{
			Debug.Info( "Root_ElementDestroy " + sender.GetType() + " " + e.This.GetType() );
		}
	}
}
