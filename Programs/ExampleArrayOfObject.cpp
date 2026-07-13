/*
Array of Objects

    1. Each element of the array id an object of the class.
    2. Each object has its own copy of the data members, but they share same definition of member functions.
*/

#include<iostream>
using namespace std;

    class Student{
        string name;
        int age;

    public:
        void setData(string n, int a){
            name = n;
            age = a;

        }

        void display(){
            cout << "Name: " << name << " | Age: " << age << endl; 
        }
    };

    int main(){
            Student s[2];
            s[0].setData("Saroj", 35);
            s[1].setData("Bishnu", 23);


            for(int i = 0; i < 2; i++){
                s[i].display();
            }
            return 0;
        }