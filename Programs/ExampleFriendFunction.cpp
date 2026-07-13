#include <iostream>
using namespace std;

// Forward declaration
class B;

class A {
private:
    int valueA;
    
public:
   
    A(int v) : valueA(v) {}
    
    // Declare friend function that can access both classes
    friend void swapValues(A& a, B& b);
};

class B {
private:
    int valueB;
    
public:

    B(int v) : valueB(v) {}
    
    // Friend of both classes
    friend void swapValues(A& a, B& b);
};

// Friend function can access private members of both classes
void swapValues(A& a, B& b) {
    int temp = a.valueA;
    a.valueA = b.valueB;
    b.valueB = temp;
}

int main() {
    A objA(10);
    B objB(20);
    
    cout << "Before swap: A = 10, B = 20" << endl;
    swapValues(objA, objB);
    cout << "After swap: A = ?, B = ?" << endl;
    
    // We can't access directly, but we can add display methods
    return 0;
}