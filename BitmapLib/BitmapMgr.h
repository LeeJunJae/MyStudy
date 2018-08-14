#pragma once
#include "Bitmap.h"

struct TCacheData
{
	int key;
	T_STR name;
	Bitmap* pBitmap;
};


class BitmapMgr : public TSingleton<BitmapMgr>
{
	friend class TSingleton<BitmapMgr>;
	std::map<int, Bitmap*> mapList;
	std::list<TCacheData> mapCacheList;
	int iInex;

public:
	int Load(T_STR szLoadFile);
	int GetChche(T_STR szName);


	Bitmap*  GetPtr(int Key);
	Bitmap*  GetChche(int Key);
	void AddChche(int Key, T_STR name, Bitmap* pData);
	bool Release();

protected:

	BitmapMgr();

public:
	
	virtual ~BitmapMgr();
};
#define I_BitmapMgr BitmapMgr::GetInstance()
