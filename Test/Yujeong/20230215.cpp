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
	//�̷��� �����ϸ� �����迭�� int�� ���� 100��, �޸� �󿡼� 400byte �� �̾ int�� 100�� ���� ����

	int_array[50];	//���������ߴٰ� ��
	//�ε����� �迭�� �����ּҿ������� 4 * 50 ����Ʈ��ŭ ������ ��ġ�� �ٷ� ���� ?


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

	&Third;	//�޸𸮻󿡼� ���� ���� �ּ�, �� ������

	//first��� �� ���� �˰������Ű�
	//first�� ���ؼ� second, third���� �� ���������� �����ϰڴ�
	//�� ������ ����Ʈ


	//�����Ͷ�°� 0~4Gbyte ������ ���ڸ� �����ϴ� ����
	//�����Ͱ� ������
	//�����Ͱ� ���ڸ� �����ϴ� ������
	//�����͵� �޸𸮻� �ּҰ� ���� ?
	//�� �������� �ּҸ� �����ϴ°� ���������Ͱ�

	int a;

	

	return 0;
}