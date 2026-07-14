#include <iostream>
using namespace std;

class Increment {
private:
    int cnt;

public:
    Increment() : cnt(0) {}

    // Overloading the post-increment operator ++
    Increment operator++(int) {
        Increment dp(*this);
        cnt++;
        return dp;
    }
    int get() const { return cnt; }
};

int main(){
    Increment i1;

    cout << "Before Increment- " << i1.get() << "\n";

    Increment i2 = i1++; // Post-incrementing i1

    cout << "After Increment- " << i1.get() << "\n";
    cout << "i2 is- " << i2.get() << "\n";

    return 0;
}