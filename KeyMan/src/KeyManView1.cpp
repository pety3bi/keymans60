#include  <aknviewappui.h>
#include  <avkon.hrh>
#include  <KeyMan.rsg>
#include  "KeyManView1.h"
#include  "KeyManAppUi.h"

class CKeyManAppUi;

void CKeyManView1::ConstructL()
{
	BaseConstructL( R_KEYMAN_VIEW1 );

	CEikStatusPane* sp = StatusPane();
	iNaviPane = (CAknNavigationControlContainer*)sp->ControlL(TUid::Uid(EEikStatusPaneUidNavi));
	iDecoratedTabGroup = iNaviPane->ResourceDecorator();
	if(iDecoratedTabGroup)
		iTabGroup = (CAknTabGroup*) iDecoratedTabGroup->DecoratedControl();
	
	#ifndef SERIES_60_FP1
		iTabGroup->AddTabL(EKeyManView7Tab, *CCoeEnv::Static()->AllocReadResourceL(R_LSW_VIEW7_TAB));
	#endif

	ui = (CKeyManAppUi*)AppUi();
	if(ui->log.LogValid())
		iTabGroup->AddTabL(EKeyManView8Tab, *CCoeEnv::Static()->AllocReadResourceL(R_TEXT_TEST));
}

CKeyManView1::~CKeyManView1()
{
	delete iDecoratedTabGroup;

	if(iListBox) {
		AppUi()->RemoveFromViewStack(*this, iListBox);
	}
	delete iListBox;
	iListBox = NULL;

	if(iContainer) {
		AppUi()->RemoveFromViewStack(*this, iContainer);
	}
	delete iContainer;
	iContainer = NULL;
}

TInt CKeyManView1::OfferKeyEventTabGroupL(const TKeyEvent &aKeyEvent, TEventCode aType) 
{
	if(aKeyEvent.iModifiers == 1280 || aKeyEvent.iModifiers == 1281)
		return EKeyWasNotConsumed;

	switch (aKeyEvent.iCode)
	{
		case '1':
			if ( iTabGroup->ActiveTabIndex() != 0 ) {
				iTabGroup->SetActiveTabByIndex(0);
				TabChangedL(0);
				return EKeyWasConsumed;
			}
			break;
		case '2':
			if ( iTabGroup->ActiveTabIndex() != 1 ) {
				iTabGroup->SetActiveTabByIndex(1);
				TabChangedL(1);
				return EKeyWasConsumed;
			}
			break;
		case '3':
			if ( iTabGroup->ActiveTabIndex() != 2 ) {
				iTabGroup->SetActiveTabByIndex(2);
				TabChangedL(2);
				return EKeyWasConsumed;
			}
			break;
		case '4':
			if ( iTabGroup->ActiveTabIndex() != 3 ) {
				iTabGroup->SetActiveTabByIndex(3);
				TabChangedL(3);
				return EKeyWasConsumed;
			}
			break;
		case '5':
			if ( iTabGroup->ActiveTabIndex() != 4 ) {
				iTabGroup->SetActiveTabByIndex(4);
				TabChangedL(4);
				return EKeyWasConsumed;
			}
			break;
		case '6':
			if ( iTabGroup->ActiveTabIndex() != 5 )	{
				iTabGroup->SetActiveTabByIndex(5);
				TabChangedL(5);
				return EKeyWasConsumed;
			}
			break;
		case '7':
			if ( iTabGroup->ActiveTabIndex() != 6 )	{
				iTabGroup->SetActiveTabByIndex(6);
				TabChangedL(6);
				return EKeyWasConsumed;
			}
			break;
		case '0':
			// Test tab check
			if(ui->log.LogValid()) {
				if ( iTabGroup->ActiveTabIndex() != 7 ) {
					iTabGroup->SetActiveTabByIndex(7);
					TabChangedL(7);
					return EKeyWasConsumed;
				}
			}
			break;
		default:
			break;
	}

	if(iTabGroup->OfferKeyEventL(aKeyEvent,aType)==EKeyWasConsumed)
	{
		TabChangedL(iTabGroup->ActiveTabIndex());
		return EKeyWasConsumed;
	}
	
	return EKeyWasNotConsumed;
}

void CKeyManView1::TabChangedL(TInt aIndex)
{
	switch(iTabGroup->ActiveTabIndex())
	{
		case 0:
			CreateListBoxL(R_SETTING_LIST_0);
			break;
		case 1:
			CreateListBoxL(R_SETTING_LIST_1);
			break;
		case 2:
			CreateListBoxL(R_SETTING_LIST_2);
			break;
		case 3:
			CreateListBoxL(R_SETTING_LIST_3);
			break;
		case 4:
			CreateListBoxL(R_SETTING_LIST_4);
			break;
		case 5:
			CreateListBoxL(R_SETTING_LIST_5);
			break;
		case 6:
			CreateListBoxL(R_SETTING_LIST_6);
			break;
		case 7:
			CreateListBoxL(R_SETTING_LIST_7);
			break;

		default: 
			break;
	}
}

TUid CKeyManView1::Id() const
{
	return KView1Id;
}

void CKeyManView1::HandleClientRectChange()
{
	if(iContainer)
		iContainer->SetRect(ClientRect());
}

CAknTabGroup* CKeyManView1::TabGroup()
{
	return iTabGroup;
}

void CKeyManView1::HandleCommandL(TInt aCommand)
{
	AppUi()->HandleCommandL(aCommand);
}

void CKeyManView1::DoActivateL(const TVwsViewId&,TUid,const TDesC8&)
{
	iDecoratedTabGroup->MakeVisible(ETrue);
	
	if(!iContainer) {
		iContainer = new (ELeave) CKeyManContainerSettings;
		iContainer->SetMopParent(this);
		iContainer->ConstructL( ClientRect() );
		AppUi()->AddToStackL( *this, iContainer );
	}

	if(!iListBox) {
		TabChangedL(iTabGroup->ActiveTabIndex());
	}
}

void CKeyManView1::DoDeactivate()
{
	iDecoratedTabGroup->MakeVisible(EFalse);
	
	if(iListBox) {
		AppUi()->RemoveFromStack(iListBox);
	}
	delete iListBox;
	iListBox = NULL;
	
	if (iContainer) {
		AppUi()->RemoveFromViewStack( *this, iContainer );
	}
	delete iContainer;
	iContainer = NULL;
}

void CKeyManView1::CreateListBoxL(TInt aResourceId)
{
	if(iListBox) {
		iListBox->StoreSettingsL();
		AppUi()->RemoveFromStack(iListBox);
	}
	delete iListBox;
	iListBox = NULL;

	iListBox = new (ELeave) CKeyManListbox;

	ui->ReloadSettings();
	
	iListBox->SetAutoStart				(ui->iAutoStart);
#ifdef SERIES_60_FP3
	iListBox->SetMMKey					(ui->iMMKey);
#endif
	iListBox->SetFileManagers			(ui->iFileManagers);
	iListBox->SetBookReaders			(ui->iBookReaders);
	iListBox->SetCamera					(ui->iCamera);
	
	iListBox->SetSwitchKeyToggle		(ui->iToggleKey);
	iListBox->SetSwitchKey				(ui->iSwitchKey);
	iListBox->SetSwitchKeyFirst			(ui->iSwitchKeyFirst);
	iListBox->SetLanguageFirst			(ui->iLanguageFirst);
	iListBox->SetSwitchKeySecond		(ui->iSwitchKeySecond);
	iListBox->SetLanguageSecond			(ui->iLanguageSecond);
	iListBox->SetEnableThird			(ui->iEnableThird);
	iListBox->SetSwitchKeyThird			(ui->iSwitchKeyThird);
	iListBox->SetLanguageThird			(ui->iLanguageThird);
	
	iListBox->SetSwitchKeyMemory		(ui->iSwitchKeyMemory);
	iListBox->SetSwitchKeyRestart		(ui->iSwitchKeyRestart);
	iListBox->SetSwitchKeyShutdown		(ui->iSwitchKeyShutdown);
	iListBox->SetSwitchKeyKeyLock		(ui->iSwitchKeyKeyLock);
	iListBox->SetLockNote				(ui->iLockNote);
	
	iListBox->SetSwitchKeyBTState		(ui->iSwitchKeyBTState);
	iListBox->SetSwitchKeyBTMode		(ui->iSwitchKeyBTMode);
	
	iListBox->SetSwitchApplications		(ui->iSwitchKeySwitchApplications);
	iListBox->SetSwitchKeyClose			(ui->iSwitchKeyClose);
	iListBox->SetSwitchKeyMinimize		(ui->iSwitchKeyMinimize);
	iListBox->SetSwitchKeyKill			(ui->iSwitchKeyKill);
	
	iListBox->SetSwitchKeyApp0			(ui->iSwitchKeyApp0);
	iListBox->SetSwitchKeyApp1			(ui->iSwitchKeyApp1);
	iListBox->SetSwitchKeyApp2			(ui->iSwitchKeyApp2);
	iListBox->SetSwitchKeyApp3			(ui->iSwitchKeyApp3);
	iListBox->SetSwitchKeyApp4			(ui->iSwitchKeyApp4);
	iListBox->SetSwitchKeyApp5			(ui->iSwitchKeyApp5);
	iListBox->SetSwitchKeyApp6			(ui->iSwitchKeyApp6);
	iListBox->SetSwitchKeyApp7			(ui->iSwitchKeyApp7);
	iListBox->SetSwitchKeyApp8			(ui->iSwitchKeyApp8);
	iListBox->SetSwitchKeyApp9			(ui->iSwitchKeyApp9);

	iListBox->SetUIDApp0				(ui->iUIDApplication_0);
	iListBox->SetUIDApp1				(ui->iUIDApplication_1);
	iListBox->SetUIDApp2				(ui->iUIDApplication_2);
	iListBox->SetUIDApp3				(ui->iUIDApplication_3);
	iListBox->SetUIDApp4				(ui->iUIDApplication_4);
	iListBox->SetUIDApp5				(ui->iUIDApplication_5);
	iListBox->SetUIDApp6				(ui->iUIDApplication_6);
	iListBox->SetUIDApp7				(ui->iUIDApplication_7);
	iListBox->SetUIDApp8				(ui->iUIDApplication_8);
	iListBox->SetUIDApp9				(ui->iUIDApplication_9);

	iListBox->SetSwitchKeyTest			(ui->iSwitchKeyTest);
	iListBox->SetLog					(ui->iLog);
	iListBox->SetCapturePriority		(ui->iCapturePriority);
	
	iListBox->SetNoteTimeout			(ui->iNoteTimeout);
	iListBox->SetNoteType				(ui->iNoteType);
	
#ifndef SERIES_60_FP1
	iListBox->SetVibration				(ui->iVibration);
	iListBox->SetVibrationTimeout		(ui->iVibrationTimeout);
	iListBox->SetVibrationPower			(ui->iVibrationPower);
#endif

	iListBox->SetView(this);
	iListBox->SetMopParent(this);
	iListBox->ConstructFromResourceL(aResourceId);
	AppUi()->AddToStackL(*this, iListBox);	
	iListBox->MakeVisible(ETrue);
	iListBox->SetRect(ClientRect());
//#ifdef SERIES_60_2
//	iListBox->InitBackGround(ClientRect());
//#endif
	iListBox->DrawNow();
	iListBox->ActivateL();
}

void CKeyManView1::DynInitMenuPaneL(TInt aResourceId, CEikMenuPane *aMenuPane)
{
	if (aResourceId == R_KEYMAN_VIEW1_MENU)	{
//		aMenuPane->SetItemDimmed(EKeyManCmdAppRegister, ETrue);
		aMenuPane->DeleteMenuItem(EKeyManCmdAppRegister);
	}
}

void CKeyManView1::UpdateSettings()
{
	ui->CancelCaptureKey();
	
	iListBox->StoreSettingsL();
	
	ui->iAutoStart = iListBox->GetAutoStart();
#ifdef SERIES_60_FP3
	ui->iMMKey = iListBox->GetMMKey();
#endif
	ui->iFileManagers = iListBox->GetFileManagers();
	ui->iBookReaders = iListBox->GetBookReaders();
	ui->iCamera = iListBox->GetCamera();

	ui->iToggleKey = iListBox->GetSwitchKeyToggle();
	ui->iSwitchKey = iListBox->GetSwitchKey();
	ui->iSwitchKeyFirst = iListBox->GetSwitchKeyFirst();
	ui->iLanguageFirst = iListBox->GetLanguageFirst();
	ui->iSwitchKeySecond = iListBox->GetSwitchKeySecond();
	ui->iLanguageSecond = iListBox->GetLanguageSecond();
	ui->iEnableThird = iListBox->GetEnableThird();
	ui->iSwitchKeyThird = iListBox->GetSwitchKeyThird();
	ui->iLanguageThird = iListBox->GetLanguageThird();
	
	ui->iSwitchKeyMemory = iListBox->GetSwitchKeyMemory();
	ui->iSwitchKeyRestart = iListBox->GetSwitchKeyRestart();
	ui->iSwitchKeyShutdown = iListBox->GetSwitchKeyShutdown();
	ui->iSwitchKeyKeyLock = iListBox->GetSwitchKeyKeyLock();
	ui->iLockNote = iListBox->GetLockNote();
	
	ui->iSwitchKeyBTState = iListBox->GetSwitchKeyBTState();
	ui->iSwitchKeyBTMode = iListBox->GetSwitchKeyBTMode();
	
	ui->iSwitchKeySwitchApplications = iListBox->GetSwitchApplications();
	ui->iSwitchKeyMinimize = iListBox->GetSwitchKeyMinimize();
	ui->iSwitchKeyClose = iListBox->GetSwitchKeyClose();
	ui->iSwitchKeyKill = iListBox->GetSwitchKeyKill();

	ui->iSwitchKeyApp0 = iListBox->GetSwitchKeyApp0();
	ui->iSwitchKeyApp1 = iListBox->GetSwitchKeyApp1();
	ui->iSwitchKeyApp2 = iListBox->GetSwitchKeyApp2();
	ui->iSwitchKeyApp3 = iListBox->GetSwitchKeyApp3();
	ui->iSwitchKeyApp4 = iListBox->GetSwitchKeyApp4();
	ui->iSwitchKeyApp5 = iListBox->GetSwitchKeyApp5();
	ui->iSwitchKeyApp6 = iListBox->GetSwitchKeyApp6();
	ui->iSwitchKeyApp7 = iListBox->GetSwitchKeyApp7();
	ui->iSwitchKeyApp8 = iListBox->GetSwitchKeyApp8();
	ui->iSwitchKeyApp9 = iListBox->GetSwitchKeyApp9();

	ui->iUIDApplication_0 = iListBox->GetUIDApp0();
	ui->iUIDApplication_1 = iListBox->GetUIDApp1();
	ui->iUIDApplication_2 = iListBox->GetUIDApp2();
	ui->iUIDApplication_3 = iListBox->GetUIDApp3();
	ui->iUIDApplication_4 = iListBox->GetUIDApp4();
	ui->iUIDApplication_5 = iListBox->GetUIDApp5();
	ui->iUIDApplication_6 = iListBox->GetUIDApp6();
	ui->iUIDApplication_7 = iListBox->GetUIDApp7();
	ui->iUIDApplication_8 = iListBox->GetUIDApp8();
	ui->iUIDApplication_9 = iListBox->GetUIDApp9();

	ui->iSwitchKeyTest = iListBox->GetSwitchKeyTest();
	ui->iLog = iListBox->GetLog();
	ui->iCapturePriority = iListBox->GetCapturePriority();
	
	ui->iNoteTimeout = iListBox->GetNoteTimeout();
	ui->iNoteType = iListBox->GetNoteType();
	
#ifndef SERIES_60_FP1	
	ui->iVibration = iListBox->GetVibration();
	ui->iVibrationTimeout = iListBox->GetVibrationTimeout();
	ui->iVibrationPower = iListBox->GetVibrationPower();
#endif

	sd.Connect(0);
	sd.Assign(KUidKeyMan);
	
	sd.SetInt(_L("autostart"), ui->iAutoStart);
#ifdef SERIES_60_FP3
	sd.SetInt(_L("mmkey"), ui->iMMKey);
#endif
	sd.SetInt(_L("filemanagers"), ui->iFileManagers);
	sd.SetInt(_L("bookreaders"), ui->iBookReaders );
	sd.SetInt(_L("camera"), ui->iCamera );
	
	sd.SetInt(_L("key_toggle"), ui->iToggleKey );
	sd.SetInt(_L("key_language"), ui->iSwitchKey );
	sd.SetInt(_L("key_language_1"), ui->iSwitchKeyFirst );
	sd.SetInt(_L("id_language_1"), ui->iLanguageFirst );
	sd.SetInt(_L("key_language_2"), ui->iSwitchKeySecond );
	sd.SetInt(_L("id_language_2"), ui->iLanguageSecond );
	sd.SetInt(_L("enable_language_3"), ui->iEnableThird );
	sd.SetInt(_L("key_language_3"), ui->iSwitchKeyThird );
	sd.SetInt(_L("id_language_3"), ui->iLanguageThird );

	sd.SetInt(_L("key_memory"), ui->iSwitchKeyMemory );
	sd.SetInt(_L("key_restart"), ui->iSwitchKeyRestart );
	sd.SetInt(_L("key_shutdown"), ui->iSwitchKeyShutdown );
	sd.SetInt(_L("lock_note"), ui->iLockNote );
	sd.SetInt(_L("key_lock"), ui->iSwitchKeyKeyLock );

	sd.SetInt(_L("key_bt_state"), ui->iSwitchKeyBTState );
	sd.SetInt(_L("key_bt_mode"), ui->iSwitchKeyBTMode );

	sd.SetInt(_L("key_switch"), ui->iSwitchKeySwitchApplications );
	sd.SetInt(_L("key_minimize"), ui->iSwitchKeyMinimize );
	sd.SetInt(_L("key_close"), ui->iSwitchKeyClose );
	sd.SetInt(_L("key_kill"), ui->iSwitchKeyKill );

	sd.SetInt(_L("key_app_0"), ui->iSwitchKeyApp0 );
	sd.SetInt(_L("uid_app_0"), ui->iUIDApplication_0 );
	sd.SetInt(_L("key_app_1"), ui->iSwitchKeyApp1 );
	sd.SetInt(_L("uid_app_1"), ui->iUIDApplication_1 );
	sd.SetInt(_L("key_app_2"), ui->iSwitchKeyApp2 );
	sd.SetInt(_L("uid_app_2"), ui->iUIDApplication_2 );
	sd.SetInt(_L("key_app_3"), ui->iSwitchKeyApp3 );
	sd.SetInt(_L("uid_app_3"), ui->iUIDApplication_3 );
	sd.SetInt(_L("key_app_4"), ui->iSwitchKeyApp4 );
	sd.SetInt(_L("uid_app_4"), ui->iUIDApplication_4 );
	sd.SetInt(_L("key_app_5"), ui->iSwitchKeyApp5 );
	sd.SetInt(_L("uid_app_5"), ui->iUIDApplication_5 );
	sd.SetInt(_L("key_app_6"), ui->iSwitchKeyApp6 );
	sd.SetInt(_L("uid_app_6"), ui->iUIDApplication_6 );
	sd.SetInt(_L("key_app_7"), ui->iSwitchKeyApp7 );
	sd.SetInt(_L("uid_app_7"), ui->iUIDApplication_7 );
	sd.SetInt(_L("key_app_8"), ui->iSwitchKeyApp8 );
	sd.SetInt(_L("uid_app_8"), ui->iUIDApplication_8 );
	sd.SetInt(_L("key_app_9"), ui->iSwitchKeyApp9 );
	sd.SetInt(_L("uid_app_9"), ui->iUIDApplication_9 );

	sd.SetInt(_L("key_test"), ui->iSwitchKeyTest );
	sd.SetInt(_L("log"), ui->iLog );
	sd.SetInt(_L("capture_priority"), ui->iCapturePriority );
				
	sd.SetInt(_L("note_time"), ui->iNoteTimeout );
	sd.SetInt(_L("note_type"), ui->iNoteType );

#ifndef SERIES_60_FP1
	sd.SetInt(_L("vibration"), ui->iVibration );
	sd.SetInt(_L("vibration_time"), ui->iVibrationTimeout );
	sd.SetInt(_L("vibration_power"), ui->iVibrationPower );
#endif

	sd.Close();

//	ui->CaptureKey();
	ui->ReloadSettings();
}