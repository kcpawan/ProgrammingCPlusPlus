#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date: 14/07/2027
Program Description:This program exibits the Dynamic Binding.
                    Dynamic binding in C++ means that a function call is connected to its actual definition at runtime (when the program runs) rather than at compile-time (when the program is built).
*/

class Animal {
public:
    // The "virtual" keyword tells C++ to use dynamic binding here
    virtual void makeSound() { 
        cout << "Generic animal sound\n"; 
    }
};

class Dog : public Animal {
public:
    void makeSound() override { 
        std::cout << "Woof!\n"; 
    }
};

int main(){
    // A base class pointer pointing to a derived (child) class object
    Animal* myAnimal = new Dog(); 

    // Dynamic binding occurs here! 
    // Even though the pointer is an "Animal*", C++ checks the actual object at runtime.
    // Because the actual object is a Dog, it calls Dog's makeSound().
    myAnimal->makeSound(); // Outputs: Woof!

    delete myAnimal;
    return 0;
}