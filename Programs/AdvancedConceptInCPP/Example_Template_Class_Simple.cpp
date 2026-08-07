#include<iostream>
#include<string>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/
template <typename T,typename T2>
class Box{

    T item;
    T2 item2;

    public:
    Box(T val , T2 val2): item(val), item2(val2){}
    T get(){ return item;}

    T2 get2(){ return item2;}
};
int main() {

    Box<int,float> b(20, 30.5);
    cout << b.get() << " : " << b.get2() << endl;

    Box<double,string> b2(50.60, "Hello World");
    cout << b2.get() << " : " << b2.get2() << endl;

   


return 0;
}
