#include <iostream>
using namespace std;

class student {
public:
    int n;
    // Constructor
    student(int a) : n(a) {}
    
    // Const member function to display n
    void show() const {
        cout << n << endl;
    }
    
    // Modify function (corrected logic)
    void modify(int a) {
        n = a;  // Assuming 'q' was meant to be 'n'
    }
};

int main() {
    // Create student object with value 50
    student s1(10);
    s1.modify(20);  // Modify n to 20
    
   student s2(30);  // Const object can only call const functions
    s2.show();
   
    return 0;
}