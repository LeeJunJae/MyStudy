#include "Student.h"



void Student::CreateSTD(int number)
{
	this->number  = number;
	this->name[0] = 65 + rand() % 26;
	this->name[1] = 65 + rand() % 26;
	this->name[2] = 65 + rand() % 26;
	this->name[3] = '\0';

	this->iKor =  rand() % 100;
	this->iEng =  rand() % 100;
	this->iMath = rand() % 100;

	this->iTotal = iKor + iEng + iMath;
	this->average = (iKor + iEng + iMath) / 3.0f;
}

void Student::PrintAll()
{
	std::cout << "===============================" << std::endl;
	std::cout << "번호 : " << number << std::endl;
	std::cout << "이름 : " << name << std::endl;
	std::cout << "국어 : " << iKor << std::endl;
	std::cout << "영어 : " << iEng << std::endl;
	std::cout << "수학 : " << iMath << std::endl;
	std::cout << "총점 : " << iTotal << std::endl;
	std::cout << "평균 : " << average << std::endl;
	std::cout << "===============================" << std::endl;

}

void Student::SetStudent(int number, char * name, int iKor, int iEng, int iMath, int iTotal, float average)
{
	this->number = number;
	strcpy(this->name, name);
	this->iKor = iKor;
	this->iEng = iEng;
	this->iMath = iMath;
	this->iTotal = iTotal;
	this->average = average;
}

Student::Student()
{
}


Student::~Student()
{
	
}
