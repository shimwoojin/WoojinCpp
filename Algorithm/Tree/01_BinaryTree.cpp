#include <iostream>

struct SBT_Tree
{
	SBT_Tree* Left;
	SBT_Tree* Right;

	char Data;
};

SBT_Tree* SBT_CreateNode(char Data)
{
	SBT_Tree* NewNode = (SBT_Tree*)malloc(sizeof(SBT_Tree));
	NewNode->Left = nullptr;
	NewNode->Right = nullptr;

	NewNode->Data = Data;

	return NewNode;
}

void SBT_DestroyNode(SBT_Tree* Node)
{
	free(Node);
}



int main()
{



	return 0;
}