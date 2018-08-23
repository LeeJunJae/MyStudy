#pragma once
#include "Std.h"

class Bitmap
{
public:
	T_STR	szName;
	HBITMAP hBitmap;
	HDC		hMemDC;
	BITMAP	bmpInfo;

	///////////////////////////////////
	HDC			m_hScreenDC;
	Bitmap*	m_pBitmap;
	Bitmap*	m_pBitmapMask;
	int			m_iBitmap;
	int			m_iBitmapMask;
	bool		m_bMask;
	HDC			m_hOffScreenDC;
	HBRUSH		m_hBrush;
	HBRUSH		m_hOldBrush;
	Point		m_ObjPos; // ��ġ(��,����� ����)
	RECT		m_rtObj;  // �����̹������� ��ο��� ����
	RECT		m_rtCollision;  // �浹����(Ŭ���̾�Ʈ ��ǥ��)
	DWORD		m_dwReverse;
	Point		m_rtStart;

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

