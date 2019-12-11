#pragma once
#include "Dlink.h"
template<typename T>
class Queue {
private:
	DoublyLinkedList<T> base;
public:
	Queue();
	T pop();
	void push(T el);
	T&front();
	T& back();
	int size();
	bool empty();
};

template<typename T>
inline Queue<T>::Queue()
{
}

template<typename T>
inline T Queue<T>::pop()
{
	T tmp;
	tmp = base.front();
	base.pop_front();
	return tmp;
}

template<typename T>
inline void Queue<T>::push(T el)
{
	base.push_back(el);
}

template<typename T>
inline T & Queue<T>::front()
{
	return base.front();
}

template<typename T>
inline T & Queue<T>::back()
{
	return base.back();
}

template<typename T>
inline int Queue<T>::size()
{
	return base.size();
}

template<typename T>
inline bool Queue<T>::empty()
{
	if (this->size() == 0) {
		return true;
	}
	else return false;
}
