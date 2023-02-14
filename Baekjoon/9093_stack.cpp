#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
	- window.h ��� �Ұ���
		�� zeromemory ��� �Ұ�
*/

int main()
{
	//���� �� ������ŭ ���ڿ� �Է¹ޱ�
	int num = 0;

	std::cin >> num;

	char** sentences = new char*[num];
	char** sentences_result = new char* [num];

	for (int i = 0; i < num; i++)
	{
		sentences[i] = new char[1000]{ 0 };
		sentences_result[i] = new char[1000]{ 0 };
	}

	std::cin.ignore();

	for (int i = 0; i < num; i++)
	{
		std::cin.getline(sentences[i], 1000);
	}

	//���� ����
	//TODO::
	std::stack<char> reverse;

	for (int i = 0; i < num; i++)
	{
		char* temp = sentences[i];
		char* temp_result = sentences_result[i];
		while ((*(sentences[i]) != '\n') && (*(sentences[i]) != '\0'))
		{
			while ((*(sentences[i]) != ' ') && (*(sentences[i]) != '\0'))
			{
				reverse.push(*sentences[i]);
				sentences[i]++;
			}

			sentences[i]++;

			while (reverse.empty() != true)
			{
				*(sentences_result[i]) = reverse.top();
				reverse.pop();
				sentences_result[i]++;
			}

			*(sentences_result[i]) = ' ';
			sentences_result[i]++;
		}
		*(sentences_result[i]) = '\0';
		sentences[i] = temp;
		sentences_result[i] = temp_result;
	}

	//��� ���
	for (int i = 0; i < num; i++)
	{
		std::cout << sentences_result[i] << std::endl;
	}


	//�� �����Ҵ� ����
	for (int i = num -1; i >= 0; i--)
	{
		delete[] sentences_result[i];
	}
	for (int i = num - 1; i >= 0; i--)
	{
		delete[] sentences[i];
	}
	
	delete[] sentences_result;
	delete[] sentences;

	return 0;
}

//int main()
//{
//    int T;  //���̽� ����
//    cin >> T;
//    cin.ignore();
//
//    for (int i = 0; i < T; i++)
//    {
//        string str("");
//        getline(cin, str);
//        str += ' ';
//
//        stack<char> stack;
//        for (int j = 0; j < str.size(); ++j)
//        {
//            if (str[j] == ' ')
//            {
//                while (stack.empty() != true)
//                {
//                    cout << stack.top();
//                    stack.pop();
//                }
//                cout << ' ';
//            }
//            else
//            {
//                stack.push(str[j]);
//            }
//        }
//        cout << endl;
//    }
//
//    return 0;
//}