//10_UpdateMethod.cpp

/*
	게임 푸르는 매 프레임마다 객체 컬렉션을 쭉 돌면서 update()를 호출
	각 객체는 '한 프레임'만큼 동작, 모든 객체가 동시에 동작 가능
*/

/*
	객체 간 접근이 가능함
	-> '업데이트 순서'가 중요함
*/

/*
	객체 추가 및 삭제는 항상 주의
	- 삭제 후 인덱스 하나를 건너뛰는 실수를 할 수 있음
	(수업에서 for문에서 iter++를 else뒤에 적었던 이유)
*/

class Entity
{
public:
	Entity() : x_(0), y_(0) {}
	virtual ~Entity() {}
	virtual void update() = 0;

private:
	double x_;
	double y_;
};

class World
{
public:
	World() : numEntities_(0) {	/*Entity 추가*/ }
	void gameLoop();


private:
	static const int MAX_ENTITIES = 100;
	Entity* entities_[MAX_ENTITIES];
	int numEntities_;
};

void World::gameLoop()
{
	while (true)
	{
		//user input..

		//entities update
		for (int i = 0; i < numEntities_; i++)
		{
			entities_[i]->update();
		}
		//render..
	}
}

//entity만의 for문을 돌리는 것이 아닌 컴포넌트 패턴을 통해 다양한 객체의 update를 해야함