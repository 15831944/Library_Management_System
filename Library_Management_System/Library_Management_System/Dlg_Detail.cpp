// Dlg_Detail.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library_Management_System.h"
#include "Dlg_Detail.h"
#include "afxdialogex.h"
#include <vector>

using namespace std;

// CDlg_Detail �Ի���

IMPLEMENT_DYNAMIC(CDlg_Detail, CDialogEx)

CDlg_Detail::CDlg_Detail(long long id, sql_utils *sql, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg_Detail::IDD, pParent)
	, m_type(_T(""))
	, m_id(_T(""))
	, m_author(_T(""))
	, m_title(_T(""))
	, m_rate(_T(""))
	, m1(_T(""))
	, m2(_T(""))
	, m3(_T(""))
{
	this->id = id; 
	this->sql = sql;
}

BOOL CDlg_Detail::OnInitDialog()
{
	SetDlgItemText(IDC_TYPE, L"����  :");
	SetDlgItemText(IDC_ID, L"���  :");
	SetDlgItemText(IDC_TITLE, L"����  :");
	SetDlgItemText(IDC_AUTHOR, L"����  :");
	SetDlgItemText(IDC_RATE, L"����  :");

	vector <object> res;
	sql->searchById(id, res);

	CString tmp;

	tmp.Format(L"%lld", res[0].id);
	m_id = tmp;

	if (res[0].type == object::TYPE_BOOK)
		tmp = L"ͼ��";
	else if (res[0].type == object::TYPE_PICTURE)
		tmp = L"ͼ��";
	else
		tmp = L"��Ƶ�ļ�";
	m_type = tmp;

	tmp = res[0].author.c_str();
	m_author = tmp;

	tmp = res[0].title.c_str();
	m_title = tmp;

	if (res[0].classification == object::CLASSIFICATION_CHILDREN)
		tmp = L"��ͯ";
	else if (res[0].classification == object::CLASSIFICATION_ADULT)
		tmp = L"����";
	else if (res[0].classification == object::CLASSIFICATION_NORMAL)
		tmp = L"��ͨ";
	else
		tmp = L"δ����";
	m_rate = tmp;

	if (m_type == L"ͼ��"){
		SetDlgItemText(IDC_M_1, L"������  :");
		SetDlgItemText(IDC_M_2, L"ISBN��  :");
		SetDlgItemText(IDC_M_3, L"ҳ��  :");
		m1 = res[0].publishingCompany.c_str();
		m2 = res[0].ISBN.c_str();
		m3.Format(L"%d", res[0].page);
	}
	else if (m_type == L"��Ƶ�ļ�"){
		SetDlgItemText(IDC_M_1, L"��Ʒ�� :");
		SetDlgItemText(IDC_M_2, L"��Ʒ���  :");
		SetDlgItemText(IDC_M_3, L"��Ƶʱ�� :");
		m1 = res[0].producer.c_str();
		m2 = res[0].production_time.c_str();
		m3.Format(L"%d", res[0].duration);
	}
	else if (m_type == L"ͼ��"){
		SetDlgItemText(IDC_M_1, L"��Ʒ����  :");
		SetDlgItemText(IDC_M_2, L"ͼ���ĳ� :");
		SetDlgItemText(IDC_M_3, L"ͼ���Ŀ�  :");
		m1 = res[0].productionNationality.c_str();
		m2.Format(L"%d", res[0].height);
		m3.Format(L"%d", res[0].width);
	}

	UpdateData(FALSE);
	return TRUE;
}

CDlg_Detail::~CDlg_Detail()
{

}

void CDlg_Detail::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TYPE, m_type);
	DDX_Text(pDX, IDC_EDIT_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_TITLE2, m_author);
	DDX_Text(pDX, IDC_EDIT1_AUTHOR2, m_title);
	DDX_Text(pDX, IDC_EDIT_RATE2, m_rate);
	DDX_Text(pDX, IDC_EDIT_M_1, m1);
	DDX_Text(pDX, IDC_EDIT_M2, m2);
	DDX_Text(pDX, IDC_EDIT_M3, m3);
}


BEGIN_MESSAGE_MAP(CDlg_Detail, CDialogEx)
END_MESSAGE_MAP()


// CDlg_Detail ��Ϣ�������
