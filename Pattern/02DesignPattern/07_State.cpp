//07_State.cpp

/*
	���� ���� ���(FSM)

	- ���� �� �ִ� '����'�� ������
	- �� ���� '�� ����' ���¸� �� �� ����
	- '�Է�'�̳� '�̺�Ʈ'�� ��迡 ���޵�
	- �� ���¿��� �Է¿� ���� ���� ���·� �ٲ�� '����'�� ����
*/

//Interface
class HeroineState
{
public:
	virtual ~HeroineState() {}
	virtual void handleInput(class Heroine& heroine, const class Input& input) {}
	virtual void update(Heroine& heroine) {}

private:
	static class DuckingState duckingstate;
};

DuckingState HeroineState::duckingstate;

//Inheritance
class DuckingState : public HeroineState
{
public:
	DuckingState() : chargeTime_(0) { }

	virtual void handleInput(class Heroine& heroine, const class Input& input)
	{
		//change state
		//heroine.action();
		//..
	}

	virtual void update(Heroine& heroine)
	{
		//..
	}

private:
	int chargeTime_;
};

//Use
class Heroine
{
public:
	virtual void handleInput(const class Input& input)
	{
		state_->handleInput(*this, input);
	}

	virtual void update() { state_->update(*this); }

private:
	HeroineState* state_;
};

//���� ��� �޸��� (���� ����)
//
//class Heroine
//{
//
//private:
//	HeroineState* state_;
//	HeroineState* equipment_;
//};
//
//�ٸ� ������ ����

/*
	���� ���·� ���ư�����? (Ǫ�ôٿ� ����ٸ�)

	- ������ ����ϱ⵵ ��
*/