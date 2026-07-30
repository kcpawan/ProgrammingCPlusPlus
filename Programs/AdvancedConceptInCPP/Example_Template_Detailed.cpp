#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 1. Base template class
template <typename T>
class Calculator {
private:
    T value;
    
public:
    Calculator(T v = 0) : value(v) {}
    
    // 2. Operator overloading inside template class
    Calculator<T> operator+(const Calculator<T>& other) const {
        cout << "Template class operator+" << endl;
        return Calculator<T>(value + other.value);
    }
    
    // 3. Template method inside template class
    template <typename U>
    auto add(const U& other) const -> decltype(value + other) {
        cout << "Template method inside template class" << endl;
        return value + other;
    }
    
    // 4. Friend function with template
    template <typename U>
    friend ostream& operator<<(ostream& os, const Calculator<U>& calc);
    
    T getValue() const { return value; }
};

// 5. Friend function implementation (also template)
template <typename T>
ostream& operator<<(ostream& os, const Calculator<T>& calc) {
    os << "Calculator(" << calc.value << ")";
    return os;
}

// 6. Function template with overload
template <typename T>
T multiply(T a, T b) {
    cout << "Template multiply (same type)" << endl;
    return a * b;
}

template <typename T1, typename T2>
auto multiply(T1 a, T2 b) -> decltype(a * b) {
    cout << "Template multiply (different types)" << endl;
    return a * b;
}

// 7. Overloaded regular function
int multiply(int a, int b) {
    cout << "Regular multiply (int)" << endl;
    return a * b;
}

int main() {
    // Using template class
    Calculator<int> c1(10);
    Calculator<int> c2(20);
    Calculator<double> c3(5.5);
    
    cout << c1 << " + " << c2 << " = " << (c1 + c2) << endl;
    cout << c1 << " + " << c3 << " = " << c1.add(c3) << endl;
    
    // Using function templates with overloading
    cout << "\nFunction template examples:" << endl;
    cout << "multiply(5, 3) = " << multiply(5, 3) << endl;  // Regular function
    cout << "multiply(5.5, 2.5) = " << multiply(5.5, 2.5) << endl;  // Template
    cout << "multiply(5.5, 3) = " << multiply(5.5, 3) << endl;  // Template different types
    
    // Template class with different types
    Calculator<string> s1("Hello ");
    Calculator<string> s2("World");
    cout << "\nString calculator:" << endl;
    cout << s1 << " + " << s2 << " = " << (s1 + s2) << endl;
    
    return 0;
}