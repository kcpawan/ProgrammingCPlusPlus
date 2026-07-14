#include <iostream>
using namespace std;

class Time {
private:
    int hours;
    int minutes;
    
public:
    Time(int h = 0, int m = 0) : hours(h), minutes(m) {
        normalize();
    }
    
    void normalize() {
        hours += minutes / 60;
        minutes %= 60;
    }
    
    // Less than operator
    bool operator<(const Time& other) {
        int total1 = hours * 60 + minutes;
        int total2 = other.hours * 60 + other.minutes;
        return total1 < total2;
    }
    
    // Equality operator
    bool operator==(const Time& other) {
        return (hours == other.hours && minutes == other.minutes);
    }
    
    void display() {
        cout << hours << ":" << minutes;
        if (hours < 10) cout << " AM";
        else cout << " PM";
        cout << endl;
    }
};

int main() {
    Time t1(10, 30);
    Time t2(14, 45);
    Time t3(10, 30);
    
    cout << "t1: "; t1.display();
    cout << "t2: "; t2.display();
    cout << "t3: "; t3.display();
    
    cout << "\nComparisons:" << endl;
    cout << "t1 < t2: " << (t1 < t2 ? "Yes" : "No") << endl;
    cout << "t1 == t3: " << (t1 == t3 ? "Yes" : "No") << endl;
    
    return 0;
}