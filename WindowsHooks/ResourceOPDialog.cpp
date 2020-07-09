// ResourceOPDialog.cpp: 实现文件
//

#include "stdafx.h"
#include "WindowsHooks.h"
#include "ResourceOPDialog.h"
#include "afxdialogex.h"


// ResourceOPDialog 对话框

IMPLEMENT_DYNAMIC(ResourceOPDialog, CDialogEx)

ResourceOPDialog::ResourceOPDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ResourceOP, pParent)
{

}

ResourceOPDialog::~ResourceOPDialog()
{
}

void ResourceOPDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ResourceOPDialog, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ResourceOPDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// ResourceOPDialog 消息处理程序


void ResourceOPDialog::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	//把一个"数字ID",转化为"字符串".
	HRSRC hSrc = FindResource(NULL, MAKEINTRESOURCE(IDR_WORD2), L"WORD");

	//NULL放前面的写法是为了防止写 '=='时写成了 '='
	if (hSrc == NULL)
	{
		MessageBox(L"查找资源错误");
		return;
	}

	//获取资源大小
	DWORD dwSize = SizeofResource(NULL, hSrc);

	if (dwSize <= 0)
		return;

	//将资源加载到内存里
	HGLOBAL hGlobal = LoadResource(NULL, hSrc);

	if (hGlobal == NULL)
		return;

	/*
	LockResource does not actually lock memory; it is just used to obtain a pointer to 
    the memory containing the resource data. The name of the function comes from versions prior to Windows XP, when it was
    used to lock a global memory block allocated by LoadResource.
   */
	LPVOID lpVoid = LockResource(hGlobal);

	if (lpVoid == NULL)
		return;

	FILE* fp = NULL;
	fopen_s(&fp,"D:\\HelloWorld.docx", "wb");
	fwrite(lpVoid, sizeof(char), dwSize, fp);
	fclose(fp);

	AfxMessageBox(L"文件已保存到D:\\HelloWorld.docx");
}
