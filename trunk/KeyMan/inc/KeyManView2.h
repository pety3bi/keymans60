#ifndef KEYMANVIEW2_H
#define KEYMANVIEW2_H

#include <aknview.h>
#include <aknviewappui.h>

#include <avkon.hrh>
#include <KeyMan.rsg>

#include  "KeyManContainerAbout.h"

class CKeyManContainer;

const TUid KView2Id = {2};

class CKeyManView2 : public CAknView
{
	public:
		void ConstructL();
		~CKeyManView2();
		TUid Id() const;

	private:
		void DoActivateL(const TVwsViewId& aPrevViewId,TUid aCustomMessageId,const TDesC8& aCustomMessage);
		void DoDeactivate();

		void HandleCommandL(TInt aCommand);
		void HandleClientRectChange();
		
		CKeyManContainer* iContainer;
};

#endif
