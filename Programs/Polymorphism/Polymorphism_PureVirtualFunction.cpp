#include <iostream>
#include <vector>

// Abstract base class
class Shape {
public:
// Pure virtual functions for area and perimeter
virtual double area() const = 0;
virtual double perimeter() const = 0;
};

// Derived class for circles
class Circle : public Shape {
private:
double radius;

public:
Circle(double r) : radius(r) {}

// Implementation of the area function for circles
double area() const override {
return 3.14 * radius * radius;}

// Implementation of the perimeter function for circles
double perimeter() const override {
return 2 * 3.14 * radius;}
};

// Derived class for rectangles
class Rectangle : public Shape {
private:
double width;
double height;

public:
Rectangle(double w, double h) : width(w), height(h) {}

// Implementation of the area function for rectangles
double area() const override {
return width * height;}

// Implementation of the perimeter function for rectangles
double perimeter() const override {
return 2 * (width + height);}
};

int main() {
// Create instances of Circle and Rectangle
Circle circle(5.0);
Rectangle rectangle(4.0, 6.0);

// Store shapes in a vector of Shape pointers
std::vector<Shape*> shapes;
shapes.push_back(&circle);
shapes.push_back(&rectangle);

// Calculate and display the area and perimeter of each shape
for (const Shape* shape : shapes) {
std::cout << "Area: " << shape->area() << std::endl;
std::cout << "Perimeter: " << shape->perimeter() << std::endl;
std::cout << "------------------------" << std::endl;}

return 0;
}