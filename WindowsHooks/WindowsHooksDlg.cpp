
// WindowsHooksDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "WindowsHooks.h"
#include "WindowsHooksDlg.h"
#include "afxdialogex.h"
#include "ExecDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CWindowsHooksDlg 对话框



CWindowsHooksDlg::CWindowsHooksDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WINDOWSHOOKS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_LOGO);
}

void CWindowsHooksDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWindowsHooksDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CWindowsHooksDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CWindowsHooksDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CWindowsHooksDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CWindowsHooksDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CWindowsHooksDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CWindowsHooksDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CWindowsHooksDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CWindowsHooksDlg::OnBnClickedButton8)
END_MESSAGE_MAP()


// CWindowsHooksDlg 消息处理程序

BOOL CWindowsHooksDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CWindowsHooksDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CWindowsHooksDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CWindowsHooksDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWindowsHooksDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL bResult = Window10TaskbarTransparent();
	if (bResult)
		AfxMessageBox(_T("成功"));
	else
		AfxMessageBox(_T("失败"));
}


void CWindowsHooksDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL bResult = RestoreWindow10TaskbarTransparent();
	if (bResult)
		AfxMessageBox(_T("成功"));
	else
		AfxMessageBox(_T("失败"));
}


void CWindowsHooksDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	BOOL bResult = HideDesktop();
	if (bResult)
		AfxMessageBox(_T("成功"));
	else
		AfxMessageBox(_T("失败"));
	
}


void CWindowsHooksDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
    BOOL bResult = 	ShowDesktop();
	if (bResult)
		AfxMessageBox(_T("成功"));
	else
		AfxMessageBox(_T("失败"));
}


void CWindowsHooksDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	HideStartMenu();
}


void CWindowsHooksDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	ShowStartMenu();
}


void CWindowsHooksDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	ExecDialog execDialog;
	if (execDialog.DoModal() == IDOK)
	{		
		ExecuteProgram(CT2CA(execDialog.m_strProgrameName), SW_NORMAL);
	}
}


void CWindowsHooksDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	AfxMessageBox(L"请在3秒内选择要透明的窗口");
	Sleep(3000);
	HWND hwnd = ::GetFocus();
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	//https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes	
	int alpha = 200;
	::SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), alpha, LWA_ALPHA);
}
