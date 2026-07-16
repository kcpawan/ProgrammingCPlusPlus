#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date: 15/07/2026
Program Description: This programs exibhits inheritance. Here we have a base class Animal and two derived classes Dog and Cat.
                     Both derived classes will be aquiring the member attributes and member function from base class.
                     Here both base class Dog and Cat will be aquiring the functions eat() and sleep() from base class Animal.
                     Hence it is not required to re-write eat() and sleep() functions from derived class Dog and Cat. 
                     That exibits the code reusability while using inheritance.
*/



class Animal {
public:
    void eat() {
        std::cout << "This animal eats food.\n";
    }
    void sleep() {
        std::cout << "This animal sleeps.\n";
    }
};

class Dog : public Animal {
public:
    void bark() {
        std::cout << "This animal barks.\n";
    }
};

class Cat : public Animal {
public:
    void meow() {
        std::cout << "This animal meows.\n";
    }
};

int main() {
    Dog d;
    Cat c;

    std::cout << "Dog behaviour:\n";
    d.eat();
    d.sleep();
    d.bark();

    std::cout << "\nCat behaviour:\n";
    c.eat();
    c.sleep();
    c.meow();

    return 0;
}