#pragma once

enum class Event
{
	begin = 0,
	kill = begin,	//0
	death,			//1
	level_up,		// 2
	end = level_up,
	num
};

class Observer
{
	friend class Subject;

public:
	Observer() : next_(nullptr) {}
	virtual ~Observer() {}

	virtual void onNotify(const class Entity& entity, Event event) = 0;

private:
	Observer* next_;
};

class Achivements : public Observer
{
public:
	virtual void onNotify(const class Entity& eneity, Event event);

private:

};