#include <iostream>
#include <vector>

struct Pos
{
	Pos(int x, int y) : x(x), y(y) {}

	int x;
	int y;
};

int main()
{
	std::vector<Pos> test;

	//emplace_back을 쓰고 싶으면 구조체여도 생성자 정의해놔야됨
	//위에 Pos(int x, int y)이렇게 인자 2개 넘기는 생성자 있어서 emplace_back 쓸 수 있는거고
	//근데 저렇게 하는거 번거로우면 그냥
	//Push_back(Pos{1,1}); 이런식으로 하는 게 맞음
	test.emplace_back(1, 1);
	test.emplace_back(2, 1);
	test.emplace_back(3, 1);
	test.emplace_back(4, 1);

	using namespace std;

	cout << test[0].x << endl;
	cout << test[0].y << endl;
	cout << test[1].x << endl;
	cout << test[1].y << endl;
	cout << test[2].x << endl;
	cout << test[2].y << endl;
	cout << test[3].x << endl;
	cout << test[3].y << endl;

	return 0;
}