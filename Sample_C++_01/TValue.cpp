#include "TValue.h"



TValue::TValue(char* pData)
{
	int iLength = strlen(pData) + 1;
	int iSize = sizeof(char) * iLength;
	this->m_szValue = new char[iSize];
	strcpy(m_szValue, pData);
	m_pNext = NULL;
}


TValue::~TValue()
{
	delete m_szValue;
}
