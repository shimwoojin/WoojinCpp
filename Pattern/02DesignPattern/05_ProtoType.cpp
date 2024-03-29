//05_ProtoType.cpp

/*
	ProtoType

	- 원형이 되는 인스턴스를 사용하여 생성할 객체의 종류를 명시,
	이 견본을 복사하여 새로운 객체 생성
*/

//#define BAD_CASE
//#define NORMAL_CASE
//#define TEMPLATE_CASE
//#define FUNCTION_POINTER_CASE

#ifdef BAD_CASE

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
};		//이렇게 할 경우 각 몬스터의 spawner를 각각 정의하여야 함(안 좋음)

#endif

#ifdef NORMAL_CASE

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

#ifdef TEMPLATE_CASE
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
	virtual ~Spawner() {}
	virtual Monster* spawnMonster() = 0;
};

template <class T>
class SpawnerFor : public Spawner
{
public:
	virtual Monster* spawnMonster() { return new T(); }
};


#endif

#ifdef FUNCTION_POINTER_CASE
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

Monster* spawnGhost()
{
	return new Ghost(50,5);
}

typedef Monster* (*SpawnCallback)();
//using SpawnCallback = Monster* (*)();

class Spawner
{
public:
	Spawner(SpawnCallback spawn) : spawn_(spawn) {}
	Monster* spawnMonster() { return spawn_(); }

private:
	SpawnCallback spawn_;
};

int main()
{
	Spawner* ghostSpawner = new Spawner(spawnGhost);

	return 0;
}


#endif