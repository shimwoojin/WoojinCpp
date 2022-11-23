#pragma once
#include <string>

class Yujeong
{
public:
	Yujeong(std::string name);

	void printInfo();
	friend std::ostream& operator<<(std::ostream& os, const Yujeong& yujeong);

private:
	std::string name;
};

//이런 클래스를 만들었다 쳐
//저 printInfo에 대해 함수 구현부를 적으려고
//.cpp파일에 구현부를 적으려고 해