#pragma once
#include"Dlink.h"
template<typename T>
class Stack {
private:
	DoublyLinkedList<T> base;
public:
	Stack();
	void push(T val);
	void pop();
	T& top();
	int size();
	bool empty();
};

template<typename T>
inline Stack<T>::Stack()
{
}

template<typename T>
inline void Stack<T>::push(T val)
{
	base.push_back(val);
}

template<typename T>
inline void Stack<T>::pop()
{
	base.pop_back();
}

template<typename T>
inline T & Stack<T>::top()
{
	return base.back();
}

template<typename T>
inline int Stack<T>::size()
{
	return base.size();
}

template<typename T>
inline bool Stack<T>::empty()
{
	if (base.size() == 0) {
		return true;
	}
	else return false;
}