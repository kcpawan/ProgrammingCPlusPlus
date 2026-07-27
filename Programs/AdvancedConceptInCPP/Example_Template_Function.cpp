#include <iostream>
#include <string>
#include <vector>
using namespace std;

template <typename T>
void swapValues(T &a, T &b) {
    cout << "Swapping values of type: " << typeid(T).name() << endl;
    T temp = a;
    a = b;
    b = temp;
}

// Template specialization for pointers
template <typename T>
void swapValues(T* &a, T* &b) {
    T* temp = a;
    a = b;
    b = temp;
}

int main() {
    // Basic types
    int x = 10, y = 20;
    double p = 1.1, q = 2.2;
    string s1 = "cat", s2 = "dog";
    
    // Swap different types
    swapValues(x, y);
    swapValues(p, q);
    swapValues(s1, s2);
    
    // Verify results
    cout << "int: " << x << " " << y << "\n";
    cout << "double: " << p << " " << q << "\n";
    cout << "string: " << s1 << " " << s2 << "\n";
    
    // Pointer swapping
    int* ptr1 = &x;
    int* ptr2 = &y;
    swapValues(ptr1, ptr2);  // Uses pointer specialization
    cout << "Pointers: " << *ptr1 << " " << *ptr2 << "\n";
    
    return 0;
}