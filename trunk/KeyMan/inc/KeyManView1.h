#ifndef KEYMANVIEW1_H
#define KEYMANVIEW1_H

#include <KeyMan.hrh>
// View
#include <aknview.h>
// Menu
#include <eikmenup.h>
// Tab Group
#include <akntabgrp.h>
//#include <aknnavide.h>
//#include <akntabobserver.h>

// ListBox
#include <KeyManListBox.h>

// Container
#include  "KeyManContainerSettings.h"

// Shared data
#include "shared.h"

const TUid KView1Id = {1};

class CKeyManView1 : public CAknView
{
	public:
		void ConstructL();
		~CKeyManView1();

		TUid Id() const;
		void HandleCommandL(TInt aCommand);
		void HandleClientRectChange();

		CAknTabGroup* TabGroup();
		void TabChangedL(TInt aIndex);

	private:
		CAknNavigationControlContainer* iNaviPane;
		CAknNavigationDecorator*        iDecoratedTabGroup;
		CAknTabGroup*                   iTabGroup;

	public:
		TInt OfferKeyEventTabGroupL (const TKeyEvent& aKeyEvent, TEventCode aType );
		void UpdateSettings();

	private:
		void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,const TDesC8& aCustomMessage);
		void DoDeactivate();
		void DynInitMenuPaneL(TInt aResourceId, CEikMenuPane *aMenuPane);

		void CreateListBoxL(TInt aResourceId);

	private:
		CKeyManContainerSettings* iContainer;
		CKeyManListbox* iListBox;
		RSharedDataClient sd;
		
	public:
		CKeyManAppUi* ui;
};

#endif
