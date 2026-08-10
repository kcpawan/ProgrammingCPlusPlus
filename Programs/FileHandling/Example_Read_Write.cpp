#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to display file content
void displayFileContent(const string& filename) {
    ifstream file(filename);
    
    if (!file.is_open()) {
        cout << "Error: Could not open file '" << filename << "' for reading." << endl;
        return;
    }
    
    string line;
    cout << "\n=== File Content ===" << endl;
    while (getline(file, line)) {
        cout << line << endl;
    }
    cout << "=== End of File ===\n" << endl;
    
    file.close();
}

// Function to write content to file from user input
void writeContentToFile(const string& filename) {
    ofstream file(filename, ios::app); // Open in append mode
    
    if (!file.is_open()) {
        cout << "Error: Could not open file '" << filename << "' for writing." << endl;
        return;
    }
    
    cout << "\nEnter content to write to the file (type 'END' on a new line to finish):" << endl;
    string line;
    
    // Clear input buffer
    cin.ignore();
    
    while (true) {
        getline(cin, line);
        if (line == "END") {
            break;
        }
        file << line << endl;
    }
    
    cout << "Content written successfully!" << endl;
    file.close();
}

int main() {
    string filename;
    int choice;
    
    cout << "=== File Operations Program ===" << endl;
    cout << "Enter the filename (with path if needed): ";
    getline(cin, filename);
    
    do {
        cout << "\n--- Menu ---" << endl;
        cout << "1. Read and display file content" << endl;
        cout << "2. Write content to file (append mode)" << endl;
        cout << "3. Write content to file (overwrite mode)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                displayFileContent(filename);
                break;
                
            case 2: {
                ofstream file(filename, ios::app);
                if (!file.is_open()) {
                    cout << "Error: Could not open file for writing." << endl;
                    break;
                }
                file.close();
                writeContentToFile(filename);
                break;
            }
                
            case 3: {
                ofstream file(filename);
                if (!file.is_open()) {
                    cout << "Error: Could not open file for writing." << endl;
                    break;
                }
                file.close();
                cout << "\nWarning: This will overwrite the entire file content!" << endl;
                writeContentToFile(filename);
                break;
            }
                
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        
    } while (choice != 4);
    
    return 0;
}