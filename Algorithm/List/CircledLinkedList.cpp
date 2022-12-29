#include <iostream>

struct Node
{
	int Data;
	Node* PrevNode;
	Node* NextNode;
};

Node* CLL_CreateNode(Node** Head, Node* NewNode)
{
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
		(*Head)->NextNode = *Head;
		(*Head)->PrevNode = *Head;
	}
	else
	{
		Node* Tail = (*Head)->PrevNode;

		Tail->NextNode->PrevNode = NewNode;
		Tail->NextNode = NewNode;

		NewNode->NextNode = (*Head);
		NewNode->PrevNode = Tail;
	}
}

int main()
{



	return 0;
}