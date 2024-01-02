#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
#include<vector>
// #include<random>

using namespace std;

#define width 44
#define height 22

void gotoxy(int x, int y)
{
    COORD pos = { x * 2, y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

enum Dir
{
    UP = 'W', up = 'w',
    DOWN = 'S', down = 's',
    LEFT = 'A', left = 'a',
    RIGHT = 'D', right = 'd'
};

enum object
{
    snake_head,
    snake_body,
    food
};

void print_object(object obj)
{
    switch (obj)
    {
    case snake_head:
        cout << "б█";
        break;
    case snake_body:
        cout << "б▄";
        break;
    case food:
        cout << "в╛";
        break;
    }
}

class Snake_Head
{
    Snake_Head(int x, int y) : x(x), y(y), dir(Dir::right) {}

    /*void Update()
    {
        time_t pre_time;
        time_t cur_time;
        char input = '\0';

        pre_time = clock();

        while (1)
        {
            cur_time = clock();
            time_t time = cur_time - pre_time;

            if (_kbhit())
            {
                input = _getch();

                switch (input)
                {
                case Dir::UP:
                case up:
                    AddMove(0, -1);
                    break;

                case LEFT:
                case Dir::left:
                    AddMove(-1, 0);
                    break;

                case RIGHT:
                case Dir::right:
                    AddMove(+1, 0);
                    break;

                case DOWN:
                case down:
                    AddMove(0, +1);
                    break;
                }
                break;
            }
        }
    }*/

    bool AddMove(int x, int y)
    {
        bool result = true;

        if (this->x + x >= 2 && this->x + x <= 40) this->x += x;
        else result = false;

        if (this->y + y >= 1 && this->y + y <= 20) this->y += y;
        else result = false;

        return result;
    }

    void print_head()
    {
        gotoxy(x, y);
        print_object(snake_head);
    }

private:
    Dir dir;
    int x;
    int y;
};

class Food
{
public:
    Food(int x, int y) : x(x), y(y) {}

    void rand_food()
    {
        srand(time(NULL));
        int x = rand() % 20 + 1;
        int y = rand() % 20 + 1;
    }

    void print_food()
    {
        rand_food();
        gotoxy(.x, food.y);
        print_object(food);
    }


private:
    int x;
    int y;
};

int main() {
    //system("mode con: cols=44 lines=35");
    //Snake_Head snake_head(10,11);

    for (int x = 0; x < width; x += 2)
        cout << "бс";
    cout << endl;

    for (int y = 1; y < height - 1; y++)
        for (int x = 0; x < width; x += 2)
            if (x == 0 || x == width - 2)
            {
                gotoxy(x / 2, y);
                cout << "бс";
            }
    cout << endl;

    for (int x = 0; x < width; x += 2)
        cout << "бс";

    Food food(0, 0);
    food.rand_food();
    food.print_food();

    gotoxy(0, 25);

    return 0;
}