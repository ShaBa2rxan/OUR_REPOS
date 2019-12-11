#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class DoublyLinkedList {
	class Node
	{
	private:
		T value;
		Node* nextPtr;
		Node* prevPtr;
	public:
		Node();
		Node(T value);
		T& getValue();
		void setValue(T value);
		Node*& getNextPtr() {
			return nextPtr;
		}
		void setNextPtr(Node* ptr);
		Node*& getPrevPtr() {
			return prevPtr;
		}
		void setPrevPtr(Node* ptr);
	} *firstPtr, *lastPtr;
	int cur_size;

public:
	DoublyLinkedList();
	//DoublyLinkedList(const DoublyLinkedList & obj);
	~DoublyLinkedList();
	//void clear();
	int size();
	void push_back(T value);
	void push_front(T value);
	void pop_back();
	void pop_front();
	/*T& operator[](int index);
	void insert(int pos, T value);*/
	void print();
	T&back();
	T&front();
	/*void removeByPos(int index);
	void removeAll(T value);
	void findAll(T value);
	void sort();
	void bucket_sort();*/

};


template<typename T>
inline DoublyLinkedList<T>::Node::Node()
{
	value = 0;
	nextPtr = nullptr;
	prevPtr = nullptr;
}

template<typename T>
inline DoublyLinkedList<T>::Node::Node(T value)
{
	this->value = value;
	this->nextPtr = nullptr;
	this->prevPtr = nullptr;
}

template<typename T>
inline T & DoublyLinkedList<T>::Node::getValue()
{
	return value;
}

template<typename T>
inline void DoublyLinkedList<T>::Node::setValue(T value)
{
	this->value = value;
}

template<typename T>
inline void DoublyLinkedList<T>::Node::setNextPtr(Node * ptr)
{
	this->nextPtr = ptr;
}

template<typename T>
inline void DoublyLinkedList<T>::Node::setPrevPtr(Node * ptr)
{
	this->prevPtr = ptr;
}
template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
{
	firstPtr = lastPtr = nullptr;
	cur_size = 0;
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	Node* cur_ptr = firstPtr;
	while (cur_ptr != nullptr)
	{
		Node*tmp = cur_ptr;
		cur_ptr = cur_ptr->getNextPtr();
		delete tmp;
		cur_size--;
	}
}

template<typename T>
inline int DoublyLinkedList<T>::size()
{
	return cur_size;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(T value)
{
	Node* ptr = new Node(value);
	if (cur_size == 0) {
		firstPtr = lastPtr = ptr;
	}
	else
	{
		lastPtr->setNextPtr(ptr);
		ptr->setPrevPtr(lastPtr);
		lastPtr = ptr;
	}
	cur_size++;
}

template<typename T>
inline void DoublyLinkedList<T>::push_front(T value)
{


}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
{
	if (cur_size == 1) {
		delete firstPtr;
		firstPtr = 0;
		lastPtr = 0;
	}
	else if (cur_size > 0) {
		Node*ptr = lastPtr;
		lastPtr = lastPtr->getPrevPtr();
		delete ptr;
		lastPtr->setNextPtr(nullptr);
	}
	else
	{
		throw("List is empty");
	}
	cur_size--;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
{
	if (cur_size == 1) {
		delete firstPtr;
		firstPtr = nullptr;
		lastPtr = nullptr;
	}
	else if (cur_size > 1) {
		Node* tmp = firstPtr;
		firstPtr = tmp->getNextPtr();
		delete tmp;
		firstPtr->setPrevPtr(nullptr);
	}
	else {
		throw("List is empty");
	}
	cur_size--;
}

template<typename T>
inline void DoublyLinkedList<T>::print()
{
	Node* cur_ptr = lastPtr;
	while (cur_ptr != nullptr)
	{
		cout << cur_ptr->getValue() << endl;
		cur_ptr = cur_ptr->getPrevPtr();
	}
}

template<typename T>
inline T & DoublyLinkedList<T>::back()
{
	return lastPtr->getValue();
}

template<typename T>
inline T & DoublyLinkedList<T>::front()
{
	return this->firstPtr->getValue();
}
