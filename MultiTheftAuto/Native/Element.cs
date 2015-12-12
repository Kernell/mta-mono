using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto.Native
{
	public static class Element
    {
		// Element create/destroy
        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern UInt32 Create( string type, string ID );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Destroy( UInt32 userdata );

		// Element get funcs
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetRootElement();

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsElement( UInt32 userdata );
		
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetType( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetID( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 Clone( UInt32 userdata, Vector3 position = null, bool cloneChildren = false );
        
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32[] GetByType( string elementType, UInt32 startElement = 0 );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern UInt32 GetByID( string elementID, int index = 0 );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern UInt32 GetByIndex( string type, int index );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern UInt32 GetChild( UInt32 parent, int index );

        [MethodImpl( MethodImplOptions.InternalCall )]
        public static extern int GetChildrenCount( UInt32 parent );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetData( UInt32 userdata, string key, bool inherit = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Array GetAllData( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetParent( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetPosition( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetRotation( UInt32 userdata, string order = "default" );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern Vector3 GetVelocity( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetInterior( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsWithinColShape( UInt32 userdata, UInt32 colshape );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsWithinMarker( UInt32 userdata, UInt32 marker );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetDimension( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern string GetZoneName( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsAttached( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetAttachedTo( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetColShape( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetAlpha( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsDoubleSided( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern float GetHealth( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern int GetModel( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsInWater( UInt32 userdata );

//		[MethodImpl( MethodImplOptions.InternalCall )]
//		public static extern bool GetElementAttachedOffsets( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetSyncer( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool GetCollisionsEnabled( UInt32 userdata );

        [MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsFrozen( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern UInt32 GetLowLODElement( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool IsElementLowLOD( UInt32 userdata );

		// Element set funcs
		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool ClearElementVisibleTo( UInt32 userdata );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetID( UInt32 userdata, string ID );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetData( UInt32 userdata, string key, string value, bool sync = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool RemoveData( UInt32 userdata, string key );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetParent( UInt32 userdata, UInt32 parent );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetPosition( UInt32 userdata, Vector3 position, bool warp = true );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetRotation( UInt32 userdata, Vector3 rotation, string order = "default", bool pedRotation = false );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetVelocity( UInt32 userdata, Vector3 velocity );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetVisibleTo( UInt32 userdata, UInt32 target, bool visible );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetInterior( UInt32 userdata, int interior, Vector3 position = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDimension( UInt32 userdata, int dimension );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Attach( UInt32 userdata, UInt32 target, Vector3 offsetPosition = null, Vector3 offsetRotation = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool Detach( UInt32 userdata, UInt32 target = 0 );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetAlpha( UInt32 userdata, int alpha );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetDoubleSided( UInt32 userdata, bool doubleSided );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetHealth( UInt32 userdata, float health );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetModel( UInt32 userdata, int model );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetAttachedOffsets( UInt32 userdata, Vector3 offsetPosition = null, Vector3 offsetRotation = null );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetSyncer( UInt32 userdata, UInt32 player );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetCollisionsEnabled( UInt32 userdata, bool enabled );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetFrozen( UInt32 userdata, bool frozen );

		[MethodImpl( MethodImplOptions.InternalCall )]
		public static extern bool SetLowLODElement( UInt32 userdata, UInt32 lowLod );
    }
}
