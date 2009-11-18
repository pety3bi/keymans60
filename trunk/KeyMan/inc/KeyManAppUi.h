#ifndef KEYMANAPPUI_H
#define KEYMANAPPUI_H

#include "KeyMan.hrh"

#include <eikapp.h>
#include <eikdoc.h>
#include <e32std.h>
#include <coeccntx.h>
#include <aknappui.h>
#include <aknglobalnote.h>
#include <apgwgnam.h>
#include <aknmessagequerydialog.h> 
#include <aknnotewrappers.h>
#include <settinginfo.h>
#include <apgtask.h>
#include <hal.h>
#include <apgcli.h>

#include <aknviewappui.h>
#include <akntabgrp.h>
#include <aknnavide.h>
#include <akntabobserver.h>

// Shared data API
#include "shared.h"
// System Utils API
#include "sysutil.h"
// Vibra Control API
#include <vibractrl.h>
// KeyLock API
#include <aknkeylock.h>
// Bluetooth Control API
#include "bteng.h"
// IMEI API
#include <plpvariant.h>
// File Log API
#include <flogger.h>
// Notify API
#include <aknnotifystd.h>
// File System API
#include <f32file.h>

#define SW_SCAN_PHOTO 227

const TUid KUidKeyMan        = { 0x20008D94 };
const TUid KUidSettings      = { 0x100058EC };
const TUid KUidPhone         = { 0x100058B3 };
const TUid KUidMenu          = { 0x101F4CD2 };
const TUid KUidAnyKey        = { 0x1020E4F1 };
const TUid KUidHandyTaskMan  = { 0x20004EBB };
const TUid KUidBTSettings    = { 0x10005952 };

class CKeyManListbox;
class CWsClient;
class CKeyManWsClient;

class CKeyManAppUi : public CAknAppUi
{
	public:
		void ConstructL();
		~CKeyManAppUi();

	private:
		CAknNavigationControlContainer* iNaviPane;
		CAknNavigationDecorator*        iDecoratedTabGroup;
		CAknTabGroup*                   iTabGroup;

	private:
		TUint keyCode(TInt key);
		TInt scanCode(TInt key);
		TUint mask(TInt key);
		TInt event(TInt key);

	private:
		CKeyManListbox* iListBox;

	private:
		void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane *aMenuPane);
		void DynInitMenuPaneAllL(TInt aResourceId,CEikMenuPane* aMenuPane);
		
		void HandleCommandL(TInt aCommand);

		void CaptureKey(void);
		void CancelCaptureKey(void);

		TBool CheckKey(TInt iKeyCode, const TKeyEvent & aKeyEvent, TEventCode aType);

		void SwitchTo(TInt language_id);
		void CompressMemory();
		void TerminateApplication(TUid KUidApplication);
		void TerminateApplication();
		void LaunchApplication(TUid KUidApplication);
		void MinimizeApplication();
		void Toggle();
		void CycleTasks();
		void RestartPhone();
		void SwitchBTState();
		void KeyLock();
		void SwitchBTMode();
		void Test();
		void GetIMEI(TDes &aImei);
		inline TBool ValidateRegCode();

	public:
		virtual TKeyResponse HandleKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);
		void UpdateSettings();  

	public:
		TInt iToggleKey;
		TInt iSwitchKey;
		TInt iSwitchKeyFirst;
		TInt iSwitchKeySecond;
		TInt iSwitchKeyThird;
		TInt iSwitchKeyMemory;
		TInt iSwitchKeyRestart;
		TInt iSwitchKeyBTState;
		TInt iSwitchKeySwitchApplications;
		TInt iSwitchKeyKeyLock;
		TInt iSwitchKeyMinimize;
		TInt iSwitchKeyClose;
		TInt iSwitchKeyApp1;
		TInt iSwitchKeyApp2;
		TInt iSwitchKeyBTMode;
		TInt iSwitchKeyTest;

	private:
		TBool iAutoStart;
#ifdef SERIES_60_FP3
		TBool iMMKey;
#endif
		TBool iEnableThird;
		TInt iLanguageFirst;
		TInt iLanguageSecond;
		TInt iLanguageThird;
		TBool iLockNote;
		TInt iNoteTimeout;
		TInt iNoteType;
#ifndef SERIES_60_FP1
		TBool iVibration;
		TInt iVibrationTimeout;
		TInt iVibrationPower;
#endif

		TInt iUIDApplication_1;
		TInt iUIDApplication_2;

		TInt32 iCaptureKeyToggle, iCaptureKeyKeyUpAndDownsToggle;
		TInt32 iCaptureKey, iCaptureKeyKeyUpAndDowns;
		TInt32 iCaptureKeyFirst, iCaptureKeyKeyUpAndDownsFirst;
		TInt32 iCaptureKeySecond, iCaptureKeyKeyUpAndDownsSecond;
		TInt32 iCaptureKeyThird, iCaptureKeyKeyUpAndDownsThird;
		TInt32 iCaptureKeyMemory, iCaptureKeyKeyUpAndDownsMemory;
		TInt32 iCaptureKeyRestart, iCaptureKeyKeyUpAndDownsRestart;
		TInt32 iCaptureKeyBTState, iCaptureKeyKeyUpAndDownsBTState;
		TInt32 iCaptureKeySwitchApplications, iCaptureKeyKeyUpAndDownsSwitchApplications;
		TInt32 iCaptureKeyKeyLock, iCaptureKeyKeyUpAndDownsKeyLock;
		TInt32 iCaptureKeyMinimize, iCaptureKeyKeyUpAndDownsMinimize;
		TInt32 iCaptureKeyClose, iCaptureKeyKeyUpAndDownsClose;
		TInt32 iCaptureKeyApp1, iCaptureKeyKeyUpAndDownsApp1;
		TInt32 iCaptureKeyApp2, iCaptureKeyKeyUpAndDownsApp2;
		TInt32 iCaptureKeyBTMode, iCaptureKeyKeyUpAndDownsBTMode;
		TInt32 iCaptureKeyTest, iCaptureKeyKeyUpAndDownsTest, iCaptureKeyLongTest;
		TInt iPermanentNoteId;
		
		TRequestStatus st;
		TRequestStatus timerStatus; 

		CPeriodic* iPermanentTimer;
//		CPeriodic* iCompressMemoryTimer;
		
		static TInt PermanentNoteTimeoutL( TAny* aThis );

		static TInt ResetInactivityTime( TAny* aThis );
		static TInt CompressMemory( TAny* aThis );

		RSharedDataClient sd;
		RAknKeyLock keyLock;
#ifndef SERIES_60_FP1
		CVibraControl* vibration;
#endif

	public:
		RFileLogger log;

	public: virtual TBool ProcessCommandParametersL(TApaCommand aCommand,TFileName& aDocumentName,const TDesC8& aTail);
	protected: void HandleWsEventL(const TWsEvent& aEvent,CCoeControl* aDestination);
};
#endif