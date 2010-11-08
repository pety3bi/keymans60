#include "KeyMan.hrh"
#include "KeyManListBox.h"

#include "KeyManAppUi.h"
#include "KeyManView1.h"

#include <KeyMan.rsg>

CAknSettingItem* CKeyManListbox::CreateSettingItemL( TInt aIdentifier )
{
	CAknSettingItem* settingItem = NULL;

	switch(aIdentifier)
	{
		case EKeyManSettingAutoStart:
			settingItem = new (ELeave) CAknBinaryPopupSettingItem ( aIdentifier, iAutoStart );
			break;
#ifdef SERIES_60_FP3
		case EKeyManSettingMMKey:
			if(iView->ui->CheckAppUID(KUidAnyKey.iUid))
				settingItem = new (ELeave) CAknBinaryPopupSettingItem ( aIdentifier, iMMKey );
			break;
#endif
		case EKeyManSettingFileManagers:
			if(iView->ui->CheckAppUID(KUidXPlore.iUid) || iView->ui->CheckAppUID(KUidYBrowser.iUid) || iView->ui->CheckAppUID(KUidGriffon.iUid)  || iView->ui->CheckAppUID(KUidBestFileMan.iUid))
				settingItem = new (ELeave) CAknBinaryPopupSettingItem ( aIdentifier, iFileManagers );
			break;
		case EKeyManSettingBookReaders:
			if(iView->ui->CheckAppUID(KUidQReader.iUid))
				settingItem = new (ELeave) CAknBinaryPopupSettingItem ( aIdentifier, iBookReaders );
			break;
		case EKeyManSettingCamera:
			if(iView->ui->CheckAppUID(KUidCamera.iUid))
				settingItem = new (ELeave) CAknBinaryPopupSettingItem ( aIdentifier, iCamera );
			break;
		case EKeyManSettingKeysToggle:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iToggleKey );
			break;
		case EKeyManSettingKeys:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKey );
			break;
		case EKeyManSettingLanguageFirst:
			settingItem = new (ELeave) CAknEnumeratedLanguagePopupSettingItem ( aIdentifier, iLanguageFirst );
			break;
		case EKeyManSettingKeysFirst:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeyFirst );
			break;
		case EKeyManSettingLanguageSecond:
			settingItem = new (ELeave) CAknEnumeratedLanguagePopupSettingItem ( aIdentifier, iLanguageSecond );
			break;
		case EKeyManSettingKeysSecond:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeySecond );
			break;
		case EKeyManSettingEnableThird:
			settingItem = new (ELeave) CAknBinaryPopupSettingItem( aIdentifier, iEnableThird );
			break;
		case EKeyManSettingLanguageThird:
			settingItem = new (ELeave) CAknEnumeratedLanguagePopupSettingItem ( aIdentifier, iLanguageThird );
			break;
		case EKeyManSettingKeysThird:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeyThird );
			break;
		case EKeyManSettingKeysMemory:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeyMemory );
			break;
		case EKeyManSettingKeysRestart:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeyRestart );
			break;
		case EKeyManSettingKeysShutdown:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeyShutdown );
			break;
		case EKeyManSettingKeysBTState:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iSwitchKeyBTState );
			break;
		case EKeyManSettingKeysBTMode:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyBTMode );
			break;
		case EKeyManSettingKeysSwitchApplications:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeySwitchApplications );
			break;
		case EKeyManSettingLockNote:
			settingItem = new (ELeave) CAknBinaryPopupSettingItem( aIdentifier, iLockNote );
			break;
		case EKeyManSettingKeysKeyLock:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyKeyLock );
			break;
		case EKeyManSettingKeysMinimize:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyMinimize );
			break;
		case EKeyManSettingKeysClose:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyClose );
			break;
		case EKeyManSettingKeysKill:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyKill );
			break;
		case EKeyManSettingKeysApp0:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp0 );
			break;
		case EKeyManSettingAppUID0:
			if(!iWaitDialog) {
//				iWaitDialog = new (ELeave) CAknWaitDialog(reinterpret_cast<CEikDialog**>(&iWaitDialog), ETrue);
				iWaitDialog = new (ELeave) CAknWaitDialog((REINTERPRET_CAST(CEikDialog**,&iWaitDialog)), ETrue);				
//				iWaitDialog->PrepareLC(R_WAIT_DIALOG);
//				iWaitDialog->RunLD();
				iWaitDialog->ExecuteLD(R_WAIT_DIALOG);
			}
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_0 );
			break;
		case EKeyManSettingKeysApp1:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp1 );
			break;
		case EKeyManSettingAppUID1:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_1 );
			break;
		case EKeyManSettingKeysApp2:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp2 );
			break;
		case EKeyManSettingAppUID2:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_2 );
			break;
		case EKeyManSettingKeysApp3:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp3 );
			break;
		case EKeyManSettingAppUID3:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_3 );
			break;
		case EKeyManSettingKeysApp4:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp4 );
			break;
		case EKeyManSettingAppUID4:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_4 );
			break;
		case EKeyManSettingKeysApp5:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp5 );
			break;
		case EKeyManSettingAppUID5:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_5 );
			break;
		case EKeyManSettingKeysApp6:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp6 );
			break;
		case EKeyManSettingAppUID6:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_6 );
			break;
		case EKeyManSettingKeysApp7:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp7 );
			break;
		case EKeyManSettingAppUID7:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_7 );
			break;
		case EKeyManSettingKeysApp8:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp8 );
			break;
		case EKeyManSettingAppUID8:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_8 );
			break;
		case EKeyManSettingKeysApp9:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp9 );
			if(iWaitDialog) {
				iWaitDialog->ProcessFinishedL();
//				iWaitDialog = NULL;
			}
			break;
		case EKeyManSettingAppUID9:
			settingItem = new ( ELeave) CAknEnumeratedApplicationPopupSettingItem ( aIdentifier, iUIDApplication_9 );
			break;

		case EKeyManSettingKeysTest:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyTest );
			break;
		case EKeyManSettingLog:
			settingItem = new (ELeave) CAknBinaryPopupSettingItem ( aIdentifier, iLog );
			break;
		case EKeyManSettingCapturePriority:
			settingItem = new (ELeave) CAknIntegerEdwinSettingItem ( aIdentifier, iCapturePriority );
			break;

		case EKeyManSettingNoteType:
			settingItem = new (ELeave) CAknEnumeratedTextPopupSettingItem ( aIdentifier, iNoteType );
			break;
		case EKeyManSettingNoteTimeout:
			settingItem = new (ELeave) CAknIntegerEdwinSettingItem ( aIdentifier, iNoteTimeout );
			break;
			
#ifndef SERIES_60_FP1
		case EKeyManSettingVibration:
			settingItem = new (ELeave) CAknBinaryPopupSettingItem( aIdentifier, iVibration );
			break;
		case EKeyManSettingVibrationTimeout:
			settingItem = new (ELeave) CAknIntegerEdwinSettingItem ( aIdentifier, iVibrationTimeout );
			break;
		case EKeyManSettingVibrationPower:
			settingItem = new (ELeave) CAknSliderSettingItem ( aIdentifier, iVibrationPower );
			break;
#endif
	}
	
	return settingItem;
}

void CKeyManListbox::SetView(CKeyManView1* aView)
{
	iView = aView;
}

void CKeyManListbox::HandleListBoxEventL( CEikListBox* aListBox, TListBoxEvent aEventType )
{
	CAknSettingItemList::HandleListBoxEventL( aListBox, aEventType );
	iView->UpdateSettings();  
}

TKeyResponse CKeyManListbox::OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType ) 
{
	if(iView->OfferKeyEventTabGroupL(aKeyEvent,aType)==EKeyWasConsumed)
		return EKeyWasConsumed;
	
	iView->ui->HandleKeyEventL( aKeyEvent, aType );

	// Disable ListBox Modifier Events
	if(aKeyEvent.iModifiers == 1280 || aKeyEvent.iModifiers == 1281)
		return EKeyWasConsumed;
	
	return CAknSettingItemList::OfferKeyEventL( aKeyEvent, aType );
}

CAknEnumeratedLanguagePopupSettingItem::CAknEnumeratedLanguagePopupSettingItem(TInt aResourceId, TInt &aValue)
:CAknEnumeratedTextPopupSettingItem(aResourceId, aValue)
{
}

/*
CAknEnumeratedLanguagePopupSettingItem::~CAknEnumeratedLanguagePopupSettingItem()
{
//	delete aEnumeratedTextArray;
//	delete aPoppedUpTextArray;
}
*/

void CAknEnumeratedLanguagePopupSettingItem::CompleteConstructionL()
{
//	CArrayPtr< CAknEnumeratedText > * aEnumeratedTextArray;
//	CArrayPtr< HBufC > * aPoppedUpTextArray;

	aEnumeratedTextArray = new (ELeave) CArrayPtrFlat<CAknEnumeratedText> (10);
	aPoppedUpTextArray = new (ELeave) CArrayPtrFlat<HBufC> (10);

	AknInputLanguageInfoFactory LanguageInfoFactory;
	CAknInputLanguageInfo* InputLanguageInfo = LanguageInfoFactory.CreateInputLanguageInfoL();

	HBufC* aText;

/*
	aText = HBufC::NewL(sizeof(TAknLanguageName));
	aText->Des().Copy(InputLanguageInfo->LanguageName(ELangEnglish));
	aEnumeratedTextArray->AppendL(new CAknEnumeratedText(ELangEnglish, aText));
//	aEnumeratedTextArray->AppendL(new CAknEnumeratedText(ELangEnglish, CCoeEnv::Static()->AllocReadResourceL(R_LSW_01)));
	
	aText = HBufC::NewL(sizeof(TAknLanguageName));
	aText->Des().Copy(InputLanguageInfo->LanguageName(ELangEnglish));
	aPoppedUpTextArray->AppendL(aText);
//	aPoppedUpTextArray->AppendL(CCoeEnv::Static()->AllocReadResourceL(R_LSW_01));
*/
	
	RFs fsSession;
	User::LeaveIfError(fsSession.Connect());
	RFile file;
	_LIT(fileName,"z:\\system\\bootdata\\languages.txt");
//	User::LeaveIfError(file.Open(fsSession, fileName, EFileStreamText|EFileRead|EFileShareAny));
	if(file.Open(fsSession, fileName, EFileStreamText|EFileRead|EFileShareAny) != KErrNotFound) {
		TFileText fileText;
		fileText.Set(file);
	
		TBuf<5> iBuf;
		// Read string while !EOF
		while(fileText.Read(iBuf) == KErrNone) {
			// Trim string
			iBuf.SetLength(2);
			// convert to TInt
			TLex iLex(iBuf);
			TInt iLangCode;
			iLex.Val(iLangCode);
			// Append to array
			aText = HBufC::NewL(sizeof(TAknLanguageName));
			aText->Des().Copy(InputLanguageInfo->LanguageName((TLanguage)iLangCode));
			aEnumeratedTextArray->AppendL(new CAknEnumeratedText(iLangCode, aText));

			aText = HBufC::NewL(sizeof(TAknLanguageName));
			aText->Des().Copy(InputLanguageInfo->LanguageName((TLanguage)iLangCode));
			aPoppedUpTextArray->AppendL(aText);
		}
		file.Flush();
		file.Close(); 
	}
	fsSession.Close();

	delete InputLanguageInfo;
	
	SetEnumeratedTextArrays(aEnumeratedTextArray, aPoppedUpTextArray);

	HandleTextArrayUpdateL(); 
	UpdateListBoxTextL();
}

CAknEnumeratedApplicationPopupSettingItem::CAknEnumeratedApplicationPopupSettingItem(TInt aResourceId, TInt &aValue)
:CAknEnumeratedTextPopupSettingItem(aResourceId, aValue)
{
}

void CAknEnumeratedApplicationPopupSettingItem::CompleteConstructionL()
{
	RApaLsSession iApaLs;
	iApaLs.Connect();
	TInt aCount = 0;
	User::LeaveIfError(iApaLs.AppCount(aCount));
	User::LeaveIfError(iApaLs.GetAllApps());
	
//	CArrayPtr< CAknEnumeratedText > * aEnumeratedTextArray;
//	CArrayPtr< HBufC > * aPoppedUpTextArray;

	aEnumeratedTextArray = new (ELeave) CArrayPtrFlat<CAknEnumeratedText> (aCount+1);
	aPoppedUpTextArray = new (ELeave) CArrayPtrFlat<HBufC> (aCount+1);

	aEnumeratedTextArray->AppendL(new CAknEnumeratedText(0, CCoeEnv::Static()->AllocReadResourceL(R_TEXT_NO)));
	aPoppedUpTextArray->AppendL(CCoeEnv::Static()->AllocReadResourceL(R_TEXT_NO));

	TApaAppInfo appInfo;
	while (iApaLs.GetNextApp(appInfo) == KErrNone) {
//		TApaAppCapabilityBuf capability;
//	    User::LeaveIfError(iApaLs.GetAppCapability(capability, appInfo.iUid));
//	    if (!capability().iAppIsHidden) {
	
		TInt spaceChar = 0;

    	for (TInt i = 0; i < appInfo.iCaption.Length(); ++i)
    	if (appInfo.iCaption[i] == ' ')
        	++spaceChar;

    	if (appInfo.iCaption.Length() > 0 && spaceChar < appInfo.iCaption.Length())
    	{
	    	aEnumeratedTextArray->AppendL(new CAknEnumeratedText(appInfo.iUid.iUid, appInfo.iCaption.AllocL()));
			aPoppedUpTextArray->AppendL(appInfo.iCaption.AllocL());
	    }
	}
	iApaLs.Close();

	SetEnumeratedTextArrays(aEnumeratedTextArray, aPoppedUpTextArray);
	
	HandleTextArrayUpdateL(); 
	UpdateListBoxTextL();
}