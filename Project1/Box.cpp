#include "Box.h"

Box::Box()
{
	this->totalServingTime = 0;
	this->frontWatingTime = 0;
}

void Box::push(Car el)
{
	totalServingTime += el.getDuration();
	cs.push(el);
}

Car Box::pop()
{
	totalServingTime -= cs.front().getDuration();
	frontWatingTime += cs.front().getDuration();
	return cs.pop();
}

int Box::size()
{
	return cs.size();
}

bool Box::empty()
{
	return cs.empty();
}

int Box::getTotalServingTime()const
{
	return totalServingTime;
}

int Box::getTotalWatingTime()const
{
	return frontWatingTime;
}

Car & Box::front()
{
	return cs.front();
}

Car & Box::back()
{
	return cs.back();
}
