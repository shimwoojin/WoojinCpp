//13_TypeObject.cpp

/*
	클래스 하나를 인스턴스 별로 다른 객체형으로 표현할 수 있게 만들어, 새로운
	'클래스들'을 유연하게 만들 수 있게 함
*/

/*
	패턴
	- 타입 객체 클래스와 타입 사용 객체 클래스응 정의
	-> 타입 사용 객체는 자신의 타입을 나타내는 타입 객체를 참조
*/

//#define BAD_CASE
//#define SHOW_PATTERN
#define OTHER_CASE

#ifdef BAD_CASE
//너무 많은 몬스터를 일일히 작업해야 함
class Monster
{
public:
	virtual ~Monster() {}
	virtual const char* getAttack() = 0;

protected:
	Monster(int startingHealth) : health_(startingHealth) {}

private:
	int health_;
};

class Dragon : public Monster
{
public:
	Dragon() : Monster(230) {}
	virtual const char* getAttack() {}
};

class Troll : public Monster
{
public:
	Troll() : Monster(50) {}
	virtual const char* getAttack() {}
};
#endif

#ifdef SHOW_PATTERN
class Breed
{
public:
	Breed(int health, const char* attack)
		: health_(health),
		attack_(attack) {}
	int getHelath() { return health_; }
	const char* getAttack() { return attack_; }

private:
	int health_;
	const char* attack_;
};

class Monster
{
public:
	Monster(Breed& breed)
		: health_(breed.getHelath()),
		breed_(breed) {}
	const char* getAttack() { return breed_.getAttack(); }

private:
	int health_;
	Breed& breed_;
};


#endif

#ifdef OTHER_CASE
//Factory Method Pattern ?
class Breed
{
public:
	Monster* newMonster()	//Factory Method Pattern ?
	{
		return new Monster(*this);
	}

public:
	Breed(int health, const char* attack)
		: health_(health),
		attack_(attack) {}
	int getHealth() { return health_; }
	const char* getAttack() { return attack_; }

private:
	int health_;
	const char* attack_;
};

class Monster
{
	friend class Breed;

public:
	const char* getAttack() { return breed_.getAttack(); }

private:
	Monster(Breed& breed)
		: health_(breed.getHealth()),
		breed_(breed) {}
	int health_;
	Breed& breed_;
};
#endif