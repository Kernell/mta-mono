/*********************************************************
*
*  Copyright © 2013, Innovation Roleplay Engine. 
*
*  All Rights Reserved.
*
*  Redistribution and use in source and binary forms,
*  with or without modification,
*  is permitted only for authors.
*
*********************************************************/

#include "CMonoFunctions.h"

void CMonoFunctions::AddInternals( void )
{
	mono_add_internal_call( "MultiTheftAuto.Debug::Log",						CMonoFunctions::Debug::Log );
	mono_add_internal_call( "MultiTheftAuto.Debug::Info",						CMonoFunctions::Debug::Info );
	mono_add_internal_call( "MultiTheftAuto.Debug::Error",						CMonoFunctions::Debug::Error );

	MONO_DECLARE( Config, Get );
	MONO_DECLARE( Config, Set );

	MONO_DECLARE( Server, GetMaxPlayers );
	MONO_DECLARE( Server, SetMaxPlayers );
	MONO_DECLARE( Server, OutputChatBox );
	MONO_DECLARE( Server, OutputConsole );
	MONO_DECLARE( Server, SetPassword );
	MONO_DECLARE( Server, GetVersion );

	MONO_DECLARE( Game, GetType );
	MONO_DECLARE( Game, GetMapName );

	MONO_DECLARE( Game, SetType );
	MONO_DECLARE( Game, SetMapName );
	MONO_DECLARE( Game, GetRuleValue );
	MONO_DECLARE( Game, SetRuleValue );
	MONO_DECLARE( Game, RemoveRuleValue );

	MONO_DECLARE( Event, AddHandler );

	// Element create/destroy
	MONO_DECLARE( Element, Create );
	MONO_DECLARE( Element, Destroy );
	MONO_DECLARE( Element, Clone );

	// Element get funcs
	MONO_DECLARE( Element, GetRootElement );

	MONO_DECLARE( Element, GetByType );
	MONO_DECLARE( Element, IsElement );
	MONO_DECLARE( Element, GetType );
	MONO_DECLARE( Element, GetByID );
	MONO_DECLARE( Element, GetByIndex );
	MONO_DECLARE( Element, GetChild );
	MONO_DECLARE( Element, GetChildrenCount );
	MONO_DECLARE( Element, GetID );
	MONO_DECLARE( Element, GetParent );
	MONO_DECLARE( Element, GetPosition );
	MONO_DECLARE( Element, GetRotation );
	MONO_DECLARE( Element, GetVelocity );
	MONO_DECLARE( Element, GetInterior );
	MONO_DECLARE( Element, IsWithinColShape );
	MONO_DECLARE( Element, IsWithinMarker );
	MONO_DECLARE( Element, GetDimension );
	MONO_DECLARE( Element, GetZoneName );
	MONO_DECLARE( Element, IsAttached );
	MONO_DECLARE( Element, GetAttachedTo );
	MONO_DECLARE( Element, GetColShape );
	MONO_DECLARE( Element, GetAlpha );
	MONO_DECLARE( Element, IsDoubleSided );
	MONO_DECLARE( Element, GetHealth );
	MONO_DECLARE( Element, GetModel );
	MONO_DECLARE( Element, IsInWater );
	MONO_DECLARE( Element, GetAttachedOffsetPosition );
	MONO_DECLARE( Element, GetAttachedOffsetRotation );
	MONO_DECLARE( Element, GetSyncer );
	MONO_DECLARE( Element, GetCollisionsEnabled );
	MONO_DECLARE( Element, IsFrozen );
	MONO_DECLARE( Element, GetLowLod );
	MONO_DECLARE( Element, IsLowLod );

	// Element set funcs
	MONO_DECLARE( Element, ClearVisibleTo );
	MONO_DECLARE( Element, SetID );
	MONO_DECLARE( Element, SetData );
	MONO_DECLARE( Element, RemoveData );
	MONO_DECLARE( Element, SetParent );
	MONO_DECLARE( Element, SetPosition );
	MONO_DECLARE( Element, SetRotation );
	MONO_DECLARE( Element, SetVelocity );
	MONO_DECLARE( Element, SetVisibleTo );
	MONO_DECLARE( Element, SetInterior );
	MONO_DECLARE( Element, SetDimension );
	MONO_DECLARE( Element, Attach );
	MONO_DECLARE( Element, Detach );
	MONO_DECLARE( Element, SetAlpha );
	MONO_DECLARE( Element, SetDoubleSided );
	MONO_DECLARE( Element, SetHealth );
	MONO_DECLARE( Element, SetModel );
	MONO_DECLARE( Element, SetAttachedOffsets );
	MONO_DECLARE( Element, SetSyncer );
	MONO_DECLARE( Element, SetCollisionsEnabled );
	MONO_DECLARE( Element, SetFrozen );
	MONO_DECLARE( Element, SetLowLod );

	// Player get functions
	MONO_DECLARE( Player, GetCount );
	MONO_DECLARE( Player, GetFromName );
	MONO_DECLARE( Player, GetPing );
	MONO_DECLARE( Player, GetMoney );
	MONO_DECLARE( Player, GetRandom );
	MONO_DECLARE( Player, IsMuted );
	MONO_DECLARE( Player, GetTeam );
	MONO_DECLARE( Player, GetWantedLevel );
	MONO_DECLARE( Player, GetAlivePlayers );
	MONO_DECLARE( Player, GetDeadPlayers );
	MONO_DECLARE( Player, GetIdleTime );
	MONO_DECLARE( Player, IsMapForced );
	MONO_DECLARE( Player, GetNametagText );
	MONO_DECLARE( Player, GetNametagColor );
	MONO_DECLARE( Player, IsNametagShowing );
	MONO_DECLARE( Player, GetSerial );
	MONO_DECLARE( Player, GetUserName );
	MONO_DECLARE( Player, GetBlurLevel );
	MONO_DECLARE( Player, GetName );
	MONO_DECLARE( Player, GetIP );
	MONO_DECLARE( Player, GetAccount );
	MONO_DECLARE( Player, GetVersion );
	MONO_DECLARE( Player, GetACInfo );
	MONO_DECLARE( Player, GetPlayerAnnounceValue );

	// Player set functions
	MONO_DECLARE( Player, SetMoney );
	MONO_DECLARE( Player, GiveMoney );
	MONO_DECLARE( Player, TakeMoney );
	MONO_DECLARE( Player, Spawn );
	MONO_DECLARE( Player, ShowHudComponent );
	MONO_DECLARE( Player, SetWantedLevel );
	MONO_DECLARE( Player, ForceMap );
	MONO_DECLARE( Player, SetNametagText );
	MONO_DECLARE( Player, SetNametagColor );
	MONO_DECLARE( Player, SetNametagShowing );
	MONO_DECLARE( Player, SetMuted );
	MONO_DECLARE( Player, SetBlurLevel );
	MONO_DECLARE( Player, Redirect );
	MONO_DECLARE( Player, SetName );
	MONO_DECLARE( Player, DetonateSatchels );
	MONO_DECLARE( Player, TakeScreenShot );
	MONO_DECLARE( Player, SetTeam );
	MONO_DECLARE( Player, SetPlayerAnnounceValue );

	// Input funcs
	MONO_DECLARE( Player, BindKey );
	MONO_DECLARE( Player, UnbindKey );
	MONO_DECLARE( Player, GetControlState );
	MONO_DECLARE( Player, IsControlEnabled );
		
	MONO_DECLARE( Player, SetControlState );
	MONO_DECLARE( Player, ToggleControl );
	MONO_DECLARE( Player, ToggleAllControls );

	// Log in/out funcs
	MONO_DECLARE( Player, LogIn );
	MONO_DECLARE( Player, LogOut );

	// Admin funcs
	MONO_DECLARE( Player, Kick );
	MONO_DECLARE( Player, Ban );
		
	// Cursor get funcs
	MONO_DECLARE( Player, IsCursorShowing );
		
	// Cursor set funcs
	MONO_DECLARE( Player, ShowCursor );
		
	// Chat funcs
	MONO_DECLARE( Player, ShowChat );

	// Camera get functions
	MONO_DECLARE( Player, GetCameraMatrix );
	MONO_DECLARE( Player, GetCameraTarget );
	MONO_DECLARE( Player, GetCameraInterior );

	// Camera set functions
	MONO_DECLARE( Player, SetCameraMatrix );
	MONO_DECLARE( Player, SetCameraTarget );
	MONO_DECLARE( Player, SetCameraInterior );
	MONO_DECLARE( Player, FadeCamera );

	// Ped get functions
	MONO_DECLARE( Ped, Create );
	MONO_DECLARE( Ped, GetArmor );    
	MONO_DECLARE( Ped, IsChoking );
	MONO_DECLARE( Ped, IsDead );
	MONO_DECLARE( Ped, IsDucked );    
	MONO_DECLARE( Ped, GetStat );
	MONO_DECLARE( Ped, GetTarget );    
	MONO_DECLARE( Ped, GetWeapon );
	MONO_DECLARE( Ped, GetClothesTexture );
	MONO_DECLARE( Ped, GetClothesModel );
	MONO_DECLARE( Ped, DoesHaveJetPack );
	MONO_DECLARE( Ped, IsOnGround );    
	MONO_DECLARE( Ped, GetFightingStyle );
	MONO_DECLARE( Ped, GetMoveAnim );
	MONO_DECLARE( Ped, GetGravity );    
	MONO_DECLARE( Ped, GetContactElement );
	MONO_DECLARE( Ped, GetWeaponSlot );
	MONO_DECLARE( Ped, IsDoingGangDriveby );
	MONO_DECLARE( Ped, IsOnFire );
	MONO_DECLARE( Ped, IsHeadless );
	MONO_DECLARE( Ped, IsFrozen );
	MONO_DECLARE( Ped, GetOccupiedVehicle );
	MONO_DECLARE( Ped, GetOccupiedVehicleSeat );
	MONO_DECLARE( Ped, IsInVehicle );
	MONO_DECLARE( Ped, GetWeaponProperty );
	MONO_DECLARE( Ped, GetOriginalWeaponProperty );

	// Ped set functions
	MONO_DECLARE( Ped, SetArmor );
	MONO_DECLARE( Ped, Kill );
	MONO_DECLARE( Ped, SetStat );
	MONO_DECLARE( Ped, AddClothes );
	MONO_DECLARE( Ped, RemoveClothes );
	MONO_DECLARE( Ped, GiveJetPack );
	MONO_DECLARE( Ped, RemoveJetPack );
	MONO_DECLARE( Ped, SetFightingStyle );
	MONO_DECLARE( Ped, SetMoveAnim );
	MONO_DECLARE( Ped, SetGravity );
	MONO_DECLARE( Ped, SetChoking );
	MONO_DECLARE( Ped, SetWeaponSlot );
	MONO_DECLARE( Ped, WarpIntoVehicle );
	MONO_DECLARE( Ped, RemoveFromVehicle );
	MONO_DECLARE( Ped, SetDoingGangDriveby );
	MONO_DECLARE( Ped, SetAnimation );
	MONO_DECLARE( Ped, SetAnimationProgress );
	MONO_DECLARE( Ped, SetOnFire );
	MONO_DECLARE( Ped, SetHeadless );
	MONO_DECLARE( Ped, SetFrozen );
	MONO_DECLARE( Ped, ReloadWeapon );
	MONO_DECLARE( Ped, SetWeaponProperty );

	// Ped body?
	MONO_DECLARE( Ped, GetBodyPartName );
	MONO_DECLARE( Ped, GetClothesByTypeIndex );
	MONO_DECLARE( Ped, GetTypeIndexFromClothes );
	MONO_DECLARE( Ped, GetClothesTypeName );

	// Weapon give/take functions
	MONO_DECLARE( Ped, GiveWeapon );
	MONO_DECLARE( Ped, TakeWeapon );
	MONO_DECLARE( Ped, TakeAllWeapons );
	MONO_DECLARE( Ped, SetWeaponAmmo );

	// Vehicle create/destroy functions
	MONO_DECLARE( Vehicle, Create );

	// Vehicle get functions
	MONO_DECLARE( Vehicle, GetType );
	MONO_DECLARE( Vehicle, GetVariant );
	MONO_DECLARE( Vehicle, GetColor );
	MONO_DECLARE( Vehicle, GetModelFromName );
	MONO_DECLARE( Vehicle, GetLandingGearDown );
	MONO_DECLARE( Vehicle, GetMaxPassengers );
	MONO_DECLARE( Vehicle, GetName );
	MONO_DECLARE( Vehicle, GetNameFromModel );
	MONO_DECLARE( Vehicle, GetOccupant );
	MONO_DECLARE( Vehicle, GetOccupants );
	MONO_DECLARE( Vehicle, GetController );
	MONO_DECLARE( Vehicle, GetSirensOn );
	MONO_DECLARE( Vehicle, GetTurnVelocity );
	MONO_DECLARE( Vehicle, GetTurretPosition );
	MONO_DECLARE( Vehicle, IsLocked );
	MONO_DECLARE( Vehicle, GetOfType );       
	MONO_DECLARE( Vehicle, GetUpgradeOnSlot );
	MONO_DECLARE( Vehicle, GetUpgrades );
//	MONO_DECLARE( Vehicle, GetUpgradeSlotName );
	MONO_DECLARE( Vehicle, GetUpgradeSlotName );
	MONO_DECLARE( Vehicle, GetCompatibleUpgrades );
	MONO_DECLARE( Vehicle, GetDoorState );
	MONO_DECLARE( Vehicle, GetWheelStates );
	MONO_DECLARE( Vehicle, GetLightState );
	MONO_DECLARE( Vehicle, GetPanelState );
	MONO_DECLARE( Vehicle, GetOverrideLights );
	MONO_DECLARE( Vehicle, GetTowedByVehicle );
	MONO_DECLARE( Vehicle, GetTowingVehicle );
	MONO_DECLARE( Vehicle, GetPaintjob );
	MONO_DECLARE( Vehicle, GetPlateText );
	MONO_DECLARE( Vehicle, IsDamageProof );
	MONO_DECLARE( Vehicle, IsFuelTankExplodable );
	MONO_DECLARE( Vehicle, IsFrozen );
	MONO_DECLARE( Vehicle, IsOnGround );
	MONO_DECLARE( Vehicle, GetEngineState );
	MONO_DECLARE( Vehicle, IsTrainDerailed );
	MONO_DECLARE( Vehicle, IsTrainDerailable );
	MONO_DECLARE( Vehicle, GetTrainDirection );
	MONO_DECLARE( Vehicle, GetTrainSpeed );
	MONO_DECLARE( Vehicle, IsBlown );
	MONO_DECLARE( Vehicle, GetHeadLightColor );
	MONO_DECLARE( Vehicle, GetDoorOpenRatio );
	MONO_DECLARE( Vehicle, IsTaxiLightOn );

	// Vehicle set functions
	MONO_DECLARE( Vehicle, Fix );
	MONO_DECLARE( Vehicle, Blow );
	MONO_DECLARE( Vehicle, SetTurnVelocity );
	MONO_DECLARE( Vehicle, SetColor );
	MONO_DECLARE( Vehicle, SetLandingGearDown );
	MONO_DECLARE( Vehicle, SetLocked );
	MONO_DECLARE( Vehicle, SetDoorsUndamageable );
	MONO_DECLARE( Vehicle, SetSirensOn );
	MONO_DECLARE( Vehicle, SetTaxiLightOn );
	MONO_DECLARE( Vehicle, AddUpgrade );
	MONO_DECLARE( Vehicle, RemoveUpgrade );
	MONO_DECLARE( Vehicle, SetDoorState );
	MONO_DECLARE( Vehicle, SetWheelStates );
	MONO_DECLARE( Vehicle, SetLightState );
	MONO_DECLARE( Vehicle, SetPanelState );
	MONO_DECLARE( Vehicle, SetIdleRespawnDelay );
	MONO_DECLARE( Vehicle, SetRespawnDelay );
	MONO_DECLARE( Vehicle, SetRespawnPosition );
	MONO_DECLARE( Vehicle, ToggleRespawn );
	MONO_DECLARE( Vehicle, ResetExplosionTime );
	MONO_DECLARE( Vehicle, ResetIdleTime );
	MONO_DECLARE( Vehicle, Spawn );
	MONO_DECLARE( Vehicle, Respawn );
	MONO_DECLARE( Vehicle, SetOverrideLights );
	MONO_DECLARE( Vehicle, AttachTrailer );
	MONO_DECLARE( Vehicle, DetachTrailer );
	MONO_DECLARE( Vehicle, SetEngineState );
	MONO_DECLARE( Vehicle, SetDirtLevel );
	MONO_DECLARE( Vehicle, SetDamageProof );
	MONO_DECLARE( Vehicle, SetPaintjob );
	MONO_DECLARE( Vehicle, SetFuelTankExplodable );
	MONO_DECLARE( Vehicle, SetTrainDerailed );
	MONO_DECLARE( Vehicle, SetTrainDerailable );
	MONO_DECLARE( Vehicle, SetTrainDirection );
	MONO_DECLARE( Vehicle, SetTrainSpeed );
	MONO_DECLARE( Vehicle, SetHeadLightColor );
	MONO_DECLARE( Vehicle, SetTurretPosition );
	MONO_DECLARE( Vehicle, SetDoorOpenRatio );
	MONO_DECLARE( Vehicle, SetVariant );
	MONO_DECLARE( Vehicle, GiveSirens );
	MONO_DECLARE( Vehicle, RemoveSirens );
	MONO_DECLARE( Vehicle, SetSirens );
	MONO_DECLARE( Vehicle, GetSirens );
	MONO_DECLARE( Vehicle, GetSirenParams );
	MONO_DECLARE( Vehicle, SetPlateText );
	
	// Marker create/destroy functions
	MONO_DECLARE( Marker, Create );

	// Marker get functions
	MONO_DECLARE( Marker, GetCount );
	MONO_DECLARE( Marker, GetType );
	MONO_DECLARE( Marker, GetSize );
	MONO_DECLARE( Marker, GetColor );
	MONO_DECLARE( Marker, GetTarget );
	MONO_DECLARE( Marker, GetIcon );

	// Marker set functions
	MONO_DECLARE( Marker, SetType );
	MONO_DECLARE( Marker, SetSize );
	MONO_DECLARE( Marker, SetColor );
	MONO_DECLARE( Marker, SetTarget );
	MONO_DECLARE( Marker, SetIcon );

	// Blip create/destroy functions
	MONO_DECLARE( Blip, Create );
	MONO_DECLARE( Blip, CreateAttachedTo );
	
	// Blip get functions
	MONO_DECLARE( Blip, GetIcon );
	MONO_DECLARE( Blip, GetSize );
	MONO_DECLARE( Blip, GetColor );
	MONO_DECLARE( Blip, GetOrdering );
	MONO_DECLARE( Blip, GetVisibleDistance );

	// Blip set functions
	MONO_DECLARE( Blip, SetIcon );
	MONO_DECLARE( Blip, SetSize );
	MONO_DECLARE( Blip, SetColor );
	MONO_DECLARE( Blip, SetOrdering );
	MONO_DECLARE( Blip, SetVisibleDistance );

	// Object create/destroy functions
	MONO_DECLARE( Object, Create );

	// Object get functions
	MONO_DECLARE( Object, GetScale );

	// Object set functions
	MONO_DECLARE( Object, SetScale );
	MONO_DECLARE( Object, Move );
	MONO_DECLARE( Object, Stop );

	// Radar area create/destroy funcs
	MONO_DECLARE( RadarArea, Create );

	// Radar area get funcs
	MONO_DECLARE( RadarArea, GetSize );
	MONO_DECLARE( RadarArea, GetColor );
	MONO_DECLARE( RadarArea, IsFlashing );
	MONO_DECLARE( RadarArea, IsInside );

	// Radar area set funcs
	MONO_DECLARE( RadarArea, SetSize );
	MONO_DECLARE( RadarArea, SetColor );
	MONO_DECLARE( RadarArea, SetFlashing );

	// Pickup create/destroy funcs
	MONO_DECLARE( Pickup, Create );

	// Pickup get funcs
	MONO_DECLARE( Pickup, GetType );
	MONO_DECLARE( Pickup, GetWeapon );
	MONO_DECLARE( Pickup, GetAmount );
	MONO_DECLARE( Pickup, GetAmmo );
	MONO_DECLARE( Pickup, GetRespawnInterval );
	MONO_DECLARE( Pickup, IsSpawned );

	// Pickup set funcs
	MONO_DECLARE( Pickup, SetType );
	MONO_DECLARE( Pickup, SetRespawnInterval );
	MONO_DECLARE( Pickup, Use );

	// Shape create funcs
	MONO_DECLARE( Shape, CreateCircle );
	MONO_DECLARE( Shape, CreateCuboid );
	MONO_DECLARE( Shape, CreateSphere );
	MONO_DECLARE( Shape, CreateRectangle );
	MONO_DECLARE( Shape, CreatePolygon );
	MONO_DECLARE( Shape, CreateTube );

	// Explosion funcs
	MONO_DECLARE( Explosion, Create );

	// Audio funcs
	MONO_DECLARE( Audio, PlayFrontEnd );
	MONO_DECLARE( Audio, PlayMission );

	// Team get funcs
	MONO_DECLARE( Team, Create );
	MONO_DECLARE( Team, GetFromName );
	MONO_DECLARE( Team, GetName );
	MONO_DECLARE( Team, GetColor );
	MONO_DECLARE( Team, CountPlayers );
	MONO_DECLARE( Team, GetFriendlyFire );

	// Team set funcs
	MONO_DECLARE( Team, SetName );
	MONO_DECLARE( Team, SetColor );
	MONO_DECLARE( Team, SetFriendlyFire );

	// Water funcs
	MONO_DECLARE( Water, Create );
	MONO_DECLARE( Water, SetLevel );
	MONO_DECLARE( Water, SetLevelAll );
	MONO_DECLARE( Water, SetLevelWorld );
	MONO_DECLARE( Water, ResetLevelWorld );
	MONO_DECLARE( Water, GetVertexPosition );
	MONO_DECLARE( Water, SetVertexPosition );
	MONO_DECLARE( Water, GetColor );
	MONO_DECLARE( Water, SetColor );
	MONO_DECLARE( Water, ResetColor );

	// General world get funcs
	MONO_DECLARE( World, GetTime );
	MONO_DECLARE( World, GetWeather );
	MONO_DECLARE( World, GetZoneName );
	MONO_DECLARE( World, GetGravity );
	MONO_DECLARE( World, GetGameSpeed );
	MONO_DECLARE( World, GetWaveHeight );
	MONO_DECLARE( World, GetFPSLimit );
	MONO_DECLARE( World, GetMinuteDuration );
	MONO_DECLARE( World, IsGarageOpen );
	MONO_DECLARE( World, GetTrafficLightState );
	MONO_DECLARE( World, GetTrafficLightsLocked );
	MONO_DECLARE( World, GetJetpackMaxHeight );
	MONO_DECLARE( World, GetAircraftMaxVelocity );
	MONO_DECLARE( World, GetInteriorSoundsEnabled );
	MONO_DECLARE( World, GetRainLevel );
	MONO_DECLARE( World, GetSunSize );
	MONO_DECLARE( World, GetSunColor );
	MONO_DECLARE( World, GetWindVelocity );
	MONO_DECLARE( World, GetFarClipDistance );
	MONO_DECLARE( World, GetFogDistance );
	MONO_DECLARE( World, GetAircraftMaxHeight );
	MONO_DECLARE( World, GetOcclusionsEnabled );
	MONO_DECLARE( World, GetMoonSize );
	MONO_DECLARE( World, GetSkyGradient );
	MONO_DECLARE( World, GetHeatHaze );
	MONO_DECLARE( World, GetJetpackWeaponEnabled );
	MONO_DECLARE( World, GetCloudsEnabled );

	// General world set funcs
	MONO_DECLARE( World, SetTime );
	MONO_DECLARE( World, SetWeather );
	MONO_DECLARE( World, SetWeatherBlended );
	MONO_DECLARE( World, SetGravity );
	MONO_DECLARE( World, SetGameSpeed );
	MONO_DECLARE( World, SetWaveHeight );
	MONO_DECLARE( World, SetSkyGradient );
	MONO_DECLARE( World, ResetSkyGradient );
	MONO_DECLARE( World, SetHeatHaze );
	MONO_DECLARE( World, ResetHeatHaze );
	MONO_DECLARE( World, SetFPSLimit );
	MONO_DECLARE( World, SetMinuteDuration );
	MONO_DECLARE( World, SetGarageOpen );
	MONO_DECLARE( World, SetGlitchEnabled );
	MONO_DECLARE( World, IsGlitchEnabled );
	MONO_DECLARE( World, SetJetpackWeaponEnabled );
	MONO_DECLARE( World, SetCloudsEnabled );
	MONO_DECLARE( World, SetTrafficLightState );
	MONO_DECLARE( World, SetTrafficLightsLocked );
	MONO_DECLARE( World, SetJetpackMaxHeight );
	MONO_DECLARE( World, SetInteriorSoundsEnabled );
	MONO_DECLARE( World, SetRainLevel );
	MONO_DECLARE( World, SetSunSize );
	MONO_DECLARE( World, SetSunColor );
	MONO_DECLARE( World, SetWindVelocity );
	MONO_DECLARE( World, SetFarClipDistance );
	MONO_DECLARE( World, SetFogDistance );
	MONO_DECLARE( World, SetAircraftMaxHeight );
	MONO_DECLARE( World, SetAircraftMaxVelocity );
	MONO_DECLARE( World, SetOcclusionsEnabled );
	MONO_DECLARE( World, ResetRainLevel );
	MONO_DECLARE( World, ResetSunSize );
	MONO_DECLARE( World, ResetSunColor );
	MONO_DECLARE( World, ResetWindVelocity );
	MONO_DECLARE( World, ResetFarClipDistance );
	MONO_DECLARE( World, ResetFogDistance );
	MONO_DECLARE( World, RemoveWorldModel );
	MONO_DECLARE( World, RestoreWorldModel );
	MONO_DECLARE( World, RestoreAllWorldModels );
	MONO_DECLARE( World, SetMoonSize );
	MONO_DECLARE( World, ResetMoonSize );

	// Account get funcs
	MONO_DECLARE( Account, Get );
	MONO_DECLARE( Account, GetAll );
	MONO_DECLARE( Account, GetPlayer );
	MONO_DECLARE( Account, IsGuest );
//	MONO_DECLARE( Account, GetData );
//	MONO_DECLARE( Account, GetAllData );
	MONO_DECLARE( Account, GetSerial );
//	MONO_DECLARE( Account, GetBySerial );

	// Account set funcs
	MONO_DECLARE( Account, Add );
	MONO_DECLARE( Account, Remove );
	MONO_DECLARE( Account, SetPassword );
//	MONO_DECLARE( Account, SetData );
	MONO_DECLARE( Account, CopyData );

	MONO_DECLARE( Ban, Add );
	MONO_DECLARE( Ban, Remove );

//	MONO_DECLARE( Ban, GetBans );
	MONO_DECLARE( Ban, Reload );

	MONO_DECLARE( Ban, GetIP );
	MONO_DECLARE( Ban, GetSerial );
	MONO_DECLARE( Ban, GetUsername );
	MONO_DECLARE( Ban, GetNick );
	MONO_DECLARE( Ban, GetReason );
	MONO_DECLARE( Ban, GetAdmin );

	MONO_DECLARE( Ban, GetBanTime );
	MONO_DECLARE( Ban, GetUnbanTime );

	MONO_DECLARE( Ban, SetUnbanTime );
	MONO_DECLARE( Ban, SetReason );
	MONO_DECLARE( Ban, SetAdmin );

	// Resource funcs
	MONO_DECLARE( Resource, Create );
	MONO_DECLARE( Resource, Copy );
	MONO_DECLARE( Resource, GetRootElement );
	MONO_DECLARE( Resource, GetMapRootElement );
	MONO_DECLARE( Resource, GetDynamicElementRoot );
//	MONO_DECLARE( Resource, AddMap );
//	MONO_DECLARE( Resource, AddConfig );
	MONO_DECLARE( Resource, RemoveFile );
//	MONO_DECLARE( Resource, AddConfig );
//	MONO_DECLARE( Resource, AddMap );
//	MONO_DECLARE( Resource, GetConfig );
//	MONO_DECLARE( Resource, GetExportedFunctions );
	MONO_DECLARE( Resource, GetFromName );
	MONO_DECLARE( Resource, GetInfo );
	MONO_DECLARE( Resource, GetLastStartTime );
	MONO_DECLARE( Resource, GetLoadFailureReason );
	MONO_DECLARE( Resource, GetLoadTime );
	MONO_DECLARE( Resource, GetName );
	MONO_DECLARE( Resource, GetResources );
	MONO_DECLARE( Resource, GetState );
	MONO_DECLARE( Resource, GetCurrent );
	MONO_DECLARE( Resource, Refresh );
	MONO_DECLARE( Resource, RemoveDefaultSetting );
	MONO_DECLARE( Resource, Start );
	MONO_DECLARE( Resource, Restart );
	MONO_DECLARE( Resource, Stop );
	MONO_DECLARE( Resource, SetDefaultSetting );
//	MONO_DECLARE( Resource, SetDefaultSetting );
//	MONO_DECLARE( Resource, SetDefaultSetting );
	MONO_DECLARE( Resource, SetInfo );
	MONO_DECLARE( Resource, Rename );
	MONO_DECLARE( Resource, Delete );
//	MONO_DECLARE( Resource, GetACLRequests );
	MONO_DECLARE( Resource, UpdateACLRequest );
}

void CMonoFunctions::Debug::Log( MonoString *string )
{
	if( RESOURCE )
	{
		g_pModuleManager->Printf( "%s\n", mono_string_to_utf8( string ) );
	}
}

void CMonoFunctions::Debug::Info( MonoString *string )
{
	if( RESOURCE )
	{
		g_pModuleManager->DebugPrintf( RESOURCE->GetLua(), "%s", mono_string_to_utf8( string ) );
	}
}

void CMonoFunctions::Debug::Error( MonoString *string )
{
	if( RESOURCE )
	{
		

		g_pModuleManager->ErrorPrintf( "%s\n", mono_string_to_utf8( string ) );
	}
}

MonoString *CMonoFunctions::Config::Get( MonoString *msKey )
{
	if( RESOURCE )
	{
		string sValue = CLuaFunctionDefinitions::Get( RESOURCE->GetLua(), mono_string_to_utf8( msKey ) );

		return mono_string_new( mono_domain_get(), sValue.c_str() );
	}

	return mono_string_new( mono_domain_get(), "" );
}

bool CMonoFunctions::Config::Set( MonoString *msKey, MonoString *msValue )
{
	if( RESOURCE )
	{
		const char* szKey	= mono_string_to_utf8( msKey );
		const char* szValue	= mono_string_to_utf8( msValue );

		return CLuaFunctionDefinitions::Set( RESOURCE->GetLua(), szKey, szValue );
	}

	return false;
}

unsigned int CMonoFunctions::Server::GetMaxPlayers( void )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::GetMaxPlayers( RESOURCE->GetLua() );
	}
	
	return 0;
}

bool CMonoFunctions::Server::SetMaxPlayers( unsigned int uiMax )
{
	if( RESOURCE )
	{
		return CLuaFunctionDefinitions::SetMaxPlayers( RESOURCE->GetLua(), uiMax );
	}
	
	return 0;
}

bool CMonoFunctions::Server::OutputChatBox( MonoString* msText, DWORD pElement, MonoObject* mpColor, bool bColorCoded )
{
	if( RESOURCE )
	{
		const char* szText		= mono_string_to_utf8( msText );

		unsigned char ucRed		= CMonoObject::GetPropertyValue< unsigned char >( mpColor, "R" );
		unsigned char ucGreen	= CMonoObject::GetPropertyValue< unsigned char >( mpColor, "G" );
		unsigned char ucBlue	= CMonoObject::GetPropertyValue< unsigned char >( mpColor, "B" );

		return CLuaFunctionDefinitions::OutputChatBox( RESOURCE->GetLua(), szText, (void*)pElement, ucRed, ucGreen, ucBlue, bColorCoded );
	}
	
	return false;
}

bool CMonoFunctions::Server::OutputConsole( MonoString* msText, DWORD pElement )
{
	if( RESOURCE )
	{
		const char* szText		= mono_string_to_utf8( msText );

		return CLuaFunctionDefinitions::OutputConsole( RESOURCE->GetLua(), szText, (void*)pElement );
	}
	
	return false;
}

bool CMonoFunctions::Server::SetPassword( MonoString* msPassword, bool bSave )
{
	if( RESOURCE )
	{
		const char* szPassword		= mono_string_to_utf8( msPassword );

		return CLuaFunctionDefinitions::SetServerPassword( RESOURCE->GetLua(), szPassword, bSave );
	}
	
	return false;
}

MonoObject* CMonoFunctions::Server::GetVersion( void )
{
	if( RESOURCE )
	{
		LuaTable pLuaTable = CLuaFunctionDefinitions::GetVersion( RESOURCE->GetLua() );

		if( !pLuaTable.empty() )
		{
			unsigned long	ulNumber	= pLuaTable[ "number" ]->GetNumber< unsigned long >();
			const char*		szString	= pLuaTable[ "mta" ]->GetString();
			const char*		szName		= pLuaTable[ "name" ]->GetString();
			const char*		szBuildType	= pLuaTable[ "type" ]->GetString();
			unsigned long	ulNetcode	= pLuaTable[ "netcode" ]->GetNumber< unsigned long >();
			const char*		szOS		= pLuaTable[ "os" ]->GetString();
			const char*		szBuildTag	= pLuaTable[ "tag" ]->GetString();
			const char*		szSortable	= pLuaTable[ "sortable" ]->GetString();

			CMonoCorlib* pLib = RESOURCE->GetDomain()->GetCorlib();

			void** args = new gpointer[ 8 ];

			MonoObject* pNumber			= pLib->Class[ "uint64" ]->Box( &ulNumber );
			MonoString* pString			= RESOURCE->GetDomain()->NewString( szString );
			MonoString* pName			= RESOURCE->GetDomain()->NewString( szName );
			MonoString* pBuildType		= RESOURCE->GetDomain()->NewString( szBuildType );
			MonoObject* pNetcode		= pLib->Class[ "uint64" ]->Box( &ulNetcode );
			MonoString* pOS				= RESOURCE->GetDomain()->NewString( szOS );
			MonoString* pBuildTag		= RESOURCE->GetDomain()->NewString( szBuildTag );
			MonoString* pSortable		= RESOURCE->GetDomain()->NewString( szSortable );

			args[ 0 ] = pNumber;
			args[ 1 ] = pString;
			args[ 2 ] = pName;
			args[ 3 ] = pBuildType;
			args[ 4 ] = pNetcode;
			args[ 5 ] = pOS;
			args[ 6 ] = pBuildTag;
			args[ 7 ] = pSortable;

			return RESOURCE->GetDomain()->GetMTALib()->GetClass( "ServerVersion" )->New( args, 8 );
		}
	}

	return NULL;
}

MonoString* CMonoFunctions::Game::GetType( void )
{
	if( RESOURCE )
	{
		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetGameType( RESOURCE->GetLua() ) );
	}

	return NULL;
}

MonoString* CMonoFunctions::Game::GetMapName( void )
{
	if( RESOURCE )
	{
		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetMapName( RESOURCE->GetLua() ) );
	}

	return NULL;
}

bool CMonoFunctions::Game::SetType( MonoString* msGameType )
{
	if( RESOURCE )
	{
		const char* szGameType = mono_string_to_utf8( msGameType );

		return CLuaFunctionDefinitions::SetGameType( RESOURCE->GetLua(), szGameType );
	}

	return false;
}

bool CMonoFunctions::Game::SetMapName( MonoString* msMapName )
{
	if( RESOURCE )
	{
		const char* szMapName = mono_string_to_utf8( msMapName );

		return CLuaFunctionDefinitions::SetMapName( RESOURCE->GetLua(), szMapName );
	}

	return false;
}

MonoString* CMonoFunctions::Game::GetRuleValue( MonoString* msKey )
{
	if( RESOURCE )
	{
		const char* szKey	= mono_string_to_utf8( msKey );

		return RESOURCE->GetDomain()->NewString( CLuaFunctionDefinitions::GetRuleValue( RESOURCE->GetLua(), szKey ) );
	}

	return false;
}

bool CMonoFunctions::Game::SetRuleValue( MonoString* msKey, MonoString* msValue )
{
	if( RESOURCE )
	{
		const char* szKey	= mono_string_to_utf8( msKey );
		const char* szValue	= mono_string_to_utf8( msValue );

		return CLuaFunctionDefinitions::SetRuleValue( RESOURCE->GetLua(), szKey, szValue );
	}

	return false;
}

bool CMonoFunctions::Game::RemoveRuleValue( MonoString* msKey )
{
	if( RESOURCE )
	{
		const char* szKey = mono_string_to_utf8( msKey );

		return CLuaFunctionDefinitions::RemoveRuleValue( RESOURCE->GetLua(), szKey );
	}

	return false;
}

