//14_Component.cpp

/*
	패턴
	- 여러 분야를 다루는 하나의 개체가 있음
	- 분야별로 각각의 코드를 컴포넌트 클래스에 둠
	- 개체 클래스는 컴포넌트들의 컨테이너 역할만 함
*/

/*
	언제 ?
	- 한 클래스에서 여러 분야를 건드리고 있어서 이들을 서로 디커플링 하고 싶을 때
	- 클래스가 너무 거대해져서 나누고 싶을 때
	- 여러 기능을 정의하는 다양한 객체를 정의하고 싶을 때
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
class Component		//component들이 상속받아야 하는 최상위 클래스
{
public:
	virtual ~Component() {}
	virtual void recieve(int message) = 0;	//메시지 recieve
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