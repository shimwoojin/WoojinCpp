//07_State.cpp

/*
	유한 상태 기계(FSM)

	- 가질 수 있는 '상태'가 한정됨
	- 한 번에 '한 가지' 상태만 될 수 있음
	- '입력'이나 '이벤트'가 기계에 전달됨
	- 각 상태에는 입력에 따라 다음 상태로 바뀌는 '전이'가 있음
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

//총을 들고 달리기 (병행 상태)
//
//class Heroine
//{
//
//private:
//	HeroineState* state_;
//	HeroineState* equipment_;
//};
//
//다른 포인터 변수

/*
	이전 상태로 돌아가려면? (푸시다운 오토다마)

	- 스택을 사용하기도 함
*/