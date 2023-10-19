#include <iostream>

class CharacterState
{
public:
	virtual ~CharacterState() {}
	virtual void handleInput(class Character& character, char input) {}
	virtual void update(Character& character) {}

public:
	static class DuckingState ducking;
};

class DuckingState : public CharacterState
{
public:
	DuckingState() : chargeTime_(0) {}

	virtual void handleInput(class Character& character, char input)
	{
		if (input == 'w')
		{
			//character.setGraphics(IMAGE_STAND);
		}
		//...
	}

	virtual void update(Character& character)
	{
		chargeTime_++;
		if (chargeTime_ > MAX_CHARGE)
		{
			//character.doSomething();
		}
	}

private:
	const int MAX_CHARGE = 50;
private:
	int chargeTime_;
};

class Character
{
public:
	virtual void handleInput(char input)
	{
		state_->handleInput(*this, input);
	}
	virtual void update() { state_->update(*this); }
	//...
private:
	CharacterState* state_;
};

int main()
{

	
	return 0;
}