#include<iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Author : Pawan KC
Date: 04/07/2026
Program Description: This Program exhibits the opening of file and write in Step 1 and Step 2. 
                        In Step 3 and 4 reopening the same file to read and close.
*/

int main() {
    // Step 1: open file in write mode
		ofstream outFile;
		outFile.open("./FilesFromFileHandling/student.txt", ios::out);
		if (!outFile) {
			cout << "Error opening file!";
			return 1;
		}
		
		// Step 2: write data (text I/O)
		outFile << "Roll No: 101" << endl;
		outFile << "Name: Anish Thapa" << endl;
		outFile << "Marks: 87.5" << endl;
		
		outFile.close(); // Step 3
		
		// Step 4: reopen the SAME file, this time for reading
		ifstream inFile;
		inFile.open("./FilesFromFileHandling/student.txt", ios::in);
		if (!inFile) {
			cout << "Error reading file!";
			return 1;
		}

		// Step 5: read and display, line by line
		string line;
		cout << "----- File Contents -----" << endl;
		while (getline(inFile, line)) {
				cout << line << endl;
		}

		inFile.close(); // Step 6
	
    return 0;
}
