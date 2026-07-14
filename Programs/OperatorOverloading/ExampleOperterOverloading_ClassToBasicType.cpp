#include <iostream>

class Fraction {
private:
    int num, den;
public:
    Fraction(int n, int d) : num(n), den(d) {}

    // Overloading the float cast operator: Class -> float
    operator float() const {
        return static_cast<float>(num) / den;
    }
};

int main() {
    Fraction f(3, 4);
    
    // Implicit conversion from Class (Fraction) to basic type (float)
    float val = f; 
    std::cout << "Value: " << val << "\n"; // Outputs: Value: 0.75
}