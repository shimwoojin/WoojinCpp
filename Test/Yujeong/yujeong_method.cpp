#include <iostream>
#include <string>
#include "yujeong_method.h"

Yujeong::Yujeong(std::string name)
	: name(name)
{
}

void Yujeong::printInfo()	//�Լ� �̸� �տ� Yujeong:: �̷��� Ŭ������ ���ӽ����̽��� ���� ?
//�̰� �޼ҵ��̱� �����̾�
//Yujeong�̶�� Ŭ�����ȿ��� ������ ���� �Լ��̱� ������
//�޼ҵ尡 �ƴ� ���� �����ٰ�
{


}

std::ostream& operator<<(std::ostream& os, const Yujeong& yujeong)
//�̰� ���� ���� Yujeong:: ���ӽ����̽��� �� ����پ��� ?
//�̰� ����ϰ� �Ǹ� Yujeong�� �޼ҵ带 ����ϴ°� �ƴ�
//ostream ��ü�� Yujeong ��ü�� �Ű������� �޴�
//�����Լ��� ����ϰ� �Ǵ� ��
//����ϴ� �� �����ָ�
{
	os << yujeong.name;
	return os;
}
