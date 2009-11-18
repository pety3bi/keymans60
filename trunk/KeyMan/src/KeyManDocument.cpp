#include "KeyManDocument.h"
#include "KeyManAppUi.h"
#include <apgwgnam.h>

CKeyManDocument::CKeyManDocument(CEikApplication& aApp): CAknDocument(aApp)    
{
}

CKeyManDocument::~CKeyManDocument()
{
}

void CKeyManDocument::ConstructL()
{
}

CKeyManDocument* CKeyManDocument::NewL(CEikApplication& aApp)
{
	CKeyManDocument* self = new (ELeave) CKeyManDocument( aApp );
	CleanupStack::PushL( self );
	self->ConstructL();
	CleanupStack::Pop();
	return self;
}
    
CEikAppUi* CKeyManDocument::CreateAppUiL()
{
	return new (ELeave) CKeyManAppUi;
}

void CKeyManDocument::UpdateTaskNameL( CApaWindowGroupName* aWgName )
{
	CAknDocument::UpdateTaskNameL( aWgName );
	aWgName->SetRespondsToShutdownEvent( ETrue );
	aWgName->SetHidden(ETrue);
	aWgName->SetSystem(ETrue);
}

