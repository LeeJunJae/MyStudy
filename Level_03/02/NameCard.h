#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>


namespace COMP_POS 
{
	enum
	{
		CRLERK,
		SENIOR,
		ASSIST,
		MANAGER
	};
};


class NameCard
{
private:
	char* name;
	char* compayName;
	char*  phoneNumber;
	int  level;

public:
	void ShowNameCardInfo();
	

public:
	NameCard(const char* name, const char* companyName, const char* number, int level);
	~NameCard();
};

