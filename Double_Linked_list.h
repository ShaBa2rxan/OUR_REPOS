#pragma once
#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class DLinkedList {
			
	class Node {
	private:
		T value;
		Node* nextPtr;
		Node* prevPtr;
	public:
		Node();
		Node(T value);
		T&getvalue();
		void setValue(T value);
		Node* getNextPtr() {
			return this->nextPtr;
		}
		Node* getPrevPtr() {
			return this->prevPtr;
		}
		void setPrevPtr(Node* ptr);
		void setNextPtr(Node* ptr);
	}*firstPointer, *LastPointer;

	int cur_size;

public:
	DLinkedList();
	~DLinkedList();
	void clear();
	DLinkedList(const DLinkedList& ob);
	int size();
	void Push_back(T el);
	void Push_front(T el);
	void pop_back();
	void pop_front();
	void print();
	//void insert(int pos, T val);
	//void remove_by_pos(int pos);
	//void find_all(T val);
	//void sort();
	//void bucket_sort();
	//T operator[](int ind);
};

template<typename T>
inline DLinkedList<T>::DLinkedList()
{
	firstPointer = LastPointer = nullptr;
	cur_size = 0;
	
}

template<typename T>
inline DLinkedList<T>::~DLinkedList()
{
	Node*cur_ptr = firstPointer;
	while (cur_ptr != nullptr) {
		Node* tmp = cur_ptr;
		cur_ptr = cur_ptr->getNextPtr();
		delete tmp;
		cur_size--;
	}
}

template<typename T>
inline void DLinkedList<T>::clear()
{
	Node*tmp = firstPointer;
	while (tmp != nullptr) {
		tmp = tmp->getNextPtr();
		delete tmp;
		cur_size--;
	}
	firstPointer = nullptr;
	LastPointer = nullptr;
}

template<typename T>
inline DLinkedList<T>::DLinkedList(const DLinkedList & ob)
{
	Node* cur_ptr = ob.firstPointer;
	while (cur_ptr != nullptr) {
		Push_back(cur_ptr->getValue());
		cur_ptr = cur_ptr->getNextPtr();
	}
}

template<typename T>
inline int DLinkedList<T>::size()
{
	return this->cur_size;
}

template<typename T>
inline void DLinkedList<T>::Push_back(T el)
{
	Node *ptr = new Node(el);
	if (cur_size == 0) {
		firstPointer = LastPointer = ptr;
	}
	else {
		LastPointer->setNextPtr(ptr);
		ptr->setPrevPtr(LastPointer);
		LastPointer = ptr;
	}
	cur_size++;
}

template<typename T>
inline void DLinkedList<T>::Push_front(T el)
{
	Node* ptr = new Node(el);
	if (cur_size == 0) {
		firstPointer = LastPointer = ptr;
	}
	else {
		firstPointer->setNextPtr(firstPointer->getNextPtr());
		ptr->setNextPtr(firstPointer);
		firstPointer->setPrevPtr(ptr);
		firstPointer = ptr;
	}
	cur_size++;
}

template<typename T>
inline void DLinkedList<T>::pop_back()
{
	Node*cur_ptr = firstPointer;
	while (cur_ptr->getNextPtr() != LastPointer) {
		cur_ptr = cur_ptr->getNextPtr();
	}
	delete LastPointer;
	LastPointer = cur_ptr;
	LastPointer->setNextPtr(nullptr);
	LastPointer->setPrevPtr(LastPointer->getPrevPtr());
	cur_size--;
}

template<typename T>
inline void DLinkedList<T>::pop_front()
{
	Node* ptr = firstPointer;
	firstPointer = ptr->getNextPtr();
	firstPointer->getNextPtr()->setPrevPtr(nullptr);
	delete ptr;
	cur_size--;
}

template<typename T>
inline DLinkedList<T>::Node::Node()
{
	value = 0;
	nextPtr = nullptr;
}

template<typename T>
inline DLinkedList<T>::Node::Node(T value)
{
	this->value = value;
}

template<typename T>
inline T & DLinkedList<T>::Node::getvalue()
{
	return this->value;
}

template<typename T>
inline void DLinkedList<T>::Node::setValue(T value)
{
	this->value = value;
}

template<typename T>
inline void DLinkedList<T>::Node::setPrevPtr(Node * ptr)
{
	this->prevPtr = ptr;
}

template<typename T>
inline void DLinkedList<T>::Node::setNextPtr(Node * ptr)
{
	this->nextPtr = ptr;
}

template<typename T>
inline void DLinkedList<T>::print()
{
	Node* cur_ptr = firstPointer;
	while (cur_ptr != nullptr) {
		cout << cur_ptr->getvalue() << endl;
		cur_ptr = cur_ptr->getNextPtr();
	}
}
