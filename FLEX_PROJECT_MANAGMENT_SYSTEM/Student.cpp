
#include "Person.h"
int Student::count = 0;
Student::Student() {
	section = nullptr;
	size = 0;
	course = nullptr;
	number = 0;
	ID = "";
	FeeStatus = 0;
	Attendence = 0;
	marks = 0.0;
	count++;
}
Student::Student(const Student& S1) :Person(S1)
{
	ID = S1.ID;
	FeeStatus = S1.FeeStatus;
	size = S1.size;
	number = S1.number;
	section = new string[size];
	for (int i = 0; i < size; i++)
	{
		section[i] = S1.section[i];
	}

	course = new string[number];
	for (int i = 0; i < number; i++)
	{
		course[i] = S1.course[i];
	}
}
Student::~Student() {
	if (section != nullptr)
	{
		delete[]section;
	}
	if (course != nullptr)
	{
		delete[]course;
	}
	count--;
}

void Student::Edit() {
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			string fname;
			cout << "Enter new first name:" << endl;
			cin >> fname;
			setFirstName(fname);
			break;
		}
		case 2:
		{
			string lname;
			cout << "Enter new last name:" << endl;
			cin >> lname;
			setLastName(lname);
			break;
		}
		case 3:
		{
			bool fee;
			cout << "Enter new fee status (0 for unpaid, 1 for paid):" << endl;
			cin >> fee;
			setFeeStatus(fee);
			break;
		}
		case 4:
		{
			string address;
			cout << "Enter new address:" << endl;
			cin.ignore();
			getline(cin, address);
			setAddress(address);
			break;
		}
		case 5:
		{
			string contact;
			cout << "Enter new contact number:" << endl;
			cin >> contact;
			setContact(contact);
			break;
		}
		default:
		{
			cout << "Invalid choice." << endl;
			break;
		}
		}	
}




void Student::Input() {
	//Enter the data
	//call all the setters of class 
	//except marks
	cout << "Enter the first name" << endl;
	string fname;
	cin >> fname;
	setFirstName(fname);
	cout << "Enter the last name" << endl;
	string lname;
	cin >> lname;
	setLastName(lname);
	cout << "Enter the gender" << endl;
	string gender;
	cin >> gender;
	setGender(gender);
	cout << "Enter the department name" << endl;
	department department;
	cin >> department;
	setDepartment(department);
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
	cout << "Enter the Blood Group" << endl;
	string bgroup;
	cin >> bgroup;
	setBloodGroup(bgroup);
	cout << "Enter the Registration date" << endl;
	Date registration{};
	cin >> registration;
	setRegistrationDate(registration);
	cout << "Setting the ID" << endl;
	setID();
	cout << "Enter the Fee status" << endl;
	bool fee;
	cin >> fee;
	setFeeStatus(fee);
	cout << "Enter the UserName" << endl;
	string User;
	cin >> User;
	setUserName(User);
	cout << "Enter the Password" << endl;
	string Pass;
	if (cin.peek() == '\n')
	{
		cin.ignore();
	}
	getline(cin, Pass);
	setPassword(Pass);
}

void Student::Display()
{
	cout << "Name" << endl;
	cout << getFirstName() << '\t'
		<< getLastName() << endl;
	cout << "Department name" << endl;
	cout << getDepartment();
	cout << "Qualification" << endl;
	cout << getQualification() << endl;
	cout << "Gender" << endl;
	cout << getGender() << endl;
	cout << "Address" << endl;
	cout << getAddress() << endl;
	cout << "Contact Number" << endl;
	cout << getContact() << endl;
	cout << "Blood Group" << endl;
	cout << getBloodGroup() << endl;
	cout << "Registration date" << endl;
	cout << getRegistrationDate() << endl;
	cout << "ID" << endl;
	cout << getID();
	cout << "Enter the Fee status" << endl;
	getFeeStatus();
}

string Student::getID()const {
	return ID;
}

void Student::setID() {
	cout << "Enter the batch number" << endl;
	int temp;
	cin >> temp;
	stringstream stream;
	stream << temp;
	string str;
	stream >> str;
	ID += str + "F-";
	temp = count;
	int tcount = 0;
	while (temp != 0)
	{
		temp /= 10;
		tcount++;
	}
	tcount = 4 - tcount;
	while (tcount > 0)
	{
		ID += "0";
		tcount--;
	}
	stringstream st;
	st << count;
	st >> str;
	ID += str;
}

void Student::getFeeStatus() const {
	if (FeeStatus)
	{
		cout << "Fee : Paid" << endl;
	}
	else
	{
		cout << "Fee: UnPaid" << endl;
	}
}

void Student::setFeeStatus(bool FeeStatus) {
	this->FeeStatus = FeeStatus;
}

void Student::setCourse(const Administer* A1, UnSorted& S)
{
	cout << "How many course you are taking?" << endl;
	cin >> number;
	size = number;
	course = new string[number];
	section = new string[size];
	for (int i = 0; i < number; i++)
	{
		cout << "Choose from the following courses and then select the offered section for that course" << endl;
		A1->getCourse();
		cout << endl;
		cin >> course[i];
		cin >> section[i];
		A1->addStudent(S, this);
	}
}
char Student::getAttendence()
{
	return Attendence;
}
Student& Student :: operator=(const Student S1)
{

	setFirstName(S1.getFirstName());
	setLastName(S1.getLastName());
	setDepartment(S1.getDepartment());
	setQualification(S1.getQualification());
	setContact(S1.getContact());
	setAddress(S1.getAddress());
	setGender(S1.getGender());
	setRegistrationDate(S1.getRegistrationDate());
	setUserName(S1.getUserName());;
	setPassword(S1.getPassword());
	setBloodGroup(S1.getBloodGroup());
	ID = S1.ID;
	FeeStatus = S1.FeeStatus;
	size = S1.size;
	number = S1.number;
	section = new string[size];
	for (int i = 0; i < size; i++)
	{
		section[i] = S1.section[i];
	}

	course = new string[number];
	for (int i = 0; i < number; i++)
	{
		course[i] = S1.course[i];
	}
	return *this;
}


