#include<iostream>
#include <fstream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/

class Student {
    int rollNo;
    char name[30];
    float marks;

    public:
        void getData() {
            cout << "Roll, Name, Marks: " << endl;
            cin >> rollNo >> name >> marks;
        }
        void showData() {
            cout << rollNo << "\t" << name << "\t" << marks << endl;
        }
};  

int main() {
    Student s1;
    s1.getData();

    ofstream outFile("./FilesFromFileHandling/student.dat", ios::out | ios::binary);
    if (!outFile) {
        cerr << "Error: Cannot open file for writing!" << endl;
        return 1;
    }
    outFile.write(reinterpret_cast<char*>(&s1),sizeof(Student));
    
    outFile.close();


    Student s2; // empty, untouched object
    ifstream inFile("./FilesFromFileHandling/student.dat", ios::in | ios::binary);
    if (!inFile) {
        cerr << "Error: Cannot open file for reading!" << endl;
        return 1;
    }
    inFile.read(reinterpret_cast<char*>(&s2), sizeof(Student));
    inFile.close();

    
    cout << "\nRead back from file:\n";
    s2.showData();
return 0;
}
