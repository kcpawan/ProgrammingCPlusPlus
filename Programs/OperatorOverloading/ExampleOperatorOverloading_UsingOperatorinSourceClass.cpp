#include <iostream>
using namespace std;

class Celsius {
private:
    double temp;
    
public:
    Celsius(double t = 0) : temp(t) {}
    
    double getTemp() const { return temp; }
    
    void display() {
        cout << temp << "°C" << endl;
    }
};

class Fahrenheit {
private:
    double temp;
    
public:
    Fahrenheit(double t = 0) : temp(t) {}
    
    // Conversion operator to Celsius
    operator Celsius() {
        double cTemp = (temp - 32) * 5.0 / 9.0;
        return Celsius(cTemp);
    }
    
    void display() {
        cout << temp << "°F" << endl;
    }
};

int main() {
    Fahrenheit f(98.6);
    Celsius c = f;  // Uses conversion operator
    
    cout << "Fahrenheit: ";
    f.display();
    cout << "Celsius: ";
    c.display();
    
    return 0;
}