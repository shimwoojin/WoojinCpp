#pragma once

#ifndef TEMPLATE_MYVECTOR
#define TEMPLATE_MYVECTOR

template <typename T>
class MyVector
{
public:
	MyVector();
	MyVector(int length);
	~MyVector() { delete[] data; }

	//function
	MyVector<T>& push_back(const T& data);
	MyVector<T>& pop_back();

	//operator overloading
	friend std::ostream& operator<<(std::ostream& os, const MyVector& mv);
	T& operator[](int index);

	//getter
	int GetLength() const { return length; }
	int GetCapacity() const { return capacity; }
	int size() const { return length; }
private:
	T* data;
	int length;
	int capacity;

	//getter
	bool isFull (int capacity) const;
	//setter
	int SetCapacity_double();
	void Realloc_data();
};

#endif

#include "MyVector.hpp"