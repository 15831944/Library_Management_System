// Dlg_Find.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library_Management_System.h"
#include "Dlg_Find.h"
#include "afxdialogex.h"


// CDlg_Find �Ի���

IMPLEMENT_DYNAMIC(CDlg_Find, CDialogEx)

CDlg_Find::CDlg_Find(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg_Find::IDD, pParent)
	, m_info(_T(""))
{

}

BOOL CDlg_Find::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	init_combo_obj_type();
	return TRUE;
}

CDlg_Find::~CDlg_Find()
{
}

void CDlg_Find::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo_obj_type);
	DDX_Text(pDX, IDC_EDIT_INFO, m_info);
}


BEGIN_MESSAGE_MAP(CDlg_Find, CDialogEx)
	
	ON_BN_CLICKED(IDOK, &CDlg_Find::OnBnClickedOk)
END_MESSAGE_MAP()

void CDlg_Find::init_combo_obj_type()
{
	m_combo_obj_type.AddString(_T("����"));
	m_combo_obj_type.AddString(_T("���"));
	m_combo_obj_type.AddString(_T("���"));
}

// CDlg_Find ��Ϣ�������




void CDlg_Find::OnBnClickedOk()
{
	int nSel;
	nSel = m_combo_obj_type.GetCurSel();
	m_combo_obj_type.GetLBText(nSel, m_type);
	UpdateData();

	if (m_type.GetLength() == 0)
		MessageBox(L"��ѡ���������", 0);
	else if (m_info.GetLength() == 0)
		MessageBox(L"�����������Ϣ", 0);
	else
		CDialogEx::OnOK();

}
