#ifndef NO_BTENG_H
#define NO_BTENG_H

enum TBTDiscoverabilityMode { EBTDiscoverabilityMode0 = 2, EBTDiscoverabilityMode1 = 3 };
enum TBTSearchMode { EBTSearchMode0 , EBTSearchMode1 };

class CBTMCMSettings : public CBase {
public:
	IMPORT_C static int  GetAllSettings(int &, enum TBTDiscoverabilityMode &, enum TBTSearchMode &, class TDes16 &, int &);
	IMPORT_C static int  GetDiscoverabilityModeL(enum TBTDiscoverabilityMode &);
	IMPORT_C static int  GetLocalBDAddress(class TBTDevAddr &);
	IMPORT_C static int  GetLocalBTName(class TDes16 &);
	IMPORT_C static int  GetPowerStateL(int &);
	IMPORT_C static int  GetSearchModeL(enum TBTSearchMode &);
	IMPORT_C static int  IsLocalNameModified(int &);
	IMPORT_C static class CBTMCMSettings *  NewL(class MBTMCMSettingsCB *);
	IMPORT_C static class CBTMCMSettings *  NewLC(class MBTMCMSettingsCB *);
	IMPORT_C int  SetDefaultValuesL(void);
	IMPORT_C int  SetDiscoverabilityModeL(enum TBTDiscoverabilityMode, int);
	IMPORT_C int  SetLocalBTName(class TDesC16 const &);
	IMPORT_C int  SetPowerStateL(int, int);
	IMPORT_C int  SetSearchModeL(enum TBTSearchMode);
};

#endif