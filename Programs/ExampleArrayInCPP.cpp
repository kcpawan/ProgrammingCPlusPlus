/*
Basics of Array

    1. Collection of elements of same data type stored in contiguous memory locations.
    2. Instead of creating multiple variables for similar data, arrys can be used.

    Example: 
        int main(){
            int marks[3] = {80, 90, 75};

            cout << marks[0] << endl;
            cout << marks[1] << endl;
            cout << marks[2] << endl;

            for(int i = 0; i < 3; i++){
                cout << marks[i] << endl;
            }
            return 0;
        }


*/

#include<iostream>
using namespace std;

 int main(){
            int marks[3] = {80, 90, 75};

            cout << marks[0] << endl;
            cout << marks[1] << endl;
            cout << marks[2] << endl;

            cout << "\n";
            cout << "Ouptput from Loop" << endl;
            cout << "\n";


            for(int i = 0; i < 3; i++){
                cout << marks[i] << endl;
            }
            return 0;
        }
