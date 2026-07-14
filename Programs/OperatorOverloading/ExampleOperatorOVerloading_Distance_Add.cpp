#include<iostream>
using namespace std;

class Distance{
    int meter;

    public:

        Distance() {
            meter=0;
        }

        Distance(int m){
            meter=m;
        }

        Distance operator +(Distance d){
            Distance temp;

            temp.meter = meter + d.meter;

            return temp;
        }

        void display(){
            cout<<"Distance = "<<meter<<" meters"<<endl;
        }
};

int main(){
    Distance d1(10);
    Distance d2(20);
    Distance d3;

    d3 = d1 + d2;

    d3.display();
    
    return 0;
}