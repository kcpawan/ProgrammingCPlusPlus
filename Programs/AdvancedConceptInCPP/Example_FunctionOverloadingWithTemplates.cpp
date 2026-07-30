#include <iostream>
#include <string>
using namespace std;

// 1. Regular function overload
int sum(int a, int b) {
    cout << "Regular function: int + int" << endl;
    return a + b;
}

// 2. Template function
template <typename T>
T sum(T a, T b) {
    cout << "Template: same type" << endl;
    return a + b;
}

// 3. Template function with different types
template <typename T1, typename T2>
auto sum(T1 a, T2 b) -> decltype(a + b) {
    cout << "Template: different types" << endl;
    return a + b;
}

// 4. Template specialization for string
template <>
string sum<string>(string a, string b) {
    cout << "Specialized template: string concatenation" << endl;
    return a + b;
}

int main() {
    // Calls regular function (most specific)
    cout << "Result: " << sum(5, 10) << endl << endl;
    
    // Calls template with same type (double)
    cout << "Result: " << sum(5.5, 10.5) << endl << endl;
    
    // Calls template with different types
    cout << "Result: " << sum(5.5, 10) << endl << endl;
    
    // Calls specialized template
    cout << "Result: " << sum(string("Hello "), string("World")) << endl;
    
    return 0;
}