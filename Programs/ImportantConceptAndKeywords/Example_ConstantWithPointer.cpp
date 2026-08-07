#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/

int main() {
    int a {10}, b {20};

    cout << endl;
    cout << endl;
    
    
    cout << "   Value of a :  " << a << endl;
    
    
    cout << endl;
    cout << endl;

    // 0. Pointer to data

    int* p0 = &a;

    *p0 = 50;

    cout << "   Address in p0 (Address of a is assigned in p0):  " << p0 << endl;
    cout << "   Value of a after modifiying though pointer:  " << a << endl;
    cout << "   Value in p0 :  " << *p0 << endl;

    cout << endl;

     // 1. Pointer to const (data read-only)
    cout <<" 1. Pointer to const (data read-only)" << endl;
    const int* p1 = &a;
    // *p1 = 30;  // ERROR: cannot modify data

    cout << "   Value in p1:  " << *p1 << endl;
    cout << "   Address Of a:  " << &a << endl;
    cout << "   Address in p1 (Address of a is assigned in p1):  " << p1 << endl;


    p1 = &b;      // can change where p1 points

    cout << "   Address in Pointer p1 after p1 is assigned address of &b:  " << p1 << endl;
    /* Here we cannot modify the data in the address where pointer is pointing as it is declared as const.*/
    
    cout << endl;
    // 2. Const pointer (address read-only)
    cout <<" 2. Const pointer (address read-only)" << endl;
    int* const p2 = &a;
    *p2 = 30;     // can modify data
    // p2 = &b;   // ERROR: cannot change where p2 points

    cout << "   Value in p2:  " << *p2 << endl;
    cout << "   Address in p2:  " << p2 << endl;

    cout << endl;

    // 3. Const pointer to const (both read-only)
    const int* const p3 = &a;
    // *p3 = 30;  // ERROR: cannot modify data
    // p3 = &b;   // ERROR: cannot change where p3 points

return 0;
}
