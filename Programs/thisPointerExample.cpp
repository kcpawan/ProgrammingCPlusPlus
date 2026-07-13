#include<iostream>
#include<string.h>
using namespace std;

class demo{
    char sname[50];
    int age;
    float marks;

    public:
        demo(char sname[50], int a, float marks){
            age = a;
            strcpy(sname,sname);
            this->marks = marks;
        }

        void display(){
            cout << "Name: "<< sname << endl;
            cout << "Age: "<< age << endl;
            cout << "Marks: "<< marks << endl;
            cout << "Name: "<< (*this).sname<< ", Marks: "<<(*this).marks <<endl;
        }
};
int main(){

    demo d("Pawan", 40, 90);
    d.display();
    
    return 0;
}
 