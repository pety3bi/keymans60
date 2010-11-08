#include <KeyMan.rsg>
#include "KeyManAppUi.h"
#include "KeyMan.hrh"
#include <avkon.hrh>

TUint CKeyManAppUi::keyCode(TInt key)
{
	switch(key)
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
		case EKeyLongPower:
		case EKeyPower: return EKeyDevice2;
		case EKeyShiftMenuKey:
		case EKeyLongMenu:
		case EKeyMenuKey: return EKeyApplication0;
		case EKeyShiftC: return EKeyBackspace;
		case EKeyShift: return EKeyLeftShift;
		case EKeyShiftMM:
		case EKeyLongMM:
		case EKeyMM: return EKeyApplication6;
		case EKeyShiftPhoto:
		case EKeyLongPhoto:
		case EKeyPhoto: return EKeyApplicationPhoto;
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
		
		// Experimental
		case EKeyAD41Play: return EKeyAD41_Play;
		case EKeyAD41Stop: return EKeyAD41_Stop;
		case EKeyAD41Rev: return EKeyAD41_Rev;
		case EKeyAD41FF: return EKeyAD41_FF;
		case EKeyAD41VolUp: return EKeyAD41_VolUp;
		case EKeyAD41VolDown: return EKeyAD41_VolDown;
	}
	return 0;
}

TInt CKeyManAppUi::scanCode(TInt key)
{
	switch(key)
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
		case EKeyShiftStar: return '*'/*EStdKeyNkpAsterisk*/;
		case EKeyShiftPower:
		case EKeyLongPower:
		case EKeyPower: return EStdKeyDevice2;
		case EKeyShiftMenuKey:
		case EKeyLongMenu:
		case EKeyMenuKey: return EStdKeyApplication0;
		case EKeyShiftC: return EStdKeyBackspace;
		case EKeyShift: return EStdKeyLeftShift;
		case EKeyShiftMM:
		case EKeyLongMM:
		case EKeyMM: return EStdKeyApplication6;
		case EKeyShiftPhoto:
		case EKeyLongPhoto:
		case EKeyPhoto: return EStdKeyApplicationPhoto;
		case EKeyShiftPTT:
		case EKeyLongPTT:
		case EKeyPTT: return EStdKeyDevice6;
		case EKeyShiftPTT2:
		case EKeyLongPTT2:	
		case EKeyPTT2: return EStdKeyDevice8; // 3230 PTT
		case EKeyShiftSoftLeft: return EStdKeyDevice0;
		case EKeyShiftSoftRight: return EStdKeyDevice1;
		case EKeyShiftUp: return EStdKeyUpArrow;
		case EKeyShiftDown: return EStdKeyDownArrow;
		case EKeyShiftLeft: return EStdKeyLeftArrow;
		case EKeyShiftRight: return EStdKeyRightArrow;
		case EKeyShiftCenter: return EStdKeyDevice3;
		
		// Experimental
		case EKeyAD41Play: return EStdKeyAD41_Play;
		case EKeyAD41Stop: return EStdKeyAD41_Stop;
		case EKeyAD41Rev: return EStdKeyAD41_Rev;
		case EKeyAD41FF: return EStdKeyAD41_FF;
		case EKeyAD41VolUp: return EStdKeyAD41_VolUp;
		case EKeyAD41VolDown: return EStdKeyAD41_VolDown;
	}
	return 0;
}

TUint CKeyManAppUi::mask(TInt key)
{
	switch(key)
	{
		case EKeyShiftCall:
		case EKeyShiftBreak:
		case EKeyShift1:
		case EKeyShift2:
		case EKeyShift3:
		case EKeyShift4:
		case EKeyShift5:
		case EKeyShift6:
		case EKeyShift7:
		case EKeyShift8:
		case EKeyShift9:
		case EKeyShift0:
		case EKeyShiftHash:
		case EKeyShiftStar:
		case EKeyShiftPower:
		case EKeyShiftMenuKey:
		case EKeyShiftC:
		case EKeyShiftMM:
		case EKeyShiftPhoto:
		case EKeyShiftPTT:
		case EKeyShiftPTT2:
		case EKeyShiftSoftLeft:
		case EKeyShiftSoftRight:
		case EKeyShiftUp:
		case EKeyShiftDown:
		case EKeyShiftLeft:
		case EKeyShiftRight:
		case EKeyShiftCenter:
			return EModifierShift;
	}
	return 0;
}

bool CKeyManAppUi::repeat(TInt key)
{
	switch(key)
	{
		case EKeyLongPhoto:
		case EKeyLongMM:
		case EKeyLongMenu:
		case EKeyLongPower:
		case EKeyLongPTT:
		case EKeyLongPTT2:
			return ETrue;
	}
	return EFalse;
}

TInt CKeyManAppUi::event(TInt key) 
{
	switch(key)	{
		// Experimental
		case EKeyAD41Play:
		case EKeyAD41Stop:
		case EKeyAD41Rev:
		case EKeyAD41FF:
		case EKeyAD41VolUp:
		case EKeyAD41VolDown:
			return EEventKeyDown;

		// Experimental
//		case EKeyPower:
//		case EKeyShiftPower:
//		case EKeyLongPower:
//			return EEventKeyUp;
			
		default:
			return EEventKey;
	}
}

void CKeyManAppUi::ConstructL()
{
#ifdef SERIES_60_FP1
	BaseConstructL();
#else
	BaseConstructL(EAknEnableSkin);
#endif

	log.Connect();
	log.SetDateAndTime(EFalse, EFalse);
	
	log.CreateLog(_L("keyman"),_L("keyman.log"),EFileLoggingModeOverwrite);
//	log.CreateLog(_L("keyman"),_L("keyman.log"),EFileLoggingModeAppend);
	
	if(log.LogValid()) {
		TInt MachineUid = 0;
		HAL::Get(HAL::EMachineUid, MachineUid);
		log.WriteFormat(_L("MachineUid = 0x%x"), MachineUid);
	
		TBuf<KSysUtilVersionTextLength> version;
/*
		if(SysUtil::GetLangVersion(version) == KErrNone)
			log.WriteFormat(_L("LangVersion = %d"), version);

		if(SysUtil::GetSWVersion(version) == KErrNone)
			log.WriteFormat(_L("SWVersion = %s"), version);
*/
		if(SysUtil::GetLangSWVersion(version) == KErrNone)
			log.Write(version);
		
		RFs fsSession;
		User::LeaveIfError(fsSession.Connect());
//		CleanupClosePushL(fsSession);
		
		RFile file;
		
		_LIT(KLangFileName,"z:\\system\\bootdata\\languages.txt");
		
//		User::LeaveIfError(file.Open(fsSession, fileName, EFileStreamText|EFileRead|EFileShareAny));
		if(file.Open(fsSession, KLangFileName, EFileStreamText|EFileRead|EFileShareAny) != KErrNotFound) {
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
				// Log
//				log.WriteFormat(_L("LangVersionString = %d"), iBuf);
				log.WriteFormat(_L("Lang = %d"), iLangCode);
			}
			file.Flush();
			file.Close(); 
		}
		fsSession.Close();
		
		
		// Log applications list
		_LIT(KLogFileName, "c:\\logs\\keyman\\applications.txt");
		const TInt KMaxSize = 512;

		RApaLsSession lsSession;

		// Connect to file server
		User::LeaveIfError(fsSession.Connect());
		CleanupClosePushL(fsSession);

		// Connect to application architecture server
		User::LeaveIfError(lsSession.Connect());
		CleanupClosePushL(lsSession);

		// Open (replace if exists) the file for writing 
		file.Replace(fsSession, KLogFileName, EFileWrite | EFileStreamText); 
		CleanupClosePushL(file);

		TApaAppInfo appInfo;
		
		TBuf<KMaxSize>  buf;
		TBuf8<KMaxSize> fileBuf;

		// Get info on all apps, then iterate through each app  
		// and write its info (caption, name, uid) to file 
		lsSession.GetAllApps();  
		while(lsSession.GetNextApp(appInfo) == KErrNone)
		{
			buf.Zero();
			buf.AppendNum(appInfo.iUid.iUid, EHex);
			buf.Append(_L("\t"));
			buf.Append(appInfo.iCaption);
			buf.Append(_L("\t"));
			buf.Append(appInfo.iFullName);

			fileBuf.Copy(buf);
			fileBuf.Append(_L("\n"));
			file.Write(fileBuf);
		}

		CleanupStack::PopAndDestroy(3);   
	}
	log.CloseLog();

	CKeyManView1* view1 = new (ELeave) CKeyManView1;

	CleanupStack::PushL(view1);
	view1->ConstructL();
	AddViewL(view1);
	CleanupStack::Pop();

	CKeyManView2* view2 = new (ELeave) CKeyManView2;

	CleanupStack::PushL(view2);
	view2->ConstructL();
	AddViewL(view2);
	CleanupStack::Pop();

	SetDefaultViewL(*view1);

// Null default capture
	iCaptureKeyToggle             = iCaptureKeyKeyUpAndDownsToggle             = iCaptureKeyLongToggle             = 0;
	iCaptureKey                   = iCaptureKeyKeyUpAndDowns                   = iCaptureKeyLong                   = 0;
	iCaptureKeyFirst              = iCaptureKeyKeyUpAndDownsFirst              = iCaptureKeyLongFirst              = 0;
	iCaptureKeySecond             = iCaptureKeyKeyUpAndDownsSecond             = iCaptureKeyLongSecond             = 0;
	iCaptureKeyThird              = iCaptureKeyKeyUpAndDownsThird              = iCaptureKeyLongThird              = 0;
	iCaptureKeyMemory             = iCaptureKeyKeyUpAndDownsMemory             = iCaptureKeyLongMemory             = 0;
	iCaptureKeyRestart            = iCaptureKeyKeyUpAndDownsRestart            = iCaptureKeyLongRestart            = 0;
	iCaptureKeyShutdown           = iCaptureKeyKeyUpAndDownsShutdown           = iCaptureKeyLongShutdown           = 0;
	iCaptureKeyBTState            = iCaptureKeyKeyUpAndDownsBTState            = iCaptureKeyLongBTState            = 0;
	iCaptureKeyBTMode             = iCaptureKeyKeyUpAndDownsBTMode             = iCaptureKeyLongBTMode             = 0;
	iCaptureKeySwitchApplications = iCaptureKeyKeyUpAndDownsSwitchApplications = iCaptureKeyLongSwitchApplications = 0;
	iCaptureKeyKeyLock            = iCaptureKeyKeyUpAndDownsKeyLock            = iCaptureKeyLongKeyLock            = 0;
	iCaptureKeyMinimize           = iCaptureKeyKeyUpAndDownsMinimize           = iCaptureKeyLongMinimize           = 0;
	iCaptureKeyClose              = iCaptureKeyKeyUpAndDownsClose              = iCaptureKeyLongClose              = 0;
	iCaptureKeyKill               = iCaptureKeyKeyUpAndDownsKill               = iCaptureKeyLongKill               = 0;

	iCaptureKeyApp0               = iCaptureKeyKeyUpAndDownsApp0               = iCaptureKeyLongApp0               = 0;
	iCaptureKeyApp1               = iCaptureKeyKeyUpAndDownsApp1               = iCaptureKeyLongApp1               = 0;
	iCaptureKeyApp2               = iCaptureKeyKeyUpAndDownsApp2               = iCaptureKeyLongApp2               = 0;
	iCaptureKeyApp3               = iCaptureKeyKeyUpAndDownsApp3               = iCaptureKeyLongApp3               = 0;
	iCaptureKeyApp4               = iCaptureKeyKeyUpAndDownsApp4               = iCaptureKeyLongApp4               = 0;
	iCaptureKeyApp5               = iCaptureKeyKeyUpAndDownsApp5               = iCaptureKeyLongApp5               = 0;
	iCaptureKeyApp6               = iCaptureKeyKeyUpAndDownsApp6               = iCaptureKeyLongApp6               = 0;
	iCaptureKeyApp7               = iCaptureKeyKeyUpAndDownsApp7               = iCaptureKeyLongApp7               = 0;
	iCaptureKeyApp8               = iCaptureKeyKeyUpAndDownsApp8               = iCaptureKeyLongApp8               = 0;
	iCaptureKeyApp9               = iCaptureKeyKeyUpAndDownsApp9               = iCaptureKeyLongApp9               = 0;
	
	iCaptureKeyTest               = iCaptureKeyKeyUpAndDownsTest               = iCaptureKeyLongTest               = 0;

// Null default settings
	iAutoStart                    = EFalse;
#ifdef SERIES_60_FP3
	iMMKey                        = EFalse;
#endif
	iFileManagers                 = EFalse;
	iBookReaders                  = EFalse;
	iCamera                       = EFalse;
	
	iToggleKey                    = EKeyNone;
	iSwitchKeyFirst               = EKeyNone;
	iSwitchKeySecond              = EKeyNone;
	iSwitchKeyThird               = EKeyNone;
	
	iSwitchKeyMemory              = EKeyNone;
	iSwitchKeyRestart             = EKeyNone;
	iSwitchKeyBTState             = EKeyNone;
	iSwitchKeyBTMode              = EKeyNone;
	iSwitchKeySwitchApplications  = EKeyNone;
	iSwitchKeyKeyLock             = EKeyNone;
	iSwitchKeyMinimize            = EKeyNone;
	iSwitchKeyClose               = EKeyNone;

	iSwitchKeyApp0                = EKeyNone;
	iSwitchKeyApp1                = EKeyNone;
	iSwitchKeyApp2                = EKeyNone;
	iSwitchKeyApp3                = EKeyNone;
	iSwitchKeyApp4                = EKeyNone;
	iSwitchKeyApp5                = EKeyNone;
	iSwitchKeyApp6                = EKeyNone;
	iSwitchKeyApp7                = EKeyNone;
	iSwitchKeyApp8                = EKeyNone;
	iSwitchKeyApp9                = EKeyNone;

	iSwitchKeyTest                = EKeyNone;
	iLog                          = EFalse;
	iCapturePriority              = 9999999;

	iEnableThird                  = EFalse;

	iLanguageFirst                = User::Language();
	iLanguageSecond               = User::Language();
	iLanguageThird                = User::Language();

	iUIDApplication_0             = 0;
	iUIDApplication_1             = 0;
	iUIDApplication_2             = 0;
	iUIDApplication_3             = 0;
	iUIDApplication_4             = 0;
	iUIDApplication_5             = 0;
	iUIDApplication_6             = 0;
	iUIDApplication_7             = 0;
	iUIDApplication_8             = 0;
	iUIDApplication_9             = 0;

	iLockNote                     = EFalse;

	iNoteTimeout                  = 300;
	iNoteType                     = ENoteTimeout;

#ifndef SERIES_60_FP1
	iVibration                    = EFalse;
	iVibrationTimeout             = 300;
	iVibrationPower               = 50;
#endif

	iPermanentTimer = CPeriodic::NewL(CActive::EPriorityStandard);

#ifndef SERIES_60_FP1
	vibration = VibraFactory::NewL();
#endif

	ReloadSettings();
}

CKeyManAppUi::~CKeyManAppUi()
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::CKeyManAppUi destructor"));

	log.CloseLog();
	log.Close();

	CancelCaptureKey();

	delete iPermanentTimer;

#ifndef SERIES_60_FP1
	delete vibration;
#endif
}

TKeyResponse CKeyManAppUi::HandleKeyEventL(const TKeyEvent& aKeyEvent,TEventCode aType)
{
	if(iLog) {
		log.Write(_L("CKeyManAppUi::HandleKeyEventL"));
		log.WriteFormat(_L("iCode = %d"), aKeyEvent.iCode);
		log.WriteFormat(_L("iScanCode = %d"), aKeyEvent.iScanCode);
		log.WriteFormat(_L("iModifiers = %d"), aKeyEvent.iModifiers);
		log.WriteFormat(_L("iRepeats = %d"), aKeyEvent.iRepeats);
		log.WriteFormat(_L("EventCode = %d"), aType);
	}
	
/*
	if((aKeyEvent.iRepeats && !repeat(aKeyEvent.iCode)) || (!aKeyEvent.iRepeats && repeat(aKeyEvent.iCode))) {
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task(iEikonEnv->WsSession());
		Task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
		if(Task.WgId() != ApaTaskList.FindApp(KUidKeyMan).WgId()) {
			TKeyEvent keyEvent;
			keyEvent.iCode = aKeyEvent.iCode;
			keyEvent.iScanCode = aKeyEvent.iScanCode;
			keyEvent.iModifiers = aKeyEvent.iModifiers;
			keyEvent.iRepeats = aKeyEvent.iRepeats;
			Task.SendKey(keyEvent);
		}
		return EKeyWasNotConsumed;;
	}
*/

	if(CheckKey(iToggleKey, aKeyEvent, aType)) {
		Toggle();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKey, aKeyEvent, aType)) {
		SwitchTo(0);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyFirst, aKeyEvent, aType)) {
		SwitchTo(iLanguageFirst);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeySecond, aKeyEvent, aType)) {
		SwitchTo(iLanguageSecond);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyThird, aKeyEvent, aType)) {
		SwitchTo(iLanguageThird);
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyMemory, aKeyEvent, aType)) {
		CompressMemory();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyRestart, aKeyEvent, aType)) {
		RestartPhone();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyShutdown, aKeyEvent, aType)) {
		ShutdownPhone();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyBTState, aKeyEvent, aType)) {
		SwitchBTState();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyBTMode, aKeyEvent, aType)) {
		SwitchBTMode();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeySwitchApplications, aKeyEvent, aType)) {
		CycleTasks();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyKeyLock, aKeyEvent, aType)) {
		KeyLock();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyMinimize, aKeyEvent, aType)) {
		MinimizeApplication();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyClose, aKeyEvent, aType)) {
		TerminateApplication();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyKill, aKeyEvent, aType)) {
		KillApplication();
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp0, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_0));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp1, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_1));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp2, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_2));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp3, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_3));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp4, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_4));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp5, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_5));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp6, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_6));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp7, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_7));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp8, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_8));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyApp9, aKeyEvent, aType)) {
		LaunchApplication(TUid::Uid(iUIDApplication_9));
		return EKeyWasConsumed;
	}
	if(CheckKey(iSwitchKeyTest, aKeyEvent, aType)) {
		Test();
		return EKeyWasConsumed;
	}
	
	return EKeyWasNotConsumed;
}

TBool CKeyManAppUi::CheckKey(TInt iKeyCode, const TKeyEvent& aKeyEvent, TEventCode aType)
{
	if(iKeyCode >= 0) {
		if(aKeyEvent.iCode == keyCode(iKeyCode) || aKeyEvent.iScanCode == scanCode(iKeyCode)) {

			if((aKeyEvent.iRepeats && !repeat(iKeyCode)) || (!aKeyEvent.iRepeats && repeat(iKeyCode))) {
/*
				TApaTaskList ApaTaskList(iCoeEnv->WsSession());
				TApaTask Task(iEikonEnv->WsSession());
				Task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
				if(Task.WgId() != ApaTaskList.FindApp(KUidKeyMan).WgId()) {
					TKeyEvent keyEvent;
					keyEvent.iCode = aKeyEvent.iCode;
					keyEvent.iScanCode = aKeyEvent.iScanCode;
					keyEvent.iModifiers = aKeyEvent.iModifiers;
					keyEvent.iRepeats = aKeyEvent.iRepeats;
					Task.SendKey(keyEvent);
				}
*/
				return EFalse;
			}
		
			if(mask(iKeyCode)) {
				if(aKeyEvent.iModifiers == 1280 || aKeyEvent.iModifiers == 1281) {
					if(aType == event(iKeyCode)) {
						// File Managers option
						if (!iFileManagers)
							return ETrue;

						TApaTaskList ApaTaskList(iCoeEnv->WsSession());
						TApaTask Task = ApaTaskList.FindByPos(0);
						switch (aKeyEvent.iCode)
						{
							case '1':
							case '2':
							case '3':
							case '4':
							case '5':
							case '6':
							case '7':
							case '8':
							case '9':
							case '0':
							{
								if (Task.WgId() == ApaTaskList.FindApp(KUidXPlore).WgId() || Task.WgId() == ApaTaskList.FindApp(KUidYBrowser).WgId() || Task.WgId() == ApaTaskList.FindApp(KUidBestFileMan).WgId())	{
										if(iLog)
											log.Write(_L("File Managers (0-9) -> key confirmed"));
										TKeyEvent keyEvent;
										keyEvent.iCode = aKeyEvent.iCode;
										keyEvent.iScanCode = aKeyEvent.iScanCode;
										keyEvent.iModifiers = aKeyEvent.iModifiers;
										keyEvent.iRepeats = aKeyEvent.iRepeats;
										Task.SendKey(keyEvent);
										return EFalse;
								}
								break;
							}
							case EKeyYes:
							case EKeyLeftArrow:
							case EKeyRightArrow:
							case EKeyDevice3:
							{
								if (Task.WgId() == ApaTaskList.FindApp(KUidXPlore).WgId())
								{
										if(iLog)
											log.Write(_L("File Managers (XPlore) -> key confirmed"));
										TKeyEvent keyEvent;
										keyEvent.iCode = aKeyEvent.iCode;
										keyEvent.iScanCode = aKeyEvent.iScanCode;
										keyEvent.iModifiers = aKeyEvent.iModifiers;
										keyEvent.iRepeats = aKeyEvent.iRepeats;
										Task.SendKey(keyEvent);
										return EFalse;
								}
								break;
							}
						}

						// Griffon HotKeys
						switch (aKeyEvent.iCode)	
						{
							case '1':
							case '2':
							case '4':
							case '6':
							case EKeyUpArrow:
							case EKeyDownArrow:
							case EKeyRightArrow:
							{
								if (Task.WgId() == ApaTaskList.FindApp(KUidGriffon).WgId())
								{
										if(iLog)
											log.Write(_L("File Managers (Griffon) -> key confirmed"));
										TKeyEvent keyEvent;
										keyEvent.iCode = aKeyEvent.iCode;
										keyEvent.iScanCode = aKeyEvent.iScanCode;
										keyEvent.iModifiers = aKeyEvent.iModifiers;
										keyEvent.iRepeats = aKeyEvent.iRepeats;
										Task.SendKey(keyEvent);
										return EFalse;
								}
								break;
							}
						}

						return ETrue;
					}
				}
			}
			else
			{
				if(aKeyEvent.iModifiers != 1280 && aKeyEvent.iModifiers != 1281)
				{
					if(aType == event(iKeyCode))
					{
						// Check if Camera key is used
						if(aKeyEvent.iScanCode == EStdKeyApplicationPhoto || aKeyEvent.iScanCode == EStdKeyDevice6 || aKeyEvent.iScanCode == EStdKeyDevice8)
						{
							// in Camera
							TApaTaskList ApaTaskList(iCoeEnv->WsSession());
							TApaTask Task_1 = ApaTaskList.FindApp(KUidCamera);

							RWsSession ws;
							User::LeaveIfError(ws.Connect());

							if(Task_1.WgId() == ws.GetFocusWindowGroup() && iCamera)
							{
								if(iLog)
									log.Write(_L("Camera -> key confirmed"));
/*								
								TApaTask Task = ApaTaskList.FindApp(KUidCamServerCore);
								if(Task.Exists()) {
									TKeyEvent keyEvent;
									keyEvent.iCode = aKeyEvent.iCode;
									keyEvent.iScanCode = aKeyEvent.iScanCode;
									keyEvent.iModifiers = aKeyEvent.iModifiers;
									keyEvent.iRepeats = aKeyEvent.iRepeats;
									Task.SendKey(keyEvent);
							}
*/
								TKeyEvent keyEvent;

								keyEvent.iCode         = EKeyDevice3;
//								keyEvent.iCode         = EKeyApplicationPhoto;
								keyEvent.iScanCode     = EStdKeyDevice3;
//								keyEvent.iScanCode     = EStdKeyApplicationPhoto;
								keyEvent.iModifiers    = 1;
								keyEvent.iRepeats      = 0;
								Task_1.SendKey(keyEvent);

								return EFalse;
							}

							// in QReader
							TApaTask Task_2 = ApaTaskList.FindApp(KUidQReader);

							if(Task_2.WgId() == ws.GetFocusWindowGroup() && iBookReaders)
							{
								if(iLog)
									log.Write(_L("QReader -> key confirmed"));
								TKeyEvent keyEvent;
//								keyEvent.iCode          = EKeyDevice1;
								keyEvent.iCode          = EKeyDownArrow;
//								keyEvent.iScanCode      = EStdKeyDevice1;
								keyEvent.iScanCode      = EStdKeyDownArrow;
								keyEvent.iModifiers     = 1;
								keyEvent.iRepeats       = 0;
								Task_2.SendKey(keyEvent);
								return EFalse;
							}
							ws.Close();
						}
						return ETrue;
					}
				}
			}
		}
	}
	return EFalse;
}

void CKeyManAppUi::HandleCommandL( TInt aCommand )
{
	switch(aCommand) {
		case EAknSoftkeyBack: {
			TApaTask task(iEikonEnv->WsSession());
			task.SetWgId(CEikonEnv::Static()->RootWin().Identifier());
			task.SendToBackground();
			break;
		}
		case EEikCmdExit: {
			LaunchApplication(KUidAnyKey);
			Exit();
			break;
		}
		case EAknSoftkeyOk:	{
			ActivateLocalViewL(KView1Id);
			break;
		}
		case EKeyManCmdAppAbout: {
			ActivateLocalViewL(KView2Id);
			break;
		}
		case EKeyManCmdAppRegister: {
			TBuf<128> strCode;
			CAknTextQueryDialog *dlgReg = CAknTextQueryDialog::NewL(strCode);
			if(dlgReg->ExecuteLD(R_KM_REGISTRATION)) {
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

/*
void CKeyManAppUi::HandleForegroundEventL(TBool aForeground)
{
//	CAknAppUi::HandleForegroundEventL(aForeground);
	if(!aForeground)
		ActivateLocalViewL(KView1Id);
//	if(aForeground)
		// Мы получили фокус
//	else
		// Мы потеряли фокус
}
*/

void CKeyManAppUi::SwitchTo(TInt language_id) 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::SwitchTo"));

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

		AknInputLanguageInfoFactory LanguageInfoFactory;
		CAknInputLanguageInfo* InputLanguageInfo = LanguageInfoFactory.CreateInputLanguageInfoL();
		if(iLog)
			log.Write(InputLanguageInfo->LanguageName((TLanguage) language_id));
		
		if(iNoteTimeout && iNoteType!=ENoteDont) {
			TAknLanguageName LanguageName = InputLanguageInfo->LanguageName((TLanguage) language_id);
			
			HBufC* textFormat = iCoeEnv->AllocReadResourceLC(R_TEXT_LANGUAGE);
			HBufC* text = HBufC::NewLC(textFormat->Length() + sizeof(TAknLanguageName));
			text->Des().Format(*textFormat, &LanguageName);

			CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
			CleanupStack::PushL(globalNote);
			globalNote->SetTone(0);
			globalNote->SetPriority(CActive::EPriorityHigh);

			iPermanentNoteId = globalNote->ShowNoteL(EAknGlobalConfirmationNote, *text);
			CleanupStack::PopAndDestroy(text);
			CleanupStack::PopAndDestroy(textFormat);
			CleanupStack::PopAndDestroy();

			TCallBack callback(PermanentNoteTimeoutL, this);
			iPermanentTimer->Cancel();
			iPermanentTimer->Start(
				(TTimeIntervalMicroSeconds32) (iNoteTimeout*1000),
				(TTimeIntervalMicroSeconds32) (100*1000), 
				callback);
		}
		delete InputLanguageInfo;

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
	if(iLog)
		log.Write(_L("CKeyManAppUi::CompressMemory"));

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

		if (iNoteTimeout && iNoteType!=ENoteDont) {
			HBufC* textFormat = iCoeEnv->AllocReadResourceLC(R_TEXT_COMPRESSED_MEMORY);
			HBufC* text = HBufC::NewLC(textFormat->Length() + sizeof (afterFreeRAM >> 10) + sizeof((afterFreeRAM - beforeFreeRAM) >> 10));
			text->Des().Format(*textFormat, (afterFreeRAM - beforeFreeRAM) >> 10, afterFreeRAM >> 10);

			CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
			CleanupStack::PushL(globalNote);
			globalNote->SetTone(0);
			globalNote->SetPriority(CActive::EPriorityHigh);

			iPermanentNoteId = globalNote->ShowNoteL(EAknGlobalInformationNote, *text);
			CleanupStack::PopAndDestroy(text);
			CleanupStack::PopAndDestroy(textFormat);
			CleanupStack::PopAndDestroy();

			TCallBack callback(PermanentNoteTimeoutL, this);
			iPermanentTimer->Cancel();
			iPermanentTimer->Start(
				(TTimeIntervalMicroSeconds32) (iNoteTimeout*1000),
				(TTimeIntervalMicroSeconds32) (100*1000), 
				callback);
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
	if(iLog)
		log.Write(_L("CKeyManAppUi::RestartPhone"));

	// Restart phone
	SysStartup::ShutdownAndRestart(KUidKeyMan, ESWNone);
}

void CKeyManAppUi::ShutdownPhone()
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::ShutdownPhone"));

	// Shutdown phone
	SysStartup::Shutdown(KUidKeyMan);
}

void CKeyManAppUi::TerminateApplication(TUid KUidApplication) 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::TerminateApplication"));

	// Terminate application
	TApaTaskList ApaTaskList(iCoeEnv->WsSession());
	TApaTask Task = ApaTaskList.FindApp( KUidApplication );
	if(Task.Exists())
		Task.EndTask();
}

void CKeyManAppUi::TerminateApplication() 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::TerminateApplication"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Terminate application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindByPos(0);
		if (Task.WgId() != ApaTaskList.FindApp(KUidPhone).WgId())
			Task.EndTask();
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::KillApplication() 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::KillApplication"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Terminate application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindByPos(0);
		if (Task.WgId() != ApaTaskList.FindApp(KUidPhone).WgId())
			Task.KillTask();
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::LaunchApplication(TUid KUidApplication) 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::LaunchApplication"));
	
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled()) {
		// LaunchApplication
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindApp(KUidApplication);
		if(!Task.Exists()) {
			RApaLsSession iApaLs;
			if(iApaLs.Connect()!=KErrNone)
				return;

			TApaAppInfo appInfo;
			if(iApaLs.GetAppInfo(appInfo,KUidApplication)==KErrNone) {
				HBufC* name = HBufC::New(appInfo.iFullName.Length()); 
				name->Des().Copy(appInfo.iFullName);
				CApaCommandLine* cmdLine = CApaCommandLine::New(name);
				if(KUidApplication != KUidAnyKey)
					cmdLine->SetCommandL(EApaCommandRun);
				else
					cmdLine->SetCommandL(EApaCommandBackground);
				iApaLs.StartApp(*cmdLine);
			}
			iApaLs.Close();
		}
		else {
			RWsSession ws;
			User::LeaveIfError(ws.Connect());
			if(Task.WgId() == ws.GetFocusWindowGroup())
				Task.SendToBackground();
			else
				if (KUidApplication != KUidAnyKey)
					Task.BringToForeground();
			ws.Close();
		}
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::MinimizeApplication() 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::MinimizeApplication"));
	
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Minimize application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindApp(KUidPhone);
		if (Task.Exists())
			Task.BringToForeground();
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::Toggle() 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::Toggle"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Toggle application
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		TApaTask Task = ApaTaskList.FindApp(KUidKeyMan);
		RWsSession ws;
		User::LeaveIfError(ws.Connect());
		if(Task.WgId() == ws.GetFocusWindowGroup())
			Task.SendToBackground();
		else
			Task.BringToForeground();
		ws.Close();
	}
	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

void CKeyManAppUi::CycleTasks() 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::CycleTasks"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Cycle Tasks
		TInt numOfTask = 0;
		TApaTaskList ApaTaskList(iCoeEnv->WsSession());
		while (numOfTask < 256) {
			bool taskHidden = true;
			TInt taskWgId = ApaTaskList.FindByPos(numOfTask).WgId();
			
			if (taskWgId != 0) {
				CApaWindowGroupName *wGrName = CApaWindowGroupName::NewL(CEikonEnv::Static()->WsSession(), taskWgId );
				CleanupStack::PushL( wGrName );
				if (!wGrName->Hidden())
					taskHidden = false;
				CleanupStack::PopAndDestroy( wGrName );
			}
			if (taskHidden) {
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
	if(iLog)
		log.Write(_L("CKeyManAppUi::SwitchBTState"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Switch BlueTooth State
		CBTMCMSettings * BtSettings = CBTMCMSettings::NewLC(NULL);
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
	if(iLog)
		log.Write(_L("CKeyManAppUi::SwitchBTMode"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Switch BlueTooth Mode
		CBTMCMSettings * BtSettings=CBTMCMSettings::NewLC(NULL);

		if(iPermanentTimer->IsActive())
			PermanentNoteTimeoutL(this);

		TBTDiscoverabilityMode mode;
		BtSettings->GetDiscoverabilityModeL(mode);

		HBufC* string;
		switch (mode)
		{
			case 2:
				string = CCoeEnv::Static()->AllocReadResourceLC(R_TEXT_BT_MODE_1);
				BtSettings->SetDiscoverabilityModeL(EBTDiscoverabilityMode1, EFalse);
				break;
			case 	3:
				string = CCoeEnv::Static()->AllocReadResourceLC(R_TEXT_BT_MODE_2);
				BtSettings->SetDiscoverabilityModeL(EBTDiscoverabilityMode0, EFalse);
				break;
			default:
				string = CCoeEnv::Static()->AllocReadResourceLC(R_LSW_UNKNOWN);
				break;
		}

		HBufC* textFormat = iCoeEnv->AllocReadResourceLC(R_TEXT_BT_MODE);
		HBufC* text = HBufC::NewLC(textFormat->Length() + string->Length());
		text->Des().Format(*textFormat, string);

		CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
		CleanupStack::PushL(globalNote);
		globalNote->SetTone(0);
		globalNote->SetPriority(CActive::EPriorityHigh);

		iPermanentNoteId = globalNote->ShowNoteL(EAknGlobalConfirmationNote, *text);
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

void CKeyManAppUi::KeyLock()
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::KeyLock"));
	
	// KeyLock
	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(keyLock.IsKeyLockEnabled()) {
		if(iLockNote)
			keyLock.DisableKeyLock();
		else {
			keyLock.DisableWithoutNote();
//			keyLock.EnableSoftNotifications(ETrue);
		}
	}
	else {
		if(iLockNote)
			keyLock.EnableKeyLock();
		else {
			keyLock.EnableWithoutNote();
//			keyLock.EnableSoftNotifications(EFalse);
		}
	}

#ifndef SERIES_60_FP1
	// Vibration
	if (iVibrationTimeout && iVibration)
		vibration->StartVibraL(iVibrationTimeout, iVibrationPower);
#endif

	keyLock.Close();
	CleanupStack::PopAndDestroy();
}

TInt CKeyManAppUi::CheckAppUID(TInt iUID) {
	RApaLsSession iApaLs;
	if(iApaLs.Connect() != KErrNone)
		return 0;
	TApaAppInfo appInfo;
	if(iApaLs.GetAppInfo(appInfo,TUid::Uid(iUID)) == KErrNone) {
		iApaLs.Close();
		return iUID;
	}
	iApaLs.Close();
	return 0;
}

void CKeyManAppUi::ReloadSettings()
{
	CancelCaptureKey();
	
	sd.Connect(0);
	sd.Assign( KUidKeyMan );

	sd.GetInt( _L("autostart"), iAutoStart );
#ifdef SERIES_60_FP3
	sd.GetInt( _L("mmkey"), iMMKey );
#endif
	sd.GetInt( _L("filemanagers"), iFileManagers );
	sd.GetInt( _L("bookreaders"), iBookReaders );
	sd.GetInt( _L("camera"), iCamera );
			
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
	sd.GetInt( _L("key_shutdown"), iSwitchKeyShutdown );
	sd.GetInt( _L("lock_note"), iLockNote );
	sd.GetInt( _L("key_lock"), iSwitchKeyKeyLock );
	sd.GetInt( _L("key_bt_state"), iSwitchKeyBTState );
	sd.GetInt( _L("key_bt_mode"), iSwitchKeyBTMode );
	sd.GetInt( _L("key_switch"), iSwitchKeySwitchApplications );
	sd.GetInt( _L("key_minimize"), iSwitchKeyMinimize );
	sd.GetInt( _L("key_close"), iSwitchKeyClose );
	sd.GetInt( _L("key_kill"), iSwitchKeyKill );

	
	sd.GetInt( _L("key_app_0"), iSwitchKeyApp0 );
	sd.GetInt( _L("uid_app_0"), iUIDApplication_0 );
	sd.GetInt( _L("key_app_1"), iSwitchKeyApp1 );
	sd.GetInt( _L("uid_app_1"), iUIDApplication_1 );
	sd.GetInt( _L("key_app_2"), iSwitchKeyApp2 );
	sd.GetInt( _L("uid_app_2"), iUIDApplication_2 );
	sd.GetInt( _L("key_app_3"), iSwitchKeyApp3 );
	sd.GetInt( _L("uid_app_3"), iUIDApplication_3 );
	sd.GetInt( _L("key_app_4"), iSwitchKeyApp4 );
	sd.GetInt( _L("uid_app_4"), iUIDApplication_4 );
	sd.GetInt( _L("key_app_5"), iSwitchKeyApp5 );
	sd.GetInt( _L("uid_app_5"), iUIDApplication_5 );
	sd.GetInt( _L("key_app_6"), iSwitchKeyApp6 );
	sd.GetInt( _L("uid_app_6"), iUIDApplication_6 );
	sd.GetInt( _L("key_app_7"), iSwitchKeyApp7 );
	sd.GetInt( _L("uid_app_7"), iUIDApplication_7 );
	sd.GetInt( _L("key_app_8"), iSwitchKeyApp8 );
	sd.GetInt( _L("uid_app_8"), iUIDApplication_8 );
	sd.GetInt( _L("key_app_9"), iSwitchKeyApp9 );
	sd.GetInt( _L("uid_app_9"), iUIDApplication_9 );

	sd.GetInt( _L("key_test"), iSwitchKeyTest );
	sd.GetInt( _L("log"), iLog );
	sd.GetInt( _L("capture_priority"), iCapturePriority );
	
	sd.GetInt( _L("note_time"), iNoteTimeout );
	sd.GetInt( _L("note_type"), iNoteType );
	
#ifndef SERIES_60_FP1
	sd.GetInt( _L("vibration"), iVibration );
	sd.GetInt( _L("vibration_time"), iVibrationTimeout );
	sd.GetInt( _L("vibration_power"), iVibrationPower );
#endif

	sd.Close();

	iUIDApplication_0 = CheckAppUID(iUIDApplication_0);
	iUIDApplication_1 = CheckAppUID(iUIDApplication_1);
	iUIDApplication_2 = CheckAppUID(iUIDApplication_2);
	iUIDApplication_3 = CheckAppUID(iUIDApplication_3);
	iUIDApplication_4 = CheckAppUID(iUIDApplication_4);
	iUIDApplication_5 = CheckAppUID(iUIDApplication_5);
	iUIDApplication_6 = CheckAppUID(iUIDApplication_6);
	iUIDApplication_7 = CheckAppUID(iUIDApplication_7);
	iUIDApplication_8 = CheckAppUID(iUIDApplication_8);
	iUIDApplication_9 = CheckAppUID(iUIDApplication_9);

#ifdef SERIES_60_FP3
	if(iMMKey)
		TerminateApplication(KUidAnyKey);
	else
		LaunchApplication(KUidAnyKey);
#endif
	
	if(iLog)
		log.CreateLog(_L("keyman"),_L("keyman.log"),EFileLoggingModeAppend);
	else
		log.CloseLog();

	CaptureKey();
}

void CKeyManAppUi::CaptureKey()
{
	CaptureKey(iCapturePriority, iToggleKey, iCaptureKeyToggle, iCaptureKeyKeyUpAndDownsToggle, iCaptureKeyLongToggle);

	CaptureKey(iCapturePriority, iSwitchKey, iCaptureKey, iCaptureKeyKeyUpAndDowns, iCaptureKeyLong);
	CaptureKey(iCapturePriority, iSwitchKeyFirst, iCaptureKeyFirst, iCaptureKeyKeyUpAndDownsFirst, iCaptureKeyLongFirst);
	CaptureKey(iCapturePriority, iSwitchKeySecond, iCaptureKeySecond, iCaptureKeyKeyUpAndDownsSecond, iCaptureKeyLongSecond);
	CaptureKey(iCapturePriority, iSwitchKeyThird, iCaptureKeyThird, iCaptureKeyKeyUpAndDownsThird, iCaptureKeyLongThird);

	CaptureKey(iCapturePriority, iSwitchKeyMemory, iCaptureKeyMemory, iCaptureKeyKeyUpAndDownsMemory, iCaptureKeyLongMemory);
	CaptureKey(iCapturePriority, iSwitchKeyRestart, iCaptureKeyRestart, iCaptureKeyKeyUpAndDownsRestart, iCaptureKeyLongRestart);
	CaptureKey(iCapturePriority, iSwitchKeyShutdown, iCaptureKeyShutdown, iCaptureKeyKeyUpAndDownsShutdown, iCaptureKeyLongShutdown);
	CaptureKey(iCapturePriority, iSwitchKeyKeyLock, iCaptureKeyKeyLock, iCaptureKeyKeyUpAndDownsKeyLock, iCaptureKeyLongKeyLock);
	
	CaptureKey(iCapturePriority, iSwitchKeyBTMode, iCaptureKeyBTMode, iCaptureKeyKeyUpAndDownsBTMode, iCaptureKeyLongBTMode);
	CaptureKey(iCapturePriority, iSwitchKeyBTState, iCaptureKeyBTState, iCaptureKeyKeyUpAndDownsBTState, iCaptureKeyLongBTState);

	CaptureKey(iCapturePriority, iSwitchKeySwitchApplications, iCaptureKeySwitchApplications, iCaptureKeyKeyUpAndDownsSwitchApplications, iCaptureKeyLongSwitchApplications);
	CaptureKey(iCapturePriority, iSwitchKeyMinimize, iCaptureKeyMinimize, iCaptureKeyKeyUpAndDownsMinimize, iCaptureKeyLongMinimize);
	CaptureKey(iCapturePriority, iSwitchKeyClose, iCaptureKeyClose, iCaptureKeyKeyUpAndDownsClose, iCaptureKeyLongClose);
	CaptureKey(iCapturePriority, iSwitchKeyKill, iCaptureKeyKill, iCaptureKeyKeyUpAndDownsKill, iCaptureKeyLongKill);
	
	CaptureKey(iCapturePriority, iSwitchKeyApp0, iCaptureKeyApp0, iCaptureKeyKeyUpAndDownsApp0, iCaptureKeyLongApp0);
	CaptureKey(iCapturePriority, iSwitchKeyApp1, iCaptureKeyApp1, iCaptureKeyKeyUpAndDownsApp1, iCaptureKeyLongApp1);
	CaptureKey(iCapturePriority, iSwitchKeyApp2, iCaptureKeyApp2, iCaptureKeyKeyUpAndDownsApp2, iCaptureKeyLongApp2);
	CaptureKey(iCapturePriority, iSwitchKeyApp3, iCaptureKeyApp3, iCaptureKeyKeyUpAndDownsApp3, iCaptureKeyLongApp3);
	CaptureKey(iCapturePriority, iSwitchKeyApp4, iCaptureKeyApp4, iCaptureKeyKeyUpAndDownsApp4, iCaptureKeyLongApp4);
	CaptureKey(iCapturePriority, iSwitchKeyApp5, iCaptureKeyApp5, iCaptureKeyKeyUpAndDownsApp5, iCaptureKeyLongApp5);
	CaptureKey(iCapturePriority, iSwitchKeyApp6, iCaptureKeyApp6, iCaptureKeyKeyUpAndDownsApp6, iCaptureKeyLongApp6);
	CaptureKey(iCapturePriority, iSwitchKeyApp7, iCaptureKeyApp7, iCaptureKeyKeyUpAndDownsApp7, iCaptureKeyLongApp7);
	CaptureKey(iCapturePriority, iSwitchKeyApp8, iCaptureKeyApp8, iCaptureKeyKeyUpAndDownsApp8, iCaptureKeyLongApp8);
	CaptureKey(iCapturePriority, iSwitchKeyApp9, iCaptureKeyApp9, iCaptureKeyKeyUpAndDownsApp9, iCaptureKeyLongApp9);

	if(log.LogValid())
		CaptureKey(iCapturePriority, iSwitchKeyTest, iCaptureKeyTest, iCaptureKeyKeyUpAndDownsTest, iCaptureKeyLongTest);
}

void CKeyManAppUi::CancelCaptureKey()
{
	CancelCaptureKey(iCaptureKeyToggle, iCaptureKeyKeyUpAndDownsToggle, iCaptureKeyLongToggle);

	CancelCaptureKey(iCaptureKey, iCaptureKeyKeyUpAndDowns, iCaptureKeyLong);
	CancelCaptureKey(iCaptureKeyFirst, iCaptureKeyKeyUpAndDownsFirst, iCaptureKeyLongFirst);
	CancelCaptureKey(iCaptureKeySecond, iCaptureKeyKeyUpAndDownsSecond, iCaptureKeyLongSecond);
	CancelCaptureKey(iCaptureKeyThird,iCaptureKeyKeyUpAndDownsThird, iCaptureKeyLongThird);
	
	CancelCaptureKey(iCaptureKeyMemory, iCaptureKeyKeyUpAndDownsMemory, iCaptureKeyLongMemory);
	CancelCaptureKey(iCaptureKeyRestart, iCaptureKeyKeyUpAndDownsRestart, iCaptureKeyLongRestart);
	CancelCaptureKey(iCaptureKeyShutdown, iCaptureKeyKeyUpAndDownsShutdown, iCaptureKeyLongShutdown);
	CancelCaptureKey(iCaptureKeyKeyLock, iCaptureKeyKeyUpAndDownsKeyLock, iCaptureKeyLongKeyLock);
	
	CancelCaptureKey(iCaptureKeyBTState, iCaptureKeyKeyUpAndDownsBTState, iCaptureKeyLongBTState);
	CancelCaptureKey(iCaptureKeyBTMode, iCaptureKeyKeyUpAndDownsBTMode, iCaptureKeyLongBTMode);

	CancelCaptureKey(iCaptureKeySwitchApplications, iCaptureKeyKeyUpAndDownsSwitchApplications, iCaptureKeyLongSwitchApplications);
	CancelCaptureKey(iCaptureKeyMinimize, iCaptureKeyKeyUpAndDownsMinimize, iCaptureKeyLongMinimize);
	CancelCaptureKey(iCaptureKeyClose, iCaptureKeyKeyUpAndDownsClose, iCaptureKeyLongClose);
	CancelCaptureKey(iCaptureKeyKill, iCaptureKeyKeyUpAndDownsKill, iCaptureKeyLongKill);

	CancelCaptureKey(iCaptureKeyApp0, iCaptureKeyKeyUpAndDownsApp0, iCaptureKeyLongApp0);
	CancelCaptureKey(iCaptureKeyApp1, iCaptureKeyKeyUpAndDownsApp1, iCaptureKeyLongApp1);
	CancelCaptureKey(iCaptureKeyApp2, iCaptureKeyKeyUpAndDownsApp2, iCaptureKeyLongApp2);
	CancelCaptureKey(iCaptureKeyApp3, iCaptureKeyKeyUpAndDownsApp3, iCaptureKeyLongApp3);
	CancelCaptureKey(iCaptureKeyApp4, iCaptureKeyKeyUpAndDownsApp4, iCaptureKeyLongApp4);
	CancelCaptureKey(iCaptureKeyApp5, iCaptureKeyKeyUpAndDownsApp5, iCaptureKeyLongApp5);
	CancelCaptureKey(iCaptureKeyApp6, iCaptureKeyKeyUpAndDownsApp6, iCaptureKeyLongApp6);
	CancelCaptureKey(iCaptureKeyApp7, iCaptureKeyKeyUpAndDownsApp7, iCaptureKeyLongApp7);
	CancelCaptureKey(iCaptureKeyApp8, iCaptureKeyKeyUpAndDownsApp8, iCaptureKeyLongApp8);
	CancelCaptureKey(iCaptureKeyApp9, iCaptureKeyKeyUpAndDownsApp9, iCaptureKeyLongApp9);

	if(log.LogValid())
		CancelCaptureKey(iCaptureKeyTest, iCaptureKeyKeyUpAndDownsTest, iCaptureKeyLongTest);
}

void CKeyManAppUi::CaptureKey(TInt iPriority, TInt iKey, TInt iCaptureKey, TInt iCaptureKeyUpAndDowns, TInt iCaptureLongKey)
{
	if (iKey >= 0) {
		iCaptureKey = CEikonEnv::Static()->RootWin().CaptureKey(keyCode(iKey), mask(iKey),mask(iKey), iPriority);
		iCaptureKeyUpAndDowns = CEikonEnv::Static()->RootWin().CaptureKeyUpAndDowns(scanCode(iKey), mask(iKey),mask(iKey), iPriority);
		if(repeat(iKey))
			iCaptureLongKey = CEikonEnv::Static()->RootWin().CaptureLongKey(keyCode(iKey), keyCode(iKey), 0, 0, iPriority, ELongCaptureWaitShort);
	}
}

void CKeyManAppUi::CancelCaptureKey(TInt iCaptureKey, TInt iCaptureKeyUpAndDowns, TInt iCaptureLongKey)
{
	if(iCaptureKey)
		CEikonEnv::Static()->RootWin().CancelCaptureKey(iCaptureKey);
	if(iCaptureKeyUpAndDowns)
		CEikonEnv::Static()->RootWin().CancelCaptureKeyUpAndDowns(iCaptureKeyUpAndDowns);
	if(iCaptureLongKey)
		CEikonEnv::Static()->RootWin().CancelCaptureLongKey(iCaptureLongKey);
	iCaptureKey = iCaptureKeyUpAndDowns = iCaptureLongKey = 0;
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
		PermanentNoteTimeoutL(this);
	CAknAppUi::HandleWsEventL(aEvent,aDestination);
}

void CKeyManAppUi::Test() 
{
	if(iLog)
		log.Write(_L("CKeyManAppUi::Test"));

	User::LeaveIfError(keyLock.Connect());
	CleanupClosePushL(keyLock);
	if(!keyLock.IsKeyLockEnabled())	{
		// Test only
		if(iPermanentTimer->IsActive())
			PermanentNoteTimeoutL(this);

		if (iNoteTimeout && iNoteType!=ENoteDont) {
			HBufC* string = CCoeEnv::Static()->AllocReadResourceLC(R_TEXT_TEST);

			CAknGlobalNote* globalNote = CAknGlobalNote::NewL();
			CleanupStack::PushL(globalNote);
			globalNote->SetTone(0);
			globalNote->SetPriority(CActive::EPriorityHigh);

			iPermanentNoteId = globalNote->ShowNoteL(EAknGlobalInformationNote, *string);
			CleanupStack::PopAndDestroy(string);
			CleanupStack::PopAndDestroy();
			
			TCallBack callback(PermanentNoteTimeoutL, this);
			iPermanentTimer->Cancel();
			iPermanentTimer->Start(
				(TTimeIntervalMicroSeconds32) (iNoteTimeout*1000),
				(TTimeIntervalMicroSeconds32) (100*1000), 
				callback);

			RWsSession& wsSession = iCoeEnv->WsSession();
			TKeyEvent keyEvent;
			keyEvent.iCode = EKeyDevice6;
			keyEvent.iScanCode = EStdKeyDevice6;
			keyEvent.iModifiers = 0;
			keyEvent.iRepeats = 0;
			wsSession.SimulateKeyEvent(keyEvent);
			wsSession.Flush();
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

/*
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
	if(iLog)
		log.Write(_L("CKeyManAppUi::ValidateRegCode"));

	// Registration validation
	TBuf<15> iRegCode;
	sd.Connect(0);
	sd.Assign( KUidKeyMan );
	sd.GetString( _L("reg_code"), iRegCode );
	sd.Close();
	
	TBuf<15> aImei;
	GetIMEI(aImei);
	if(iLog)
		log.WriteFormat(_L("IMEI: %d"), aImei);

	if(iRegCode.Compare(aImei))
		return EFalse;
	
	return ETrue;
}
*/
