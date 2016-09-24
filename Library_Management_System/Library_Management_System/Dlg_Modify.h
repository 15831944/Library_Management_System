#pragma once

#include "sql_utils.h"
#include "object.h"

// CDlg_Modify �Ի���

class CDlg_Modify : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Modify)

public:
	CDlg_Modify(long long id, sql_utils* sql, CWnd* pParent = NULL);   // ��׼���캯��
	
	virtual ~CDlg_Modify();
	BOOL OnInitDialog();
	object after_modify;

// �Ի�������
	enum { IDD = IDD_DIALOG_MODIFY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
	
public:
	long long id;
	sql_utils *sql;
	CString m_type;
	CString m_id;
	CString m_title;
	CString m_author;
	CString m_rate;
	CString m1;
	CString m2;
	CString m3;
	afx_msg void OnBnClickedOk();
};
