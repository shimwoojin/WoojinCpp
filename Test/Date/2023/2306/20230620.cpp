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
			// va_arg(arg_list, int) : arg_list에서 4바이트(int크기)만큼 역참조하며 데이터를 가져온 뒤
			//							arg_list를 4바이트(int크기)만큼 이동시킴-> 다음 가변 인자의 시작위치로 이동시킴
			int num = va_arg(arg_list, int);

			printf("%d ", num);
		}
		printf("\n");

		// va_end() : 해당 가변 인자 포인터를 nullptr로 초기화
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