//02_Command.cpp

/*
	키 입력에 대한 것을 정의하는 패턴
*/

//Command Interface
class ICommand
{
public:
	virtual ~ICommand() {}
	virtual void execute(/*Actor actor*/) = 0;

	static class JumpCommand jumpcommand;
	static class FireCommand firecommand;
};

//Command Interface Inheritance
class JumpCommand : public ICommand
{
public:
	virtual void execute(/*Actor actor*/)
	{
		//actor.jump();
	}
};

class FireCommand : public ICommand
{
public:
	virtual void execute(/*Actor actor*/)
	{
		//actor.fireGun();
	}
};

JumpCommand ICommand::jumpcommand;
FireCommand ICommand::firecommand;

class InputHandler
{
	enum class Button { Q, W };
public:
	InputHandler()
	{
		buttonQ_ = &jumpcommand;
		buttonW_ = &firecommand;
	}
	ICommand* handleInput();
	bool isPressed(Button button)
	{
		//버튼이 눌렸을 때 처리
	}

private:
	ICommand* buttonQ_;
	ICommand* buttonW_;
};

ICommand* InputHandler::handleInput()
{
	if (isPressed(Button::Q)) return buttonQ_;
	else if (isPressed(Button::W)) return buttonW_;
}

int main()
{
	InputHandler inputhandler;
	ICommand* command = inputhandler.handleInput();
	if (command)
	{
		command->execute(/*actor*/);
	}


	return 0;
}