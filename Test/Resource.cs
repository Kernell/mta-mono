using System;
using MultiTheftAuto;
using MultiTheftAuto.Native;

namespace Test
{
    public class Resource
    {
        public Resource()
        {
			Debug.Error( "{0}", new Color( 255, 128, 0 ).ToARGB().ToString( "X" ) );
			
			Vehicle vehicle = Vehicle.Create( 562, new Vector3( 192.0f, 168.0f, 0.0f ), new Vector3( 0.0f, 0.0f, 0.0f ) );

			//Debug.Log( "{0}", Element.GetPosition( vehicle ) );
        }
    }
}
