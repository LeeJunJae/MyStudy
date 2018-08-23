#include "CockMgr.h"
#define NPCCNT 5





bool CockMgr::Init()
{
	startTime = (float)timeGetTime() * 0.001f;
	//LNpcArr[obj].Set(100, 100 + rand() % 1000, 0, 0, 80, 96);
	//LNpcArr[obj].Load(L"80ChickenSample110.bmp", L"80ChickenSampleMask110.bmp");

	return true;

}



bool CockMgr::Update()
{
	currentTime = (float)timeGetTime() * 0.001f;

	if (currentTime - startTime >= 1.0f )
	{
			
		this->CreateCock();




		startTime = currentTime;
	}

	npcList.resize(NPCCNT);
	for (int inpc = 0; inpc < NPCCNT; inpc++)
	{
		if (!npcList[inpc]->dead)
		{
			npcList[inpc]->Update();
		}
	}


}

bool CockMgr::Render()
{

}

bool CockMgr::Release()
{
	for (int i = 0; i < NPCCNT; i++)
	{
		delete npcList[i];
	}
}

bool CockMgr::CreateCock()
{
	npcList.resize(NPCCNT);
	for (int i = 0; i < NPCCNT; i++)
	{
		NPCObject* npc = new NPCObject();
		npcList[i] = npc;
		npcList[i]->Set(100, 100 + rand() % 1000, 0, 0, 80, 96);
		npcList[i]->Load(L"80ChickenSample110.bmp", L"80ChickenSampleMask110.bmp");

		npcList.push_back(npc);
	}


	return true;
}

CockMgr::CockMgr()
{
}


CockMgr::~CockMgr()
{
}
