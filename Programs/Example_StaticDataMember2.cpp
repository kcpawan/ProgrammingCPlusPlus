#include <iostream>  
using namespace std; // Allows using cout and endl without std:: prefix

// Class declaration for Mercedes
class Mercedes {
public:
    // Declaration of static data member.Static members belong to the class itself, not to individual objects
    // All objects share the same static variable
    static int modelCount;

    // Constructor - automatically called when a Mercedes object is created
    Mercedes() {
        // Increment modelCount for each object created
        // Since modelCount is static, it keeps its value across all objects
        modelCount++;
    }
};

// Definition and initialization of static data member outside the class
// This allocates memory for the static variable
// Must be done exactly once in exactly one source file
int Mercedes::modelCount = 0;

int main() {
    // Creating Mercedes objects - each triggers the constructor
    Mercedes m1; // Creates first Mercedes object → modelCount becomes 1
    Mercedes m2; // Creates second Mercedes object → modelCount becomes 2
    Mercedes m3; // Creates third Mercedes object → modelCount becomes 3

    // Accessing the static data member using the class name with scope resolution operator (::)
    // Static members can be accessed even without creating any objects
    cout << "Total Mercedes models: " << Mercedes::modelCount << endl;

    return 0; // Program executed successfully
}
