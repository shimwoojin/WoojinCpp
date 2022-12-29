#include <iostream>

struct Node
{
	int Data;
	Node* PrevNode;
	Node* NextNode;
};

Node* DLL_CreateNode(int newData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = newData;
	NewNode->PrevNode = nullptr;
	NewNode->NextNode = nullptr;

	return NewNode;
}

void DLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == nullptr)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);

		while (Tail->NextNode != nullptr)
		{
			Tail = Tail->NextNode;
		}
		Tail->NextNode = NewNode;
		NewNode->PrevNode = Tail;
	}
}

Node* DLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

void DLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
		if (*Head != nullptr)	(*Head)->PrevNode = nullptr;
		
		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
	}
	else
	{
		Node* temp = Remove;

		Remove->PrevNode->NextNode = temp->NextNode;
		if (Remove->NextNode != nullptr) Remove->NextNode->PrevNode = temp->PrevNode;

		Remove->PrevNode = nullptr;
		Remove->NextNode = nullptr;
	}
}

void DLL_DestroyNode(Node* Node)
{
	free(Node);
}

void DLL_Free_Node(Node* Head)
{
	Node* temp = nullptr;

	while (Head != nullptr)
	{
		temp = Head->NextNode;
		DLL_DestroyNode(Head);
		Head = temp;
	}
}

void DLL_Print_All_Data(const Node* Head)
{
	const Node* temp = Head;
	while (temp != nullptr)
	{
		std::cout << temp->Data << std::endl;
		temp = temp->NextNode;
	}
}

int main()
{
	Node* Head = DLL_CreateNode(1);

	DLL_AppendNode(&Head, DLL_CreateNode(2));
	DLL_AppendNode(&Head, DLL_CreateNode(3));
	DLL_AppendNode(&Head, DLL_CreateNode(4));
	DLL_AppendNode(&Head, DLL_CreateNode(5));
	DLL_AppendNode(&Head, DLL_CreateNode(6));
	DLL_AppendNode(&Head, DLL_CreateNode(7));

	DLL_Print_All_Data(Head);

	DLL_Free_Node(Head);

	return 0;
}