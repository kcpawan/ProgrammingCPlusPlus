#include <iostream>
using namespace std;

class Fahrenheit {
private:
    double temp;
    
public:
    Fahrenheit(double t = 0) : temp(t) {}
    
    double getTemp() const { return temp; }
    
    void display() {
        cout << temp << "°F" << endl;
    }
};

class Celsius {
private:
    double temp;
    
public:
    Celsius(double t = 0) : temp(t) {}
    
    // Constructor for conversion from Fahrenheit
    Celsius(const Fahrenheit& f) {
        temp = (f.getTemp() - 32) * 5.0 / 9.0;
    }
    
    void display() {
        cout << temp << "°C" << endl;
    }
};

int main() {
    Fahrenheit f(98.6);
    Celsius c = f;  // Convert Fahrenheit to Celsius
    
    cout << "Fahrenheit: ";
    f.display();
    cout << "Celsius: ";
    c.display();
    
    return 0;
}