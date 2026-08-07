#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/
class Shape{

    private:
    float x;
    float y;
    
    public:
    Shape(float x, float y){

       cout << "Shape class Constructor called." << endl;

        this -> x = x;
        this -> y = y;

    } ;

    virtual float area() = 0;
    
    float getX() const{ return x;}
    float getY() const{ return y;}
    
    
    
};

class Circle : public Shape{
    private:
    float radius;

    public:
    /* Circle Class constructor where Shape call constructor is also called.
        Logic / Theory : Every derived class constructor must explicitly call the base class constructor.
    */
     
    Circle(float r):Shape(r,0), radius(r){

        cout << "Circle class Constructor called." << endl;

    };

    /* 
        The derived class must override the pure virtual function with the exact same signature (parameter types and count). 
        Different signatures create a new function instead of overriding.
    */
    float area(){
        return 3.14159 * radius * radius;
    }
};

class Rectangle: public Shape{
    private:
        float length;
        float breath;

    public:  
    Rectangle(float l, float b): Shape(l,b), length(l),breath(b){
        cout << "Rectangle class Constructor called." << endl;

    }

    float area(){
        return length * breath;
    }

};


int main() {
        Circle c1(2);
        Rectangle r1(5, 5);

        //Calculate area

        cout << "Area of Circle: " << c1.area() << endl;

        cout << "Area of Rectangle: " << r1.area() << endl;


return 0;
}
