//06_Singleton.cpp

#include <cassert>

/*
	인스턴스가 한 개인 것을 보장하는 패턴 + 전역 접근

	- 오디오, keyInputSystem 등에 유용함
*/

/*
	남용 금지

	- 싱글턴은 전역에서 접근 가능한 정적 객체를 만드는 것이기 때문에
	제어가 어려울 수 있음. 특히 멀티 스레딩 환경에서
*/

/*
	필자가 사용한 싱글턴 대안
	- 정적 클래스 (static 키워드를 사용하여 인스턴스 생성)
	- 생성자에 정적 플래그를 둬서 인스턴스 개수를 검사하는 방법
*/

//#define SINGLETON
//#define INHERITANCE_OF_SINGLETON
//#define GUARD_GLOBAL_ACCESS_SINGLETON
#define MANAGE_MANY_SINGLETON_CLASS_WITH_ONE_GLOBAL_CLASS

#ifdef SINGLETON
class Singleton
{
public:
	static Singleton& instance()
	{
		static Singleton singleton;
		return singleton;
	}

	Singleton(const Singleton& singleton) = delete;
	Singleton& operator=(const Singleton& singleton) = delete;
	Singleton(Singleton&& singleton) = delete;
	Singleton& operator=(Singleton&& singleton) = delete;
private:
	Singleton() = default;
};

int main()
{
	Singleton& singleton = Singleton::instance();


	return 0;
}

#endif

//필자가 말하는 강력한 싱글턴의 상속
#ifdef INHERITANCE_OF_SINGLETON
class BaseSingleton
{
public:
	static BaseSingleton& instance();
	
	virtual ~BaseSingleton() {}
	virtual void printInfo() = 0;

protected:
	BaseSingleton() {}
};

class DerivedSingleton1 : public BaseSingleton
{
public:
	void printInfo() {}
};

class DerivedSingleton2 : public BaseSingleton
{
public:
	void printInfo() {}
};

#define CHOICE1 DERIVED1

BaseSingleton& BaseSingleton::instance()
{
#if CHOICE1 == DERIVED1
	static BaseSingleton* instance = new DerivedSingleton1();
#elif CHOICE1 == DERIVED2
	static BaseSingleton* instance = new DerivedSingleton2();
#endif

	return *instance;
}

#endif

#ifdef GUARD_GLOBAL_ACCESS_SINGLETON
class Singleton
{
public:
	Singleton()
	{
		assert(!instantiated_);
		instantiated_ = true;
	}
	~Singleton()
	{
		instantiated_ = false;
	}

private:
	static bool instantiated_;
};

bool Singleton::instantiated_ = false;


#endif

#ifdef MANAGE_MANY_SINGLETON_CLASS_WITH_ONE_GLOBAL_CLASS
//전역에서 접근할 수 있는 싱글턴 Game을 통해 다른 싱글턴 인스턴스들 제어
class Game
{
public:
	static Game& instance() { return instance_; }

	//Log& getLog() { return *log_; }
	//FileSystem& getFileSystem() { return *filesystem_; }
	//AudioPlayer& getAudioPlayer() { return *audioplayer_; }
private:
	static Game instance_;

	//Log* log_;
	//FileSystem* filesystem_;
	//AudioPlayer* audioplayer_;
};

int main()
{
	//Game::instance().getAudioPlayer.play(VERY_LOUD_BANG);

	return 0;
}


#endif