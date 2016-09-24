
// Library_Management_SystemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "afxcmn.h"
#include "sql_utils.h"

// CLibrary_Management_SystemDlg �Ի���
class CLibrary_Management_SystemDlg : public CDialogEx
{
// ����
public:
	CLibrary_Management_SystemDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CLibrary_Management_SystemDlg();

// �Ի�������
	enum { IDD = IDD_LIBRARY_MANAGEMENT_SYSTEM_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_combo_obj_type;
	void init_combo_type();
	void init_list_show();
	CListCtrl m_list_show;
	afx_msg void OnBnClickedButtonFind2();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnNMClickListShow(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMDblclkListShow(NMHDR *pNMHDR, LRESULT *pResult);
	sql_utils* sql;
	afx_msg void OnBnClickedButtonModify();
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnCbnSelchangeComboObjType();
	afx_msg void OnBnClickedButtonOut();
	afx_msg void OnBnClickedButtonIn();
	void show_list_by_type();
	void count_number();
	long m_num_obj;
	long m_num_book;
	long m_num_vedio;
	long m_num_picture;
};
