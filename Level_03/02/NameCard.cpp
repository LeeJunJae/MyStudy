#include "NameCard.h"



void NameCard::ShowNameCardInfo()
{
	std::cout << "�̸� : " << this->name << std::endl;
	std::cout << "ȸ�� : " << this->compayName << std::endl;
	std::cout << "��ȣ : " << this->phoneNumber << std::endl;
	std::cout << "���� : " << this->level << std::endl; 
}



NameCard::NameCard(const char* name, const char* companyName, const char* number, int level)
{
	this->name = new char[strlen(name)];
	strcpy(this->name, name);

	this->compayName = new char[strlen(companyName)];
	strcpy(this->compayName, companyName);

	this->phoneNumber = new char[strlen(number)];
	strcpy(this->phoneNumber, number);

	this->level = level;
	

}


NameCard::~NameCard()
{
}
