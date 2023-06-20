#include <iostream>
#include <cstdarg>

class Test
{
public:
	void __stdcall PrintTest(int arg_count, ...)
	{
		va_list arg_list;

		va_start(arg_list, arg_count);

		for (int i = 0; i < arg_count; i++)
		{
			// va_arg(arg_list, int) : arg_list���� 4����Ʈ(intũ��)��ŭ �������ϸ� �����͸� ������ ��
			//							arg_list�� 4����Ʈ(intũ��)��ŭ �̵���Ŵ-> ���� ���� ������ ������ġ�� �̵���Ŵ
			int num = va_arg(arg_list, int);

			printf("%d ", num);
		}
		printf("\n");

		// va_end() : �ش� ���� ���� �����͸� nullptr�� �ʱ�ȭ
		this->a = 10;

		va_end(arg_list);
	}

	int a = 5;
};

int main()
{
	using namespace std;

	Test t;

	//t.a = 10;
	t.PrintTest(3, 1, 2, 3);

	cout << t.a << endl;


	return 0;
}