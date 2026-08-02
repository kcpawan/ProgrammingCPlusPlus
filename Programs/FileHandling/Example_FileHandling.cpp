#include<iostream>
#include<fstream>
using namespace std;

/*
Author : Pawan KC
Date: 2026-07-31
Program Description: This is basic program that exibhit file handling in C++
*/

int main() {

    ofstream file("./FilesFromFileHandling/File_Handle_example.txt");

    if(file.is_open()){
        cout << "File Opened Successfully\n";

    }

    file << "Hello Worold !! This is File Handling";

    file.close();

    

    return 0;
}
