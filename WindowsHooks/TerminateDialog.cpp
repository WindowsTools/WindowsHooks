// TerminateDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "WindowsHooks.h"
#include "TerminateDialog.h"
#include "afxdialogex.h"


// TerminateDialog 对话框

IMPLEMENT_DYNAMIC(TerminateDialog, CDialogEx)

TerminateDialog::TerminateDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_Terminate, pParent)
	, m_strProcessName(_T(""))
{

}

TerminateDialog::~TerminateDialog()
{
}

void TerminateDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_strProcessName);
}


BEGIN_MESSAGE_MAP(TerminateDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TerminateDialog::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TerminateDialog::OnBnClickedButton2)
END_MESSAGE_MAP()


// TerminateDialog 消息处理程序


void TerminateDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	CDialogEx::OnOK();
}


void TerminateDialog::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
