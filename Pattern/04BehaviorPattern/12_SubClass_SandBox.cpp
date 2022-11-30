//12_SubClass_SandBox.cpp

/*
	���� Ŭ�������� �����ϴ� ��ɵ��� ���ؼ� ���� Ŭ�������� �ൿ�� ����
*/

/*
	���� ������ ?
	- Ŭ���� �ϳ��� ���� Ŭ������ ���� ����
	- ���� Ŭ������ ���� Ŭ������ �ʿ�� �ϴ� ����� ���� ����
	- ���� Ŭ���� �ൿ �߿� ��ġ�°� ���� �̸� ���� Ŭ�������� ���� �����ϰ� ����
	- ���� Ŭ������ ������ Ŀ�ø� �� ���� Ŭ������ ������ �ڵ���� Ŀ�ø��� �ּ�ȭ�ϰ� ����
*/

//�ٽ� 1. protected�� ���� ��ӿ� �ڵ�
//�ٽ� 2. activate�� ���������Լ� -> �ݵ�� ������ ( move, playSound, spawnParticles���� ������ �Լ�)
//�ٽ� 3. virtual�� �ƴ� move, playSound, spawnParicles
//-> ���� Ŀ�ø��� Superpower Ŭ������ ���� ��
class Superpower
{
public:
	virtual ~Superpower() {}

protected:
	virtual void activate() = 0;
	void move(double x, double y, double z) {/*..*/ }
	//void playSound() {/*..*/ }
	//void stopSound() {}
	//void setVolume() {}	//�̷��� ����� �������� �� ��ġ ���� ���.. �ٸ� Ŭ������ ���� ����
	SoundPlayer& getSoundPlayer() 
	{
		return soundPlayer_;
	}
	void spawnParticles() {/*..*/}

	double getHeroX() {}
	double getHeroY() {}
	double getHeroZ() {}

private:
	SoundPlayer soundPlayer_;	//�� ������ ���� Ŭ�������� �Ű������� ���� ���� �ʴٸ�
	//Init�Լ��� ���� �ʱ�ȭ�� �� ����
	//Init�Լ��� �� �ٸ� �Լ���� �������μ� ���� Ŭ������ �ʱ�ȭ �Լ��� ���
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