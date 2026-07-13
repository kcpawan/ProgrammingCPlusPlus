#include <iostream>
using namespace std;

class Person {
private:
string name;
int age;

public:
// Default constructor
Person() {
name = "Unknown";
age = 0;
}

// Parameterized constructor
Person(const string& name, int age) {
this->name = name;
this->age = age;
}

// Member function to display person's information
void display() const {
cout << "Name: " << name << ", Age: " << age << endl;
}
};

int main() {
// Creating instances using constructors
Person person1; // Using default constructor
Person person2("Unstop", 7); // Using parameterized constructor

// Displaying person information
cout << "Person 1: ";
person1.display();
cout << "Person 2: ";
person2.display();

return 0;
}