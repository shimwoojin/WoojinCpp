#include <iostream>
#include "MyVector.h"

template<typename T>
MyVector<T>::MyVector()
	: data(nullptr), length(0), capacity(5)
{
	data = new T[capacity];
}

template<typename T>
MyVector<T>::MyVector(int capacity)
	: data(nullptr), length(0), capacity(capacity)
{
	data = new T[capacity];
}

template<typename T>
MyVector<T>& MyVector<T>::push_back(const T& data)
{
	if (isFull(length)) Realloc_data();
	this->data[length] = data;
	++length;
	return *this;
}

template<typename T>
MyVector<T>& MyVector<T>::pop_back()
{
	this->data[--length] = NULL;
	return *this;
}

template<typename T>
void MyVector<T>::Realloc_data()
{
	T* copy = new T[length];
	for (int i = 0; i < length; i++)
		copy[i] = data[i];
	delete[] data;
	int capacity_double = SetCapacity_double();
	data = new T[capacity_double];
	for (int i = 0; i < length; i++)
		data[i] = copy[i];
	delete[] copy;
}

template<typename T>
int MyVector<T>::SetCapacity_double()
{
	return capacity *= 2;
}

template<typename T>
bool MyVector<T>::isFull(const int length) const
{
	if (this->capacity < length + 1) return true;
	else return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& mv)
{
	os << mv;
	return os;
}

template<typename T>
T& MyVector<T>::operator[](int index)
{
	return data[index];
}