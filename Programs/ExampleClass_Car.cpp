#include <iostream>
using namespace std;
// Define a class called 'Car'
class Car {
    private: // Private access specifier ensures data security
        string model;
        int year;
        int speed;
    public:
        // Constructor to initialize data members
        Car(string m, int y, int s) : model(m), year(y), speed(s) {}
        // Member function to display car details
        void displayDetails() {
            cout << "Model: " << model << endl;
            cout << "Year: " << year << endl;
            cout << "Speed: " << speed << " km/h" << endl;
        }
        // Member function to accelerate the car
        void accelerate(int increment) {
            speed += increment;
            cout << model << " accelerated to " << speed << " km/h." << endl;
        }
        
        // Member function to apply brakes
        void brake(int decrement) {
            speed = (speed - decrement >= 0) ? speed - decrement : 0;
            cout << model << " slowed down to " << speed << " km/h." << endl;
        }
};
int main() {
    // Creating an object of the Car class
    Car myCar("Tesla Model S", 2022, 0);
    
    // Displaying the car details
    myCar.displayDetails();
    // Accelerating the car
    myCar.accelerate(60);
    // Applying brakes
    myCar.brake(20);
    return 0;
}