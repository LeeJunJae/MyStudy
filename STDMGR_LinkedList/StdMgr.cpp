#define _CRT_SECURE_NO_WARNINGS
#include "StdMgr.h"



void StdMgr::Input()
{
	stdCount++;
	stdTail->next = new StdLinkList;
	stdTail = stdTail->next;
	stdTail->std.CreateSTD(stdCount);
	stdTail->next = nullptr;
	
}

void StdMgr::Print()
{
	StdLinkList* pNext;
	pNext = stdHead;
	for (int idx = 0; idx < stdCount; idx++)
	{		
		pNext->std.PrintAll();
		pNext = pNext->next;
	}

}

void StdMgr::Search()
{
	int searchNum;

	std::cout << "찾는 학생의 번호를 입력하세요" << std::endl;
	std::cin >> searchNum;

	StdLinkList* pNext;
	pNext = stdHead;

	for (int idx = 0; idx < stdCount; idx++)
	{
		if (pNext->std.GetNumber() == searchNum)
		{
			pNext->std.PrintAll();
		}
		pNext = pNext->next;
	}


}

void StdMgr::CreateData(int stdCount)
{
	this->stdCount = stdCount;	
	StdLinkList* head = new StdLinkList;
	head->std.CreateSTD(0);
	StdLinkList* pNext = head;
	
	for (int idx = 1; idx < stdCount; idx++)
	{		
		pNext->next = new StdLinkList;
		pNext = pNext->next;
		pNext->std.CreateSTD(idx);		
	}
	
	pNext = head;

	for (int i = 0; i < stdCount-1; i++)
	{
		pNext = pNext->next;
	}
	this->stdTail = pNext;
	pNext->next = nullptr;

	this->stdHead = head;

}

void StdMgr::FileSave()
{
	StdLinkList* pNext;
	pNext = this->stdHead;

	FILE* fp;
	fp = fopen("data.txt", "w");
	for (int i = 0; i < stdCount; i++)
	{
		fprintf(fp, "%d %s %d %d %d %d %10.4f", 
			pNext->std.GetNumber(),
			pNext->std.GetName(),
			pNext->std.GetKor(),
			pNext->std.GetEng(),
			pNext->std.GetMath(),
			pNext->std.GetTotal(),
			pNext->std.GetAverage());
		fprintf(fp, "\n");

		pNext = pNext->next;
	}
	fclose(fp);

}

void StdMgr::FileLoad()
{
	std::cout << "학생수를 입력하세요" << std::endl;
	std::cout << "입력 : ";
	std::cin >> this->stdCount;	

	int   number;
	char  name[20];
	int	  iKor;
	int	  iEng;
	int	  iMath;
	int   iTotal;
	float average;

	StdLinkList* head = new StdLinkList;
	StdLinkList* pNext;
	pNext = head;

	FILE* fp;
	fp = fopen("data.txt", "r");
	for (int i = 0; i < stdCount; i++)
	{
		fscanf(fp, "%d %s %d %d %d %d %f \n", &number,name,&iKor,&iEng,&iMath,&iTotal,&average);

		pNext->std.SetStudent(number, name, iKor, iEng, iMath, iTotal, average);

		pNext->next = new StdLinkList;
		pNext = pNext->next;
	}
	pNext = head;
	for (int i = 0; i < stdCount - 1; i++)
	{
		pNext = pNext->next;
	}
	this->stdTail = pNext;
	pNext->next = nullptr;

	this->stdHead = head;
	fclose(fp);
}

void StdMgr::Delete()
{
	int number;

	std::cout << "삭제할 학생의 번호를 입력하세요" << std::endl;
	std::cin >> number;

	StdLinkList* pPrev;
	StdLinkList* delete_next;
	
	pPrev = stdHead;

	for (int i = 0; i < stdCount; i++)
	{
		if (number == 0)
		{
			//delete pPrev;					
			stdHead = pPrev->next;
			delete pPrev;
			break;
		}

		if (pPrev->next->std.GetNumber() == number)
		{
			
			delete_next = pPrev->next->next;
			delete pPrev->next;
			pPrev->next = delete_next;

			break;
		}

		if (number == stdCount)
		{
			StdLinkList* temp;
			temp = pPrev->next;
			pPrev->next = nullptr;

			delete temp;

			break;
		}
		pPrev = pPrev->next;
		
	}

	stdCount--;

}

StdMgr::StdMgr()
{
}


StdMgr::~StdMgr()
{
}
