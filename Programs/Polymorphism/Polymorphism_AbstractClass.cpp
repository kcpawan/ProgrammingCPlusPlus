#include <iostream>

class AbstractClass {
public:
virtual void pureVirtualFunction() = 0; // Pure virtual function

void concreteFunction() {
std::cout << "Concrete function in AbstractClass" << std::endl;}
};

class Derived : public AbstractClass {
public:
void pureVirtualFunction() override {
std::cout << "Derived class implementation of pureVirtualFunction" << std::endl;}

void concreteFunction() {
std::cout << "Concrete function in Derived class" << std::endl;}
};

int main() {
// AbstractClass obj; // Error: Cannot create an object of an abstract class

Derived d;
d.pureVirtualFunction(); // Calls the overridden function in Derived
d.concreteFunction(); // Calls the function in Derived class

AbstractClass* ptr = &d;
ptr->pureVirtualFunction(); // Calls the overridden function in Derived
ptr->concreteFunction(); // Calls the function in AbstractClass

return 0;
}