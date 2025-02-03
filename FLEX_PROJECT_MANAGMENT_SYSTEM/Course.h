#ifndef COURSE_H
#define COURSE_H
#include<iostream>
#include<string>
#include"Section.h"
using namespace std;
struct Time
{
	int hours;
	int minutes;
	int sec;
};
struct Date
{
	int hours;
	int minutes;
	int seconds;
};
ostream& operator <<(ostream& out, Time &obj)
{
	if (obj.sec > 60)
	{
		obj.sec -= 60;
		obj.minutes++;
	}
	if (obj.minutes > 60)
	{
		obj.minutes -= 60;
		obj.hours++;
	}
	out << obj.hours << " : ";
	out << obj.minutes << " : ";
	out << obj.sec << endl;
	return out;
}
istream& operator >>(istream& in, Time obj)
{
	in >> obj.hours ;
	in >> obj.minutes;
	in >> obj.sec;
	return in;
}
class Course
{
	string name;
	Date date;
	Time time;
	Section * section;
public:
	Course();
	~Course();
	void Input();
	void display();
};
#endif
