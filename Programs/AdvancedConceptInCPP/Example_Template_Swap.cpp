#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date: 2026-07-22
Program Description: This Program exhibits the template functionality pesent in C++.
*/

template < typename T >
void swapValues(T &a, T &b) {
    T temp = a;   // works for int, double, string...
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swapValues(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;

    double m = 1.5, n = 2.5;
    cout << "Before swapping: m = " << m << ", n = " << n << endl;
    swapValues(m, n);
    cout << "After swapping: m = " << m << ", n = " << n << endl;

    string str1 = "Hello", str2 = "World";
    cout << "Before swapping: str1 = " << str1 << ", str2 = " << str2 << endl;
    swapValues(str1, str2);
    cout << "After swapping: str1 = " << str1 << ", str2 = " << str2 << endl;

    return 0;
}