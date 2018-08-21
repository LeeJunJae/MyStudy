#include "TCore.h"
#include "TScene.h"
#include "TSound.h"

typedef std::vector<RECT>  RECT_ARRAY;
class TEffectObj : public TNpcObj
{
public:
	int			m_iSpriteIndex;
	int			m_iCurrentRect;
	float		m_fSpriteTime;
	float		m_fOffset;
	float		m_fLifeTime;
public:
	bool Frame()
	{
		if (m_bDead) return true;
		m_fLifeTime -= g_fSecPerFrame;
		if (m_fLifeTime < 0.0f)
		{
			m_fLifeTime = 1.0f;
			m_bDead = true;
		}
		int iHalfX = m_rtDraw.right / 2;
		int iHalfY = m_rtDraw.bottom / 2;	
		//m_pos.x += m_fDir[0] * m_fSpeed * g_fSecPerFrame;
		m_pos.y -= m_fSpeed * g_fSecPerFrame;
		m_posDraw.x = m_pos.x - iHalfX;
		m_posDraw.y = m_pos.y - iHalfY;

		m_rtCollision.left = m_posDraw.x;
		m_rtCollision.top = m_posDraw.y;
		m_rtCollision.right = m_rtCollision.left + m_rtDraw.right;
		m_rtCollision.bottom = m_rtCollision.top + m_rtDraw.bottom;
		return true;
	}
	TEffectObj() {
		m_iSpriteIndex = 0;
		m_iCurrentRect = 0;
		m_fSpriteTime = 1.0f;
		m_fOffset = 1.0f;
		m_fLifeTime = 1.0f;
	};
	~TEffectObj() {};
};
class Sample : public TCore
{
	std::shared_ptr<TScene> m_pGameScene;
	std::vector<TEffectObj>   m_tmpObj;
	std::vector<TNpcObj>		m_npcList;
	float		m_fAngle;	
	std::vector<RECT_ARRAY>  m_rtSpriteList;
	bool		m_bGameSceneChange;
public:
	bool GameDataLoad(const TCHAR* pszLoad)
	{
		TCHAR pBuffer[256] = { 0 };
		TCHAR pTemp[256] = { 0 };

		int iNumSprite = 0;
		FILE* fp_src;
		_wfopen_s(&fp_src, pszLoad, _T("rt"));
		if (fp_src == NULL) return false;

		_fgetts(pBuffer, _countof(pBuffer), fp_src);
		_stscanf_s(pBuffer, _T("%s%d%s"), pTemp, _countof(pTemp), &iNumSprite);
		m_rtSpriteList.resize(iNumSprite);

		for (int iCnt = 0; iCnt < iNumSprite; iCnt++)
		{
			int iNumFrame = 0;
			_fgetts(pBuffer, _countof(pBuffer), fp_src);
			_stscanf_s(pBuffer, _T("%s %d"), pTemp, _countof(pTemp), &iNumFrame);
			//m_rtSpriteList[iCnt].resize(iNumFrame);

			RECT rt;
			for (int iFrame = 0; iFrame < iNumFrame; iFrame++)
			{
				_fgetts(pBuffer, _countof(pBuffer), fp_src);
				_stscanf_s(pBuffer, _T("%s %d %d %d %d"), pTemp, _countof(pTemp),
					&rt.left, &rt.top, &rt.right, &rt.bottom);
				m_rtSpriteList[iCnt].push_back(rt);
			}
		}
		fclose(fp_src);
		return true;
	}

	void AddEffect(POINT pos)
	{
		TEffectObj obj;
		obj.Init();
		obj.Set(pos.x, pos.y, 1, 142, 41, 41);
		obj.Load(
				L"../../data/bitmap1.bmp",
				L"../../data/bitmap2.bmp");
		obj.m_iSpriteIndex = rand() % m_rtSpriteList.size();		
		obj.m_fSpeed = 1000.0f;
		m_tmpObj.push_back(obj);
	}
	bool	Init()
	{
		m_bGameSceneChange = false;
		TSound::Get()->Init();
		TSound::Get()->Load("../../data/abel_leaf.asf", true);
		TSound::Get()->Load("../../data/OnlyLove.mp3", false);
		TSound::Get()->Load("../../data/romance.mid", false);

		TSound::Get()->Load("../../data/ItemGain.wav", false);
		TSound::Get()->Load("../../data/Gun2.wav", false);
		TSound::Get()->Load("../../data/GunShot.mp3", false);


		GameDataLoad( L"SpriteList.txt");
		
		m_npcList.resize(g_iMaxNpcCount);
		for (int iObj = 0; iObj < g_iMaxNpcCount; iObj++)
		{
			m_npcList[iObj].Set(
				100 + rand() % 600,
				100 + rand() % 400,
				46, 62, 68, 79);
			m_npcList[iObj].Load(
				L"../../data/bitmap1.bmp",
				L"../../data/bitmap2.bmp");
		}

		m_fAngle = 0.0f;		
		m_pGameScene = std::make_shared<TSceneGame>();
		m_pGameScene->Init();
		m_pGameScene->SetNpcCount(1);
		return true;
	}

	bool	Frame()
	{
		TSound::Get()->Frame();
		if (I_Input.Key('3') == KEY_PUSH)
		{
			TSound::Get()->PlayEffect(3);
		}
		if (I_Input.Key('4') == KEY_PUSH)
		{
			TSound::Get()->PlayEffect(4);
		}
		if (I_Input.Key('5') == KEY_PUSH)
		{
			TSound::Get()->PlayEffect(5);
		}

		m_pGameScene->Frame();
		for (int inpc = 0; inpc < g_iMaxNpcCount; inpc++)
		{
			if (!m_npcList[inpc].m_bDead)
			{
				m_npcList[inpc].Frame();
			}
		}

		if (I_Input.Key(VK_LBUTTON))
		{
			static float fAddTime = 0.0f;
			fAddTime += g_fSecPerFrame;
			if (fAddTime >= 0.1f)
			{
				AddEffect(I_Input.m_MousePos);
				TSound::Get()->PlayEffect(5);
				fAddTime -= 0.1f;
			}
		}
		
		for (int iObj = 0; iObj < m_tmpObj.size(); iObj++)
		{
			m_tmpObj[iObj].m_fOffset = 1.0f / m_rtSpriteList[m_tmpObj[iObj].m_iSpriteIndex].size();
			m_tmpObj[iObj].m_fSpriteTime += g_fSecPerFrame;
			if (m_tmpObj[iObj].m_fSpriteTime >= m_tmpObj[iObj].m_fOffset)
			{
				m_tmpObj[iObj].m_iCurrentRect++;
				if (m_tmpObj[iObj].m_iCurrentRect >= m_rtSpriteList[m_tmpObj[iObj].m_iSpriteIndex].size())
				{
					m_tmpObj[iObj].m_iCurrentRect = 0;
					//m_tmpObj[iObj].m_iSpriteIndex = (++m_tmpObj[iObj].m_iSpriteIndex >= m_rtSpriteList.size()) ? 0 : m_tmpObj[iObj].m_iSpriteIndex;
				}
				m_tmpObj[iObj].m_fSpriteTime -= m_tmpObj[iObj].m_fOffset;
			}
			RECT rt = m_rtSpriteList[m_tmpObj[iObj].m_iSpriteIndex][m_tmpObj[iObj].m_iCurrentRect];
			m_tmpObj[iObj].m_rtDraw = rt;
			m_tmpObj[iObj].Frame();
		}
		
		for (int inpc = 0; inpc < g_iMaxNpcCount; inpc++)
		{
			for (int ieffect = 0; ieffect < m_tmpObj.size(); ieffect++)
			{
				if (m_npcList[inpc].m_bDead==false)
				{
					if (TCollision::SphereInSphere(
						m_npcList[inpc].m_rtCollision,
						m_tmpObj[ieffect].m_rtCollision))
					{
						TSound::Get()->PlayEffect(3);
						m_npcList[inpc].m_bDead = true;
					}
				}
			}
		}

		
		return true;
	}
	bool	Render()
	{
		if(m_bGameSceneChange==false)
			m_pGameScene->Render();
		else
			m_pGameScene->FadeOut();

		m_bGameSceneChange = true;
		for (int inpc = 0; inpc < m_pGameScene->m_iMaxNpcCount; inpc++)
		{
			if (!m_npcList[inpc].m_bDead)
			{
				m_npcList[inpc].Render();
				m_bGameSceneChange = false;
			}
		}

		m_fAngle += g_fSecPerFrame * 100.0f;
		for (int iObj = 0; iObj < m_tmpObj.size(); iObj++)
		{
			m_tmpObj[iObj].RotationBlt(m_fAngle);
		}
		return true;
	}
	bool	Release()
	{
		for (int iObj = 0; iObj < m_tmpObj.size(); iObj++)
		{
			m_tmpObj[iObj].Release();
		}
		for (int iObj = 0; iObj < g_iMaxNpcCount; iObj++)
		{
			m_npcList[iObj].Release();
		}
		m_pGameScene->Release();
		TSound::Get()->Release();
		return true;
	}
public:
	Sample() {
	}
	virtual ~Sample() {}
};


GAME_RUN("SampleSprite", 800, 600)