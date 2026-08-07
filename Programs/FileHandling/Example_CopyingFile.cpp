#include<iostream>
#include <fstream>
using namespace std;

/*
Author : Pawan KC
Date:
Program Description:
*/

    int main() {
        ifstream source("./FilesFromFileHandling/source.txt");
        ofstream destination("./FilesFromFileHandling/backup.txt");
        char ch;
    // Read one character at a time until EOF,then immediately write that same character
        while (source.get(ch)) {
            destination.put(ch);
        }
    
        cout << "File copied successfully "
         << "using get() and put().";
    
        source.close();
        destination.close();
    return 0;
}