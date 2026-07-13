#include <iostream>
using namespace std;
    class set{
        int m,n;
        
        public:
            void input();
            void display ();
            int largest();
    };
    
    int set::largest(){
        if(m>n)
            return m;
        else
            return n;
    }
    void set::input(){
        cout<<"input values of m:";
            cin>>m;
        cout<<"input values of n:";
            cin>>n;
    }
    void set::display(){
        cout<<"largestvalue="<<largest()<<"\n";
}
int main(){
    set A;
    A.input();
    A.display();
    return 0;
}