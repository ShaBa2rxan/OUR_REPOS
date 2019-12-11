#pragma once
#include "Car.h"
#include "Q.h"

class Box {
private:
	Queue<Car> cs;
	int totalServingTime;
	int frontWatingTime;
public:
	Box();
	void push(Car el);
	Car pop();
	int size();
	bool empty();
	int getTotalServingTime()const;
	int getTotalWatingTime()const;
	Car& front();
	Car& back();
};