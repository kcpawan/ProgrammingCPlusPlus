#include <iostream>
using namespace std;

class Rectangle {
private:
    int width;
    int height;
    
public:
    Rectangle(int w = 0, int h = 0) : width(w), height(h) {
        cout << "Constructor called" << endl;
    }
    
    Rectangle(const Rectangle& other) {
        width = other.width;
        height = other.height;
        cout << "Copy constructor called!" << endl;
    }
    
    int area() const {
        return width * height;
    }
    
    void setWidth(int w) {
        width = w;
    }
};

// Function that takes Rectangle by value (creates a copy)
void modifyRectangleByValue(Rectangle r) {
    r.setWidth(20);  // Modifies the copy, not the original
    cout << "Inside function area: " << r.area() << endl;
}

int main() {
    Rectangle rect(5, 10);
    cout << "Original area: " << rect.area() << endl;
    
    modifyRectangleByValue(rect);  // Copy is created
    
    cout << "Original area after function: " << rect.area() << endl;
    // Original remains unchanged
    
    return 0;
}