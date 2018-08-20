#pragma once
#include "Bitmap.h"


struct stCacheData
{
	int		iKey;
	T_STR	name;
	Bitmap* pBitmap;
};
class BitmapMgr : public Singleton<BitmapMgr>
{
	friend class Singleton<BitmapMgr>;
	std::map<int, Bitmap*> mapList;
	std::list<stCacheData> mapCacheList;
	int		iInex;

public:
	int	Load(T_STR szLoadFile);
	int  GetChche(T_STR szName);


	Bitmap*  GetPtr(int iKey);
	Bitmap*  GetChche(int iKey);
	void  AddChche(int ikey,
		T_STR name,
		Bitmap* pData);

protected:
	BitmapMgr();
public:
	virtual ~BitmapMgr();
};

