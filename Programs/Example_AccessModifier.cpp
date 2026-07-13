#include <iostream>
#include <string>
using namespace std;

class MyClass {
public:
    int publicData;

    void publicFunction() {
        cout << "This is a public member function." << endl;
    }

private:
    int privateData;

    void privateFunction() {
        cout << "This is a private member function." << endl;
    }

protected:
    int protectedData;

    void protectedFunction() {
        cout << "This is a protected member function." << endl;
    }
};

class Derived : public MyClass {
public:
    void accessBaseMembers() {
        publicData = 10;       // Accessible (public member)
        publicFunction();      // Accessible (public member function)

        // privateData = 20;   // Not accessible (private member)
        // privateFunction();  // Not accessible (private member function)

        protectedData = 30;    // Accessible (protected member)
        protectedFunction();   // Accessible (protected member function)
    }
};

int main() {
    MyClass obj;
    obj.publicData = 42;       // Accessible (public member)
    obj.publicFunction();      // Accessible (public member function)

    // obj.privateData = 55;   // Not accessible (private member)
    // obj.privateFunction();  // Not accessible (private member function)
    // obj.protectedData = 20; // Not accessible (protected member)
    // obj.protectedFunction();// Not accessible (protected member function)

    Derived derivedObj;
    derivedObj.accessBaseMembers();  // Accessing base class members from derived class

    return 0;
}