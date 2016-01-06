using System;
using System.Runtime.CompilerServices;

namespace MultiTheftAuto
{
	public enum PickupType
	{
		Health,
		Armour,
		Weapon,
		Custom,
	}

	public class Pickup : Element
	{
		internal Pickup()
		{
		}

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public Pickup( Vector3 position, PickupType type, double value, ulong ulRespawnInterval, int ammo );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public PickupType GetPickupType();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public int GetWeapon();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public float GetAmount();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public ushort GetAmmo();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public ulong GetRespawnInterval();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool IsSpawned();

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetType( PickupType type, double value, double ammo );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool SetRespawnInterval( ulong interval );

		[MethodImpl( MethodImplOptions.InternalCall )]
		extern public bool Use( Element player );
	}
}
