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

class CLuaFunctionDefinitions;

#ifndef __CLUAFUNCTIONDEFINITIONS_H
#define __CLUAFUNCTIONDEFINITIONS_H

#include "../Common.h"
#include "../extra/CLuaArguments.h"

class CLuaFunctionDefinitions
{
public:
	static string   Get                                 ( lua_State* pLuaVM, const string &sKey );
	static bool     Set                                 ( lua_State* pLuaVM, const string &sKey, const string &sValue );
	static string   GetGameType                         ( lua_State* pLuaVM );
	static string   GetMapName                          ( lua_State* pLuaVM );
	static string   GetRuleValue                        ( lua_State* pLuaVM, const string &sKey );
	static bool     RemoveRuleValue                     ( lua_State* pLuaVM, const string &sKey );
	static bool     SetGameType                         ( lua_State* pLuaVM, const string &sType );
	static bool     SetMapName                          ( lua_State* pLuaVM, const string &sName );
	static bool     SetRuleValue                        ( lua_State* pLuaVM, const string &sKey, const string &sValue );
	
 //   static int      CallRemote                          ( lua_State* luaVM );
 //   static int      FetchRemote                         ( lua_State* luaVM );

 //   // Event functions
 //   static int      AddEvent                            ( lua_State* luaVM );
 //   static int      AddEventHandler                     ( lua_State* luaVM );
 //   static int      RemoveEventHandler                  ( lua_State* luaVM );
 //   static int      GetEventHandlers                    ( lua_State* luaVM );
 //   static int      TriggerEvent                        ( lua_State* luaVM );
 //   static int      TriggerClientEvent                  ( lua_State* luaVM );
 //   static int      CancelEvent                         ( lua_State* luaVM );
 //   static int      GetCancelReason                     ( lua_State* luaVM );
 //   static int      WasEventCancelled                   ( lua_State* luaVM );
 //   static int      TriggerLatentClientEvent            ( lua_State* luaVM );
 //   static int      GetLatentEventHandles               ( lua_State* luaVM );
 //   static int      GetLatentEventStatus                ( lua_State* luaVM );
 //   static int      CancelLatentEvent                   ( lua_State* luaVM );

	// Element create/destroy
	static void*				CreateElement						( lua_State* pLuaVM, string sType, string sID );
	static bool					DestroyElement						( lua_State* pLuaVM, void* pUserData );
	static void*				CloneElement						( lua_State* pLuaVM, void* pUserData, float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f, bool bCloneChildren = false );

    // Element get funcs
	static bool					IsElement							( lua_State* pLuaVM, void* pUserData );
	static string				GetElementType						( lua_State* pLuaVM, void* pUserData );
	static void*				GetElementByID						( lua_State* pLuaVM, string sID );
	static void*				GetElementByIndex					( lua_State* pLuaVM, int iIndex );
	static void*				GetElementChild						( lua_State* pLuaVM, void* pUserData, int iIndex );
	static int					GetElementChildrenCount				( lua_State* pLuaVM, void* pUserData );
	static string				GetElementID						( lua_State* pLuaVM, void* pUserData );
	static CLuaArgument*		GetElementData						( lua_State* pLuaVM, void* pUserData, string sKey, bool bInherit = true );
	static CLuaArguments*		GetAllElementData					( lua_State* pLuaVM, void* pUserData );
    static void*				GetElementParent					( lua_State* pLuaVM, void* pUserData );
	static bool					GetElementPosition					( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ );
	static bool					GetElementRotation					( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ );
	static bool					GetElementVelocity					( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ );
	static int					GetElementInterior					( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementWithinColShape				( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementWithinMarker				( lua_State* pLuaVM, void* pUserData );
	static int					GetElementDimension					( lua_State* pLuaVM, void* pUserData );
	static string				GetElementZoneName					( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementAttached					( lua_State* pLuaVM, void* pUserData );
	static void*				GetElementAttachedTo				( lua_State* pLuaVM, void* pUserData );
	static void*				GetElementColShape					( lua_State* pLuaVM, void* pUserData );
	static int					GetElementAlpha						( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementDoubleSided				( lua_State* pLuaVM, void* pUserData );
	static float				GetElementHealth					( lua_State* pLuaVM, void* pUserData );
	static int					GetElementModel						( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementInWater					( lua_State* pLuaVM, void* pUserData );
	static bool					GetElementAttachedOffsets			( lua_State* pLuaVM, void* pUserData, float &fX, float &fY, float &fZ, float &fRX, float &fRY, float &fRZ );
	static void*				GetElementSyncer					( lua_State* pLuaVM, void* pUserData );
	static bool					GetElementCollisionsEnabled			( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementFrozen						( lua_State* pLuaVM, void* pUserData );
	static bool					GetLowLodElement					( lua_State* pLuaVM, void* pUserData );
	static bool					IsElementLowLod						( lua_State* pLuaVM, void* pUserData );

	// Element set funcs
	static bool                 ClearElementVisibleTo               ( lua_State* pLuaVM, void* pUserData );
	static bool                 SetElementID                        ( lua_State* pLuaVM, void* pUserData, string sID );
	static bool                 SetElementData                      ( lua_State* pLuaVM, void* pUserData, string sKey, const CLuaArgument& Variable );
	static bool                 RemoveElementData                   ( lua_State* pLuaVM, void* pUserData, string sKey );
	static bool                 SetElementParent                    ( lua_State* pLuaVM, void* pUserData, void* pTarget );
	static bool                 SetElementPosition                  ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ );
	static bool                 SetElementRotation                  ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ );
	static bool                 SetElementVelocity                  ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ );
	static bool                 SetElementVisibleTo                 ( lua_State* pLuaVM, void* pUserData, void* pTarget, bool bVisible );
	static bool                 SetElementInterior                  ( lua_State* pLuaVM, void* pUserData, int iInterior );
	static bool                 SetElementDimension                 ( lua_State* pLuaVM, void* pUserData, int iDimension );
	static bool                 AttachElements                      ( lua_State* pLuaVM, void* pUserData, void* pTarget, float fX = 0.0f, float fY = 0.0f, float fZ = 0.0f, float fRX = 0.0f, float fRY = 0.0f, float fRZ = 0.0f );
	static bool                 DetachElements                      ( lua_State* pLuaVM, void* pUserData, void* pTarget = NULL );
	static bool                 SetElementAlpha                     ( lua_State* pLuaVM, void* pUserData, int iAlpha );
	static bool                 SetElementDoubleSided               ( lua_State* pLuaVM, void* pUserData, bool bDoubleSided );
	static bool                 SetElementHealth                    ( lua_State* pLuaVM, void* pUserData, float fHealth );
	static bool                 SetElementModel                     ( lua_State* pLuaVM, void* pUserData, int iModel );
	static bool                 SetElementAttachedOffsets           ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ );
	static bool                 SetElementSyncer                    ( lua_State* pLuaVM, void* pUserData, void* pPlayer );
	static bool                 SetElementCollisionsEnabled         ( lua_State* pLuaVM, void* pUserData, bool bEnabled );
	static bool                 SetElementFrozen                    ( lua_State* pLuaVM, void* pUserData, bool bFrozen );
	static bool                 SetLowLodElement                    ( lua_State* pLuaVM, void* pUserData, bool bEnabled );

	//// Player get functions
 //   static int      GetPlayerCount                      ( lua_State* luaVM );
 //   static int      GetPedAmmoInClip                    ( lua_State* luaVM );
 //   static int      GetPedTotalAmmo                     ( lua_State* luaVM );
 //   static int      SetPlayerAmmo                       ( lua_State* luaVM );
 //   static int      GetPlayerFromName                   ( lua_State* luaVM );
 //   static int      GetPlayerMoney                      ( lua_State* luaVM );
 //   static int      GetPlayerPing                       ( lua_State* luaVM );
 //   static int      GetRandomPlayer                     ( lua_State* luaVM );
 //   static int      IsPlayerMuted                       ( lua_State* luaVM );
 //   static int      GetPlayerTeam                       ( lua_State* luaVM );
 //   static int      CanPlayerUseFunction                ( lua_State* luaVM );
 //   static int      GetPlayerWantedLevel                ( lua_State* luaVM );
 //   static int      GetAlivePlayers                     ( lua_State* luaVM );
 //   static int      GetDeadPlayers                      ( lua_State* luaVM );
 //   static int      GetPlayerIdleTime                   ( lua_State* luaVM );
 //   static int      IsPlayerScoreboardForced            ( lua_State* luaVM );
 //   static int      IsPlayerMapForced                   ( lua_State* luaVM );
 //   static int      GetPlayerNametagText                ( lua_State* luaVM );
 //   static int      GetPlayerNametagColor               ( lua_State* luaVM );
 //   static int      IsPlayerNametagShowing              ( lua_State* luaVM );
 //   static int      GetPlayerSerial                     ( lua_State* luaVM );
 //   static int      GetPlayerCommunityID                ( lua_State* luaVM );
 //   static int      IsPlayerDev                         ( lua_State* luaVM );
 //   static int      IsPlayerQA                          ( lua_State* luaVM );
 //   static int      GetPlayerUserName                   ( lua_State* luaVM );
 //   static int      GetPlayerBlurLevel                  ( lua_State* luaVM );
 //   static int      GetPlayerName                       ( lua_State* luaVM );
 //   static int      GetPlayerIP                         ( lua_State* luaVM );
 //   static int      GetPlayerAccount                    ( lua_State* luaVM );
 //   static int      GetPlayerVersion                    ( lua_State* luaVM );
 //   static int      GetPlayerACInfo                     ( lua_State* luaVM );

 //   // Player set functions
 //   static int      SetPlayerMoney                      ( lua_State* luaVM );
 //   static int      GivePlayerMoney                     ( lua_State* luaVM );
 //   static int      TakePlayerMoney                     ( lua_State* luaVM );
 //   static int      SpawnPlayer                         ( lua_State* luaVM );
 //   static int      ShowPlayerHudComponent              ( lua_State* luaVM );
 //   static int      SetPlayerWantedLevel                ( lua_State* luaVM );
 //   static int      ForcePlayerMap                      ( lua_State* luaVM );
 //   static int      SetPlayerNametagText                ( lua_State* luaVM );
 //   static int      SetPlayerNametagColor               ( lua_State* luaVM );
 //   static int      SetPlayerNametagShowing             ( lua_State* luaVM );
 //   static int      SetPlayerMuted                      ( lua_State* luaVM );
 //   static int      SetPlayerBlurLevel                  ( lua_State* luaVM );
 //   static int      RedirectPlayer                      ( lua_State* luaVM );
 //   static int      SetPlayerName                       ( lua_State* luaVM );
 //   static int      DetonateSatchels                    ( lua_State* luaVM );
 //   static int      TakePlayerScreenShot                ( lua_State* luaVM );

	//// Ped get functions
 //   static int      CreatePed                           ( lua_State* luaVM );
 //   static int      GetPedArmor                         ( lua_State* luaVM );    
 //   static int      GetPedRotation                      ( lua_State* luaVM );    
 //   static int      IsPedChoking                        ( lua_State* luaVM );
 //   static int      IsPedDead                           ( lua_State* luaVM );
 //   static int      IsPedDucked                         ( lua_State* luaVM );    
 //   static int      GetPedStat                          ( lua_State* luaVM );
 //   static int      GetPedTarget                        ( lua_State* luaVM );    
 //   static int      GetPedWeapon                        ( lua_State* luaVM );
 //   static int      GetPedClothes                       ( lua_State* luaVM );
 //   static int      DoesPedHaveJetPack                  ( lua_State* luaVM );
 //   static int      IsPedOnGround                       ( lua_State* luaVM );    
 //   static int      GetPedFightingStyle                 ( lua_State* luaVM );
 //   static int      GetPedMoveAnim                      ( lua_State* luaVM );
 //   static int      GetPedGravity                       ( lua_State* luaVM );    
 //   static int      GetPedContactElement                ( lua_State* luaVM );
 //   static int      GetPedWeaponSlot                    ( lua_State* luaVM );
 //   static int      IsPedDoingGangDriveby               ( lua_State* luaVM );
 //   static int      IsPedOnFire                         ( lua_State* luaVM );
 //   static int      IsPedHeadless                       ( lua_State* luaVM );
 //   static int      IsPedFrozen                         ( lua_State* luaVM );
 //   static int      GetPedOccupiedVehicle               ( lua_State* luaVM );
 //   static int      GetPedOccupiedVehicleSeat           ( lua_State* luaVM );
 //   static int      IsPedInVehicle                      ( lua_State* luaVM );
 //   static int      GetWeaponProperty                   ( lua_State* luaVM );
 //   static int      GetOriginalWeaponProperty           ( lua_State* luaVM );

 //   // Player set functions
 //   static int      SetPedArmor                         ( lua_State* luaVM );    
 //   static int      KillPed                             ( lua_State* luaVM );
 //   static int      SetPedRotation                      ( lua_State* luaVM );
 //   static int      SetPedStat                          ( lua_State* luaVM );
 //   static int      AddPedClothes                       ( lua_State* luaVM );
 //   static int      RemovePedClothes                    ( lua_State* luaVM );
 //   static int      GivePedJetPack                      ( lua_State* luaVM );
 //   static int      RemovePedJetPack                    ( lua_State* luaVM );
 //   static int      SetPedFightingStyle                 ( lua_State* luaVM );
 //   static int      SetPedMoveAnim                      ( lua_State* luaVM );
 //   static int      SetPedGravity                       ( lua_State* luaVM );
 //   static int      SetPedChoking                       ( lua_State* luaVM );      
 //   static int      WarpPedIntoVehicle                  ( lua_State* luaVM );
 //   static int      RemovePedFromVehicle                ( lua_State* luaVM );
 //   static int      SetPedDoingGangDriveby              ( lua_State* luaVM );
 //   static int      SetPedAnimation                     ( lua_State* luaVM );
 //   static int      SetPedAnimationProgress             ( lua_State* luaVM );
 //   static int      SetPedWeaponSlot                    ( lua_State* luaVM );
 //   static int      SetPedOnFire                        ( lua_State* luaVM );
 //   static int      SetPedHeadless                      ( lua_State* luaVM );
 //   static int      SetPedFrozen                        ( lua_State* luaVM );
 //   static int      reloadPedWeapon                     ( lua_State* luaVM );
 //   static int      SetWeaponProperty                   ( lua_State* luaVM );

 //   // Weapon give/take functions
 //   static int      GiveWeapon                          ( lua_State* luaVM );
 //   static int      TakeWeapon                          ( lua_State* luaVM );
 //   static int      TakeAllWeapons                      ( lua_State* luaVM );
 //   static int      SetWeaponAmmo                       ( lua_State* luaVM );
 //   static int      GetSlotFromWeapon                   ( lua_State* luaVM );

 //   // Vehicle create/destroy functions
	static void*	CreateVehicle						( lua_State* luaVM, int model, float fX, float fY, float fZ, float fRX, float fRY, float fRZ, string numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );

 //   // Vehicle get functions
 //   static int      GetVehicleType                      ( lua_State* luaVM );
 //   static int      GetVehicleVariant                   ( lua_State* luaVM );
 //   static int      GetVehicleColor                     ( lua_State* luaVM );
 //   static int      GetVehicleModelFromName             ( lua_State* luaVM );
 //   static int      GetVehicleLandingGearDown           ( lua_State* luaVM );
 //   static int      GetVehicleMaxPassengers             ( lua_State* luaVM );
 //   static int      GetVehicleName                      ( lua_State* luaVM );
 //   static int      GetVehicleNameFromModel             ( lua_State* luaVM );
 //   static int      GetVehicleOccupant                  ( lua_State* luaVM );
 //   static int      GetVehicleOccupants                 ( lua_State* luaVM );
 //   static int      GetVehicleController                ( lua_State* luaVM );
 //   static int      GetVehicleRotation                  ( lua_State* luaVM );
 //   static int      GetVehicleSirensOn                  ( lua_State* luaVM );
 //   static int      GetVehicleTurnVelocity              ( lua_State* luaVM );
 //   static int      GetVehicleTurretPosition            ( lua_State* luaVM );
 //   static int      IsVehicleLocked                     ( lua_State* luaVM );
 //   static int      GetVehiclesOfType                   ( lua_State* luaVM );       
 //   static int      GetVehicleUpgradeOnSlot             ( lua_State* luaVM );
 //   static int      GetVehicleUpgrades                  ( lua_State* luaVM );
 //   static int      GetVehicleUpgradeSlotName           ( lua_State* luaVM );
 //   static int      GetVehicleCompatibleUpgrades        ( lua_State* luaVM );
 //   static int      GetVehicleDoorState                 ( lua_State* luaVM );
 //   static int      GetVehicleWheelStates               ( lua_State* luaVM );
 //   static int      GetVehicleLightState                ( lua_State* luaVM );
 //   static int      GetVehiclePanelState                ( lua_State* luaVM );
 //   static int      GetVehicleOverrideLights            ( lua_State* luaVM );
 //   static int      GetVehicleTowedByVehicle            ( lua_State* luaVM );
 //   static int      GetVehicleTowingVehicle             ( lua_State* luaVM );
 //   static int      GetVehiclePaintjob                  ( lua_State* luaVM );
 //   static int      GetVehiclePlateText                 ( lua_State* luaVM );
 //   static int      IsVehicleDamageProof                ( lua_State* luaVM );
 //   static int      IsVehicleFuelTankExplodable         ( lua_State* luaVM );
 //   static int      IsVehicleFrozen                     ( lua_State* luaVM );
 //   static int      IsVehicleOnGround                   ( lua_State* luaVM );
 //   static int      GetVehicleEngineState               ( lua_State* luaVM );
 //   static int      IsTrainDerailed                     ( lua_State* luaVM );
 //   static int      IsTrainDerailable                   ( lua_State* luaVM );
 //   static int      GetTrainDirection                   ( lua_State* luaVM );
 //   static int      GetTrainSpeed                       ( lua_State* luaVM );
 //   static int      IsVehicleBlown                      ( lua_State* luaVM );
 //   static int      GetVehicleHeadLightColor            ( lua_State* luaVM );
 //   static int      GetVehicleDoorOpenRatio             ( lua_State* luaVM );

 //   // Vehicle set functions
 //   static int      FixVehicle                          ( lua_State* luaVM );
 //   static int      BlowVehicle                         ( lua_State* luaVM );
 //   static int      SetVehicleRotation                  ( lua_State* luaVM );
 //   static int      SetVehicleTurnVelocity              ( lua_State* luaVM );
 //   static int      SetVehicleColor                     ( lua_State* luaVM );
 //   static int      SetVehicleLandingGearDown           ( lua_State* luaVM );
 //   static int      SetVehicleLocked                    ( lua_State* luaVM );
 //   static int      SetVehicleModel                     ( lua_State* luaVM );
 //   static int      SetVehicleDoorsUndamageable         ( lua_State* luaVM );
 //   static int      SetVehicleSirensOn                  ( lua_State* luaVM );
 //   static int      SetVehicleTaxiLightOn               ( lua_State* luaVM );
 //   static int      IsVehicleTaxiLightOn                ( lua_State* luaVM );
 //   static int      AddVehicleUpgrade                   ( lua_State* luaVM );
 //   static int      RemoveVehicleUpgrade                ( lua_State* luaVM );
 //   static int      SetVehicleDoorState                 ( lua_State* luaVM );
 //   static int      SetVehicleWheelStates               ( lua_State* luaVM );
 //   static int      SetVehicleLightState                ( lua_State* luaVM );
 //   static int      SetVehiclePanelState                ( lua_State* luaVM );
 //   static int      SetVehicleIdleRespawnDelay          ( lua_State* luaVM );
 //   static int      SetVehicleRespawnDelay              ( lua_State* luaVM );
 //   static int      SetVehicleRespawnPosition           ( lua_State* luaVM );
 //   static int      ToggleVehicleRespawn                ( lua_State* luaVM );
 //   static int      ResetVehicleExplosionTime           ( lua_State* luaVM );
 //   static int      ResetVehicleIdleTime                ( lua_State* luaVM );
 //   static int      SpawnVehicle                        ( lua_State* luaVM );
 //   static int      RespawnVehicle                      ( lua_State* luaVM );
 //   static int      SetVehicleOverrideLights            ( lua_State* luaVM );
 //   static int      AttachTrailerToVehicle              ( lua_State* luaVM );
 //   static int      DetachTrailerFromVehicle            ( lua_State* luaVM );
 //   static int      SetVehicleEngineState               ( lua_State* luaVM );
 //   static int      SetVehicleDirtLevel                 ( lua_State* luaVM );
 //   static int      SetVehicleDamageProof               ( lua_State* luaVM );
 //   static int      SetVehiclePaintjob                  ( lua_State* luaVM );
 //   static int      SetVehicleFuelTankExplodable        ( lua_State* luaVM );
 //   static int      SetVehicleFrozen                    ( lua_State* luaVM );
 //   static int      SetTrainDerailed                    ( lua_State* luaVM );
 //   static int      SetTrainDerailable                  ( lua_State* luaVM );
 //   static int      SetTrainDirection                   ( lua_State* luaVM );
 //   static int      SetTrainSpeed                       ( lua_State* luaVM );
 //   static int      SetVehicleHeadLightColor            ( lua_State* luaVM );
 //   static int      SetVehicleTurretPosition            ( lua_State* luaVM );
 //   static int      SetVehicleDoorOpenRatio             ( lua_State* luaVM );
 //   static int      SetVehicleVariant                   ( lua_State* luaVM );
 //   static int      GiveVehicleSirens                   ( lua_State* luaVM );
 //   static int      RemoveVehicleSirens                 ( lua_State* luaVM );
 //   static int      SetVehicleSirens                    ( lua_State* luaVM );
 //   static int      GetVehicleSirens                    ( lua_State* luaVM );
 //   static int      GetVehicleSirenParams               ( lua_State* luaVM );
 //   static int      SetVehiclePlateText                 ( lua_State* luaVM );

 //   // Marker create/destroy functions
 //   static int      CreateMarker                        ( lua_State* luaVM );

 //   // Marker get functions
 //   static int      GetMarkerCount                      ( lua_State* luaVM );
 //   static int      GetMarkerType                       ( lua_State* luaVM );
 //   static int      GetMarkerSize                       ( lua_State* luaVM );
 //   static int      GetMarkerColor                      ( lua_State* luaVM );
 //   static int      GetMarkerTarget                     ( lua_State* luaVM );
 //   static int      GetMarkerIcon                       ( lua_State* luaVM );

 //   // Marker set functions
 //   static int      SetMarkerType                       ( lua_State* luaVM );
 //   static int      SetMarkerSize                       ( lua_State* luaVM );
 //   static int      SetMarkerColor                      ( lua_State* luaVM );
 //   static int      SetMarkerTarget                     ( lua_State* luaVM );
 //   static int      SetMarkerIcon                       ( lua_State* luaVM );

 //   // Blip create/destroy functions
 //   static int      CreateBlip                          ( lua_State* luaVM );
 //   static int      CreateBlipAttachedTo                ( lua_State* luaVM );

 //   // Blip get functions
 //   static int      GetBlipIcon                         ( lua_State* luaVM );
 //   static int      GetBlipSize                         ( lua_State* luaVM );
 //   static int      GetBlipColor                        ( lua_State* luaVM );
 //   static int      GetBlipOrdering                     ( lua_State* luaVM );
 //   static int      GetBlipVisibleDistance              ( lua_State* luaVM );

 //   // Blip set functions
 //   static int      SetBlipIcon                         ( lua_State* luaVM );
 //   static int      SetBlipSize                         ( lua_State* luaVM );
 //   static int      SetBlipColor                        ( lua_State* luaVM );
 //   static int      SetBlipOrdering                     ( lua_State* luaVM );
 //   static int      SetBlipVisibleDistance              ( lua_State* luaVM );

 //   // Object create/destroy functions
 //   static int      CreateObject                        ( lua_State* luaVM );

 //   // Object get functions
 //   static int      GetObjectName                       ( lua_State* luaVM );
 //   static int      GetObjectRotation                   ( lua_State* luaVM );
 //   static int      GetObjectScale                      ( lua_State* luaVM );

 //   // Object set functions
 //   static int      SetObjectName                       ( lua_State* luaVM );
 //   static int      SetObjectRotation                   ( lua_State* luaVM );
 //   static int      SetObjectScale                      ( lua_State* luaVM );
 //   static int      MoveObject                          ( lua_State* luaVM );
 //   static int      StopObject                          ( lua_State* luaVM );

 //   // Radar area create/destroy funcs
 //   static int      CreateRadarArea                     ( lua_State* luaVM );

 //   // Radar area get funcs
 //   static int      GetRadarAreaSize                    ( lua_State* luaVM );
 //   static int      GetRadarAreaColor                   ( lua_State* luaVM );
 //   static int      IsRadarAreaFlashing                 ( lua_State* luaVM );
 //   static int      IsInsideRadarArea                   ( lua_State* luaVM );

 //   // Radar area set funcs
 //   static int      SetRadarAreaSize                    ( lua_State* luaVM );
 //   static int      SetRadarAreaColor                   ( lua_State* luaVM );
 //   static int      SetRadarAreaFlashing                ( lua_State* luaVM );

 //   // Explosion funcs
 //   static int      CreateExplosion                     ( lua_State* luaVM );

 //   // Fire funcs
 //   static int      CreateFire                          ( lua_State* luaVM );

 //   // Audio funcs
 //   static int      PlaySoundFrontEnd                   ( lua_State* luaVM );
 //   static int      PlayMissionAudio                    ( lua_State* luaVM );
 //   static int      PreloadMissionAudio                 ( lua_State* luaVM );

 //   // Ped body funcs?
 //   static int      GetBodyPartName                     ( lua_State* luaVM );
 //   static int      GetClothesByTypeIndex               ( lua_State* luaVM );
 //   static int      GetTypeIndexFromClothes             ( lua_State* luaVM );
 //   static int      GetClothesTypeName                  ( lua_State* luaVM );

 //   // Key bind funcs
 //   static int      BindKey                             ( lua_State* luaVM );
 //   static int      UnbindKey                           ( lua_State* luaVM );
 //   static int      IsKeyBound                          ( lua_State* luaVM );
 //   static int      GetFunctionsBoundToKey              ( lua_State* luaVM );
 //   static int      GetKeyBoundToFunction               ( lua_State* luaVM );
 //   static int      GetControlState                     ( lua_State* luaVM );
 //   static int      IsControlEnabled                    ( lua_State* luaVM );
 //  
 //   static int      SetControlState                     ( lua_State* luaVM );
 //   static int      ToggleControl                       ( lua_State* luaVM );
 //   static int      ToggleAllControls                   ( lua_State* luaVM ); 

 //   // Shape create funcs
 //   static int      CreateColCircle                     ( lua_State* luaVM );
 //   static int      CreateColCuboid                     ( lua_State* luaVM );
 //   static int      CreateColSphere                     ( lua_State* luaVM );
 //   static int      CreateColRectangle                  ( lua_State* luaVM );
 //   static int      CreateColPolygon                    ( lua_State* luaVM );
 //   static int      CreateColTube                       ( lua_State* luaVM );

 //   // Team get funcs
 //   static int      CreateTeam                          ( lua_State* luaVM );    
 //   static int      GetTeamFromName                     ( lua_State* luaVM );
 //   static int      GetTeamName                         ( lua_State* luaVM );
 //   static int      GetTeamColor                        ( lua_State* luaVM );
 //   static int      GetTeamFriendlyFire                 ( lua_State* luaVM );
 //   static int      GetPlayersInTeam                    ( lua_State* luaVM );
 //   static int      CountPlayersInTeam                  ( lua_State* luaVM );

 //   // Team set funcs
 //   static int      SetPlayerTeam                       ( lua_State* luaVM );
 //   static int      SetTeamName                         ( lua_State* luaVM );
 //   static int      SetTeamColor                        ( lua_State* luaVM );       
 //   static int      SetTeamFriendlyFire                 ( lua_State* luaVM );

 //   // Water funcs
 //   static int      CreateWater                         ( lua_State* luaVM );
 //   static int      SetWaterLevel                       ( lua_State* luaVM );
 //   static int      ResetWaterLevel                     ( lua_State* luaVM );
 //   static int      GetWaterVertexPosition              ( lua_State* luaVM );
 //   static int      SetWaterVertexPosition              ( lua_State* luaVM );
 //   static int      GetWaterColor                       ( lua_State* luaVM );
 //   static int      SetWaterColor                       ( lua_State* luaVM );
 //   static int      ResetWaterColor                     ( lua_State* luaVM );

 //   // Weapon funcs
 //   static int      CreateWeapon                        ( lua_State* luaVM );
 //   static int      GetWeaponNameFromID                 ( lua_State* luaVM );
 //   static int      GetWeaponIDFromName                 ( lua_State* luaVM );
 //   static int      FireWeapon                          ( lua_State* luaVM );
 //   static int      SetWeaponState                      ( lua_State* luaVM );
 //   static int      GetWeaponState                      ( lua_State* luaVM );
 //   static int      SetWeaponTarget                     ( lua_State* luaVM );
 //   static int      GetWeaponTarget                     ( lua_State* luaVM );
 //   static int      SetWeaponOwner                      ( lua_State* luaVM );
 //   static int      GetWeaponOwner                      ( lua_State* luaVM );
 //   static int      SetWeaponFlags                      ( lua_State* luaVM );
 //   static int      GetWeaponFlags                      ( lua_State* luaVM );
 //   static int      SetWeaponFiringRate                 ( lua_State* luaVM );
 //   static int      GetWeaponFiringRate                 ( lua_State* luaVM );
 //   static int      ResetWeaponFiringRate               ( lua_State* luaVM );
 //   static int      GetWeaponAmmo                       ( lua_State* luaVM );
 //   static int      GetWeaponClipAmmo                   ( lua_State* luaVM );
 //   static int      SetWeaponClipAmmo                   ( lua_State* luaVM );
};

#endif