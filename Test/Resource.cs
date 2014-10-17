using System;
using System.Collections.Generic;
using MultiTheftAuto;

namespace Test
{
	public class Resource
	{
		public Resource()
		{
			var vehicles = new List<Vehicle>( 10 );

			for( int i = 0; i < vehicles.Capacity; i++ )
			{
				Vehicle vehicle = new Vehicle( 562, new Vector3( 192.0f, 168.0f, 10.0f ) * i, new Vector3( 0.0f, 0.0f, 0.0f ) );

				if( vehicle.IsValid() )
				{
					vehicles.Add( vehicle );
				}
				else
				{
					Debug.Error( "Failed to create vehicle" );
				}
			}

			foreach( Vehicle vehicle in vehicles )
			{
				Debug.Log( "{0} {1}", vehicle, vehicle.GetPosition() );
			}
		}
	}
}
