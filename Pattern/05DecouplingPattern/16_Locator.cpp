//16_Locator.cpp

/*
	서비스를 구현한 구체 클래스는 숨긴 채로 어디에서나 서비스에 접근할 수 있게 함
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
	virtual void playSound() { /* 실제로 이렇게 정의, 아무 동작도 안함*/ }
	virtual void stopSound() {}	//마찬가지..
	virtual void stopAllSounds() {}	//..
};

class LoggedAudio : public Audio {};	//log를 남기는 오디오를 정의할 수도..


class Locator
{
public:
	static Audio* getAudio() { return service_; }
	static void provide(Audio* service)
	{
		if (service == nullptr)	//null일 경우 아무소리도 안나는 오디오 지정
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