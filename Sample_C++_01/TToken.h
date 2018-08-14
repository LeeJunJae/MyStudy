#pragma once
#include "TValue.h"

class TToken
{
public:
	TValue * m_pToken;
	int   m_iSize;

public:
	void Show();	

	TToken(char* pData);
	~TToken();
};

