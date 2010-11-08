#ifndef KEYMANDOCUMENT_H
#define KEYMANDOCUMENT_H

#include <akndoc.h>
   
class  CEikAppUi;

class CKeyManDocument : public CAknDocument
{
	public:
		static CKeyManDocument* NewL(CEikApplication& aApp);
		virtual ~CKeyManDocument();

	public:
		void UpdateTaskNameL( CApaWindowGroupName* aWgName );

	private:
		CKeyManDocument(CEikApplication& aApp);
		void ConstructL();
		CEikAppUi* CreateAppUiL();
};

#endif