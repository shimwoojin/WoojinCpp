#include <iostream>
#include <thread>
#include <mutex>
#include <functional>

thread_local int i = 0;

void OnThread(int id, std::mutex& m)
{
	m.lock();
	{
		++i;
		std::cout << id << " : " << i << std::endl;
	}
	m.unlock();
}

int main()
{
	std::mutex m;

	std::thread t1(std::bind(OnThread, 1, std::ref(m)));
	std::thread t2(std::bind(OnThread, 2, std::ref(m)));

	m.lock();
	{
		++i;
		++i;
		++i;
		std::cout << "main" << " : " << i << std::endl;
	}
	m.unlock();

	t1.join();
	t2.join();

	return 0;
}