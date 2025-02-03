#include"Student.h"
class Section
{
	string name;
	Student* students;
public:
	Section();
	~Section();
	void setName();
	void addStudent();
	void display();
};

