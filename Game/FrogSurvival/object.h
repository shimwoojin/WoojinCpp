//object.h

#pragma once

class Monster;
class Item;
class Snake;
class Player;

enum class Direct { up = 1, down, left, right };

struct Location
{
	int x;
	int y;
};

class Object
{
public:
	Object() : loc{ 1,1 } {}
	Object(int x, int y) : loc{ x,y } {}
	virtual ~Object() {}
	
	virtual void print_object() = 0;

	virtual void move();

protected:
	Location loc;
	void move_strict();
private:

};

class Player : public Object
{
public:
	Player() : attack_range(5), attack_width(0), life(true), Object(20,10) {}

	virtual void print_object() override;

	//action
	void attack(Monster& m);
	void getItem(Item& item);
	int colision_snake(Snake& s);

	//setter
	void Dead() { life = false; }
	//getter
	bool isLifeOn() const { return life; }

private:
	int attack_range;
	int attack_width;
	bool life;

	void print_attack(Direct);
};

class Monster : public Object
{
public:
	Monster() : hp(5), Object(1,1), life(true) {
		make_random(&loc.x, 10, 40);
		make_random(&loc.y, 5, 35);
	}
	Monster(int x,int y) : hp(5), Object(x,y), life(true) {	}

	virtual void print_object() override;

	virtual void move();

	void dead() { life = false; }

	//getter
	int get_x() { return loc.x; }
	int get_y() { return loc.y; }
	bool isLifeOn() { return life; }

private:
	int hp;
	bool life;
};

class Item : public Object
{
public:
	Item();
	~Item() {}

	//override
	virtual void print_object() override;
	virtual void move() { /*..empty..*/ }
	
	//getter
	const bool& isExist() const { return exist; }
	const int get_x() const { return loc.x; }
	const int get_y() const { return loc.y; }
	const bool get_width() const { return width; }
	const bool get_range() const { return range; }
	//setter
	void Use() { exist = false; }
	void SetErase();

	void EraseItem() { 
		SetErase();
		if (erase - make > 7000) { Use(); }
	}


private:
	bool exist;
	time_t make;
	time_t erase;
	struct {
		bool width;
		bool range;
	};
};


class Snake
{
public:
	struct Node
	{
		int x;
		int y;
		Node* next;
	};
public:
	Snake() { initialize(7); }
	~Snake() { delete[] body; }

	void move();
	void body_move(const int beforeHeadX, const int beforeHeadY);

	void print_object() const;
	void move_strict();
	
	//getter
	int get_size() const { return size; }
	int get_headX() const { return head.x; }
	int get_headY() const { return head.y; }
	Node* get_body() const { return body; }

private:
	Node head;
	Node* body;
	int size;

	void initialize(int size);
};