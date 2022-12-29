#include <iostream>

typedef int Elementtype;

struct Node
{
	Elementtype Data;
};

struct CircularQueue
{
	int Capacity;
	int Front;
	int Rear;
	Node* Nodes;
};

void CQ_CreateQueue(CircularQueue** Queue, int Capacity)
{
	(*Queue) = (CircularQueue*)malloc(sizeof(CircularQueue));

	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Capacity+1));

	(*Queue)->Capacity = Capacity;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
}

void CQ_DestroyNode(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, Elementtype Data)
{
	int position = 0;

	if (Queue->Rear == Queue->Capacity)
	{
		position = Queue->Rear;
		Queue->Rear = 0;
	}
	else
		position = Queue->Rear++;

	Queue->Nodes[position].Data = Data;
}

Elementtype CQ_Dequeue(CircularQueue* Queue)
{
	int position = Queue->Front;

	if (Queue->Front == Queue->Capacity)
		Queue->Front = 0;
	else
		Queue->Front++;

	return Queue->Nodes[position].Data;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
	return (Queue->Front == Queue->Rear);
}

int CQ_IsFull(CircularQueue* Queue)
{
	if (Queue->Front < Queue->Rear)
		return (Queue->Rear - Queue->Front) == Queue->Capacity;
	else
		return (Queue->Rear + 1) == Queue->Front;
}

int main()
{
	CircularQueue* Queue = nullptr;

	CQ_CreateQueue(&Queue, 30);

	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);
	CQ_Enqueue(Queue, 5);
	
	for (int i = 0; i < 4; i++)
	{
		std::cout << i << " : "<< CQ_Dequeue(Queue) << std::endl;
		std::cout << "Front : " << Queue->Front << ", " << Queue->Rear << std::endl;
	}


	return 0;
}