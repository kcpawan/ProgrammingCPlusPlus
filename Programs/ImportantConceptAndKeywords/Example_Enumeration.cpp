#include <iostream>
using namespace std;

// Define an enumeration for days of the week
enum Days {
    Monday,    // 0
    Tuesday,   // 1
    Wednesday, // 2
    Thursday,  // 3
    Friday,    // 4
    Saturday,  // 5
    Sunday     // 6
};
int main() {
// Declare a variable of type Days
    Days today = Wednesday;

    cout << "Today is: " << today << endl;       // Outputs integer value (2)
    cout << "Wednesday has value: " << Wednesday << endl;

    // Using enum in a loop
    for (int i = Monday; i <= Sunday; i++) {
        cout << "Day " << i << endl;
    }
    
return 0;
}
