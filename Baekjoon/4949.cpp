#include <iostream>
#include <stack>
#include <string>

int main()
{
	while (true)
	{
		std::string line;
		std::stack<char> balanced;
		std::getline(std::cin, line);

		if (line[0] == '.')
		{
			break;
		}

		int i = 0;

		for (i = 0; i < line.size(); i++)
		{
			if (line[i] == '.') break;
			if (line[i] == '(' || line[i] == '[')
			{
				balanced.push(line[i]);
			}
			if (line[i] == ')')
			{
				if (balanced.empty() == false && balanced.top() == '(')
						balanced.pop();
				else
				{
					std::cout << "no" << std::endl;
					break;
				}
			}
			if (line[i] == ']')
			{
				if (balanced.empty() == false && balanced.top() == '[')
					balanced.pop();
				else
				{
					std::cout << "no" << std::endl;
					break;
				}
			}
		}

		if (balanced.empty() == true && line[i] == '.')
			std::cout << "yes" << std::endl;
		else if(balanced.empty() == false && line[i] == '.')
			std::cout << "no" << std::endl;
	}

	return 0;
}