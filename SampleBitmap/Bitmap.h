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
	bool	Init();		// 초기화
	bool	Update();	// 계산
	bool	Render();	// 드로우
	bool	Release();	// 소멸, 삭제
	bool	Load(T_STR szLoadFile);
public:
	Bitmap();
	~Bitmap();
};

