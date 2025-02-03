
#include "Person.h"

string Person::getFirstName() const {
	return this->firstName;
}

void Person::setFirstName(string firstName) {
	this->firstName = firstName;
}

string Person::getLastName() const {
	return this->lastName;
}

void Person::setLastName(string lastName) {
	this->lastName = lastName;
}

department Person::getDepartment() const {
	return this->Department;
}

void Person::setDepartment(department d1) {
	Department = d1;
}

string Person::getQualification() const {
	return	this->Qualification;
}

void Person::setQualification(string Qualification) {
	this->Qualification = Qualification;
}

string Person::getContact() const {
	return this->Contact;
}

void Person::setContact(string Contact) {
	this->Contact = Contact;
}

string Person::getAddress()const {
	return this->Address;
}

void Person::setAddress(string Address) {
	this->Address = Address;
}

string Person::getGender()const {
	return this->Gender;
}

void Person::setGender(string Gender) {
	this->Gender = Gender;
}

Date Person::getRegistrationDate() const {
	return this->registrationDate;
}

void Person::setRegistrationDate(Date registrationDate) {
	this->registrationDate = registrationDate;
}

string Person::getUserName()const {
	return this->UserName;
}

void Person::setUserName(string UserName) {
	this->UserName = UserName;
}

string Person::getPassword()const {
	return this->Password;
}

void Person::setPassword(string Password) {
	this->Password = Password;
}

string Person::getBloodGroup()const {
	return 	this->BloodGroup;
}

void Person::setBloodGroup(string BloodGroup) {
	this->BloodGroup = BloodGroup;
}
void Person::setSalary(double salary) 
{
	this->salary = salary;
}


Person::Person()
{
	firstName = "";
	lastName = "";
	Qualification = "";
	Contact = "";
	Address = "";
	Gender = "";
	registrationDate.day = registrationDate.month = registrationDate.year = 0;
	UserName = "";
	Password = "";
	BloodGroup = "";
}

Person::Person(const Person& P) : Department(P.Department)
{
	firstName = P.firstName;
	lastName = P.lastName;
	Qualification = P.Qualification;
	Contact = P.Contact;
	Address = P.Address;
	Gender = P.Gender;
	registrationDate = P.registrationDate;
	UserName = P.UserName;
	Password = P.Password;
	BloodGroup = P.BloodGroup;
}
Person::~Person()
{

}