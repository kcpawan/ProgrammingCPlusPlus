#include <iostream>
using namespace std;

class Base {
    public:
    void display() { cout << "I am Base Class" << endl; }
};

class Derived : public Base {
    public:
    void display() { cout << "I am Derived Class" << endl; }
};


int main() {
    Base* ptr; 
    Derived d;
    ptr = &d;

    ptr->display();
    return 0;
}
