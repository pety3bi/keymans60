enum TSWStartupReason
{
	// Normal startup reasons (100..149)

	// Nothing set the (default value).
	ESWNone = 100,

	// Restore Factory Settings (Normal)
	ESWRestoreFactorySet = 101,

	// Language Switched
	ESWLangSwitch = 102,

	// Warranty transfer
	ESWWarrantyTransfer = 103,

	// Possibly needed for handling
	// power off & charger connected use case.
	ESWChargerConnected = 104,

	// Restore Factory Settings (Deep)
	ESWRestoreFactorySetDeep = 105
};

class SysStartup
{
	public:
		IMPORT_C static TInt ShutdownAndRestart( const class TUid& aSource, TSWStartupReason aReason);
		IMPORT_C static TInt Shutdown( const class TUid& aSource );
};