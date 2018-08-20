#pragma once
#include <windows.h>
#include <assert.h>
#include <tchar.h>
#include <iostream>
#include <map>
#include <string>
#include <list>

typedef std::basic_string<char> C_STR;
typedef std::basic_string<wchar_t> W_STR;
typedef std::basic_string<TCHAR> T_STR;


extern HWND g_hWnd;
extern HINSTANCE g_hInstance;
extern float g_fSecPerFrame;
extern HDC g_hOffScreenDC;


template<class T> class Singleton
{
public:
	static T& GetInstance()
	{
		static T theSingleInstance;
		return theSingleInstance;
	}
};

