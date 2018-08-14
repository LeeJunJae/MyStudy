#include <iostream>


struct Node
{
	int num;
	Node* next;
};

Node* head = new Node;
Node* pNext = head;


void AddNode(int num)
{
	pNext->num = num;
	pNext->next = new Node;
	pNext = pNext->next;
}

void DelNode(int nodeLen, int data)
{	
	pNext = head;
	for (int i = 0; i < nodeLen; i++)
	{		
		if (pNext->num == data-1)
		{
			pNext->next = pNext->next->next;
		}

		pNext = pNext->next;
	}
}

int main()
{
	

	for (int i = 0 ;i < 5; i++)
	{
		AddNode(i);
	}
	pNext->num = 5;
	pNext->next = NULL;
	

	DelNode(5, 2);

	for (Node* pNode = head; pNode->next != NULL; pNode = pNode->next)
	{
		std::cout << pNode->num << std::endl;
	}


	



	return 0;
}



