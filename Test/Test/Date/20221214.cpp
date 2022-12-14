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

	//emplace_back�� ���� ������ ����ü���� ������ �����س��ߵ�
	//���� Pos(int x, int y)�̷��� ���� 2�� �ѱ�� ������ �־ emplace_back �� �� �ִ°Ű�
	//�ٵ� ������ �ϴ°� ���ŷο�� �׳�
	//Push_back(Pos{1,1}); �̷������� �ϴ� �� ����
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