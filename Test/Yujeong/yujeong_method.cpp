#include <iostream>
#include <string>
#include "yujeong_method.h"

Yujeong::Yujeong(std::string name)
	: name(name)
{
}

void Yujeong::printInfo()	//함수 이름 앞에 Yujeong:: 이렇게 클래스의 네임스페이스가 붙지 ?
//이게 메소드이기 때문이야
//Yujeong이라는 클래스안에서 쓰려고 만든 함수이기 때문에
//메소드가 아닌 예를 보여줄게
{


}

std::ostream& operator<<(std::ostream& os, const Yujeong& yujeong)
//이거 같은 경우는 Yujeong:: 네임스페이스가 안 따라붙었지 ?
//이걸 사용하게 되면 Yujeong의 메소드를 사용하는게 아닌
//ostream 객체랑 Yujeong 객체를 매개변수로 받는
//전역함수를 사용하게 되는 것
//사용하는 걸 보여주면
{
	os << yujeong.name;
	return os;
}
