
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#include<conio.h>
#include<sstream>
using namespace std;
struct Time
{
	int hours;
	int minutes;
	int sec;
};
struct Date
{
	int year;
	int day;
	int month;
};
enum department
{
	ComputerScience = 1, SocialScience = 2, Business = 3, SoftwareEngineering = 4, ElectricalEngineering = 5
};
ostream& operator <<(ostream& out, Time& obj);
istream& operator >>(istream& in, Time& obj);
ostream& operator <<(ostream& out, Date obj);
istream& operator >>(istream& in, Date& obj);
istream& operator >> (istream& in, department& x);
ostream& operator <<(ostream& out, department x);
class UnSorted;
class Person {

private:
	string firstName;
	string lastName;
	department Department;
	string Qualification;
	string Contact;
	string Address;
	string Gender;
	Date registrationDate;
	string UserName;
	string Password;
	string BloodGroup;
public:
	string getFirstName() const;

	void setFirstName(string firstName);

	string getLastName()const;

	void setLastName(string lastName);

	department getDepartment()const;

	void setDepartment(department);

	string getQualification()const;

	void setQualification(string Qualification);

	string getContact()const;

	void setContact(string Contact);

	string getAddress()const;

	void setAddress(string Address);

	string getGender()const;

	void setGender(string Gender);

	Date getRegistrationDate()const;

	void setRegistrationDate(Date registrationDate);

	string getUserName()const;

	void setUserName(string UserName);

	string getPassword()const;

	void setPassword(string Password);

	string getBloodGroup()const;

	void setBloodGroup(string BloodGroup);


	void setSalary(double );

	Person();

	Person(const Person&);

	~Person();

	virtual void Edit() = 0;

	virtual void Input() = 0;

	virtual void Display() = 0;
};
class Section;
class Course;
class Student;
class Teacher;
class Administer
{
private:
	Course* course;
	int number;
	Section* section;
	int size;
	Teacher* teacher;
	int no;
	void PrintSection();
public:
	Administer(Course*, Section*);
	Administer(const Administer& A1);
	~Administer();
	Course* setCourse();
	void getCourse() const;
	Section* setSection();
	void addStudent(UnSorted&) const;
	void addStudent(UnSorted& S, const Student* S1) const;
	Teacher* addTeacher(const Course*);
	void editStudent();
};
class Student : public Person {

private:
	string ID;
	bool FeeStatus;
	static int count;
public:
	char Attendence;

	float marks;

	string* course;

	int number;

	string* section;

	int size;

	Student();

	Student(const Student& S1);

	~Student();

	void Edit();

	void Input();

	void Display();

	string getID() const;

	void setID();

	void getFeeStatus() const;

	void setFeeStatus(bool FeeStatus);

	void setCourse(const Administer*, UnSorted&);

	Student& operator = (const Student);

	char getAttendence();
};
class Teacher : public Person
{
	string ID;
	static int count;
	struct TCourse
	{
		Course* course;
		int no;
		Section* section;
	}*tcourse;
	int number;
public:

	string getID();

	void setID(string ID);

	Teacher();

	~Teacher();
	
	void Edit();

	void Input();

	void setAttendence(Student&);

	void setCourse(const Course&, string*, int);

	void Display();
};
class Course
{
protected:
	string name;
private:
	Date date;
	Time time;
	Section* section;
	int size;
	void GrowSection(const Section&);
public:
	Course();
	Course(const Course&);
	~Course();
	void setName();
	void setSection(const Section&);
	void setTime();
	void setDate();
	Student* findSStudent(string) const;
	string getName() const;
	void getSection()const;
	Section& findSection(string);
	void display();
};
class Section
{
	string name;
	Student* students;
	int size;
public:
	Section();
	~Section();
	Section(const Section&);
	void setName();
	void addStudent(const Student&);
	string getName();
	void findStudent(string,Student*) const;
	Section& operator=(const Section& S1);
	void Display();
};
class UnSorted
{
	Student* students;
	int size;
public:
	UnSorted();
	UnSorted(const UnSorted&);
	~UnSorted();
	void Add(const Student&);
	void shrink(const Student&);
	Student& getStudent(string);
	void Display();
};
#endif


