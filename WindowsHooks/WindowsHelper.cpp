#include "stdafx.h"
#include "WindowsHelper.h"


ACCENTPOLICY policy_Blur = { 3, 0, 0, 0 }; // ACCENT_ENABLE_BLURBEHIND=3, ACCENT_INVALID=4...
WINCOMPATTRDATA data_Blur = { 19, &policy_Blur, sizeof(ACCENTPOLICY) }; // WCA_ACCENT_POLICY=19

HHOOK mHook = nullptr;

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
	HWND hDesktop = FindWindow(_T("Progman"), _T("Program Manager"));
	HWND hDestopW = GetDesktopWindow();
	HWND hWorkerW = NULL;
	HWND hShellView = NULL;
	HWND hSysListView = NULL;
	HWND hTaskbar = FindWindowA("Shell_TrayWnd", NULL);	

	int nStatus = 0;
	
	if (bValue)
	{
		nStatus = SW_HIDE;
	}
	else
	{
		nStatus = SW_SHOW;
	}



	if (hDesktop != NULL)
	{
		//有些暂时不用
		//开始菜单暂未屏蔽
		hShellView = FindWindowEx(hDesktop, NULL, L"SHELLDLL_DefView", NULL);
		hSysListView = FindWindowEx(hShellView, NULL, L"SysListView32", L"FolderView");
		if (hSysListView != NULL && hTaskbar != NULL)
		{
			//ShowWindow(hDesktop, nStatus);
			ShowWindow(hTaskbar, nStatus);
			ShowWindow(hShellView, nStatus);
			//ShowWindow(hSysListView, nStatus);
			return TRUE;
		}				
	}
	else
	{
		do
		{
			hWorkerW = FindWindowEx(hDestopW, hWorkerW, _T("WorkerW"), NULL);
			hShellView = FindWindowEx(hWorkerW, NULL, L"SHELLDLL_DefView", NULL);
		} while (hShellView == NULL && hWorkerW != NULL);

		if (hShellView != NULL && hTaskbar != NULL)
		{
			
			ShowWindow(hTaskbar, nStatus);
			ShowWindow(hShellView, nStatus);
			return TRUE;
		}
	}	

	return FALSE;
}

BOOL HideStartMenu()
{	
	return SetStartMenu(TRUE);
}

BOOL ShowStartMenu()
{
	return SetStartMenu(FALSE);
}

BOOL SetStartMenu(BOOL bValue)
{
	HWND hTaskBar = FindWindow(_T("Shell_TrayWnd"), NULL);
	HWND hStartMenu = FindWindowEx(hTaskBar, NULL, _T("Start"), NULL);
	int nStatus = bValue == TRUE ? SW_HIDE : SW_SHOW;
	if (hStartMenu != NULL)
	{
		ShowWindow(hStartMenu, nStatus);
		//屏蔽开始菜单按键
		if (nStatus == SW_HIDE)
		{
			//https://docs.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-setwindowshookexa
			//get all id
			mHook =  SetWindowsHookEx(WH_KEYBOARD_LL, MyHookProc, NULL, 0);
		}
		else
		{
			if (mHook)
			{
				UnhookWindowsHookEx(mHook);
			}
		}
		return TRUE;
	}
	return FALSE;
}

LRESULT WINAPI MyHookProc(int code, WPARAM wParam, LPARAM lParam)
{
	LPKBDLLHOOKSTRUCT hookStruct = (LPKBDLLHOOKSTRUCT)lParam;
	if (code == HC_ACTION)
	{
		switch (wParam)
		{
		case WM_KEYDOWN:
		case WM_SYSKEYDOWN:
		case WM_KEYUP:
		case WM_SYSKEYUP:
			if (hookStruct->vkCode == VK_LWIN || hookStruct->vkCode == VK_RWIN || 
				  (hookStruct->vkCode == VK_ESCAPE) && ((GetKeyState(VK_CONTROL) & 0x8000) != 0))
			{
				return 1;
			}
			break;
		default:
			break;
		}
	}
	return LRESULT();
}

BOOL ExecuteProgram(LPCSTR strProgramName, UINT nCmdShow)
{
	UINT nRect = WinExec(strProgramName, nCmdShow);

	if (nRect > 31)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}

BOOL ExecuteCMDWithParamter(LPCWSTR param)
{
	ShellExecute(NULL, NULL, L"C:\\WINDOWS\\System32\\cmd.exe", L"", param, SW_SHOW);
	return 0;
}

DWORD GetActiveConsoleSessionID()
{
	return WTSGetActiveConsoleSessionId();
}

BOOL QueryUserToken(ULONG SessionID,PHANDLE phToken)
{
	return WTSQueryUserToken(SessionID, phToken);
}

BOOL TerminateProgram(LPTSTR strProgramName)
{
	HWND hwnd = FindWindow(strProgramName, NULL);

	if (hwnd == NULL)
		return FALSE;

	DWORD dwPid = 0;
	GetWindowThreadProcessId(hwnd, &dwPid);

	if (dwPid == 0)
		return FALSE;

	HANDLE hProgramHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPid);

	if (hProgramHandle == NULL)
		return FALSE;

	BOOL bRet = TerminateProcess(hProgramHandle, 0);
	return bRet;
}
