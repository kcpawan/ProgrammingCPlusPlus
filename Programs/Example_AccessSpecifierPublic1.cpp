#include <iostream>
class Car {
public:
    std::string model;
    int speed;

    Car(std::string m, int s) : model(m), speed(s) {}

    void accelerate(int increase) {
        speed += increase;
        std::cout << model << " accelerated to " << speed << " km/h" << std::endl;
    }
};

int main() {
    Car car("Toyota", 60);
    car.accelerate(20); // Public method
    std::cout << "Model: " << car.model << ", Speed: " << car.speed << std::endl; // Direct access to public members
    return 0;
}