#include "Car.h"

Car::Car()
{	title = "";
	duration = 0;
	time(&arrival_time);}

Car::Car(string title, int duration)
{	this->title = title;
	this->duration = duration;
	time(&arrival_time);}

int& Car::getDuration()
{	return duration;}

time_t Car::getArrivalTime()
{	return arrival_time;}

string Car::getTitle()
{
	return title;
}

ostream & operator<<(ostream & os, const Car & obj)
{	struct tm s_t;
	localtime_s(&s_t, &obj.arrival_time);
	os << obj.title << " " << obj.duration << " ";
	os << s_t.tm_hour << ":" << s_t.tm_min << ":" << s_t.tm_sec << endl;
	return os;}

istream & operator>>(istream & is, Car & obj)
{
	is >> obj.title >> obj.duration;
	return is;
}
