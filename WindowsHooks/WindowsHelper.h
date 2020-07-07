#pragma once

#include <windows.h>
#include<wtsapi32.h>

#pragma comment(lib,"Wtsapi32.lib")

struct WINCOMPATTRDATA
{
	int nAttribute;
	PVOID pData;
	ULONG ulDataSize;
};

struct ACCENTPOLICY
{
	int nAccentState;
	int nFlags;
	int nColor;
	int nAnimationId;
};



typedef BOOL(WINAPI*SetWindowCompositionAttribute)(HWND hWnd, WINCOMPATTRDATA* wData);

//Source https://github.com/TranslucentTB/TranslucentTB
BOOL SetWindowTransparent(HWND hWnd);
BOOL Window10TaskbarTransparent();
BOOL RestoreWindow10TaskbarTransparent();

BOOL HideDesktop();
BOOL ShowDesktop();
BOOL SetDesktopStatus(BOOL bValue);
BOOL HideStartMenu();
BOOL ShowStartMenu();
BOOL SetStartMenu(BOOL bValue);
LRESULT WINAPI MyHookProc(int code, WPARAM wParam, LPARAM lParam);

BOOL ExecuteProgram(LPCSTR strProgramName, UINT nCmdShow);
BOOL ExecuteCMDWithParamter(LPCWSTR param);

DWORD GetActiveConsoleSessionID();
BOOL QueryUserToken(ULONG SessionID, PHANDLE phToken);

BOOL TerminateProgram(LPTSTR strProgramName);