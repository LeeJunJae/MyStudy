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
	std::cout << "��ȣ : " << number << std::endl;
	std::cout << "�̸� : " << name << std::endl;
	std::cout << "���� : " << iKor << std::endl;
	std::cout << "���� : " << iEng << std::endl;
	std::cout << "���� : " << iMath << std::endl;
	std::cout << "���� : " << iTotal << std::endl;
	std::cout << "��� : " << average << std::endl;
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
