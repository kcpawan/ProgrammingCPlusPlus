#include<iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overload unary - operator to negate a Complex object
    Complex operator - () const {
        return Complex(-real, -imag);
    }
};

int main() {
    Complex c1(3, 4);
    Complex c2 = -c1;
    std::cout << "Result: " << c2.real << " + " << c2.imag << "i" << std::endl;
    
    return 0;
}