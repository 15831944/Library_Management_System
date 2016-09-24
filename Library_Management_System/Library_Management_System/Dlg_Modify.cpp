// Dlg_Modify.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Library_Management_System.h"
#include "Dlg_Modify.h"
#include "afxdialogex.h"
#include <vector>
#include "object.h"

using namespace std;
// CDlg_Modify �Ի���

IMPLEMENT_DYNAMIC(CDlg_Modify, CDialogEx)

CDlg_Modify::CDlg_Modify(long long id, sql_utils* sql, CWnd* pParent /*=NULL*/)
	: CDialogEx(CDlg_Modify::IDD, pParent)
	, m_type(_T(""))
	, m_id(_T(""))
	, m_title(_T(""))
	, m_author(_T(""))
	, m_rate(_T(""))
	, m1(_T(""))
	, m2(_T(""))
	, m3(_T(""))
{
	this->id = id;
	this->sql = sql;
}


BOOL CDlg_Modify::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
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
		SetDlgItemText(IDC_MODIFY_M1, L"������  :");
		SetDlgItemText(IDC_MODIFY_M2, L"ISBN��  :");
		SetDlgItemText(IDC_MODIFY_M3, L"ҳ��  :");
		m1 = res[0].publishingCompany.c_str();
		m2 = res[0].ISBN.c_str();
		m3.Format(L"%d", res[0].page);
	}
	else if (m_type == L"��Ƶ�ļ�"){
		SetDlgItemText(IDC_MODIFY_M1, L"��Ʒ�� :");
		SetDlgItemText(IDC_MODIFY_M2, L"��Ʒ���  :");
		SetDlgItemText(IDC_MODIFY_M3, L"��Ƶʱ�� :");
		m1 = res[0].producer.c_str();
		m2 = res[0].production_time.c_str();
		m3.Format(L"%d", res[0].duration);
	}
	else if (m_type == L"ͼ��"){
		SetDlgItemText(IDC_MODIFY_M1, L"��Ʒ����  :");
		SetDlgItemText(IDC_MODIFY_M2, L"ͼ���ĳ� :");
		SetDlgItemText(IDC_MODIFY_M3, L"ͼ���Ŀ�  :");
		m1 = res[0].productionNationality.c_str();
		m2.Format(L"%d",res[0].height);
		m3.Format(L"%d", res[0].width);
	}

	UpdateData(FALSE);
	return TRUE;
}

CDlg_Modify::~CDlg_Modify()
{

}

void CDlg_Modify::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_MD_TYPE, m_type);
	DDX_Text(pDX, IDC_EDIT_MD_ID, m_id);
	DDX_Text(pDX, IDC_EDIT_MD_TITLE, m_title);
	DDX_Text(pDX, IDC_EDIT_MD_AUTHOR, m_author);
	DDX_Text(pDX, IDC_EDIT_MD_RATE, m_rate);
	DDX_Text(pDX, IDC_EDIT_MD_M1, m1);
	DDX_Text(pDX, IDC_EDIT_MD_M2, m2);
	DDX_Text(pDX, IDC_EDIT_MD_M3, m3);
}


BEGIN_MESSAGE_MAP(CDlg_Modify, CDialogEx)
	ON_BN_CLICKED(IDOK, &CDlg_Modify::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlg_Modify ��Ϣ�������
long long CStr_to_ll2(CString & tmp)
{
	long long res = 0;
	int cnt = 0;
	for (int i = tmp.GetLength() - 1; i >= 0; i--){
		res += (tmp.GetAt(i) - '0')*pow(10, cnt++);
	}
	return res;
}


void CDlg_Modify::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (!object::checkDate(m2)){
		MessageBox(L"�������ڸ�ʽΪyyyy-mm-dd �� yyyy/mm/dd!");
		return;
	}
	long long new_id = CStr_to_ll2(m_id);
	if (sql->isExistId(new_id) && new_id != id){
		MessageBox(L"�ñ���Ѵ��ڣ�������ѡ���ţ�", 0);
		return;
	}

	CDialogEx::OnOK();
}
