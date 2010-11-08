#include "KeyManApp.h"
#include "KeyManDocument.h"
#include <aknnotewrappers.h>
#include "shared.h"
#include <avkon.hrh>

TUid CKeyManApp::AppDllUid() const
{
	return KUidKeyMan;
}

CApaDocument* CKeyManApp::CreateDocumentL()
{
	return CKeyManDocument::NewL( *this );
}

EXPORT_C CApaApplication* NewApplication()
{
	return new CKeyManApp;
}

GLDEF_C TInt E32Dll( TDllReason )
{
	return KErrNone;
}