
// media_library_management_systemDlg.h : ͷ�ļ�
//

#pragma once


// Cmedia_library_management_systemDlg �Ի���
class Cmedia_library_management_systemDlg : public CDialogEx
{
// ����
public:
	Cmedia_library_management_systemDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_MEDIA_LIBRARY_MANAGEMENT_SYSTEM_DIALOG };

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
};
