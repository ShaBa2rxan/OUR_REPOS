#pragma once
#include <iostream>
#include <vector>
#include "Double_Linked_list.h"
using namespace std;
template<typename T>
class LinkedList {

	class Node {
	private:
		T value;
		Node* nextPtr;
	public:
		Node();
		Node(T value);
		T&getvalue();
		void setValue(T value);
		Node* getNextPtr() {
			return this->nextPtr;
		}
		void setNextPtr(Node* ptr);
	}*firstPointer, *LastPointer;
	
	int cur_size;
	
public:
	LinkedList();
	~LinkedList();
	void clear();
	LinkedList(const LinkedList& ob);
	int size();
	void Push_back(T el);
	void Push_front(T el);
	void pop_back();
	void pop_front();
	void print();
	void insert(int pos, T val);
	void remove_by_pos(int pos);
	void remove_ALL(T val);
	void find_all(T val);
	void sort();
	void bucket_sort();
	T operator[](int ind);

};

template<typename T>
inline LinkedList<T>::Node::Node()
{
	value = 0;
	nextPtr = nullptr;
}

template<typename T>
inline LinkedList<T>::Node::Node(T value)
{
	this->value = value;
}

template<typename T>
inline T & LinkedList<T>::Node::getvalue()
{
	return this->value;
}

template<typename T>
inline void LinkedList<T>::Node::setValue(T value)
{
	this->value = value;
}

template<typename T>
inline void LinkedList<T>::Node::setNextPtr(Node * ptr)
{
	this->nextPtr = ptr;
}

//---------------------------------------------------------------//

template<typename T>
inline LinkedList<T>::LinkedList()
{
	firstPointer = nullptr;
	LastPointer = nullptr;
	cur_size = 0;
}

template<typename T>
inline LinkedList<T>::~LinkedList()
{
	Node* cur_ptr = firstPointer;
	while (cur_ptr != nullptr) {
		Node *tmp = cur_ptr;
		cur_ptr = cur_ptr->getNextPtr();
		delete tmp;
		cur_size--;
	}
}

template<typename T>
inline void LinkedList<T>::clear()
{
	Node* cur_ptr = firstPointer;
	while (cur_ptr != nullptr) {
		Node *tmp = cur_ptr;
		cur_ptr = cur_ptr->getNextPtr();
		delete tmp;
		cur_size--;
	}
	firstPointer = nullptr;
	LastPointer = nullptr;
}

template<typename T>
inline LinkedList<T>::LinkedList(const LinkedList & ob)
{
	Node* cur_ptr = ob.firstPointer;
	while (cur_ptr != nullptr) {
		Push_back(cur_ptr->getValue());
		cur_ptr = cur_ptr->getNextPtr();
	}
}

template<typename T>
inline int LinkedList<T>::size()
{
	return cur_size;
}

template<typename T>
inline void LinkedList<T>::Push_back(T el)
{
	Node *ptr = new Node(el);

	if (cur_size == 0) {
		firstPointer = LastPointer = ptr;
	}
	else {
		LastPointer->setNextPtr(ptr);
		LastPointer = ptr;
	}
	cur_size++;
}

template<typename T>
inline void LinkedList<T>::Push_front(T el)
{
	Node* ptr = new Node(el);
	if (cur_size == 0) {
		firstPointer=LastPointer = ptr;
	}
	else {
		ptr->setNextPtr(firstPointer);
		firstPointer = ptr;
	}
	cur_size++;
}

template<typename T>
inline void LinkedList<T>::pop_back()
{
	Node*cur_ptr = firstPointer;
	while (cur_ptr->getNextPtr() != LastPointer) {
		cur_ptr = cur_ptr->getNextPtr();
	}
	delete LastPointer;
	LastPointer = cur_ptr;
	LastPointer->setNextPtr(nullptr);
	cur_size--;
}

template<typename T>
inline void LinkedList<T>::pop_front()
{
	Node* ptr = firstPointer;
	firstPointer = ptr->getNextPtr();
	delete ptr;
	cur_size--;
}

template<typename T>
inline void LinkedList<T>::print()
{
	Node* cur_ptr = firstPointer;
	while (cur_ptr != nullptr) {
		cout << cur_ptr->getvalue() << endl;
		cur_ptr = cur_ptr->getNextPtr();
	}
}

template<typename T>
inline void LinkedList<T>::insert(int pos, T val)
{
	if (pos<0 || pos>cur_size) {
		throw("incorrect index");
	}
	if (pos == 0) {
		this->Push_front(val);
	}
	else if (pos == cur_size) {
		this->Push_back(val);
	}
	else {
		int ind = 0;
		Node*ptr = new Node(val);
		Node *cur_ptr = firstPointer;
		while (ind < pos - 1) {
			cur_ptr = cur_ptr->getNextPtr();
			ind++;
		}
		ptr->setNextPtr(cur_ptr->getNextPtr());
		cur_ptr->setNextPtr(ptr);
		cur_size++;
	}
}

template<typename T>
inline void LinkedList<T>::remove_by_pos(int pos)
{
	if (pos<0 || pos>=cur_size) {
		throw("error");
	}
	if (pos == 0) {
		this->pop_front();
	}
	else if (pos == cur_size) {
		this->pop_back();
	}
	else {
		Node* cur_ptr = firstPointer;
		Node* ptr;
		int i = 0;
		while (i < pos - 1) {
			cur_ptr = cur_ptr->getNextPtr();
			i++;
		}

		ptr = cur_ptr->getNextPtr();
		cur_ptr->setNextPtr(ptr->getNextPtr());

		delete  ptr;
	}
}

template<typename T>
inline void LinkedList<T>::remove_ALL(T val)
{
	if (firstPointer->getvalue() == val)pop_front();
	int i = 0;
	Node* cur_ptr = firstPointer;
	Node* ptr;
	while (cur_ptr!=nullptr) {
		if (cur_ptr->getNextPtr()->getvalue() == val) {
			ptr = cur_ptr->getNextPtr();
			cur_ptr->setNextPtr(ptr->getNextPtr());
			delete ptr;
			cur_size--;
		}
		cur_ptr = cur_ptr->getNextPtr();
	}
}

template<typename T>
inline void LinkedList<T>::find_all(T val)
{
	Node* cur_ptr = firstPointer;
	int i = 0;
	while (cur_ptr != nullptr) {
		if (cur_ptr->getvalue() == val) {
			cout << i << endl;
		}
		i++;
		cur_ptr = cur_ptr->getNextPtr();
	}
}

template<typename T>
inline void LinkedList<T>::sort()
{
	Node* cur_ptr;
	Node *tmp=nullptr;
	int k = 0;
	for (int i = 0; i < cur_size; i++) {
		cur_ptr = firstPointer;
		while (cur_ptr->getNextPtr() != tmp) {
			if (cur_ptr->getvalue() > cur_ptr->getNextPtr()->getvalue()) {
				swap(cur_ptr->getvalue(), cur_ptr->getNextPtr()->getvalue());
			}
			cur_ptr = cur_ptr->getNextPtr();
			k++;
		}
		tmp = cur_ptr;
	}
	cout <<"k="<< k << endl;
}

template<typename T>
inline void LinkedList<T>::bucket_sort()
{
	vector<LinkedList<T>> ll(10);

	Node* cur_ptr=firstPointer;
	T tmp;
	while (cur_ptr != nullptr) {
		tmp = cur_ptr->getvalue();
		if (tmp < 10) {
			ll[0].Push_back(tmp);
		}else if (tmp < 20) {
			ll[1].Push_back(tmp);
		}else if (tmp < 30) {
			ll[2].Push_back(tmp);
		}else if (tmp < 40) {
			ll[3].Push_back(tmp);
		}
		cur_ptr = cur_ptr->getNextPtr();
	}

	for (int i = 0; i < ll.size(); i++) {
		ll[i].sort();
	}

	this->clear();

	for (int i = 0; i < ll.size(); i++) {
		for (int j = 0; j < ll[i].size(); j++) {
			this->Push_back(ll[i][j]);
		}
	}
}

template<typename T>
inline T LinkedList<T>::operator[](int ind)
{
	if (ind >= cur_size) {
		throw("ind is too high");
	}
	else if (ind < 0) {
		throw("ind is too low");
 	}

 	Node* tmp = firstPointer;
	int k = 0;
		while (k != ind) {
			tmp = tmp->getNextPtr();
			k++;
		}
		return tmp->getvalue();
}