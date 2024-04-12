#include <iostream>
#include <chrono>
#include <windows.h>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <cstdio>

_NODISCARD int Add(int a, int b)
{
	return a + b;
}

[[deprecated("This Function will be deprecated at next version")]] void Test()
{
	
}

int main()
{
	{
		int a = Add(3, 5);
		//Add(4, 5);
		//Test();
	}

	{
		std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
		Sleep(500);
		std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();

		std::chrono::system_clock::duration time_diff = end - start;

		std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(time_diff).count();

		time_t time = std::chrono::system_clock::to_time_t(start);
		tm date;
		errno_t error = localtime_s(&date, &time);

		if (error == 0)
		{
			std::cout << "현재 시간은 : " << std::put_time(&date, "%F %T %z")
				<< '\n';
		}
	}

	return 0;
}