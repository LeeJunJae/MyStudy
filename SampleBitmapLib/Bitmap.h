#pragma once
#include "Std.h"


class Bitmap
{
public:
	T_STR m_szName;
	HBITMAP m_hBitmap;
	HDC m_hMemDC;
	BITMAP m_bmpInfo;

public:
	bool	Init();		// �ʱ�ȭ
	bool	Frame();	// ���
	bool	Render();	// ��ο�
	bool	Release();	// �Ҹ�, ����
	bool	Load(T_STR szLoadFile);
public:
	Bitmap();
	~Bitmap();
};

