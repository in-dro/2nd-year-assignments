#include<iostream>
#include<string>

using namespace std;

struct student
{
    string  Name;
    string  Department;
    string  Favourite_sports;
    string  phone_NO;
};
 void createStudentdata (student &s)
{
int n;
	cout<<"How many recordes you want to store? ";
	cin>>n;
	int p=n;
	student s1[n];

}
void ReadStudentData(student &s)
{   
    cout<<"Name         :   "<<getline(cin, s.Name)<<endl;
    cout<<"Department         :   "<<getline(cin, s.Department)<<endl;
    cout<<"Favourite sports :   "<<getline(cin, s.Favourite_sports)<<endl;
    cout<<"phone NO       :   "<<getline(cin, s.phone_NO)<<endl;
      
   
}
void PrintStudentData(student &s)
{
    cout<<"Name         :   "<<s.Name<<endl;
    cout<<"Department         :   "<<s.Department<<endl;
    cout<<"Favourite sports   :   "<<s.Favourite_sports<<endl;
    cout<<"Year         :   "<<s.phone_NO<<endl;
}

int main()
{
    student s_arr;

    ReadStudentData(s_arr);
    PrintStudentData(s_arr);

}

    