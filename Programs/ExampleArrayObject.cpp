#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    // Default constructor
    Student() {
        name = "";
        rollNumber = 0;
        marks = 0.0;
    }

    // Parameterized constructor
    Student(string n, int r, float m) {
        name = n;
        rollNumber = r;
        marks = m;
    }

    // Setter methods
    void setName(string n) { name = n; }
    void setRollNumber(int r) { rollNumber = r; }
    void setMarks(float m) { marks = m; }

    // Getter methods
    string getName() const { return name; }
    int getRollNumber() const { return rollNumber; }
    float getMarks() const { return marks; }

    // Display method
    void display() const {
        cout << "Name: " << name << ", Roll: " << rollNumber 
             << ", Marks: " << marks << endl;
    }
};

int main() {
    // Method 1: Array of objects with default constructor
    Student students1[3];
    
    // Setting values individually
    students1[0].setName("Alice");
    students1[0].setRollNumber(101);
    students1[0].setMarks(85.5);
    
    students1[1].setName("Bob");
    students1[1].setRollNumber(102);
    students1[1].setMarks(92.0);
    
    students1[2].setName("Charlie");
    students1[2].setRollNumber(103);
    students1[2].setMarks(78.5);

    cout << "Method 1 - Array with default constructor:" << endl;
    for(int i = 0; i < 3; i++) {
        students1[i].display();
    }

    // Method 2: Array of objects with parameterized constructor
    Student students2[3] = {
        Student("David", 104, 88.0),
        Student("Eve", 105, 95.5),
        Student("Frank", 106, 76.0)
    };

    cout << "\nMethod 2 - Array with parameterized constructor:" << endl;
    for(int i = 0; i < 3; i++) {
        students2[i].display();
    }

    return 0;
}