#include "TToken.h"

void TToken::Show()
{
	TValue* pData = m_pToken;
	for (int i = 0; i < m_iSize; i++)
	{
		cout << pData->m_szValue << endl;
		pData = pData->m_pNext;
	}
}

TToken::TToken(char* pData)
{
	m_iSize = 0;
	char* temp;
	char* pszNextToken = 0;

	temp = strtok(pData, " ");


}


TToken::~TToken()
{
}
