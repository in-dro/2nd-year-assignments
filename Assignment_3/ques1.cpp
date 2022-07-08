#include <iostream>
using namespace std;

class Student {
    private:
        string name;
        int age;
        string department;
        int year;
    public:
        void ReadStudentData();
        void PrintStudentData();
};

void Student::ReadStudentData(){
    cin >> this->name;
    cin >> this->age;
    cin >> this->department;
    cin >> this->year;
}

void Student::PrintStudentData(){
    cout << this->name << "\n";
    cout << this->age << "\n";
    cout << this->department << "\n";
    cout << this->year << "\n";
}

int main(){
    int N;
    cout << "Enter N: ";
    cin >> N;
    Student students[100];
    for(int i=0; i < N; i++)
        students[i].ReadStudentData();
    
    for(int i=0; i < N; i++)
        students[i].PrintStudentData();
    return 0;
}
Q1.cpp
Displaying Q1.cpp.