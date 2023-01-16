#include <iostream>
#include <memory>

std::weak_ptr<int> test(std::shared_ptr<int> other)
{
	std::weak_ptr<int> wp(other);
	
	if (*wp.lock().get() == 1)
	{
		std::cout << "weak �����ʹ� 1�Դϴ�" << std::endl;
		return wp;
	}
	else if (*other.get() == 2)
	{
		std::cout << "sp�� 2�Դϴ�" << std::endl;
		return wp;
	}
	else if (*other.get() == 3)
	{
		std::cout << "sp�� 3�Դϴ�" << std::endl;
		return wp;
	}
	else
	{
		std::cout << "�̻��� ���Դϴ�" << std::endl;
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