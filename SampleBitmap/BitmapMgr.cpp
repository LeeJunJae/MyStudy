#include "BitmapMgr.h"

void  BitmapMgr::AddChche(int ikey,	T_STR name,	Bitmap* pData)
{
	TCacheData cache;
	cache.key = ikey;
	cache.name = name;
	cache.pBitmap = pData;
	if (mapCacheList.size() >= 3)
	{
		mapCacheList.pop_front();
	}
	mapCacheList.push_back(cache);
}
int BitmapMgr::GetChche(T_STR szName)
{
	std::list<TCacheData>::iterator iter;
	for (iter = mapCacheList.begin();	iter != mapCacheList.end(); iter++)
	{
		TCacheData& cache = *iter;
		if (cache.name == szName)
		{
			return cache.key;
		}
	}
	return -1;
}
Bitmap*  BitmapMgr::GetChche(int iKey)
{
	std::list<TCacheData>::iterator iter;
	for (iter = mapCacheList.begin();	iter != mapCacheList.end();iter++)
	{
		TCacheData& cache = *iter;
		if (cache.key == iKey)
		{
			return cache.pBitmap;
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
	for (iter = mapList.begin();
		iter != mapList.end();
		iter++)
	{
		Bitmap* pBitmap = (Bitmap*)(*iter).second;
		if (pBitmap->szName == szName)
		{
			AddChche((*iter).first, szName,	pBitmap);
			return (*iter).first;
		}
	}
	Bitmap* pBitmap = new Bitmap;
	if (pBitmap->Load(szLoadFile))
	{
		mapList.insert(std::make_pair(++iInex, pBitmap));
		AddChche(iInex, szName,pBitmap);

		return iInex;
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
	iter = mapList.find(iKey);

	if (iter == mapList.end())
		return NULL;


	return (*iter).second;
}

BitmapMgr::BitmapMgr()
{
}


BitmapMgr::~BitmapMgr()
{
}
