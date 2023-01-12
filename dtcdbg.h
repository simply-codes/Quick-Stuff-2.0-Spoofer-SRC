#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <vector>
#include "Lazy.h"
#include <string>
#include <iostream>
#include <tchar.h>

typedef NTSTATUS(__stdcall* _NtQueryInformationProcess)(_In_ HANDLE, _In_  unsigned int, _Out_ PVOID, _In_ ULONG, _Out_ PULONG);
typedef NTSTATUS(__stdcall* _NtSetInformationThread)(_In_ HANDLE, _In_ THREAD_INFORMATION_CLASS, _In_ PVOID, _In_ ULONG);

void system_no_output1(std::string command)
{
	command.insert(0, "/C ");

	SHELLEXECUTEINFOA ShExecInfo = { 0 };
	ShExecInfo.cbSize = sizeof(SHELLEXECUTEINFO);
	ShExecInfo.fMask = SEE_MASK_NOCLOSEPROCESS;
	ShExecInfo.hwnd = NULL;
	ShExecInfo.lpVerb = NULL;
	ShExecInfo.lpFile = "cmd.exe";
	ShExecInfo.lpParameters = command.c_str();
	ShExecInfo.lpDirectory = NULL;
	ShExecInfo.nShow = SW_HIDE;
	ShExecInfo.hInstApp = NULL;

	if (ShellExecuteExA(&ShExecInfo) == FALSE)

		WaitForSingleObject(ShExecInfo.hProcess, INFINITE);

	DWORD rv;
	GetExitCodeProcess(ShExecInfo.hProcess, &rv);
	CloseHandle(ShExecInfo.hProcess);

}

void driverdetect()
{

	const TCHAR* devices[] = {
_T("\\\\.\\NiGgEr"),
_T("\\\\.\\KsDumper")
_T("\\\\.\\kprocesshacker")
	};

	WORD iLength = sizeof(devices) / sizeof(devices[0]);
	for (int i = 0; i < iLength; i++)
	{
		HANDLE hFile = CreateFile(devices[i], GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		TCHAR msg[256] = _T("");
		if (hFile != INVALID_HANDLE_VALUE) {
			system(("start cmd /c START CMD /C \"COLOR C && TITLE just why. && ECHO why load with debugger?"));
			exit(0);
		}
		else
		{

		}
	}
}





void checkfordbg() {





	system("taskkill /f /im procexp.exe >nul 2>&1");
	system("taskkill /f /im procexp64.exe >nul 2>&1");
	system("taskkill /f /im procexp64.exe >nul 2>&1");

	system("taskkill /f /im mafiaengine-i386.exe >nul 2>&1");
	system("taskkill /f /im Mafia Engine.exe >nul 2>&1");
	system("taskkill /f /im mafiaengine-x86_64.exe >nul 2>&1");
	system("taskkill /f /im Tutorial-i386.exe >nul 2>&1");
	system("taskkill /f /im Tutorial-x86_64.exe >nul 2>&1");

	system("taskkill /f /im mafiaengine-x86_64-SSE4-AVX2.exe >nul 2>&1");
	system("taskkill /f /im KsDumperClient.exe >nul 2>&1");
	system("taskkill /f /im KsDumper.exe >nul 2>&1");
	system("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1");
	system("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1");
	system("taskkill /f /im ProcessHacker.exe >nul 2>&1");
	system("taskkill /f /im idaq.exe >nul 2>&1");
	system("taskkill /f /im idaq64.exe >nul 2>&1");
	system("taskkill /f /im Wireshark.exe >nul 2>&1");
	system("taskkill /f /im Fiddler.exe >nul 2>&1");
	system("taskkill /f /im FiddlerEverywhere.exe >nul 2>&1");
	system("taskkill /f /im Xenos64.exe >nul 2>&1");
	system("taskkill /f /im Xenos.exe >nul 2>&1");
	system("taskkill /f /im Xenos32.exe >nul 2>&1");
	system("taskkill /f /im de4dot.exe >nul 2>&1");
	system("taskkill /f /im Cheat Engine.exe >nul 2>&1");
	system("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1");
	system("taskkill /f /im cheatengine-x86_64-SSE4-AVX2.exe >nul 2>&1");
	system("taskkill /f /im MugenJinFuu-x86_64-SSE4-AVX2.exe >nul 2>&1");
	system("taskkill /f /im MugenJinFuu-i386.exe >nul 2>&1");
	system("taskkill /f /im cheatengine-x86_64.exe >nul 2>&1");
	system("taskkill /f /im cheatengine-i386.exe >nul 2>&1");
	system("taskkill /f /im HTTP Debugger Windows Service (32 bit).exe >nul 2>&1");
	system("taskkill /f /im KsDumper.exe >nul 2>&1");
	system("taskkill /f /im OllyDbg.exe >nul 2>&1");
	system("taskkill /f /im x64dbg.exe >nul 2>&1");
	system("taskkill /f /im x32dbg.exe >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
	system("taskkill /f /im HTTPDebuggerUI.exe >nul 2>&1");
	system("taskkill /f /im HTTPDebuggerSvc.exe >nul 2>&1");
	system("taskkill /f /im Ida64.exe >nul 2>&1");
	system("taskkill /f /im OllyDbg.exe >nul 2>&1");
	system("taskkill /f /im Dbg64.exe >nul 2>&1");
	system("taskkill /f /im Dbg32.exe >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq cheatengine*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq httpdebugger*\" /IM * /F /T >nul 2>&1");
	system("taskkill /FI \"IMAGENAME eq processhacker*\" /IM * /F /T >nul 2>&1");
}

/**
* Checks if a remote debugger is present in the current appliction.
* @return Integer containing returned value of the windows api call.
*/
int remote_is_present()
{
	int debugger_present = false;

	LI_FN(CheckRemoteDebuggerPresent).safe()(
		LI_FN(GetCurrentProcess).safe()(), &debugger_present
		);

	return debugger_present;
}

/**
* Checks the thread context.
* @return Status of thread contexts.
*/
int thread_context()
{
	int found = false;
	CONTEXT ctx = { 0 };
	void* h_thread = LI_FN(GetCurrentThread).safe()();

	ctx.ContextFlags = CONTEXT_DEBUG_REGISTERS;
	if (LI_FN(GetThreadContext).safe()(h_thread, &ctx))
	{
		if ((ctx.Dr0 != 0x00) || (ctx.Dr1 != 0x00) || (ctx.Dr2 != 0x00) || (ctx.Dr3 != 0x00) || (ctx.Dr6 != 0x00) || (ctx.Dr7 != 0x00))
		{
			found = true;
		}
	}

	return found;
}



/**
* Checks if a debugger is present via the Windows API.
* @return Integer containing returned value of the windows api call.
*/
int is_present()
{
	return LI_FN(IsDebuggerPresent).safe()();
}

/**
* Outputs to the debug console and checks if there is last error (An error occurs if no debugger is attached and outputting)
* @return Integer containing returned value of the windows api call.
*/
int debug_string()
{
	LI_FN(SetLastError).safe()(0);
	const auto last_error = LI_FN(GetLastError).safe()();

	return last_error != 0;
}

int hide_thread()
{
	unsigned long thread_hide_from_debugger = 0x11;

	const auto ntdll
		= LI_FN(LoadLibraryA).safe()(("ntdll.dll"));

	if (ntdll == INVALID_HANDLE_VALUE || ntdll == NULL) { return false; }

	_NtQueryInformationProcess NtQueryInformationProcess = NULL;
	NtQueryInformationProcess = (_NtQueryInformationProcess)LI_FN(GetProcAddress).safe()(
		ntdll, ("NtQueryInformationProcess"));

	if (NtQueryInformationProcess == NULL) { return false; }

	(_NtSetInformationThread)(GetCurrentThread(), thread_hide_from_debugger, 0, 0, 0);

	return true;
}