
// Library_Management_System.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CLibrary_Management_SystemApp: 
// �йش����ʵ�֣������ Library_Management_System.cpp
//

class CLibrary_Management_SystemApp : public CWinApp
{
public:
	CLibrary_Management_SystemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CLibrary_Management_SystemApp theApp;