#include <iostream>
#include <memory>

std::weak_ptr<int> test(std::shared_ptr<int> other)
{
	std::weak_ptr<int> wp(other);
	
	if (*wp.lock().get() == 1)
	{
		std::cout << "weak 포인터는 1입니다" << std::endl;
		return wp;
	}
	else if (*other.get() == 2)
	{
		std::cout << "sp는 2입니다" << std::endl;
		return wp;
	}
	else if (*other.get() == 3)
	{
		std::cout << "sp는 3입니다" << std::endl;
		return wp;
	}
	else
	{
		std::cout << "이상한 값입니다" << std::endl;
		//return {};
		return std::weak_ptr<int>();
	}

	return {};
	//return std::weak_ptr<int>();
}

int main()
{
	std::shared_ptr<int> sp = std::make_shared<int>(0);

	auto out_wp = test(sp);

	if(out_wp.expired() == false)
		std::cout << *out_wp.lock().get() << std::endl;

	return 0;
}