#include <iostream>
enum class Dir{up,down,left,right};

class Snake
{
public:

	// 6가지
	// 01_디폴트 생성자
	// 02_복사 생성자 / 05_복사 대입 연산자
	// 03_이동 생성자 / 06_이동 대입 연산자
	// 04_소멸자

	//01_디폴트 생성자
	Snake() : x(10),y(10),dir(Dir::right) {}
	//01_1_매개변수가 있는 생성자
	Snake(int x, int y, Dir dir) : x(x), y(y), dir(dir) {}

	//02_복사 생성자
	Snake(const Snake& snake) 
	{
		x = snake.x;
		y = snake.y;
		dir = snake.dir;
	}

	//05_
	Snake operator=(const Snake& snake) {}

	//03_이동 생성자
	Snake(Snake&& snake)
	{
		x = snake.x;
		y = snake.y;
		dir = snake.dir;
	}

	//06_
	Snake operator=(const Snake&& snake) {}

	//04_소멸자
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

	//01_ 디폴트 생성자
	Snake snake;

	Snake snake5(10, 20, Dir::right);

	//02_ 복사 생성자
	Snake snake2(snake);

	//03_ 이동 생성자
	Snake snake3(std::move(snake));

	//04_소멸자
	//

	//05_복사 대입 연산자
	snake2 = snake;

	//06_이동 대입 연산자
	snake2 = std::move(snake);

	return 0;
}