#include <iostream>
using namespace std;

class Person {
	public:
string name;
int age;

// Default Constructor
Person() : name("Unknown"), age(0) {
	cout << "Default constructor called" << endl;
}

	// Parameterized Constructor
	Person(string n, int a) : name(n), age(a) {
		cout << "Parameterized constructor called for " << name << endl;
	}

// Destructor
~Person() {
	cout << "Destructor called for " << name << endl;
	}

	void display() const {
		cout << "Name: " << name << ", Age: " << age << endl;
	}
};

int main() {

	// Using new operator to create a single Person object
	Person* singlePerson = new Person("Aayusha", 20);
	singlePerson->display();

	// Deallocating the single Person object
	delete singlePerson;

// Using new operator to create an array of Person objects
int numPersons = 3;

	Person* personArray = new Person[numPersons];

	// Manually initializing each element in the array
	personArray[0] = Person("Pallav", 19);

personArray[1] = Person("Sulabh", 23);
personArray[2] = Person("Neha", 22);

// Accessing the array of Person objects
for (int i = 0; i < numPersons; ++i) {
	personArray[i].display();
	}

// Deallocating the array of Person objects
delete[] personArray;

return 0;
}
