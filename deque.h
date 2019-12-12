#pragma once
#include <iostream>
using namespace std;

template<typename T>
class MYdeque {
private:
	T* els;
	int buf_size;
	int cur_begin;
	int cur_end;
public:
	MYdeque() {
		els = 0;
		buf_size = 0;
		cur_begin = 0;
		cur_end = 0;
	}
	MYdeque(const MYdeque& obj) {
		this->buf_size = obj.buf_size;
		this->els = new T[buf_size];

		this->cur_begin = obj.cur_begin;
		this->cur_end = obj.cur_end;

		for (int i = cur_end; i <= cur_begin; i++) {
			els[i] = obj.els[i];
		}
	}
	~MYdeque() {
		delete[] els;
		els = nullptr;
	}
	void push_back(T el) {
		cur_end++;
		if (buf_size == 0) {
			buf_size = 4;
			els = new T[buf_size];
			cur_begin = (buf_size - 1) / 2;
			cur_end = cur_begin;
		}
		else if (cur_end > size()) {
			buf_size *= 2;
			T*tmp = new T[buf_size];
			int tmp_begin, tmp_end;
			tmp_begin = buf_size / 2 - size() / 2;
			tmp_end = tmp_begin;

			for (int i = cur_begin; i <= cur_end; i++, tmp_end++) {
				tmp[tmp_end] = els[i];
			}
			delete[] els;
			els = tmp;
			cur_begin = tmp_begin;
			cur_end = tmp_end;
		}
		els[cur_end] = el;
	}

	void push_front(T el) {
		cur_begin--;
		if (buf_size == 0) {
			buf_size = 4;
			els = new T[buf_size];
			cur_begin = (buf_size - 1) / 2;
			cur_end = cur_begin;
		}
		else if (cur_begin < 0) {
			buf_size *= 2;
			T*tmp = new T[buf_size];
			int tmp_begin, tmp_end;
			tmp_begin = buf_size / 2 - size()/2;
			tmp_end = tmp_begin;

			for (int i = cur_begin; i <= cur_end; i++, tmp_end++) {
				tmp[tmp_end] = els[i];
			}
			tmp_end--;
			delete[] els;
			els = tmp;
			cur_begin = tmp_begin;
			cur_end = tmp_end;
		}
		els[cur_begin] = el;
	}
	void pop_back() {
		cur_end--;
	}
	void pop_front() {
		cur_begin++;
	}
	int size() {
		return cur_end - cur_begin + 1;
	}
	T& operator[](int ind) {
		if (ind<0 || ind>=size()) {
			throw("error");
		}
		return els[cur_begin + ind];
	}

};