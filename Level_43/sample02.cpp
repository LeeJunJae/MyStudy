#include <iostream>


struct Node
{
	Node* rigth = NULL;
	Node* rigth = NULL;

	int data = 0;
};


int data[6] = { 7,1,5,3,6,9 };

int main()
{
	Node* pNode = new Node;
	Node* head = new Node;
	head->data = data[0];


	pNode = head;
	/*
	for (int i = 1; i < 7; i++)
	{
		Node* pNext = new Node;
		pNext->data = data[i];
		if (data[i] < pNode->data)
		{
			pNode->lNext = pNext;
		}
		else
		{
			pNode->rNext = pNext;
		}

		pNode = pNext;		
	}*/

	int idx = 1;
	while (true)
	{
		if (idx == 7)
		{
			break;
		}

		Node* pNext = new Node;
		pNext->data = data[idx];

		for (int i = 0; i < 6; i++)
		{

			if (data[i] < pNext->data)
			{
				if (pNode->rigth == NULL)
				{
					pNode->rigth = pNext;
				}
				else
				{
					//
				}
			}
			else
			{
				if (pNode->rigth == NULL)
				{
					pNode->rigth = pNext;
				}
				else
				{
					//
				}
				
			}
		}

		idx++;
	}


	return 0; 
}

