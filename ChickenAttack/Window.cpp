#include "Window.h"

Window*   g_pWindow	  = 0;
HWND      g_hWnd      = NULL;
HINSTANCE g_hInstance = NULL;


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	assert(g_pWindow != NULL);

	LRESULT ret;
	if (ret = g_pWindow->MsgProc(hWnd, msg, wParam, lParam))
	{
		return ret;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}



void Window::Set(DWORD style)
{
	this->Style = style;
}
void Window::CenterWindow()
{
	int iScreenWidth = GetSystemMetrics(SM_CXFULLSCREEN);
	int iScreenHegiht = GetSystemMetrics(SM_CYFULLSCREEN);
	int x = (iScreenWidth - (window.right - window.left)) / 2;
	int y = (iScreenHegiht - (window.bottom - window.top)) / 2;
	MoveWindow(hWnd, x, y, window.right, window.bottom, true);
}

bool Window::SetWindow(HINSTANCE hInstance, const TCHAR* titleName ,UINT width , UINT height )
{
	this->hInstance = hInstance;
	g_hInstance = hInstance;
	// 윈도우 클래스 등록
	WNDCLASSEX wc;
	ZeroMemory(&wc, sizeof(WNDCLASSEX));
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = WndProc;
	wc.hInstance = this->hInstance;
	wc.lpszClassName = L"MyWindow";
	wc.hCursor = LoadCursor(this->hInstance, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);
	if (RegisterClassEx(&wc) == FALSE)
	{
		return false;
	}

	//// 윈도우 생성( 등록된 클래스를 사용해서 )
	this->hWnd = CreateWindowEx(WS_EX_APPWINDOW, L"MyWindow", titleName, Style, 0, 0, width, height, NULL, NULL, this->hInstance, NULL);
	if (this->hWnd == NULL)
	{
		return false;
	}
	g_hWnd = this->hWnd;

	GetWindowRect(this->hWnd, &window);
	GetClientRect(this->hWnd, &client);

	CenterWindow();

	ShowWindow(this->hWnd, SW_SHOW);
	return true;
}

bool Window::Run()
{
	if (!GameInit()) return false;
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			if (msg.message == WM_QUIT)
			{
				break;
			}
			MsgEvent(msg);
		}
		else
		{
			GameRun();
			Sleep(1);
		}
	}
	return GameRelease();
}


LRESULT Window::MsgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lPram)
{
	switch (msg)
	{
		case WM_CREATE:
		{
			//MessageBox(NULL, L"윈도우가 떴다.", L"윈도우생성", MB_OK);
		}
		break;

		case WM_DESTROY:
		{
			PostQuitMessage(0);// WM_QUIT--> PUSH			
		}
		return 0;
	}
	return 0;
}

bool    Window::GameInit()
{
	return true;
}
bool	Window::GameRun()
{
	return true;
}
bool	Window::GameRelease()
{
	return true;
}


void Window::MsgEvent(MSG msg)
{
	//I_Input.MsgEvent(msg);
}










Window::Window()
{
	Style = WS_OVERLAPPEDWINDOW;
	g_pWindow = this;
}


Window::~Window()
{
}
