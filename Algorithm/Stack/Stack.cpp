//stack with array 동적할당

#include <iostream>

typedef int ElementType;

struct Node
{
	ElementType Data;
};

struct Stack
{
	int capacity;
	int Top;
	Node* Nodes;
};

void AS_CreateStack(Stack** stack, int Capacity)
{
	(*stack) = (Stack*)malloc(sizeof(Stack));
	(*stack)->Nodes = (Node*)malloc(sizeof(Node) * Capacity);

	(*stack)->capacity = Capacity;
	(*stack)->Top = 0;
}

void AS_DestroyStack(Stack* stack)
{
	free(stack->Nodes);
	free(stack);
}

void AS_Push(Stack* stack, ElementType data)
{
	int Position = stack->Top;

	stack->Nodes[Position].Data = data;
	stack->Top++;
}

ElementType As_Pop(Stack* stack)
{
	int position = --(stack->Top);

	return stack->Nodes[position].Data;
}

int main()
{
	Stack* stack;

	AS_CreateStack(&stack, 50);

	AS_Push(stack, 10);
	AS_Push(stack, 20);
	AS_Push(stack, 30);
	AS_Push(stack, 40);
	AS_Push(stack, 50);
	AS_Push(stack, 60);

	std::cout << stack->Nodes[2].Data << std::endl;

	std::cout << As_Pop(stack) << std::endl;
	std::cout << As_Pop(stack) << std::endl;
	std::cout << As_Pop(stack) << std::endl;
	std::cout << As_Pop(stack) << std::endl;

	return 0;
}