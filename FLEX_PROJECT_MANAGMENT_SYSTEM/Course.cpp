
#include "Person.h"
Course::Course()
{
	name = "";
	size = 0;
	date.day = date.month = date.year = 0;
	time.hours = time.minutes = time.sec = 0;
	section = nullptr;
}
Course::Course(const Course& C)
{
	size = C.size;
	name = C.name;
	date = C.date;
	time = C.time;
	if (C.section != nullptr)
	{
		section = new Section[size];
		for (int i = 0; i < size; i++)
		{
			section[i] = C.section[i];
		}
	}
}
Course::~Course()
{
	if (section != nullptr)
	{
		delete[]section;
	}
}
void Course::setName()
{
	cout << "Input the lecture name" << endl;
	cin >> name;
}
void Course::GrowSection(const Section& S1)
{
	if (size == 0)
	{
		section = new Section[size + 1];
		*section = S1;
	}
	else
	{
		Section* temp;
		temp = new Section[size + 1];
		for (int i = 0; i < size + 1; i++)
		{
			if (i < size)
			{
				temp[i] = section[i];
			}
			else
			{
				temp[i] = S1;
			}
		}
		delete[] section;
		section = temp;
	}
	size++;
}
void Course::setSection(const Section& S1)
{
	GrowSection(S1);
}

void Course::setDate()
{

}
void Course::setTime()
{

}
string Course::getName() const
{
	return name;
}
void Course::getSection() const
{
	for (int i = 0; i < size; i++)
	{
		cout << section[i].getName() << '\t';
	}
}
void Course::display()
{
	cout << "Name" << endl;
	cout << "Time" << endl;
	cout << "Date" << endl;
}
Section& Course::findSection(string st)
{
	for (int i = 0; i < size; i++)
	{
		if (section[i].getName() == st)
		{
			return section[i];
		}
	}
}
Student* Course::findSStudent(string rollNo) const
{
	Student* S = nullptr;
	for (int i = 0; i < size; i++)
	{
		section[i].findStudent(rollNo, S);
		if (S != nullptr)
		{
			return S;
		}
	}
}
