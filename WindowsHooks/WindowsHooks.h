
// WindowsHooks.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CWindowsHooksApp: 
// �йش����ʵ�֣������ WindowsHooks.cpp
//

class CWindowsHooksApp : public CWinApp
{
public:
	CWindowsHooksApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CWindowsHooksApp theApp;