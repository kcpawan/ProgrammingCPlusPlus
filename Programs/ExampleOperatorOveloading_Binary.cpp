#include<iostream>
using namespace std;

class Complex {
public:
    int real, imag;

    Complex(int r = 0, int i = 0) : real(r), imag(i) {}

    // Overload * operator to multiply two Complex objects
    Complex operator * (const Complex& obj) {
        Complex temp;
        temp.real = real * obj.real - imag * obj.imag;
        temp.imag = real * obj.imag + imag * obj.real;
        return temp;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 * c2;
    std::cout << "Result: " << c3.real << " + " << c3.imag << "i" << std::endl;
    return 0;
}