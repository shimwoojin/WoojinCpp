#include <iostream>
enum class Dir{up,down,left,right};

class Snake
{
public:

	// 6����
	// 01_����Ʈ ������
	// 02_���� ������ / 05_���� ���� ������
	// 03_�̵� ������ / 06_�̵� ���� ������
	// 04_�Ҹ���

	//01_����Ʈ ������
	Snake() : x(10),y(10),dir(Dir::right) {}
	//01_1_�Ű������� �ִ� ������
	Snake(int x, int y, Dir dir) : x(x), y(y), dir(dir) {}

	//02_���� ������
	Snake(const Snake& snake) 
	{
		x = snake.x;
		y = snake.y;
		dir = snake.dir;
	}

	//05_
	Snake operator=(const Snake& snake) {}

	//03_�̵� ������
	Snake(Snake&& snake)
	{
		x = snake.x;
		y = snake.y;
		dir = snake.dir;
	}

	//06_
	Snake operator=(const Snake&& snake) {}

	//04_�Ҹ���
	~Snake() {}

	//getter
	int getX() const { return x; }
	int getY() const { return y; }

	//setter
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }

private:
	Dir dir;
	int x;
	int y;
};

struct Position
{
	int x;
	int y;
};

int main()
{
	/*Snake() : x(10),y(10),dir(Dir::right) {}*/
	using namespace std;
	//Snake snake;
	//Snake snake2;

	//snake = snake2;
	//
	//cout << snake.getX() << endl;
	//cout << snake.getY() << endl;

	//snake.setX(20);
	//cout << snake.getX() << endl;
	//snake.setY(30);
	//cout << snake.getY() << endl;

	//01_ ����Ʈ ������
	Snake snake;

	Snake snake5(10, 20, Dir::right);

	//02_ ���� ������
	Snake snake2(snake);

	//03_ �̵� ������
	Snake snake3(std::move(snake));

	//04_�Ҹ���
	//

	//05_���� ���� ������
	snake2 = snake;

	//06_�̵� ���� ������
	snake2 = std::move(snake);

	return 0;
}