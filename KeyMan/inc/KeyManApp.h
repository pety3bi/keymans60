#ifndef KEYMANAPP_H
#define KEYMANAPP_H

#include <aknapp.h>

const TUid KUidKeyMan = { 0x20008D94 };

class CKeyManApp : public CAknApplication
{
	public:
	private:
		CApaDocument* CreateDocumentL();
		TUid AppDllUid() const;
};

#endif