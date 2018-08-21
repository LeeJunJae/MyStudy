#include "TScene.h"
#include "TInput.h"
void    TScene::SetNpcCount(int iNpc)
{
	if (g_iMaxNpcCount <= iNpc)
	{
		m_iMaxNpcCount = g_iMaxNpcCount;
		return;
	}
	m_iMaxNpcCount = iNpc;
}
bool    TSceneGame::Reset()
{
	m_bNextSceneStart = false;
	for (int iObj = 0; iObj < g_iMaxNpcCount; iObj++)
	{
		m_npcList[iObj].m_bDead = false;
		m_npcList[iObj].Set(
			100 + rand() % 600,
			100 + rand() % 400,
			46, 62, 68, 79);
	}
	return true;
}
bool	TSceneGame::Init()
	{
		m_BackGround.Init();
		m_BackGround.Set(g_rtClient.right / 2,
			g_rtClient.bottom / 2, 0, 0, 800, 600);
		m_BackGround.Load(
			L"../../data/eye.bmp");
		m_Hero.Set(300, 300, 90, 2, 42, 58);
		m_Hero.Load(
			L"../../data/bitmap1.bmp",
			L"../../data/bitmap2.bmp");

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
		return true;
	}
bool	TSceneGame::Frame()
	{
		if (I_Input.Key('0') == KEY_PUSH)
		{
			m_Hero.m_bDebugRect = !m_Hero.m_bDebugRect;
			for (int iObj = 0; iObj < m_iMaxNpcCount; iObj++)
			{
				m_npcList[iObj].m_bDebugRect =
					!m_npcList[iObj].m_bDebugRect;
			}
		}

		m_BackGround.Frame();
		m_Hero.Frame();
		for (int inpc = 0; inpc < m_iMaxNpcCount; inpc++)
		{
			if (!m_npcList[inpc].m_bDead)
			{
				m_npcList[inpc].Frame();
			}
		}
		for (int inpc = 0; inpc < m_iMaxNpcCount; inpc++)
		{
			if (TCollision::SphereInSphere(
				m_npcList[inpc].m_rtCollision,
				m_Hero.m_rtCollision))
			{
				m_npcList[inpc].m_bDead = true;
			}
		}
		bool bChangeScene = true;
		for (int inpc = 0; inpc < m_iMaxNpcCount; inpc++)
		{
			if (I_Input.Key(VK_LBUTTON) &&
				TCollision::SphereInPt(
					m_npcList[inpc].m_rtCollision,
					I_Input.m_MousePos))
			{
				m_npcList[inpc].m_bDead = true;
			}
			if(m_npcList[inpc].m_bDead==false)
			{
				bChangeScene = false;
			}
		}
		if (bChangeScene==true)
		{
			m_bNextSceneStart = true;
		}

		return true;
	}
bool	TSceneGame::Render() {
		//m_BackGround.Draw(LRTB_ROTATION);
		//m_BackGround.DrawColorKey(RGB(255,0,0));
		m_BackGround.Render();
		m_Hero.Render();
		for (int inpc = 0; inpc < m_iMaxNpcCount; inpc++)
		{
			if (!m_npcList[inpc].m_bDead)
			{
				m_npcList[inpc].Render();
			}
		}

		return true;
	}
bool	TSceneGame::Release() {
		m_BackGround.Release();
		m_Hero.Release();
		for (int iObj = 0; iObj < m_iMaxNpcCount; iObj++)
		{
			m_npcList[iObj].Release();
		}
		return true;
	}
TSceneGame::TSceneGame()
{
	m_iSceneID = SCENE_PLAYLEVEL;
}
TSceneGame::~TSceneGame()
{
}
