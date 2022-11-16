//Object.h

#pragma once
#include <vector>

class Item;

class Object
{
public:
	Object() : position{ 10,10 } {}
	Object(int x, int y) : position{ x, y } {}
	virtual ~Object() {}
	virtual void printObject() const = 0;

protected:
	struct Position { int x; int y; };
	Position position;
};

class Snake final  : public Object
{
	enum class Direct { up, down, left ,right };
public:
	Snake() = delete;
	Snake(int size)
		: Object(), direct(Direct::right), body{}, size(size), position_before{ position.x, position.y }, is_dead(false)
	{
		makeBody(size);
	}
	Snake(int x, int y, int size)
		: Object(x, y), direct(Direct::up), body{}, size(size), position_before{ position.x, position.y }, is_dead(false)
	{
		makeBody(size);
	}
	virtual ~Snake() {	}
	virtual void printObject() const override;

	//update
	void update(Item& item);


	//getter
	int getSize() const { return size; }
	bool getIsDead() const { return is_dead; }

private:
	//setter
	void setDirect();
	void move();
	void sizeUp(int size) { this->size += size; }
	
	bool isOutOfBound();
	void makeBody(int size);
	void bodyFollowHead();
	void isCollision(class Item& item);
	bool isCollision();
	void bodyAddOne();
	
private:
	Direct direct;
	Position position_before;
	std::vector<Position> body;
	int size;
	bool is_dead;
};

class Item final : public Object
{
public:
	Item();

	virtual void printObject() const override;

	//setter
	void setIsUsed(bool isused) { isUsed = isused; }
	void setVisible(bool visible) { this->visible = visible; }

	//getter
	int getX() const { return position.x; }
	int getY() const { return position.y; }
	bool getIsUsed() const { return isUsed; }
	bool getVisible() const { return visible; }
private:
	bool isUsed;
	bool visible;
};