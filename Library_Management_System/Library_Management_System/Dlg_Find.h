#pragma once
#include "afxwin.h"


// CDlg_Find �Ի���

class CDlg_Find : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Find)

public:
	CDlg_Find(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg_Find();

// �Ի�������
	enum { IDD = IDD_DIALOG_FIND };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	BOOL OnInitDialog();
	void init_combo_obj_type();
	CComboBox m_combo_obj_type;
	CString m_info;
	CString m_type;

	afx_msg void OnBnClickedOk();
};
