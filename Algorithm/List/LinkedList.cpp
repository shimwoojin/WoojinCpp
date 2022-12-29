#include <iostream>

struct Node
{
	int data;
	Node* NextNode;
};

Node* SLL_CreateNode(int newData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->data = newData;
	NewNode->NextNode = nullptr;

	return NewNode;
}

void SLL_DestoryNode(Node* Node)
{
	free(Node);
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	if ((*Head) == NULL)
	{
		*Head = NewNode;
	}
	else
	{
		Node* Tail = (*Head);
		while (Tail->NextNode != NULL)
		{
			Tail = Tail->NextNode;
		}
		
		Tail->NextNode = NewNode;
	}
}

Node* SLL_GetNodeAt(Node* Head, int Location)
{
	Node* Current = Head;

	while (Current != nullptr && (--Location) >= 0)
	{
		Current = Current->NextNode;
	}

	return Current;
}

void SLL_RemoveNode(Node** Head, Node* Remove)
{
	if (*Head == Remove)
	{
		*Head = Remove->NextNode;
	}
	else
	{
		Node* Current = *Head;
		while (Current != nullptr && Current->NextNode != Remove)
		{
			Current = Current->NextNode;
		}
		if (Current != nullptr)
			Current->NextNode = Remove->NextNode;
	}
}

void SLL_FreeNode(Node* head)
{
	Node* temp;

	while (head != nullptr)
	{
		temp = head->NextNode;
		SLL_DestoryNode(head);
		head = temp;
	}
}

int main()
{
	Node* head = SLL_CreateNode(15);

	SLL_AppendNode(&head, SLL_CreateNode(10));
	SLL_AppendNode(&head, SLL_CreateNode(12));
	SLL_AppendNode(&head, SLL_CreateNode(13));
	SLL_AppendNode(&head, SLL_CreateNode(14));

	Node* temp = head;

	Node* at = SLL_GetNodeAt(head, 0);

	std::cout << at->data << std::endl;

	SLL_FreeNode(head);

	return 0;
}