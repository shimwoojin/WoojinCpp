//10_UpdateMethod.cpp

/*
	���� Ǫ���� �� �����Ӹ��� ��ü �÷����� �� ���鼭 update()�� ȣ��
	�� ��ü�� '�� ������'��ŭ ����, ��� ��ü�� ���ÿ� ���� ����
*/

/*
	��ü �� ������ ������
	-> '������Ʈ ����'�� �߿���
*/

/*
	��ü �߰� �� ������ �׻� ����
	- ���� �� �ε��� �ϳ��� �ǳʶٴ� �Ǽ��� �� �� ����
	(�������� for������ iter++�� else�ڿ� ������ ����)
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
	World() : numEntities_(0) {	/*Entity �߰�*/ }
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

//entity���� for���� ������ ���� �ƴ� ������Ʈ ������ ���� �پ��� ��ü�� update�� �ؾ���