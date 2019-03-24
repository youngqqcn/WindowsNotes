// WinJob.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define _WIN32_WINNT 0x0500     //NT5.0以上支持, 作业
#include "windows.h"



HANDLE Create(LPSTR pszPath)
{
	STARTUPINFO si = {0};
	PROCESS_INFORMATION pi = {0};
	si.cb = sizeof(si);
	CreateProcess(pszPath, 
			NULL, NULL, NULL, FALSE, 0,
			NULL, NULL, &si, &pi);

	return pi.hProcess;
}

void Job()
{
	//创建Job对象
	HANDLE hJob = CreateJobObject(NULL, "MyJob");
	
	JOBOBJECT_BASIC_UI_RESTRICTIONS ui = {0};
	ui.UIRestrictionsClass = JOB_OBJECT_UILIMIT_READCLIPBOARD|JOB_OBJECT_UILIMIT_WRITECLIPBOARD;
	
	SetInformationJobObject(hJob, JobObjectBasicUIRestrictions, &ui, sizeof(ui));

	
	HANDLE  hProc = Create("C:\\WINDOWS\\system32\\mspaint.exe");


	AssignProcessToJobObject(hJob, hProc);

	CloseHandle(hJob);

}



int main(int argc, char* argv[])
{
	Job();
	printf("Hello World!\n");
	return 0;
}

