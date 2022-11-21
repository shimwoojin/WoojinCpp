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

	//int add(int a)	//int를 리턴받는 add함수를 썼어
	//{
	//	this->a += a;
	//	return this->a;	//이 함수 자체가 리턴 받는 값은 자기 자신의 a야
	//}	//그래서 이걸 main에서 어떤식으로 쓰게되냐면

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
	}	//이게 하는 역할은 Character형으로 선언된 본인이 int형으로 형변환될 때 a 값을 주겠다 이거거든 ?
	//이건 tmi일수 있고 
	//사실 아래에서 int형에 c2.add(3)이걸 int형에 대입하고 싶을땐 그냥 add함수의 리턴형을 int형으로 쓰면 된단 뜻
	//근데 ?
	//add함수의 반환형을 int로 하게 되면 아까 c2.add(3).mul(2).sub(3); 이런 문장은 못쓰거든 ?
	//그러면 반환형은 Character&로 주고
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
	//래퍼런스를 안붙이게되면
	//이 두개가 다르게 돼
	//왜냐하면 c2.add(2)를 하고 난 다음 부터는 c2자체가 아니라 c2의 복사본인 add를 리턴받은 복사본이 그다음 연산에 사용되는 거거든
	//7이고 3으로 다르잖아
	//처음에 1로 들어가있따가 add(2)하고 난 값이 3이고
	//암튼 저걸 래퍼런스로 바꿔서 확인해보면
	//

	int result = c2.add(3);	//int형 변수에 함수 결과를 리턴받을수있지 ?
	//만약 리턴형이 int가 아니라 Character였다면 ?
	//이 문장이 오류겠지 ?
	//보여줄게

	//왜 오류 나냐면 int형 변수인 result는 Character 변수를 대입 못받지 ?
	//근데 저렇게만 처리해놓고 저 문장을 오류 안나게 하고싶어
	//그럴때 하는걸 보여줄게

	//지금 같은 경우는 c2.add(3)가 암시적으로 Character형에서 int형으로 형변환 된 다음 result에 대입된거. 뭔말알 ?
	//근데 나는 저런 문장이 싫어 그럴때 static_cast

	result = static_cast<int>(c2.add(3));
	//이게 명시적 형변환

	struct position
	{
		int x;
		int y;
	};

	position pos;

	pos.x = 3;
	pos.y = 5;	//이건 그냥 구조체 변수값 바꾸는거지 ?

	//====================================

	position* p_pos = &pos;	//구조체 변수 선언한거에 대해 p_pos로 다시 pos의 주소 받았지 ?

	p_pos->x = 3;	//p_pos가 구조체 변수이기 때문에 
	p_pos->y = 5;

	(*p_pos).x = 3;
	(*p_pos).y = 5;

	return 0;
}