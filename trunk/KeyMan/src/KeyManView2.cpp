#include  "KeyManView2.h"

void CKeyManView2::ConstructL()
{
	BaseConstructL(R_KEYMAN_VIEW2);
}

CKeyManView2::~CKeyManView2()
{
	if(iContainer) {
		AppUi()->RemoveFromViewStack(*this, iContainer);
	}
	delete iContainer;
}

TUid CKeyManView2::Id() const
{
	return KView2Id;
}

void CKeyManView2::HandleClientRectChange()
{
	if (iContainer)
		iContainer->SetRect(ClientRect());
}

void CKeyManView2::DoActivateL(const TVwsViewId&,TUid,const TDesC8&)
{
	if(!iContainer)	{
		iContainer = new (ELeave) CKeyManContainer;
		iContainer->SetMopParent(this);
		iContainer->ConstructL(ClientRect());
		AppUi()->AddToStackL(*this, iContainer);
	}
}

void CKeyManView2::DoDeactivate()
{
	if(iContainer)	{
		AppUi()->RemoveFromViewStack(*this, iContainer);
	}
	delete iContainer;
	iContainer = NULL;
}

void CKeyManView2::HandleCommandL(TInt aCommand)
{
	AppUi()->HandleCommandL(aCommand);
}