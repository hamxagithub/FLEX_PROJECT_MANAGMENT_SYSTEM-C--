#include <iostream>
#include <string>
#include "Person.h"

using namespace std;

int Teacher::count = 0;

string Teacher::getID()
{
    return ID;
}

void Teacher::setID(string ID)
{
    this->ID = ID;
}

void Teacher::setAttendence(Student& S1)
{
    cout << "1.Present" << endl;
    cout << "2.Absent" << endl;
    cout << "Press the corresponding key" << endl;
    char ch = _getch();
    if (ch == '1')
    {
        S1.Attendence = 'P';
    }
    else if (ch == '2')
    {
        S1.Attendence = 'A';
    }
}

Teacher::Teacher()
{
    ID = "";
    tcourse = NULL;
    number = 0;
    count++;
}

Teacher::~Teacher()
{
    count--;
}

void Teacher::Edit()
{
    cout << "Enter the ID of the Teacher to edit : " << endl;
    string id;
    cin >> id;
    Display();
    cout << "Select the field to edit:" << endl;
    cout << "1. Address" << endl;
    cout << "2. Contact Number" << endl;
    cout << "3. Qualification" << endl;
    cout << "4. Salary" << endl;
    int choice;
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        string address;
        cout << "Enter new address:" << endl;
        cin.ignore();
        getline(cin, address);
        setAddress(address);
        break;
    }
    case 2:
    {
        string contact;
        cout << "Enter new contact number:" << endl;
        cin >> contact;
        setContact(contact);
        break;
    }
    case 3:
    {
        cout << "Enter the Qualification" << endl;
        string Qualification;
        if (cin.peek() == '\n')
        {
            cin.ignore();
        }
        getline(cin, Qualification);
        setQualification(Qualification);
        break;
    }
    case 4:
    {
        double salary;
        cout << "Enter new salary: ";
        cin >> salary;
        setSalary(salary);
        break;
    }
    default:
    {
        cout << "Invalid choice." << endl;
        break;
    }
    }
}

void Teacher::Input()
{
    cout << "Enter the first name" << endl;
    string fname;
    cin >> fname;
    setFirstName(fname);
    cout << "Enter the last name" << endl;
    string lname;
    cin >> lname;
    setLastName(lname);
    cout << "Enter the department name" << endl;
    department department;
    cin >> department;
    setDepartment(department);
    cout << "Enter the Gender" << endl;
    string Gender;
    cin >> Gender;

	setGender(Gender);
	cout << "Enter the Qualification" << endl;
	string Qualification;
	if (cin.peek() == '\n')
	{
		cin.ignore();
	}
	getline(cin, Qualification);
	setQualification(Qualification);
	cout << "Enter the Address" << endl;
	string address;
	if (cin.peek() == '\n')
	{
		cin.ignore();
	}
	getline(cin, address);
	setAddress(address);
	cout << "Enter the Contact Number" << endl;
	string Contact;
	if (cin.peek() == '\n')
	{
		cin.ignore();
	}
	getline(cin, Contact);
	setContact(Contact);
	cout << "Enter the Registration date" << endl;
	Date registration{};
	cin >> registration;
	setRegistrationDate(registration);
	cout << "Enter the Username" << endl;
	string uname;
	cin >> uname;
	setUserName(uname);
	cout << "Enter the Password" << endl;
	string password;
	cin >> password;
	setPassword(password);
}
void Teacher::Display() {
	// TODO - implement Teacher::Display
	throw "Not yet implemented";
}
void Teacher::setCourse(const Course& C, string* section, int n)
{
	if (number == 0)
	{
		tcourse = new TCourse[number + 1];
		tcourse->course = new Course[number + 1];
		*(tcourse->course) = C;
		tcourse->no = n;
		tcourse->section = new Section[tcourse->no];
		for (int j = 0; j < n; j++)
		{
			*(tcourse->section + j) = (tcourse->course)->findSection(section[j]);
		}
	}
	else
	{
		TCourse* temp;
		temp = new TCourse[number + 1];
		for (int i = 0; i < number + 1; i++)
		{
			if (i < number)
			{
				temp[i] = tcourse[i];
			}
			else
			{
				*(temp[i].course) = C;
				temp[i].no = n;
				temp[i].section = new Section[tcourse->no];
				for (int j = 0; j < n; j++)
				{
					*(temp[i].section + j) = (temp[i].course)->findSection(section[j]);
				}
			}
		}
	}
	number++;
}
