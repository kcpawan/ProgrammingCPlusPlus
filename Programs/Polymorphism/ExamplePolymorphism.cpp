#include <iostream>
using namespace std;

// BASE CLASS
class Vehicle {
public:
    // Virtual function - can be overridden
    virtual void startEngine() {
        cout << "Vehicle: Turning ignition key" << endl;
    }
    
    // Virtual function with different behavior
    virtual void honk() {
        cout << "Vehicle: Beep beep!" << endl;
    }
    
    // Non-virtual function - cannot be overridden
    void getWheels() {
        cout << "Vehicle has 4 wheels" << endl;
    }
    
    virtual ~Vehicle() {}  // Virtual destructor - important!
};

// DERIVED CLASS 1
class Car : public Vehicle {
public:
    // OVERRIDING the virtual function
    void startEngine() override {  // 'override' keyword checks correctness
        cout << "Car: Press push-start button" << endl;
        cout << "Car: Engine roars to life!" << endl;
    }
    
    // OVERRIDING another virtual function
    void honk() override {
        cout << "Car: HONK HONK! (loud car horn)" << endl;
    }
    
    // Can't override getWheels() - it's not virtual
     void getWheels() {
        cout << "Vehicle has 4 wheels from Car" << endl;
    }
};

// DERIVED CLASS 2
class ElectricCar : public Vehicle {
public:
    // OVERRIDING with different implementation
    void startEngine() override {
        cout << "Electric Car: Press power button" << endl;
        cout << "Electric Car: Silent motor activates (no sound!)" << endl;
    }
    
    void honk() override {
        cout << "Electric Car: Beep-beep (soft digital sound)" << endl;
    }
};

int main() {
    cout << "=== DEMONSTRATING OVERRIDING ===" << endl << endl;
    
    // Creating objects
    Vehicle vehicle;
    Car car;
    ElectricCar tesla;
    
    cout << "1. Direct object calls:" << endl;
    vehicle.startEngine();  // Base version
    car.startEngine();      // Car's overridden version
    car.getWheels();        // Car's overridden version
    
    tesla.startEngine();    // ElectricCar's overridden version
    cout << endl;
    
    cout << "2. Using base pointers (polymorphism):" << endl;
    Vehicle* v1 = &car;
    Vehicle* v2 = &tesla;
    
    v1->startEngine();  // Calls Car's version (polymorphism!)
    v2->startEngine();  // Calls ElectricCar's version
    cout << endl;
    
    cout << "3. Non-virtual function (no override):" << endl;
    v1->getWheels();    // Always calls base version
    v2->getWheels();    // Always calls base version
    cout << endl;
    
    cout << "4. Array of different vehicles:" << endl;
    Vehicle* fleet[] = {&vehicle, &car, &tesla};
    for(int i = 0; i < 3; i++) {
        fleet[i]->honk();  // Each honks differently!
    }
    
    return 0;
}