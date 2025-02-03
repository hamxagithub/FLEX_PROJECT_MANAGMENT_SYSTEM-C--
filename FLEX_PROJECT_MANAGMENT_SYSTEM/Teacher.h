#ifndef TEACHER_H
#define TEACHER_H
#include"Person.h"
class Teacher : public Person 
{
	string ID;
public:

	string getID();

	void setID();

	Teacher();

	~Teacher();

	void Edit();

	void Input();

	void Display();
};

#endif

