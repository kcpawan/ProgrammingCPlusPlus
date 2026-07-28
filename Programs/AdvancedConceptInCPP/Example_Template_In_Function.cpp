#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Template function for finding maximum
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

// Template with multiple parameters
template <typename T1, typename T2>
void display(T1 a, T2 b) {
    cout << "Value 1: " << a << ", Value 2: " << b << endl;
}

// Template for array operations
template <typename T, size_t N>
T sumArray(T (&arr)[N]) {
    T sum = 0;
    for (size_t i = 0; i < N; i++) {
        sum += arr[i];
    }
    return sum;
}

// Template with default type
template <typename T = int>
T square(T a) {
    return a * a;
}

// Template for containers
template <typename Container>
void printContainer(const Container& c) {
    cout << "Container elements: ";
    for (const auto& elem : c) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    // Using template with different types
    cout << "Max of 10 and 20: " << findMax(10, 20) << endl;
    cout << "Max of 5.5 and 3.2: " << findMax(5.5, 3.2) << endl;
    cout << "Max of 'A' and 'Z': " << findMax('A', 'Z') << endl;
    
    // Multiple parameter template
    display(10, "Hello");
    display(3.14, 42);
    
    // Array sum template
    int arr[] = {1, 2, 3, 4, 5};
    double darr[] = {1.1, 2.2, 3.3};
    cout << "Sum of int array: " << sumArray(arr) << endl;
    cout << "Sum of double array: " << sumArray(darr) << endl;
    
    // Default template parameter
    cout << "Square of 5: " << square(5) << endl;
    cout << "Square of 2.5: " << square<double>(2.5) << endl;
    
    // Container template
    vector<int> v = {10, 20, 30, 40};
    printContainer(v);
    
    return 0;
}