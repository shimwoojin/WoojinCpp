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
		// 사용자 선택 1,2,3,0
		std::cout << "1. 여태 적은 단어 확인" << std::endl;
		std::cout << "2. 새로운 단어 적기" << std::endl;
		std::cout << "3. 시험 보기 (5문제)" << std::endl;
		std::cout << "0. 프로그램 종료" << std::endl << std::endl;
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
		case Choice::Confirm:	//단어 확인
		{
			for (int i = 0; i < voca_in.size(); i++)
			{
				std::cout << voca_in[i] << std::endl;
			}
		}
		break;
		case Choice::New:		//새 단어 입력
		{
			fout.open("Vocabulary.txt", std::ios::app);

			Voca v;
			make_voca(v);
			voca_out.push_back(v);
			fout << voca_out.back() << std::endl;

			fout.close();

		}
		break;
		case Choice::Test:		// 시험 보기
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
					std::cout << "한글 뜻을 입력하시오 : ";
					std::cin >> korean;
					if (korean == voca_in[ranIndex].get_korean())
					{
						std::cout << "정답입니다!!" << std::endl << std::endl;
						count++;
					}
					else
						std::cout << "오답입니다!! 더 공부하세요" << std::endl << std::endl;
				}
				else
				{
					std::string english;
					std::cout << voca_in[ranIndex].get_korean() << std::endl;
					std::cout << "영어 뜻을 입력하시오 : ";
					std::cin >> english;
					if (english == voca_in[ranIndex].get_english())
					{
						std::cout << "정답입니다!!" << std::endl << std::endl;
						count++;
					}
					else
						std::cout << "오답입니다!! 더 공부하세요" << std::endl << std::endl;
				}
			}
			std::cout << "총 맞힌 문제는 5문제 중 " << count << "문제 입니다" << std::endl;
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