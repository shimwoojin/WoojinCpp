#pragma once

class Observer;
enum class Event;

class Subject
{
public:
	void notify(const class Entity& entity, Event event);
	void addObserver(Observer* observer);
	void removeObserver(Observer* observer);
protected:
private:
	Observer* head_;
};