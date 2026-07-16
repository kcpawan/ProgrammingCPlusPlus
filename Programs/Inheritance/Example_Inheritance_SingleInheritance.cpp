#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date: 15/07/2026
Program Description:This program exhibits the single inheritance. 
                    Here we have a base class Person(generic) that is inherited by base class Employee(specility).
                    
                    Note: Person class has been inherited privately. The default form of inheritance in private, 
                    hence we could have skipped writing private. Moreover, with this type of inheritance, 
                    all the members of class Person now become only privately accessible members (except name & age, because they are too private) 
                    of the class Employee.
*/


class Person{
    private:
        string name;
        int age;
    
    public:
        Person(string name, int age): name{name}, age{age}{
            //Base parameterized constructor initialised using memeber initializer list
        }
        void getName(){
            cout<<"Name: "<<name<<endl;
        }
        void getAge(){
            cout<<"Age: "<<age<<endl;
        }
};

class Employee: private Person{ //Default inheritance type is private
    private:
        int employeeID;
    public:
        Employee(string name, int age, int id) : Person(name, age){  //Derived parameterized constructor
            employeeID = id;
        }
        void getEmployeeDetails(){
            getName();
            getAge();
            cout<<"Employee ID: "<<employeeID<<endl;
        }
};

int main(){
    Employee* e = new Employee("Sudhir", 46, 14298);
    e->getEmployeeDetails();
    return 0;
}

