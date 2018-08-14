#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string.h>

using namespace::std;

class TValue
{
private :
	char* m_szValue;
	TValue* m_pNext;

	friend class TToken;
	

public:
	TValue(char* pData);
	~TValue();
};

