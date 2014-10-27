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

#include "Common.h"
#include "lua/CLuaFunctionDefinitions.h"

#include "CMonoObject.h"

extern ILuaModuleManager10	*g_pModuleManager;
extern CResourceManager	*g_pResourceManager;

#define RESOURCE g_pResourceManager->GetFromList( mono_domain_get() )

#define MONO_DECLARE(a,b) mono_add_internal_call("MultiTheftAuto.Native."#a"::"#b,CMonoFunctions::a::b)

class CMonoFunctions
{
public:
	static void				AddInternals( void );

	class Debug
	{
	public:
		static void			Log									( MonoString *string );
		static void			Info								( MonoString *string );
		static void			Error								( MonoString *string );
	};

	class Config
	{
	public:
		static MonoString*	Get									( MonoString *msKey );
		static bool			Set									( MonoString *msKey, MonoString *msValue );
	};

	class Server
	{
	public:
		static unsigned int				GetMaxPlayers			( void );
		static bool						SetMaxPlayers			( unsigned int uiMax );
		static bool						OutputChatBox			( MonoString* szText, DWORD pElement, MonoObject* pColor, bool bColorCoded );
		static bool						OutputConsole			( MonoString* szText, DWORD pElement );
		static bool						SetPassword				( MonoString* msPassword, bool bSave );
		static MonoObject*				GetVersion				( void );
	};

	class Element
	{
	public:
		// Element create/destroy
		static DWORD			Create								( MonoString* msTypeName, MonoString* msID );
		static bool				Destroy								( DWORD pUserData );
		static DWORD			Clone								( DWORD pUserData, MonoObject* vecPosition, bool bCloneElement );

		// Element get funcs
		static MonoArray*		GetByType							( MonoString* msType, DWORD pStartElement );

		static bool				IsElement							( DWORD pUserData );
		static MonoString*		GetType								( DWORD pUserData );
		static DWORD			GetByID								( MonoString* msID, unsigned int uiIndex );
		static DWORD			GetByIndex							( int iIndex );
		static DWORD			GetChild							( DWORD pUserData, int iIndex );
		static int				GetChildrenCount					( DWORD pUserData );
		static MonoString*		GetID								( DWORD pUserData );
		static MonoObject*		GetData								( DWORD pUserData, MonoString* sKey, bool bInherit = true );
		static MonoArray*		GetAllData							( DWORD pUserData );
		static unsigned int		GetParent							( DWORD pUserData );
		static MonoObject*		GetPosition							( DWORD pUserData );
		static MonoObject*		GetRotation							( DWORD pUserData );
		static MonoObject*		GetVelocity							( DWORD pUserData );
		static unsigned char	GetInterior							( DWORD pUserData );
		static bool				IsWithinColShape					( DWORD pUserData );
		static bool				IsWithinMarker						( DWORD pUserData );
		static unsigned short	GetDimension						( DWORD pUserData );
		static MonoString*		GetZoneName							( DWORD pUserData, bool bCitiesOnly = false );
		static bool				IsAttached							( DWORD pUserData );
		static DWORD			GetAttachedTo						( DWORD pUserData );
		static DWORD			GetColShape							( DWORD pUserData );
		static unsigned char	GetAlpha							( DWORD pUserData );
		static bool				IsDoubleSided						( DWORD pUserData );
		static float			GetHealth							( DWORD pUserData );
		static unsigned short	GetModel							( DWORD pUserData );
		static bool				IsInWater							( DWORD pUserData );
		static MonoObject*		GetAttachedOffsetPosition			( DWORD pUserData );
		static MonoObject*		GetAttachedOffsetRotation			( DWORD pUserData );
		static DWORD			GetSyncer							( DWORD pUserData );
		static bool				GetCollisionsEnabled				( DWORD pUserData );
		static bool				IsFrozen							( DWORD pUserData );
		static DWORD			GetLowLod							( DWORD pUserData );
		static bool				IsLowLod							( DWORD pUserData );

		// Element set funcs
		static bool				ClearVisibleTo						( DWORD pUserData );
		static bool				SetID								( DWORD pUserData, MonoString* msID );
		static bool				SetData								( DWORD pUserData, MonoString* msKey, CLuaArgument& Variable );
		static bool				RemoveData							( DWORD pUserData, MonoString* msKey );
		static bool				SetParent							( DWORD pUserData, DWORD pTarget );
		static bool				SetPosition							( DWORD pUserData, MonoObject* pPosition, bool bWarp );
		static bool				SetRotation							( DWORD pUserData, MonoObject* pRotation, MonoString* msRotationOrder, bool bNewWay );
		static bool				SetVelocity							( DWORD pUserData, MonoObject* pVelocity );
		static bool				SetVisibleTo						( DWORD pUserData, DWORD pTarget, bool bVisible );
		static bool				SetInterior							( DWORD pUserData, int iInterior );
		static bool				SetDimension						( DWORD pUserData, int iDimension );
		static bool				Attach								( DWORD pUserData, DWORD pTarget, MonoObject* pPosition, MonoObject* pRotation );
		static bool				Detach								( DWORD pUserData, DWORD pTarget );
		static bool				SetAlpha							( DWORD pUserData, int iAlpha );
		static bool				SetDoubleSided						( DWORD pUserData, bool bDoubleSided );
		static bool				SetHealth							( DWORD pUserData, float fHealth );
		static bool				SetModel							( DWORD pUserData, int iModel );
		static bool				SetAttachedOffsets					( DWORD pUserData, MonoObject* pPosition, MonoObject* pRotation );
		static bool				SetSyncer							( DWORD pUserData, DWORD pPlayer );
		static bool				SetCollisionsEnabled				( DWORD pUserData, bool bEnabled );
		static bool				SetFrozen							( DWORD pUserData, bool bFrozen );
		static bool				SetLowLod							( DWORD pUserData, bool bEnabled );
	};

	class Player
	{
	public:
		// Player get functions
		static unsigned int			GetCount						( void );
		static DWORD                GetFromName						( MonoString* msNick );
		static unsigned int			GetPing							( DWORD pUserData );
		static long					GetMoney						( DWORD pUserData );
		static DWORD                GetRandom						( void );
		static bool                 IsMuted							( DWORD pUserData );
		static DWORD                GetTeam							( DWORD pUserData );
		static unsigned int			GetWantedLevel					( DWORD pUserData );
		static MonoArray*			GetAlivePlayers					( void );
		static MonoArray*			GetDeadPlayers					( void );
		static unsigned int			GetIdleTime						( DWORD pUserData );
		static bool					IsMapForced						( DWORD pUserData );
		static MonoString*			GetNametagText					( DWORD pUserData );
		static MonoObject*			GetNametagColor					( DWORD pUserData );
		static bool					IsNametagShowing				( DWORD pUserData );
		static MonoString*          GetSerial						( DWORD pUserData );
		static MonoString*          GetUserName						( DWORD pUserData );
		static unsigned char		GetBlurLevel					( DWORD pUserData );
		static MonoString*			GetName							( DWORD pUserData );
		static MonoString*			GetIP							( DWORD pUserData );
		static DWORD                GetAccount						( DWORD pUserData );
		static MonoString*          GetVersion						( DWORD pUserData );
		static MonoObject*			GetACInfo						( DWORD pUserData );

		// Player set functions
		static bool					SetMoney						( DWORD pUserData, int iAmount, bool bInstant );
		static bool					GiveMoney						( DWORD pUserData, int iAmount );
		static bool					TakeMoney						( DWORD pUserData, int iAmount );
		static bool					Spawn							( DWORD pUserData, MonoObject* vecPosition, int iRotation, int iSkinID, int iInterior, int iDimension, DWORD pTeam );
		static bool					ShowHudComponent				( DWORD pUserData, MonoString* sComponent, bool bShow );
		static bool					SetWantedLevel					( DWORD pUserData, int iLevel );
		static bool					ForceMap						( DWORD pUserData, bool bForceOn );
		static bool					SetNametagText					( DWORD pUserData, MonoString* sText );
		static bool					SetNametagColor					( DWORD pUserData, int iRed, int iGreen, int iBlue );
		static bool					SetNametagShowing				( DWORD pUserData, bool bShowing );
		static bool					SetMuted						( DWORD pUserData, bool bMuted );
		static bool					SetBlurLevel					( DWORD pUserData, int iLevel );
		static bool					Redirect						( DWORD pUserData, MonoString* sServerIP, int iServerPort, MonoString* sServerPassword );
		static bool					SetName							( DWORD pUserData, MonoString* sName );
		static bool					DetonateSatchels				( DWORD pUserData );
		static bool					TakeScreenShot					( DWORD pUserData, int iWidth, int iHeight, MonoString* sTag, int iQuality, int iMaxBandwith );
		static bool					SetTeam							( DWORD pUserData, DWORD pTeam );

		// Input funcs
		static bool					BindKey							( DWORD pUserData, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName, MonoString* msArguments );
		static bool					UnbindKey						( DWORD pUserData, MonoString* msKey, MonoString* msHitState, MonoString* msCommandName );
		static bool					GetControlState					( DWORD pUserData, MonoString* msControl );
		static bool					IsControlEnabled				( DWORD pUserData, MonoString* msControl );
		
		static bool					SetControlState					( DWORD pUserData, MonoString* msControl, bool bState );
		static bool					ToggleControl					( DWORD pUserData, MonoString* msControl, bool bEnabled );
		static bool					ToggleAllControls				( DWORD pUserData, bool bGTAControls, bool bMTAControls, bool bEnabled );

		// Log in/out funcs
		static bool					LogIn							( DWORD pPlayer, DWORD pAccount, MonoString* msPassword );
		static bool					LogOut							( DWORD pPlayer );

		// Admin funcs
		static bool					Kick							( DWORD pPlayer, MonoString* msResponsible, MonoString* msReason );
		static DWORD				Ban								( DWORD pPlayer, bool bIP, bool bUsername, bool bSerial, DWORD pResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban );
		
		// Cursor get funcs
		static bool					IsCursorShowing					( DWORD pPlayer );
		
		// Cursor set funcs
		static bool					ShowCursor						( DWORD pPlayer, bool bShow, bool bToggleControls );
		
		// Chat funcs
		static bool					ShowChat						( DWORD pPlayer, bool bShow );

		// Camera get functions
		static MonoObject*			GetCameraMatrix					( DWORD pPlayer );
		static DWORD				GetCameraTarget					( DWORD pPlayer );
		static unsigned char		GetCameraInterior				( DWORD pPlayer );

		// Camera set functions
		static bool					SetCameraMatrix					( DWORD pPlayer, MonoObject* pCameraMatrix );
		static bool					SetCameraTarget					( DWORD pPlayer, DWORD pTarget );
		static bool					SetCameraInterior				( DWORD pPlayer, unsigned char ucInterior );
		static bool					FadeCamera						( DWORD pPlayer, bool bFadeIn, float fFadeTime, MonoObject* pColor );
	};

	class Ped
	{
	public:
		// Ped get functions
		static DWORD				Create							( int iModelid, MonoObject* pMonoPosition, float fRot, bool bSynced );
		static float				GetArmor						( DWORD pUserData );    
		static bool					IsChoking						( DWORD pUserData );
		static bool					IsDead							( DWORD pUserData );
		static bool					IsDucked						( DWORD pUserData );    
		static float				GetStat							( DWORD pUserData, unsigned short usStat );
		static DWORD				GetTarget						( DWORD pUserData );    
		static int					GetWeapon						( DWORD pUserData, int iWeaponSlot );
		static MonoString*			GetClothesTexture				( DWORD pUserData, unsigned char ucType );
		static MonoString*			GetClothesModel					( DWORD pUserData, unsigned char ucType );
		static bool					DoesHaveJetPack					( DWORD pUserData );
		static bool					IsOnGround						( DWORD pUserData );    
		static unsigned char		GetFightingStyle				( DWORD pUserData );
		static unsigned int			GetMoveAnim						( DWORD pUserData );
		static float				GetGravity						( DWORD pUserData );    
		static DWORD				GetContactElement				( DWORD pUserData );
		static unsigned char		GetWeaponSlot					( DWORD pUserData );
		static bool					IsDoingGangDriveby				( DWORD pUserData );
		static bool					IsOnFire						( DWORD pUserData );
		static bool					IsHeadless						( DWORD pUserData );
		static bool					IsFrozen						( DWORD pUserData );
		static DWORD				GetOccupiedVehicle				( DWORD pUserData );
		static unsigned int			GetOccupiedVehicleSeat			( DWORD pUserData );
		static bool					IsInVehicle						( DWORD pUserData );
		static short				GetWeaponProperty				( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty );
		static short				GetOriginalWeaponProperty		( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty );

		// Ped set functions
		static bool                 SetArmor						( DWORD pUserData, float fArmor );
		static bool                 Kill							( DWORD pUserData, DWORD pKiller, unsigned char ucKillerWeapon, unsigned char ucBodyPart, bool bStealth );
		static bool                 SetStat							( DWORD pUserData, unsigned short usStat, float fValue );
		static bool                 AddClothes						( DWORD pUserData, MonoString* msTexture, MonoString* msModel, unsigned char ucType );
		static bool                 RemoveClothes					( DWORD pUserData, unsigned char ucType, MonoString* msTexture, MonoString* msModel );
		static bool                 GiveJetPack						( DWORD pUserData );
		static bool                 RemoveJetPack					( DWORD pUserData );
		static bool                 SetFightingStyle				( DWORD pUserData, unsigned char ucStyle );
		static bool                 SetMoveAnim						( DWORD pUserData, unsigned int iMoveAnim );
		static bool                 SetGravity						( DWORD pUserData, float fGravity );
		static bool                 SetChoking						( DWORD pUserData, bool bChoking );
		static bool                 SetWeaponSlot					( DWORD pUserData, unsigned char ucWeaponSlot );
		static bool                 WarpIntoVehicle					( DWORD pUserData, DWORD pVehicle, unsigned int uiSeat );
		static bool                 RemoveFromVehicle				( DWORD pUserData );
		static bool                 SetDoingGangDriveby				( DWORD pUserData, bool bGangDriveby );
		static bool                 SetAnimation					( DWORD pUserData, MonoString* msBlockName, MonoString* msAnimName, int iTime, bool bLoop, bool bUpdatePosition, bool bInterruptable, bool bFreezeLastFrame );
		static bool                 SetAnimationProgress			( DWORD pUserData, MonoString* msAnimName, float fProgress );
		static bool                 SetOnFire						( DWORD pUserData, bool bIsOnFire );
		static bool                 SetHeadless						( DWORD pUserData, bool bIsHeadless );
		static bool                 SetFrozen						( DWORD pUserData, bool bIsFrozen );
		static bool                 ReloadWeapon					( DWORD pUserData );
		static bool					SetWeaponProperty				( unsigned char ucWeaponID, MonoString *msWeaponSkill, MonoString* msProperty, short uData );

		// Ped body?
		static MonoString*			GetBodyPartName					( unsigned char ucID );
		static MonoArray*			GetClothesByTypeIndex			( unsigned char ucType, unsigned char ucIndex );
		static MonoArray*			GetTypeIndexFromClothes			( MonoString* msTexture, MonoString* msModel );
		static MonoString*			GetClothesTypeName				( unsigned char ucType );

		// Weapon give/take functions
		static bool					GiveWeapon						( DWORD pPed, unsigned char ucWeaponID, unsigned short usAmmo, bool bSetAsCurrent = false );
		static bool					TakeWeapon						( DWORD pPed, unsigned char ucWeaponID, unsigned short usAmmo = 9999 );
		static bool					TakeAllWeapons					( DWORD pPed );
		static bool					SetWeaponAmmo					( DWORD pPed, unsigned char ucWeaponID, unsigned short usAmmo, unsigned short usAmmoInClip );
	};

	class Vehicle
	{
	public:
		// Vehicle create/destroy functions
		static DWORD					Create	( int model, MonoObject* position, MonoObject* rotation, MonoString* numberplate, bool direction = false, int variant1 = 255, int variant2 = 255 );
		
		// Vehicle get functions
		static MonoString*				GetType							( DWORD pUserData );
		static MonoArray*				GetVariant						( DWORD pUserData );
		static MonoObject*				GetColor						( DWORD pUserData );
		static unsigned short			GetModelFromName				( MonoString* msName );
		static bool						GetLandingGearDown				( DWORD pUserData );
		static unsigned char			GetMaxPassengers				( DWORD pUserData );
		static MonoString*				GetName							( DWORD pUserData );
		static MonoString*				GetNameFromModel				( unsigned short usModel );
		static DWORD					GetOccupant						( DWORD pUserData, unsigned int uiSeat );
		static MonoArray*				GetOccupants					( DWORD pUserData );
		static DWORD					GetController					( DWORD pUserData );
		static bool						GetSirensOn						( DWORD pUserData );
		static MonoObject*				GetTurnVelocity					( DWORD pUserData );
		static MonoObject*				GetTurretPosition				( DWORD pUserData );
		static bool						IsLocked						( DWORD pUserData );
		static MonoArray*				GetOfType						( unsigned int uiModel );       
		static unsigned short			GetUpgradeOnSlot				( DWORD pUserData, unsigned char ucSlot );
		static MonoArray*				GetUpgrades						( DWORD pUserData );
//		static MonoString*				GetUpgradeSlotName				( unsigned char ucSlot );
		static MonoString*				GetUpgradeSlotName				( unsigned short usUpgrade );
		static MonoArray*				GetCompatibleUpgrades			( DWORD pUserData );
		static unsigned char			GetDoorState					( DWORD pUserData, unsigned char ucDoor );
		static MonoObject*				GetWheelStates					( DWORD pUserData );
		static unsigned char			GetLightState					( DWORD pUserData, unsigned char ucLight );
		static unsigned char			GetPanelState					( DWORD pUserData, unsigned char ucPanel );
		static unsigned char			GetOverrideLights				( DWORD pUserData );
		static DWORD					GetTowedByVehicle				( DWORD pUserData );
		static DWORD					GetTowingVehicle				( DWORD pUserData );
		static unsigned char			GetPaintjob						( DWORD pUserData );
		static MonoString*				GetPlateText					( DWORD pUserData );
		static bool						IsDamageProof					( DWORD pUserData );
		static bool						IsFuelTankExplodable			( DWORD pUserData );
		static bool						IsFrozen						( DWORD pUserData );
		static bool						IsOnGround						( DWORD pUserData );
		static bool						GetEngineState					( DWORD pUserData );
		static bool						IsTrainDerailed                 ( DWORD pUserData );
		static bool						IsTrainDerailable               ( DWORD pUserData );
		static bool						GetTrainDirection               ( DWORD pUserData );
		static float					GetTrainSpeed                   ( DWORD pUserData );
		static bool						IsBlown							( DWORD pUserData );
		static MonoObject*				GetHeadLightColor				( DWORD pUserData );
		static float					GetDoorOpenRatio				( DWORD pUserData, unsigned char ucDoor );
		static bool						IsTaxiLightOn					( DWORD pUserData );

		// Vehicle set functions
		static bool						Fix								( DWORD pUserData );
		static bool						Blow							( DWORD pUserData, bool bExplode );
		static bool						SetTurnVelocity					( DWORD pUserData, MonoObject* pVelocity );
		static bool						SetColor						( DWORD pUserData, MonoObject* pColor1, MonoObject* pColor2, MonoObject* pColor3, MonoObject* pColor4 );
		static bool						SetLandingGearDown				( DWORD pUserData, bool bLandingGearDown );
		static bool						SetLocked						( DWORD pUserData, bool bLocked );
		static bool						SetDoorsUndamageable			( DWORD pUserData, bool bDoorsUndamageable );
		static bool						SetSirensOn						( DWORD pUserData, bool bSirensOn );
		static bool						SetTaxiLightOn					( DWORD pUserData, bool bTaxiLightState );
		static bool						AddUpgrade						( DWORD pUserData, unsigned short usUpgrade );
		static bool						RemoveUpgrade					( DWORD pUserData, unsigned short usUpgrade );
		static bool						SetDoorState					( DWORD pUserData, unsigned char ucDoor, unsigned char ucState );
		static bool						SetWheelStates					( DWORD pUserData, int iFrontLeft, int iRearLeft, int iFrontRight, int iRearRight );
		static bool						SetLightState					( DWORD pUserData, unsigned char ucLight, unsigned char ucState );
		static bool						SetPanelState					( DWORD pUserData, unsigned char ucPanel, unsigned char ucState );
		static bool						SetIdleRespawnDelay				( DWORD pUserData, unsigned long ulTime );
		static bool						SetRespawnDelay					( DWORD pUserData, unsigned long ulTime );
		static bool						SetRespawnPosition				( DWORD pUserData, MonoObject* pPosition, MonoObject* pRotation );
		static bool						ToggleRespawn					( DWORD pUserData, bool bRespawn );
		static bool						ResetExplosionTime				( DWORD pUserData );
		static bool						ResetIdleTime					( DWORD pUserData );
		static bool						Spawn							( DWORD pUserData, MonoObject* pPosition, MonoObject* pRotation );
		static bool						Respawn							( DWORD pUserData );
		static bool						SetOverrideLights				( DWORD pUserData, unsigned char ucLights );
		static bool						AttachTrailer					( DWORD pUserData, DWORD pTrailer );
		static bool						DetachTrailer					( DWORD pUserData, DWORD pTrailer );
		static bool						SetEngineState					( DWORD pUserData, bool bState );
		static bool						SetDirtLevel					( DWORD pUserData, float fDirtLevel );
		static bool						SetDamageProof					( DWORD pUserData, bool bDamageProof );
		static bool						SetPaintjob						( DWORD pUserData, unsigned char ucPaintjob );
		static bool						SetFuelTankExplodable			( DWORD pUserData, bool bExplodable );
		static bool						SetTrainDerailed                ( DWORD pUserData, bool bDerailed );
		static bool						SetTrainDerailable              ( DWORD pUserData, bool bDerailable );
		static bool						SetTrainDirection               ( DWORD pUserData, bool bDireciton );
		static bool						SetTrainSpeed                   ( DWORD pUserData, float fSpeed );
		static bool						SetHeadLightColor				( DWORD pUserData, MonoObject* pColor );
		static bool						SetTurretPosition				( DWORD pUserData, MonoObject* pPosition );
		static bool						SetDoorOpenRatio				( DWORD pUserData, unsigned char ucDoor, float fRatio, unsigned long ulTime );
		static bool						SetVariant						( DWORD pUserData, unsigned char ucVariant, unsigned char ucVariant2 );
		static bool						GiveSirens						( DWORD pUserData, unsigned char ucSirenType, unsigned char ucSirenCount, bool bFlag360 = false, bool bCheckLosFlag = true, bool bUseRandomiserFlag = true, bool bSilentFlag = false );
		static bool						RemoveSirens					( DWORD pUserData );
		static bool						SetSirens						( DWORD pUserData, unsigned char ucSirenID, MonoObject* pPosition, MonoObject* pColor, float fMinAlpha );
		static MonoArray*				GetSirens						( DWORD pUserData );
		static MonoObject*				GetSirenParams					( DWORD pUserData );
		static bool						SetPlateText					( DWORD pUserData, MonoString* msName );
	};
	
	class Marker
	{
	public:
		// Marker create/destroy functions
		static DWORD					Create							( MonoObject* pPosition, MonoString* szType, float fSize, MonoObject* color, DWORD pVisibleTo );

		// Marker get functions
		static unsigned int				GetCount						();
		static MonoString*				GetType							( DWORD pUserData );
		static float					GetSize							( DWORD pUserData );
		static MonoObject*				GetColor						( DWORD pUserData );
		static MonoObject*				GetTarget						( DWORD pUserData );
		static MonoString*				GetIcon							( DWORD pUserData );

		// Marker set functions
		static bool						SetType							( DWORD pUserData, MonoString* szType );
		static bool						SetSize							( DWORD pUserData, float fSize );
		static bool						SetColor						( DWORD pUserData, MonoObject* color );
		static bool						SetTarget						( DWORD pUserData, MonoObject* pTarget );
		static bool						SetIcon							( DWORD pUserData, MonoString* szIcon );
	};

	class Blip
	{
	public:
		// Blip create/destroy functions
		static DWORD					Create							( MonoObject* vecPosition, unsigned char ucIcon, unsigned char ucSize, MonoObject* color, short sOrdering, unsigned short usVisibleDistance, DWORD pVisibleTo );
		static DWORD					CreateAttachedTo				( DWORD pTarget, unsigned char ucIcon, unsigned char ucSize, MonoObject* color, short sOrdering, unsigned short usVisibleDistance, DWORD pVisibleTo );
		
		// Blip get functions
		static unsigned char			GetIcon							( DWORD pUserData );
		static unsigned char			GetSize							( DWORD pUserData );
		static MonoObject*				GetColor						( DWORD pUserData );
		static short					GetOrdering						( DWORD pUserData );
		static unsigned short			GetVisibleDistance				( DWORD pUserData );

		// Blip set functions
		static bool						SetIcon							( DWORD pUserData, unsigned char ucIcon );
		static bool						SetSize							( DWORD pUserData, unsigned char ucSize );
		static bool						SetColor						( DWORD pUserData, MonoObject* color );
		static bool						SetOrdering						( DWORD pUserData, short sOrdering );
		static bool						SetVisibleDistance				( DWORD pUserData, unsigned short usVisibleDistance );
	};

	class Object
	{
	public:
		// Object create/destroy functions
		static DWORD					Create							( unsigned short usModelID, MonoObject* pPosition, MonoObject* pRotation, bool bIsLowLod );

		// Object get functions
		static MonoObject*				GetScale						( DWORD pUserData );

		// Object set functions
		static bool						SetScale						( DWORD pUserData, MonoObject* pScale );
		static bool						Move							( DWORD pUserData, unsigned long ulTime, MonoObject* pPosition, MonoObject* pRotation, MonoString* msEasingType, float fEasingPeriod, float fEasingAmplitude, float fEasingOvershoot );
		static bool						Stop							( DWORD pUserData );
	};

	class RadarArea
	{
	public:
		// Radar area create/destroy funcs
		static DWORD					Create							( MonoObject* pPosition, MonoObject* pSize, MonoObject* pColor, DWORD pVisibleTo );

		// Radar area get funcs
		static MonoObject*				GetSize							( DWORD pUserData );
		static MonoObject*				GetColor						( DWORD pUserData );
		static bool						IsFlashing						( DWORD pUserData );
		static bool						IsInside						( DWORD pUserData, MonoObject* pPosition );

		// Radar area set funcs
		static bool						SetSize							( DWORD pUserData, MonoObject* pSize );
		static bool						SetColor						( DWORD pUserData, MonoObject* pColor );
		static bool						SetFlashing						( DWORD pUserData, bool bFlashing );
	};

	class Pickup
	{
	public:
		// Pickup create/destroy funcs
		static DWORD					Create							( MonoObject* pPosition, unsigned char ucType, double dFive, unsigned long ulRespawnInterval, double dSix );

		// Pickup get funcs
		static unsigned char			GetType							( DWORD pUserData );
		static unsigned char			GetWeapon						( DWORD pUserData );
		static float					GetAmount						( DWORD pUserData );
		static unsigned short			GetAmmo							( DWORD pUserData );
		static unsigned long			GetRespawnInterval				( DWORD pUserData );
		static bool						IsSpawned						( DWORD pUserData );

		// Pickup set funcs
		static bool						SetType							( DWORD pUserData, unsigned char ucType, double dThree, double dFour );
		static bool						SetRespawnInterval				( DWORD pUserData, unsigned long ulInterval );
		static bool						Use								( DWORD pUserData, DWORD pPlayer );
	};

	class Shape
	{
	public:
		// Shape create funcs
		static DWORD					CreateCircle					( MonoObject* pPosition, float fRadius );
		static DWORD					CreateCuboid					( MonoObject* pPosition, MonoObject* vecSize );
		static DWORD					CreateSphere					( MonoObject* pPosition, float fRadius );
		static DWORD					CreateRectangle					( MonoObject* pPosition, MonoObject* vecSize );
		static DWORD					CreatePolygon					( MonoArray* vecPointList );
		static DWORD					CreateTube						( MonoObject* pPosition, float fRadius, float fHeight );
	};

	class Explosion
	{
	public:
		// Explosion funcs
		static bool						Create							( MonoObject* pPosition, unsigned char ucType, DWORD pCreator );
	};

	class Audio
	{
	public:
		// Audio funcs
		static bool						PlayFrontEnd					( DWORD pUserData, unsigned char ucSound );
		static bool						PlayMission						( DWORD pUserData, MonoObject* vecPosition, unsigned short usSlot );
	};

	class Team
	{
	public:
		// Team get funcs
		static DWORD					Create							( MonoString* msTeamName, MonoObject* pColor );
		static DWORD					GetFromName						( MonoString* msTeamName );
		static MonoString*				GetName							( DWORD pUserData );
		static MonoObject*				GetColor						( DWORD pUserData );
		static unsigned int				CountPlayers					( DWORD pUserData );
		static bool						GetFriendlyFire					( DWORD pUserData );

		// Team set funcs
		static bool						SetName							( DWORD pUserData, MonoString* msTeamName );
		static bool						SetColor						( DWORD pUserData, MonoObject* pColor );
		static bool						SetFriendlyFire					( DWORD pUserData, bool bFriendlyFire );
	};

	class Water
	{
	public:
		// Water funcs
		static DWORD					Create							( MonoObject* pV1, MonoObject* pV2, MonoObject* pV3, MonoObject* pV4, bool bShallow );
		static bool						SetLevel						( DWORD pUserData, float fLevel );
		static bool						SetLevelAll						( float fLevel );
		static bool						SetLevelWorld					( float fLevel, bool bIncludeWorldNonSeaLevel );
		static bool						ResetLevelWorld					( void );
		static MonoObject*				GetVertexPosition				( DWORD pUserData, int iVertexIndex );
		static bool						SetVertexPosition				( DWORD pUserData, int iVertexIndex, MonoObject* vecPosition );
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
		static DWORD					Get								( MonoString* msName, MonoString* msPassword );
		static MonoArray*				GetAll							( void );
		static DWORD					GetPlayer						( DWORD pAccount );
		static bool						IsGuest							( DWORD pAccount );
	//	static CLuaArgument*			GetData							( DWORD pAccount, MonoString* szKey );
	//	static MonoArray*				GetAllData						( DWORD pAccount );
		static MonoString*				GetSerial						( DWORD pAccount );
	//	static MonoArray*				GetBySerial						( MonoString* msSerial );

		// Account set funcs
		static DWORD					Add								( MonoString* msName, MonoString* msPassword );
		static bool						Remove							( DWORD pAccount );
		static bool						SetPassword						( DWORD pAccount, MonoString* msPassword );
	//	static bool						SetData							( DWORD pAccount, MonoString* msKey, CLuaArgument* pArgument );
		static bool						CopyData						( DWORD pAccount, DWORD pFromAccount );
	};

	class Ban
	{
	public:
		static DWORD					Add								( MonoString* msIP, MonoString* msUsername, MonoString* msSerial, DWORD pResponsible, MonoString* msResponsible, MonoString* msReason, int iUnban );
		static bool						Remove							( DWORD pBan, DWORD pResponsible );

	//	static MonoArray*				GetBans							( void );
		static bool						Reload							( void );

		static MonoString*				GetIP							( DWORD pBan );
		static MonoString*				GetSerial						( DWORD pBan );
		static MonoString*				GetUsername						( DWORD pBan );
		static MonoString*				GetNick							( DWORD pBan );
		static MonoString*				GetReason						( DWORD pBan );
		static MonoString*				GetAdmin						( DWORD pBan );

		static int						GetBanTime						( DWORD pBan );
		static int						GetUnbanTime					( DWORD pBan );

		static bool						SetUnbanTime					( DWORD pBan, int time );
		static bool						SetReason						( DWORD pBan, MonoString* msReason );
		static bool						SetAdmin						( DWORD pBan, MonoString* msAdminName );
	};

	class Resource
	{
	public:
		// Resource funcs
		static DWORD					Create					( MonoString* msResourceName, MonoString* msOrganizationalDir );
		static DWORD					Copy					( DWORD pResource, MonoString* msNewResourceName, MonoString* msOrganizationalDir );
		static DWORD					GetRootElement			( DWORD pResource = NULL );
		static DWORD					GetMapRootElement		( MonoString* msMap );
		static DWORD					GetDynamicElementRoot	( DWORD pResource );
	//	static CXMLNode*				AddMap					( MonoString* msFilePath, MonoString* msMapName, int iDimension );
	//	static CXMLNode*				AddConfig				( MonoString* msFilePath, MonoString* msConfigName, int iType );
		static bool						RemoveFile				( MonoString* msFilename );
	//	static CXMLNode					AddConfig				( MonoString* msFilePath, MonoString* msFileType );
	//	static CXMLNode					AddMap					( MonoString* msFilePath, unsigned int uiDimension = 0 );
	//	static CXMLNode					GetConfig				( MonoString* msFilePath );
	//	static CLuaArguments*			GetExportedFunctions	( DWORD pResource );
		static DWORD					GetFromName				( MonoString* msResourceName );
		static MonoString*				GetInfo					( DWORD pResource, MonoString* msAttribute );
		static unsigned int				GetLastStartTime		( DWORD pResource );
		static MonoString*				GetLoadFailureReason	( DWORD pResource );
		static unsigned int				GetLoadTime				( DWORD pResource );
		static MonoString*				GetName					( DWORD pResource );
		static MonoArray*				GetResources			( void );
		static MonoString*				GetState				( DWORD pResource );
		static DWORD					GetCurrent				( void );
		static bool						Refresh					( bool refreshAll = false );
		static bool						RemoveDefaultSetting	( DWORD pResource, MonoString* msSettingName );
		static bool						Start					( DWORD pResource, bool persistent = false, bool startIncludedResources = true, bool loadServerConfigs = true, bool loadMaps = true, bool loadServerScripts = true, bool loadHTML = true, bool loadClientConfigs = true, bool loadClientScripts = true, bool loadFiles = true );
		static bool						Restart					( DWORD pResource );
		static bool						Stop					( DWORD pResource );
		static bool						SetDefaultSetting		( DWORD pResource, MonoString* msSettingName, MonoString* msSettingValue );
	//	static bool						SetDefaultSetting		( DWORD pResource, MonoString* msSettingName, int iSettingValue );
	//	static bool						SetDefaultSetting		( DWORD pResource, MonoString* msSettingName, float fSettingValue );
		static bool						SetInfo					( DWORD pResource, MonoString* msAttribute, MonoString* msValue );
		static bool						Rename					( MonoString* msResourceName, MonoString* msNewResourceName, MonoString* msOrganizationalPath );
		static bool						Delete					( MonoString* msResourceName );
	//	static CLuaArguments*			GetACLRequests			( DWORD pResource );
		static bool						UpdateACLRequest		( DWORD pResource, MonoString* msRightName, bool bAccess, MonoString* msByWho );
	};
};

#endif