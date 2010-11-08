#ifndef KEYMANLISTBOX_H
#define KEYMANLISTBOX_H

#include <AknSettingItemList.h>

// Language Info
#include <akninputlanguageinfo.h>
#include <apgcli.h>

// CAknWaitDialog
#include <aknwaitdialog.h>

class CKeyManAppUi;
class CKeyManView1;

class CAknEnumeratedLanguagePopupSettingItem : public CAknEnumeratedTextPopupSettingItem
{
	public:
		CAknEnumeratedLanguagePopupSettingItem(TInt aResourceId, TInt &aValue);
//		~CAknEnumeratedLanguagePopupSettingItem();
		void CompleteConstructionL();

	private:
		CArrayPtr< CAknEnumeratedText > * aEnumeratedTextArray; 
		CArrayPtr< HBufC > * aPoppedUpTextArray;
};

class CAknEnumeratedApplicationPopupSettingItem : public CAknEnumeratedTextPopupSettingItem
{
	public:
		CAknEnumeratedApplicationPopupSettingItem(TInt aResourceId, TInt &aValue);
		void CompleteConstructionL();

	private:
		CArrayPtr< CAknEnumeratedText > * aEnumeratedTextArray; 
		CArrayPtr< HBufC > * aPoppedUpTextArray;
};

class CKeyManListbox : public CAknSettingItemList
{
	public:
		CAknSettingItem* CreateSettingItemL( TInt identifier );

/*
	private:
		TInt CheckAppUID(TInt iUID) {
			RApaLsSession iApaLs;
			if(iApaLs.Connect()!=KErrNone)
				return 0;
			TApaAppInfo appInfo;
			if(iApaLs.GetAppInfo(appInfo,TUid::Uid(iUID)) == KErrNone) {
				iApaLs.Close();
				return iUID;
			}
			iApaLs.Close();
			return 0;
		}
*/		
	public:
		inline TBool GetAutoStart() { return iAutoStart; }
		inline void SetAutoStart( TBool aAutoStart ) { iAutoStart = aAutoStart; }

#ifdef SERIES_60_FP3
		inline TBool GetMMKey() { return iMMKey; }
		inline void SetMMKey( TBool aMMKey ) { iMMKey = aMMKey; }
#endif

		inline TBool GetFileManagers() { return iFileManagers; }
		inline void SetFileManagers( TBool aFileManagers ) { iFileManagers = aFileManagers; }

		inline TBool GetBookReaders() { return iBookReaders; }
		inline void SetBookReaders( TBool aBookReaders ) { iBookReaders = aBookReaders; }

		inline TBool GetCamera() { return iCamera; }
		inline void SetCamera( TBool aCamera ) { iCamera = aCamera; }

		inline TInt GetSwitchKeyToggle() { return iToggleKey; }
		inline void SetSwitchKeyToggle( TInt aToggleKey ) { iToggleKey = aToggleKey; }

		inline TInt GetSwitchKey() { return iSwitchKey; }
		inline void SetSwitchKey( TInt aSwitchKey ) { iSwitchKey = aSwitchKey; }

		inline TInt GetSwitchKeyFirst() { return iSwitchKeyFirst; }
		inline void SetSwitchKeyFirst( TInt aSwitchKeyFirst ) { iSwitchKeyFirst = aSwitchKeyFirst; }

		inline TInt GetLanguageFirst() { return iLanguageFirst; }
		inline void SetLanguageFirst( TInt aLanguageFirst ) { iLanguageFirst = aLanguageFirst; }

		inline TInt GetSwitchKeySecond() { return iSwitchKeySecond; }
		inline void SetSwitchKeySecond( TInt aSwitchKeySecond ) { iSwitchKeySecond = aSwitchKeySecond; }

		inline TInt GetLanguageSecond() { return iLanguageSecond; }
		inline void SetLanguageSecond( TInt aLanguageSecond ) { iLanguageSecond = aLanguageSecond; }

		inline TBool GetEnableThird() { return iEnableThird; }
		inline void SetEnableThird( TBool aEnableThird ) { iEnableThird = aEnableThird; }

		inline TInt GetSwitchKeyThird() { return iSwitchKeyThird; }
		inline void SetSwitchKeyThird( TInt aSwitchKeyThird ) { iSwitchKeyThird = aSwitchKeyThird; }

		inline TInt GetLanguageThird() { return iLanguageThird; }
		inline void SetLanguageThird( TInt aLanguageThird ) { iLanguageThird = aLanguageThird; }

		inline TInt GetSwitchKeyMemory() { return iSwitchKeyMemory; }
		inline void SetSwitchKeyMemory( TInt aSwitchKeyMemory ) { iSwitchKeyMemory = aSwitchKeyMemory; }

		inline TInt GetSwitchKeyRestart() { return iSwitchKeyRestart; }
		inline void SetSwitchKeyRestart( TInt aSwitchKeyRestart ) { iSwitchKeyRestart = aSwitchKeyRestart; }

		inline TInt GetSwitchKeyShutdown() { return iSwitchKeyShutdown; }
		inline void SetSwitchKeyShutdown( TInt aSwitchKeyShutdown ) { iSwitchKeyShutdown = aSwitchKeyShutdown; }

		inline TInt GetSwitchKeyBTState() { return iSwitchKeyBTState; }
		inline void SetSwitchKeyBTState( TInt aSwitchKeyBTState ) { iSwitchKeyBTState = aSwitchKeyBTState; }

		inline TInt GetSwitchKeyBTMode() { return iSwitchKeyBTMode; }
		inline void SetSwitchKeyBTMode( TInt aSwitchKeyBTMode ) { iSwitchKeyBTMode = aSwitchKeyBTMode; }

		inline TInt GetSwitchApplications() { return iSwitchKeySwitchApplications; }
		inline void SetSwitchApplications( TInt aSwitchKeySwitchApplications ) { iSwitchKeySwitchApplications = aSwitchKeySwitchApplications; }

		inline TBool GetLockNote() { return iLockNote; }
		inline void SetLockNote( TBool aLockNote ) { iLockNote = aLockNote; }

		inline TInt GetSwitchKeyKeyLock() { return iSwitchKeyKeyLock; }
		inline void SetSwitchKeyKeyLock( TInt aSwitchKeyKeyLock ) { iSwitchKeyKeyLock = aSwitchKeyKeyLock; }

		inline TInt GetSwitchKeyMinimize() { return iSwitchKeyMinimize; }
		inline void SetSwitchKeyMinimize( TInt aSwitchKeyMinimize ) { iSwitchKeyMinimize = aSwitchKeyMinimize; }

		inline TInt GetSwitchKeyClose() { return iSwitchKeyClose; }
		inline void SetSwitchKeyClose( TInt aSwitchKeyClose ) { iSwitchKeyClose = aSwitchKeyClose; }

		inline TInt GetSwitchKeyKill() { return iSwitchKeyKill; }
		inline void SetSwitchKeyKill( TInt aSwitchKeyKill ) { iSwitchKeyKill = aSwitchKeyKill; }

		inline TInt GetSwitchKeyApp0() { return iSwitchKeyApp0; }
		inline void SetSwitchKeyApp0( TInt aSwitchKeyApp0 ) { iSwitchKeyApp0 = aSwitchKeyApp0; }

		inline TInt GetSwitchKeyApp1() { return iSwitchKeyApp1; }
		inline void SetSwitchKeyApp1( TInt aSwitchKeyApp1 ) { iSwitchKeyApp1 = aSwitchKeyApp1; }

		inline TInt GetSwitchKeyApp2() { return iSwitchKeyApp2; }
		inline void SetSwitchKeyApp2( TInt aSwitchKeyApp2 ) { iSwitchKeyApp2 = aSwitchKeyApp2; }

		inline TInt GetSwitchKeyApp3() { return iSwitchKeyApp3; }
		inline void SetSwitchKeyApp3( TInt aSwitchKeyApp3 ) { iSwitchKeyApp3 = aSwitchKeyApp3; }

		inline TInt GetSwitchKeyApp4() { return iSwitchKeyApp4; }
		inline void SetSwitchKeyApp4( TInt aSwitchKeyApp4 ) { iSwitchKeyApp4 = aSwitchKeyApp4; }

		inline TInt GetSwitchKeyApp5() { return iSwitchKeyApp5; }
		inline void SetSwitchKeyApp5( TInt aSwitchKeyApp5 ) { iSwitchKeyApp5 = aSwitchKeyApp5; }

		inline TInt GetSwitchKeyApp6() { return iSwitchKeyApp6; }
		inline void SetSwitchKeyApp6( TInt aSwitchKeyApp6 ) { iSwitchKeyApp6 = aSwitchKeyApp6; }

		inline TInt GetSwitchKeyApp7() { return iSwitchKeyApp7; }
		inline void SetSwitchKeyApp7( TInt aSwitchKeyApp7 ) { iSwitchKeyApp7 = aSwitchKeyApp7; }

		inline TInt GetSwitchKeyApp8() { return iSwitchKeyApp8; }
		inline void SetSwitchKeyApp8( TInt aSwitchKeyApp8 ) { iSwitchKeyApp8 = aSwitchKeyApp8; }

		inline TInt GetSwitchKeyApp9() { return iSwitchKeyApp9; }
		inline void SetSwitchKeyApp9( TInt aSwitchKeyApp9 ) { iSwitchKeyApp9 = aSwitchKeyApp9; }

		inline TInt GetUIDApp0() { return /*CheckAppUID(*/iUIDApplication_0/*)*/; }
		inline void SetUIDApp0( TInt aUIDApplication_0 ) { iUIDApplication_0 = aUIDApplication_0;	}

		inline TInt GetUIDApp1() { return /*CheckAppUID(*/iUIDApplication_1/*)*/; }
		inline void SetUIDApp1( TInt aUIDApplication_1 ) { iUIDApplication_1 = aUIDApplication_1;	}

		inline TInt GetUIDApp2() { return /*CheckAppUID(*/iUIDApplication_2/*)*/; }
		inline void SetUIDApp2( TInt aUIDApplication_2 ) { iUIDApplication_2 = aUIDApplication_2; }

		inline TInt GetUIDApp3() { return /*CheckAppUID(*/iUIDApplication_3/*)*/; }
		inline void SetUIDApp3( TInt aUIDApplication_3 ) { iUIDApplication_3 = aUIDApplication_3; }

		inline TInt GetUIDApp4() { return /*CheckAppUID(*/iUIDApplication_4/*)*/; }
		inline void SetUIDApp4( TInt aUIDApplication_4 ) { iUIDApplication_4 = aUIDApplication_4; }

		inline TInt GetUIDApp5() { return /*CheckAppUID(*/iUIDApplication_5/*)*/; }
		inline void SetUIDApp5( TInt aUIDApplication_5 ) { iUIDApplication_5 = aUIDApplication_5; }

		inline TInt GetUIDApp6() { return /*CheckAppUID(*/iUIDApplication_6/*)*/; }
		inline void SetUIDApp6( TInt aUIDApplication_6 ) { iUIDApplication_6 = aUIDApplication_6; }

		inline TInt GetUIDApp7() { return /*CheckAppUID(*/iUIDApplication_7/*)*/; }
		inline void SetUIDApp7( TInt aUIDApplication_7 ) { iUIDApplication_7 = aUIDApplication_7; }

		inline TInt GetUIDApp8() { return /*CheckAppUID(*/iUIDApplication_8/*)*/; }
		inline void SetUIDApp8( TInt aUIDApplication_8 ) { iUIDApplication_8 = aUIDApplication_8; }

		inline TInt GetUIDApp9() { return /*CheckAppUID(*/iUIDApplication_9/*)*/; }
		inline void SetUIDApp9( TInt aUIDApplication_9 ) { iUIDApplication_9 = aUIDApplication_9; }

		inline TInt GetSwitchKeyTest() { return iSwitchKeyTest; }
		inline void SetSwitchKeyTest( TInt aSwitchKeyTest ) { iSwitchKeyTest = aSwitchKeyTest; }
		
		inline TBool GetLog() { return iLog; }
		inline void SetLog( TBool aLog ) { iLog = aLog; }

		inline TInt GetCapturePriority() { return iCapturePriority; }
		inline void SetCapturePriority( TInt aCapturePriority ) { iCapturePriority = aCapturePriority; }

		inline TInt GetNoteType() { return iNoteType; }
		inline void SetNoteType( TInt aNoteType ) { iNoteType = aNoteType; }

		inline TInt GetNoteTimeout() { return iNoteTimeout; }
		inline void SetNoteTimeout( TInt aNoteTimeout ) { iNoteTimeout = aNoteTimeout; }

#ifndef SERIES_60_FP1
		inline TBool GetVibration() { return iVibration; }
		inline void SetVibration( TBool aVibration ) { iVibration = aVibration; }

		inline TInt GetVibrationTimeout() { return iVibrationTimeout; }
		inline void SetVibrationTimeout( TInt aVibrationTimeout ) { iVibrationTimeout = aVibrationTimeout; }

		inline TInt GetVibrationPower() { return iVibrationPower; }
		inline void SetVibrationPower( TInt aVibrationPower ) { iVibrationPower = aVibrationPower; }
#endif

		virtual void HandleListBoxEventL( CEikListBox* aListBox, TListBoxEvent aEventType );
		virtual TKeyResponse OfferKeyEventL( const TKeyEvent & aKeyEvent, TEventCode aType );

	public:
		void SetView(CKeyManView1* aView);

	private:
		CKeyManView1* iView;
		
		TBool iAutoStart;

#ifdef SERIES_60_FP3
		TBool iMMKey;
#endif
		TBool iFileManagers;
		TBool iBookReaders;
		TBool iCamera;
		
		TInt iToggleKey;
		TInt iSwitchKey;
		TInt iLanguageFirst;
		TInt iSwitchKeyFirst;
		TInt iLanguageSecond;
		TInt iSwitchKeySecond;
		TBool iEnableThird;
		TInt iLanguageThird;
		TInt iSwitchKeyThird;
		TInt iSwitchKeyMemory;
		TInt iSwitchKeyRestart;
		TInt iSwitchKeyShutdown;
		TInt iSwitchKeyBTState;
		TInt iSwitchKeyBTMode;
		TInt iSwitchKeySwitchApplications;
		TBool iLockNote;
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
		
		TInt iSwitchKeyTest;
		TBool iLog;
		TInt iCapturePriority;
		
		TInt iNoteTimeout;
		TInt iNoteType;
#ifndef SERIES_60_FP1
		TBool iVibration;
		TInt iVibrationTimeout;
		TInt iVibrationPower;
#endif
	private:
		CAknWaitDialog* iWaitDialog;
};

#endif