#include <iostream>

class Distance {
private:
    int meters;
public:
    Distance() : meters(0) {}
    
    // Constructor handles: int -> Distance conversion
    Distance(int m) { 
        meters = m; 
    }

    void display() const { 
        std::cout << meters << " meters\n"; 
    }
};

int main() {
    // Implicit conversion from basic type (int) to Class type (Distance)
    Distance d = 50; 
    d.display(); // Outputs: 50 meters
}
