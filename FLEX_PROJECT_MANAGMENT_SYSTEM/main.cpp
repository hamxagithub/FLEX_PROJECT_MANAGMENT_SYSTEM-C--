
#include"Person.h"
ostream& operator <<(ostream& out, Time& obj)
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
istream& operator >>(istream& in, Time& obj)
{
	in >> obj.hours;
	in >> obj.minutes;
	in >> obj.sec;
	return in;
}
ostream& operator <<(ostream& out, Date obj)
{
	out << obj.day << " / ";
	out << obj.month << " / ";
	out << obj.year << endl;
	return out;
}
istream& operator >>(istream& in, Date& obj)
{
	in >> obj.year;
	in >> obj.month;
	in >> obj.day;
	return in;
}
istream& operator >> (istream& in, department& x)
{
	cout << "Departments available:" << endl;
	cout << "1.Computer Science" << endl
		<< "2.Social Science" << endl
		<< "3.Business" << endl
		<< "4.Software Engineering" << endl
		<< "5.Electrical Engineering" << endl;
	cout << "Press the coresspnding keys" << endl;
	int n;
	if (in >> n)
	{
		switch (n)
		{
		case ComputerScience: case SocialScience:case Business: case SoftwareEngineering: case ElectricalEngineering:
		{
			x = department(n);
			break;
		}
		default:
			throw out_of_range("Program is not offered here");
		}
	}
	return in;
}
ostream& operator <<(ostream& out, department x)
{

	switch (x)
	{
	case ComputerScience:
	{
		out << "Computer Science" << endl;
		break;
	}
	case SocialScience:
	{
		out << "Social Science" << endl;
		break;
	}
	case Business:
	{
		out << "Business" << endl;
		break;
	}
	case SoftwareEngineering:
	{
		out << "Software Engineering" << endl;
		break;

	}
	case ElectricalEngineering:
	{
		out << "Electrical Engineering" << endl;
		break;
	}
	}
	return out;
}
int main()
{
	Course* C1 = 0;
	Section* S1 = 0;
	Administer A1(C1, S1);
	UnSorted S2;
	Teacher* teacher;
	S1 = A1.setSection();
	C1 = A1.setCourse();
	/*cout << C1->getName();
	C1->getSection();*/
	/*A1.addStudent(S2);
	S2.Display();
	S2.getStudent("Line").setCourse(&A1, S2);*/
	teacher= A1.addTeacher(C1);
	system("pause");
}