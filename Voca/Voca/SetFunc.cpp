#include <windows.h>
#include <iostream>
#include <random>
#include <fstream>
#include "SetFunc.h"
#include "voca.h"


void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void SetConsoleView()
{
	system("mode con:cols=40 lines=40");
	system("title MadeByShimwoojin");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 0b1110'0000);
}

void PrintMain()
{
	std::cout << "=====================================" << std::endl;
	std::cout << "            Vocabulary list          " << std::endl;
	std::cout << "=====================================" << std::endl;
}

void make_random(int* random, int start, int end)
{
	std::random_device rd;
	std::mt19937_64 merssenne(rd());

	std::uniform_int_distribution<> random_(start, end);

	*random = random_(merssenne);
}

void make_voca(Voca& v)
{
	std::string english;
	std::string korean;
	std::cout << "영어 단어를 쓰시오 : ";
	std::cin >> english;
	std::cout << "한글 뜻을 쓰시오 : ";
	std::cin >> korean;
	v.write_english(english);
	v.write_korean(korean);
}

void read_voca(std::vector<Voca>& voca_in, std::ifstream& fin )
{
	//파일 open 후 voca_in에 단어 정보 입력
	fin.open("Vocabulary.txt");


	if (fin.fail())
	{
		std::cerr << "파일을 찾을 수 없음" << std::endl;
		exit(100);
	}

	voca_in.clear();	//벡터 원소 모두 제거

	while (!fin.eof())
	{
		std::string english;
		std::string korean;
		Voca v;
		fin >> english >> korean;
		v.write_english(english);
		v.write_korean(korean);
		voca_in.push_back(v);

	}
	fin.close();
}