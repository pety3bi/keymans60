#ifndef KEYMANCONTAINERSETTINGS_H
#define KEYMANCONTAINERSETTINGS_H

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

#ifndef SERIES_60_FP1
class CAknsBasicBackgroundControlContext;
#endif

class CKeyManContainerSettings : public CCoeControl, MCoeControlObserver
{
	public:
		void ConstructL(const TRect& aRect);
		~CKeyManContainerSettings();

#ifndef SERIES_60_FP1
		TTypeUid::Ptr MopSupplyObject(TTypeUid aId);
#endif

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

};

#endif