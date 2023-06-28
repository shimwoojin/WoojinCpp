#include <iostream>
#include <functional>
using namespace std;

class AirPlane
{
public:
	typedef void (AirPlane::*ChangeFlyHeight)();

	void FlyLow()
	{
		Height = 1000.0f;
	}

	void FlyHigh()
	{
		Height = 3000.0f;
	}

	void Fly(const ChangeFlyHeight& ReadyToFlyRef)
	{
		ReadyToFly = ReadyToFlyRef;
		(this->*ReadyToFly)();

		Execute();
	}

	void Execute()
	{
		std::cout << "flying... height : " << Height << "km" << std::endl;
	}

private:
	ChangeFlyHeight ReadyToFly;
	float Height;
};

int main()
{
	AirPlane* airplane = new AirPlane();
	
	airplane->Fly(&AirPlane::FlyLow);
	airplane->Fly(&AirPlane::FlyHigh);

	delete airplane;

	return 0;
}