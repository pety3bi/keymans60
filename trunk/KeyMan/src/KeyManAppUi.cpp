#include <KeyMan.rsg>
#include "KeyManAppUi.h"
#include "KeyManListBox.h"
#include "KeyMan.hrh"
#include <avkon.hrh>

TUint CKeyManAppUi::keyCode( TInt key)
{
	switch( key )
	{
		case EKeyShiftCall:
		case EKeyCall: return EKeyYes;
		case EKeyShiftBreak:
		case EKeyBreak: return EKeyNo;
		case EKeyShift1: return '1';
		case EKeyShift2: return '2';
		case EKeyShift3: return '3';
		case EKeyShift4: return '4';
		case EKeyShift5: return '5';
		case EKeyShift6: return '6';
		case EKeyShift7: return '7';
		case EKeyShift8: return '8';
		case EKeyShift9: return '9';
		case EKeyShift0: return '0';
		case EKeyShiftHash: return '#';
		case EKeyShiftStar: return '*';
		case EKeyShiftPower:
		case EKeyPower: return EKeyDevice2;
		case EKeyShiftMenuKey:
		case EKeyMenuKey: return EKeyApplication0;
		case EKeyShiftC: return EKeyBackspace;
		case EKeyShift: return EKeyLeftShift;
		case EKeyShiftMM:
		case EKeyMM: return EKeyApplication6;
		case EKeyShiftPhoto:
		case EKeyPhoto: return SW_SCAN_PHOTO;
		case EKeyShiftPTT:
		case EKeyPTT: return EKeyDevice6;
		case EKeyShiftPTT2:
		case EKeyPTT2: return EKeyDevice8; // 3230 PTT
		case EKeyShiftSoftLeft: return EKeyDevice0;
		case EKeyShiftSoftRight: return EKeyDevice1;
		case EKeyShiftUp: return EKeyUpArrow;
		case EKeyShiftDown: return EKeyDownArrow;
		case EKeyShiftLeft: return EKeyLeftArrow;
		case EKeyShiftRight: return EKeyRightArrow;
		case EKeyShiftCenter: return EKeyDevice3;
	}
	return 0;
}

TInt CKeyManAppUi::scanCode(TInt key)
{
	switch( key )
	{
		case EKeyShiftCall:
		case EKeyCall: return EStdKeyYes;
		case EKeyShiftBreak:
		case EKeyBreak: return EStdKeyNo;
		case EKeyShift1: return '1';
		case EKeyShift2: return '2';
		case EKeyShift3: return '3';
		case EKeyShift4: return '4';
		case EKeyShift5: return '5';
		case EKeyShift6: return '6';
		case EKeyShift7: return '7';
		case EKeyShift8: return '8';
		case EKeyShift9: return '9';
		case EKeyShift0: return '0';
		case EKeyShiftHash: return EStdKeyHash;
		case EKeyShiftStar: return EStdKeyNkpAsterisk;
		case EKeyShiftPower:
		case EKeyPower: return EStdKeyDevice2;
		case EKeyShiftMenuKey:
		case EKeyMenuKey: return EStdKeyApplication0;
		case EKeyShiftC: return EStdKeyBackspace;
		case EKeyShift: return EStdKeyLeftShift;
		case EKeyShiftMM:
		case EKeyMM: return EStdKeyApplication6;
		case EKeyShiftPhoto:
		case EKeyPhoto: return SW_SCAN_PHOTO;
		case EKeyShiftPTT:
		case EKeyPTT: return EStdKeyDevice6;
		case EKeyShiftPTT2:
		case EKeyPTT2: return EStdKeyDevice8; // 3230 PTT
		case EKeyShiftSoftLeft: return EStdKeyDevice0;
		case EKeyShiftSoftRight: return EStdKeyDevice1;
		case EKeyShiftUp: return EStdKeyUpArrow;
		case EKeyShiftDown: return EStdKeyDownArrow;
		case EKeyShiftLeft: return EStdKeyLeftArrow;
		case EKeyShiftRight: return EStdKeyRightArrow;
		case EKeyShiftCenter: return EStdKeyDevice3;
	}
	return 0;
}

TUint CKeyManAppUi::mask(TInt key)
{
	switch( key )
	{
		case EKeyShiftCall:
			return EModifierShift;
		case EKeyShiftBreak:
			return EModifierShift;
		case EKeyShift1:
			return EModifierShift;
		case EKeyShift2:
			return EModifierShift;
		case EKeyShift3:
			return EModifierShift;
		case EKeyShift4:
			return EModifierShift;
		case EKeyShift5:
			return EModifierShift;
		case EKeyShift6:
			return EModifierShift;
		case EKeyShift7:
			return EModifierShift;
		case EKeyShift8:
			return EModifierShift;
		case EKeyShift9:
			return EModifierShift;
		case EKeyShift0:
			return EModifierShift;
		case EKeyShiftHash:
			return EModifierShift;
		case EKeyShiftStar:
			return EModifierShift;
		case EKeyShiftPower:
			return EModifierShift;
		case EKeyShiftMenuKey:
			return EModifierShift;
		case EKeyShiftC:
			return EModifierShift;
		case EKeyShiftMM:
			return EModifierShift;
		case EKeyShiftPhoto:
			return EModifierShift;
		case EKeyShiftPTT:
			return EModifierShift;
		case EKeyShiftPTT2:
			return EModifierShift;
		case EKeyShiftSoftLeft:
			return EModifierShift;
		case EKeyShiftSoftRight:
			return EModifierShift;
		case EKeyShiftUp:
			return EModifierShift;
		case EKeyShiftDown:
			return EModifierShift;
		case EKeyShiftLeft:
			return EModifierShift;
		case EKeyShiftRight:
			return EModifierShift;
		case EKeyShiftCenter:
			return EModifierShift;
	}
	return 0;
}

TInt CKeyManAppUi::event(TInt key) 
{
	switch( key ) 
	{
		case EKeyPhoto:
		case EKeyShiftPhoto:
			return EEventKeyDown;
//		case EKeyShiftStar:
//			return EEventKey;
//		case EKeyShift:
//			return EEventKeyDown;
		default:
//			return EEventKeyDown;
			return EEventKey;
	}
}

void CKeyManAppUi::ConstructL()
{
#ifdef SERIES_60_FP1
	BaseConstructL();
#else
	BaseConstructL( EAknEnableSkin );
#endif

	log.Connect();
	log.CreateLog(_L("keyman"),_L("keyman.log"),EFileLoggingModeOverwrite);

	log.Write(_L("start KeyMan"));

	if(log.LogValid())
	{
		CEikStatusPane* sp = StatusPane();
		iNaviPane = (CAknNavigationControlContainer*)sp->ControlL(TUid::Uid(EEikStatusPaneUidNavi));
		iDecoratedTabGroup = iNaviPane->ResourceDecorator();
		if (iDecoratedTabGroup)
			iTabGroup = (CAknTabGroup*) iDecoratedTabGroup->DecoratedControl();
	}

	iCaptureKeyToggle = iCaptureKeyKeyUpAndDownsToggle = 0;
	iCaptureKey = iCaptureKeyKeyUpAndDowns = 0;
	iCaptureKeyFirst = iCaptureKeyKeyUpAndDownsFirst = 0;
	iCaptureKeySecond = iCaptureKeyKeyUpAndDownsSecond = 0;
	iCaptureKeyThird = iCaptureKeyKeyUpAndDownsThird = 0;
	iCaptureKeyMemory = iCaptureKeyKeyUpAndDownsMemory = 0;
	iCaptureKeyRestart = iCaptureKeyKeyUpAndDownsRestart = 0;
	iCaptureKeyBTState = iCaptureKeyKeyUpAndDownsBTState = 0;
	iCaptureKeySwitchApplications = iCaptureKeyKeyUpAndDownsSwitchApplications = 0;
	iCaptureKeyKeyLock = iCaptureKeyKeyUpAndDownsKeyLock = 0;
	iCaptureKeyMinimize = iCaptureKeyKeyUpAndDownsMinimize = 0;
	iCaptureKeyClose = iCaptureKeyKeyUpAndDownsClose = 0;
	iCaptureKeyApp1 = iCaptureKeyKeyUpAndDownsApp1 = 0;
	iCaptureKeyApp2 = iCaptureKeyKeyUpAndDownsApp2 = 0;
	iCaptureKeyBTMode = iCaptureKeyKeyUpAndDownsBTMode = 0;

	iCaptureKeyTest = iCaptureKeyKeyUpAndDownsTest = iCaptureKeyLongTest = 0;

	iAutoStart = EFalse;
#ifdef SERIES_60_FP3
	iMMKey = EFalse;
#endif
	
	iToggleKey = EKeyNone;
	iSwitchKeyFirst = EKeyNone;
	iSwitchKeySecond = EKeyNone;
	iSwitchKeyThird = EKeyNone;
	iSwitchKeyMemory = EKeyNone;
	iSwitchKeyRestart = EKeyNone;
	iSwitchKeyBTState = EKeyNone;
	iSwitchKeySwitchApplications = EKeyNone;
	iSwitchKeyKeyLock = EKeyNone;
	iSwitchKeyMinimize = EKeyNone;
	iSwitchKeyClose = EKeyNone;
	iSwitchKeyApp1 = EKeyNone;
	iSwitchKeyApp2 = EKeyNone;
	iSwitchKeyTest = EKeyNone;
	iSwitchKeyBTMode = EKeyNone;

	iEnableThird = EFalse;

	iLanguageFirst = ELangEnglish;
	iLanguageSecond = ELangRussian;
	iLanguageThird = ELangUkrainian;

	iUIDApplication_1 = 270486738;
	iUIDApplication_2 = 536891067;

	iLockNote = EFalse;

	iNoteTimeout = 300;
	iNoteType = ENoteTimeout;

#ifndef SERIES_60_FP1
	iVibration = EFalse;
	iVibrationTimeout = 300;
	iVibrationPower = 50;
#endif

	iListBox = new (ELeave) CKeyManListbox;
	iPermanentTimer = CPeriodic::NewL(CActive::EPriorityStandard);

#ifndef SERIES_60_FP1
	vibration = VibraFactory::NewL();
#endif

	if(ValidateRegCode())
	{
		sd.Connect(0);
		sd.Assign( KUidKeyMan );
		sd.GetInt( _L("autostart"), iAutoStart );
#ifdef SERIES_60_FP3
		sd.GetInt( _L("mmkey"), iMMKey );
#endif
		sd.GetInt( _L("key_toggle"), iToggleKey );
		sd.GetInt( _L("key_language"), iSwitchKey );
		sd.GetInt( _L("key_language_1"), iSwitchKeyFirst );
		sd.GetInt( _L("id_language_1"), iLanguageFirst );
		sd.GetInt( _L("key_language_2"), iSwitchKeySecond );
		sd.GetInt( _L("id_language_2"), iLanguageSecond );
		sd.GetInt( _L("enable_language_3"), iEnableThird );
		sd.GetInt( _L("key_language_3"), iSwitchKeyThird );
		sd.GetInt( _L("id_language_3"), iLanguageThird );
		sd.GetInt( _L("key_memory"), iSwitchKeyMemory );
		sd.GetInt( _L("key_restart"), iSwitchKeyRestart );
		sd.GetInt( _L("key_bt_state"), iSwitchKeyBTState );
		sd.GetInt( _L("key_bt_mode"), iSwitchKeyBTMode );
		sd.GetInt( _L("key_switch"), iSwitchKeySwitchApplications );
		sd.GetInt( _L("lock_note"), iLockNote );
		sd.GetInt( _L("key_lock"), iSwitchKeyKeyLock );
		sd.GetInt( _L("key_minimize"), iSwitchKeyMinimize );
		sd.GetInt( _L("key_close"), iSwitchKeyClose );
		sd.GetInt( _L("key_app_1"), iSwitchKeyApp1 );
		sd.GetInt( _L("uid_app_1"), iUIDApplication_1 );
		sd.GetInt( _L("key_app_2"), iSwitchKeyApp2 );
		sd.GetInt( _L("uid_app_2"), iUIDApplication_2 );
		sd.GetInt( _L("key_test"), iSwitchKeyTest );
		sd.GetInt( _L("note_time"), iNoteTimeout );
		sd.GetInt( _L("note_type"), iNoteType );
#ifndef SERIES_60_FP1
		sd.GetInt( _L("vibration"), iVibration );
		sd.GetInt( _L("vibration_time"), iVibrationTimeout );
		sd.GetInt( _L("vibration_power"), iVibrationPower );
#endif
		sd.Close();
	}

	iListBox->SetAutoStart( iAutoStart );
#ifdef SERIES_60_FP3
	iListBox->SetMMKey( iMMKey );
#endif
	iListBox->SetSwitchKeyToggle( iToggleKey );
	iListBox->SetSwitchKey( iSwitchKey );
	iListBox->SetSwitchKeyFirst( iSwitchKeyFirst );
	iListBox->SetLanguageFirst( iLanguageFirst );
	iListBox->SetSwitchKeySecond( iSwitchKeySecond );
	iListBox->SetLanguageSecond( iLanguageSecond );
	iListBox->SetEnableThird( iEnableThird );
	iListBox->SetSwitchKeyThird( iSwitchKeyThird );
	iListBox->SetLanguageThird( iLanguageThird );
	iListBox->SetSwitchKeyMemory( iSwitchKeyMemory );
	iListBox->SetSwitchKeyRestart( iSwitchKeyRestart );
	iListBox->SetSwitchKeyBTState( iSwitchKeyBTState );
	iListBox->SetSwitchKeyBTMode( iSwitchKeyBTMode );
	iListBox->SetSwitchApplications( iSwitchKeySwitchApplications );	
	iListBox->SetLockNote( iLockNote );
	iListBox->SetSwitchKeyKeyLock( iSwitchKeyKeyLock );
	iListBox->SetSwitchKeyMinimize( iSwitchKeyMinimize );
	iListBox->SetSwitchKeyClose( iSwitchKeyClose );
	iListBox->SetSwitchKeyApp1( iSwitchKeyApp1 );
	iListBox->SetSwitchKeyApp2( iSwitchKeyApp2 );
	iListBox->SetSwitchKeyTest( iSwitchKeyTest );
	iListBox->SetNoteTimeout( iNoteTimeout );
	iListBox->SetNoteType( iNoteType );
#ifndef SERIES_60_FP1
	iListBox->SetVibration( iVibration );
	iListBox->SetVibrationTimeout( iVibrationTimeout );
	iListBox->SetVibrationPower( iVibrationPower );
#endif
	iListBox->SetUI( this );

	iListBox->ConstructFromResourceL( R_LSW_SETTING_LIST );
	AddToStackL( iListBox );
	iListBox->ActivateL();

#ifdef SERIES_60_FP3
	if(iMMKey)
		TerminateApplication(KUidAnyKey);
	else
		LaunchApplication(KUidAnyKey);
#endif

	CaptureKey();

	iEikonEnv->SetRespondsToShutdownEvent(ETrue);
}

CKeyManAppUi::~CKeyManAppUi()
{
	log.Write(_L("exit KeyMan"));
	log.CloseLog();
	log.Close();

	CancelCaptureKey();
	if(iListBox)
	{
		RemoveFromStack(iListBox);
		delete iListBox;
		iListBox = NULL;
	}

	delete iPermanentTimer;
	delete iDecoratedTabGroup;
#ifndef SERIES_60_FP1
	delete vibration;
#endif
}

void CKeyManAppUi::DynInitMenuPaneL(TInt aResourceId, CEikMenuPane *aMenuPane)
{
	if (aResourceId == R_LSW_MENU && ValidateRegCode())
	{
//		aMenuPane->SetItemDimmed(EKeyManCmdAppRegister, ETrue);
		aMenuPane->DeleteMenuItem(EKeyManCmdAppRegister);
	}
}

void CKeyManAppUi::DynInitMenuPaneAllL(TInt aResourceId, CEikMenuPane* aMenuPane)
{
	DynInitMenuPaneL(aResourceId,aMenuPane);
}

TKeyResponse CKeyManAppUi::HandleKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType)
{
/*
	if( aKeyEvent.iCode == EKeyLeftArrow || aKeyEvent.iCode == EKeyRightArrow )
	{
		if( iTabGroup == NULL )
		{
			return EKeyWasNotConsumed;
		}

//		log.WriteFormat(_L("TabGgoup Event: ActiveTabIndex %d"), iTabGroup->ActiveTabIndex());
		iTabGroup->OfferKeyEventL( aKeyEvent, aType );
		
//		if(iTabGroup->ActiveTabIndex() > 0)
//		{
//		}
		return EKeyWasConsumed;
	}
*/
	if(CheckKey(iToggleKey, aKeyEvent, aType))
	{
		Toggle();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKey, aKeyEvent, aType))
	{
		SwitchTo(0);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyFirst, aKeyEvent, aType))
	{
		SwitchTo(iLanguageFirst);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeySecond, aKeyEvent, aType))
	{
		SwitchTo(iLanguageSecond);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyThird, aKeyEvent, aType))
	{
		SwitchTo(iLanguageThird);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyMemory, aKeyEvent, aType))
	{
		CompressMemory();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyRestart, aKeyEvent, aType))
	{
		RestartPhone();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyBTState, aKeyEvent, aType))
	{
		SwitchBTState();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeySwitchApplications, aKeyEvent, aType))
	{
		CycleTasks();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyKeyLock, aKeyEvent, aType))
	{
		KeyLock();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyMinimize, aKeyEvent, aType))
	{
		MinimizeApplication();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyClose, aKeyEvent, aType))
	{
		TerminateApplication();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp1, aKeyEvent, aType))
	{
		LaunchApplication(TUid::Uid(iUIDApplication_1));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp2, aKeyEvent, aType))
	{
		LaunchApplication(TUid::Uid(iUIDApplication_2));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyBTMode, aKeyEvent, aType))
	{
		SwitchBTMode();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyTest, aKeyEvent, aType))
	{
		Test();
		return EKeyWasConsumed;
	}

	return EKeyWasNotConsumed;
}

TBool CKeyManAppUi::CheckKey(TInt iKeyCode, const TKeyEvent& aKeyEvent, TEventCode aType)
{
	if (iKeyCode>=0)
	{
		if(aKeyEvent.iCode == keyCode(iKeyCode) || aKeyEvent.iScanCode == scanCode(iKeyCode))
		{
			if(mask(iKeyCode) || aKeyEvent.iCode == EKeyLeftShift || aKeyEvent.iScanCode == EStdKeyLeftShift)
			{
				if(aKeyEvent.iModifiers == 1280 || aKeyEvent.iModifiers == 1281)
					if( aType == event(iKeyCode) )
						return ETrue;
			}
			else
			{
				if(aKeyEvent.iModifiers != 1280 && aKeyEvent.iModifiers != 1281)
					if( aType == event(iKeyCode) )
						return ETrue;
			}
		}
	}
	return EFalse;
}

void CKeyManAppUi::HandleCommandL( TInt aCommand )
{
	switch ( aCommand )
	{
		case EAknSoftkeyBack:
		{
			TApaTask task(iEikonEnv->WsSession());
			task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
			task.SendToBackground();
			break;
		}
		case EEikCmdExit:
		{
			LaunchApplication(KUidAnyKey);
			Exit();
			break;
		}
		case EKeyManCmdAppAbout:
		{
			HBufC*  string;
			string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_AUTHORS);
			CAknMessageQueryDialog* dlg = CAknMessageQueryDialog::NewL(*string);
			dlg->PrepareLC(R_LSW_ABOUT_DLG);
			dlg->RunLD();
			CleanupStack::PopAndDestroy(string);
			break;
		}
		case EKeyManCmdAppDevelopers:
		{
			HBufC*  string;
			string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_DEVELOPERS);
			CAknMessageQueryDialog* dlg = CAknMessageQueryDialog::NewL(*string);
			dlg->PrepareLC(R_LSW_DEVELOPERS_DLG);
			dlg->RunLD();
			CleanupStack::PopAndDestroy(string);
			break;
		}
		case EKeyManCmdAppRegister:
		{
			TBuf<128> strCode;
			CAknTextQueryDialog *dlgReg = CAknTextQueryDialog::NewL(strCode);
			if (dlgReg->ExecuteLD(R_KM_REGISTRATION))
			{
				sd.Connect(0);
				sd.Assign( KUidKeyMan );
				sd.SetString( _L("reg_code"), strCode );
				sd.Close();
			}
			break;
		}
		default:
			break;      
	}
}

void CKeyManAppUi::SwitchTo(TInt language_id) 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Switch Language
		if(iPermanentTimer->IsActive())
			PermanentNoteTimeoutL(this);

		_LIT( InputLangStr, "InputLang" );

		sd.Connect(0);
		sd.Assign( KUidSettings );

		if (!language_id)
		{
			sd.GetInt( InputLangStr, language_id );
			if(iEnableThird)
				language_id = (language_id == iLanguageFirst) ? iLanguageSecond : (language_id == iLanguageSecond ? iLanguageThird : iLanguageFirst);
			else
				language_id = (language_id == iLanguageFirst) ? iLanguageSecond : iLanguageFirst;
		}

		sd.SetInt( InputLangStr, language_id );
		sd.Close();

//		if (iNoteTimeout && iNoteType!=ENoteDont)
//		{
			HBufC*  string;
			switch (language_id)
			{
				case ELangEnglish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_01);
					break;
				case 	ELangFrench:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_02);
					break;
				case 	ELangGerman:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_03);
					break;
				case 	ELangSpanish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_04);
					break;
				case 	ELangItalian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_05);
					break;
				case 	ELangSwedish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_06);
					break;
				case 	ELangDanish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_07);
					break;
				case 	ELangNorwegian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_08);
					break;
				case 	ELangFinnish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_09);
					break;
				case 	ELangAmerican:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_10);
					break;
				case 	ELangSwissFrench:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_11);
					break;
				case 	ELangSwissGerman:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_12);
					break;
				case 	ELangPortuguese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_13);
					break;
				case 	ELangTurkish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_14);
					break;
				case 	ELangIcelandic:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_15);
					break;
				case 	ELangRussian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_16);
					break;
				case 	ELangHungarian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_17);
					break;
				case 	ELangDutch:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_18);
					break;
				case 	ELangBelgianFlemish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_19);
					break;
				case 	ELangAustralian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_20);
					break;
				case 	ELangBelgianFrench:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_21);
					break;
				case 	ELangAustrian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_22);
					break;
				case 	ELangNewZealand:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_23);
					break;
				case 	ELangInternationalFrench:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_24);
					break;
				case 	ELangCzech:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_25);
					break;
				case 	ELangSlovak:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_26);
					break;
				case 	ELangPolish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_27);
					break;
				case 	ELangSlovenian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_28);
					break;
				case 	ELangTaiwanChinese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_29);
					break;
				case 	ELangHongKongChinese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_30);
					break;
				case 	ELangPrcChinese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_31);
					break;
				case 	ELangJapanese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_32);
					break;
				case 	ELangThai:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_33);
					break;
				case 	ELangAfrikaans:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_34);
					break;
				case 	ELangAlbanian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_35);
					break;
				case 	ELangAmharic:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_36);
					break;
				case 	ELangArabic:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_37);
					break;
				case 	ELangArmenian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_38);
					break;
				case 	ELangTagalog:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_39);
					break;
				case 	ELangBelarussian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_40);
					break;
				case 	ELangBengali:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_41);
					break;
				case 	ELangBulgarian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_42);
					break;
				case 	ELangBurmese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_43);
					break;
				case 	ELangCatalan:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_44);
					break;
				case 	ELangCroatian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_45);
					break;
				case 	ELangCanadianEnglish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_46);
					break;
				case 	ELangInternationalEnglish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_47);
					break;
				case 	ELangSouthAfricanEnglish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_48);
					break;
				case 	ELangEstonian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_49);
					break;
				case 	ELangFarsi:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_50);
					break;
				case 	ELangCanadianFrench:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_51);
					break;
				case 	ELangScotsGaelic:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_52);
					break;
				case 	ELangGeorgian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_53);
					break;
				case 	ELangGreek:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_54);
					break;
				case 	ELangCyprusGreek:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_55);
					break;
				case 	ELangGujarati:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_56);
					break;
				case 	ELangHebrew:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_57);
					break;
				case 	ELangHindi:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_58);
					break;
				case 	ELangIndonesian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_59);
					break;
				case 	ELangIrish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_60);
					break;
				case 	ELangSwissItalian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_61);
					break;
				case 	ELangKannada:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_62);
					break;
				case 	ELangKazakh:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_63);
					break;
				case 	ELangKhmer:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_64);
					break;
				case 	ELangKorean:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_65);
					break;
				case 	ELangLao:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_66);
					break;
				case 	ELangLatvian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_67);
					break;
				case 	ELangLithuanian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_68);
					break;
				case 	ELangMacedonian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_69);
					break;
				case 	ELangMalay:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_70);
					break;
				case 	ELangMalayalam:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_71);
					break;
				case 	ELangMarathi:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_72);
					break;
				case 	ELangMoldavian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_73);
					break;
				case 	ELangMongolian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_74);
					break;
				case 	ELangNorwegianNynorsk:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_75);
					break;
				case 	ELangBrazilianPortuguese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_76);
					break;
				case 	ELangPunjabi:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_77);
					break;
				case 	ELangRomanian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_78);
					break;
				case 	ELangSerbian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_79);
					break;
				case 	ELangSinhalese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_80);
					break;
				case 	ELangSomali:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_81);
					break;
				case 	ELangInternationalSpanish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_82);
					break;
				case 	ELangLatinAmericanSpanish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_83);
					break;
				case 	ELangSwahili:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_84);
					break;
				case 	ELangFinlandSwedish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_85);
					break;
				case 	ELangReserved1:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_86);
					break;
				case 	ELangTamil:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_87);
					break;
				case 	ELangTelugu:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_88);
					break;
				case 	ELangTibetan:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_89);
					break;
				case 	ELangTigrinya:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_90);
					break;
				case 	ELangCyprusTurkish:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_91);
					break;
				case 	ELangTurkmen:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_92);
					break;
				case 	ELangUkrainian:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_93);
					break;
				case 	ELangUrdu:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_94);
					break;
				case 	ELangReserved2:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_95);
					break;
				case 	ELangVietnamese:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_96);
					break;
				case 	ELangWelsh:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_97);
					break;
				case 	ELangZulu:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_98);
					break;
				case 	ELangOther:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_99);
					break;
				default:
					string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_UNKNOWN);
					break;
			}

			HBufC* textFormat = iCoeEnv->AllocReadResourceLC(R_TEXT_LANGUAGE);
			HBufC* text = HBufC::NewLC(textFormat->Length() + string->Length());
			TPtr textPtr(text->Des());
			textPtr.Format(*textFormat, string);

			CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
			CleanupStack::PushL(globalNote);
			globalNote->SetTone(0);
			globalNote->SetPriority(CActive::EPriorityHigh);

			iPermanentNoteId = globalNote->ShowNoteL( EAknGlobalInformationNote, *text);
			CleanupStack::PopAndDestroy(text);
			CleanupStack::PopAndDestroy(string);
			CleanupStack::PopAndDestroy(textFormat);
			CleanupStack::PopAndDestroy();

/*
			CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
			CleanupStack::PushL(globalNote);
			globalNote->SetTone(0);
			globalNote->SetPriority(CActive::EPriorityHigh);
			
			iPermanentNoteId = globalNote->ShowNoteL( EAknGlobalInformationNote, *string);
			CleanupStack::PopAndDestroy(string);
*/

			TCallBack callback(PermanentNoteTimeoutL, this);
			iPermanentTimer->Cancel();
			iPermanentTimer->Start(
				(TTimeIntervalMicroSeconds32) (iNoteTimeout*1000),
				(TTimeIntervalMicroSeconds32) (100*1000), 
				callback);
//		}

#ifndef SERIES_60_FP1
		// Vibration
		if (iVibrationTimeout && iVibration)
			vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::CompressMemory() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Compress Memory
		if(iPermanentTimer->IsActive())
			PermanentNoteTimeoutL(this);

		TInt beforeFreeRAM = 0;
		HAL::Get(HAL::EMemoryRAMFree, beforeFreeRAM);
		User::CompressAllHeaps();
		TInt afterFreeRAM = 0;
		HAL::Get(HAL::EMemoryRAMFree, afterFreeRAM);

		if (iNoteTimeout && iNoteType!=ENoteDont)
		{
			HBufC* textFormat = iCoeEnv->AllocReadResourceLC(R_TEXT_COMPRESSED_MEMORY);
			HBufC* text = HBufC::NewLC(textFormat->Length() + sizeof (afterFreeRAM >> 10) + sizeof((afterFreeRAM - beforeFreeRAM) >> 10));
			TPtr textPtr(text->Des());
			textPtr.Format(*textFormat, (afterFreeRAM - beforeFreeRAM) >> 10, afterFreeRAM >> 10);

			CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
			CleanupStack::PushL(globalNote);
			globalNote->SetTone(0);
			globalNote->SetPriority(CActive::EPriorityHigh);

			iPermanentNoteId = globalNote->ShowNoteL( EAknGlobalInformationNote, *text);
			CleanupStack::PopAndDestroy(text);
			CleanupStack::PopAndDestroy(2, textFormat);

			TCallBack callback(PermanentNoteTimeoutL, this);
			iPermanentTimer->Cancel();
			iPermanentTimer->Start(
				(TTimeIntervalMicroSeconds32) (iNoteTimeout*1000),
				(TTimeIntervalMicroSeconds32) (100*1000), 
				callback);
//			CleanupStack::PopAndDestroy();
		}

#ifndef SERIES_60_FP1
		// Vibration
		if (iVibrationTimeout && iVibration)
			vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::RestartPhone()
{
	// Restart phone
	SysStartup::ShutdownAndRestart(KUidKeyMan, ESWNone);
}

void CKeyManAppUi::TerminateApplication(TUid KUidApplication) 
{
	// Terminate application
	TApaTaskList ApaTaskList(iCoeEnv->WsSession());
	TApaTask Task = ApaTaskList.FindApp( KUidApplication );
	if(Task.Exists())
		Task.EndTask();
}

void CKeyManAppUi::TerminateApplication() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Terminate application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindByPos(0);
		if (Task.WgId() != ApaTaskList.FindApp(KUidPhone).WgId())
			Task.EndTask();
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::LaunchApplication(TUid KUidApplication) 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// LaunchApplication
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindApp(KUidApplication);
		if (!Task.Exists())
		{
			RApaLsSession ses;
			if (ses.Connect()!=KErrNone)
				return;

			TApaAppInfo aInfo;
			if (ses.GetAppInfo(aInfo,KUidApplication)==KErrNone)
			{
				TInt len=aInfo.iFullName.Length();
				HBufC* name = HBufC::New(len); 
				name->Des().Copy(aInfo.iFullName);
				CApaCommandLine* cmdLine = CApaCommandLine::New(name);
				if (KUidApplication != KUidAnyKey)
					cmdLine->SetCommandL(EApaCommandRun);
				else
					cmdLine->SetCommandL(EApaCommandBackground);
				ses.StartApp(*cmdLine);
			}
			ses.Close();
		}
		else
		{
			if (Task.ThreadId() == ApaTaskList.FindByPos(0).ThreadId())
				Task.SendToBackground();
			else if (KUidApplication != KUidAnyKey)
				Task.BringToForeground();
		}
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::MinimizeApplication() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Minimize application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindApp(KUidPhone);
		if (Task.Exists())
		{
			Task.BringToForeground();
		}
/*
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindByPos(0);
//		TApaTask Task(iEikonEnv->WsSession());
//		Task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
//		if (Task.ThreadId() != ApaTaskList.FindApp(KUidPhone).ThreadId())
		if (Task.WgId() != ApaTaskList.FindApp(KUidPhone).WgId())
			Task.SendToBackground();
*/
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::Toggle() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Toggle application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindApp(KUidKeyMan);
			Task.BringToForeground();
			
//		Task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
//		log.WriteFormat(_L("Task0 = %d"), Task.ThreadId());
//		log.WriteFormat(_L("Task1 = %d"), ApaTaskList.FindApp(KUidPhone).ThreadId());
//		log.WriteFormat(_L("Task2 = %d"), ApaTaskList.FindByPos(0).ThreadId());

//		for ( TInt i = -20; i < 20; i++ )
//			log.WriteFormat(_L("Task %d = %d"), i, ApaTaskList.FindByPos(i).WgId());

//		if (Task.ThreadId() != ApaTaskList.FindByPos(0).ThreadId())

//		TApaTask Task2(iEikonEnv->WsSession());
//		Task2.SetWgId(CEikonEnv::Static()->RootWin().Identifier());

//		if (Task.WgId() != Task2.WgId())
//		{
//			Task.BringToForeground();
//		}
//		if(ApaTaskList.FindApp(KUidPhone).ThreadId() == ApaTaskList.FindByPos(0).ThreadId())
//		else
//		{
//			Task.SendToBackground();
//		}
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::CycleTasks() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Cycle Tasks
		TInt numOfTask = 0;
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		while ( numOfTask < 256 )
		{
			bool taskHidden = true;
			TInt taskWgId = ApaTaskList.FindByPos(numOfTask).WgId();
			
			if (taskWgId != 0)
			{
				CApaWindowGroupName *wGrName = CApaWindowGroupName::NewL(CEikonEnv::Static()->WsSession(), taskWgId );
				CleanupStack::PushL( wGrName );
				if (!wGrName->Hidden())
					taskHidden = false;
				CleanupStack::PopAndDestroy( wGrName );
			}
//			if(taskWgId == ApaTaskList.FindApp(KUidPhone).WgId())
//				taskHidden = true;
			if (taskHidden)
			{
				numOfTask--;
				break;
			}
	                numOfTask++;
		}

		TApaTask CurrAppTask = ApaTaskList.FindByPos(numOfTask);
		if (CurrAppTask.Exists())
			CurrAppTask.BringToForeground();
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::SwitchBTState() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Switch BlueTooth State
		CBTMCMSettings * BtSettings=CBTMCMSettings::NewLC(NULL);
		TBool power;
		BtSettings->GetPowerStateL(power);
		if (!power)
			BtSettings->SetPowerStateL(ETrue, EFalse);
		else
			BtSettings->SetPowerStateL(EFalse, EFalse);
	
		CleanupStack::PopAndDestroy();

#ifndef SERIES_60_FP1
		// Vibration
		if (iVibrationTimeout && iVibration)
			vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::SwitchBTMode() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Switch BlueTooth Mode
		if(iPermanentTimer->IsActive())
			PermanentNoteTimeoutL(this);
		
		_LIT( VisibilityStr, "Visibility" );

		sd.Connect(0);
		sd.Assign( KUidBTSettings );

		TInt visibility;
		HBufC* string;
		sd.GetInt( VisibilityStr, visibility );
		switch (visibility)
		{
			case 2:
				string = CCoeEnv::Static()->AllocReadResourceLC(R_TEXT_BT_MODE_1);
				sd.SetInt( VisibilityStr, 3 );
				break;
			case 	3:
				string = CCoeEnv::Static()->AllocReadResourceLC(R_TEXT_BT_MODE_2);
				sd.SetInt( VisibilityStr, 2 );
				break;
			default:
				string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_UNKNOWN);
				break;
		}
		sd.Close();

		HBufC* textFormat = iCoeEnv->AllocReadResourceLC(R_TEXT_BT_MODE);
		HBufC* text = HBufC::NewLC(textFormat->Length() + string->Length());
		TPtr textPtr(text->Des());
		textPtr.Format(*textFormat, string);

		CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
		CleanupStack::PushL(globalNote);
		globalNote->SetTone(0);
		globalNote->SetPriority(CActive::EPriorityHigh);

		iPermanentNoteId = globalNote->ShowNoteL( EAknGlobalInformationNote, *text);
		CleanupStack::PopAndDestroy(string);
		CleanupStack::PopAndDestroy(text);
		CleanupStack::PopAndDestroy(textFormat);
		CleanupStack::PopAndDestroy();
		
		TCallBack callback(PermanentNoteTimeoutL, this);
		iPermanentTimer->Cancel();
		iPermanentTimer->Start(
			(TTimeIntervalMicroSeconds32) (iNoteTimeout*1000),
			(TTimeIntervalMicroSeconds32) (100*1000), 
			callback);

#ifndef SERIES_60_FP1
		// Vibration
		if (iVibrationTimeout && iVibration)
			vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::KeyLock()
{
	// KeyLock
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(keyLock.IsKeyLockEnabled())
		if(iLockNote)
			keyLock.DisableKeyLock();
		else
		{
			keyLock.DisableWithoutNote();
//			keyLock.EnableSoftNotifications(ETrue);
		}
	else
		if(iLockNote)
			keyLock.EnableKeyLock();
		else
		{
			keyLock.EnableWithoutNote();
//			keyLock.EnableSoftNotifications(EFalse);
		}

#ifndef SERIES_60_FP1
	// Vibration
	if (iVibrationTimeout && iVibration)
		vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif

	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::UpdateSettings()
{
	CancelCaptureKey();

	iListBox->StoreSettingsL();

	iAutoStart = iListBox->GetAutoStart();
#ifdef SERIES_60_FP3
	iMMKey = iListBox->GetMMKey();
#endif
	iToggleKey = iListBox->GetSwitchKeyToggle();
	iSwitchKey = iListBox->GetSwitchKey();
	iSwitchKeyFirst = iListBox->GetSwitchKeyFirst();
	iLanguageFirst = iListBox->GetLanguageFirst();
	iSwitchKeySecond = iListBox->GetSwitchKeySecond();
	iLanguageSecond = iListBox->GetLanguageSecond();
	iEnableThird = iListBox->GetEnableThird();
	iSwitchKeyThird = iListBox->GetSwitchKeyThird();
	iLanguageThird = iListBox->GetLanguageThird();
	iSwitchKeyMemory = iListBox->GetSwitchKeyMemory();
	iSwitchKeyRestart = iListBox->GetSwitchKeyRestart();
	iSwitchKeyBTState = iListBox->GetSwitchKeyBTState();
	iSwitchKeyBTMode = iListBox->GetSwitchKeyBTMode();
	iSwitchKeySwitchApplications = iListBox->GetSwitchApplications();
	iLockNote = iListBox->GetLockNote();
	iSwitchKeyKeyLock = iListBox->GetSwitchKeyKeyLock();
	iSwitchKeyMinimize = iListBox->GetSwitchKeyMinimize();
	iSwitchKeyClose = iListBox->GetSwitchKeyClose();
	iSwitchKeyApp1 = iListBox->GetSwitchKeyApp1();
	iSwitchKeyApp2 = iListBox->GetSwitchKeyApp2();
	iSwitchKeyTest = iListBox->GetSwitchKeyTest();
	iNoteTimeout=iListBox->GetNoteTimeout();
	iNoteType=iListBox->GetNoteType();
#ifndef SERIES_60_FP1	
	iVibration=iListBox->GetVibration();
	iVibrationTimeout=iListBox->GetVibrationTimeout();
	iVibrationPower = iListBox->GetVibrationPower();
#endif
	if(ValidateRegCode())
	{
		sd.Connect(0);
		sd.Assign( KUidKeyMan );
		sd.SetInt( _L("autostart"), iAutoStart );
#ifdef SERIES_60_FP3
		sd.SetInt( _L("mmkey"), iMMKey );
#endif
		sd.SetInt( _L("key_toggle"), iToggleKey );
		sd.SetInt( _L("key_language"), iSwitchKey );
		sd.SetInt( _L("key_language_1"), iSwitchKeyFirst );
		sd.SetInt( _L("id_language_1"), iLanguageFirst );
		sd.SetInt( _L("key_language_2"), iSwitchKeySecond );
		sd.SetInt( _L("id_language_2"), iLanguageSecond );
		sd.SetInt( _L("enable_language_3"), iEnableThird );
		sd.SetInt( _L("key_language_3"), iSwitchKeyThird );
		sd.SetInt( _L("id_language_3"), iLanguageThird );
		sd.SetInt( _L("key_memory"), iSwitchKeyMemory );
		sd.SetInt( _L("key_restart"), iSwitchKeyRestart );
		sd.SetInt( _L("key_bt_state"), iSwitchKeyBTState );
		sd.SetInt( _L("key_bt_mode"), iSwitchKeyBTMode );
		sd.SetInt( _L("key_switch"), iSwitchKeySwitchApplications );
		sd.SetInt( _L("lock_note"), iLockNote );
		sd.SetInt( _L("key_lock"), iSwitchKeyKeyLock );
		sd.SetInt( _L("key_minimize"), iSwitchKeyMinimize );
		sd.SetInt( _L("key_close"), iSwitchKeyClose );
		sd.SetInt( _L("key_app_1"), iSwitchKeyApp1 );
		sd.SetInt( _L("uid_app_1"), iUIDApplication_1 );
		sd.SetInt( _L("key_app_2"), iSwitchKeyApp2 );
		sd.SetInt( _L("uid_app_2"), iUIDApplication_2 );
		sd.SetInt( _L("key_test"), iSwitchKeyTest );
		sd.SetInt( _L("note_time"), iNoteTimeout );
		sd.SetInt( _L("note_type"), iNoteType );
#ifndef SERIES_60_FP1
		sd.SetInt( _L("vibration"), iVibration );
		sd.SetInt( _L("vibration_time"), iVibrationTimeout );
		sd.SetInt( _L("vibration_power"), iVibrationPower );
#endif
		sd.Close();
	}

#ifdef SERIES_60_FP3
	if(iMMKey)
		TerminateApplication(KUidAnyKey);
	else
		LaunchApplication(KUidAnyKey);
#endif

	CaptureKey();
}

void CKeyManAppUi::CaptureKey()
{
	if (iToggleKey>=0)
	{
		iCaptureKeyToggle = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iToggleKey), mask(iToggleKey),mask(iToggleKey), 1000000);
		iCaptureKeyKeyUpAndDownsToggle = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iToggleKey), mask(iToggleKey),mask(iToggleKey), 1000000);
	}

	if (iSwitchKey>=0)
	{
		iCaptureKey = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKey), mask(iSwitchKey),mask(iSwitchKey), 1000000);
		iCaptureKeyKeyUpAndDowns = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKey), mask(iSwitchKey),mask(iSwitchKey), 1000000);
	}

	if (iSwitchKeyFirst>=0)
	{
		iCaptureKeyFirst = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyFirst), mask(iSwitchKeyFirst),mask(iSwitchKeyFirst), 1000000);
		iCaptureKeyKeyUpAndDownsFirst = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyFirst), mask(iSwitchKeyFirst),mask(iSwitchKeyFirst), 1000000);
	}

	if (iSwitchKeySecond>=0)
	{
		iCaptureKeySecond = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeySecond), mask(iSwitchKeySecond),mask(iSwitchKeySecond), 1000000);
		iCaptureKeyKeyUpAndDownsSecond = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeySecond), mask(iSwitchKeySecond),mask(iSwitchKeySecond), 1000000);
	}

	if (iSwitchKeyThird>=0)
	{
		iCaptureKeyThird = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyThird), mask(iSwitchKeyThird),mask(iSwitchKeyThird), 1000000);
		iCaptureKeyKeyUpAndDownsThird = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyThird), mask(iSwitchKeyThird),mask(iSwitchKeyThird), 1000000);
	}

	if (iSwitchKeyMemory>=0)
	{
		iCaptureKeyMemory = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyMemory), mask(iSwitchKeyMemory),mask(iSwitchKeyMemory), 1000000);
		iCaptureKeyKeyUpAndDownsMemory = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyMemory), mask(iSwitchKeyMemory),mask(iSwitchKeyMemory), 1000000);
	}

	if (iSwitchKeyRestart>=0)
	{
		iCaptureKeyRestart = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyRestart), mask(iSwitchKeyRestart),mask(iSwitchKeyRestart), 1000000);
		iCaptureKeyKeyUpAndDownsRestart = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyRestart), mask(iSwitchKeyRestart),mask(iSwitchKeyRestart), 1000000);
	}

	if (iSwitchKeyBTState>=0)
	{
		iCaptureKeyBTState = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyBTState), mask(iSwitchKeyBTState),mask(iSwitchKeyBTState), 1000000);
		iCaptureKeyKeyUpAndDownsBTState = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyBTState), mask(iSwitchKeyBTState),mask(iSwitchKeyBTState), 1000000);
	}

	if (iSwitchKeyBTMode>=0)
	{
		iCaptureKeyBTMode = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyBTMode), mask(iSwitchKeyBTMode),mask(iSwitchKeyBTMode), 1000000);
		iCaptureKeyKeyUpAndDownsBTMode = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyBTMode), mask(iSwitchKeyBTMode),mask(iSwitchKeyBTMode), 1000000);
	}

	if (iSwitchKeySwitchApplications>=0)
	{
		iCaptureKeySwitchApplications = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeySwitchApplications), mask(iSwitchKeySwitchApplications),mask(iSwitchKeySwitchApplications), 1000000);
		iCaptureKeyKeyUpAndDownsSwitchApplications = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeySwitchApplications), mask(iSwitchKeySwitchApplications),mask(iSwitchKeySwitchApplications), 1000000);
	}

	if (iSwitchKeyKeyLock>=0)
	{
		iCaptureKeyKeyLock = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyKeyLock), mask(iSwitchKeyKeyLock),mask(iSwitchKeyKeyLock), 1000000);
		iCaptureKeyKeyUpAndDownsKeyLock = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyKeyLock), mask(iSwitchKeyKeyLock),mask(iSwitchKeyKeyLock), 1000000);
	}

	if (iSwitchKeyMinimize>=0)
	{
		iCaptureKeyMinimize = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyMinimize), mask(iSwitchKeyMinimize),mask(iSwitchKeyMinimize), 1000000);
		iCaptureKeyKeyUpAndDownsMinimize = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyMinimize), mask(iSwitchKeyMinimize),mask(iSwitchKeyMinimize), 1000000);
	}
	
	if (iSwitchKeyClose>=0)
	{
		iCaptureKeyClose = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyClose), mask(iSwitchKeyClose),mask(iSwitchKeyClose), 1000000);
		iCaptureKeyKeyUpAndDownsClose = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyClose), mask(iSwitchKeyClose),mask(iSwitchKeyClose), 1000000);
	}
	
	if (iSwitchKeyApp1>=0)
	{
		iCaptureKeyApp1 = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyApp1), mask(iSwitchKeyApp1),mask(iSwitchKeyApp1), 1000000);
		iCaptureKeyKeyUpAndDownsApp1 = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyApp1), mask(iSwitchKeyApp1),mask(iSwitchKeyApp1), 1000000);
	}
	
	if (iSwitchKeyApp2>=0)
	{
		iCaptureKeyApp2 = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyApp2), mask(iSwitchKeyApp2),mask(iSwitchKeyApp2), 1000000);
		iCaptureKeyKeyUpAndDownsApp2 = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyApp2), mask(iSwitchKeyApp2),mask(iSwitchKeyApp2), 1000000);
	}

	if (iSwitchKeyTest>=0)
	{
		iCaptureKeyTest = CEikonEnv::Static()->RootWin().CaptureKey( keyCode(iSwitchKeyTest), mask(iSwitchKeyTest),mask(iSwitchKeyTest), 1000000);
		iCaptureKeyKeyUpAndDownsTest = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns( scanCode(iSwitchKeyTest), mask(iSwitchKeyTest),mask(iSwitchKeyTest), 1000000);
		iCaptureKeyLongTest = CEikonEnv::Static()->RootWin().CaptureLongKey( keyCode(iSwitchKeyTest), keyCode(iSwitchKeyTest), 0, 0, 1000000, ELongCaptureWaitShort);
	}
}

void CKeyManAppUi::CancelCaptureKey()
{
	if( iCaptureKeyToggle )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyToggle );
	if( iCaptureKeyKeyUpAndDownsToggle )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsToggle );
	iCaptureKeyToggle = iCaptureKeyKeyUpAndDownsToggle = 0;

	if( iCaptureKeyFirst )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyFirst );
	if( iCaptureKeyKeyUpAndDownsFirst )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsFirst );
	iCaptureKeyFirst = iCaptureKeyKeyUpAndDownsFirst = 0;

	if( iCaptureKeySecond )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeySecond );
	if( iCaptureKeyKeyUpAndDownsSecond )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsSecond );
	iCaptureKeySecond = iCaptureKeyKeyUpAndDownsSecond = 0;

	if( iCaptureKeyThird )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyThird );
	if( iCaptureKeyKeyUpAndDownsThird )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsThird );
	iCaptureKeyThird = iCaptureKeyKeyUpAndDownsThird = 0;

	if( iCaptureKeyMemory )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyMemory );
	if( iCaptureKeyKeyUpAndDownsMemory )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsMemory );
	iCaptureKeyMemory = iCaptureKeyKeyUpAndDownsMemory = 0;

	if( iCaptureKeyRestart )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyRestart );
	if( iCaptureKeyKeyUpAndDownsRestart )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsRestart );
	iCaptureKeyRestart = iCaptureKeyKeyUpAndDownsRestart = 0;

	if( iCaptureKeyBTState )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyBTState );
	if( iCaptureKeyKeyUpAndDownsBTState )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsBTState );
	iCaptureKeyBTState = iCaptureKeyKeyUpAndDownsBTState = 0;

	if( iCaptureKeyBTMode )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyBTMode );
	if( iCaptureKeyKeyUpAndDownsBTMode )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsBTMode );
	iCaptureKeyBTMode = iCaptureKeyKeyUpAndDownsBTMode = 0;

	if( iCaptureKeySwitchApplications )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeySwitchApplications );
	if( iCaptureKeyKeyUpAndDownsSwitchApplications )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsSwitchApplications );
	iCaptureKeySwitchApplications = iCaptureKeyKeyUpAndDownsSwitchApplications = 0;

	if( iCaptureKeyKeyLock )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyKeyLock );
	if( iCaptureKeyKeyUpAndDownsKeyLock )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsKeyLock );
	iCaptureKeyKeyLock = iCaptureKeyKeyUpAndDownsKeyLock = 0;

	if( iCaptureKeyMinimize )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyMinimize );
	if( iCaptureKeyKeyUpAndDownsMinimize )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsMinimize );
	iCaptureKeyMinimize = iCaptureKeyKeyUpAndDownsMinimize = 0;

	if( iCaptureKeyClose )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyClose );
	if( iCaptureKeyKeyUpAndDownsClose )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsClose );
	iCaptureKeyClose = iCaptureKeyKeyUpAndDownsClose = 0;

	if( iCaptureKeyApp1 )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyApp1 );
	if( iCaptureKeyKeyUpAndDownsApp1 )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsApp1 );
	iCaptureKeyApp1 = iCaptureKeyKeyUpAndDownsApp1 = 0;

	if( iCaptureKeyApp2 )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyApp2 );
	if( iCaptureKeyKeyUpAndDownsApp2 )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsApp2 );
	iCaptureKeyApp2 = iCaptureKeyKeyUpAndDownsApp2 = 0;

	if( iCaptureKeyTest )
		CEikonEnv::Static()->RootWin().CancelCaptureKey( iCaptureKeyTest );
	if( iCaptureKeyKeyUpAndDownsTest )
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns( iCaptureKeyKeyUpAndDownsTest );
	if( iCaptureKeyLongTest )
		CEikonEnv::Static()->RootWin().CancelCaptureLongKey( iCaptureKeyLongTest );
	iCaptureKeyTest = iCaptureKeyKeyUpAndDownsTest = iCaptureKeyLongTest = 0;
}

TBool CKeyManAppUi::ProcessCommandParametersL(TApaCommand, TFileName& /*aDocumentName*/, const TDesC8&)
{
	CEikonEnv::Static()->RootWin().EnableModifierChangedEvents(EModifierShift, EEventControlAlways);
	return false;
}

TInt CKeyManAppUi::PermanentNoteTimeoutL( TAny* aThis )
{
	CKeyManAppUi* container = STATIC_CAST(CKeyManAppUi*, aThis);

	CAknGlobalNote * note = CAknGlobalNote::NewL();
	CleanupStack::PushL(note);
	note->CancelNoteL(container->iPermanentNoteId);
	CleanupStack::PopAndDestroy();
	container->iPermanentTimer->Cancel();

	return 0;
}

void CKeyManAppUi::HandleWsEventL(const TWsEvent& aEvent, CCoeControl* aDestination)
{
	if (iNoteType == ENoteABC && aEvent.Type()==EEventModifiersChanged && iPermanentTimer->IsActive())
	{
		PermanentNoteTimeoutL(this);
	}
	CAknAppUi::HandleWsEventL(aEvent,aDestination);
}

void CKeyManAppUi::GetIMEI(TDes &aImei)
{
	#ifndef __WINS__
		// This only works on target machine
		TPlpVariantMachineId imei;
		PlpVariant::GetMachineIdL(imei);
		aImei.Copy(imei);
	#else
		_LIT(KEmulatorImei, "000000000000000");
		// Return a fake IMEI when working on emulator
		aImei.Copy(KEmulatorImei);
	#endif
}

TBool CKeyManAppUi::ValidateRegCode() 
{
	// Registration validation
	TBuf<15> iRegCode;
	sd.Connect(0);
	sd.Assign( KUidKeyMan );
	sd.GetString( _L("reg_code"), iRegCode );
	sd.Close();
	
	TBuf<15> aImei;
	GetIMEI(aImei);

	if(aImei[0] + 1 < 58)
		aImei[0] = aImei[0] + 1;
	else
		aImei[0] = aImei[0] - 1;
	if(aImei[1] + 2 < 58)
		aImei[1] = aImei[1] + 2;
	else
		aImei[1] = aImei[1] - 2;

	if(aImei[3] + aImei[7] < 58)
		aImei[3] = aImei[3] + aImei[7];
	else if(aImei[3] - aImei[7] > 48)
		aImei[3] = aImei[3] - aImei[7];
	else
		aImei[3] = aImei[7];
		
/*
	log.Write(aImei);
	log.WriteFormat(_L("aImei[0] = %d"),aImei[0]);
	log.WriteFormat(_L("aImei[1] = %d"),aImei[1]);
	log.WriteFormat(_L("aImei[2] = %d"),aImei[2]);
	log.WriteFormat(_L("aImei[3] = %d"),aImei[3]);
	log.WriteFormat(_L("aImei[4] = %d"),aImei[4]);
	log.WriteFormat(_L("aImei[5] = %d"),aImei[5]);
	log.WriteFormat(_L("aImei[6] = %d"),aImei[6]);
	log.WriteFormat(_L("aImei[7] = %d"),aImei[7]);
	log.WriteFormat(_L("aImei[8] = %d"),aImei[8]);
	log.WriteFormat(_L("aImei[9] = %d"),aImei[9]);
	log.WriteFormat(_L("aImei[10] = %d"),aImei[10]);
	log.WriteFormat(_L("aImei[11] = %d"),aImei[11]);
	log.WriteFormat(_L("aImei[12] = %d"),aImei[12]);
	log.WriteFormat(_L("aImei[13] = %d"),aImei[13]);
	log.WriteFormat(_L("aImei[14] = %d"),aImei[14]);
*/

	if(iRegCode.Compare(aImei))
		return EFalse;
	
	return ETrue;
}

TInt CKeyManAppUi::ResetInactivityTime(TAny* ) 
{ 
	User::ResetInactivityTime();

	RWsSession session;
	session.Connect();

	TRawEvent event;
	event.Set(TRawEvent::EActive);
	session.SimulateRawEvent(event);

	session.Flush();
	session.Close();

	return KErrNone;
}

TInt CKeyManAppUi::CompressMemory(TAny* ) 
{ 
	// Compress Memory
	User::CompressAllHeaps();

	CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
	CleanupStack::PushL(globalNote);
	globalNote->SetTone(0);
	globalNote->SetPriority(CActive::EPriorityHigh);

	globalNote->ShowNoteL( EAknGlobalInformationNote, _L("TEST"));
	CleanupStack::PopAndDestroy();
	
	return KErrNone;
}

void CKeyManAppUi::Test() 
{
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())
	{
		// Test only

#ifndef SERIES_60_FP1
		// Vibration
		if (iVibrationTimeout && iVibration)
			vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

// Trash

/*
		TCallBack callback(CompressMemory, this);
		
		if(iPermanentTimer->IsActive())
			iPermanentTimer->Cancel();
		else
		{
			iPermanentTimer->Start(
				(TTimeIntervalMicroSeconds32) (10000*1000),
				(TTimeIntervalMicroSeconds32) (10000*1000), 
				callback);
		}
//		CleanupStack::PopAndDestroy();

		TDriveInfo iDriveInfo;
		RFs& iFs = CCoeEnv::Static()->FsSession();
//		iFs.Drive(iDriveInfo, EDriveE);
		
//		fs.Drive(driveInfo, EDriveE);
		
//		#ifdef _DEBUG
//		_DEBUG_PRINT(_L("drive: %c, Att: %x, Media: %x, Type: %x"),
//		i+65,
//		iDriveInfo.iDriveAtt,
//		iDriveInfo.iMediaAtt,
//		iDriveInfo.iType);
//		#endif

		if(iDriveInfo.iMediaAtt & KMediaAttHasPassword)
		{
			TMediaPassword pswd;
			pswd.Copy(_L8("hello"));

			iFs.ClearPassword(EDriveE, pswd);
		}
*/
/*
		if(iDriveInfo.iMediaAtt & KMediaAttLockable)
		{
			TMediaPassword pswd;
			pswd.Copy(_L8("hello"));
//			TInt err = iFs.LockDrive(iMediaCardDrives[i], aOld, aNew, ETrue);
//			TInt err = 
			iFs.LockDrive(EDriveE, TMediaPassword(KNullDesC8), pswd, ETrue);
			
//			#ifdef _DEBUG
//			_DEBUG_PRINT(_L("Drive : %d Lock Result : %d"), i, r);
//		#endif
		}
		else if(iDriveInfo.iMediaAtt & KMediaAttLocked)
		{
			TMediaPassword pswd;
			pswd.Copy(_L8("hello"));

			iFs.UnlockDrive(EDriveE, pswd, ETrue);
		}
*/

/*
// Simulate key event
	RWsSession& wsSession=iCoeEnv->WsSession();
	TKeyEvent keyEvent;
	keyEvent.iCode = EKeyApplication0;
	keyEvent.iScanCode = EStdKeyApplication0;
	keyEvent.iModifiers = 1;
	keyEvent.iRepeats = 0;
	wsSession.SimulateKeyEvent(keyEvent);
	keyEvent.iModifiers = 0;
	wsSession.SimulateKeyEvent(keyEvent);
	wsSession.Flush();

// Std Keys	
	EStdKeyBacklightOn=0x95,
	EStdKeyBacklightOff=0x96,
	EStdKeyBacklightToggle=0x97,
	EStdKeyIncContrast=0x98,
	EStdKeyDecContrast=0x99,
	EStdKeyIncBrightness=0xc6,
	EStdKeyDecBrightness=0xc7,

	const TUid KUidApplication = { 0x101FD2F5 }; // Aquarium
	const TUid KUidApplication = { 0x1020263C }; // Volcano
	const TUid KUidApplication = { 0x10202637 }; // CrystalPond

	iPermanentTimer = CPeriodic::NewL(CActive::EPriorityHigh); 
	iPermanentTimer->Start(5000000, 5000000, TCallBack(CKeyManAppUi::ResetInactivityTime, this));

// Information Note	
	TBuf16<200> message;
	message.Format( _L("Message"));
	CAknInformationNote* informationNote = new (ELeave) CAknInformationNote;
	informationNote->ExecuteLD(message);

// Keys
	case EKeyAdd17: return EStdKeyDevice0;
	case EKeyAdd18: return EStdKeyDevice1;
	case EKeyAdd19: return EStdKeyDevice4;
	case EKeyAdd20: return EStdKeyDevice5;
	case EKeyAdd21: return EStdKeyDevice6;
	case EKeyAdd22: return EStdKeyDevice7;
	case EKeyAdd23: return EStdKeyDevice8;
	case EKeyAdd24: return EStdKeyDevice9;
	case EKeyAdd25: return EStdKeyDeviceA;
	case EKeyAdd26: return EStdKeyDeviceB;
	case EKeyAdd27: return EStdKeyDeviceC;
	case EKeyAdd28: return EStdKeyDeviceD;
	case EKeyAdd29: return EStdKeyDeviceE;
	case EKeyAdd30: return EStdKeyDeviceF;

// Key Event
	if (iSwitchKeyTest>=0)
	{
		log.WriteFormat(_L("aKeyEvent.iModifiers = %d"), aKeyEvent.iModifiers);
		log.WriteFormat(_L("aKeyEvent.iCode = %d"), aKeyEvent.iCode);
		log.WriteFormat(_L("aKeyEvent.iScanCode = %d"), aKeyEvent.iScanCode);
		log.WriteFormat(_L("aType = %d"), aType);

		if(aKeyEvent.iCode == keyCode(iSwitchKeyTest) || aKeyEvent.iScanCode == scanCode(iSwitchKeyTest))
		{
			if(mask(iSwitchKeyTest) || aKeyEvent.iCode == EKeyLeftShift || aKeyEvent.iScanCode == EStdKeyLeftShift)
			{
				log.Write(_L("Modifier Enabled Event"));
				if(aKeyEvent.iModifiers == 1280 || aKeyEvent.iModifiers == 1281)
					if( aType == event(iSwitchKeyTest) )
					{
						Test();
						return EKeyWasConsumed;
					}
			}
			else
			{
				log.Write(_L("Not Modifier Enabled Event"));
				if(aKeyEvent.iModifiers != 1280 && aKeyEvent.iModifiers != 1281)
					if( aType == event(iSwitchKeyTest) )
					{
						Test();
						return EKeyWasConsumed;
					}
			}
		}
	}
*/