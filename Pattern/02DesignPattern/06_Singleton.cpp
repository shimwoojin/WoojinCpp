//06_Singleton.cpp

#include <cassert>

/*
	�ν��Ͻ��� �� ���� ���� �����ϴ� ���� + ���� ����

	- �����, keyInputSystem � ������
*/

/*
	���� ����

	- �̱����� �������� ���� ������ ���� ��ü�� ����� ���̱� ������
	��� ����� �� ����. Ư�� ��Ƽ ������ ȯ�濡��
*/

/*
	���ڰ� ����� �̱��� ���
	- ���� Ŭ���� (static Ű���带 ����Ͽ� �ν��Ͻ� ����)
	- �����ڿ� ���� �÷��׸� �ּ� �ν��Ͻ� ������ �˻��ϴ� ���
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

//���ڰ� ���ϴ� ������ �̱����� ���
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
//�������� ������ �� �ִ� �̱��� Game�� ���� �ٸ� �̱��� �ν��Ͻ��� ����
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