//04_Observer.cpp

class Observer
{
public:
	virtual ~Observer() {}
	virtual void onNotify(/*const Entity& entity, Event event*/) = 0;
};

class Achivements : public Observer
{
public:
	virtual void onNotify(/* */)
	{
		//switch (/*event*/)
		//{
		//case A: 
		//{
		//	//케이스 처리
		//}
		//	break;
		//}
	}
};

class Subject
{
public:
	Subject() = default;

	void addObserver(Observer* observer)
	{
		//추가
	}

	void removeObserver(Observer* observer)
	{
		//제거
	}

	void notify(/*const Entity& eneity, Event event*/)
	{
		for (int i = 0; i < numObservers_; i++)
		{
			observers_[i]->onNotify(/*entity, event*/);
		}
	}

private:
	static const int MAX_OBSERVERS = 100;
	Observer* observers_[MAX_OBSERVERS];
	int numObservers_;
};

class Physics : public Subject
{
public:
	void updateEntity(/*Entity& entity*/)
	{
		notify();
	}
};