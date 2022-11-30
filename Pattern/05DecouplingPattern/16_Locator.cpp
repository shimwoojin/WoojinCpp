//16_Locator.cpp

/*
	���񽺸� ������ ��ü Ŭ������ ���� ä�� ��𿡼��� ���񽺿� ������ �� �ְ� ��
*/
//#define NORMAL_CASE
//#define USE_MACRO

#ifdef NORMAL_CASE
class Audio
{
public:
	virtual ~Audio() {}
	virtual void playSound() = 0;
	virtual void stopSound() = 0;
	virtual void stopAllSounds() = 0;
};

class ConsoleAudio : public Audio
{
public:
	virtual void playSound() {}
	virtual void stopSound() {}
	virtual void stopAllSounds() {}
};

class NullAudio : public Audio
{
public:
	virtual void playSound() { /* ������ �̷��� ����, �ƹ� ���۵� ����*/ }
	virtual void stopSound() {}	//��������..
	virtual void stopAllSounds() {}	//..
};

class LoggedAudio : public Audio {};	//log�� ����� ������� ������ ����..


class Locator
{
public:
	static Audio* getAudio() { return service_; }
	static void provide(Audio* service)
	{
		if (service == nullptr)	//null�� ��� �ƹ��Ҹ��� �ȳ��� ����� ����
		{
			service_ = &nullService_;
		}
		else service_ = service;
	}

private:
	static Audio* service_;
	static NullAudio nullService_;
};
#endif

#ifdef USE_MACRO

class Audio
{
public:
	virtual ~Audio() {}
	virtual void playSound() = 0;
	virtual void stopSound() = 0;
	virtual void stopAllSounds() = 0;
};

class DebugAudio : public Audio { 
public:
	virtual void playSound() {}
	virtual void stopSound() {}
	virtual void stopAllSounds() {}
};

class ReleaseAudio : public Audio { 
public:
	virtual void playSound() {}
	virtual void stopSound() {}
	virtual void stopAllSounds() {}
};

class Locator
{
public:
	static Audio& getAudio() { return service_; }

private:
#if DEBUG
	static DebugAudio service_;
#else
	static ReleaseAudio service_;
#endif

};

#endif