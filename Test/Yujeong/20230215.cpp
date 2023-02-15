#include<iostream>

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr;
	Node* prev = nullptr;
};

int main()
{
	int int_array[100] = { 0 };
	//이렇게 선언하면 정적배열로 int형 공간 100개, 메모리 상에서 400byte 쭉 이어서 int형 100개 저장 가능

	int_array[50];	//임의접근했다고 해
	//인덱스로 배열의 시작주소에서부터 4 * 50 바이트만큼 떨어진 위치로 바로 갔지 ?


	//Node First;	

	Node* First = new Node();

	Node* head = First;

	Node Second;
	Node Third;
	Node* tail = &Third;

	//First.data = 10;
	//First.next = &Second;
	//
	//Second.prev = &First;
	Second.data = 20;
	Second.next = &Third;

	&Third;	//메모리상에서 실제 얘의 주소, 즉 숫자임

	//first라는 놈만 내가 알고있을거고
	//first를 통해서 second, third까지 다 순차적으로 접근하겠다
	//이 개념이 리스트


	//포인터라는건 0~4Gbyte 사이의 숫자를 보관하는 변수
	//포인터가 변순데
	//포인터가 숫자를 보관하는 변수지
	//포인터도 메모리상에 주소가 있지 ?
	//그 포인터의 주소를 보관하는게 이중포인터고

	int a;

	

	return 0;
}