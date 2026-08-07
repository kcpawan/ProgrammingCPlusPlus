#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;
    
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Member function for addition
    Complex add(Complex c) {
        return Complex(real + c.real, imag + c.imag);
    }
    
    // Friend function for addition (operator overloading style)
    friend Complex addFriend(Complex c1, Complex c2);
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

// Friend function for addition
Complex addFriend(Complex c1, Complex c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

int main() {
    Complex c1(3, 4);
    Complex c2(1, 2);
    
    cout << "c1 = ";
    c1.display();
    cout << "c2 = ";
    c2.display();
    
    // Using member function
    Complex c3 = c1.add(c2);
    cout << "Using member function: ";
    c3.display();
    
    // Using friend function
    Complex c4 = addFriend(c1, c2);
    cout << "Using friend function: ";
    c4.display();
    
    return 0;
}