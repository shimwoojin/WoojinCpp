#include <iostream>
#include <thread>
#include <windows.h>
#include <ctime>

//�޸� : decay_t<>	//���ø� ��� �� ���۷����� �����ִ� (�ڷ��� ������ ã���ִ�)
//�޸� : std::forward	//����Ʈ ������ Ű����

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