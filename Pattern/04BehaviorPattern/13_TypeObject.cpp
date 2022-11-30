//13_TypeObject.cpp

/*
	Ŭ���� �ϳ��� �ν��Ͻ� ���� �ٸ� ��ü������ ǥ���� �� �ְ� �����, ���ο�
	'Ŭ������'�� �����ϰ� ���� �� �ְ� ��
*/

/*
	����
	- Ÿ�� ��ü Ŭ������ Ÿ�� ��� ��ü Ŭ������ ����
	-> Ÿ�� ��� ��ü�� �ڽ��� Ÿ���� ��Ÿ���� Ÿ�� ��ü�� ����
*/

//#define BAD_CASE
//#define SHOW_PATTERN
#define OTHER_CASE

#ifdef BAD_CASE
//�ʹ� ���� ���͸� ������ �۾��ؾ� ��
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