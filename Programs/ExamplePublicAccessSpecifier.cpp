#include <iostream>
#include <string>   // Required for std::string

using namespace std;

// Define a class called 'Student'
class Student {
public:             // Access specifier
    string name;    // Data member
    int rollNo;     // Data member

    void display() {                    // Member function
        cout << "Name: " << name << endl;
        cout << "RollNo: " << rollNo << endl;
    }
};

int main() {
    // Creating an object of the Student class
    Student s1;

    s1.name = "Ankit";
    s1.rollNo = 2;
    s1.display();

    return 0;   // Indicate successful program completion
}