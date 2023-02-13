#include <iostream>
#include <stack>
#include <string>

int main()
{
	//갯수 및 갯수만큼 문자열 입력받기
	int num = 0;

	std::cin >> num;

	char** sentences = new char*[num];
	char** sentences_result = new char* [num];

	for (int i = 0; i < num; i++)
	{
		sentences[i] = new char[1000];
		sentences_result[i] = new char[1000];
	}

	std::cin.ignore();

	for (int i = 0; i < num; i++)
	{
		std::cin.getline(sentences[i], 1000);
	}

	//실제 내용
	//TODO::
	std::stack<char> reverse;

	for (int i = 0; i < num; i++)
	{
		while (*sentences[i] != '\0')
		{
			while (*sentences[i] != ' ')
			{
				reverse.push(*sentences[i]);
				sentences[i]++;
			}

			while (reverse.empty() != true)
			{
				*sentences_result[i] = reverse.top();
				reverse.pop();
				sentences_result[i]++;
			}

			*sentences_result[i] = ' ';
			sentences_result[i]++;
		}
	}

	//결과 출력
	for (int i = 0; i < num; i++)
	{
		std::cout << sentences_result[i] << std::endl;
	}


	//위 동적할당 해제
	for (int i = 0; i < num; i++)
	{
		delete sentences[i];
	}
	delete[] sentences;

	return 0;
}

