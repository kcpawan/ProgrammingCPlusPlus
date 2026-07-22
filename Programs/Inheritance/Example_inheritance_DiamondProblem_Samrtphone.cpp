#include <iostream>

class Device {
public:
    int deviceId;
    
    Device(int id) : deviceId(id) {
        std::cout << "Device constructor called with ID: " << id << std::endl;
    }
    
    void powerOn() {
        std::cout << "Device " << deviceId << " is powering on" << std::endl;
    }
};

class Phone : virtual public Device {
public:
    Phone(int id) : Device(id) {
        std::cout << "Phone constructor called" << std::endl;
    }
    
    void makeCall() {
        std::cout << "Making a call from device " << deviceId << std::endl;
    }
};

class Camera : virtual public Device {
public:
    Camera(int id) : Device(id) {
        std::cout << "Camera constructor called" << std::endl;
    }
    
    void takePhoto() {
        std::cout << "Taking photo with device " << deviceId << std::endl;
    }
};

class SmartPhone : public Phone, public Camera {
public:
    SmartPhone(int id) : Device(id), Phone(id), Camera(id) {
        std::cout << "SmartPhone constructor called" << std::endl;
    }
};

int main() {
    SmartPhone myPhone(123);
    
    // These work perfectly now!
    myPhone.powerOn();    // Calls Device::powerOn()
    myPhone.makeCall();   // Calls Phone::makeCall()
    myPhone.takePhoto();  // Calls Camera::takePhoto()
    
    std::cout << "Device ID: " << myPhone.deviceId << std::endl;
    
    return 0;
}