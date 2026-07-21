#include <iostream>
using namespace std;

/*
Author : Pawan KC
Date: 14/07/2027
Program Description:This program exibits the Multipath Ambiguity in C++.
                    Multipath Ambiguity in C++ happens in multiple inheritance when a derived class inherits from two or more base classes that themselves inherit from a common base class.
                    This creates multiple copies of the common base class in the inheritance hierarchy, leading to ambiguity when accessing its members.
*/


class A {
public:
   void func() { cout << "I am in class A" << endl; }
};
class B {
public:
   void func() { cout << "I am in class B" << endl; }
};
class C : public A, public B {};
int main() {
   C obj;
   // obj.func(); //  Error: ambiguous
   obj.A::func(); //  Calls A's func
   obj.B::func(); //  Calls B's func
}

/*
class C : public A, public B {
public:
using A::func; // Always use A's func by default
};

class C : public A, public B {
public:
void func() override {
A::func();
B::func();
}

*/
