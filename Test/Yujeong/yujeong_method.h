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

//�̷� Ŭ������ ������� ��
//�� printInfo�� ���� �Լ� �����θ� ��������
//.cpp���Ͽ� �����θ� �������� ��