#ifndef KEYMANLISTBOX_H
#define KEYMANLISTBOX_H

#include <AknSettingItemList.h>

class CKeyManAppUi;

class CKeyManListbox : public CAknSettingItemList
{
	public:
		CAknSettingItem* CreateSettingItemL( TInt identifier );

		inline TBool GetAutoStart() { return iAutoStart; }
		inline void SetAutoStart( TBool aAutoStart ) { iAutoStart = aAutoStart; }

#ifdef SERIES_60_FP3
		inline TBool GetMMKey() { return iMMKey; }
		inline void SetMMKey( TBool aMMKey ) { iMMKey = aMMKey; }
#endif

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

		inline TInt GetSwitchKeyBTState() { return iSwitchKeyBTState; }
		inline void SetSwitchKeyBTState( TInt aSwitchKeyBTState ) { iSwitchKeyBTState = aSwitchKeyBTState; }

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

		inline TInt GetSwitchKeyApp1() { return iSwitchKeyApp1; }
		inline void SetSwitchKeyApp1( TInt aSwitchKeyApp1 ) { iSwitchKeyApp1 = aSwitchKeyApp1; }

		inline TInt GetSwitchKeyApp2() { return iSwitchKeyApp2; }
		inline void SetSwitchKeyApp2( TInt aSwitchKeyApp2 ) { iSwitchKeyApp2 = aSwitchKeyApp2; }

		inline TInt GetSwitchKeyBTMode() { return iSwitchKeyBTMode; }
		inline void SetSwitchKeyBTMode( TInt aSwitchKeyBTMode ) { iSwitchKeyBTMode = aSwitchKeyBTMode; }

		inline TInt GetSwitchKeyTest() { return iSwitchKeyTest; }
		inline void SetSwitchKeyTest( TInt aSwitchKeyTest ) { iSwitchKeyTest = aSwitchKeyTest; }

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

		inline void SetUI( CKeyManAppUi *aui ) { ui = aui; }

		virtual void HandleListBoxEventL( CEikListBox* aListBox, TListBoxEvent aEventType );
		virtual TKeyResponse OfferKeyEventL( const TKeyEvent & aKeyEvent, TEventCode aType );

	private:
		CKeyManAppUi *ui;
		TBool iAutoStart;
#ifdef SERIES_60_FP3
		TBool iMMKey;
#endif
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
		TInt iSwitchKeyBTState;
		TInt iSwitchKeySwitchApplications;
		TBool iLockNote;
		TInt iSwitchKeyKeyLock;
		TInt iSwitchKeyMinimize;
		TInt iSwitchKeyClose;
		TInt iSwitchKeyApp1;
		TInt iSwitchKeyApp2;
		TInt iSwitchKeyBTMode;
		TInt iSwitchKeyTest;
		TInt iNoteTimeout;
		TInt iNoteType;
#ifndef SERIES_60_FP1
		TBool iVibration;
		TInt iVibrationTimeout;
		TInt iVibrationPower;
#endif
};

#endif