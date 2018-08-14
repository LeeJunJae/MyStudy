#include "TCore.h"
#include "TScene.h"

//#define USE_LIBRARY



class Sample : public TCore
{
	std::shared_ptr<TScene> m_pGameScene;
	TScene* m_pGameScene;
	TObject   m_tmpObj;
	float	  m_fAngle;
	std::vector<RECT> m_rtSpriteList;

#ifdef USE_LIBRARY
	HBITMAP   m_hColorRotateBitmap;
	HBITMAP   m_hMaskRotateBitmap;
	HDC		  m_hRotationDC;
	HDC		  m_hMemMaskDC;
	HDC		  m_hMemColorDC;
	float	  m_iMaxDistance;
	HBRUSH	  m_hbrBack;
#endif
public:
	bool	Init()
	{
		m_fAngle = 0.0f;
		m_tmpObj.Init();
		m_tmpObj.Set(300, 300, 90, 2, 42, 58);
		m_tmpObj.Load(L"../../data/bitmap1.bmp",L"../../data/bitmap2.bmp");
#ifdef USE_LIBRARY
		m_hbrBack = CreateSolidBrush(RGB(255, 255, 255));
		m_iMaxDistance =
			sqrt(m_tmpObj.m_rtDraw.right*
				m_tmpObj.m_rtDraw.right +
				m_tmpObj.m_rtDraw.bottom*
				m_tmpObj.m_rtDraw.bottom);

		m_hColorRotateBitmap =
			CreateCompatibleBitmap(m_hScreenDC,
				m_iMaxDistance, m_iMaxDistance);
		m_hMaskRotateBitmap =
			CreateCompatibleBitmap(m_hScreenDC,
				m_iMaxDistance, m_iMaxDistance);

		m_hRotationDC = CreateCompatibleDC(m_hScreenDC);
		m_hMemMaskDC = CreateCompatibleDC(m_hScreenDC);
		m_hMemColorDC = CreateCompatibleDC(m_hScreenDC);
#endif
		//m_pGameScene = std::make_shared<TSceneLobby>();
		m_pGameScene = std::make_shared<SCENE_LOBBY>;
		m_pGameScene->Init();
		m_pGameScene->SetNpcCount(1);
		return true;
	}
#ifdef USE_LIBRARY
	void	RotateBlt(float fAngle, HBITMAP hBitmap,
		TBitmap* pSrcBitmap)
	{
		float fRadian = fAngle * 3.141592f / 180.0f;
		float fCosine = cos(fRadian);
		float fSine = sin(fRadian);

		HBITMAP hOldBitmap = (HBITMAP)SelectObject(m_hRotationDC, hBitmap);
		HBRUSH hOldBrush = (HBRUSH)SelectObject(m_hRotationDC, m_hbrBack);
		PatBlt(m_hRotationDC, 0, 0, m_iMaxDistance, m_iMaxDistance, PATCOPY);
		SelectObject(m_hRotationDC, hOldBrush);

		int iOldGraphic = SetGraphicsMode(m_hRotationDC, GM_ADVANCED);

		XFORM xform;// x,y,1 * 3by2 = x,y,1, µ¿Â÷
		xform.eM11 = fCosine; xform.eM12 = -fSine;
		xform.eM21 = fSine;	xform.eM22 = fCosine;
		xform.eDx = m_iMaxDistance / 2;
		xform.eDy = m_iMaxDistance / 2;
		SetWorldTransform(m_hRotationDC, &xform);

		BitBlt(m_hRotationDC,
			-(m_tmpObj.m_rtDraw.right / 2),
			-(m_tmpObj.m_rtDraw.bottom / 2),
			m_tmpObj.m_rtDraw.right,
			m_tmpObj.m_rtDraw.bottom,
			pSrcBitmap->m_hMemDC,
			m_tmpObj.m_rtDraw.left,
			m_tmpObj.m_rtDraw.top,
			SRCCOPY);

		SelectObject(m_hRotationDC, hOldBitmap);
		SelectObject(m_hRotationDC, hOldBrush);

		xform.eM11 = 1; xform.eM12 = 0;
		xform.eM21 = 0;	xform.eM22 = 1;
		xform.eDx = 0;
		xform.eDy = 0;
		SetWorldTransform(m_hRotationDC, &xform);
		SetGraphicsMode(m_hRotationDC, iOldGraphic);
	}
#endif
	bool	Frame()
	{
#ifdef USE_LIBRARY
		m_fAngle += g_fSecPerFrame * 100.0f;
		RotateBlt(m_fAngle, m_hMaskRotateBitmap, m_tmpObj.m_pMaskBitmap);
		RotateBlt(m_fAngle, m_hColorRotateBitmap, m_tmpObj.m_pColorBitmap);
#endif
		m_tmpObj.Frame();
		m_pGameScene->Frame();
		return true;
	}
	bool	Render()
	{
		m_pGameScene->Render();
		m_fAngle += g_fSecPerFrame * 100.0f;
#ifdef USE_LIBRARY
		m_pGameScene->Render();
		HBITMAP hOldMask = (HBITMAP)SelectObject(m_hMemMaskDC, m_hMaskRotateBitmap);
		HBITMAP hOldColor = (HBITMAP)SelectObject(m_hMemColorDC, m_hColorRotateBitmap);
		BitBlt(g_hOffScreenDC,
			m_tmpObj.m_pos.x - (m_iMaxDistance / 2),
			m_tmpObj.m_pos.y - (m_iMaxDistance / 2),
			m_iMaxDistance,
			m_iMaxDistance,
			m_hMemMaskDC,
			0, 0,
			SRCAND);

		BitBlt(g_hOffScreenDC,
			m_tmpObj.m_pos.x - (m_iMaxDistance / 2),
			m_tmpObj.m_pos.y - (m_iMaxDistance / 2),
			m_iMaxDistance,
			m_iMaxDistance,
			m_hMemColorDC,
			0, 0,
			SRCINVERT);

		BitBlt(g_hOffScreenDC,
			m_tmpObj.m_pos.x - (m_iMaxDistance / 2),
			m_tmpObj.m_pos.y - (m_iMaxDistance / 2),
			m_iMaxDistance,
			m_iMaxDistance,
			m_hMemMaskDC,
			0, 0,
			SRCINVERT);

		SelectObject(m_hMemMaskDC, hOldMask);
		SelectObject(m_hMemColorDC, hOldColor);
#else
		m_tmpObj.RotationBlt(m_fAngle);
#endif		
		return true;
	}
	bool	Release()
	{
#ifdef USE_LIBRARY
		DeleteObject(m_hbrBack);
		DeleteObject(m_hColorRotateBitmap);
		DeleteObject(m_hMaskRotateBitmap);
		ReleaseDC(g_hWnd, m_hRotationDC);
		ReleaseDC(g_hWnd, m_hMemMaskDC);
		ReleaseDC(g_hWnd, m_hMemColorDC);
#endif
		m_tmpObj.Release();
		m_pGameScene->Release();
		return true;
	}
public:
	Sample() {}
	virtual ~Sample() {}
};

GAME_RUN("SampleUI", 800, 600)
 int WINAPI WinMain(HINSTANCE hInst,	HINSTANCE hPrevInst,LPSTR   lpCmdLine,int   nCmdShow)
{
	Sample win; 
	win.SetWindow(hInst, hPrevInst, lpCmdLine, nCmdShow);
	win.Run(); 
}
