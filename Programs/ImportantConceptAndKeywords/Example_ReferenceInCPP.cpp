#include<iostream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:

============================================================================================================
What is Reference in C++?
References in C++ provide a way to create an alternative name for an existing variable. 
They allow programmers to access and modify the original variable directly without creating a separate copy,
making programs more effifient and easier to read.
    * A reference acts as an alias for another variable.
    * Used to access or modify a variable.
    * Changes made through a reference affect the original variable.
    * References are commonly used in function parameters to improve performance.

    Syntax:
        datatype& reference_name {original_value};

        The & symbol is used to declare a reference.

            T &ref = var;

        Here,
            T - Data type of the variable.
            ref - Name of the reference variable.
            var - Existing variable to which the reference is bound

 ==>  Unlike pointers, reference is not a separate variable. It is just another name.

=============================================================================================================
*/

int main() {

    int a{10};
    int& ref{a};

    cout << "\n"<< "Initial value of a:" << endl;
    cout << a << endl;
    cout << ref << endl;

    ref = 20;
    
    cout << "\n" << "Value of a after modifying through ref:" << endl;
    cout << a << endl;
    cout << ref << endl;


   //Reference cannot be changes. In below program z will be always be reference of x.
    int x{10};
    int y{20};
    int& z{x};

    z = y;

    cout << "Value of x: " << x << endl;
    cout << "Value of y: " << y << endl;

return 0;
}
