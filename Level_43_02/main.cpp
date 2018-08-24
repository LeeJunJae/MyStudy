#include <iostream>

struct Node
{
	int level;
	int data;
	
	Node* left  = NULL;
	Node* right = NULL;		
};
int data[6] = { 7,1,5,3,6,9 };

Node* BinaryNode(Node* parent, int data)
{
	if (parent == 0)
		return 0;
	if (parent->data > data)
	{
		if (parent->left == NULL)
		{
			parent->left = new Node;
			parent->left->data = data;
			parent->left->level = parent->level + 1;
		}
		else
		{
			BinaryNode(parent->left, data);
		}
	}
	else
	{
		if (parent->right == NULL)
		{
			parent->right = new Node;
			parent->right->data = data;
			parent->right->level = parent->level + 1;
		}
		else
		{
			BinaryNode(parent->right, data);
		}
	}
}
int main()
{
	Node* head = new Node;
	head->level = 1;
	head->data = data[0];

	for (int i = 1; i < 6; i++)
	{
		BinaryNode(head, data[i]);
	}


	return 0;
}