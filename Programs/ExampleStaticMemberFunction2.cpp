#include <iostream>
using namespace std; 


class MyClass {
public:
static int staticValue; // Static data member declaration

static int getStaticValue() {
return staticValue; // Static member function to access the static data member
}
};

// Initialization of the static data member outside the class
int MyClass::staticValue = 101;

int main() {
// Accessing the static data member using the static member function
int value = MyClass::getStaticValue();
std::cout << "Value of Static Data Member: " << value << std::endl;

return 0;
}