#include <iostream>
#include <thread>
#include <windows.h>
#include <ctime>

//메모 : decay_t<>	//템플릿 사용 시 래퍼런스를 떼어주는 (자료형 원본을 찾아주는)
//메모 : std::forward	//퍼펙트 포워딩 키워드

void WaitSeconds(int seconds)
{
	std::cout << clock() << std::endl;
	Sleep(seconds * 1000);
	std::cout << clock() << std::endl;
}

int main()
{
	std::cout << "hello world" << std::endl;
	std::thread t1(WaitSeconds, 3);
	std::cout << "hello world2" << std::endl;

	t1.join();

	return 0;
}