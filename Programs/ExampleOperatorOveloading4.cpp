#include <bits/stdc++.h>
using namespace std;

class Marks{
    int intmark;
    int extmark;

public:
    Marks() {
    intmark = 0;
    extmark = 0;
    }


    Marks( int im, int em) {
    intmark = im;
    extmark = em;
    }
    void display() {
    cout << intmark<<endl<<extmark<<endl;
    }

    Marks operator+(Marks m) {
        Marks temp;
        temp.intmark = intmark + m.intmark;
        temp.extmark = extmark + m.extmark;
        return temp;
    }  

    Marks operator-(Marks m);
};

Marks Marks::operator-(Marks m) {
        Marks temp;
        temp.intmark = intmark - m.intmark;
        temp.extmark = extmark - m.extmark;
        return temp;
    }  



int main() {
    Marks m1(10, 20), m2(30, 40), m3;
    m3 = m1 + m2;
    cout << "Marks of student 1: " << endl;
    m1.display();
    cout << "Marks of student 2: " << endl;
    m2.display();
    cout << "Total marks of both students: " << endl;
    m3.display();

    Marks m4 = m1 - m2;
    cout << "Difference in marks: " << endl;
    m4.display();

    return 0;
}