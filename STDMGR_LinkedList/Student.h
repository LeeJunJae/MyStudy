#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>


class Student
{
private:
	int   number;
	char  name[20];
	int	  iKor;
	int	  iEng;
	int	  iMath;	
	int   iTotal;
	float average;


public:
	void CreateSTD(int number);
	void PrintAll();

	int   GetNumber() { return number; };
	char* GetName() { return name; };
	int   GetKor() { return iKor; };
	int   GetEng() { return iEng; };
	int   GetMath() { return iMath; };
	int   GetTotal() { return iTotal; };
	float GetAverage() { return average; };


	void SetStudent(int number, char* name, int iKor, int iEng, int iMath, int iTotal, float average);
	

	


public:
	Student();
	~Student();
};

