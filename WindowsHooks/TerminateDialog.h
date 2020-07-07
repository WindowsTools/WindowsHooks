#pragma once


// TerminateDialog 对话框

class TerminateDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TerminateDialog)

public:
	TerminateDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TerminateDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Terminate };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_strProcessName;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
