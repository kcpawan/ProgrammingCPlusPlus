#include <iostream>
using namespace std;
// Define a class called 'Car'

class Car {
    public:     // Access specifier
        string brand;  // Data member
        int speed;     // Data member
        
        // Member function
        void display() {
            cout << "Brand: " << brand << ", Speed: " << speed << " km/h" << endl;
        }
};

int main() {
    // Creating an object of the Car class
    Car myCar;
    
    // Setting values for the object's data members
    myCar.brand = "Toyota";  // Assign brand name
    myCar.speed = 120;       // Assign speed value
    
    // Displaying the car details
    myCar.display();  // Call the display function to output car information
    
    return 0;  // Indicate successful program completion

}