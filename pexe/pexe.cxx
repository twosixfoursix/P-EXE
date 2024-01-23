#include <Windows.h>
#include <stdlib.h>
#include <string>

// Comp: cl /nologo /EHsc /MD /O2 /c pexe.cxx
// Link: link /nologo /SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup pexe.obj user32.lib shell32.lib advapi32.lib kernel32.lib /OUT:pexe.exe

using namespace std; // YUGH... but this is a small program.

int main(int argn, char **arg)
{
	FILE *p;
	if(argn > 1)
	{
		p = fopen(arg[1], "r");
	}
	else
	{
		p = fopen("app.x", "r");
	}
	if(p == NULL)
	{
		MessageBoxA(NULL, "No cmd file found.", "P-EXE", MB_OK);
		return 0;
	}
	fseek(p, 0, SEEK_END);
	long n = ftell(p);
	rewind(p);
	char *cmd = (char *)malloc(n + 1);
	fread(cmd, 1, n, p);
	cmd[n] = '\0';
	fclose(p);
	string c(cmd);
	free(cmd);
	c = "Invoke-Expression " + c;
	// MessageBoxA(NULL, (LPSTR)c.c_str(), "P-EXE", MB_OK);
	STARTUPINFO uinfo;
	PROCESS_INFORMATION pinfo;
	ZeroMemory(&uinfo, sizeof(uinfo));
	uinfo.cb = sizeof(uinfo);
	ZeroMemory(&pinfo, sizeof(pinfo));
	CreateProcess("C:\\Windows\\System32\\WindowsPowerShell\\v1.0\\powershell.exe", (LPSTR)c.c_str(), NULL, NULL, FALSE, 0, NULL, NULL, &uinfo, &pinfo);
	WaitForSingleObject(pinfo.hProcess, INFINITE);
	CloseHandle(pinfo.hProcess);
	CloseHandle(pinfo.hThread);
	return 0;
}
