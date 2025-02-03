// Person.h
#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    string firstName;
    string lastName;
    string address;
    string contactNo;

public:
    Person();
    Person(string fname, string lname, string addr, string contact);
    virtual ~Person();
    void Display();
    void setFirstName(string fname);
    void setLastName(string lname);
    void setAddress(string addr);
    void setContact(string contact);
    string getID() const;
};

class Student : public Person {
private:
    string rollNo;
    bool feeStatus;

public:
    Student();
    Student(string fname, string lname, string addr, string contact, string rollno, bool feestatus);
    ~Student();
    void Edit();
    bool getFeeStatus() const;
    void setFeeStatus(bool status);
};

// Student.cpp
#include "Person.h"

int numStudents = 3; // for testing purposes only
Student students[] = { Student("John", "Doe", "123 Main St", "555-1234", "001", true),
                       Student("Jane", "Doe", "456 Maple Ave", "555-5678", "002", false),
                       Student("Bob", "Smith", "789 Elm St", "555-9012", "003", true) };

Student::Student() : rollNo(""), feeStatus(false) {}
Student::Student(string fname, string lname, string addr, string contact, string rollno, bool feestatus) :
    Person(fname, lname, addr, contact), rollNo(rollno), feeStatus(feestatus) {}

Student::~Student() {}

void Student::Edit()
{
    // display list of students
    cout << "List of Students:" << endl;
    for (int i = 0; i < numStudents; i++)
    {
        cout << students[i].getID() << ". " << students[i].getFirstName() << " " << students[i].getLastName() << endl;
    }

    // select student to edit
    cout << "Enter the roll number of the student to edit:" << endl;
    string rollNo;
    cin >> rollNo;

    bool found = false;
    for (int i = 0; i < numStudents; i++)
    {
        if (students[i].getID() == rollNo)
        {
            // display student's current details
            cout << "Current details:" << endl;
            students[i].Display();

            // ask which field to edit
            cout << "Select the field to edit:" << endl;
            cout << "1. First Name" << endl;
            cout << "2. Last Name" << endl;
            cout << "3. Fee Status" << endl;
            cout << "4. Address" << endl;
            cout << "5. Contact No" << endl;

            int choice;
            cin >> choice;

            // update the selected field
            switch (choice)
            {
            case 1:
            {
                string fname;
                cout << "Enter new first name:" << endl;
                cin >> fname;
                students[i].setFirstName(fname);
                break;
            }
            case 2:
            {
                string lname;
                cout << "Enter new last name:" << endl;
                cin >> lname;
                students[i].setLastName(lname);
                break;
            }
            }
            /*case 3:
            {
                bool fee;
                cout << "Enter new fee status (0 for unpaid, 1 for paid):" << endl;
                cin >> fee;

                students[i].*/