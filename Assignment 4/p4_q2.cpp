#include <bits/stdc++.h>
using namespace std;

class Person
{
protected:
	string name;
	int age;
	string gender;

public:
	Person(); // Default Constructor
	void display();
	void read();
};
void Person::read()
{
	//	cout<<"Reading Person Data: "<<endl;
	cout << "Enter Name: ";
	cin >> this->name;
	cout << "Enter Age: ";
	cin >> this->age;
	cout << "Enter Gender: ";
	cin >> this->gender;
}
Person::Person()
{
	name = '\0';
	age = 0;
	gender = "Male";
}
void Person::display()
{

	cout << "Name: " << this->name << endl
		 << "Age: " << this->age << "Gender: " << this->gender << endl;
}
// Person::~Person(){
//	delete[] this->name;
//	delete[] this->gender;
// }
class Student : public Person
{
private:
	int year;
	string dept;

public:
	Student();
	void display();
	void read();
};
void Student::read()
{
	cout << "Reading Student Data: " << endl;
	Person::read();
	cout << "Enter Year of the student: ";
	cin >> this->year;
	cout << "Enter Department Of the Student: ";
	cin >> this->dept;
}
Student::Student()
{
	year = 0;
	dept = "NONE";
}
void Student::display()
{
	cout << "Displaying Student Data: " << endl;
	Person::display();
	cout << "Deapartment: " << this->dept << endl
		 << "Year: " << this->year << endl;
}
class Clark : public Person
{
private:
	int workload;
	int salary;

public:
	Clark();
	void display();
	void read();
};
void Clark::read()
{
	cout << "Reading Clark Data: " << endl;
	Person::read();
	cout << "Enter WorkLoad: ";
	cin >> this->workload;
	cout << "Enter Salary: ";
	cin >> this->salary;
}
void Clark::display()
{
	cout << "Displaying Clark Data:" << endl;
	Person::display();
	cout << "WorkLoad: " << this->workload << endl
		 << "Salary: " << this->salary << endl;
}
Clark::Clark()
{
	this->workload = 0;
	this->salary = 0;
}
class Proffesor : public Person
{
private:
	int courseLoad;
	int salary;

public:
	Proffesor();
	void display();
	void read();
};
void Proffesor::read()
{
	Person::read();
	cout << "Enter CourseLoad: ";
	//	cin>this->courseLoad;
	cin >> courseLoad;
	cout << "Enter the Salary of the Proffesor: ";
	cin >> this->salary;
}
void Proffesor::display()
{
	Person::display();
	cout << "CourseLoad: " << this->courseLoad << endl
		 << "Salary: " << this->salary << endl;
}
Proffesor::Proffesor()
{
	courseLoad = 0;
	salary = 0;
}
int main()
{
	Student *s = new Student();
	s->read();
	s->display();

	Clark *c = new Clark();
	c->read();
	c->display();

	Proffesor *p = new Proffesor();
	p->read();
	p->read();
}
