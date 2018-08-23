#include "Sprite.h"
#include "BitmapMgr.h"

void		Sprite::SetLife(float fAnimTime)
{
	m_fLifeTime = fAnimTime;
	m_fSecPerRender = fAnimTime / m_iNumBitmap;
}
void Sprite::SetAttribute(float fAnimTime, int iWidth, int iWidthSize, int iHeight, int iHeightSize)
{
	RectSet.left = iWidth;
	RectSet.right = iWidthSize; // �ؽ��� ���� �� ���� �� ũ��	
	RectSet.top = iHeight;
	RectSet.bottom = iHeightSize; // �ؽ��� ���� �� ���� �� ũ��

	if (m_iNumBitmap > 0)
	{
		m_fSecPerRender = fAnimTime / m_iNumBitmap;
		return;
	}
	else
	{
		m_fSecPerRender = fAnimTime / (iWidth*iHeight);
		m_iNumBitmap = iWidth * iHeight;
	}

	for (int iHeight = 0; iHeight<RectSet.left; iHeight++)
	{
		for (int iWidth = 0; iWidth<RectSet.top; iWidth++)
		{
			RectUV  tRect;
			tRect.Rect.left = iWidth * RectSet.right;
			tRect.Rect.right = (iWidth + 1) * RectSet.right;
			tRect.Rect.top = iHeight * RectSet.bottom;
			tRect.Rect.bottom = (iHeight + 1)* RectSet.bottom;
			m_RectList.push_back(tRect);
		}
	}
}
RECT Sprite::SetUV(RECT& Rect)
{
	RECT vUV;
	float fOffSetX = 0.0f;
	if (Rect.left > 0)
	{
		fOffSetX = (float)Rect.left / (float)(RectSet.left*RectSet.right);
	}
	float fOffSetY = 0.0f;
	if (Rect.top > 0)
	{
		fOffSetY = (float)Rect.top / (float)(RectSet.top*RectSet.bottom);
	}

	vUV.left = fOffSetX;
	vUV.top = fOffSetY;

	fOffSetX = 1.0f;
	if (Rect.right > 0)
	{
		fOffSetX = (float)Rect.right / (float)(RectSet.left*RectSet.right);
	}
	fOffSetY = 1.0f;
	if (Rect.bottom > 0)
	{
		fOffSetY = (float)Rect.bottom / (float)(RectSet.top*RectSet.bottom);
	}
	vUV.right = fOffSetX;
	vUV.bottom = fOffSetY;
	return vUV;
}
void Sprite::SetRectArray(vector<RECT> rtArray, float fLifeTime)
{
	for (int iList = 0; iList < rtArray.size(); iList++)
	{
		RectUV rt;
		rt.Rect = rtArray[iList];
		m_RectList.push_back(rt);
	}
	m_fLifeTime = fLifeTime;
	m_fSecPerRender = m_fLifeTime / m_RectList.size();
	m_rtObj = m_RectList[0].Rect;
	m_iNumBitmap = m_RectList.size();
}
void Sprite::SetBitmapArray(TCHAR_STRING_VECTOR FileList)
{
	HRESULT hr = S_OK;
	for (int iList = 0; iList < FileList.size(); iList++)
	{
		INT iIndex = I_BMgr.Add(const_cast<TCHAR*>(FileList[iList].c_str()));
		if (iIndex <= 0)
		{
			MessageBox(0, _T("m_Texture.Load ����"), _T("Fatal error"), MB_OK);
			return;
		}
		m_BitmapArray.push_back(iIndex);
	}
	m_iNumBitmap = m_BitmapArray.size();
}
bool Sprite::Init()
{
	return true;
}
bool		Sprite::Release()
{
	DeleteObject(m_hBrush);
	SelectObject(m_pBitmap->m_hScreenDC, m_hOldBrush);
	return true;
};
void Sprite::SetPos(Point pos)
{
	m_ObjPos = pos;
	RECT p = m_RectList[m_iApplyIndex].Rect;
	m_rtStart.x = m_ObjPos.x - p.right / 2.0f;
	m_rtStart.y = m_ObjPos.y - p.bottom / 2.0f;
}
// ��������Ʈ Ÿ�� ������ ����
void Sprite::Updata(Point pos, float& pfCurrentTimer, int& iApplyIndex, float fGlobalTime, float fElapsedTime)
{
	pfCurrentTimer += fElapsedTime;
	if (pfCurrentTimer >= m_fSecPerRender)
	{
		if (++iApplyIndex >= m_iNumBitmap)
			iApplyIndex = 0;

		pfCurrentTimer = 0.0f;
	}
	AnimationFrame(iApplyIndex);
	SetPos(pos);
}
void Sprite::AnimationFrame(int iApplyIndex)
{
	// �ؽ�ó ���ϸ��̼�
	if (m_BitmapArray.size())
	{

	}
	else // UV �ؽ�ó ���ϸ��̼�
	{
		if (m_RectList.size())
		{
			m_rtCurrent = m_RectList[iApplyIndex].Rect;
		}
	}
}
bool Sprite::Frame(float fGlobalTime, float fElapsedTime)
{
	Updata(m_ObjPos, m_fTime, m_iApplyIndex, fGlobalTime, fElapsedTime);
	AnimationFrame(m_iApplyIndex);
	return true;
}

bool		Sprite::Render()
{
	if (m_bMask == false)
	{
		m_pBitmap->Draw(m_hOffScreenDC, m_rtStart, m_rtCurrent, m_dwReverse, SRCCOPY);
		return true;
	}
	if (m_bMask)
	{
		m_pBitmapMask->Draw(m_hOffScreenDC,
			m_rtStart,
			m_rtCurrent,
			m_dwReverse,
			SRCAND);
		m_pBitmap->Draw(m_hOffScreenDC,
			m_rtStart,
			m_rtCurrent,
			m_dwReverse,
			SRCINVERT);
		m_pBitmapMask->Draw(m_hOffScreenDC,
			m_rtStart,
			m_rtCurrent,
			m_dwReverse,
			SRCINVERT);
	}


	return true;
};


Sprite::Sprite(void)
{
	m_fLifeTime = 0.0f;
	m_fTime = 0.0f;
	m_iApplyIndex = 0;
	m_fSecPerRender = 0.2f;
	m_iNumBitmap = 0;
	RectSet.left = 4;
	RectSet.right = 64; // �ؽ��� ���� �� ���� �� ũ��	
	RectSet.top = 4;
	RectSet.bottom = 64; // �ؽ��� ���� �� ���� �� ũ��
}

Sprite::~Sprite(void)
{
}