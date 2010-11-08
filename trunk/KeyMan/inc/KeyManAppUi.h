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
// View UI
#include <aknviewappui.h>
// Resource Reader
#include <barsread.h>
// Vibra Control
#include <vibractrl.h>
// KeyLock
#include <aknkeylock.h>
// IMEI
#include <plpvariant.h>
// File Log
#include <flogger.h>
// Notify
#include <aknnotifystd.h>
// File System
#include <f32file.h>
// Language Info
#include <akninputlanguageinfo.h>
// SysUtil API
#include <sysutil.h>

// Shared data
#include "shared.h"
// System Utils
#include "system.h"
// Bluetooth Control
#include "bteng.h"

#include "KeyManView1.h"
#include "KeyManView2.h"
#include "KeyManListBox.h"

// Camera Key
#define EKeyApplicationPhoto    0xF883
#define EStdKeyApplicationPhoto 0xE3

#define EKeyAD41_Play           0xF854
#define EStdKeyAD41_Play        0xB6
#define EKeyAD41_Stop           0xF855
#define EStdKeyAD41_Stop        0xB7
#define EKeyAD41_FF             0xF856
#define EStdKeyAD41_FF          0xB8
#define EKeyAD41_Rev            0xF857
#define EStdKeyAD41_Rev         0xB9
#define EKeyAD41_VolDown        0xF807
#define EStdKeyAD41_VolDown     0xE
#define EKeyAD41_VolUp          0xF808
#define EStdKeyAD41_VolUp       0xF


// UID constants
const TUid KUidKeyMan        = { 0x20008D94 };

// Internal
const TUid KUidPhone         = { 0x100058B3 };
const TUid KUidMenu          = { 0x101F4CD2 };
const TUid KUidSettings      = { 0x100058EC };
const TUid KUidBTSettings    = { 0x10005952 };
const TUid KUidAnyKey        = { 0x1020E4F1 };
const TUid KUidCamera        = { 0x101FFA86 };
const TUid KUidQReader       = { 0x101FF382 };

// External
const TUid KUidHandyTaskMan  = { 0x20004EBB };

// File Managers
const TUid KUidXPlore        = { 0x20009591 };
const TUid KUidYBrowser      = { 0x101F7BBF };
const TUid KUidGriffon       = { 0x200044C5 };
const TUid KUidBestFileMan   = { 0x101F9D60 };

// Others
const TUid KUidKeyPress      = { 0x65F7BD8 };
const TUid KUidSysAp         = { 0x100058F3 };
const TUid KUidCamServerCore = { 0x101F851C };

//class CKeyManListbox;
class CWsClient;
class CKeyManWsClient;

class CKeyManAppUi : public CAknViewAppUi
{
	public:
		void ConstructL();
		~CKeyManAppUi();

	private:
		TUint keyCode(TInt key);
		TInt scanCode(TInt key);
		TUint mask(TInt key);
		bool repeat(TInt key);
		TInt event(TInt key);

	private:
		void HandleCommandL(TInt aCommand);
//		void HandleForegroundEventL(TBool aForeground);
		
		TBool CheckKey(TInt iKeyCode, const TKeyEvent & aKeyEvent, TEventCode aType);

		void SwitchTo(TInt language_id);
		void CompressMemory();
		void TerminateApplication();
		void KillApplication();
		void MinimizeApplication();
		void Toggle();
		void CycleTasks();
		void RestartPhone();
		void ShutdownPhone();
		void SwitchBTState();
		void SwitchBTMode();
		void KeyLock();
		void Test();
		
	public:
		void CaptureKey(void);
		void CancelCaptureKey(void);
		void ReloadSettings();
		
		TInt CheckAppUID(TInt iUID);
		
		void TerminateApplication(TUid KUidApplication);
		void LaunchApplication(TUid KUidApplication);

/*
	private:
		void GetIMEI(TDes &aImei);
		inline TBool ValidateRegCode();
*/

	private:
		void CaptureKey(TInt iPriority, TInt iKey, TInt iCaptureKey, TInt iCaptureKeyUpAndDowns, TInt iCaptureLongKey);
		void CancelCaptureKey(TInt iCaptureKey, TInt iCaptureKeyUpAndDowns, TInt iCaptureLongKey);

	public:
		virtual TKeyResponse HandleKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType);

	public:
		TInt iToggleKey;
		TInt iSwitchKey;
		TInt iSwitchKeyFirst;
		TInt iSwitchKeySecond;
		TInt iSwitchKeyThird;
		TInt iSwitchKeyMemory;
		TInt iSwitchKeyRestart;
		TInt iSwitchKeyShutdown;
		TInt iSwitchKeyBTState;
		TInt iSwitchKeyBTMode;
		TInt iSwitchKeySwitchApplications;
		TInt iSwitchKeyKeyLock;
		TInt iSwitchKeyMinimize;
		TInt iSwitchKeyClose;
		TInt iSwitchKeyKill;
		TInt iSwitchKeyApp0;
		TInt iSwitchKeyApp1;
		TInt iSwitchKeyApp2;
		TInt iSwitchKeyApp3;
		TInt iSwitchKeyApp4;
		TInt iSwitchKeyApp5;
		TInt iSwitchKeyApp6;
		TInt iSwitchKeyApp7;
		TInt iSwitchKeyApp8;
		TInt iSwitchKeyApp9;

		TInt iSwitchKeyTest;
		TBool iLog;
		TInt iCapturePriority;

		TBool iAutoStart;

#ifdef SERIES_60_FP3
		TBool iMMKey;
#endif

		TBool iFileManagers;
		TBool iBookReaders;
		TBool iCamera;

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

		TInt iUIDApplication_0;
		TInt iUIDApplication_1;
		TInt iUIDApplication_2;
		TInt iUIDApplication_3;
		TInt iUIDApplication_4;
		TInt iUIDApplication_5;
		TInt iUIDApplication_6;
		TInt iUIDApplication_7;
		TInt iUIDApplication_8;
		TInt iUIDApplication_9;

		TInt32 iCaptureKeyToggle, iCaptureKeyKeyUpAndDownsToggle, iCaptureKeyLongToggle;
		TInt32 iCaptureKey, iCaptureKeyKeyUpAndDowns, iCaptureKeyLong;
		TInt32 iCaptureKeyFirst, iCaptureKeyKeyUpAndDownsFirst, iCaptureKeyLongFirst;
		TInt32 iCaptureKeySecond, iCaptureKeyKeyUpAndDownsSecond, iCaptureKeyLongSecond;
		TInt32 iCaptureKeyThird, iCaptureKeyKeyUpAndDownsThird, iCaptureKeyLongThird;
		TInt32 iCaptureKeyMemory, iCaptureKeyKeyUpAndDownsMemory, iCaptureKeyLongMemory;
		TInt32 iCaptureKeyRestart, iCaptureKeyKeyUpAndDownsRestart, iCaptureKeyLongRestart;
		TInt32 iCaptureKeyShutdown, iCaptureKeyKeyUpAndDownsShutdown, iCaptureKeyLongShutdown;
		TInt32 iCaptureKeyBTState, iCaptureKeyKeyUpAndDownsBTState, iCaptureKeyLongBTState;
		TInt32 iCaptureKeyBTMode, iCaptureKeyKeyUpAndDownsBTMode, iCaptureKeyLongBTMode;
		TInt32 iCaptureKeySwitchApplications, iCaptureKeyKeyUpAndDownsSwitchApplications, iCaptureKeyLongSwitchApplications;
		TInt32 iCaptureKeyKeyLock, iCaptureKeyKeyUpAndDownsKeyLock, iCaptureKeyLongKeyLock;
		TInt32 iCaptureKeyMinimize, iCaptureKeyKeyUpAndDownsMinimize, iCaptureKeyLongMinimize;
		TInt32 iCaptureKeyClose, iCaptureKeyKeyUpAndDownsClose, iCaptureKeyLongClose;
		TInt32 iCaptureKeyKill, iCaptureKeyKeyUpAndDownsKill, iCaptureKeyLongKill;
		TInt32 iCaptureKeyApp0, iCaptureKeyKeyUpAndDownsApp0, iCaptureKeyLongApp0;
		TInt32 iCaptureKeyApp1, iCaptureKeyKeyUpAndDownsApp1, iCaptureKeyLongApp1;
		TInt32 iCaptureKeyApp2, iCaptureKeyKeyUpAndDownsApp2, iCaptureKeyLongApp2;
		TInt32 iCaptureKeyApp3, iCaptureKeyKeyUpAndDownsApp3, iCaptureKeyLongApp3;
		TInt32 iCaptureKeyApp4, iCaptureKeyKeyUpAndDownsApp4, iCaptureKeyLongApp4;
		TInt32 iCaptureKeyApp5, iCaptureKeyKeyUpAndDownsApp5, iCaptureKeyLongApp5;
		TInt32 iCaptureKeyApp6, iCaptureKeyKeyUpAndDownsApp6, iCaptureKeyLongApp6;
		TInt32 iCaptureKeyApp7, iCaptureKeyKeyUpAndDownsApp7, iCaptureKeyLongApp7;
		TInt32 iCaptureKeyApp8, iCaptureKeyKeyUpAndDownsApp8, iCaptureKeyLongApp8;
		TInt32 iCaptureKeyApp9, iCaptureKeyKeyUpAndDownsApp9, iCaptureKeyLongApp9;
		TInt32 iCaptureKeyTest, iCaptureKeyKeyUpAndDownsTest, iCaptureKeyLongTest;

	private:
		TInt iPermanentNoteId;
		
		TRequestStatus st;
		CPeriodic* iPermanentTimer;
		static TInt PermanentNoteTimeoutL( TAny* aThis );
		
		RAknKeyLock keyLock;
		RSharedDataClient sd;

#ifndef SERIES_60_FP1
		CVibraControl* vibration;
#endif

	public:
		RFileLogger log;

	public:
		virtual TBool ProcessCommandParametersL(TApaCommand aCommand,TFileName& aDocumentName,const TDesC8& aTail);
	protected:
		void HandleWsEventL(const TWsEvent& aEvent,CCoeControl* aDestination);
};

#endif