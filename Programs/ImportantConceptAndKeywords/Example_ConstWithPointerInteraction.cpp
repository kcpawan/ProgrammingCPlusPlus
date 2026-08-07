#include<iostream>
using namespace std;
/*
Author : Pawan KC
Date:
Program Description:
*/

class Person {
private:
    string name;
    int age;
    
public:
    Person(const string& n, int a) : name(n), age(a) {}
    
    // Const method - can read, can't write
    void display() const {
        cout << name << ", " << age << endl;
        // this->name = "Changed";  //  Error!  -- "Beacuse name is const"
    }
    
    // Non-const method - can read and write
    void setAge(int newAge) {
        age = newAge;  //  Can modify
        // this->display();  // Can call const from non-const
    }
    
    // Show pointer usage
    void showPointerDetails() const {
        cout << "\nAddress of this: " << this << endl;
        cout << "Address of this->name: " << &(this->name) << endl;
        cout << "Address of this->age: " << &(this->age) << endl;
    }
};

int main() {
    Person p("Pawan", 25);
    
    // Regular object - can call both
    p.display();
    p.setAge(30);
    
    // Pointer to object
    Person* ptr = &p;
    ptr->display();      // Arrow operator
    (*ptr).display();    // Dot operator (dereference first)
    
    // Const pointer to object
    const Person* cptr = &p;
    cptr->display();     // const method only
    // cptr->setAge(35); // Error!
    
    // Show memory addresses
    p.showPointerDetails();
    
    return 0;
}