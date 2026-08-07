#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
Author : Pawan KC
Date: 04/08/2026
Program Description: This Programs exhibits seekg() and seekp() in file handling.
*/

int main() {
    // Create and write initial content to the file
        fstream file;
        file.open("alphabet.txt", ios::out);
        if (!file) {
            cerr << "Error creating file!" << endl;
            return 1;
        }
        
        // Write alphabets to the file
        string content = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        file << content;
        file.close();
       
        
    // Now open for both reading and writing
        file.open("alphabet.txt", ios::in | ios::out);
        if (!file) {
            cerr << "Error opening file!" << endl;
            return 1;
        }
    
    // Display the original content
        cout << "Original content: ABCDEFGHIJKLMNOPQRSTUVWXYZ" << endl;
        cout << "Index positions:  0 1 2 3 4 5 6 7 8 9 ..." << endl << endl;
    
    // --------------------------------------------
    // DEMONSTRATION OF DIFFERENT SEEK OPERATIONS
    // --------------------------------------------
    
    // 1. SEEK TO POSITION 4 FROM BEGINNING
        cout << "1. file.seekg(4, ios::beg);" << endl;
        file.seekg(4, ios::beg);  // Jump READ pointer to byte index 4 (5th character)
        char ch;
        file.get(ch);
        cout << "   Character at index 4: " << ch << " (should be 'E')" << endl;
        cout << "   READ pointer now at position: " << file.tellg() << endl << endl;
    
    
    // 2. SEEK WRITE POINTER TO BEGINNING
        cout << "2. file.seekp(0, ios::beg);" << endl;
        file.seekp(0, ios::beg);  // Jump WRITE pointer back to start
        cout << "   WRITE pointer position: " << file.tellp() << " (should be 0)" << endl << endl;
    
    // 3. STEP READ POINTER 1 BYTE BACKWARD FROM CURRENT POSITION
        cout << "3. file.seekg(-1, ios::cur);" << endl;
        // After step 1, read pointer was at position 5 (after reading 'E')
        cout << "   Current READ position before: " << file.tellg() << endl;
        file.seekg(-1, ios::cur);  // Step READ pointer 1 byte backwards
        cout << "   Current READ position after: " << file.tellg() << " (should be 4)" << endl;
        file.get(ch);
        cout << "   Character now at position 4: " << ch << " (should be 'E' again)" << endl << endl;
    
    // 4. POSITION READ POINTER 2 BYTES BEFORE EOF
        cout << "4. file.seekg(-2, ios::end);" << endl;
        file.seekg(-2, ios::end);  // Position READ pointer 2 bytes before EOF
        cout << "   READ pointer position: " << file.tellg() << " (should be 24, since 26-2=24)" << endl;
        file.get(ch);
        cout << "   Character at 2 bytes before EOF: " << ch << " (should be 'Y')" << endl;
        cout << "   Read pointer now at: " << file.tellg() << " (position 25, which is 'Z')" << endl;
        file.get(ch);
        cout << "   Next character is: " << ch << " (should be 'Z')" << endl << endl;
    
    // 5. EXTRA: Modify the file using seekp
        cout << "5. MODIFYING the file:" << endl;
        file.seekp(5, ios::beg);  // Move write pointer to position 5 (6th character)
        file.put('X');  // Replace 'F' with 'X'
        cout << "   Replaced character at index 5 with 'X'" << endl;
    
    // Reset read pointer to beginning to read modified content
        file.seekg(0, ios::beg);
        string modifiedContent;
        file >> modifiedContent;
        cout << "   Modified content: " << modifiedContent << endl;
        
    file.close();
    
    // Clean up - delete the file
    remove("alphabet.txt");
    
    return 0;
}