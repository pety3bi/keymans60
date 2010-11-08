// Reconstructed from commonengine.lib with dumpbin
// by Alex Yakovlev:
// alex@alexgraf.com,
// http://alexgraf.com/alex/

#ifndef _RSHARED_DATA_
#define _RSHARED_DATA_

class RSharedDataClient
{ 
	public:
		RSharedDataClient(class MSharedDataNotifyHandler *);
		RSharedDataClient(void);
		int Assign(class TUid) const;
		int AssignToTemporaryFile(class TUid) const;
		void CancelAllNotifies(void);
		void CancelNotify(class TUid,class TDesC16 const *);
		void Close(void);
		int Connect(int);
		int Flush(void) const;
		int GetInt(class TDesC16 const &,int &) const;
		int GetReal(class TDesC16 const &,double &) const;
		int GetString(class TDesC16 const &,class TDes16 &) const;
		int NotifyChange(class TUid,class TDesC16 const *);
		int NotifySet(class TUid,class TDesC16 const *);
		int RestoreOriginal(class TUid,class MDesC16Array const *);
		int SetInt(class TDesC16 const &,int);
		int SetReal(class TDesC16 const &,double);
		int SetString(class TDesC16 const &,class TDesC16 const &);
		void CancelFreeDiskSpaceRequest(void) const;
		void RequestFreeDiskSpace(int) const;
		void RequestFreeDiskSpaceLC(int) const;
		int AddToValue(class TDesC16 const &,int);
		void CancelAllSignals(void);
		void CancelSignal(class TDesC16 const &);
		int Signal(class TDesC16 const &);
	private:
		void *v1,*v2,*v3,*v4;
};

#endif // _RSHARED_DATA_
