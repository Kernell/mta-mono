using System;
using System.Collections.Generic;
using MultiTheftAuto;
using MultiTheftAuto.Native;

namespace Test
{
	public class Resource
	{
		public Resource()
		{
			var vehicles = new List<UInt32>( 10 );

			for( int i = 0; i < vehicles.Capacity; i++ )
			{
				UInt32 vehicle = Vehicle.Create( 562, new Vector3( 192.0f, 168.0f, 10.0f ) * i, new Vector3( 0.0f, 0.0f, 0.0f ) );

				if( vehicle != 0 )
				{
					vehicles.Add( vehicle );
				}
				else
				{
					Debug.Error( "Failed to create vehicle" );
				}
			}

			foreach( UInt32 vehicle in vehicles )
			{
				Debug.Log( "{0} {1}", vehicle, Element.GetPosition( vehicle ) );
			}
		}
	}
}
