
// media_library_management_system.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// Cmedia_library_management_systemApp: 
// �йش����ʵ�֣������ media_library_management_system.cpp
//

class Cmedia_library_management_systemApp : public CWinApp
{
public:
	Cmedia_library_management_systemApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern Cmedia_library_management_systemApp theApp;