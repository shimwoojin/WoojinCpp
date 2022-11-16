#pragma once

class Monster
{
public:
	virtual ~Monster() {}
	virtual Monster* clone() = 0;
};

class Ghost : public Monster
{
public:
	Ghost(int health, int speed)
		: health_(health),
		speed_(speed) {}
	virtual Monster* clone();

private:
	int health_;
	int speed_;
};


//typedef Monster* (*SpawnCallback)();
//
//class Spawner 
//{
//public:
//	Spawner(SpawnCallback spawn) : spawn_(spawn) {}
//	Monster* spawnMonster();
//
//private:
//	SpawnCallback spawn_;
//};

class Spawner
{
public:
	virtual ~Spawner() {}
	virtual Monster* spawnMonster() = 0;
};

template <class T>
class SpawnerFor : public Spawner
{
public:
	virtual Monster* spawnMonster() override { return new T(15,3); }
};

Monster* spawnGhost();