#include "KeyManMdl.h"
#include "shared.h"

const TUid KUidAutostart = { 0x09A770B5 };
const TUid KUidApplication = { 0x20008d94 };

CKeyManAutostart::CKeyManAutostart()
:CApaDataRecognizerType(KUidAutostart, CApaDataRecognizerType::ENormal)
{
	iCountDataTypes = 1;
}

TUint CKeyManAutostart::PreferredBufSize()
{
	// no buffer recognition yet
	return 0;
}

TDataType CKeyManAutostart::SupportedDataTypeL(TInt /*aIndex*/) const
{
	return TDataType();
}

void CKeyManAutostart::DoRecognizeL(const TDesC& /*aName*/, const TDesC8& /*aBuffer*/)
{
	// this function is never called
}

void CKeyManAutostart::StartThread()
{
	TInt res = KErrNone;
	
//create a new thread for starting our application
	RThread * startAppThread;
	startAppThread = new RThread();
	
	User::LeaveIfError( res = startAppThread->Create(
		_L("Autostart starter"),
		CKeyManAutostart::StartAppThreadFunction,
		KDefaultStackSize,
		KMinHeapSize,
		KMinHeapSize,
		NULL,
		EOwnerThread) );
	
	startAppThread->SetPriority(EPriorityNormal/*EPriorityLess*/);
	startAppThread->Resume();
	startAppThread->Close();
}


TInt CKeyManAutostart::StartAppThreadFunction(TAny* /*aParam*/)
{
// wait 5 seconds...
	RTimer timer; // The asynchronous timer and ...
	TRequestStatus timerStatus; // ... its associated request status
	timer.CreateLocal(); // Always created for this thread.
// get current time (microseconds since 0AD nominal Gregorian)
	TTime time;
	time.HomeTime();
// add ten seconds to the time
	TTimeIntervalSeconds timeIntervalSeconds(45);
	time += timeIntervalSeconds;
// issue and wait
	timer.At(timerStatus,time);
	User::WaitForRequest(timerStatus);
	
// create a TRAP cleanup
	CTrapCleanup * cleanup = CTrapCleanup::New();
	TInt err;
	if( cleanup == NULL )
	{
		err = KErrNoMemory;
	}
	else
	{
		TRAP( err, StartAppThreadFunctionL() );
	}
	delete cleanup;
	
	if (err!=KErrNone) 
		User::Panic(_L("autostart"), err);
	return err;
}

void CKeyManAutostart::StartAppThreadFunctionL()
{
	RTimer timer;
	TBool iAutoStart=1;
	TRequestStatus timerStatus; 
	timer.CreateLocal();

// Ждем пока загрузится сервер приложений и сервер общих данных
	timer.After(timerStatus,5000000);
	User::WaitForRequest(timerStatus); 

	RSharedDataClient sd;
	if (sd.Connect(0)==KErrNone)
	{
		sd.Assign( TUid::Uid( 0x20008D94 ) );
		sd.GetInt( _L("autostart"), iAutoStart );
		sd.Close();
	}

	if (!iAutoStart)
	{
		timer.Close();
		return;
	}

	RWsSession wSession;
	TInt err=wSession.Connect();
	if (err != KErrNone) 
	{
		timer.Close();
		return;
	}

#ifndef __WINS__
// Ждем запуска phone.app
	while (1)
	{
		TApaTaskList theTaskList(wSession);
		TApaTask theTask = theTaskList.FindApp(TUid::Uid(0x100058B3));
		if (theTask.Exists()) 
			break;
			
		timer.After(timerStatus,10000000);
		User::WaitForRequest(timerStatus); 
	}

// Ждем валидации симки
	RSystemAgent sa;
	if (sa.Connect()!=KErrNone)
	{
		timer.Close();
		return;
	}
	while (1)
	{
		if (sa.GetState(KUidSIMStatus)==ESASimOk) 
			break;
			
		timer.After(timerStatus,10000000);
		User::WaitForRequest(timerStatus); 
	}
	sa.Close();
#endif

	timer.Close();

// Проверяем, не запустил ли нас уже кто-нибудь
	TApaTaskList theTaskList(wSession);
	TApaTask theTask = theTaskList.FindApp(KUidApplication);
	if (!theTask.Exists()) 
	{
		RApaLsSession ses;
		if (ses.Connect()!=KErrNone)
		{
			wSession.Close();
			return;
		}
		TApaAppInfo aInfo;
		if (ses.GetAppInfo(aInfo,KUidApplication)==KErrNone)
		{
			TInt len=aInfo.iFullName.Length();
			HBufC* name = HBufC::New(len); 
			name->Des().Copy(aInfo.iFullName);
			CApaCommandLine* cmdLine = CApaCommandLine::New(name);
			cmdLine->SetCommandL(EApaCommandBackground);
			ses.StartApp(*cmdLine);
		}
		ses.Close();
	}
	wSession.Close();
}

EXPORT_C CApaDataRecognizerType* CreateRecognizer()
{
	CApaDataRecognizerType* thing = new CKeyManAutostart();
//start thread for our application
	CKeyManAutostart::StartThread();
	return thing;
}

// DLL entry point
GLDEF_C TInt E32Dll(TDllReason /*aReason*/)
{
	return KErrNone;
}
