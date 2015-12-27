using System;
using System.Collections.Generic;
using System.Linq;
using MultiTheftAuto.EventArgs;
using MultiTheftAuto.Pools;
using MultiTheftAuto.Utils;

namespace MultiTheftAuto
{
	public class Element : IdentifiedPool<Element>, IIdentifyable
	{
		#region Properties

		public UInt32 userdata
		{
			get;
			private set;
		}

		#endregion

		#region Static properties

		public static Element Root
		{
			get
			{
				UInt32 userdata = Native.Element.GetRootElement();

				return userdata != 0 ? Element.FindOrCreate( userdata ) : null;
			}
		}

		#endregion

		#region Constructors

		public Element( UInt32 userdata )
		{
			this.userdata = userdata;

			FindOrCreate( userdata );
		}

		public Element( string type, string ID )
			: this( Native.Element.Create( type, ID ) )
		{
		}

		#endregion

		#region Methods

		#region Set

		public bool Destroy()
		{
			bool result = Native.Element.Destroy( this.userdata );

			if( result )
			{
				this.userdata = 0;

				this.Dispose();
			}

			return result;
		}

		public Element Clone( Vector3 position = null, bool cloneChildren = false )
		{
			return Element.FindOrCreate( Native.Element.Clone( this.userdata, position, cloneChildren ) );
		}

		public bool ClearElementVisibleTo()
		{
			return Native.Element.ClearElementVisibleTo( this.userdata );
		}

		public bool SetID( string id )
		{
			return Native.Element.SetID( this.userdata, id );
		}

		public bool SetData( string key, string value, bool sync = true )
		{
			return Native.Element.SetData( this.userdata, key, value, sync );
		}

		public bool RemoveData( string key )
		{
			return Native.Element.RemoveData( this.userdata, key );
		}

		public bool SetParent( UInt32 parent )
		{
			return Native.Element.SetParent( this.userdata, parent );
		}

		public bool SetPosition( Vector3 position, bool warp = true )
		{
			return Native.Element.SetPosition( this.userdata, position, warp );
		}

		public bool SetRotation( Vector3 rotation, string order = "default", bool pedRotation = false )
		{
			return Native.Element.SetRotation( this.userdata, rotation, order, pedRotation );
		}

		public bool SetVelocity( Vector3 velocity )
		{
			return Native.Element.SetVelocity( this.userdata, velocity );
		}

		public bool SetVisibleTo( Element target, bool visible )
		{
			return Native.Element.SetVisibleTo( this.userdata, target.GetUserData(), visible );
		}

		public bool SetInterior( int interior, Vector3 position = null )
		{
			return Native.Element.SetInterior( this.userdata, interior, position );
		}

		public bool SetDimension( int dimension )
		{
			return Native.Element.SetDimension( this.userdata, dimension );
		}

		public bool Attach( Element target, Vector3 offsetPosition = null, Vector3 offsetRotation = null )
		{
			return Native.Element.Attach( this.userdata, target.GetUserData(), offsetPosition, offsetRotation );
		}

		public bool Detach( Element target )
		{
			return Native.Element.Detach( this.userdata, target.GetUserData() );
		}

		public bool SetAlpha( int alpha )
		{
			return Native.Element.SetAlpha( this.userdata, alpha );
		}

		public bool SetDoubleSided( bool doublesided )
		{
			return Native.Element.SetDoubleSided( this.userdata, doublesided );
		}

		public bool SetHealth( float health )
		{
			return Native.Element.SetHealth( this.userdata, health );
		}

		public bool SetModel( int model )
		{
			return Native.Element.SetModel( this.userdata, model );
		}

		public bool SetAttachedOffsets( Vector3 offsetPosition = null, Vector3 offsetRotation = null )
		{
			return Native.Element.SetAttachedOffsets( this.userdata, offsetPosition, offsetRotation );
		}

		public bool SetSyncer( Player player )
		{
			return Native.Element.SetSyncer( this.userdata, player.GetUserData() );
		}

		public bool SetCollisionsEnabled( bool enabled )
		{
			return Native.Element.SetCollisionsEnabled( this.userdata, enabled );
		}

		public bool SetFrozen( bool frozen )
		{
			return Native.Element.SetFrozen( this.userdata, frozen );
		}

		public bool SetLowLODElement( Element element )
		{
			return Native.Element.SetLowLODElement( this.userdata, element.GetUserData() );
		}

		#endregion

		#region Get

		public string GetID()
		{
			return Native.Element.GetID( this.userdata );
		}

		public string GetData( string key, bool inherit = true )
		{
			return Native.Element.GetData( this.userdata, key, inherit );
		}

		public string GetElementType()
		{
			return Native.Element.GetType( this.userdata );
		}

		public Object GetChild( UInt32 parent, int index )
		{
			return Element.FindOrCreate( Native.Element.GetChild( this.userdata, index ) );
		}

		public int GetChildrenCount()
		{
			return Native.Element.GetChildrenCount( this.userdata );
		}

		public Object GetParent()
		{
			return Element.FindOrCreate( Native.Element.GetParent( this.userdata ) );
		}

		public Vector3 GetPosition()
		{
			return Native.Element.GetPosition( this.userdata );
		}

		public Vector3 GetRotation( string order = "default" )
		{
			return Native.Element.GetRotation( this.userdata, order );
		}

		public Vector3 GetVelocity()
		{
			return Native.Element.GetVelocity( this.userdata );
		}

		public int GetInterior()
		{
			return Native.Element.GetInterior( this.userdata );
		}

		public int GetDimension()
		{
			return Native.Element.GetDimension( this.userdata );
		}

		public string GetZoneName()
		{
			return Native.Element.GetZoneName( this.userdata );
		}

		public Object GetAttachedTo()
		{
			return Element.FindOrCreate( Native.Element.GetAttachedTo( this.userdata ) );
		}

		public Object GetColShape()
		{
			return Element.FindOrCreate( Native.Element.GetColShape( this.userdata ) );
		}

		public int GetAlpha()
		{
			return Native.Element.GetAlpha( this.userdata );
		}

		public float GetHealth()
		{
			return Native.Element.GetHealth( this.userdata );
		}

		public int GetModel()
		{
			return Native.Element.GetModel( this.userdata );
		}

		public Player GetSyncer()
		{
			return Element.FindOrCreate( Native.Element.GetSyncer( this.userdata ) ) as Player;
		}

		public bool GetCollisionsEnabled()
		{
			return Native.Element.GetCollisionsEnabled( this.userdata );
		}

		public Object GetLowLODElement()
		{
			return Element.FindOrCreate( Native.Element.GetLowLODElement( this.userdata ) );
		}

		#endregion

		#region Is

		public bool IsValid()
		{
			return Native.Element.IsElement( this.userdata );
		}

		public bool IsWithinColShape( ColShape colshape )
		{
			return Native.Element.IsWithinColShape( this.userdata, colshape.GetUserData() );
		}

		public bool IsWithinMarker( Marker marker )
		{
			return Native.Element.IsWithinMarker( this.userdata, marker.GetUserData() );
		}

		public bool IsAttached()
		{
			return Native.Element.IsAttached( this.userdata );
		}

		public bool IsDoubleSided()
		{
			return Native.Element.IsDoubleSided( this.userdata );
		}

		public bool IsInWater()
		{
			return Native.Element.IsInWater( this.userdata );
		}

		public bool IsFrozen()
		{
			return Native.Element.IsFrozen( this.userdata );
		}

		public bool IsElementLowLOD()
		{
			return Native.Element.IsElementLowLOD( this.userdata );
		}

		#endregion

		public override int GetHashCode()
		{
			return (int)this.GetHashCode();
		}

		public uint GetUserData()
		{
			return this.userdata;
		}

		public override string ToString()
		{
			return string.Format( "[{0}: 0x{1}]", this.GetType().Name, this.userdata.ToString( "X8" ) );
		}

		#endregion

		#region Static methods

		public static IEnumerable<T> GetByType<T>( string elementType ) where T : class
		{
			return Native.Element.GetByType( elementType ).Select( i => Element.FindOrCreate( i ) as T );
		}

		public static Object GetByID( string elementID, int index = 0 )
		{
			UInt32 userdata = Native.Element.GetByID( elementID, index );

			return userdata != 0 ? Element.FindOrCreate( userdata ) : null;
		}

		public static Object GetByIndex( string type, int index )
		{
			UInt32 userdata = Native.Element.GetByIndex( type, index );

			return userdata != 0 ? Element.FindOrCreate( userdata ) : null;
		}

		#endregion

		#region Events

		#region Event delegates

		public delegate void ElementEventHandler( Element sender, ElementEventArgs e );

		public delegate void ElementEventHandler<TEventArgs>( Element sender, TEventArgs e );

		#endregion

		#region Client events

		/// <summary>
		/// This event is triggered when a player types a message into his console. It is also triggered when entering '/' commands via the chatbox.
		/// </summary>
		public event ElementEventHandler<ConsoleEventArgs> OnConsole;

		#endregion

		#region Colshape events

		/// <summary>
		/// This event is triggered when an physical element hits a colshape.
		/// NOTE: The hit won't be detected if the element that entered the colshape is a colshape.
		/// </summary>
		public event ElementEventHandler<ColShapeEventArgs> OnColShapeHit;

		/// <summary>
		/// This event is triggered when a player or a vehicle leaves a collision shape.
		/// </summary>
		public event ElementEventHandler<ColShapeEventArgs> OnColShapeLeave;

		#endregion

		#region Element events
		/// <summary>
		/// This event is triggered when an element gets destroyed by destroyElement or when the creator resource is stopping.
		/// It is also triggered when a parent element of this element is destroyed.
		/// </summary>
		public event ElementEventHandler OnElementDestroy;

		/// <summary>
		/// This event is triggered when an elementdata entry for an element changes.
		/// A client can perform this change on the element or it can be done using setElementData.
		/// </summary>
		public event ElementEventHandler<ElementDataChangeEventArgs> OnElementDataChange;

		/// <summary>
		/// This event is triggered when an player or vehicle element collides with a colshape.
		/// </summary>
		public event ElementEventHandler<ElementColShapeEventArgs> OnElementColShapeHit;

		/// <summary>
		/// This event is triggered when an player or vehicle element leaves the area of a colshape.
		/// </summary>
		public event ElementEventHandler<ElementColShapeEventArgs> OnElementColShapeLeave;

		/// <summary>
		/// This event is triggered when an element is clicked on by the client.
		/// These events can only trigger when the client has its cursor enabled.
		/// It triggers for all three mousebuttons in both their up and down states.
		/// </summary>
		public event ElementEventHandler<ElementClickedEventArgs> OnElementClicked;

		/// <summary>
		/// This event is triggered when an element becomes synced by a player.
		/// </summary>
		public event ElementEventHandler<PlayerEventArgs> OnElementStartSync;

		/// <summary>
		/// This event is triggered when an element is no longer synced by a player.
		/// </summary>
		public event ElementEventHandler<PlayerEventArgs> OnElementStopSync;

		/// <summary>
		/// This event is triggered when the model of an element is changed using setElementModel.
		/// </summary>
		public event ElementEventHandler<ElementModelChangeEventArgs> OnElementModelChange;

		#endregion

		#region Marker events

		/// <summary>
		/// This event is triggered when an element enters a marker.
		/// </summary>
		public event ElementEventHandler<MarkerEventArgs> OnMarkerHit;

		/// <summary>
		/// This event is triggered when an element leaves the area of a marker.
		/// </summary>
		public event ElementEventHandler<MarkerEventArgs> OnMarkerLeave;

		#endregion

		#region Pickup events

		/// <summary>
		/// This event is triggered when a pickup is spawned or respawned.
		/// </summary>
		public event ElementEventHandler OnPickupSpawn;

		/// <summary>
		/// This event is triggered when a player hits a pickup.
		/// </summary>
		public event ElementEventHandler<PlayerCancelEventArgs> OnPickupHit;

		/// <summary>
		/// This event is triggered when a player stands on a pickup while not in a vehicle.
		/// </summary>
		public event ElementEventHandler<PlayerCancelEventArgs> OnPickupUse;

		#endregion

		#region Player events

		/// <summary>
		/// This event is triggered when a player added a ban (like onBan).
		/// </summary>
		public event ElementEventHandler<PlayerBanEventArgs> OnPlayerBan;

		/// <summary>
		/// This event is triggered when a player chats inside the chat box.
		/// </summary>
		public event ElementEventHandler<PlayerChatEventArgs> OnPlayerChat;

		/// <summary>
		/// This event is triggered when a player sends a private message with msg command.
		/// </summary>
		public event ElementEventHandler<PlayerPrivateMessageEventArgs> OnPlayerPrivateMessage;

		/// <summary>
		/// This event is triggered when a player attempts to connect to the server.
		/// </summary>
		public event ElementEventHandler<PlayerConnectEventArgs> OnPlayerConnect;

		/// <summary>
		/// This event is triggered when a player changes his nickname.
		/// </summary>
		public event ElementEventHandler<PlayerChangeNickEventArgs> OnPlayerChangeNick;

		/// <summary>
		/// This event is triggered when a player logs into their account in-game.
		/// </summary>
		public event ElementEventHandler<PlayerLoginEventArgs> OnPlayerLogin;

		/// <summary>
		/// This event is triggered when a user logs out of their account in-game.
		/// </summary>
		public event ElementEventHandler<PlayerLogoutEventArgs> OnPlayerLogout;

		/// <summary>
		/// This event is triggered when a player is damaged, in any way.
		/// </summary>
		public event ElementEventHandler<PlayerDamageEvetArgs> OnPlayerDamage;

		/// <summary>
		/// This event is triggered when a player joins the server.
		/// </summary>
		public event ElementEventHandler OnPlayerJoin;

		/// <summary>
		/// This event is triggered when a player disconnects from the server.
		/// </summary>
		public event ElementEventHandler<PlayerQuitEventArgs> OnPlayerQuit;

		/// <summary>
		/// This event is called when a player spawns.
		/// </summary>
		public event ElementEventHandler<PlayerSpawnEventArgs> OnPlayerSpawn;

		/// <summary>
		/// This event is triggered when a player is killed or dies.
		/// </summary>
		public event ElementEventHandler<PedWastedEventArgs> OnPlayerWasted;

		/// <summary>
		/// This event is triggered when a player targets an element with his crosshair while aiming, or simply facing it while standing close.
		/// It's triggered again when the player no longer targets anything.
		/// </summary>
		public event ElementEventHandler<PlayerTargetEventArgs> OnPlayerTarget;

		/// <summary>
		/// This event is triggered when a player enters a vehicle.
		/// </summary>
		public event ElementEventHandler<PlayerVehicleEnterEventArgs> OnPlayerVehicleEnter;

		/// <summary>
		/// This event is triggered when a player leaves a vehicle, for whatever reason.
		/// </summary>
		public event ElementEventHandler<PlayerVehicleEnterEventArgs> OnPlayerVehicleExit;

		/// <summary>
		/// This event is triggered whenever a player's equipped weapon slot changes.
		/// This means giveWeapon and takeWeapon will trigger this function if the equipped slot is forced to change.
		/// </summary>
		public event ElementEventHandler<PedWeaponSwitchEventArgs> OnPlayerWeaponSwitch;

		/// <summary>
		/// This event is triggered when a player hits a marker.
		/// </summary>
		public event ElementEventHandler<PlayerMarkerEventArgs> OnPlayerMarkerHit;

		/// <summary>
		/// This event is triggered when a player leaves the area of a marker.
		/// </summary>
		public event ElementEventHandler<PlayerMarkerEventArgs> OnPlayerMarkerLeave;

		/// <summary>
		/// This event is triggered when a player hits a pickup.
		/// </summary>
		public event ElementEventHandler<PlayerPickupHitEventArgs> OnPlayerPickupHit;

		/// <summary>
		/// This event is triggered when a player is standing on a pickup while not being in a vehicle.
		/// </summary>
		public event ElementEventHandler<PlayerPickupUseEventArgs> OnPlayerPickupUse;

		/// <summary>
		/// This event is triggered when a player clicks using the mouse cursor.
		/// </summary>
		public event ElementEventHandler<PlayerClickEventArgs> OnPlayerClick;

		/// <summary>
		/// This event is triggered when a player stands on a different element than before.
		/// </summary>
		public event ElementEventHandler<PlayerContactEventArgs> OnPlayerContact;

		/// <summary>
		/// This event is triggered when a player stealth kills another player.
		/// </summary>
		public event ElementEventHandler<PedCancelEventArgs> OnPlayerStealthKill;

		/// <summary>
		/// This event is triggered when a player has been muted by setPlayerMuted.
		/// </summary>
		public event ElementEventHandler<CancelEventArgs> OnPlayerMute;

		/// <summary>
		/// This event is triggered when a player has been unmuted by setPlayerMuted.
		/// </summary>
		public event ElementEventHandler<CancelEventArgs> OnPlayerUnmute;

		/// <summary>
		/// This event is triggered when a player issues a command.
		/// </summary>
		public event ElementEventHandler<PlayerCommandEventArgs> OnPlayerCommand;

		/// <summary>
		/// This event is triggered when a player has modified certain files.
		/// </summary>
		public event ElementEventHandler<PlayerModInfoEventArgs> OnPlayerModInfo;

		/// <summary>
		/// This event is triggered when a player starts talking through voice chat.
		/// </summary>
		public event ElementEventHandler<CancelEventArgs> OnPlayerVoiceStart;

		/// <summary>
		/// This event is triggered when a player stops talking through voice chat
		/// </summary>
		public event ElementEventHandler OnPlayerVoiceStop;

		/// <summary>
		/// This event is triggered when the screen capture requested by takePlayerScreenShot has completed.
		/// </summary>
		public event ElementEventHandler<PlayerScreenShotEventArgs> OnPlayerScreenShot;

		#endregion

		#region Ped events

		/// <summary>
		/// This event is triggered when a ped is killed or dies. It is not triggered for players.
		/// </summary>
		public event ElementEventHandler<PedWastedEventArgs> OnPedWasted;

		/// <summary>
		/// This event is triggered when a ped switches weapons.
		/// </summary>
		public event ElementEventHandler<PedWeaponSwitchEventArgs> OnPedWeaponSwitch;

		#endregion

		#region Resource events

		/// <summary>
		/// This event is triggered when a resource is started.
		/// </summary>
		public event ElementEventHandler<ResourceEventArgs> OnResourceStart;

		/// <summary>
		/// Analogous to onResourceStart, but triggered before script files are initialised.
		/// </summary>
		public event ElementEventHandler<ResourceEventArgs> OnResourcePreStart;

		/// <summary>
		/// This event is triggered when the resource is stopped. This can occur for a number of reasons:
		/// * The stop console command was used
		/// * The restart console command was used
		/// * The resource was modified (the resource will automatically restart)
		/// * Another resource stopped it using stopResource.
		/// </summary>
		public event ElementEventHandler<ResourceEventArgs> OnResourceStop;

		#endregion

		#region Server events

		public event ElementEventHandler<BanEventArgs> OnBan;
		public event ElementEventHandler<DebugMessageEventArgs> OnDebugMessage;
		public event ElementEventHandler<SettingChangeEventArgs> OnSettingChange;
		public event ElementEventHandler<AccountDataChangeEventArgs> OnAccountDataChange;
		public event ElementEventHandler<UnbanEventArgs> OnUnban;
		public event ElementEventHandler<ChatMessageEventArgs> OnChatMessage;

		#endregion

		#region Vehicle events

		public event ElementEventHandler<VehicleEventArgs> OnTrailerAttach;
		public event ElementEventHandler<VehicleEventArgs> OnTrailerDetach;
		public event ElementEventHandler<VehicleDamageEventArgs> OnVehicleDamage;
		public event ElementEventHandler<VehicleRespawnEventArgs> OnVehicleRespawn;
		public event ElementEventHandler<VehicleStartEnterEventArgs> OnVehicleStartEnter;
		public event ElementEventHandler<VehicleStartEnterEventArgs> OnVehicleStartExit;
		public event ElementEventHandler<VehicleEnterEventArgs> OnVehicleEnter;
		public event ElementEventHandler<VehicleEnterEventArgs> OnVehicleExit;
		public event ElementEventHandler OnVehicleExplode;

		#endregion

		#region Weapon events

		public event ElementEventHandler<CancelEventArgs> OnWeaponFire;

		#endregion

		#endregion

		#region Event raisers

		#region Client events

		private void raise_OnConsole( Player sender, string message )
		{
			if( this.OnConsole != null )
			{
				this.OnConsole( sender, new ConsoleEventArgs( this, message ) );
			}
		}

		#endregion

		#region Colshape events

		private void raise_OnColShapeHit( Element sender, Element hitElement, bool matchingDimension )
		{
			if( this.OnColShapeHit != null )
			{
				this.OnColShapeHit( sender, new ColShapeEventArgs( this, hitElement, matchingDimension ) );
			}
		}

		private void raise_OnColShapeLeave( Element sender, Element hitElement, bool matchingDimension )
		{
			if( this.OnColShapeLeave != null )
			{
				this.OnColShapeLeave( sender, new ColShapeEventArgs( this, hitElement, matchingDimension ) );
			}
		}

		#endregion

		#region Element events

		private void raise_OnElementDestroy( Element sender )
		{
			if( this.OnElementDestroy != null )
			{
				this.OnElementDestroy( sender, new ElementEventArgs( this ) );
			}
		}

		private void raise_OnElementDataChange( Element sender, Player client, string name, dynamic oldValue )
		{
			if( this.OnElementDataChange != null )
			{
				this.OnElementDataChange( sender, new ElementDataChangeEventArgs( this, client, name, oldValue ) );
			}
		}

		private void raise_OnElementColShapeHit( Element sender, ColShape colShape, bool matchingDimension )
		{
			if( this.OnElementColShapeHit != null )
			{
				this.OnElementColShapeHit( sender, new ElementColShapeEventArgs( this, colShape, matchingDimension ) );
			}
		}

		private void raise_OnElementColShapeLeave( Element sender, ColShape colShape, bool matchingDimension )
		{
			if( this.OnElementColShapeLeave != null )
			{
				this.OnElementColShapeLeave( sender, new ElementColShapeEventArgs( this, colShape, matchingDimension ) );
			}
		}

		private void raise_OnElementClicked( Element sender, string mouseButton, string buttonState, Player whoClicked, float clickPosX, float clickPosY, float clickPosZ )
		{
			if( this.OnElementClicked != null )
			{
				this.OnElementClicked( sender, new ElementClickedEventArgs( this, mouseButton, buttonState, whoClicked, clickPosX, clickPosY, clickPosZ ) );
			}
		}

		private void raise_OnElementStartSync( Element sender, Player newSyncer )
		{
			if( this.OnElementStartSync != null )
			{
				this.OnElementStartSync( sender, new PlayerEventArgs( this, newSyncer ) );
			}
		}

		private void raise_OnElementStopSync( Element sender, Player player )
		{
			if( this.OnElementStopSync != null )
			{
				this.OnElementStopSync( sender, new PlayerEventArgs( this, player ) );
			}
		}

		private void raise_OnElementModelChange( Element sender, int oldModel, int newModel )
		{
			if( this.OnElementModelChange != null )
			{
				this.OnElementModelChange( sender, new ElementModelChangeEventArgs( this, oldModel, newModel ) );
			}
		}

		#endregion

		#region Marker events

		private void raise_OnMarkerHit( Element sender, Element element, bool matchingDimension )
		{
			if( this.OnMarkerHit != null )
			{
				this.OnMarkerHit( sender, new MarkerEventArgs( this, element, matchingDimension ) );
			}
		}

		private void raise_OnMarkerLeave( Element sender, Element element, bool matchingDimension )
		{
			if( this.OnMarkerLeave != null )
			{
				this.OnMarkerLeave( sender, new MarkerEventArgs( this, element, matchingDimension ) );
			}
		}


		#endregion

		#region Pickup events

		private void raise_OnPickupSpawn( Element sender )
		{
			if( this.OnPickupSpawn != null )
			{
				this.OnPickupSpawn( sender, new ElementEventArgs( this ) );
			}
		}
		private void raise_OnPickupHit( Element sender, Player player )
		{
			if( this.OnPickupHit != null )
			{
				this.OnPickupHit( sender, new PlayerCancelEventArgs( this, player ) );
			}
		}
		private void raise_OnPickupUse( Element sender, Player player )
		{
			if( this.OnPickupUse != null )
			{
				this.OnPickupUse( sender, new PlayerCancelEventArgs( this, player ) );
			}
		}

		#endregion

		#region Player events

		private void raise_OnPlayerBan( Element sender, Ban banPointer, Player responsibleElement )
		{
			if( this.OnPlayerBan != null )
			{
				this.OnPlayerBan( sender, new PlayerBanEventArgs( this, banPointer, responsibleElement ) );
			}
		}

		private void raise_OnPlayerChat( Element sender, string message, int messageType )
		{
			if( this.OnPlayerChat != null )
			{
				this.OnPlayerChat( sender, new PlayerChatEventArgs( this, message, messageType ) );
			}
		}

		private void raise_OnPlayerPrivateMessage( Element sender, string message, Player recipient )
		{
			if( this.OnPlayerPrivateMessage != null )
			{
				this.OnPlayerPrivateMessage( sender, new PlayerPrivateMessageEventArgs( this, message, recipient ) );
			}
		}

		private void raise_OnPlayerConnect( Element sender, string nick, string ip, string username, string serial, int versionNumber, string versionString )
		{
			if( this.OnPlayerConnect != null )
			{
				this.OnPlayerConnect( sender, new PlayerConnectEventArgs( this, nick, ip, username, serial, versionNumber, versionString ) );
			}
		}

		private void raise_OnPlayerChangeNick( Element sender, string oldNick, string newNick )
		{
			if( this.OnPlayerChangeNick != null )
			{
				this.OnPlayerChangeNick( sender, new PlayerChangeNickEventArgs( this, oldNick, newNick ) );
			}
		}

		private void raise_OnPlayerLogin( Element sender, Account previousAccount, Account currentAccount, bool autoLogin )
		{
			if( this.OnPlayerLogin != null )
			{
				this.OnPlayerLogin( sender, new PlayerLoginEventArgs( this, previousAccount, currentAccount, autoLogin ) );
			}
		}

		private void raise_OnPlayerLogout( Element sender, Account previousAccount, Account currentAccount )
		{
			if( this.OnPlayerLogout != null )
			{
				this.OnPlayerLogout( sender, new PlayerLogoutEventArgs( this, previousAccount, currentAccount ) );
			}
		}

		private void raise_OnPlayerDamage( Element sender, Player attacker, int attackerweapon, int bodypart, float loss )
		{
			if( this.OnPlayerDamage != null )
			{
				this.OnPlayerDamage( sender, new PlayerDamageEvetArgs( this, attacker, attackerweapon, bodypart, loss ) );
			}
		}

		private void raise_OnPlayerJoin( Element sender )
		{
			if( this.OnPlayerJoin != null )
			{
				this.OnPlayerJoin( sender, new ElementEventArgs( this ) );
			}
		}

		private void raise_OnPlayerQuit( Element sender, string type, string reason, Player responsePlayer )
		{
			if( this.OnPlayerQuit != null )
			{
				this.OnPlayerQuit( sender, new PlayerQuitEventArgs( this, type, reason, responsePlayer ) );
			}
		}

		private void raise_OnPlayerSpawn( Element sender, float x, float y, float z, float rotation, Team team, int skin, int interior, int dimension )
		{
			if( this.OnPlayerSpawn != null )
			{
				this.OnPlayerSpawn( sender, new PlayerSpawnEventArgs( this, x, y, z, rotation, team, skin, interior, dimension ) );
			}
		}

		private void raise_OnPlayerWasted( Element sender, int totalAmmo, Element killer, int killerWeapon, int bodypart, bool stealth )
		{
			if( this.OnPlayerWasted != null )
			{
				this.OnPlayerWasted( sender, new PedWastedEventArgs( this, totalAmmo, killer, killerWeapon, bodypart, stealth ) );
			}
		}

		private void raise_OnPlayerTarget( Element sender, Element targettedElement )
		{
			if( this.OnPlayerTarget != null )
			{
				this.OnPlayerTarget( sender, new PlayerTargetEventArgs( this, targettedElement ) );
			}
		}

		private void raise_OnPlayerVehicleEnter( Element sender, Vehicle vehicle, int seat, Player jacker )
		{
			if( this.OnPlayerVehicleEnter != null )
			{
				this.OnPlayerVehicleEnter( sender, new PlayerVehicleEnterEventArgs( this, vehicle, seat, jacker ) );
			}
		}

		private void raise_OnPlayerVehicleExit( Element sender, Vehicle vehicle, int seat, Player jacker )
		{
			if( this.OnPlayerVehicleExit != null )
			{
				this.OnPlayerVehicleExit( sender, new PlayerVehicleEnterEventArgs( this, vehicle, seat, jacker ) );
			}
		}

		private void raise_OnPlayerWeaponSwitch( Element sender, int previousWeaponID, int currentWeaponID )
		{
			if( this.OnPlayerWeaponSwitch != null )
			{
				this.OnPlayerWeaponSwitch( sender, new PedWeaponSwitchEventArgs( this, previousWeaponID, currentWeaponID ) );
			}
		}

		private void raise_OnPlayerMarkerHit( Element sender, Marker marker, bool matchingDimension )
		{
			if( this.OnPlayerMarkerHit != null )
			{
				this.OnPlayerMarkerHit( sender, new PlayerMarkerEventArgs( this, marker, matchingDimension ) );
			}
		}

		private void raise_OnPlayerMarkerLeave( Element sender, Marker marker, bool matchingDimension )
		{
			if( this.OnPlayerMarkerLeave != null )
			{
				this.OnPlayerMarkerLeave( sender, new PlayerMarkerEventArgs( this, marker, matchingDimension ) );
			}
		}

		private void raise_OnPlayerPickupHit( Element sender, Pickup pickup, bool matchingDimension )
		{
			if( this.OnPlayerPickupHit != null )
			{
				this.OnPlayerPickupHit( sender, new PlayerPickupHitEventArgs( this, pickup, matchingDimension ) );
			}
		}

		private void raise_OnPlayerPickupUse( Element sender, Pickup pickup )
		{
			if( this.OnPlayerPickupUse != null )
			{
				this.OnPlayerPickupUse( sender, new PlayerPickupUseEventArgs( this, pickup ) );
			}
		}

		private void raise_OnPlayerClick( Element sender, string mouseButton, string buttonState, Element clickedElement, float worldX, float worldY, float worldZ, float screenX, float screenY )
		{
			if( this.OnPlayerClick != null )
			{
				this.OnPlayerClick( sender, new PlayerClickEventArgs( this, mouseButton, buttonState, clickedElement, worldX, worldY, worldZ, screenX, screenY ) );
			}
		}

		private void raise_OnPlayerContact( Element sender, Element previous, Element current )
		{
			if( this.OnPlayerContact != null )
			{
				this.OnPlayerContact( sender, new PlayerContactEventArgs( this, previous, current ) );
			}
		}

		private void raise_OnPlayerStealthKill( Element sender, Ped ped )
		{
			if( this.OnPlayerStealthKill != null )
			{
				this.OnPlayerStealthKill( sender, new PedCancelEventArgs( this, ped ) );
			}
		}

		private void raise_OnPlayerMute( Element sender )
		{
			if( this.OnPlayerMute != null )
			{
				this.OnPlayerMute( sender, new CancelEventArgs( this ) );
			}
		}

		private void raise_OnPlayerUnmute( Element sender )
		{
			if( this.OnPlayerUnmute != null )
			{
				this.OnPlayerUnmute( sender, new CancelEventArgs( this ) );
			}
		}

		private void raise_OnPlayerCommand( Element sender, string command )
		{
			if( this.OnPlayerCommand != null )
			{
				this.OnPlayerCommand( sender, new PlayerCommandEventArgs( this, command ) );
			}
		}

		private void raise_OnPlayerModInfo( Element sender, string filename, PlayerModInfo [] list )
		{
			if( this.OnPlayerModInfo != null )
			{
				this.OnPlayerModInfo( sender, new PlayerModInfoEventArgs( this, filename, list ) );
			}
		}

		private void raise_OnPlayerVoiceStart( Element sender )
		{
			if( this.OnPlayerVoiceStart != null )
			{
				this.OnPlayerVoiceStart( sender, new CancelEventArgs( this ) );
			}
		}

		private void raise_OnPlayerVoiceStop( Element sender )
		{
			if( this.OnPlayerVoiceStop != null )
			{
				this.OnPlayerVoiceStop( sender, new ElementEventArgs( this ) );
			}
		}

		private void raise_OnPlayerScreenShot( Element sender, Resource resource, string status, string imageData, int timestamp, string tag )
		{
			if( this.OnPlayerScreenShot != null )
			{
				this.OnPlayerScreenShot( sender, new PlayerScreenShotEventArgs( this, resource, status, imageData, timestamp, tag ) );
			}
		}

		#endregion

		#region Ped events

		private void raise_OnPedWasted( Element sender, int totalAmmo, Element killer, int killerWeapon, int bodypart, bool stealth )
		{
			if( this.OnPedWasted != null )
			{
				this.OnPedWasted( sender, new PedWastedEventArgs( this, totalAmmo, killer, killerWeapon, bodypart, stealth ) );
			}
		}

		private void raise_OnPedWeaponSwitch( Element sender, int previousWeaponID, int currentWeaponID )
		{
			if( this.OnPedWeaponSwitch != null )
			{
				this.OnPedWeaponSwitch( sender, new PedWeaponSwitchEventArgs( this, previousWeaponID, currentWeaponID ) );
			}
		}

		#endregion

		#region Resource events

		private void raise_OnResourceStart( Element sender, Resource resource )
		{
			if( this.OnResourceStart != null )
			{
				this.OnResourceStart( sender, new ResourceEventArgs( this, resource ) );
			}
		}

		private void raise_OnResourcePreStart( Element sender, Resource resource )
		{
			if( this.OnResourcePreStart != null )
			{
				this.OnResourcePreStart( sender, new ResourceEventArgs( this, resource ) );
			}
		}

		private void raise_OnResourceStop( Element sender, Resource resource )
		{
			if( this.OnResourceStop != null )
			{
				this.OnResourceStop( sender, new ResourceEventArgs( this, resource ) );
			}
		}

		#endregion

		#region Server events

		private void raise_OnBan( Element sender, Ban ban )
		{
			if( this.OnBan != null )
			{
				this.OnBan( sender, new BanEventArgs( this, ban ) );
			}
		}

		private void raise_OnDebugMessage( Element sender, string message, int level, string file, int line )
		{
			if( this.OnDebugMessage != null )
			{
				this.OnDebugMessage( sender, new DebugMessageEventArgs( this, message, level, file, line ) );
			}
		}

		private void raise_OnSettingChange( Element sender, string setting, string oldValue, string newValue )
		{
			if( this.OnSettingChange != null )
			{
				this.OnSettingChange( sender, new SettingChangeEventArgs( this, setting, oldValue, newValue ) );
			}
		}

		private void raise_OnAccountDataChange( Element sender, Account account, string key, dynamic value )
		{
			if( this.OnAccountDataChange != null )
			{
				this.OnAccountDataChange( sender, new AccountDataChangeEventArgs( this, account, key, value ) );
			}
		}

		private void raise_OnUnban( Element sender, Ban ban, Player responsibleElement )
		{
			if( this.OnUnban != null )
			{
				this.OnUnban( sender, new UnbanEventArgs( this, ban, responsibleElement ) );
			}
		}

		private void raise_OnChatMessage( Element sender, string message, Element element )
		{
			if( this.OnChatMessage != null )
			{
				this.OnChatMessage( sender, new ChatMessageEventArgs( this, message, element ) );
			}
		}
		
		private void raise_OnChatMessage( Element sender, string message, Resource resource )
		{
			if( this.OnChatMessage != null )
			{
				this.OnChatMessage( sender, new ChatMessageEventArgs( this, message, resource ) );
			}
		}

		#endregion

		#region Vehicle events

		private void raise_OnTrailerAttach( Element sender, Vehicle vehicle )
		{
			if( this.OnTrailerAttach != null )
			{
				this.OnTrailerAttach( sender, new VehicleEventArgs( this, vehicle ) );
			}
		}

		private void raise_OnTrailerDetach( Element sender, Vehicle vehicle )
		{
			if( this.OnTrailerDetach != null )
			{
				this.OnTrailerDetach( sender, new VehicleEventArgs( this, vehicle ) );
			}
		}

		private void raise_OnVehicleDamage( Element sender, float loss )
		{
			if( this.OnVehicleDamage != null )
			{
				this.OnVehicleDamage( sender, new VehicleDamageEventArgs( this, loss ) );
			}
		}

		private void raise_OnVehicleRespawn( Element sender, bool exploded )
		{
			if( this.OnVehicleRespawn != null )
			{
				this.OnVehicleRespawn( sender, new VehicleRespawnEventArgs( this, exploded ) );
			}
		}

		private void raise_OnVehicleStartEnter( Element sender, Player player, int seat, Player jacked, int door )
		{
			if( this.OnVehicleStartEnter != null )
			{
				this.OnVehicleStartEnter( sender, new VehicleStartEnterEventArgs( this, player, seat, jacked, door ) );
			}
		}

		private void raise_OnVehicleStartExit( Element sender, Player player, int seat, Player jacked, int door )
		{
			if( this.OnVehicleStartExit != null )
			{
				this.OnVehicleStartExit( sender, new VehicleStartEnterEventArgs( this, player, seat, jacked, door ) );
			}
		}

		private void raise_OnVehicleEnter( Element sender, Player player, int seat, Player jacked )
		{
			if( this.OnVehicleEnter != null )
			{
				this.OnVehicleEnter( sender, new VehicleEnterEventArgs( this, player, seat, jacked ) );
			}
		}

		private void raise_OnVehicleExit( Element sender, Player player, int seat, Player jacked )
		{
			if( this.OnVehicleExit != null )
			{
				this.OnVehicleExit( sender, new VehicleEnterEventArgs( this, player, seat, jacked ) );
			}
		}

		private void raise_OnVehicleExplode( Element sender )
		{
			if( this.OnVehicleExplode != null )
			{
				this.OnVehicleExplode( sender, new ElementEventArgs( this ) );
			}
		}

		#endregion

		#region Weapon events

		private void raise_OnWeaponFire( Element sender )
		{
			if( this.OnWeaponFire != null )
			{
				this.OnWeaponFire( sender, new CancelEventArgs( this ) );
			}
		}

		#endregion

		#endregion
	}
}
