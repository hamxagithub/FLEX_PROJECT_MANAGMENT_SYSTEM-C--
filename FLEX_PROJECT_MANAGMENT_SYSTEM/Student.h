#ifndef STUDENT_H
#define STUDENT_H
#include"Person.h"
class Student : public Person {

private:
	string ID;
	bool FeeStatus;
	Course Marks;

public:
	Student();

	~Student();

	void Edit();

	void Input();

	void Display();

	string getID();

	void setID(string ID);

	bool getFeeStatus();

	void setFeeStatus(bool FeeStatus);

	Course getMarks();

	void setMarks(Course Marks);
};

#endif

