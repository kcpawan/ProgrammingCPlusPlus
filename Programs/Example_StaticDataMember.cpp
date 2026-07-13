#include <iostream>  
using namespace std; 

// Class declaration for Student
class Student {
public:
    // Declaration of static data member.Static members belong to the class itself, not to individual objects
    // All objects share the same static variable
    int normalCount = 0;
    static int staticCount;

    // Constructor - automatically called when a Student object is created
    Student() {
        normalCount++;
        staticCount++;
    }
};

// Definition and initialization of static data member outside the class
// This allocates memory for the static variable
// Must be done exactly once in exactly one source file
int Student::staticCount = 0;

int main() {
    Student s1; // Creates first Student object → normalCount becomes 1, staticCount becomes 1
    Student s2; // Creates second Student object → normalCount becomes 1 (for s2), staticCount becomes 2 (shared across all objects)    
    Student s3; // Creates third Student object → normalCount becomes 1 (for s3), staticCount becomes 3 (shared across all objects) 

    cout << "s1 normalCount: " << s1.normalCount << endl; // Outputs 1 (specific to s1)
    cout << "s2 normalCount: " << s2.normalCount << endl; // Outputs 1 (specific to s2)
    cout << "s3 normalCount: " << s3.normalCount << endl; // Outputs 1 (specific to s3)

    cout << "Shared staticCount: " << Student::staticCount << endl; // Outputs 3 (shared across all objects)
    return 0; // Program executed successfully
}
