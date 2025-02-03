
#include "Person.h"
Section::Section()
{
	name = "";
	students = NULL;
	size = 0;
}
Section::~Section()
{
	if (students != NULL)
	{
		delete[] students;
	}
}
Section::Section(const Section& S1)
{

	name = S1.name;
	if (S1.students != nullptr)
	{
		students = new Student[S1.size];
		for (int i = 0; i < S1.size; i++)
		{
			students[i] = S1.students[i];
		}
	}
	size = S1.size;
}
void Section::setName()
{
	cout << "Input the name" << endl;
	cin >> name;
}
string Section::getName()
{
	return name;
}
void Section::addStudent(const Student& S1)
{
	if (size == 0)
	{
		students = new Student[size + 1];
		students[0] = S1;
	}
	else
	{
		Student* temp;
		temp = new Student[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			if (i < size)
			{
				temp[i] = students[i];
			}
			else
			{
				temp[i] = S1;
			}
		}
		delete[]students;
		students = temp;
	}
	size++;
}
Section& Section:: operator=(const Section& S1)
{
	name = S1.name;
	if (S1.students != nullptr)
	{
		students = new Student[S1.size];
		for (int i = 0; i < S1.size; i++)
		{
			students[i] = S1.students[i];
		}
	}
	size = S1.size;
	return *this;
}
void Section::findStudent(string Rollno, Student* S1) const
{
	for (int i = 0; i < size; i++)
	{
		if (Rollno == students[i].getID())
		{
			S1 = &students[i];
			break;
		}
	}
}