#include "KeyManContainerAbout.h"
#include <eiklabel.h>

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
TTypeUid::Ptr CKeyManContainer::MopSupplyObject(TTypeUid aId)
{
	if(iBgContext)
		return MAknsControlContext::SupplyMopObject( aId, iBgContext );
	return CCoeControl::MopSupplyObject(aId);
}
#endif

void CKeyManContainer::ConstructL(const TRect& aRect)
{
	CreateWindowL();

#ifndef SERIES_60_FP1
	iBgContext = CAknsBasicBackgroundControlContext::NewL( KAknsIIDQsnBgAreaMain,aRect,ETrue);
#endif

	iLabel = new (ELeave) CEikLabel;
	iLabel->SetContainerWindowL( *this );
	iLabel->SetTextL( _L("KeyMan") );

	iToDoLabel = new (ELeave) CEikLabel;
	iToDoLabel->SetContainerWindowL( *this );
	iToDoLabel->SetTextL( _L("(hotkeys manager)") );
	
	iCopyrightLabel = new (ELeave) CEikLabel;
	iCopyrightLabel->SetContainerWindowL( *this );
	iCopyrightLabel->SetTextL( _L("Copyright © IRoN (2006-2008)") );

// Edwin
	iEikEdwinText = new( ELeave )CEikEdwin;
	iEikEdwinText->SetContainerWindowL( * this );
	iEikEdwinText->ConstructL();
	iEikEdwinText->SetDimmed(EFalse);
	iEikEdwinText->SetFocus(ETrue);
	{
		TMargins8 tempMargins;
		tempMargins.iLeft = 0;
		tempMargins.iRight = 0;
		tempMargins.iTop = 0;
		tempMargins.iBottom = 0;

		iEikEdwinText->SetBorderViewMargins(tempMargins);
	}

	iEikEdwinText->AddFlagToUserFlags(CEikEdwin::EZeroEnumValue | CEikEdwin::ENoAutoSelection /* | CEikEdwin::EAvkonDisableCursor */);

	iEikEdwinText->SetAknEditorFlags(EAknEditorFlagDefault);
	{
		TCharFormat format;
		Mem::FillZ(&format, sizeof(TCharFormat));
		TCharFormatMask mask;
		Mem::FillZ(&mask, sizeof(TCharFormatMask));
#ifndef SERIES_60_FP1
		format.iFontSpec.iTypeface = AknLayoutUtils::FontFromId (EAknLogicalFontSecondaryFont )->FontSpecInTwips().iTypeface;
#else
		format.iFontSpec.iTypeface = LatinPlain12()->FontSpecInTwips().iTypeface;
#endif
		mask.SetAttrib(EAttFontTypeface);
		format.iFontPresentation.iTextColor = iEikonEnv->Color(EColorLabelText);
		mask.SetAttrib(EAttColor);
		format.iFontPresentation.iStrikethrough = EStrikethroughOff;
		mask.SetAttrib(EAttFontStrikethrough);
		format.iFontPresentation.iUnderline = EUnderlineOff;
		mask.SetAttrib(EAttFontUnderline);

		CCharFormatLayer * layer = CCharFormatLayer::NewL(format, mask);
		iEikEdwinText->SetCharFormatLayer(layer);
	}

	iEikEdwinText->SetTextLimit(0);

	HBufC*  string;
	string = CCoeEnv::Static()->AllocReadResourceLC(R_TEXT_ABOUT);
	iEikEdwinText->SetTextL(string);
	CleanupStack::PopAndDestroy(string);

	iEikEdwinText->SetWordWrapL(ETrue);
	iEikEdwinText->SetBackgroundColorL(iEikonEnv->Color(EColorWindowBackground));
	iEikEdwinText->SetReadOnly(ETrue);
	iEikEdwinText->SetAllowUndo(EFalse);
	iEikEdwinText->SetOnlyASCIIChars(EFalse);

	SetRect(aRect);
	ActivateL();
}

CKeyManContainer::~CKeyManContainer()
{
	delete iLabel;
	delete iToDoLabel;
	delete iCopyrightLabel;
	delete iEikEdwinText;

#ifndef SERIES_60_FP1
	delete iBgContext;
	iBgContext = NULL;
#endif
}

void CKeyManContainer::SizeChanged()
{
#ifndef SERIES_60_FP1
	if(iBgContext) {
		iBgContext->SetRect(Rect());
		if(&Window())
			iBgContext->SetParentPos(PositionRelativeToScreen());
	}
#endif

	const CFont* font1;
	const CFont* font2;

#ifndef SERIES_60_FP1
	font1 = AknLayoutUtils::FontFromId(EAknLogicalFontPrimaryFont);
	font2 = AknLayoutUtils::FontFromId(EAknLogicalFontPrimarySmallFont);
#else
	font1 = LatinBold12();
	font2 = LatinPlain12();
#endif

	TInt iPos = 0;

// Label 1
	iLabel->SetAlignment(( TGulAlignmentValue )( EHCenter | EVCenter ));
	iLabel->SetFont(font1);
	
	TInt iHeight_PrimaryFont = font1->HeightInPixels();
	iHeight_PrimaryFont = iHeight_PrimaryFont + iHeight_PrimaryFont / 2;
	iLabel->SetExtent(TPoint(0, iPos), TSize(Rect().Width(), iHeight_PrimaryFont));

	iPos = iHeight_PrimaryFont;

// Label 2
	iToDoLabel->SetAlignment(( TGulAlignmentValue )( EHCenter | EVCenter ));
	iToDoLabel->SetFont(font2);

	TInt iHeight_PrimarySmallFont = font2->HeightInPixels();
	iHeight_PrimarySmallFont = iHeight_PrimarySmallFont + iHeight_PrimarySmallFont / 2;
	iToDoLabel->SetExtent(TPoint(0, iPos), TSize(Rect().Width(), iHeight_PrimarySmallFont));

	iPos = iPos + iHeight_PrimarySmallFont;

// Label 3
	iCopyrightLabel->SetAlignment( ( TGulAlignmentValue )( EHCenter | EVCenter ) );
	iCopyrightLabel->SetFont(font2);

	iCopyrightLabel->SetExtent( TPoint(0, iPos), TSize(Rect().Width(), 	iHeight_PrimarySmallFont) );

	iPos = iPos + iHeight_PrimarySmallFont + 15;

// Edwin
#ifndef SERIES_60_FP1
	AknLayoutUtils::SAknLayoutTextMultiline iEdwinLayout;
	{
		iEdwinLayout.iFont = EAknLogicalFontSecondaryFont;
		iEdwinLayout.iNumberOfLinesShown = 6;
		iEdwinLayout.iC = 0;/*iEikonEnv->Color( EColorLabelText ).Value()*/
		iEdwinLayout.iL = 0;
		iEdwinLayout.iR = 0;
		iEdwinLayout.iB = 0;
		iEdwinLayout.iW = Rect().Width();
		iEdwinLayout.iJ = ELayoutAlignCenter;
		iEdwinLayout.iNextLineB = 0;
	}
	AknLayoutUtils::LayoutEdwin (iEikEdwinText, Rect(), iEdwinLayout);
	TInt iEditHeight = iEikEdwinText->Size().iHeight - 20;
#else
	TInt iEditHeight = 55;
#endif

#ifndef SERIES_60_FP1
	AknLayoutUtils::LayoutEdwin (iEikEdwinText, TRect(TPoint(0, iPos), TSize(Rect().Width(), iEditHeight)), iEdwinLayout);
#else
	iEikEdwinText->SetAlignment(EAknEditorAlignCenter);
	iEikEdwinText->SetExtent(TPoint( 0, iPos ), TSize( Rect().Width(), iEditHeight ));
#endif
}

TInt CKeyManContainer::CountComponentControls() const
{
	return 4;
}

CCoeControl* CKeyManContainer::ComponentControl(TInt aIndex) const
{
	switch (aIndex)
	{
		case 0:
			return iLabel;
		case 1:
			return iToDoLabel;
		case 2:
			return iCopyrightLabel;
		case 3:
			return iEikEdwinText;
		default:
			return NULL;
	}
}

void CKeyManContainer::Draw(const TRect& aRect) const
{
	CWindowGc& gc = SystemGc();
#ifndef SERIES_60_FP1
	MAknsSkinInstance* skin =AknsUtils::SkinInstance();
	MAknsControlContext* cc =AknsDrawUtils::ControlContext(this );
	AknsDrawUtils::Background( skin, cc, this,gc,aRect);
#else
	gc.SetPenStyle(CGraphicsContext::ENullPen);
	gc.SetBrushColor(KRgbWhite);
	gc.SetBrushStyle(CGraphicsContext::ESolidBrush);
	gc.DrawRect(aRect);
#endif
}

void CKeyManContainer::HandleControlEventL(CCoeControl*,TCoeEvent)
{
}

TKeyResponse CKeyManContainer::OfferKeyEventL(const TKeyEvent& aKeyEvent, TEventCode aType)
{
	if(aKeyEvent.iModifiers != 1280 && aKeyEvent.iModifiers != 1281)
		if(aKeyEvent.iCode == EKeyUpArrow || aKeyEvent.iCode == EKeyDownArrow)
			return iEikEdwinText->OfferKeyEventL(aKeyEvent, aType);
	return EKeyWasNotConsumed;
}