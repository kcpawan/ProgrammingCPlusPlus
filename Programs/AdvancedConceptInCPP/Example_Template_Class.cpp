#include<iostream>
using namespace std;

template<class T>

class Box
{
    T value;

public:

    void setValue(T x)
    {
        value=x;
    }

    T getValue()
    {
        return value;
    }
};

int main()
{
    Box<int> b1;

    b1.setValue(100);

    cout<<b1.getValue()<<endl;

    Box<float> b2;

    b2.setValue(45.6);

    cout<<b2.getValue();

    return 0;
}