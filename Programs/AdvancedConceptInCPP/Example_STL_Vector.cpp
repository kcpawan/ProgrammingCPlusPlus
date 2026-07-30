#include<iostream>
#include<vector>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/

int main() {
    //Creating Vector and initializing it with 3 elements
    vector<int> vec = {10, 20, 50};

    // Printing the first element of vector
    cout << "Element in First Index in Vector: " << vec[0]<< endl;
    
    // Adding values in vector using push_back function
    vec.push_back(100);
    vec.push_back(101);

    // Printing first value of Vector
    cout << "Frist Elements in Vector: " << vec.front()<< endl ;

    // Printing Last value of Vector
    cout << "Last Elements in Vector: " << vec.back()<< endl ;

    // Printing all the values in vector in console    
    cout << "Elements in Vector: " ;
    for(int num : vec){
        cout << num << " " ;
    }
    
    // Printing the size of vector in console   
    cout << "\nSize of Vector: " << vec.size() << endl;

    // Removing the values from vector 
    vec.pop_back();
    
     // Printing all the values in console after poping out last value from vector
    cout << "Elements in Vector After Pop_Back: " ;
    for(int num : vec){
        cout << num << " " ;
    }


    // Printing all the size of vector in console after poping out last value
     cout << "\nSize of Vector after Pop_Back: " << vec.size() << endl;


    // Creating the vector with same value 
    vector<int> vec2(10, -1);
    for(int num : vec2){
            cout << num << " " ;
        }


return 0;
}
