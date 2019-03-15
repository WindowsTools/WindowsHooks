#pragma once

#include <windows.h>

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

