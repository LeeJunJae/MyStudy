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
	Point		m_ObjPos; // 위치(좌,상단이 원점)
	RECT		m_rtObj;  // 원본이미지에서 드로우할 영역
	RECT		m_rtCollision;  // 충돌영역(클라이언트 좌표계)
	DWORD		m_dwReverse;
	Point		m_rtStart;

public:
	bool	Init();		// 초기화
	bool	Update();	// 계산
	bool	Render();	// 드로우
	bool	Release();	// 소멸, 삭제
	bool	Load(T_STR szLoadFile);
public:
	Bitmap();
	~Bitmap();
};

