#pragma once

#include "sql_utils.h"
#include "object.h"
// CDlg_Detail �Ի���

class CDlg_Detail : public CDialogEx
{
	DECLARE_DYNAMIC(CDlg_Detail)

public:
	CDlg_Detail(long long id, sql_utils *sql, CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CDlg_Detail();

// �Ի�������
	enum { IDD = IDD_DIALOG_DETAIL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()

public:
	long long id;
	sql_utils *sql;
	BOOL OnInitDialog();

	CString m_type;
	CString m_id;
	CString m_author;
	CString m_title;
	CString m_rate;
	CString m1;
	CString m2;
	CString m3;
};
