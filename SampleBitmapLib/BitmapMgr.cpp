#include "BitmapMgr.h"

void  BitmapMgr::AddChche(int ikey,	T_STR name,	Bitmap* pData)
{
	TCacheData cache;
	cache.iKey = ikey;
	cache.name = name;
	cache.m_pBitmap = pData;
	if (m_mapCacheList.size() >= 3)
	{
		m_mapCacheList.pop_front();
	}
	m_mapCacheList.push_back(cache);
}
int BitmapMgr::GetChche(T_STR szName)
{
	std::list<TCacheData>::iterator iter;
	for (iter = m_mapCacheList.begin();	iter != m_mapCacheList.end(); iter++)
	{
		TCacheData& cache = *iter;
		if (cache.name == szName)
		{
			return cache.iKey;
		}
	}
	return -1;
}
Bitmap*  BitmapMgr::GetChche(int iKey)
{
	std::list<TCacheData>::iterator iter;
	for (iter = m_mapCacheList.begin();	iter != m_mapCacheList.end();iter++)
	{
		TCacheData& cache = *iter;
		if (cache.iKey == iKey)
		{
			return cache.m_pBitmap;
		}
	}
	return NULL;
}
int	BitmapMgr::Load(T_STR szLoadFile)
{
	T_STR szName = szLoadFile;
	int iKey = GetChche(szName);
	if (iKey > 0)
	{
		return iKey;
	}
	std::map<int, Bitmap*>::iterator iter;
	for (iter = m_mapList.begin();
		iter != m_mapList.end();
		iter++)
	{
		Bitmap* pBitmap = (Bitmap*)(*iter).second;
		if (pBitmap->m_szName == szName)
		{
			AddChche((*iter).first, szName,	pBitmap);
			return (*iter).first;
		}
	}
	Bitmap* pBitmap = new Bitmap;
	if (pBitmap->Load(szLoadFile))
	{
		m_mapList.insert(std::make_pair(++m_iInex, pBitmap));
		AddChche(m_iInex, szName,pBitmap);

		return m_iInex;
	}
	return -1;
}
Bitmap* BitmapMgr::GetPtr(int iKey)
{
	Bitmap* pBitmap = GetChche(iKey);
	if (pBitmap != NULL)
	{
		return pBitmap;
	}
	std::map<int, Bitmap*>::iterator iter;
	iter = m_mapList.find(iKey);

	if (iter == m_mapList.end())
		return NULL;


	return (*iter).second;
}

BitmapMgr::BitmapMgr()
{
}


BitmapMgr::~BitmapMgr()
{
}
