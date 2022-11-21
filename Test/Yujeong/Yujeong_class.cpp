#include <iostream>

class CharacterState
{
public:

private:

};

class Character
{
public:
	void setA(int a)
	{
		this->a = a;
	}

	Character& getMY()
	{
		/*
			...
		*/
		return *this;
	}

	Character& add(int a)
	{
		this->a += a;
		return *this;
	}

	//int add(int a)	//int�� ���Ϲ޴� add�Լ��� ���
	//{
	//	this->a += a;
	//	return this->a;	//�� �Լ� ��ü�� ���� �޴� ���� �ڱ� �ڽ��� a��
	//}	//�׷��� �̰� main���� ������� ���Եǳĸ�

	Character& sub(int a)
	{
		this->a -= a;
		return *this;
	}

	Character& mul(int a)
	{
		this->a *= a;
		return *this;
	}

	operator int()
	{
		return a;
	}	//�̰� �ϴ� ������ Character������ ����� ������ int������ ����ȯ�� �� a ���� �ְڴ� �̰Űŵ� ?
	//�̰� tmi�ϼ� �ְ� 
	//��� �Ʒ����� int���� c2.add(3)�̰� int���� �����ϰ� ������ �׳� add�Լ��� �������� int������ ���� �ȴ� ��
	//�ٵ� ?
	//add�Լ��� ��ȯ���� int�� �ϰ� �Ǹ� �Ʊ� c2.add(3).mul(2).sub(3); �̷� ������ �����ŵ� ?
	//�׷��� ��ȯ���� Character&�� �ְ�
	//


	int a;
private:
	//CharacterState* state;
};

int main()
{

	Character c;

	c.a;
	c.setA(1);

	Character c2;
	c2.setA(1);
	std::cout << c2.add(2).mul(3).sub(2) << std::endl;	//1.
	std::cout << c2.a << std::endl;	//2.
	//���۷����� �Ⱥ��̰ԵǸ�
	//�� �ΰ��� �ٸ��� ��
	//�ֳ��ϸ� c2.add(2)�� �ϰ� �� ���� ���ʹ� c2��ü�� �ƴ϶� c2�� ���纻�� add�� ���Ϲ��� ���纻�� �״��� ���꿡 ���Ǵ� �Űŵ�
	//7�̰� 3���� �ٸ��ݾ�
	//ó���� 1�� ���ֵ��� add(2)�ϰ� �� ���� 3�̰�
	//��ư ���� ���۷����� �ٲ㼭 Ȯ���غ���
	//

	int result = c2.add(3);	//int�� ������ �Լ� ����� ���Ϲ��������� ?
	//���� �������� int�� �ƴ϶� Character���ٸ� ?
	//�� ������ �������� ?
	//�����ٰ�

	//�� ���� ���ĸ� int�� ������ result�� Character ������ ���� ������ ?
	//�ٵ� �����Ը� ó���س��� �� ������ ���� �ȳ��� �ϰ�;�
	//�׷��� �ϴ°� �����ٰ�

	//���� ���� ���� c2.add(3)�� �Ͻ������� Character������ int������ ����ȯ �� ���� result�� ���ԵȰ�. ������ ?
	//�ٵ� ���� ���� ������ �Ⱦ� �׷��� static_cast

	result = static_cast<int>(c2.add(3));
	//�̰� ����� ����ȯ

	struct position
	{
		int x;
		int y;
	};

	position pos;

	pos.x = 3;
	pos.y = 5;	//�̰� �׳� ����ü ������ �ٲٴ°��� ?

	//====================================

	position* p_pos = &pos;	//����ü ���� �����Ѱſ� ���� p_pos�� �ٽ� pos�� �ּ� �޾��� ?

	p_pos->x = 3;	//p_pos�� ����ü �����̱� ������ 
	p_pos->y = 5;

	(*p_pos).x = 3;
	(*p_pos).y = 5;

	return 0;
}