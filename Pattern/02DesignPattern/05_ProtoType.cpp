//05_ProtoType.cpp

/*
	ProtoType

	- ������ �Ǵ� �ν��Ͻ��� ����Ͽ� ������ ��ü�� ������ ���,
	�� �ߺ��� �����Ͽ� ���ο� ��ü ����
*/

//#define BADCASE
#define GOODCASE

#ifdef BADCASE

class Monster {  };

class Ghost : public Monster {};
class Demon : public Monster {};
class Sorcerer : public Monster {};

class Spawner
{
public:
	virtual ~Spawner() {}
	virtual Monster* spawnMonster() = 0;
};

class GhostSpawner : public Spawner
{
public:
	virtual Monster* spaawnMonster()
	{
		return new Ghost();
	}
};		//�̷��� �� ��� �� ������ spawner�� ���� �����Ͽ��� ��(�� ����)

#endif


#ifdef GOODCASE

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
		: health_(health), speed_(speed) {}

	virtual Monster* clone()
	{
		return new Ghost(health_, speed_);
	}

private:
	int health_;
	int speed_;
};

class Spawner
{
public:
	Spawner(Monster* prototype) : prototype_(prototype) {}

	Monster* spawnMonster()
	{
		return prototype_->clone();
	}

private:
	Monster* prototype_;
};



#endif