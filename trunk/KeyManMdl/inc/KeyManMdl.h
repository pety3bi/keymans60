#if !defined(__KEYMANMDL_H__)
#define __KEYMANMDL_H__

#include <apgcli.h>
#include <saclient.h>
#include <apgtask.h>
#include <w32std.h>
#include <apacmdln.h>

class CKeyManAutostart : public CApaDataRecognizerType
{
public:
	CKeyManAutostart();
	TUint PreferredBufSize();
	TDataType SupportedDataTypeL(TInt aIndex) const;
	static void StartThread();
	static TInt StartAppThreadFunction(TAny* aParam);
	static void StartAppThreadFunctionL();
private:
	void DoRecognizeL(const TDesC& aName, const TDesC8& aBuffer);
};

#endif