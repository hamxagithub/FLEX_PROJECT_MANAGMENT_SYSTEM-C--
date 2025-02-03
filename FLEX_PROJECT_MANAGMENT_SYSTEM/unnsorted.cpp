
#include "Person.h"
UnSorted::UnSorted()
{
	students = NULL;
	size = 0;
}
UnSorted::UnSorted(const UnSorted& S)
{
	size = S.size;
	students = new Student[size];
	for (int i = 0; i < size; i++)
	{
		students[i] = S.students[i];
	}
}
UnSorted::~UnSorted()
{
	if (students != nullptr)
	{
		delete[]students;
	}
}
void UnSorted::Add(const Student& S1)
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
void UnSorted::shrink(const Student& S1)
{
	int n;
	for (int i = 0; i < size; i++)
	{
		if (S1.getID() == students[i].getID())
		{
			n = i;
		}
	}
	Student* temp1;
	Student temp = students[n];
	students[n] = students[size - 1];
	students[size - 1] = temp;
	if (size - 1 == 0)
	{
		temp1 = NULL;
	}
	else
	{
		temp1 = new Student[size - 1];
	}
	for (int i = 0; i < size - 1; i++)
	{
		temp1[i] = students[i];
	}
	delete[]students;
	students = temp1;
	size--;
}
Student& UnSorted::getStudent(string UserName)
{
	for (int i = 0; i < size; i++)
	{
		if (UserName == students[i].getUserName())
		{
			return students[i];
		}
	}
}
void UnSorted::Display()
{
	for (int i = 0; i < size; i++)
	{
		students[i].Display();
	}
}