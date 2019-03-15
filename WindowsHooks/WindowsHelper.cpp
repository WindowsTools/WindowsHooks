#include "stdafx.h"
#include "WindowsHelper.h"


ACCENTPOLICY policy_Blur = { 3, 0, 0, 0 }; // ACCENT_ENABLE_BLURBEHIND=3, ACCENT_INVALID=4...
WINCOMPATTRDATA data_Blur = { 19, &policy_Blur, sizeof(ACCENTPOLICY) }; // WCA_ACCENT_POLICY=19



HWND taskbar = FindWindowA("Shell_TrayWnd", NULL);
HWND secondtaskbar = FindWindowA("Shell_SecondaryTrayWnd", NULL);

BOOL SetWindowTransparent(HWND hWnd,WINCOMPATTRDATA data)
{	
	HMODULE hModule = LoadLibraryA("user32.dll");
	if (hModule != nullptr)
	{
		SetWindowCompositionAttribute m_fSetWindowCompositionAttribute = (SetWindowCompositionAttribute)GetProcAddress(hModule, "SetWindowCompositionAttribute");
		if (m_fSetWindowCompositionAttribute != nullptr)
		{
			return m_fSetWindowCompositionAttribute(hWnd, &data);
		}
	}
	return FALSE;
}

BOOL Window10TaskbarTransparent()
{
	return SetWindowTransparent(taskbar, data_Blur);
}

BOOL RestoreWindow10TaskbarTransparent()
{
	return FALSE;
}

BOOL ShowDesktop()
{
	return SetDesktopStatus(FALSE);
}

BOOL HideDesktop()
{
	return SetDesktopStatus(TRUE);
}

BOOL SetDesktopStatus(BOOL bValue)
{
	HWND hDestop = GetDesktopWindow();
	HWND hWorkerW = NULL;
	HWND hShellView = NULL;
	HWND hTaskbar = FindWindowA("Shell_TrayWnd", NULL);	

	do
	{
		hWorkerW = FindWindowEx(hDestop, hWorkerW, _T("WorkerW"), NULL);
		hShellView = FindWindowEx(hWorkerW, NULL, L"SHELLDLL_DefView", NULL);
	} while (hShellView == NULL && hWorkerW != NULL);

	if (hShellView != NULL && hTaskbar != NULL)
	{
		int nStatus = 0;
		if (bValue)
		{
			nStatus = SW_HIDE;
		}
		else
		{
			nStatus = SW_SHOW;
		}			
		ShowWindow(hTaskbar, nStatus);	
		ShowWindow(hShellView, nStatus);
		return TRUE;
	}
	return FALSE;
}
