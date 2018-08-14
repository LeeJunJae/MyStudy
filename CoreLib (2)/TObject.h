#pragma once
#include "TBitmapMgr.h"
#include "TCollision.h"

#define LR_ROTATION 0x01
#define TB_ROTATION 0x02
#define LRTB_ROTATION 0x04

class TObject
{
public:
	TBitmap*  m_pColorBitmap;
	TBitmap*  m_pMaskBitmap;
	tPoint   m_pos;
	tPoint   m_posDraw;
	RECT	 m_rtDraw;
	RECT	 m_rtCollision;
	float    m_fDir[2];
	float    m_fSpeed;
	bool	 m_bDebugRect;
	bool	 m_bDead;
public:
	HBITMAP   m_hColorRotateBitmap;
	HBITMAP   m_hMaskRotateBitmap;
	HDC		  m_hRotationDC;
	HDC		  m_hMemMaskDC;
	HDC		  m_hMemColorDC;
	float	  m_iMaxDistance;
	float	  m_fAngle;
	HBRUSH	  m_hbrBack;
public:
	virtual void	Set(tPoint pos);
	virtual void	Set(float x, float y,
		            DWORD l,
					DWORD t,
					DWORD r,
					DWORD b);
	virtual bool	Load(
		const TCHAR* pszColor,
		const TCHAR* pszMask=0);
	virtual bool	Init();
	virtual bool	Frame();
	virtual bool    Draw(short sType,RECT* rt=0);
	virtual bool    DrawColorKey(DWORD maskColor);
	virtual bool	Render();
	virtual bool	Release();
public:
	void	RotationBlt(float fAngle);
	void	GetRotationBimap(float fAngle,
							HBITMAP hBitmap,
							TBitmap* pSrcBitmap);
public:
	TObject();
	virtual ~TObject();
};

