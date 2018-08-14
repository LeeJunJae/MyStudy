#pragma once
#include "Std.h"


class Bitmap
{
public:
	T_STR szName;
	HBITMAP hBitmap;
	HDC hMemDC;
	BITMAP bmpInfo;

public:
	bool	Init();		// �ʱ�ȭ
	bool	Update();	// ���
	bool	Render();	// ��ο�
	bool	Release();	// �Ҹ�, ����
	bool	Load(T_STR szLoadFile);
public:
	Bitmap();
	~Bitmap();
};

