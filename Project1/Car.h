#pragma once
#include "Q.h"
#include<ctime>
#include <string>
#include <iostream>
using namespace std;
class Car {
private:
	string title;
	int duration;
	time_t arrival_time;

public:
	Car();
	Car(string title, int duration);
	int& getDuration();
	time_t getArrivalTime();
	string getTitle();
	friend ostream& operator<<(ostream& os, const Car& obj);
	friend istream& operator>>(istream& is, Car& obj);

};
