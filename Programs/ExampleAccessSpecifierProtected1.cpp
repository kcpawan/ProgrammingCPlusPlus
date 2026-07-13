#include <iostream>
class Vehicle {
protected:
    int maxSpeed; // Accessible to derived classes
    std::string type;

public:
    Vehicle(std::string t, int ms) : type(t), maxSpeed(ms) {}
    void display() {
        std::cout << "Type: " << type << ", Max Speed: " << maxSpeed << std::endl;
    }
};

class SportsCar : public Vehicle {
public:
    SportsCar(std::string t, int ms) : Vehicle(t, ms) {}

    void boost() {
        maxSpeed += 20; // Can access and modify protected member
        std::cout << "Boosted! New max speed: " << maxSpeed << std::endl;
    }
};

int main() {
    SportsCar car("Ferrari", 300);
    car.display(); // Public method
    car.boost();  // Modifies protected member
    // std::cout << car.maxSpeed; // Error: maxSpeed is protected
    return 0;
}