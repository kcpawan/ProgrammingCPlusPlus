#include <iostream>
#include <string>
using namespace std;


// Template: 1 - Function with 2 argument, Single Datatype
template <typename T>
T sum(T a, T b){
    T sum = a + b;
    return sum;
}

// Template: 2 - Function with 3 argument, Single Datatype
template <typename T>
T sum(T a, T b, T c){
    T sum = a + b + c;
    return sum;
}

// Template: 3 - Function with 2 argument, 2 different Datatypes
template <typename T1, typename T2>
T2 sum(T1 a, T2 b){
    T2 sum = a + b;
    return sum;
}

// Template: 4 - Function with 3 argument, 3 different Datatypes
template <typename T1, typename T2, typename T3>
T3 sum(T1 a, T2 b, T3 c){
    T3 sum = a + b + c;
    return sum;
}

// Template: 5- Special handling for string concatenation
template<typename T1, typename T2>
string sum(T1 a, T2 b, const string& c) {
    return to_string(a) + to_string(b) + c;
}

int main(){
    cout << "Sum is : " << sum(4.5,10.5) << endl;      // calls first template
    cout << "Sum is : " << sum(4,10,15) << endl;      // calls second template
    cout << "Sum is : " << sum(4.5,10) << endl;      // calls first template (both int)
    
    cout << "Output : " << sum(4.5, 10, string("PKC")) << endl; 

    cout << "Output : " << sum( 'P', 'K','C') << endl; // calls second template


    return 0;
}