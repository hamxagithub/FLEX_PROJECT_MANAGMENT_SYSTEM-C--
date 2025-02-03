
#include<iostream>
using  namespace std;
#include "Person.h"
Administer::Administer(Course* C1, Section* S1)
{
    cout << "How many course are being offered?" << endl;
    cin >> number;
    C1 = new Course[number];
    this->course = C1;
    cout << "How many section are there?" << endl;
    cin >> size;
    S1 = new Section[size];
    this->section = S1;
    teacher = nullptr;
    no = 0;
}
Administer::Administer(const Administer& A1)
{
    number = A1.number;
    size = A1.size;
    course = new Course[number];
    for (int i = 0; i < number; i++)
    {
        course[i] = A1.course[i];
    }
    section = new Section[size];
    for (int i = 0; i < size; i++)
    {
        section[i] = A1.section[i];
    }
}
Administer::~Administer()
{
    if (section != nullptr)
    {
        delete[]section;
    }
    if (course != nullptr)
    {
        delete[]course;
    }
}
Section* Administer::setSection()
{
    cout << "Input the data..." << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Input the name of section " << i + 1 << endl;
        section[i].setName();
    }
    return section;
}
void Administer::PrintSection()
{
    for (int i = 0; i < size; i++)
    {
        cout << i + 1 << " " << section[i].getName() << endl;
    }
}
Course* Administer::setCourse()
{
    cout << "Input the data...." << endl;
    for (int i = 0; i < number; i++)
    {
        course[i].setName();
        bool checker = true;
        while (checker)
        {
            cout << "Which section are having this course? Press the corresponding key" << endl;
            PrintSection();
            cout << size + 1 << " " << "Exit" << endl;
            int n = _getch() - '0';
            if (n < size + 1)
            {
                course[i].setSection(section[n - 1]);
            }
            else if (n >= size)
            {
                checker = false;
            }
        }

    }
    return course;
}
void Administer::getCourse() const
{
    for (int i = 0; i < number; i++)
    {
        cout << i + 1 << " " << course[i].getName() << endl;
        cout << "Sections offered" << endl;
        course[i].getSection();
        cout << endl;
    }
}
void Administer::addStudent(UnSorted& S2) const
{
    Student S1;
    S1.Input();
    S2.Add(S1);
}
void Administer::addStudent(UnSorted& S, const Student* S1) const
{
    if (S1->section != nullptr && S1->course != nullptr)
    {
        for (int i = 0; i < S1->number; i++)
        {
            for (int j = 0; j < number; j++)
            {
                if (S1->course[i] == course[j].getName())
                {
                    course[j].findSection(S1->section[i]).addStudent(*S1);
                    break;
                }
            }
        }
        S.shrink(*S1);
    }
}
Teacher* Administer::addTeacher(const Course* C1)
{
    if (no == 0)
    {
        teacher = new Teacher[no + 1];
        teacher->Input();
        cout << "Which Course must be assigned to the teacher?" << endl;
        getCourse();
        string course;
        cin >> course;
        cout << "Sections for this course" << endl;
        cout << "Number of sections" << endl;
        int n;
        cin >> n;
        string* section = new string[n];
        cout << "Names" << endl;
        for (int j = 0; j < n; j++)
        {
            cin >> section[j];
        }
        for (int i = 0; i < number; i++)
        {
            if (course == this->course[i].getName())
            {
                teacher->setCourse(this->course[i], section, n);
            }
        }
    }
    else
    {
        Teacher* temp;
        temp = new Teacher[no + 1];
        for (int i = 0; i < no + 1; i++)
        {
            if (i < no)
            {
                temp[i] = teacher[i];
            }
            else
            {
                temp[i].Input();
                cout << "Which Course must be assigned to the teacher?" << endl;
                getCourse();
                string course;
                cin >> course;
                cout << "Sections for this course" << endl;
                cout << "Number of sections" << endl;
                int n;
                cin >> n;
                string* section = new string[n];
                cout << "Names" << endl;
                for (int j = 0; j < n; j++)
                {
                    cin >> section[j];
                }
                for (int j = 0; j < number; i++)
                {
                    if (course == this->course[i].getName())
                    {
                        temp[i].setCourse(this->course[i], section, n);
                    }
                }
            }
        }
        delete[] teacher;
        teacher = temp;
    }
    no++;
    return teacher;
}
void Administer::editStudent()
{
    cout << "Enter the roll number of the student to edit :" << endl;
    string rollNo;
    cin >> rollNo;
    Student* stud = nullptr;
    for (int i = 0; i < number; i++)
    {
        stud = course[i].findSStudent(rollNo);
        if (stud != nullptr)
        {
            break;
        }
    }
    stud->Display();
    cout << "Select the field to edit:" << endl;
    cout << "1. First Name" << endl;
    cout << "2. Last Name" << endl;
    cout << "3. Fee Status" << endl;
    cout << "4. Address" << endl;
    cout << "5. Contact No" << endl;
    stud->Edit();
}