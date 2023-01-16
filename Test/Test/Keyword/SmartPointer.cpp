#include <iostream>
#include <memory>

void DoSomething(std::weak_ptr<float> value)
{
	*value.lock().get() = 10.0f;
}

int main()
{
	std::shared_ptr<float> shared_value = std::make_shared<float>(5.0f);
	DoSomething(shared_value);

	std::cout << *shared_value << std::endl;


	return 0;
}