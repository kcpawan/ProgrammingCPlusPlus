#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/

int main() {

    int a {10};
    int* p {&a};
    int** pp {&p};  // Pointer to pointer

    cout << "a: " << a << endl;        // 10
    cout << "*p: " << *p << endl;      // 10
    cout << "**pp: " << **pp << endl;  // 10 (go to p, then to a)

return 0;
}
