#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int a {10};
    int* p {&a};
    
    cout << "=== MEMORY VISUALIZATION ===" << endl;
    cout << endl;
    
    // Values
    cout << "1. Values:" << endl;
    cout << "   a  = " << a << endl;
    cout << "   p  = " << p << " (address)" << endl;
    cout << "   *p = " << *p << " (value at address). This is called dereferencing." << endl;
    cout << endl;
    
    // Addresses
    cout << "2. Addresses:" << endl;
    cout << "   &a  = " << &a << endl;
    cout << "   &p  = " << &p << endl;
    cout << "   (Note: &p is address of pointer itself)" << endl;
    cout << endl;
    
    // Sizes
    cout << "3. Sizes (bytes):" << endl;
    cout << "   sizeof(a)  = " << sizeof(a) << endl;
    cout << "   sizeof(p)  = " << sizeof(p) << endl;
    cout << "   sizeof(*p) = " << sizeof(*p) << endl;
    cout << endl;
    
    // Memory layout
    cout << "4. Memory Layout:" << endl;
    cout << "   Address: " << &a << "  ->  a: " << a << endl;
    cout << "   Address: " << &p << "  ->  p: " << p << " (points to " << &a << ")" << endl;
    cout << endl;
    
    // Dereferencing explanation
    cout << "5. Dereferencing Process:" << endl;
    cout << "   p contains: " << p << endl;
    cout << "   *p reads value at that address: " << *p << endl;
    cout << "   Since *p is int, it reads 4 bytes starting at " << p << endl;
    
    return 0;
}