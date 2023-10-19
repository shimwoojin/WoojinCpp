#include <iostream>
#include <fstream>
#include <memory>
#include <windows.h>
#include <vector>
#include "voca.h"
#include "SetFunc.h"

int main()
{
	std::vector<Voca> voca_out;
	std::vector<Voca> voca_in;

	SetConsoleView();

	std::ofstream fout;
	std::ifstream fin;

	while (true)
	{
		system("cls");
		PrintMain();

		read_voca(voca_in, fin);

		//==================================================
		// ����� ���� 1,2,3,0
		std::cout << "1. ���� ���� �ܾ� Ȯ��" << std::endl;
		std::cout << "2. ���ο� �ܾ� ����" << std::endl;
		std::cout << "3. ���� ���� (5����)" << std::endl;
		std::cout << "0. ���α׷� ����" << std::endl << std::endl;
		int Programoff = -1;

		int choice;
		std::cin >> choice;
		Programoff = choice;
		if (Programoff == 0) break;

		//==================================================
		// action 1,2,3,0
		enum class Choice { Confirm = 1, New, Test };

		switch (static_cast<Choice>(choice))
		{
		case Choice::Confirm:	//�ܾ� Ȯ��
		{
			for (int i = 0; i < voca_in.size(); i++)
			{
				std::cout << voca_in[i] << std::endl;
			}
		}
		break;
		case Choice::New:		//�� �ܾ� �Է�
		{
			fout.open("Vocabulary.txt", std::ios::app);

			Voca v;
			make_voca(v);
			voca_out.push_back(v);
			fout << voca_out.back() << std::endl;

			fout.close();

		}
		break;
		case Choice::Test:		// ���� ����
		{
			int count = 0;

			for (int i = 0; i < 5; i++)
			{
				int ranIndex = 0, ranLanguage = 0;
				make_random(&ranIndex, 0, voca_in.size() - 1);
				make_random(&ranLanguage, 0, 1);
				if (ranLanguage == 0)
				{
					std::string korean;
					std::cout << voca_in[ranIndex].get_english() << std::endl;
					std::cout << "�ѱ� ���� �Է��Ͻÿ� : ";
					std::cin >> korean;
					if (korean == voca_in[ranIndex].get_korean())
					{
						std::cout << "�����Դϴ�!!" << std::endl << std::endl;
						count++;
					}
					else
						std::cout << "�����Դϴ�!! �� �����ϼ���" << std::endl << std::endl;
				}
				else
				{
					std::string english;
					std::cout << voca_in[ranIndex].get_korean() << std::endl;
					std::cout << "���� ���� �Է��Ͻÿ� : ";
					std::cin >> english;
					if (english == voca_in[ranIndex].get_english())
					{
						std::cout << "�����Դϴ�!!" << std::endl << std::endl;
						count++;
					}
					else
						std::cout << "�����Դϴ�!! �� �����ϼ���" << std::endl << std::endl;
				}
			}
			std::cout << "�� ���� ������ 5���� �� " << count << "���� �Դϴ�" << std::endl;
		}
		break;
		default:
			break;
		}
		//================================================= 
		system("pause");
	}

	return 0;
}