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
