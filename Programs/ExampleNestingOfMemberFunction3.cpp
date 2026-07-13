#include <iostream>
using namespace std;
    class average{
        int a,b;
        public:
        void read();
        void print();
        int avg();
    };

    void average::read(){
        cout<<"\n enter a and b: ";
        cin>>a>>b;
    }
    
    void average::print(){
        cout<<"value of a: "<<a;
        cout<<"\nvalue of b: "<<b;
        cout<<"\naverage is : "<<avg();
    }
    
    int average::avg(){
        return (a+b)/2;
    }
int main(){
    average A;
    A.read();
    A.print();
    return 0;
}