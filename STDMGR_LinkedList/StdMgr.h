#pragma once
#include "Student.h"

struct StdLinkList
{
	Student std;
	StdLinkList*  next;
};


class StdMgr
{
private:
	StdLinkList* stdHead;
	StdLinkList* stdTail;
	int stdCount;

public:
	void Input();
	void Print();
	void Search();
	void CreateData(int stdCount);
	void FileSave();
	void FileLoad();
	void Delete();

public:
	StdMgr();
	~StdMgr();
};

