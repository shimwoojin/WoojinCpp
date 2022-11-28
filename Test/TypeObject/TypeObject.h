#pragma once

class Breed
{
public:
	Breed(int health, const char* attack)
		: health(health), attack(attack) {}

	class Monster* newMonster();

	//getter
	int getHealth() { return health; }
	const char* getAttack() { return attack; }
private:
	int health;
	const char* attack;
};

class Monster
{
	friend class Breed;

public:
	Monster(Breed& breed)
		: health(breed.getHealth()), breed(breed) {}
	const char* getAttack() { return breed.getAttack(); }

private:
	int health;
	Breed& breed;
};

Monster* Breed::newMonster()
{
	return new Monster(*this);
}