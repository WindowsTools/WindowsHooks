#pragma once


// ResourceOPDialog 对话框

class ResourceOPDialog : public CDialogEx
{
	DECLARE_DYNAMIC(ResourceOPDialog)

public:
	ResourceOPDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ResourceOPDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ResourceOP };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
