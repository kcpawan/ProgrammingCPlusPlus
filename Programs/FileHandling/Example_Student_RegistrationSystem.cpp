#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

// Student class to represent a single student
class Student {
private:
    string name;
    string registrationNumber;
    double grade;

public:
    // Default constructor
    Student() : name(""), registrationNumber(""), grade(0.0) {}
    
    // Parameterized constructor
    Student(const string& n, const string& reg, double g) 
        : name(n), registrationNumber(reg), grade(g) {}
    
    // Getters
    string getName() const { return name; }
    string getRegistrationNumber() const { return registrationNumber; }
    double getGrade() const { return grade; }
    
    // Setters
    void setName(const string& n) { name = n; }
    void setRegistrationNumber(const string& reg) { registrationNumber = reg; }
    void setGrade(double g) { grade = g; }
    
    // Display student information
    void display() const {
        cout << left << setw(25) << name 
             << setw(20) << registrationNumber 
             << fixed << setprecision(2) << grade << endl;
    }
    
    // Convert student data to string for file writing
    string toFileString() const {
        return name + "|" + registrationNumber + "|" + to_string(grade);
    }
    
    // Parse student data from file string
    static Student fromFileString(const string& line) {
        size_t pos1 = line.find('|');
        size_t pos2 = line.find('|', pos1 + 1);
        
        if (pos1 != string::npos && pos2 != string::npos) {
            string name = line.substr(0, pos1);
            string reg = line.substr(pos1 + 1, pos2 - pos1 - 1);
            double grade = stod(line.substr(pos2 + 1));
            return Student(name, reg, grade);
        }
        return Student(); // Return empty student if parsing fails
    }
};

// Class to manage file operations
class FileManager {
private:
    string filename;
    
public:
    // Constructor
    FileManager(const string& file) : filename(file) {}
    
    // Write student data to file
    bool writeStudents(const vector<Student>& students) {
        ofstream file(filename);
        
        if (!file.is_open()) {
            cout << "Error: Could not open file '" << filename << "' for writing." << endl;
            return false;
        }
        
        for (const auto& student : students) {
            file << student.toFileString() << endl;
        }
        
        file.close();
        cout << "\n✓ " << students.size() << " student record(s) written successfully!" << endl;
        return true;
    }
    
    // Read student data from file
    vector<Student> readStudents() {
        vector<Student> students;
        ifstream file(filename);
        
        if (!file.is_open()) {
            cout << "Error: Could not open file '" << filename << "' for reading." << endl;
            return students;
        }
        
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                Student student = Student::fromFileString(line);
                students.push_back(student);
            }
        }
        
        file.close();
        return students;
    }
    
    // Display file contents with header
    void displayFileContents() {
        vector<Student> students = readStudents();
        
        if (students.empty()) {
            cout << "\nNo student records found in the file." << endl;
            return;
        }
        
        cout << "\n" << string(65, '=') << endl;
        cout << "                    STUDENT REGISTRATION RECORDS" << endl;
        cout << string(65, '=') << endl;
        cout << left << setw(25) << "NAME" 
             << setw(20) << "REGISTRATION NUMBER" 
             << "GRADE" << endl;
        cout << string(65, '-') << endl;
        
        for (const auto& student : students) {
            student.display();
        }
        
        cout << string(65, '-') << endl;
        cout << "Total Students: " << students.size() << endl;
        cout << string(65, '=') << "\n" << endl;
    }
};

// Class to handle user interaction for student registration
class RegistrationSystem {
private:
    FileManager fileManager;
    vector<Student> students;
    
public:
    // Constructor
    RegistrationSystem(const string& filename) : fileManager(filename) {
        // Load existing students from file
        students = fileManager.readStudents();
    }
    
    // Add a new student
    void addStudent() {
        string name, regNum;
        double grade;
        
        cout << "\n--- Enter Student Details ---" << endl;
        
        cin.ignore(); // Clear input buffer
        cout << "Name: ";
        getline(cin, name);
        
        cout << "Registration Number: ";
        getline(cin, regNum);
        
        cout << "Grade: ";
        cin >> grade;
        
        // Input validation for grade
        while (cin.fail() || grade < 0 || grade > 100) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid grade! Please enter a number between 0 and 100: ";
            cin >> grade;
        }
        
        students.push_back(Student(name, regNum, grade));
        cout << "✓ Student added successfully!" << endl;
    }
    
    // Add multiple students
    void addMultipleStudents() {
        int count;
        cout << "\nHow many students do you want to add? ";
        cin >> count;
        
        for (int i = 0; i < count; i++) {
            cout << "\n--- Student #" << (i + 1) << " ---" << endl;
            addStudent();
        }
    }
    
    // Save all students to file
    void saveToFile() {
        fileManager.writeStudents(students);
    }
    
    // Display all students
    void displayAllStudents() {
        fileManager.displayFileContents();
    }
    
    // Get the number of students
    int getStudentCount() const {
        return students.size();
    }
};

// Main program
int main() {
    const string FILENAME = "registration.txt";
    RegistrationSystem system(FILENAME);
    int choice;
    
    cout << "\n" << string(60, '*') << endl;
    cout << "*     WELCOME TO STUDENT REGISTRATION SYSTEM     *" << endl;
    cout << string(60, '*') << endl;
    
    do {
        cout << "\n--- MAIN MENU ---" << endl;
        cout << "1. Add a new student" << endl;
        cout << "2. Add multiple students" << endl;
        cout << "3. Display all students" << endl;
        cout << "4. Save to file and exit" << endl;
        cout << "5. Exit without saving" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                system.addStudent();
                break;
                
            case 2:
                system.addMultipleStudents();
                break;
                
            case 3:
                system.displayAllStudents();
                break;
                
            case 4:
                system.saveToFile();
                cout << "Data saved successfully. Exiting..." << endl;
                break;
                
            case 5:
                cout << "Exiting without saving..." << endl;
                break;
                
            default:
                cout << "Invalid choice! Please enter a number between 1 and 5." << endl;
        }
        
    } while (choice != 4 && choice != 5);
    
    cout << "\nThank you for using the Student Registration System!" << endl;
    return 0;
}