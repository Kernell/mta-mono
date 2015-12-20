using System;
using System.Collections.Generic;
using MultiTheftAuto;
using MultiTheftAuto.EventArgs;

namespace Test
{
	public class Program
	{
		static void MonoCommandHandler( Player player, string command, string[] args )
		{
			Debug.Info( player.GetName() + " executed command '" + command + "' with args: " + string.Join( " ", args ) );
		}

		static void Main( string[] args )
		{
			Server.AddCommandHandler( "mono", new CommandHandler( MonoCommandHandler ) );

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

			Debug.Info( Color.Aquamarine.ToString() );
		}

		static void Root_OnPlayerJoin( Element sender, ElementEventArgs e )
		{
			Player player = sender as Player;

			Debug.Info( "Player '" + player.GetName() + "' joined" );

			player.FadeCamera( true, 1.0f, Color.Black );
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
