#include <bits/stdc++.h>
using namespace std;

class Vehicle
{
protected:
	int price;		// Price
	string manufac; // Manufacturer
public:
	Vehicle();							 // Default constructor
	Vehicle(int, string);				 // Parametrized constructor
	void readData();					 // Read data
	void display();						 // Display data
};
Vehicle::Vehicle()
{
	this->price = 0;
	this->manufac = "Invalid!";
	// Default Constructor
}
Vehicle::Vehicle(int p, string m)
{
	this->price = p;
	//	name= new char[size(m)];
	this->manufac = m;
	//	strcpy(this->manufac,name);
}
// Vehicle::Vehicle(const Vehicle& obj)
void Vehicle::readData()
{
	cout << "Enter Price Of The Product: ";
	cin >> this->price;
	cout << "Enter the name Of The Manufacturer: ";
	cin >> this->manufac;
}
void Vehicle::display()
{
	cout << "Price: " << this->price << endl
		 << "ManuFacturer: " << this->manufac << endl;
}
class Car : public Vehicle
{
private:
	string color; // Color
	int seatNo;	  // Number Of Seats
	string model; // Model
public:
	Car() {}					// Default constructor
	Car(string, int, string);	// Parametrized constructor
	Car(const Car &);			// Copy constructor
	Car operator=(const Car &); // Assignment operator
	void readData2();			// Read data
	void displayData2();		// Display data
};
Car::Car(string color, int seatNo, string model)
{
	this->color = color;
	this->seatNo = seatNo;
	this->model = model;
}
void Car::readData2()
{
	Vehicle::readData();
	cout << "Enter Color Of The Car: ";
	cin >> this->color;
	cout << "Enter the name Of The Model: ";
	cin >> this->model;
	cout << "Enter the Total number of Seat: ";
	cin >> this->seatNo;
}
void Car::displayData2()
{
	Vehicle::display();
	cout << "Color: " << this->color << endl;
	cout << "Model Name: " << this->model << endl
		 << "Total Seat Number: " << this->seatNo << endl;
}

int main()
{
	Car *v1 = new Car();
	v1->readData2();
	v1->displayData2();
}
