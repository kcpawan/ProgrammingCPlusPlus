#include<iostream>
#include<stdexcept>
using namespace std;

int getElement(int arr[], int size, int idx) {
    if(idx < 0 || idx >= size)
        throw out_of_range("Index out of bounds");
    if(size == 0)
        throw invalid_argument("Empty array");
    return arr[idx];
}

int main() {
    int marks[5] = {90, 85, 78, 92, 60};
    int index = 7; // deliberately out of range
    try {
        cout << getElement(marks, 5, index);
    }
    catch(const out_of_range& e) {
        cout << "Range Error: " << e.what();
    }
    catch(const invalid_argument& e) {
        cout << "Argument Error: " << e.what();
    }
    catch(const exception& e) {
        cout << "Unknown error: " << e.what();
    }
}