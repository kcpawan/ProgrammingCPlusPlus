#include <iostream>
using namespace std;

// Base class
class Animal {
    public:
        // Virtual function enables overriding in derived classes
    virtual void speak() {
        cout << "Animal makes a sound" << endl;
    }

    // Pro Tip: Always use a virtual destructor in base classes to prevent memory leaks virtual ~Animal() {}
};

// Derived class
class Dog : public Animal {
    public:
        //'override' keyword (C++11+) ensures the signatures match correctly 
    void speak() override {
        cout << "Woof! Woof!" << endl;
    }
};

int main() {
// 1. Create a base class pointer
    Animal* ptr;

// 2. Create an object of the derived class
    Dog myDog;

// 3. Point the base pointer to the derived class object
    ptr = &myDog;

 /* 4. Call the virtual function through the pointer 
Because 'speak' is virtual, the program performs "late binding" and calls the Dog version, not the Animal version.*/
    
    ptr->speak(); 

    return 0;
}

