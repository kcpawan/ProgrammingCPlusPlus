#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date: 2026-07-22
Program Description: This Program exhibits the template functionality pesent in C++.
*/
template<typename T>
    T add(T a,T b){
        return a+b;
    }

int main() {
   
    cout << add(2,3) << endl;
    cout << add(4.5,9.5) << endl;
return 0;

}
