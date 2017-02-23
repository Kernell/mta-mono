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

#include "CResource.h"
#include "CResourceManager.h"

class CMonoFunctions;

#ifndef __CMONOFUNCTIONS_H
#define __CMONOFUNCTIONS_H

#include "lua/CLuaFunctionDefinitions.h"

#include "CModule.h"

#include "CMonoDomain.h"
#include "CMonoClass.h"
#include "CMonoCorlib.h"
#include "CMonoMTALib.h"
#include "CElementManager.h"

extern CModule* g_pModule;

#define MONO_DECLARE_CTOR(a)	mono_add_internal_call("MultiTheftAuto."#a"::.ctor",(const void*)CMonoFunctions::a::Ctor)

#define MONO_DECLARE(a,b)		mono_add_internal_call("MultiTheftAuto."#a"::"#b,(const void*)CMonoFunctions::a::b)

typedef MonoObject* TElement;

class CMonoFunctions
{
public:
	static void							AddInternals					( void );

	class Debug
	{
	public:
		static void						Log								( MonoString* pString );
		static void						Info							( MonoString* pString );
		static void						Error							( MonoString* pString );
	};

	class Console
	{
	public:
		static void						Write							( MonoString* pString );
		static void						WriteLine						( MonoString* pString );
		static bool						Output							( MonoString* szText, MonoObject* pThis );
	};

	class Config
	{
	public:
		static MonoString*				Get								( MonoString* msKey );
		static bool						Set								( MonoString* msKey, MonoString* msValue );
	};

	class Server
	{
	public:
		static unsigned int				GetMaxPlayers					( void );
		static bool						SetMaxPlayers					( unsigned int uiMax );
		static bool						OutputChatBox					( MonoString* szText, MonoObject* pElement, MonoObject* pColor, bool bColorCoded );
		static bool						SetPassword						( MonoString* msPassword, bool bSave );
		static MonoObject*				GetVersion						( void );

		static bool						AddCommandHandler				( MonoString* msCommand, MonoObject* pDelegate, bool bRestricted = false, bool bCaseSensitive = true );
		static bool						ExecuteCommandHandler			( MonoString* msCommand, MonoObject* pPlayerObj, MonoString* msArgs );
		static bool						RemoveCommandHandler			( MonoString* msCommand, MonoObject* pDelegate = nullptr );
	};

	class Game
	{
	public:
		static MonoString*				GetType							( void );
		static MonoString*				GetMapName						( void );

		static bool						SetType							( MonoString* msGameType );
		static bool						SetMapName						( MonoString* msMapName );
		static MonoString*				GetRuleValue					( MonoString* msKey );
		static bool						SetRuleValue					( MonoString* msKey, MonoString* msValue );
		static bool						RemoveRuleValue					( MonoString* msKey );
	};

	class Event
	{
	public:
		static bool						Add								( MonoString* msName, bool bAllowRemoteTrigger );
		static bool						AddHandler						( MonoString* msName, MonoObject* pThis, MonoObject* pDelegate, bool bPropagated, MonoString* msEventPriority );
		static bool						RemoveHandler					( MonoString* msName, MonoObject* pThis, MonoObject* pDelegate );
		static bool						Trigger							( MonoString* msName, MonoObject* pThis, MonoArray* mpArguments );
		static bool						Cancel							( bool bCancel, MonoString* msReason );
		static bool						WasCancelled					( void );
		static string					GetCancelReason					( void );

		static bool						TriggerClient					( MonoObject* pSendTo, MonoString* msName, MonoObject* pSource, MonoArray* mpArguments );
	};

	class Element
	{
	public:
		// Element create/destroy
		static void						Ctor							( TElement pThis, MonoString* msTypeName, MonoString* msID );
		static bool						Destroy							( TElement pThis );
		static TElement					Clone							( TElement pThis, MonoObject* vecPosition, bool bCloneElement );

		// Element get funcs
		static TElement					GetRootElement					( void );
		static MonoArray*				GetByType						( MonoString* msType, TElement pStartElement );

		static bool						IsElement						( TElement pThis );
		static uint32_t					GetUserData						( TElement pThis );
		static MonoString*				GetElementType					( TElement pThis );
		static TElement					GetByID							( MonoString* msID, unsigned int uiIndex );
		static TElement					GetByIndex						( int iIndex );
		static TElement					GetChild						( TElement pThis, int iIndex );
		static int						GetChildrenCount				( TElement pThis );
		static MonoString*				GetID							( TElement pThis );
		static MonoObject*				GetData							( TElement pThis, MonoString* sKey, bool bInherit = true );
		static MonoArray*				GetAllData						( TElement pThis );
		static TElement					GetParent						( TElement pThis );
		static MonoObject*				GetPosition						( TElement pThis );
		static MonoObject*				GetRotation						( TElement pThis );
		static MonoObject*				GetVelocity						( TElement pThis );
		static unsigned char			GetInterior						( TElement pThis );
		static bool						IsWithinColShape				( TElement pThis );
		static bool						IsWithinMarker					( TElement pThis );
		static unsigned short			GetDimension					( TElement pThis );
		static MonoString*				GetZoneName						( TElement pThis, bool bCitiesOnly = false );
		static bool						IsAttached						( TElement pThis );
		static TElement					GetAttachedTo					( TElement pThis );
		static TElement					GetColShape						( TElement pThis );
		static unsigned char			GetAlpha						( TElement pThis );
		static bool						IsDoubleSided					( TElement pThis );
		static float					GetHealth						( TElement pThis );
		static unsigned short			GetModel						( TElement pThis );
		static bool						IsInWater						( TElement pThis );
		static MonoObject*				GetAttachedOffsetPosition		( TElement pThis );
		static MonoObject*				GetAttachedOffsetRotation		( TElement pThis );
		static TElement					GetSyncer						( TElement pThis );
		static bool						GetCollisionsEnabled			( TElement pThis );
		static bool						IsFrozen						( TElement pThis );
		static TElement					GetLowLod						( TElement pThis );
		static bool						IsLowLod						( TElement pThis );

		// Element set funcs
		static bool						ClearVisibleTo					( TElement pThis );
		static bool						SetID							( TElement pThis, MonoString* msID );
		static bool						SetData							( TElement pThis, MonoString* msKey, CLuaArgument& Variable );
		static bool						RemoveData						( TElement pThis, MonoString* msKey );
		static bool						SetParent						( TElement pThis, TElement pTarget );
		static bool						SetPosition						( TElement pThis, MonoObject* pPosition, bool bWarp );
		static bool						SetRotation						( TElement pThis, MonoObject* pRotation, MonoString* msRotationOrder, bool bNewWay );
		static bool						SetVelocity						( TElement pThis, MonoObject* pVelocity );
		static bool						SetVisibleTo					( TElement pThis, TElement pTarget, bool bVisible );
		static bool						SetInterior						( TElement pThis, int iInterior );
		static bool						SetDimension					( TElement pThis, int iDimension );
		static bool						Attach							( TElement pThis, TElement pTarget, MonoObject* pPosition, MonoObject* pRotation );
		static bool						Detach							( TElement pThis, TElement pTarget );
		static bool						SetAlpha						( TElement pThis, int iAlpha );
		static bool						SetDoubleSided					( TElement pThis, bool bDoubleSided );
		static bool						SetHealth						( TElement pThis, float fHealth );
		static bool						SetModel						( TElement pThis, int iModel );
		static bool						SetAttachedOffsets				( TElement pThis, MonoObject* pPosition, MonoObject* pRotation );
		static bool						SetSyncer						( TElement pThis, TElement pPlayer );
		static bool						SetCollisionsEnabled			( TElement pThis, bool bEnabled );
		static bool						SetFrozen						( TElement pThis, bool bFrozen );
		static bool						SetLowLod						( TElement pThis, bool bEnabled );
	};

	class Player
	{
	public:
		// Player get functions
		static unsigned int				GetCount						( void );
		static TElement					GetFromName						( MonoString* msNick );
		static unsigned int				GetPing							( TElement pThis );
		static long						GetMoney						( TElement pThis );
		static TElement					GetRandom						( void );
		static bool						IsMuted							( TElement pThis );
		static TElement					GetTeam							( TElement pThis );
		static unsigned int				GetWantedLevel					( TElement pThis );
		static MonoArray*				GetAlivePlayers					( void );
		static MonoArray*				GetDeadPlayers					( void );
		static unsigned int				GetIdleTime						( TElement pThis );
		static bool						IsMapForced						( TElement pThis );
		static MonoString*				GetNametagText					( TElement pThis );
		static MonoObject*				GetNametagColor					( TElement pThis );
		static bool						IsNametagShowing				( TElement pThis );
		static MonoString*				GetSerial						( TElement pThis );
		static MonoString*				GetUserName						( TElement pThis );
		static unsigned char			GetBlurLevel					( TElement pThis );
		static MonoString*				GetName							( TElement pThis );
		static MonoString*				GetIP							( TElement pThis );
		static TElement					GetAccount						( TElement pThis );
		static MonoString*				GetVersion						( TElement pThis );
		static MonoObject*				GetACInfo						( TElement pThis );
		static MonoString*				GetPlayerAnnounceValue			( TElement pThis, MonoString* msKey );

		// Player set functions
		static bool						SetMoney						( TElement pThis, int iAmount, bool bInstant );
		static bool						GiveMoney						( TElement pThis, int iAmount );
		static bool						TakeMoney						( TElement pThis, int iAmount );
		static bool						Spawn							( TElement pThis, MonoObject* vecPosition, int iRotation, int iSkinID, int iInterior, int iDimension, TElement pTeam );
		static bool						ShowHudComponent				( TElement pThis, MonoString* sComponent, bool bShow );
		static bool						SetWantedLevel					( TElement pThis, int iLevel );
		static bool						ForceMap						( TElement pThis, bool bForceOn );
		static bool						SetNametagText					( TElement pThis, MonoString* sText );
		static bool						SetNametagColor					( TElement pThis, int iRed, int iGreen, int iBlue );
		static bool						SetNametagShowing				( TElement pThis, bool bShowing );
		static bool						SetMuted						( TElement pThis, bool bMuted );
		static bool						SetBlurLevel					( TElement pThis, int iLevel );
		static bool						Redirect						( TElement pThis, MonoString* sServerIP, int iServerPort, MonoString* sServerPassword );
		static bool						SetName							( TElement pThis, MonoString* sName );
		static bool						DetonateSatchels				( TElement pThis );
		static bool						TakeScreenShot					( TElement pThis, int iWidth, int iHeight, MonoString* sTag, int iQuality, int iMaxBandwith );
		static bool						SetTeam							( TElement pThis, TElement pTeam );
		static bool						SetPlayerAnnounceValue			( TElement pThis, MonoString* msKey, MonoString* msValue );

		// Input funcs
		static bool						BindKey							( TElement pThis, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName, MonoString* msArguments );
		static bool						UnbindKey						( TElement pThis, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName );
		static bool						GetControlState					( TElement pThis, MonoString* msControl );
		static bool						IsControlEnabled				( TElement pThis, MonoString* msControl );
		
		static bool						SetControlState					( TElement pThis, MonoString* msControl, bool bState );
		static bool						ToggleControl					( TElement pThis, MonoString* msControl, bool bEnabled );
		static bool						ToggleAllControls				( TElement pThis, bool bGTAControls, bool bMTAControls, bool bEnabled );

		// Log in/out funcs
		static bool						LogIn							( TElement pPlayer, TElement pAccount, MonoString* msPassword );
		static bool						LogOut							( TElement pPlayer );

		// Admin funcs
		static bool						Kick							( TElement pPlayer, MonoString* msResponsible, MonoString* msReason );
		static TElement					Ban								( TElement pPlayer, bool bIP, bool bUsername, bool bSerial, TElement pResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban );
		
		// Cursor get funcs
		static bool						IsCursorShowing					( TElement pPlayer );
		
		// Cursor set funcs
		static bool						ShowCursor						( TElement pPlayer, bool bShow, bool bToggleControls );
		
		// Chat funcs
		static bool						ShowChat						( TElement pPlayer, bool bShow );

		// Camera get functions
		static MonoObject*				GetCameraMatrix					( TElement pPlayer );
		static TElement					GetCameraTarget					( TElement pPlayer );
		static unsigned char			GetCameraInterior				( TElement pPlayer );

		// Camera set functions
		static bool						SetCameraMatrix					( TElement pPlayer, MonoObject* pCameraMatrix );
		static bool						SetCameraTarget					( TElement pPlayer, TElement pTarget );
		static bool						SetCameraInterior				( TElement pPlayer, unsigned char ucInterior );
		static bool						FadeCamera						( TElement pPlayer, bool bFadeIn, float fFadeTime, MonoObject* pColor );
	};

	class Ped
	{
	public:
		// Ped get functions
		static void						Ctor							( TElement pThis, int iModelid, MonoObject* pMonoPosition, float fRot, bool bSynced );
		static float					GetArmor						( TElement pThis );    
		static bool						IsChoking						( TElement pThis );
		static bool						IsDead							( TElement pThis );
		static bool						IsDucked						( TElement pThis );    
		static float					GetStat							( TElement pThis, unsigned short usStat );
		static TElement					GetTarget						( TElement pThis );    
		static int						GetWeapon						( TElement pThis, int iWeaponSlot );
		static MonoString*				GetClothesTexture				( TElement pThis, unsigned char ucType );
		static MonoString*				GetClothesModel					( TElement pThis, unsigned char ucType );
		static bool						DoesHaveJetPack					( TElement pThis );
		static bool						IsOnGround						( TElement pThis );    
		static unsigned char			GetFightingStyle				( TElement pThis );
		static unsigned int				GetMoveAnim						( TElement pThis );
		static float					GetGravity						( TElement pThis );    
		static TElement					GetContactElement				( TElement pThis );
		static unsigned char			GetWeaponSlot					( TElement pThis );
		static bool						IsDoingGangDriveby				( TElement pThis );
		static bool						IsOnFire						( TElement pThis );
		static bool						IsHeadless						( TElement pThis );
		static bool						IsFrozen						( TElement pThis );
		static TElement					GetOccupiedVehicle				( TElement pThis );
		static unsigned int				GetOccupiedVehicleSeat			( TElement pThis );
		static bool						IsInVehicle						( TElement pThis );
		static short					GetWeaponProperty				( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty );
		static short					GetOriginalWeaponProperty		( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty );

		// Ped set functions
		static bool						SetArmor						( TElement pThis, float fArmor );
		static bool						Kill							( TElement pThis, TElement pKiller, unsigned char ucKillerWeapon, unsigned char ucBodyPart, bool bStealth );
		static bool						SetStat							( TElement pThis, unsigned short usStat, float fValue );
		static bool						AddClothes						( TElement pThis, MonoString* msTexture, MonoString* msModel, unsigned char ucType );
		static bool						RemoveClothes					( TElement pThis, unsigned char ucType, MonoString* msTexture, MonoString* msModel );
		static bool						GiveJetPack						( TElement pThis );
		static bool						RemoveJetPack					( TElement pThis );
		static bool						SetFightingStyle				( TElement pThis, unsigned char ucStyle );
		static bool						SetMoveAnim						( TElement pThis, unsigned int iMoveAnim );
		static bool						SetGravity						( TElement pThis, float fGravity );
		static bool						SetChoking						( TElement pThis, bool bChoking );
		static bool						SetWeaponSlot					( TElement pThis, unsigned char ucWeaponSlot );
		static bool						WarpIntoVehicle					( TElement pThis, TElement pVehicle, unsigned int uiSeat );
		static bool						RemoveFromVehicle				( TElement pThis );
		static bool						SetDoingGangDriveby				( TElement pThis, bool bGangDriveby );
		static bool						SetAnimation					( TElement pThis, MonoString* msBlockName, MonoString* msAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame );
		static bool						SetAnimationProgress			( TElement pThis, MonoString* msAnimName, float fProgress );
		static bool						SetOnFire						( TElement pThis, bool bIsOnFire );
		static bool						SetHeadless						( TElement pThis, bool bIsHeadless );
		static bool						SetFrozen						( TElement pThis, bool bIsFrozen );
		static bool						ReloadWeapon					( TElement pThis );
		static bool						SetWeaponProperty				( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty, short uData );

		// Ped body?
		static MonoString*				GetBodyPartName					( unsigned char ucID );
		static MonoArray*				GetClothesByTypeIndex			( unsigned char ucType, unsigned char ucIndex );
		static MonoArray*				GetTypeIndexFromClothes			( MonoString* msTexture, MonoString* msModel );
		static MonoString*				GetClothesTypeName				( unsigned char ucType );

		// Weapon give/take functions
		static bool						GiveWeapon						( TElement pPed, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent = false );
		static bool						TakeWeapon						( TElement pPed, unsigned char ucWeaponID, unsigned short usAmmo = 9999 );
		static bool						TakeAllWeapons					( TElement pPed );
		static bool						SetWeaponAmmo					( TElement pPed, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip );
	};

	class Vehicle
	{
	public:
		// Vehicle create/destroy functions
		static void						Ctor	( TElement pThis, int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );
		
		// Vehicle get functions
		static MonoString*				GetVehicleType					( TElement pThis );
		static MonoArray*				GetVariant						( TElement pThis );
		static MonoObject*				GetColor						( TElement pThis );
		static unsigned short			GetModelFromName				( MonoString* msName );
		static bool						GetLandingGearDown				( TElement pThis );
		static unsigned char			GetMaxPassengers				( TElement pThis );
		static MonoString*				GetName							( TElement pThis );
		static MonoString*				GetNameFromModel				( unsigned short usModel );
		static TElement					GetOccupant						( TElement pThis, unsigned int uiSeat );
		static MonoArray*				GetOccupants					( TElement pThis );
		static TElement					GetController					( TElement pThis );
		static bool						GetSirensOn						( TElement pThis );
		static MonoObject*				GetTurnVelocity					( TElement pThis );
		static MonoObject*				GetTurretPosition				( TElement pThis );
		static bool						IsLocked						( TElement pThis );
		static MonoArray*				GetOfType						( unsigned int uiModel );       
		static unsigned short			GetUpgradeOnSlot				( TElement pThis, unsigned char ucSlot );
		static MonoArray*				GetUpgrades						( TElement pThis );
//		static MonoString*				GetUpgradeSlotName				( unsigned char ucSlot );
		static MonoString*				GetUpgradeSlotName				( unsigned short usUpgrade );
		static MonoArray*				GetCompatibleUpgrades			( TElement pThis );
		static unsigned char			GetDoorState					( TElement pThis, unsigned char ucDoor );
		static MonoObject*				GetWheelStates					( TElement pThis );
		static unsigned char			GetLightState					( TElement pThis, unsigned char ucLight );
		static unsigned char			GetPanelState					( TElement pThis, unsigned char ucPanel );
		static unsigned char			GetOverrideLights				( TElement pThis );
		static TElement					GetTowedByVehicle				( TElement pThis );
		static TElement					GetTowingVehicle				( TElement pThis );
		static unsigned char			GetPaintjob						( TElement pThis );
		static MonoString*				GetPlateText					( TElement pThis );
		static bool						IsDamageProof					( TElement pThis );
		static bool						IsFuelTankExplodable			( TElement pThis );
		static bool						IsFrozen						( TElement pThis );
		static bool						IsOnGround						( TElement pThis );
		static bool						GetEngineState					( TElement pThis );
		static bool						IsTrainDerailed                 ( TElement pThis );
		static bool						IsTrainDerailable               ( TElement pThis );
		static bool						GetTrainDirection               ( TElement pThis );
		static float					GetTrainSpeed                   ( TElement pThis );
		static bool						IsBlown							( TElement pThis );
		static MonoObject*				GetHeadLightColor				( TElement pThis );
		static float					GetDoorOpenRatio				( TElement pThis, unsigned char ucDoor );
		static bool						IsTaxiLightOn					( TElement pThis );

		// Vehicle set functions
		static bool						Fix								( TElement pThis );
		static bool						Blow							( TElement pThis, bool bExplode );
		static bool						SetTurnVelocity					( TElement pThis, MonoObject* pVelocity );
		static bool						SetColor						( TElement pThis, MonoObject* pColor1, MonoObject* pColor2, MonoObject* pColor3, MonoObject* pColor4 );
		static bool						SetLandingGearDown				( TElement pThis, bool bLandingGearDown );
		static bool						SetLocked						( TElement pThis, bool bLocked );
		static bool						SetDoorsUndamageable			( TElement pThis, bool bDoorsUndamageable );
		static bool						SetSirensOn						( TElement pThis, bool bSirensOn );
		static bool						SetTaxiLightOn					( TElement pThis, bool bTaxiLightState );
		static bool						AddUpgrade						( TElement pThis, unsigned short usUpgrade );
		static bool						RemoveUpgrade					( TElement pThis, unsigned short usUpgrade );
		static bool						SetDoorState					( TElement pThis, unsigned char ucDoor, unsigned char ucState );
		static bool						SetWheelStates					( TElement pThis, int iFrontLeft, int iRearLeft, int iFrontRight, int iRearRight );
		static bool						SetLightState					( TElement pThis, unsigned char ucLight, unsigned char ucState );
		static bool						SetPanelState					( TElement pThis, unsigned char ucPanel, unsigned char ucState );
		static bool						SetIdleRespawnDelay				( TElement pThis, unsigned long ulTime );
		static bool						SetRespawnDelay					( TElement pThis, unsigned long ulTime );
		static bool						SetRespawnPosition				( TElement pThis, MonoObject* pPosition, MonoObject* pRotation );
		static bool						ToggleRespawn					( TElement pThis, bool bRespawn );
		static bool						ResetExplosionTime				( TElement pThis );
		static bool						ResetIdleTime					( TElement pThis );
		static bool						Spawn							( TElement pThis, MonoObject* pPosition, MonoObject* pRotation );
		static bool						Respawn							( TElement pThis );
		static bool						SetOverrideLights				( TElement pThis, unsigned char ucLights );
		static bool						AttachTrailer					( TElement pThis, TElement pTrailer );
		static bool						DetachTrailer					( TElement pThis, TElement pTrailer );
		static bool						SetEngineState					( TElement pThis, bool bState );
		static bool						SetDirtLevel					( TElement pThis, float fDirtLevel );
		static bool						SetDamageProof					( TElement pThis, bool bDamageProof );
		static bool						SetPaintjob						( TElement pThis, unsigned char ucPaintjob );
		static bool						SetFuelTankExplodable			( TElement pThis, bool bExplodable );
		static bool						SetTrainDerailed                ( TElement pThis, bool bDerailed );
		static bool						SetTrainDerailable              ( TElement pThis, bool bDerailable );
		static bool						SetTrainDirection               ( TElement pThis, bool bDireciton );
		static bool						SetTrainSpeed                   ( TElement pThis, float fSpeed );
		static bool						SetHeadLightColor				( TElement pThis, MonoObject* pColor );
		static bool						SetTurretPosition				( TElement pThis, MonoObject* pPosition );
		static bool						SetDoorOpenRatio				( TElement pThis, unsigned char ucDoor, float fRatio, unsigned long ulTime );
		static bool						SetVariant						( TElement pThis, unsigned char ucVariant, unsigned char ucVariant2 );
		static bool						GiveSirens						( TElement pThis, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360 = false, bool bCheckLosFlag = true, bool bUseRandomiserFlag = true, bool bSilentFlag = false );
		static bool						RemoveSirens					( TElement pThis );
		static bool						SetSirens						( TElement pThis, unsigned char ucSirenID, MonoObject* pPosition, MonoObject* pColor, float fMinAlpha );
		static MonoArray*				GetSirens						( TElement pThis );
		static MonoObject*				GetSirenParams					( TElement pThis );
		static bool						SetPlateText					( TElement pThis, MonoString* msName );
	};
	
	class Marker
	{
	public:
		// Marker create/destroy functions
		static void						Ctor							( TElement pThis, MonoObject* pPosition, MonoString* szType, float fSize, MonoObject* color, TElement pVisibleTo );

		// Marker get functions
		static unsigned int				GetCount						( void );
		static MonoString*				GetMarkerType					( TElement pThis );
		static float					GetSize							( TElement pThis );
		static MonoObject*				GetColor						( TElement pThis );
		static MonoObject*				GetTarget						( TElement pThis );
		static MonoString*				GetIcon							( TElement pThis );

		// Marker set functions
		static bool						SetType							( TElement pThis, MonoString* szType );
		static bool						SetSize							( TElement pThis, float fSize );
		static bool						SetColor						( TElement pThis, MonoObject* color );
		static bool						SetTarget						( TElement pThis, MonoObject* pTarget );
		static bool						SetIcon							( TElement pThis, MonoString* szIcon );
	};

	class Blip
	{
	public:
		// Blip create/destroy functions
		static void						Ctor							( TElement pThis, MonoObject* vecPosition, unsigned char ucIcon, unsigned char ucSize, MonoObject* color, short sOrdering, unsigned short usVisibleDistance, TElement pVisibleTo );
		
		// Blip get functions
		static unsigned char			GetIcon							( TElement pThis );
		static unsigned char			GetSize							( TElement pThis );
		static MonoObject*				GetColor						( TElement pThis );
		static short					GetOrdering						( TElement pThis );
		static unsigned short			GetVisibleDistance				( TElement pThis );

		// Blip set functions
		static bool						SetIcon							( TElement pThis, unsigned char ucIcon );
		static bool						SetSize							( TElement pThis, unsigned char ucSize );
		static bool						SetColor						( TElement pThis, MonoObject* color );
		static bool						SetOrdering						( TElement pThis, short sOrdering );
		static bool						SetVisibleDistance				( TElement pThis, unsigned short usVisibleDistance );
	};

	class Object
	{
	public:
		// Object create/destroy functions
		static void						Ctor							( TElement pThis, unsigned short usModelID, MonoObject* pPosition, MonoObject* pRotation, bool bIsLowLod );

		// Object get functions
		static MonoObject*				GetScale						( TElement pThis );

		// Object set functions
		static bool						SetScale						( TElement pThis, MonoObject* pScale );
		static bool						Move							( TElement pThis, unsigned long ulTime, MonoObject* pPosition, MonoObject* pRotation, MonoString* msEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot );
		static bool						Stop							( TElement pThis );
	};

	class RadarArea
	{
	public:
		// Radar area create/destroy funcs
		static void						Ctor							( TElement pThis, MonoObject* pPosition, MonoObject* pSize, MonoObject* pColor, TElement pVisibleTo );

		// Radar area get funcs
		static MonoObject*				GetSize							( TElement pThis );
		static MonoObject*				GetColor						( TElement pThis );
		static bool						IsFlashing						( TElement pThis );
		static bool						IsInside						( TElement pThis, MonoObject* pPosition );

		// Radar area set funcs
		static bool						SetSize							( TElement pThis, MonoObject* pSize );
		static bool						SetColor						( TElement pThis, MonoObject* pColor );
		static bool						SetFlashing						( TElement pThis, bool bFlashing );
	};

	class Pickup
	{
	public:
		// Pickup create/destroy funcs
		static void						Ctor							( TElement pThis, MonoObject* pPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval, double dSix );

		// Pickup get funcs
		static unsigned char			GetPickupType					( TElement pThis );
		static unsigned char			GetWeapon						( TElement pThis );
		static float					GetAmount						( TElement pThis );
		static unsigned short			GetAmmo							( TElement pThis );
		static unsigned long			GetRespawnInterval				( TElement pThis );
		static bool						IsSpawned						( TElement pThis );

		// Pickup set funcs
		static bool						SetType							( TElement pThis, unsigned char ucType, double dThree, double dFour );
		static bool						SetRespawnInterval				( TElement pThis, unsigned long ulInterval );
		static bool						Use								( TElement pThis, TElement pPlayer );
	};

	class ColCircle
	{
	public:
		static void						Ctor							( TElement pThis, MonoObject* pPosition, float fRadius );
	};

	class ColCuboid
	{
	public:
		static void						Ctor							( TElement pThis, MonoObject* pPosition, MonoObject* vecSize );
	};

	class ColSphere
	{
	public:
		static void						Ctor							( TElement pThis, MonoObject* pPosition, float fRadius );
	};

	class ColRectangle
	{
	public:
		static void						Ctor							( TElement pThis, MonoObject* pPosition, MonoObject* vecSize );
	};

	class ColPolygon
	{
	public:
		static void						Ctor							( TElement pThis, MonoObject* vec1, MonoObject* vec2, MonoObject* vec3, MonoObject* vec4, MonoArray* vecPointList );
	};

	class ColTube
	{
	public:
		static void						Ctor							( TElement pThis, MonoObject* pPosition, float fRadius, float fHeight );
	};

	class Explosion
	{
	public:
		// Explosion funcs
		static bool						Create							( MonoObject* pPosition, unsigned char ucType, TElement pCreator );
	};

	class Audio
	{
	public:
		// Audio funcs
		static bool						PlayFrontEnd					( TElement pThis, unsigned char ucSound );
		static bool						PlayMission						( TElement pThis, MonoObject* vecPosition, unsigned short usSlot );
	};

	class Team
	{
	public:
		// Team get funcs
		static void						Ctor							( TElement pThis, MonoString* msTeamName, MonoObject* pColor );
		static TElement					GetFromName						( MonoString* msTeamName );
		static MonoString*				GetName							( TElement pThis );
		static MonoObject*				GetColor						( TElement pThis );
		static unsigned int				CountPlayers					( TElement pThis );
		static bool						GetFriendlyFire					( TElement pThis );

		// Team set funcs
		static bool						SetName							( TElement pThis, MonoString* msTeamName );
		static bool						SetColor						( TElement pThis, MonoObject* pColor );
		static bool						SetFriendlyFire					( TElement pThis, bool bFriendlyFire );
	};

	class Water
	{
	public:
		// Water funcs
		static void						Ctor							( TElement pThis, MonoObject* pV1, MonoObject* pV2, MonoObject* pV3, MonoObject* pV4, bool bShallow );
		static bool						SetLevel						( TElement pThis, float fLevel );
		static bool						SetLevelAll						( float fLevel );
		static bool						SetLevelWorld					( float fLevel, bool bIncludeWorldNonSeaLevel );
		static bool						ResetLevelWorld					( void );
		static MonoObject*				GetVertexPosition				( TElement pThis, int iVertexIndex );
		static bool						SetVertexPosition				( TElement pThis, int iVertexIndex, MonoObject* vecPosition );
		static MonoObject*				GetColor						( void );
		static bool						SetColor						( MonoObject* pColor );
		static bool						ResetColor						( void );
	};

	class World
	{
	public:
		// General world get funcs
		static MonoArray*				GetTime                         ( void );
		static MonoArray*				GetWeather                      ( void );
		static MonoString*				GetZoneName                     ( MonoObject* vecPosition, bool bCitiesOnly );
		static float					GetGravity                      ( void );
		static float					GetGameSpeed                    ( void );
		static float					GetWaveHeight                   ( void );
		static unsigned short			GetFPSLimit                     ( void );
		static unsigned long			GetMinuteDuration               ( void );
		static bool						IsGarageOpen                    ( unsigned char ucGarageID );
		static unsigned char			GetTrafficLightState            ( void );
		static bool						GetTrafficLightsLocked          ( void );
		static float					GetJetpackMaxHeight             ( void );
		static float					GetAircraftMaxVelocity          ( void );
		static bool						GetInteriorSoundsEnabled        ( void );
		static float					GetRainLevel                    ( void );
		static float					GetSunSize                      ( void );
		static MonoArray*				GetSunColor                     ( void );
		static MonoObject*				GetWindVelocity                 ( void );
		static float					GetFarClipDistance              ( void );
		static float					GetFogDistance                  ( void );
		static float					GetAircraftMaxHeight            ( void );
		static bool						GetOcclusionsEnabled            ( void );
		static int						GetMoonSize                     ( void );
		static MonoArray*				GetSkyGradient                  ( void );
		static MonoObject*				GetHeatHaze                     ( void );
		static bool						GetJetpackWeaponEnabled         ( unsigned int uiWeaponType );
		static bool						GetCloudsEnabled                ( void );

		// General world set funcs
		static bool						SetTime                         ( unsigned char ucHour, unsigned char ucMinute );
		static bool						SetWeather                      ( unsigned char ucWeather );
		static bool						SetWeatherBlended               ( unsigned char ucWeather );
		static bool						SetGravity                      ( float fGravity );
		static bool						SetGameSpeed				    ( float fSpeed );
		static bool						SetWaveHeight                   ( float fHeight );
		static bool						SetSkyGradient                  ( MonoObject* pTopColor, MonoObject* pBottomColor );
		static bool						ResetSkyGradient                ( void );
		static bool						SetHeatHaze                     ( MonoObject* heatHazeSettings );
		static bool						ResetHeatHaze                   ( void );
		static bool						SetFPSLimit                     ( unsigned short usLimit, bool bSave );
		static bool						SetMinuteDuration               ( unsigned long ulDuration );
		static bool						SetGarageOpen                   ( unsigned char ucGarageID, bool bIsOpen );
		static bool						SetGlitchEnabled                ( MonoString* msGlitchName, bool bEnabled );
		static bool						IsGlitchEnabled                 ( MonoString* msGlitchName );
		static bool						SetJetpackWeaponEnabled         ( unsigned int uiWeaponType, bool bEnabled );
		static bool						SetCloudsEnabled                ( bool bEnabled );
		static bool						SetTrafficLightState            ( unsigned char ucState, bool bForced = false );
		static bool						SetTrafficLightsLocked          ( bool bLocked );
		static bool						SetJetpackMaxHeight             ( float fMaxHeight );
		static bool						SetInteriorSoundsEnabled        ( bool bEnable );
		static bool						SetRainLevel                    ( float fRainLevel );
		static bool						SetSunSize                      ( float fSunSize );
		static bool						SetSunColor                     ( MonoObject* pCoreColor, MonoObject* pCoronaColor );
		static bool						SetWindVelocity                 ( MonoObject* pVelocity );
		static bool						SetFarClipDistance              ( float fFarClip );
		static bool						SetFogDistance                  ( float fFogDist );
		static bool						SetAircraftMaxHeight            ( float fMaxHeight );
		static bool						SetAircraftMaxVelocity          ( float fVelocity );
		static bool						SetOcclusionsEnabled            ( bool bEnabled );
		static bool						ResetRainLevel                  ( void );
		static bool						ResetSunSize                    ( void );
		static bool						ResetSunColor                   ( void );
		static bool						ResetWindVelocity               ( void );
		static bool						ResetFarClipDistance            ( void );
		static bool						ResetFogDistance                ( void );
		static bool						RemoveWorldModel                ( unsigned short usModel, float fRadius, MonoObject* vecPosition, char cInterior );
		static bool						RestoreWorldModel               ( unsigned short usModel, float fRadius, MonoObject* vecPosition, char cInterior );
		static bool						RestoreAllWorldModels           ( void );
		static bool						SetMoonSize                     ( int iMoonSize );
		static bool						ResetMoonSize                   ( void );
	};

	class Account
	{
	public:
		// Account get funcs
		static TElement					Get								( MonoString* msName, MonoString* msPassword );
		static MonoArray*				GetAll							( void );
		static TElement					GetPlayer						( TElement pAccount );
		static bool						IsGuest							( TElement pAccount );
		static MonoObject*				GetData							( TElement pAccount, MonoString* szKey );
	//	static MonoArray*				GetAllData						( TElement pAccount );
		static MonoString*				GetSerial						( TElement pAccount );
		static MonoArray*				GetBySerial						( MonoString* msSerial );

		// Account set funcs
		static TElement					Add								( MonoString* msName, MonoString* msPassword );
		static bool						Remove							( TElement pAccount );
		static bool						SetPassword						( TElement pAccount, MonoString* msPassword );
		static bool						SetData							( TElement pAccount, MonoString* msKey, MonoObject* pArgument );
		static bool						CopyData						( TElement pAccount, TElement pFromAccount );
	};

	class Ban
	{
	public:
		static TElement					Add								( MonoString* msIP, MonoString* msUsername, MonoString* msSerial, TElement pResponsible, MonoString* msReason, int iUnban );
		static bool						Remove							( TElement pBan, TElement pResponsible );

		static MonoArray*				GetAll							( void );
		static bool						Reload							( void );

		static MonoString*				GetIP							( TElement pBan );
		static MonoString*				GetSerial						( TElement pBan );
		static MonoString*				GetUsername						( TElement pBan );
		static MonoString*				GetNick							( TElement pBan );
		static MonoString*				GetReason						( TElement pBan );
		static MonoString*				GetAdmin						( TElement pBan );

		static int						GetBanTime						( TElement pBan );
		static int						GetUnbanTime					( TElement pBan );

		static bool						SetUnbanTime					( TElement pBan, int time );
		static bool						SetReason						( TElement pBan, MonoString* msReason );
		static bool						SetAdmin						( TElement pBan, MonoString* msAdminName );
	};

	class Resource
	{
	public:
		// Resource funcs
		static void						Ctor							( TElement pThis, MonoString* msResourceName, MonoString* msOrganizationalDir );
		static TElement					Copy							( TElement pResource, MonoString* msNewResourceName, MonoString* msOrganizationalDir );
		static TElement					GetRootElement					( TElement pResource = nullptr );
		static TElement					GetMapRootElement				( TElement pResource, MonoString* msMap );
		static TElement					GetDynamicElementRoot			( TElement pResource );
	//	static CXMLNode*				AddMap							( MonoString* msFilePath, MonoString* msMapName, int iDimension );
	//	static CXMLNode*				AddConfig						( MonoString* msFilePath, MonoString* msConfigName, int iType );
		static bool						RemoveFile						( TElement pResource, MonoString* msFilename );
	//	static CXMLNode					AddConfig						( MonoString* msFilePath, MonoString* msFileType );
	//	static CXMLNode					AddMap							( MonoString* msFilePath, unsigned int uiDimension = 0 );
	//	static CXMLNode					GetConfig						( MonoString* msFilePath );
	//	static CLuaArguments*			GetExportedFunctions			( TElement pResource );
		static TElement					GetFromName						( MonoString* msResourceName );
		static MonoString*				GetInfo							( TElement pResource, MonoString* msAttribute );
		static unsigned int				GetLastStartTime				( TElement pResource );
		static MonoString*				GetLoadFailureReason			( TElement pResource );
		static unsigned int				GetLoadTime						( TElement pResource );
		static MonoString*				GetName							( TElement pResource );
		static MonoArray*				GetResources					( void );
		static MonoString*				GetState						( TElement pResource );
		static TElement					GetCurrent						( void );
		static bool						Refresh							( bool refreshAll = false );
		static bool						RemoveDefaultSetting			( TElement pResource, MonoString* msSettingName );
		static bool						Start							( TElement pResource, bool persistent = false, bool startIncludedResources = true, bool loadServerConfigs = true, bool loadMaps = true, bool loadServerScripts = true, bool loadHTML = true, bool loadClientConfigs = true, bool loadClientScripts = true, bool loadFiles = true );
		static bool						Restart							( TElement pResource );
		static bool						Stop							( TElement pResource );
		static bool						SetDefaultSetting				( TElement pResource, MonoString* msSettingName, MonoString* msSettingValue );
	//	static bool						SetDefaultSetting				( TElement pResource, MonoString* msSettingName, int iSettingValue );
	//	static bool						SetDefaultSetting				( TElement pResource, MonoString* msSettingName, float fSettingValue );
		static bool						SetInfo							( TElement pResource, MonoString* msAttribute, MonoString* msValue );
		static bool						Rename							( MonoString* msResourceName, MonoString* msNewResourceName, MonoString* msOrganizationalPath );
		static bool						Delete							( MonoString* msResourceName );
	//	static CLuaArguments*			GetACLRequests					( TElement pResource );
		static bool						UpdateACLRequest				( TElement pResource, MonoString* msRightName, bool bAccess, MonoString* msByWho );
	};
};

#endif