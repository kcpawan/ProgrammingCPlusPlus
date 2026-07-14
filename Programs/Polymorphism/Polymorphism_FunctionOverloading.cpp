#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/

class operations{
    public:
        int add(int x , int y){
           //cout<< "Addition: "<<x+y<<endl;
           return x+y;
        }
    
        double add(double x , double y){
            //cout<<"Addition: "<<x+y<<endl;
            return x+y;
        }
};
int main(){
    operations obj1, obj2;
    int res1 = obj1.add(3,5); //will call int function
    double res2 = obj2.add(3.51 , 2.5); //will call double function

    cout << "Result 1: " << res1 << endl;
    cout << "Result 2: " << res2 << endl;
    
    
    return 0;
}