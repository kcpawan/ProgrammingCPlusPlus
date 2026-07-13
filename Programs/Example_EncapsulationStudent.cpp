#include <iostream>
#include <string>
#include <vector>

class Student {
private:
    std::string name;
    int age;
    std::vector<double> grades;
    std::string studentID;
    
    // Private helper method
    double calculateAverage() const {
        if (grades.empty()) return 0.0;
        
        double sum = 0;
        for (double grade : grades) {
            sum += grade;
        }
        return sum / grades.size();
    }
    
public:
    // Constructor with validation
    Student(std::string studentName, int studentAge, std::string id) 
        : studentID(id) {
        setName(studentName);
        setAge(studentAge);
    }
    
    // Setter with validation
    void setName(const std::string& newName) {
        if (newName.empty()) {
            std::cout << "Name cannot be empty!" << std::endl;
            name = "Unknown";
        } else {
            name = newName;
        }
    }
    
    void setAge(int newAge) {
        if (newAge >= 0 && newAge <= 120) {
            age = newAge;
        } else {
            std::cout << "Invalid age! Setting to 0." << std::endl;
            age = 0;
        }
    }
    
    // Getter with formatting
    std::string getName() const {
        return name;
    }
    
    int getAge() const {
        return age;
    }
    
    std::string getStudentID() const {
        return studentID;
    }
    
    // Add grade with validation
    void addGrade(double grade) {
        if (grade >= 0 && grade <= 100) {
            grades.push_back(grade);
            std::cout << "Grade " << grade << " added for " << name << std::endl;
        } else {
            std::cout << "Invalid grade! Must be between 0 and 100." << std::endl;
        }
    }
    
    // Display student info (controlled access)
    void displayInfo() const {
        std::cout << "\n=== Student Information ===" << std::endl;
        std::cout << "ID: " << studentID << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Grades: ";
        
        if (grades.empty()) {
            std::cout << "No grades yet";
        } else {
            for (size_t i = 0; i < grades.size(); i++) {
                std::cout << grades[i];
                if (i < grades.size() - 1) std::cout << ", ";
            }
            std::cout << "\nAverage: " << calculateAverage();
        }
        std::cout << std::endl;
    }
};

int main() {
    Student alice("Alice", 20, "S12345");
    
    // Cannot directly modify private members
    // alice.grades.push_back(95);  // ERROR: private
    // alice.name = "Bob";           // ERROR: private
    
    // Must use public methods
    alice.displayInfo();
    
    alice.addGrade(95);
    alice.addGrade(87);
    alice.addGrade(92);
    alice.addGrade(150);  // Invalid - will be rejected
    
    alice.displayInfo();
    
    alice.setName("Alice Johnson");
    alice.setAge(21);
    
    alice.displayInfo();
    
    return 0;
}