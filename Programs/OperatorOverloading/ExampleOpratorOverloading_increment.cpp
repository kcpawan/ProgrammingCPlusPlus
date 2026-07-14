#include <iostream>
using namespace std;

class Counter {
private:
    int value;
    
public:
    Counter(int v = 0) : value(v) {}
    
    // Prefix increment: ++obj
    Counter operator++() {
        ++value;          // Increment first
        return *this;     // Return updated object
    }
    
    // Postfix increment: obj++
    Counter operator++(int) {  // int parameter is dummy for postfix
        Counter temp = *this;  // Save old state
        ++value;               // Increment
        return temp;           // Return old state
    }
    
    void display() {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Counter c(5);
    
    cout << "Original: ";
    c.display();  // Output: 5
    
    Counter c1 = ++c;  // Prefix
    cout << "After prefix ++: ";
    c.display();       // Output: 6
    cout << "Returned: ";
    c1.display();      // Output: 6
    
    Counter c2 = c++;  // Postfix
    cout << "After postfix ++: ";
    c.display();       // Output: 7
    cout << "Returned: ";
    c2.display();      // Output: 6
    
    return 0;
}