#include <iostream>
using namespace std; 

class MathUtils {
public:
    // Static member function: belongs to the class, not instances
    // Can be called without creating an object
    static int add(int a, int b) {
        return a + b;  // Simple addition operation
    }
};

int main() {
    // Call static member function using class name and scope resolution operator (::)
    int result = MathUtils::add(5, 3);
    
    // Output the result to console
    cout << "Result: " << result << std::endl;
    
    return 0;  // Successful program termination
}