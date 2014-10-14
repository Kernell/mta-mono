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

	// Player get functions
    static int                  GetPlayerCount                      ( lua_State* pLuaVM );
    static void*                GetPlayerFromName                   ( lua_State* pLuaVM, string sName );
    static int                  GetPlayerMoney                      ( lua_State* pLuaVM, void* pUserData );
    static int                  GetPlayerPing                       ( lua_State* pLuaVM, void* pUserData );
    static void*                GetRandomPlayer                     ( lua_State* pLuaVM );
    static bool                 IsPlayerMuted                       ( lua_State* pLuaVM, void* pUserData );
    static void*                GetPlayerTeam                       ( lua_State* pLuaVM, void* pUserData );
    static int                  GetPlayerWantedLevel                ( lua_State* pLuaVM, void* pUserData );
    static int                  GetAlivePlayers                     ( lua_State* pLuaVM );
    static int                  GetDeadPlayers                      ( lua_State* pLuaVM );
    static int                  GetPlayerIdleTime                   ( lua_State* pLuaVM, void* pUserData );
    static bool                 IsPlayerMapForced                   ( lua_State* pLuaVM, void* pUserData );
    static string               GetPlayerNametagText                ( lua_State* pLuaVM, void* pUserData );
    static bool                 GetPlayerNametagColor               ( lua_State* pLuaVM, void* pUserData, int &iRed, int &iGreen, int &iBlue );
    static bool                 IsPlayerNametagShowing              ( lua_State* pLuaVM, void* pUserData );
    static string               GetPlayerSerial                     ( lua_State* pLuaVM, void* pUserData );
    static string               GetPlayerUserName                   ( lua_State* pLuaVM, void* pUserData );
    static int                  GetPlayerBlurLevel                  ( lua_State* pLuaVM, void* pUserData );
    static string               GetPlayerName                       ( lua_State* pLuaVM, void* pUserData );
    static string               GetPlayerIP                         ( lua_State* pLuaVM, void* pUserData );
    static void*                GetPlayerAccount                    ( lua_State* pLuaVM, void* pUserData );
    static string               GetPlayerVersion                    ( lua_State* pLuaVM, void* pUserData );
    static int                  GetPlayerACInfo                     ( lua_State* pLuaVM, void* pUserData );

    // Player set functions
    static bool					SetPlayerMoney                      ( lua_State* pLuaVM, void* pUserData, int iAmount, bool bInstant = false );
    static bool					GivePlayerMoney                     ( lua_State* pLuaVM, void* pUserData, int iAmount );
    static bool					TakePlayerMoney                     ( lua_State* pLuaVM, void* pUserData, int iAmount );
    static bool					SpawnPlayer                         ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, int iRotation = 0, int iSkinID = 0, int iInterior = 0, int iDimension = 0, void* theTeam = NULL );
    static bool					ShowPlayerHudComponent              ( lua_State* pLuaVM, void* pUserData, string sComponent, bool bShow );
    static bool					SetPlayerWantedLevel                ( lua_State* pLuaVM, void* pUserData, int iLevel );
    static bool					ForcePlayerMap                      ( lua_State* pLuaVM, void* pUserData, bool bForceOn );
    static bool					SetPlayerNametagText                ( lua_State* pLuaVM, void* pUserData, string sText );
    static bool					SetPlayerNametagColor               ( lua_State* pLuaVM, void* pUserData, int iRed = 0, int iGreen = 0, int iBlue = 0 );
    static bool					SetPlayerNametagShowing             ( lua_State* pLuaVM, void* pUserData, bool bShowing );
    static bool					SetPlayerMuted                      ( lua_State* pLuaVM, void* pUserData, bool bMuted );
    static bool					SetPlayerBlurLevel                  ( lua_State* pLuaVM, void* pUserData, int iLevel );
    static bool					RedirectPlayer                      ( lua_State* pLuaVM, void* pUserData, string sServerIP, int iServerPort, string sServerPassword );
    static bool					SetPlayerName                       ( lua_State* pLuaVM, void* pUserData, string sName );
    static bool					DetonateSatchels                    ( lua_State* pLuaVM, void* pUserData );
    static bool					TakePlayerScreenShot                ( lua_State* pLuaVM, void* pUserData, int iWidth, int iHeight, string sTag = "", int iQuality = 30, int iMaxBandwith = 5000 );

	// Ped get functions
	static void*				CreatePed                           ( lua_State* pLuaVM, int iModelid, float fX, float fY, float fZ, float fRot = 0.0, bool bSynced = true );
	static float				GetPedArmor                         ( lua_State* pLuaVM, void* pUserData );    
	static bool					IsPedChoking                        ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedDead                           ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedDucked                         ( lua_State* pLuaVM, void* pUserData );    
	static float				GetPedStat                          ( lua_State* pLuaVM, void* pUserData, int iStat );
	static void*				GetPedTarget                        ( lua_State* pLuaVM, void* pUserData );    
	static int					GetPedWeapon                        ( lua_State* pLuaVM, void* pUserData, int iWeaponSlot = -1 );
	static bool					GetPedClothes                       ( lua_State* pLuaVM, void* pUserData, unsigned char ucType, string& strOutTexture, string& strOutModel );
	static bool					DoesPedHaveJetPack                  ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedOnGround                       ( lua_State* pLuaVM, void* pUserData );    
	static int					GetPedFightingStyle                 ( lua_State* pLuaVM, void* pUserData );
	static int					GetPedMoveAnim                      ( lua_State* pLuaVM, void* pUserData );
	static float				GetPedGravity                       ( lua_State* pLuaVM, void* pUserData );    
	static void*				GetPedContactElement                ( lua_State* pLuaVM, void* pUserData );
	static int					GetPedWeaponSlot                    ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedDoingGangDriveby               ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedOnFire                         ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedHeadless                       ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedFrozen                         ( lua_State* pLuaVM, void* pUserData );
	static void*				GetPedOccupiedVehicle               ( lua_State* pLuaVM, void* pUserData );
	static int					GetPedOccupiedVehicleSeat           ( lua_State* pLuaVM, void* pUserData );
	static bool					IsPedInVehicle                      ( lua_State* pLuaVM, void* pUserData, void* pPed );
//	static int					GetWeaponProperty                   ( lua_State* pLuaVM, void* pUserData );
//	static int					GetOriginalWeaponProperty           ( lua_State* pLuaVM, void* pUserData );

    // Ped set functions
    static bool                 SetPedArmor                         ( lua_State* pLuaVM, void* pUserData, float fArmor );
    static bool                 KillPed                             ( lua_State* pLuaVM, void* pUserData, void* pKiller = NULL, unsigned char ucKillerWeapon = 0xFF, unsigned char ucBodyPart = 0xFF, bool bStealth = false );
    static bool                 SetPedStat                          ( lua_State* pLuaVM, void* pUserData, unsigned short usStat, float fValue );
    static bool                 AddPedClothes                       ( lua_State* pLuaVM, void* pUserData, const char* szTexture, const char* szModel, unsigned char ucType );
    static bool                 RemovePedClothes                    ( lua_State* pLuaVM, void* pUserData, unsigned char ucType, const char* szTexture = NULL, const char* szModel = NULL );
    static bool                 GivePedJetPack                      ( lua_State* pLuaVM, void* pUserData );
    static bool                 RemovePedJetPack                    ( lua_State* pLuaVM, void* pUserData );
    static bool                 SetPedFightingStyle                 ( lua_State* pLuaVM, void* pUserData, unsigned char ucStyle );
    static bool                 SetPedMoveAnim                      ( lua_State* pLuaVM, void* pUserData, unsigned int iMoveAnim );
    static bool                 SetPedGravity                       ( lua_State* pLuaVM, void* pUserData, float fGravity );
    static bool                 SetPedChoking                       ( lua_State* pLuaVM, void* pUserData, bool bChoking );
    static bool                 SetPedWeaponSlot                    ( lua_State* pLuaVM, void* pUserData, unsigned char ucWeaponSlot );
    static bool                 WarpPedIntoVehicle                  ( lua_State* pLuaVM, void* pUserData, void* pVehicle, unsigned int uiSeat = 0 );
    static bool                 RemovePedFromVehicle                ( lua_State* pLuaVM, void* pUserData );
    static bool                 SetPedDoingGangDriveby              ( lua_State* pLuaVM, void* pUserData, bool bGangDriveby );
    static bool                 SetPedAnimation                     ( lua_State* pLuaVM, void* pUserData, const char * szBlockName, const char * szAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame );
    static bool                 SetPedAnimationProgress             ( lua_State* pLuaVM, void* pUserData, const char * szAnimName, float fProgress );
    static bool                 SetPedOnFire                        ( lua_State* pLuaVM, void* pUserData, bool bIsOnFire );
    static bool                 SetPedHeadless                      ( lua_State* pLuaVM, void* pUserData, bool bIsHeadless );
    static bool                 SetPedFrozen                        ( lua_State* pLuaVM, void* pUserData, bool bIsFrozen );
    static bool                 ReloadPedWeapon                     ( lua_State* pLuaVM, void* pUserData );
//	static bool					SetWeaponProperty                   ( lua_State* pLuaVM, void* pUserData );

    // Weapon give/take functions
 //   static int      GiveWeapon                          ( lua_State* pLuaVM );
 //   static int      TakeWeapon                          ( lua_State* pLuaVM );
 //   static int      TakeAllWeapons                      ( lua_State* pLuaVM );
 //   static int      SetWeaponAmmo                       ( lua_State* pLuaVM );
 //   static int      GetSlotFromWeapon                   ( lua_State* pLuaVM );

    // Vehicle create/destroy functions
	static void*					CreateVehicle					( lua_State* pLuaVM, int model, float fX, float fY, float fZ, float fRX, float fRY, float fRZ, string numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );

    // Vehicle get functions
    static string					GetVehicleType					( lua_State* pLuaVM, void* pUserData );
    static bool						GetVehicleVariant               ( lua_State* pLuaVM, void* pUserData, unsigned char& ucVariant, unsigned char& ucVariant2 );
    static bool						GetVehicleColor					( lua_State* pLuaVM, void* pUserData, unsigned char& ucR1, unsigned char& ucG1, unsigned char& ucB1, unsigned char& ucR2, unsigned char& ucG2, unsigned char& ucB2, unsigned char& ucR3, unsigned char& ucG3, unsigned char& ucB3, unsigned char& ucR4, unsigned char& ucG4, unsigned char& ucB4 );
    static unsigned short			GetVehicleModelFromName			( lua_State* pLuaVM, const char* szName );
    static bool						GetVehicleLandingGearDown		( lua_State* pLuaVM, void* pUserData );
    static int						GetVehicleMaxPassengers			( lua_State* pLuaVM, void* pUserData );
    static string					GetVehicleName                  ( lua_State* pLuaVM, void* pUserData );
    static string					GetVehicleNameFromModel         ( lua_State* pLuaVM, void* pUserData, unsigned short usModel );
    static void*					GetVehicleOccupant              ( lua_State* pLuaVM, void* pUserData, unsigned int uiSeat );
	static CLuaArguments*			GetVehicleOccupants             ( lua_State* pLuaVM, void* pUserData );
	static void*					GetVehicleController            ( lua_State* pLuaVM, void* pUserData );
	static bool						GetVehicleSirensOn              ( lua_State* pLuaVM, void* pUserData );
	static bool						GetVehicleTurnVelocity          ( lua_State* pLuaVM, void* pUserData, float &fX, float& fY, float& fZ );
	static bool						GetVehicleTurretPosition        ( lua_State* pLuaVM, void* pUserData, float &fX, float& fY );
	static bool						IsVehicleLocked                 ( lua_State* pLuaVM, void* pUserData );
	static CLuaArguments*			GetVehiclesOfType               ( lua_State* pLuaVM, void* pUserData );       
	static unsigned short			GetVehicleUpgradeOnSlot         ( lua_State* pLuaVM, void* pUserData, unsigned char ucSlot );
	static CLuaArguments*			GetVehicleUpgrades              ( lua_State* pLuaVM, void* pUserData );
    static string				    GetVehicleUpgradeSlotName       ( lua_State* pLuaVM, unsigned char ucSlot );
    static string					GetVehicleUpgradeSlotName       ( lua_State* pLuaVM, unsigned short usUpgrade );
	static CLuaArguments*			GetVehicleCompatibleUpgrades    ( lua_State* pLuaVM, void* pUserData );
	static unsigned char			GetVehicleDoorState             ( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor );
	static bool						GetVehicleWheelStates           ( lua_State* pLuaVM, void* pUserData, unsigned char& ucFrontLeft, unsigned char& ucRearLeft, unsigned char& ucFrontRight, unsigned char& ucRearRight );
	static unsigned char			GetVehicleLightState            ( lua_State* pLuaVM, void* pUserData, unsigned char ucLight );
	static unsigned char			GetVehiclePanelState            ( lua_State* pLuaVM, void* pUserData, unsigned char ucPanel );
	static unsigned char			GetVehicleOverrideLights        ( lua_State* pLuaVM, void* pUserData );
	static void*					GetVehicleTowedByVehicle        ( lua_State* pLuaVM, void* pUserData );
	static void*					GetVehicleTowingVehicle         ( lua_State* pLuaVM, void* pUserData );
	static unsigned char			GetVehiclePaintjob              ( lua_State* pLuaVM, void* pUserData );
	static const char*				GetVehiclePlateText             ( lua_State* pLuaVM, void* pUserData );
	static bool						IsVehicleDamageProof            ( lua_State* pLuaVM, void* pUserData );
	static bool						IsVehicleFuelTankExplodable     ( lua_State* pLuaVM, void* pUserData );
	static bool						IsVehicleFrozen                 ( lua_State* pLuaVM, void* pUserData );
	static bool						IsVehicleOnGround               ( lua_State* pLuaVM, void* pUserData );
	static bool						GetVehicleEngineState           ( lua_State* pLuaVM, void* pUserData );
	static bool						IsTrainDerailed                 ( lua_State* pLuaVM, void* pUserData );
	static bool						IsTrainDerailable               ( lua_State* pLuaVM, void* pUserData );
	static bool						GetTrainDirection               ( lua_State* pLuaVM, void* pUserData );
	static float					GetTrainSpeed                   ( lua_State* pLuaVM, void* pUserData );
	static bool						IsVehicleBlown                  ( lua_State* pLuaVM, void* pUserData );
	static bool						GetVehicleHeadLightColor        ( lua_State* pLuaVM, void* pUserData, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue );
	static float					GetVehicleDoorOpenRatio         ( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor );
    static bool						IsVehicleTaxiLightOn            ( lua_State* pLuaVM, void* pUserData );

    // Vehicle set functions
    static bool						FixVehicle						( lua_State* pLuaVM, void* pUserData );
    static bool						BlowVehicle						( lua_State* pLuaVM, void* pUserData, bool bExplode );
    static bool						SetVehicleTurnVelocity			( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ );
    static bool						SetVehicleColor					( lua_State* pLuaVM, void* pUserData, unsigned char& ucRed, unsigned char& ucGreen, unsigned char& ucBlue, unsigned char& ucRed2, unsigned char& ucGreen2, unsigned char& ucBlue2, unsigned char& ucRed3, unsigned char& ucGreen3, unsigned char& ucBlue3, unsigned char& ucRed4, unsigned char& ucGreen4, unsigned char& ucBlue4 );
    static bool						SetVehicleLandingGearDown       ( lua_State* pLuaVM, void* pUserData, bool bLandingGearDown );
    static bool						SetVehicleLocked                ( lua_State* pLuaVM, void* pUserData, bool bLocked );
    static bool						SetVehicleDoorsUndamageable     ( lua_State* pLuaVM, void* pUserData, bool bDoorsUndamageable );
    static bool						SetVehicleSirensOn              ( lua_State* pLuaVM, void* pUserData, bool bSirensOn );
    static bool						SetVehicleTaxiLightOn           ( lua_State* pLuaVM, void* pUserData, bool bTaxiLightState );
    static bool						AddVehicleUpgrade               ( lua_State* pLuaVM, void* pUserData, unsigned short usUpgrade );
    static bool						RemoveVehicleUpgrade            ( lua_State* pLuaVM, void* pUserData, unsigned short usUpgrade );
    static bool						SetVehicleDoorState             ( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor, unsigned char ucState );
    static bool						SetVehicleWheelStates           ( lua_State* pLuaVM, void* pUserData, int iFrontLeft, int iRearLeft = -1, int iFrontRight = -1, int iRearRight = -1 );
    static bool						SetVehicleLightState            ( lua_State* pLuaVM, void* pUserData, unsigned char ucLight, unsigned char ucState );
    static bool						SetVehiclePanelState            ( lua_State* pLuaVM, void* pUserData, unsigned char ucPanel, unsigned char ucState );
    static bool						SetVehicleIdleRespawnDelay      ( lua_State* pLuaVM, void* pUserData, unsigned long ulTime );
    static bool						SetVehicleRespawnDelay          ( lua_State* pLuaVM, void* pUserData, unsigned long ulTime );
    static bool						SetVehicleRespawnPosition       ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ );
    static bool						ToggleVehicleRespawn            ( lua_State* pLuaVM, void* pUserData, bool bRespawn );
    static bool						ResetVehicleExplosionTime       ( lua_State* pLuaVM, void* pUserData );
    static bool						ResetVehicleIdleTime            ( lua_State* pLuaVM, void* pUserData );
    static bool						SpawnVehicle                    ( lua_State* pLuaVM, void* pUserData, float fX, float fY, float fZ, float fRX, float fRY, float fRZ );
    static bool						RespawnVehicle                  ( lua_State* pLuaVM, void* pUserData );
    static bool						SetVehicleOverrideLights        ( lua_State* pLuaVM, void* pUserData, unsigned char ucLights );
    static bool						AttachTrailerToVehicle          ( lua_State* pLuaVM, void* pUserData, void* pTrailer );
    static bool						DetachTrailerFromVehicle        ( lua_State* pLuaVM, void* pUserData, void* pTrailer = NULL );
    static bool						SetVehicleEngineState           ( lua_State* pLuaVM, void* pUserData, bool bState );
    static bool						SetVehicleDirtLevel             ( lua_State* pLuaVM, void* pUserData, float fDirtLevel );
    static bool						SetVehicleDamageProof           ( lua_State* pLuaVM, void* pUserData, bool bDamageProof );
    static bool						SetVehiclePaintjob              ( lua_State* pLuaVM, void* pUserData, unsigned char ucPaintjob );
    static bool						SetVehicleFuelTankExplodable    ( lua_State* pLuaVM, void* pUserData, bool bExplodable );
    static bool						SetVehicleFrozen                ( lua_State* pLuaVM, void* pUserData, bool bFrozen );
    static bool						SetTrainDerailed                ( lua_State* pLuaVM, void* pUserData, bool bDerailed );
    static bool						SetTrainDerailable              ( lua_State* pLuaVM, void* pUserData, bool bDerailable );
    static bool						SetTrainDirection               ( lua_State* pLuaVM, void* pUserData, bool bDireciton );
    static bool						SetTrainSpeed                   ( lua_State* pLuaVM, void* pUserData, float fSpeed );
    static bool						SetVehicleHeadLightColor        ( lua_State* pLuaVM, void* pUserData, unsigned char ucRed, unsigned char ucGreen, unsigned char ucBlue );
    static bool						SetVehicleTurretPosition        ( lua_State* pLuaVM, void* pUserData, float fHorizontal, float fVertical );
    static bool						SetVehicleDoorOpenRatio         ( lua_State* pLuaVM, void* pUserData, unsigned char ucDoor, float fRatio, unsigned long ulTime = 0 );
    static bool						SetVehicleVariant               ( lua_State* pLuaVM, void* pUserData, unsigned char ucVariant, unsigned char ucVariant2 );
    static bool						GiveVehicleSirens               ( lua_State* pLuaVM, void* pUserData, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360 = false, bool bCheckLosFlag = true, bool bUseRandomiserFlag = true, bool bSilentFlag = false );
    static bool						RemoveVehicleSirens             ( lua_State* pLuaVM, void* pUserData );
    static bool						SetVehicleSirens                ( lua_State* pLuaVM, void* pUserData, unsigned char ucSirenID, float fX, float fY, float fZ, float fRed, float fGreen, float fBlue, float fAlpha = 255, float fMinAlpha = 0.0 );
//	static bool						GetVehicleSirens                ( lua_State* pLuaVM, void* pUserData );
//	static bool						GetVehicleSirenParams           ( lua_State* pLuaVM, void* pUserData );
    static bool						SetVehiclePlateText             ( lua_State* pLuaVM, void* pUserData, const char* szName );

    // Marker create/destroy functions
 //   static int      CreateMarker                        ( lua_State* luaVM );

    // Marker get functions
 //   static int      GetMarkerCount                      ( lua_State* luaVM );
 //   static int      GetMarkerType                       ( lua_State* luaVM );
 //   static int      GetMarkerSize                       ( lua_State* luaVM );
 //   static int      GetMarkerColor                      ( lua_State* luaVM );
 //   static int      GetMarkerTarget                     ( lua_State* luaVM );
 //   static int      GetMarkerIcon                       ( lua_State* luaVM );

    // Marker set functions
 //   static int      SetMarkerType                       ( lua_State* luaVM );
 //   static int      SetMarkerSize                       ( lua_State* luaVM );
 //   static int      SetMarkerColor                      ( lua_State* luaVM );
 //   static int      SetMarkerTarget                     ( lua_State* luaVM );
 //   static int      SetMarkerIcon                       ( lua_State* luaVM );

    // Blip create/destroy functions
 //   static int      CreateBlip                          ( lua_State* luaVM );
 //   static int      CreateBlipAttachedTo                ( lua_State* luaVM );

    // Blip get functions
 //   static int      GetBlipIcon                         ( lua_State* luaVM );
 //   static int      GetBlipSize                         ( lua_State* luaVM );
 //   static int      GetBlipColor                        ( lua_State* luaVM );
 //   static int      GetBlipOrdering                     ( lua_State* luaVM );
 //   static int      GetBlipVisibleDistance              ( lua_State* luaVM );

    // Blip set functions
 //   static int      SetBlipIcon                         ( lua_State* luaVM );
 //   static int      SetBlipSize                         ( lua_State* luaVM );
 //   static int      SetBlipColor                        ( lua_State* luaVM );
 //   static int      SetBlipOrdering                     ( lua_State* luaVM );
 //   static int      SetBlipVisibleDistance              ( lua_State* luaVM );

    // Object create/destroy functions
 //   static int      CreateObject                        ( lua_State* luaVM );

 //   // Object get functions
 //   static int      GetObjectName                       ( lua_State* luaVM );
 //   static int      GetObjectRotation                   ( lua_State* luaVM );
 //   static int      GetObjectScale                      ( lua_State* luaVM );

    // Object set functions
 //   static int      SetObjectName                       ( lua_State* luaVM );
 //   static int      SetObjectRotation                   ( lua_State* luaVM );
 //   static int      SetObjectScale                      ( lua_State* luaVM );
 //   static int      MoveObject                          ( lua_State* luaVM );
 //   static int      StopObject                          ( lua_State* luaVM );

    // Radar area create/destroy funcs
 //   static int      CreateRadarArea                     ( lua_State* luaVM );

    // Radar area get funcs
 //   static int      GetRadarAreaSize                    ( lua_State* luaVM );
 //   static int      GetRadarAreaColor                   ( lua_State* luaVM );
 //   static int      IsRadarAreaFlashing                 ( lua_State* luaVM );
 //   static int      IsInsideRadarArea                   ( lua_State* luaVM );

    // Radar area set funcs
 //   static int      SetRadarAreaSize                    ( lua_State* luaVM );
 //   static int      SetRadarAreaColor                   ( lua_State* luaVM );
 //   static int      SetRadarAreaFlashing                ( lua_State* luaVM );

    // Explosion funcs
 //   static int      CreateExplosion                     ( lua_State* luaVM );

    // Fire funcs
 //   static int      CreateFire                          ( lua_State* luaVM );

    // Audio funcs
 //   static int      PlaySoundFrontEnd                   ( lua_State* luaVM );
 //   static int      PlayMissionAudio                    ( lua_State* luaVM );
 //   static int      PreloadMissionAudio                 ( lua_State* luaVM );

    // Ped body funcs?
 //   static int      GetBodyPartName                     ( lua_State* luaVM );
 //   static int      GetClothesByTypeIndex               ( lua_State* luaVM );
 //   static int      GetTypeIndexFromClothes             ( lua_State* luaVM );
 //   static int      GetClothesTypeName                  ( lua_State* luaVM );

    // Key bind funcs
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

    // Shape create funcs
 //   static int      CreateColCircle                     ( lua_State* luaVM );
 //   static int      CreateColCuboid                     ( lua_State* luaVM );
 //   static int      CreateColSphere                     ( lua_State* luaVM );
 //   static int      CreateColRectangle                  ( lua_State* luaVM );
 //   static int      CreateColPolygon                    ( lua_State* luaVM );
 //   static int      CreateColTube                       ( lua_State* luaVM );

    // Team get funcs
 //   static int      CreateTeam                          ( lua_State* luaVM );    
 //   static int      GetTeamFromName                     ( lua_State* luaVM );
 //   static int      GetTeamName                         ( lua_State* luaVM );
 //   static int      GetTeamColor                        ( lua_State* luaVM );
 //   static int      GetTeamFriendlyFire                 ( lua_State* luaVM );
 //   static int      GetPlayersInTeam                    ( lua_State* luaVM );
 //   static int      CountPlayersInTeam                  ( lua_State* luaVM );

    // Team set funcs
 //   static int      SetPlayerTeam                       ( lua_State* luaVM );
 //   static int      SetTeamName                         ( lua_State* luaVM );
 //   static int      SetTeamColor                        ( lua_State* luaVM );       
 //   static int      SetTeamFriendlyFire                 ( lua_State* luaVM );

    // Water funcs
 //   static int      CreateWater                         ( lua_State* luaVM );
 //   static int      SetWaterLevel                       ( lua_State* luaVM );
 //   static int      ResetWaterLevel                     ( lua_State* luaVM );
 //   static int      GetWaterVertexPosition              ( lua_State* luaVM );
 //   static int      SetWaterVertexPosition              ( lua_State* luaVM );
 //   static int      GetWaterColor                       ( lua_State* luaVM );
 //   static int      SetWaterColor                       ( lua_State* luaVM );
 //   static int      ResetWaterColor                     ( lua_State* luaVM );

    // Weapon funcs
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