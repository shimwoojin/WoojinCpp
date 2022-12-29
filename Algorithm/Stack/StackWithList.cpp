#include <iostream>

struct Node
{
	const char* data;
	Node* NextNode;
};

struct LinkedListStack
{
	Node* List;
	Node* Top;
};

using LLS  = LinkedListStack;

void LLS_CreateStack(LLS** stack)
{
	(*stack) = (LLS*)malloc(sizeof(LLS));
	(*stack)->List = nullptr;
	(*stack)->Top = nullptr;
}

int LLS_IsEmptyStack(LLS* stack)
{
	return (stack->Top == nullptr);
}

//void LLS_DestroyStack(LLS* stack)
//{
//	while (!LLS_IsEmpty(stack))
//	{
//		Node* Popped = LLS_Pop(stack);
//		LLS_DestryNode(Popped);
//	}
//}

int main()
{




	return 0;
}