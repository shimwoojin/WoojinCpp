//14_Component.cpp

/*
	����
	- ���� �о߸� �ٷ�� �ϳ��� ��ü�� ����
	- �оߺ��� ������ �ڵ带 ������Ʈ Ŭ������ ��
	- ��ü Ŭ������ ������Ʈ���� �����̳� ���Ҹ� ��
*/

/*
	���� ?
	- �� Ŭ�������� ���� �о߸� �ǵ帮�� �־ �̵��� ���� ��Ŀ�ø� �ϰ� ���� ��
	- Ŭ������ �ʹ� �Ŵ������� ������ ���� ��
	- ���� ����� �����ϴ� �پ��� ��ü�� �����ϰ� ���� ��
*/

//#define WHOLE_IN_ONE
//#define PATTERN
//#define PATTERN_WITH_INTERFACE
#define MESSAGE_IF_COUPLING

#ifdef WHOLE_IN_ONE
class Bjorn
{
public:
	Bjorn() : velocity_(0), x_(0), y_(0) {}
	void update(class World& world, class Graphics& graphics);

private:
	static const int WALK_ACCELERATION = 1;

	int velocity_;
	int x_, y_;

	class Volume& volume_;

	class Sprite& spriteStand_;
	Sprite& spriteWalkLeft_;
	Sprite& spriteWalkRight_;
};


#endif

#ifdef PATTERN
class Inputcomponent
{
public:
	void update(Bjorn& bjorn)
	{

	}
private:
	static const int WALK_ACCELERATION = 1;
};

class PhysicsComponent
{
public:
	void update(Bjorn& bjorn, class World& world) {}
private:
	class Volume& volume_;
};

class GraphicsComponent
{
public:
	void update(Bjorn& bjorn, class Graphics& graphics) {}
private:
	class Sprite& spriteStand_;
	Sprite& spriteWalkLeft_;
	Sprite& spriteWalkRight_;
};

class Bjorn
{
public:
	int velocity;
	int x, y;

	void update(class World& world, class Graphics& graphics)
	{
		input_.update(*this);
		//...
	}

private:
	Inputcomponent& input_;
	PhysicsComponent& physics_;
	GraphicsComponent& graphics_;
};


#endif

#ifdef PATTERN_WITH_INTERFACE
class PhysicsComponent
{
public:
	virtual ~PhysicsComponent() {}
	virtual void update(class GameObject& obj) = 0;
};
class GraphicsComponent
{
public:
	virtual ~GraphicsComponent() {}
	virtual void update(class GameObject& obj) = 0;
};
class InputComponent
{
public:
	virtual ~InputComponent() {}
	virtual void update(class GameObject& obj) = 0;
};

class GameObject
{
public:
	int velocity;
	int x, y;

	GameObject(InputComponent* input,
		PhysicsComponent* physics,
		GraphicsComponent* graphics)
		: input_(input),
		physics_(physics),
		graphics_(graphics) {}

	void update()
	{
		input_->update(*this);
		physics_->update(*this);
		graphics_->update(*this);
	}

private:
	InputComponent* input_;
	PhysicsComponent* physics_;
	GraphicsComponent* graphics_;
};

#endif

#ifdef MESSAGE_IF_COUPLING
class Component		//component���� ��ӹ޾ƾ� �ϴ� �ֻ��� Ŭ����
{
public:
	virtual ~Component() {}
	virtual void recieve(int message) = 0;	//�޽��� recieve
};

class ContainerObject
{
	void send(int message)
	{
		for (int i = 0; i < MAX_COMPONENTS; i++)
		{
			if (components_[i] != nullptr)
			{
				components_[i]->recieve(message);
			}
		}
	}
private:
	static const int MAX_COMPONENTS = 10;
	Component* components_[MAX_COMPONENTS];
};

#endif