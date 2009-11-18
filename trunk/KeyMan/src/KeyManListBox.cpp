#include "KeyMan.hrh"
#include "KeyManListBox.h"

#include "KeyManAppUi.h"

CAknSettingItem* CKeyManListbox::CreateSettingItemL( TInt aIdentifier )
{
	CAknSettingItem* settingItem = NULL;

	switch( aIdentifier )
	{
		case EKeyManSettingAutoStart:
			settingItem = new (ELeave) 
			CAknBinaryPopupSettingItem( aIdentifier, iAutoStart );
			break;
#ifdef SERIES_60_FP3
		case EKeyManSettingMMKey:
			settingItem = new (ELeave) 
			CAknBinaryPopupSettingItem( aIdentifier, iMMKey );
			break;
#endif
		case EKeyManSettingKeysToggle:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iToggleKey );
			break;
		case EKeyManSettingKeys:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKey );
			break;
		case EKeyManSettingKeysFirst:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyFirst );
			break;
		case EKeyManSettingLanguageFirst:
			settingItem = new (ELeave) 
			CAknIntegerEdwinSettingItem ( aIdentifier, iLanguageFirst );
			break;
		case EKeyManSettingKeysSecond:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeySecond );
			break;
		case EKeyManSettingLanguageSecond:
			settingItem = new (ELeave) 
			CAknIntegerEdwinSettingItem ( aIdentifier, iLanguageSecond );
			break;
		case EKeyManSettingEnableThird:
			settingItem = new (ELeave) 
			CAknBinaryPopupSettingItem( aIdentifier, iEnableThird );
			break;
		case EKeyManSettingKeysThird:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyThird );
			break;
		case EKeyManSettingLanguageThird:
			settingItem = new (ELeave) 
			CAknIntegerEdwinSettingItem ( aIdentifier, iLanguageThird );
			break;
		case EKeyManSettingKeysMemory:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyMemory );
			break;
		case EKeyManSettingKeysRestart:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyRestart );
			break;
		case EKeyManSettingKeysBTState:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyBTState );
			break;
		case EKeyManSettingKeysBTMode:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyBTMode );
			break;
		case EKeyManSettingKeysSwitchApplications:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeySwitchApplications );
			break;
		case EKeyManSettingLockNote:
			settingItem = new (ELeave) 
			CAknBinaryPopupSettingItem( aIdentifier, iLockNote );
			break;
		case EKeyManSettingKeysKeyLock:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyKeyLock );
			break;
		case EKeyManSettingKeysMinimize:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyMinimize );
			break;
		case EKeyManSettingKeysClose:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyClose );
			break;
		case EKeyManSettingKeysApp1:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp1 );
			break;
		case EKeyManSettingKeysApp2:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyApp2 );
			break;
		case EKeyManSettingKeysTest:
			if(ui->log.LogValid())
			{
				settingItem = new (ELeave) 
				CAknEnumeratedTextPopupSettingItem( aIdentifier, iSwitchKeyTest );
			}
			break;
		case EKeyManSettingNoteType:
			settingItem = new (ELeave) 
			CAknEnumeratedTextPopupSettingItem ( aIdentifier, iNoteType );
			break;
		case EKeyManSettingNoteTimeout:
			settingItem = new (ELeave) 
			CAknIntegerEdwinSettingItem ( aIdentifier, iNoteTimeout );
			break;
#ifndef SERIES_60_FP1
		case EKeyManSettingVibration:
			settingItem = new (ELeave) 
			CAknBinaryPopupSettingItem( aIdentifier, iVibration );
			break;
		case EKeyManSettingVibrationTimeout:
			settingItem = new (ELeave) 
			CAknIntegerEdwinSettingItem ( aIdentifier, iVibrationTimeout );
			break;
		case EKeyManSettingVibrationPower:
			settingItem = new (ELeave) 
			CAknSliderSettingItem ( aIdentifier, iVibrationPower );
			break;
#endif
	}
	return settingItem;
}

void CKeyManListbox::HandleListBoxEventL( CEikListBox* aListBox, TListBoxEvent aEventType )
{
	CAknSettingItemList::HandleListBoxEventL( aListBox, aEventType );
	ui->UpdateSettings();  
}

TKeyResponse CKeyManListbox::OfferKeyEventL( const TKeyEvent& aKeyEvent, TEventCode aType ) 
{
	// Call Key Events
	ui->HandleKeyEventL( aKeyEvent, aType );
	
	// Disable ListBox Modifier Events
	if(aKeyEvent.iModifiers == 1280 || aKeyEvent.iModifiers == 1281)
		return EKeyWasConsumed;

	return CAknSettingItemList::OfferKeyEventL( aKeyEvent, aType );
}