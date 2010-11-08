#ifndef KEYMANCONTAINERABOUT_H
#define KEYMANCONTAINERABOUT_H

#include <coecntrl.h>
#include <eikappui.h>
#include <coecntrl.h>
#include <akncontext.h>
#include <aknnavi.h>
#include <aknnavide.h>
#include <akntabgrp.h>
#include <akntitle.h>
#include <avkon.rsg>
#include <barsread.h>
#include <eikspane.h>
#include <eikedwin.h>
#include <aknnotedialog.h>
#include <eiklabel.h>

#ifndef SERIES_60_FP1
class CAknsBasicBackgroundControlContext;
#endif

class CEikLabel;
class CEikEdwin;

class CKeyManContainer : public CCoeControl, MCoeControlObserver
{
	public:
		void ConstructL(const TRect& aRect);
		~CKeyManContainer();

#ifndef SERIES_60_FP1
		TTypeUid::Ptr MopSupplyObject(TTypeUid aId);
#endif

		TKeyResponse OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType);

	private:
		void Draw(const TRect& aRect) const;
		void SizeChanged();
		TInt CountComponentControls() const;
		CCoeControl* ComponentControl(TInt aIndex) const;
		void HandleControlEventL(CCoeControl* aControl,TCoeEvent aEventType);
		
	private:
#ifndef SERIES_60_FP1
		CAknsBasicBackgroundControlContext* iBgContext;
#endif

	private:
		CEikLabel* iLabel;
		CEikLabel* iToDoLabel;
		CEikLabel* iCopyrightLabel;
		CEikEdwin* iEikEdwinText;
};

#endif