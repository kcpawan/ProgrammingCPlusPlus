#include<iostream>
using namespace std;
    int a=100;
    class A{
        int a;

        public:
        void fun(){
            a=20;
            a=a+::a; //using global variable value
            cout<<a;
        }
    };

A a1;

int main(){
    a1.fun();
    return 0;
}
