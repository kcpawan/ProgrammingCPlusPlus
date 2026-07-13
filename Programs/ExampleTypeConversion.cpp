#include <conio.h>
#include <iostream>
using namespace std;

class invent1
{
int code;
int items;
float price;
 public:
 invent1()
 {}
 invent1(int a,int b,int c)
 {
 code=a;
 items=b;
 price=c;
 }
 void display()
 {
 cout<<"\nCode : "<<code;
 cout<<"\nItems : "<<items;
 cout<<"\nPrice : "<<price;
 }
 int getcode()
 {return code;}
 int getitem()
 {return items;}
 int getprice()
 {return price;}
};

class invent2
{
 int code;
 float value;

 public:
 invent2()
 {
 code=0;
 value=0;
 }
 invent2(int x,float y)
 {
 code=x;
 value=y;
 }
 void display()
 {
 cout<<"Code : "<<code<<endl;
 cout<<"Value : "<<value<<endl;
 }
 invent2(invent1 p)
 {
 code=p.getcode();
 value=p.getitem()*p.getprice();
 }
};


int main(){
invent1 s1(100,5,140);
invent2 d1;
d1=s1; //Invoke Constructor in Invent2 for conversion
cout<<"\nProduct details - Invent1 type";
s1.display();
cout<<"\n\n\nProduct details - Invent2 type\n";
d1.display();
return 0;
}
