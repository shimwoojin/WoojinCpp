//02_Command.cpp

/*
	Ű �Է¿� ���� ���� �����ϴ� ����
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
		//��ư�� ������ �� ó��
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