//12_SubClass_SandBox.cpp

/*
	상위 클래스에서 제공하는 기능들을 통해서 하위 클래스에서 행동을 정의
*/

/*
	언제 쓰나요 ?
	- 클래스 하나에 하위 클래스가 많이 있음
	- 상위 클래스는 하위 클래스가 필요로 하는 기능을 전부 제공
	- 하위 클래스 행동 중에 겹치는게 많아 이를 하위 클래스끼리 쉽게 공유하고 싶음
	- 하위 클래스들 사이의 커플링 및 하위 클래스와 나머지 코드와의 커플링을 최소화하고 싶음
*/

//핵심 1. protected에 적은 상속용 코드
//핵심 2. activate는 순수가상함수 -> 반드시 재정의 ( move, playSound, spawnParticles등을 포함할 함수)
//핵심 3. virtual이 아닌 move, playSound, spawnParicles
//-> 강한 커플링은 Superpower 클래스만 갖게 됨
class Superpower
{
public:
	virtual ~Superpower() {}

protected:
	virtual void activate() = 0;
	void move(double x, double y, double z) {/*..*/ }
	//void playSound() {/*..*/ }
	//void stopSound() {}
	//void setVolume() {}	//이렇게 기능이 많아지는 걸 원치 않을 경우.. 다른 클래스로 업무 분할
	SoundPlayer& getSoundPlayer() 
	{
		return soundPlayer_;
	}
	void spawnParticles() {/*..*/}

	double getHeroX() {}
	double getHeroY() {}
	double getHeroZ() {}

private:
	SoundPlayer soundPlayer_;	//이 변수를 하위 클래스에서 매개변수로 쓰고 싶지 않다면
	//Init함수를 통해 초기화할 수 있음
	//Init함수는 또 다른 함수들과 묶음으로서 하위 클래스의 초기화 함수에 사용
};

class SoundPlayer
{
	void playSound() {/*..*/ }
	void stopSound() {}
	void setVolume() {}
};

class SkyLaunch : public Superpower
{
protected:
	virtual void activate()
	{
		//playSound();
		spawnParticles();
		move(0, 0, 20);
	}
};