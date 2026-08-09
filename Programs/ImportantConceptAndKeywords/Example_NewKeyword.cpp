#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date: 2026-08-07
Program Description:This Program exhbits the pointer with new keyword.
*/

int main() {

   cout << "\nPointer with new keyword" << endl;
   cout << "-------------------------" << endl;

   int *ptr = new int; // dynamically allocating memory for an integer
   *ptr = 42; // assigning a value to the allocated memory
   
   cout << "Value of *ptr: " << *ptr << endl;


   delete ptr; // deallocating the memory

return 0;

}