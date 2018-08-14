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


	Bitmap*  GetPtr(int iKey);
	Bitmap*  GetChche(int iKey);
	void AddChche(int iKey, T_STR name, Bitmap* pData);

protected:

	BitmapMgr();

public:
	
	virtual ~BitmapMgr();
};
#define I_BitmapMgr BitmapMgr::GetInstance()
