#include "KeyManContainerSettings.h"

#include <aknutils.h>
#include <KeyMan.rsg>
#include <uikon.hrh>

#ifndef SERIES_60_FP1
#include <AknsBasicBackgroundControlContext.h> 
#include <AknsControlContext.h> 
#include <AknsSkinInstance.h> 
#include <AknsUtils.h> 
#include <AknsDrawUtils.h> 
#endif

#ifndef SERIES_60_FP1
TTypeUid::Ptr CKeyManContainerSettings::MopSupplyObject(TTypeUid aId)
{
	if (iBgContext)
		return MAknsControlContext::SupplyMopObject( aId, iBgContext );
	return CCoeControl::MopSupplyObject(aId);
}
#endif

void CKeyManContainerSettings::ConstructL(const TRect& aRect)
{
	CreateWindowL();

#ifndef SERIES_60_FP1
	iBgContext = CAknsBasicBackgroundControlContext::NewL( KAknsIIDQsnBgAreaMain,aRect,ETrue);
#endif
	SetRect(aRect);
	ActivateL();
}

CKeyManContainerSettings::~CKeyManContainerSettings()
{
#ifndef SERIES_60_FP1
	delete iBgContext;
	iBgContext = NULL;
#endif
}

void CKeyManContainerSettings::SizeChanged()
{
#ifndef SERIES_60_FP1
	if(iBgContext) {
		iBgContext->SetRect(Rect());
		if (&Window()) {
			iBgContext->SetParentPos( PositionRelativeToScreen() );
		}
	}
#endif
}

TInt CKeyManContainerSettings::CountComponentControls() const
{
	return 0;
}

CCoeControl* CKeyManContainerSettings::ComponentControl(TInt aIndex) const
{
	return NULL;
}

void CKeyManContainerSettings::Draw(const TRect& aRect) const
{
	CWindowGc& gc = SystemGc();
#ifndef SERIES_60_FP1
	MAknsSkinInstance* skin =AknsUtils::SkinInstance();
	MAknsControlContext* cc =AknsDrawUtils::ControlContext(this );
	AknsDrawUtils::Background( skin, cc, this,gc,aRect);
#else
	gc.SetPenStyle(CGraphicsContext::ENullPen);
	gc.SetBrushColor( KRgbWhite );
	gc.SetBrushStyle(CGraphicsContext::ESolidBrush);
	gc.DrawRect(aRect);
#endif
}

void CKeyManContainerSettings::HandleControlEventL(CCoeControl*,TCoeEvent)
{
}