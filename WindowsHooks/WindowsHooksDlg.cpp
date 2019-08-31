
// WindowsHooksDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "WindowsHooks.h"
#include "WindowsHooksDlg.h"
#include "afxdialogex.h"
#include "ExecDialog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CWindowsHooksDlg �Ի���



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


// CWindowsHooksDlg ��Ϣ�������

BOOL CWindowsHooksDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWindowsHooksDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CWindowsHooksDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWindowsHooksDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL bResult = Window10TaskbarTransparent();
	if (bResult)
		AfxMessageBox(_T("�ɹ�"));
	else
		AfxMessageBox(_T("ʧ��"));
}


void CWindowsHooksDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL bResult = RestoreWindow10TaskbarTransparent();
	if (bResult)
		AfxMessageBox(_T("�ɹ�"));
	else
		AfxMessageBox(_T("ʧ��"));
}


void CWindowsHooksDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	BOOL bResult = HideDesktop();
	if (bResult)
		AfxMessageBox(_T("�ɹ�"));
	else
		AfxMessageBox(_T("ʧ��"));
	
}


void CWindowsHooksDlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
    BOOL bResult = 	ShowDesktop();
	if (bResult)
		AfxMessageBox(_T("�ɹ�"));
	else
		AfxMessageBox(_T("ʧ��"));
}


void CWindowsHooksDlg::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	HideStartMenu();
}


void CWindowsHooksDlg::OnBnClickedButton6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ShowStartMenu();
}


void CWindowsHooksDlg::OnBnClickedButton7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	ExecDialog execDialog;
	if (execDialog.DoModal() == IDOK)
	{		
		ExecuteProgram(CT2CA(execDialog.m_strProgrameName), SW_NORMAL);
	}
}


void CWindowsHooksDlg::OnBnClickedButton8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	AfxMessageBox(L"����3����ѡ��Ҫ͸���Ĵ���");
	Sleep(3000);
	HWND hwnd = ::GetFocus();
	SetWindowLong(hwnd, GWL_EXSTYLE, GetWindowLong(hwnd, GWL_EXSTYLE) | WS_EX_LAYERED);
	//https://docs.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setlayeredwindowattributes	
	int alpha = 200;
	::SetLayeredWindowAttributes(hwnd, RGB(0, 0, 0), alpha, LWA_ALPHA);
}
